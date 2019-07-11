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


// *********  Timing ******** //
const int COL_SIZES[4][2] = {{0,8}, {8, 11}, {19, 11}, {30, 2}};
//, {8, 11, 11, 2}

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
    //vector<string> sql_tokens;
    void a_ram(string table, string column);
    void create_table(string table_name, string col1, string col2, string col3, string col4);
    void create_index(string column, string table_name);
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
        delete_rows(sql_tokens[1], sql_tokens[4], sql_tokens[5]); return 1;
    }else if(boost::to_lower_copy(sql_tokens[0]) == "create_table"){
        create_table(sql_tokens[1], sql_tokens[2], sql_tokens[3], sql_tokens[4], sql_tokens[5]); return 1;
    }else if(boost::to_lower_copy(sql_tokens[0]) == "a_ram"){
        a_ram(sql_tokens[1], sql_tokens[2]); return 1;
    }else
        return 0;
};
void DBmanager::a_ram(string table, string column){
	auto start = std::chrono::high_resolution_clock::now();
    
    FILE *fpSourceFile = fopen(table.c_str(), "rb");
    if (fpSourceFile==NULL) perror ("Error opening file");
    
    int key_size;
    if (pos_col(column)%2 == 0)	key_size = 8;  // para id
    else key_size = 2;

    char buffer[8+key_size];

    while(fread(&buffer, 1, sizeof(buffer), fpSourceFile) == sizeof(buffer))
    	myMap[pos_col(column)%2][stoi(string(buffer).substr(0, key_size))].push_back(stoi(string(buffer).substr(key_size,8)));
    
    auto finish = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = finish - start;
    std::cout << "Ram Elapsed time: " << elapsed.count() << " s\n";
};
void DBmanager::create_table(string table_name, string col1, string col2, string col3, string col4){

};
void DBmanager::create_index(string column, string table_name){
    
};
void DBmanager::select_ts(string table, string column, string value){
    auto start = std::chrono::high_resolution_clock::now();
    std::vector<string> v;
    
    /*for(auto u in Adj[u]){
        if(*p == value_condition)
            my_stack.push(u);
    }*/
    FILE *fpSourceFile = fopen(table.c_str(), "rb");
    if (fpSourceFile==NULL) perror ("Error opening file");
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
    //int size = myMap[pos_col(column)%2][stoi(value)].size();
    cout <<  pos_col(column)%2 << " helou "<<endl;
    //error de map.find()
/*
    std::map<int,vector<int>>::iterator it;
    it = myMap[pos_col(column)%2].find(stoi(value));
    if (it != myMap[pos_col(column)%2].end()){
    	myMap[pos_col(column)%2].erase(it);
    	cout << "...No se encontro ese registro..." << endl;
    }else { 
    */
    	int size = myMap[pos_col(column)%2][stoi(value)].size();
    	if (size == 0)	cout << "...No se encontro ese registro..." << endl; // solucion error map.find() ?
    	for (int i = 0; i < size; ++i){
    	 	fseek(fpSourceFile, (BUFFER_SIZE * myMap[pos_col(column)%2][stoi(value)][i]), SEEK_SET);
    		if(fread(&buffer, 1, BUFFER_SIZE, fpSourceFile) == BUFFER_SIZE)
    			cout <<"Reg #" <<i+1 <<": " << print_row(string(buffer)) <<endl;
    	}
//    }
    auto finish = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = finish - start;
    std::cout << "Elapsed time: " << elapsed.count() << " s\n";
};
void DBmanager::insert(string table_file, string value1, string value2, string value3, string value4){
	char buffer[ROW_SIZE]; //tam de la fila
	string temp_file = "c" + table_file;
	FILE *fpSourceFile = fopen(table_file.c_str(), "rb");
	FILE *fpTargetFile = fopen(temp_file.c_str(), "wb");

	string new_row = value1 + value2 + value3 + value4; // fix values
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

	//anadir a la estructura, ejemplo map
	/*
	map<int, vector<int>> myMap;
	for (int i = 0; i < 100; ++i)
	{
		myMap[i].push_back(i+1000);
		cout << myMap[i][0] << endl;
	}
	*/
	//
	// Close The Files
	fclose(fpSourceFile);
	fclose(fpTargetFile);
	remove(table_file.c_str());
	rename(temp_file.c_str(), table_file.c_str());
};

//DELETE FROM link WHERE id = 8;
void DBmanager::delete_rows(string table, string column_condition, string value_condition){

};

//UPDATE COMPANY SET SALARY = 15000 WHERE ID = 3;
void DBmanager::update(string table, string column, string new_value, string column_condition, string value_condition){

};


// =================   MAIN   ====================
int main(int argc, char const *argv[]){

    //string message = "select * from tb_alumno where id=85454 using idx.txt";
    //string message = "create_table Alumno(id, nombre, apellido, edad)";
    //string message = "insert prueba10M.txt 10000000 alu10000000 ape10000000 99";
    


    string message = "select_ts from prueba.txt where edad=00";
    
    string message2 = "select from prueba.txt where edad=00";

    DBmanager db;
    
    auto start = std::chrono::high_resolution_clock::now();
    db.a_ram("name_idx.txt", "id");
    db.a_ram("edad_idx.txt", "edad");
    db.classifier(db.tokenizer(message));
    db.classifier(db.tokenizer(message2));
    
    auto finish = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = finish - start;
    std::cout << "Total time: " << elapsed.count() << " s\n";

    return 0;
};


/*
10 000 000		8
alu12345678		11
ape12345678		11
ape99999999
99				2


*/