#include <iostream>
#include <cstring>
using namespace std

void touppercase(char* words){
	for(int i=0; words[i] != "\0"; i++){
		words[i] = toupper(words[i]);
	}
}

class Matrix{
	private:
		char area[24][24];
};

int main(){
	int n;
	cin >> n;
	char words[n][24];
	
	Matrix matrix;
	
	for(int i=0; i<n;i++){
		cin.getline(words[i], 25);
		touppercase(words[i]);
	}
	
	
	return 0;
}
