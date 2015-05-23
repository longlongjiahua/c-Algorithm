#include<iostream>
#include<stack>
#include<string>
using namespace std;
//solved bfs
string CUR = "http://www.acm.org/";
string cur;
void check(string st, stack<string> &F, stack<string> &B){
	int found = st.find(" ");
	string action, url;
        if(found!=string::npos){
		action = st.substr(0, found);
		url = st.substr(found+1);
	}
	else action = st;
	if(action == "VISIT"){
	cout << url<<endl;
	B.push(cur);
	cur =url;
	while(!F.empty()) F.pop();
	}
	else if(action =="BACK"){
		if(!B.empty()){
			F.push(cur);
			cur = B.top();
			B.pop();
			cout << cur << endl;
		}
		else  cout << "Ignored" << endl;	
	}
	else if(action =="FORWARD"){
		if(!F.empty()){
			B.push(cur);
			cur = F.top();
			F.pop();
			cout << cur << endl;
		}
		else  cout << "Ignored" << endl;	
	}
}
int main(){
	int N;
	cin>>N;
	cin.ignore();
	for(int i=0; i<N; i++){
		if(i>0) cout <<endl;
		string st;
		getline(cin, st);
		stack<string> F, B;
		cur = CUR;
		while(getline(cin, st)!=NULL &&st!="QUIT"){
			//if(st =="QUIT") break;
			check(st,F,B);
		}
	}
}

