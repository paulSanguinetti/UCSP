#include <iostream>
using namespace std;
int _strlen(char *s){
	int len = 0;
	while(*s++ != '\0')
		len++;
	return len;
}
int main(){
	char p[] = "abc";
	cout << _strlen(p) << endl;
	return 0;
	
}
