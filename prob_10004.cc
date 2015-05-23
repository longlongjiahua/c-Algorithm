#include<iostream>
#include<stack>
//solved
//dfs. if the the color of current node is the same as the next one, then it is not BICOLORABLE;
using namespace std;
int M, N;
bool dfs(){
	int a[1000][1000];
	for(int i=0; i<M; i++) for(int j=0; j<M; j++) {a[i][j]=-1;}
	int visited[1000]={-1};
	int x, y;
	for(int i=0; i<N; i++){
		cin>>x>>y;
		a[x][y]=1;
		a[y][x] =1;
		visited[x] =-1;
		visited[y] =-1;
	}
	//dfs start
	stack<int> s;
	s.push(x);
	visited[x] =1;
	while(!s.empty()){
		int cur =s.top();
		int curcol = visited[cur];
		s.pop();
		for(int i=0; i<M; i++){
			if(a[cur][i]==1){	
				if(visited[i] ==curcol){
					cout << "NOT BICOLORABLE." << endl;
					return false;
				}
				else if(visited[i]==-1){
					visited[i] =1-curcol;
					s.push(i);
				}
			}
		}
	}
cout << "BICOLORABLE." << endl;
return true;
}

int main(){
	while(cin>>M>>N){
		dfs();
	}
}

