#include <iostream>
#include <cstdio>
#include <boost/algorithm/string.hpp>
#include <stdio.h>
#include <stdlib.h>
#include <chrono>
#include <vector>
#include <map>
using namespace std;

#define ROW_SIZE 32
#define BUFFER_SIZE 32
const int COL_SIZES[4][2] = {{0,8}, {8, 11}, {19, 11}, {30, 2}}; //, {8, 11, 11, 2}

string zeroes(string s, int dig){
	int how = dig-s.size();
	for(int i=0; i<how; i++)
		s.insert(0,"0");
	return s;
};
int pos_col(string str){
	if(str == "id") return 0;
	else if(str == "nombre") return 1;
	else if(str == "apellido") return 2;
	else if(str == "edad") return 3;
	else return -1;
};
string print_row(string str){
	return str = " | " + str.substr(COL_SIZES[0][0],COL_SIZES[0][1]) + " | " + str.substr(COL_SIZES[1][0],COL_SIZES[1][1]) + " | " + str.substr(COL_SIZES[2][0],COL_SIZES[2][1]) + " | " + str.substr(COL_SIZES[3][0],COL_SIZES[3][1]) + " | " ;
};
// *********    DB    ******* //
class DBmanager{
public:
    DBmanager(){};
    vector<string> tokenizer(string);
    map<int, vector<int>> myMap[2]; // 0 : id | 1 : edad
    bool classifier(vector<string>);
    void a_ram(string table, string column);
    void create_table(string table_name, string col1, string col2, string col3, string col4);
    void create_index(string table_name);
    void select(string table, string column, string value);
    void select_ts(string table, string column, string value);
    void insert(string table, string value1, string value2, string value3, string value4);
    void delete_rows(string table, string column, string value);
    void update(string table, string set_col, string set_value, string col_condition, string value_condition);
};
vector<string> DBmanager::tokenizer(string sql_sentence){
    vector<string> tokens;
    boost::split(tokens, sql_sentence, boost::is_any_of(" ,=*();"));
    return tokens;
};
bool DBmanager::classifier(vector<string> sql_tokens){
    if(boost::to_lower_copy(sql_tokens[0]) == "select"){
        select(sql_tokens[2], sql_tokens[4], sql_tokens[5]); return 1;
    }else if(boost::to_lower_copy(sql_tokens[0]) == "select_ts"){
        select_ts(sql_tokens[2], sql_tokens[4], sql_tokens[5]); return 1;
    }else if(boost::to_lower_copy(sql_tokens[0]) == "insert"){
        insert(sql_tokens[1], sql_tokens[2], sql_tokens[3], sql_tokens[4], sql_tokens[5]); return 1;
    }else if(boost::to_lower_copy(sql_tokens[0]) == "update"){
        update(sql_tokens[1], sql_tokens[3], sql_tokens[4], sql_tokens[6], sql_tokens[7]); return 1;
    }else if(boost::to_lower_copy(sql_tokens[0]) == "delete"){
        delete_rows(sql_tokens[2], sql_tokens[4], sql_tokens[5]); return 1;
    }else if(boost::to_lower_copy(sql_tokens[0]) == "create_table"){
        create_table(sql_tokens[1], sql_tokens[2], sql_tokens[3], sql_tokens[4], sql_tokens[5]); return 1;
    }else if(boost::to_lower_copy(sql_tokens[0]) == "a_ram"){
        a_ram(sql_tokens[1], sql_tokens[2]); return 1;
    }else
    	cout << " >> syntax error <<"<< endl;
        return 0;
};
void DBmanager::a_ram(string table, string column){
	auto start = std::chrono::high_resolution_clock::now();
    FILE *fpSourceFile = fopen(table.c_str(), "rb");
    if (fpSourceFile==NULL) perror ("Error opening file");
    int key_size;
    if (pos_col(column)%2 == 0)	key_size = 8;  // para id, sino edad
    else key_size = 2;
    char buffer[8+key_size];
    while(fread(&buffer, 1, sizeof(buffer), fpSourceFile) == sizeof(buffer))
    	myMap[pos_col(column)%2][stoi(string(buffer).substr(0, key_size))].push_back(stoi(string(buffer).substr(key_size,8)));
    fclose(fpSourceFile);
    auto finish = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = finish - start;
    std::cout << "Ram Elapsed time: " << elapsed.count() << " s\n";
};
void DBmanager::create_table(string table_name, string col1, string col2, string col3, string col4){

};
void DBmanager::create_index(string table){
	string tb_idx_age = "idx_age_" + table;
	string tb_idx_name = "idx_name_" + table;
	FILE *fpSourceFile = fopen(table.c_str(), "rb");
	FILE *fpTargetFile = fopen(tb_idx_age.c_str(), "wb");
	FILE *fpTargetFile2 = fopen(tb_idx_name.c_str(), "wb");
	if (fpSourceFile==NULL) perror ("Error opening file");
	char buffer[32];
	for(int i=0;fread(&buffer, 1, BUFFER_SIZE, fpSourceFile) == BUFFER_SIZE;i++){
		string idx_age = string(buffer).substr(COL_SIZES[3][0],COL_SIZES[3][1]) + zeroes(to_string(i),8);
		string idx_name = string(buffer).substr(COL_SIZES[0][0],COL_SIZES[0][1]) + zeroes(to_string(i),8);
		fwrite(&idx_age[0], 1, idx_age.length(), fpTargetFile);
		fwrite(&idx_name[0], 1, idx_name.length(), fpTargetFile2);
	}
	fclose(fpSourceFile);
	fclose(fpTargetFile);
	fclose(fpTargetFile2);
};
void DBmanager::select_ts(string table, string column, string value){
    auto start = std::chrono::high_resolution_clock::now();
    std::vector<string> v;
    FILE *fpSourceFile = fopen(table.c_str(), "rb");
    if (fpSourceFile==NULL) perror ("Error opening file on select_ts");
    char buffer[32]; //tam de la fila
    while (fread(&buffer, 1, BUFFER_SIZE, fpSourceFile) == BUFFER_SIZE)
		if (string(buffer).substr(COL_SIZES[pos_col(column)][0],COL_SIZES[pos_col(column)][1]) == value)
			v.push_back(string(buffer));

	//anadir encabezado
	for (int i = 0; i < v.size(); ++i)
		cout <<"Reg #" <<i+1 <<": " << print_row(v[i]) << endl;
	
	if (v.size()==0)
		cout << "...No se encontro ese registro..." << endl;

    auto finish = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = finish - start;
    std::cout << "table scanning Elapsed time: " << elapsed.count() << " s\n";
};
void DBmanager::select(string table, string column, string value){
	auto start = std::chrono::high_resolution_clock::now();
    
    FILE *fpSourceFile = fopen(table.c_str(), "rb");
    if (fpSourceFile==NULL) perror ("Error opening file");
    char buffer[32];
	int size = myMap[pos_col(column)%2][stoi(value)].size();
	if (size == 0)	cout << "...No se encontro ese registro..." << endl;
	for (int i = 0; i < size; ++i){
	 	fseek(fpSourceFile, (BUFFER_SIZE * myMap[pos_col(column)%2][stoi(value)][i]), SEEK_SET);
		if(fread(&buffer, 1, BUFFER_SIZE, fpSourceFile) == BUFFER_SIZE)
			cout <<"Reg #" <<i+1 <<": " << print_row(string(buffer)) <<endl;
	}
	fclose(fpSourceFile);
    auto finish = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = finish - start;
    std::cout << " >SELECT Elapsed time <: " << elapsed.count() << " s\n";
};
void DBmanager::insert(string table_file, string value1, string value2, string value3, string value4){
	char buffer[ROW_SIZE]; //tam de la fila
	string temp_file = "c" + table_file;
	FILE *fpSourceFile = fopen(table_file.c_str(), "rb");
	FILE *fpTargetFile = fopen(temp_file.c_str(), "wb");

	string new_row = value1 + value2 + value3 + value4; // need fix values
	char * cstr = new char [new_row.length()+1];
	strcpy (cstr, new_row.c_str());
	int last_buffer;
	
	while ((last_buffer = fread(&buffer, 1, BUFFER_SIZE, fpSourceFile)) == BUFFER_SIZE && stoi(string(buffer).substr(0,8)) <= stoi(value1)){
		fwrite(&buffer, 1, BUFFER_SIZE, fpTargetFile);
	}
	fwrite(cstr, 1, new_row.length(), fpTargetFile);
	if (last_buffer == BUFFER_SIZE){
		fwrite(&buffer, 1, BUFFER_SIZE, fpTargetFile);
	}
	while( fread(&buffer, 1, BUFFER_SIZE, fpSourceFile) == BUFFER_SIZE)
		fwrite(&buffer, 1, BUFFER_SIZE, fpTargetFile);

	// Close The Files
	fclose(fpSourceFile);
	fclose(fpTargetFile);
	remove(table_file.c_str());
	rename(temp_file.c_str(), table_file.c_str());

	//anadir a la estructura
	create_index(table_file);
	string tb_idx_age = "idx_age_" + table_file;
	string tb_idx_name = "idx_name_" + table_file;
	myMap[0].clear();
	myMap[1].clear();
	a_ram(tb_idx_age, "edad");
    a_ram(tb_idx_name, "id");
	

};
//DELETE FROM tb WHERE id = 8;
void DBmanager::delete_rows(string table_file, string column, string value){
	auto start = std::chrono::high_resolution_clock::now();

	string temp_file = "c" + table_file;
	FILE *fpSourceFile = fopen(table_file.c_str(), "rb");
	FILE *fpTargetFile = fopen(temp_file.c_str(), "wb");
    if (fpSourceFile==NULL) perror ("Error opening file");
    char buffer[32];
	int size = myMap[pos_col(column)%2][stoi(value)].size();
	if (size == 0)	cout << "...No se encontro ese registro..." << endl;
	else{
		for (int i = 0, j = 0; fread(&buffer, 1, BUFFER_SIZE, fpSourceFile) == BUFFER_SIZE; ++i){
			if(i == myMap[pos_col(column)%2][stoi(value)][j]) j++;
			else fwrite(&buffer, 1, BUFFER_SIZE, fpTargetFile);
		}
	}

	fclose(fpSourceFile);
	fclose(fpTargetFile);
	remove(table_file.c_str());
	rename(temp_file.c_str(), table_file.c_str());
		//anadir a la estructura
	create_index(table_file);
	string tb_idx_age = "idx_age_" + table_file;
	string tb_idx_name = "idx_name_" + table_file;
	myMap[0].clear();
	myMap[1].clear();
	a_ram(tb_idx_age, "edad");
    a_ram(tb_idx_name, "id");
	
    auto finish = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = finish - start;
    std::cout << "Elapsed time: " << elapsed.count() << " s\n";
};
//UPDATE COMPANY SET SALARY = 15000 WHERE ID = 3;
void DBmanager::update(string table, string column, string new_value, string column_condition, string value_condition){

};
// =================   MAIN   ====================
int main(int argc, char const *argv[]){

    std::chrono::duration<double> elapsed;
    DBmanager db;
    string input = "";
    while(true){
    	cout << "  >>>";
    	getline(cin, input);
	    auto start = std::chrono::high_resolution_clock::now();
	    db.classifier(db.tokenizer(input));
	    auto finish = std::chrono::high_resolution_clock::now();
	    std::chrono::duration<double> elapsed = finish - start;
	    std::cout << "Total time: " << elapsed.count() << " s\n\n";
    }

    return 0;
};

	//select_ts from data10.txt where id=00000000
    //select from data10.txt where id=00000000
    //delete from data10.txt where id=00000001
    //insert data10.txt 00000021 alU00000000 apE00000000 99

//g++ -o3 -pthread sqlito.cpp -o e -std=c++17 -lntl -lgmp -lm -ggdb
