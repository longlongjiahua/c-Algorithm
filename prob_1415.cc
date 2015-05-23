#include <string>
#include<iostream>
#include<map>
using namespace std;
//solved
//represent 14 note with 10 fingers.seting  the additional finger [0] is easy for index

int table[14][11] = 
{
  0,0,1,1,1,0,0,1,1,1,1,
  0,0,1,1,1,0,0,1,1,1,0,
  0,0,1,1,1,0,0,1,1,0,0,
  0,0,1,1,1,0,0,1,0,0,0,
  0,0,1,1,1,0,0,0,0,0,0,
  0,0,1,1,0,0,0,0,0,0,0,
  0,0,1,0,0,0,0,0,0,0,0,
  0,0,0,1,0,0,0,0,0,0,0,
  0,1,1,1,1,0,0,1,1,1,0,
  0,1,1,1,1,0,0,1,1,0,0,
  0,1,1,1,1,0,0,1,0,0,0,
  0,1,1,1,1,0,0,0,0,0,0,
  0,1,1,1,0,0,0,0,0,0,0,
  0,1,1,0,0,0,0,0,0,0,0,
};

map<char, int> nt;

void solve(string str){
    //initialize
	bool used[11]={false};
	int count[11]={0};
	for(int i = 0; i < str.length(); i++){
		int t = nt[str[i]];
		for(int j = 1; j < 11; j++){
			if(table[t][j] && !used[j]) {
				count[j]++;
				used[j] =true ;
			}
			if(!table[t][j]) used[j] = false; 
		}
	}
	for(int i = 1; i < 10; i++){
		cout << count[i]<<" ";
	}
	cout << count[10]<<"\n";
}
int main(){
	string inits = "cdefgabCDEFGAB";
	for(int i=0; i<inits.length(); i++){
		nt[inits[i]] = i;

	}
	int N;
	cin >>N;
	cin.ignore();
	while(N--)
	{
		string str;
		getline(cin, str);
		solve(str);
	}
}
