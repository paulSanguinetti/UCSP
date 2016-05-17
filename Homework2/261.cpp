#include <iostream>
#include <string>

using namespace std;

void printArray(int A[], int len){
  for(int i = 0; i < len; i++){
    cout << A[i] << ", ";
  }
  cout << endl;
}

int main(void)
{
  int A[10];
  int len = 10;  
  for(int i = 0; i < len; i++)
    A[i]=i+1;

  printArray(A, len);

  return 0;
}
