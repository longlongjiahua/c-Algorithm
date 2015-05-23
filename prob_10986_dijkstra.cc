#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
using namespace std;
const int MaxN = 20001;
const int inf=0x3f3f3f3f;
int st, end;
int nE, nN;
struct E {
	 int to,w;
	E() {;}
	E(int x,int y) {
	to = x; w =y; }
};
vector<E> G[MaxN];

typedef pair<int, int> pii; //Node and weight

priority_queue<pii, vector<pii>, greater<pii> > pq;
bool visited[MaxN];
int D[MaxN]; 
void dijkstra(){
	memset(visited, false, sizeof(visited));
	memset(D, inf, sizeof(D));
	pii  t= make_pair(0, st);
	D[st] = 0;
	pq.push(t);
	while(!pq.empty()) {
		pii top = pq.top();
		int d = top.first;
		int u = top.second;
		pq.pop();
		if(visited[u]) continue;
		visited[u] = true;
		int len = G[u].size();
		for(int i=0; i<len; i++) {
			int w = d + G[u][i].w;
			if(w<D[G[u][i].to]){
				D[G[u][i].to] = w;
				pq.push(make_pair(w, G[u][i].to));
			}

		}
	}
	if(D[end] == inf) { cout << "unreachable" << endl;}
	else cout << D[end] << endl;
}

int main(){
	int Case;
	cin >> Case;
	for(int i=1; i<=Case; i++){
		cout <<"Case #"<< i<<": ";
		cin >> nN>>nE>>st>>end;
		for(int x=0; x<nN; x++) G[x].clear();
		for(int j=0; j<nE; j++){
			int t1, t2, w;
			cin >> t1 >> t2 >> w;
			G[t1].push_back(E(t2,w));
			G[t2].push_back(E(t1, w));
		}
		dijkstra();
	}
}

