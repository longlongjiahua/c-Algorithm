#include <iostream>
#include <string>
#include <stack>
#include<map>
#include<sstream>
#include<vector>
using namespace std;
//sloved
////model as Source->Party =( #club-1)/2; Party->Member =1;  Membber->club =1; club->target=1;

int m[3000][3000];
typedef map<string, int> Map;
Map R,P,C; //resisdence, parity, club
int S, T; //source and target;
int n;
int addX(string s,Map &t){
	if(t.count(s)==0){
		n++;
		t[s] =n;
		return n;
	}
	else return t[s];
}	
int getThisFlow(int parent[3000]){
        int minflow=30000;
        int t = T;
        do {
           minflow=min(minflow, m[parent[t]][t]);
                t=parent[t];
        } while(t!=S); // wrong if it is parent[t]
        t = T;
        do {
                m[parent[t]][t]-=minflow;
                m[t][parent[t]] += minflow;
                t=parent[t];
        } while(t!=S);
        return minflow;

}

int dfs(){
	stack<int> st;
	st.push(S);
	vector<int> path; 
	int parent[3000]; // record the path
	bool visited[3000]={false};
	visited[S]=true;
	while(!st.empty()){
		int cur = st.top();
		 path.push_back(cur);
		st.pop();
		for(int i=0; i<=n; i++){
			if(m[cur][i]>0 && !visited[i]){
				parent[i] = cur;
				if(i==T){	
					path.push_back(T);
					return getThisFlow(parent);
				}
					st.push(i);
				visited[i] = true;
			}
		}
	}
	return 0;
	
}

void  ford_fulkerson(){
	int maxflow =0;
	while(1){
		int minn = dfs();
		if(minn>0){	
			maxflow += minn;
		}
		else break;
	}
	//cout <<"maxlfow" <<maxflow <<" " << C.size() << endl;
	if(maxflow == C.size()) {
		for(Map::iterator itr = R.begin(); itr!=R.end(); itr++){
			//cout << itr->first << "  " << itr->second << endl;
			for(Map::iterator itc=C.begin(); itc!=C.end(); itc++){
				if(m[itc->second][itr->second]>0){
					cout << itr->first<<" " << itc->first << endl;
				}}}				
	}


	else cout << "Impossible." << endl;
}

int main(){
	int Case; string str;
	cin >> Case;
	cin.ignore();
	getline(cin, str);
	for(int mCase=0; mCase<Case; mCase++){
		if(mCase>0) cout << endl;
		S=0; T=1;
		n=2;
		R.clear(); P.clear();C.clear();//initial
		for(int i=0; i<3000; i++) {  //initial
			for(int j=0; j<3000; j++){
				m[i][j] = 0; 
			} }
		while(getline(cin, str)!=NULL && str.length()>1){ 
			stringstream ss(str);
			string sr, sp, sc;	
			ss>>sr>>sp;
			m[addX(sp, P)][addX(sr,R)]=1;
			while(ss>>sc){
				if(sc!="") {
					m[addX(sr,R)][addX(sc,C)] =1;
					m[addX(sc,C)][T] =1;
				}
			}
		}
		int SPflow = (C.size()-1)/2;
		for(Map::iterator it = P.begin(); it !=P.end(); it++){
			m[S][it->second] = SPflow;
		}
		 ford_fulkerson();
	}
}
