# include <iostream>
int doubleNumber(int num){ 
	return num * 2;
}
int main(){
	int num = 35;
	num	= doubleNumber(num);
	std::cout << num << "\n"; // Should print 70
	return 0;
}
