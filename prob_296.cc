#include <iostream>
#include<map>
#include <string>
#include<vector>
#include <sstream>
using namespace std;
//solved
//All integers treated as string. Searching space includes all possible numbers from 0000 to 9999
struct guess {
string st;
int pc;
int lc;
};

guess a[11];
string int2string(int x){
	stringstream ss;
	ss<<x;
	string st =  ss.str();
	st = "000" +st;
	return st.substr(st.length() -4);
}
void solve(int M){
	vector<string> corrects;
	for(int i =0; i<10000; i++){
		bool correct_guess = true;
		for(int m=0; m<M; m++){
		string curr =int2string(i);
			guess x = a[m];		string st = x.st;
			int pc =0; int lc =0;
			for(int j=0; j<4; j++){
				if(curr[j] ==st[j]){
					curr[j] =st[j] ='x';
					pc++;
				}
			}
			for(int j=0; j<4; j++){
				for(int k =0; k<4; k++){
					if(curr[j] ==st[k]  && j !=k && curr[j] !='x'&& st[k] !='x'){	
						curr[j] =st[k]='x';
						lc++;
					}
				}
			}
			if(!(pc == x.pc && lc == x.lc)){
				correct_guess = false;
				break;
			}
		}
		if(correct_guess) corrects.push_back(int2string(i));
		if(corrects.size() >1) break;
	}
	if(corrects.size() ==0) cout << "impossible" << endl;
	else if(corrects.size() ==1) cout << corrects[0] << endl;
	else cout << "indeterminate" << endl;
}
int main(){
	int N;
	cin>>N;
	while(N--){
		int M;
		cin>>M;
		for(int i =0; i<M; i++){
		string p, b;
			cin>>p>>b;
			int pc = b[0]-'0';
			int lc = b[2] -'0';
			guess x;
			x.st = p, x.pc =pc, x.lc = lc;	
			a[i] = x;
		}
		solve(M);
	}
}

