#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include<sstream>

using namespace std;
vector<string> ks;
vector<pair<string,int> >strs;

string toLowCase(const string &line){
	string nl=" ";

	for(int p=0; p<line.length(); p++){
		char a = line.at(p);
		if(a>='A' && a <='Z'){
			a = tolower(a);
			nl+=a;
		}
		else if(!((a>='A' && a<='Z') ||(a>='a' && a<='z'))){
			nl +="  ";
		}
		else {
		nl+=a;
		}
	}
	nl+=' ';
	return nl;
}
int findK(const string &s){

	int count =0;
	for(int i =0; i<ks.size(); i++){
		string k  =  ' '+ks[i]+' ';
		int pos=0;
		while((pos=s.find(k, pos))!=string::npos){
			pos++;
			count++;
		}
	}
	return count;
}
void output(int t, int max){
	
	cout << "Excuse Set #" << t << endl;
	for(int i=0; i<strs.size(); i++){
		if(strs[i].second ==max){
			cout << strs[i].first <<endl;
		}
	}
	cout << endl;
}

int main(){
	int max = -1;
	int Case =0;
	int M, N;
	while(cin>>M>>N){
		for(int i=0; i<M; i++){
			string key;
			cin>>key;
			ks.push_back(key);
		}
		cin.ignore();
		for(int i=0; i<N; i++){
			string line;
			getline(cin, line);
			string nl = toLowCase(line);
			int nf = findK(nl);
			if(nf>max){
				max = nf;
			}
			strs.push_back(make_pair(line, nf));
		}
		Case++;
			output(Case, max);
		ks.clear();
		strs.clear();
		max = -1;
	}

}
