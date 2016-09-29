#include <iostream>

using namespace std;

int pow(int n, int e){
    if(e==0)
        return 1;
    else if(e==1)
        return n;
    int x = n;
    int result = 1;
    while(e!=0){
        if(e%2==1)
            result*=x;
        x*=x;
        e/=2;
        //cout <<e<<endl;
    }
    return result;
}


int main(){

cout << expo(2,11) <<endl;

return 0;
}
