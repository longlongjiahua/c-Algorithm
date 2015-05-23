#include<cstring>
#include<algorithm>
#include<iostream>
#include<vector>
using namespace std;
//solved
//data struc: array of vector  vector<int>g[maxN];  all children from a father  g[u][i] is the index of i-th children of father u
//base case for(int i=1; i<=m; i++)  dp[0][i]=-inf;
//recursion : dp[i][j] = max(dp[i+1][j], dp[i][j-1] +val[u])  dp[i][j] means for father, from its subtree  to get the max value with j nodes


const int inf=0x3f3f3f3f;
const int maxN=150001;
const int maxM=301;

int n,m;
int dp[150001][maxM];
vector<int>g[maxN]; // all children from a father  g[u][i] is the index of i-th children of father u
int val[maxN];
void dfs(int u,int d){
	//cout << "dfs:" << u << " " << d << endl;
	for(int i=1; i<=m; i++){
		dp[d+1][i]=dp[d][i]; // every recursion, base case//  
	}
	for(int i=0; i<g[u].size(); i++) //
		dfs(g[u][i],d+1);
	for(int i=m; i>=1; i--){
		dp[d][i]=max(dp[d+1][i],dp[d][i-1]+val[u]); 
	}
}

int main(){
	while( cin >> n >> m){
		for(int i=0; i<=n; i++)g[i].clear();  //initial
		for(int i=1; i<=n; i++){
			int fa,va;
			cin >>fa >> va ;
			g[fa].push_back(i);
			val[i]=va;
		}
		for(int i=1; i<=m; i++)  dp[0][i]=-inf;

		dfs(g[0][0],0);

		if(dp[0][m]<=0) cout <<"impossible" << endl;
		else cout << dp[0][m] << endl;
	}
	return 0;
}
