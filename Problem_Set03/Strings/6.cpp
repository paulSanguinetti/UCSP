// string::erase
#include <iostream>
#include <string>
using namespace std;

string pigLatinify(string S)
{
	string vowels = "aeiou";

	if (S[0] == 'q' && S[1] == 'u')
	  	return S.erase(0,2) + "-quay";

	else
	{
		for(int i = 0; i<5; i++)
			if(S[0] == vowels[i])
				return S.erase(0,1) + "-way";
		
		S = S + "-" + S[0] + "ay";
		return S.erase(0,1);
	}
  return 0;
}

int main(){
	string test;
	cin >> test;
	cout << pigLatinify(test) << endl;
}