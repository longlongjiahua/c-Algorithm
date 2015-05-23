#include<queue>  
#include<vector>
#include<iostream>
using namespace std;  
//solved
//dijkstra; each step move one unit along the chosen road, and minimize its  cost;  
const int INF=100000+10; 
int idx,n,m;
int cost[1001]; //the cost to reach the target
vector<vector<int> > froms(1000); // Es from same node; 
int dp[1001][101];//dp[i][j] the minimum cost to reach place i with j unit gas left
struct E{
	int to,length,from; 
}e[20001];    
  
void add(int from,int to,int length){ 
	e[idx].to=to;    
	e[idx].from = from;
	e[idx].length=length; 
	froms[from].push_back(idx);
	idx++;  
}    
struct state{
	int id,cost,move;  
	state(int mid,int mmove,int mcost){
		id=mid, move = mmove, cost = mcost;
	}
	bool operator <(const state & x)const {   
		return cost > x.cost;   
	}  
};  
void dijk(int vol,int from,int to){
	for(int i=0;i<n;i++)  
		for(int j=0;j<101;j++)  
			dp[i][j]=INF;  
	priority_queue<state> q;  
	q.push(state(from,0,0));  
	while(!q.empty()){  
		state cur=q.top();  
		if(cur.id==to) {
			cout <<cur.cost << endl;
			return;  
		}  
		q.pop();  
		if(cur.move<vol &&  dp[cur.id][cur.move+1] > cost[cur.id]+cur.cost){ // if move 1 unit 
			dp[cur.id][cur.move+1] = cost[cur.id]+cur.cost;  
			q.push(state(cur.id,cur.move+1,cost[cur.id]+cur.cost));//after move one unit , update move and cost 
		}  
		for(int t=0; t< froms[cur.id].size(); t++){
			int i = froms[cur.id][t];
			int id=e[i].to;  
			if(cur.move < e[i].length) continue;// could not move to next stop
			//just finish this road and move to the next  place  :cur.move = e[i].length
			if(dp[e[i].to][cur.move-e[i].length] > cur.cost){  //cur.move < e[i].length 
				dp[e[i].to][cur.move-e[i].length] = cur.cost;  
				q.push(state(e[i].to,cur.move-e[i].length,cur.cost));  
			}  
		}  
	}  
	cout << "impossible" << endl;
}  
  
int main(){ 
    while(cin >> n >> m && n && m){
	froms.clear(); 
        idx=0;  
        for(int i=0;i<n;i++)  
            cin >>cost[i];  
        for(int i=0;i<m;i++){
            int from,to,length;  
            cin >> from >> to >> length;
            add(from,to,length);  
            add(to,from,length);  
        }  
        int q;  cin >>q;  
        while(q--){
            int c,s,e;  
            cin >> c >> s >> e;
            dijk(c,s,e);  
        }  
    }  
}  
