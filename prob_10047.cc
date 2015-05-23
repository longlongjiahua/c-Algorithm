#include<iostream>
#include<string>
#include<queue>
using namespace std;
//sloved
//using bfs with four dimesnsion array: r, c direction and color
string grid[100];
int R, C;
struct state{
	int r,c;
	int step;
	int time;
	int dir; //4 direction
	int color;  // 5 colors
	void set(int r1, int c1, int step1, int time1,int dir1, int color1){
		r=r1; c=c1; step = step1; time = time1; dir = dir1%4; color = color1%5;
	}
};
int turn[]={-1,1}; //left turn or right turn
//dir from 0 to 3;
int dr[]={1,0,-1,0};
int dc[]={0,1,0,-1};

state start;
void solve(){
	bool visited[100][100][4][5] = {false};
	queue<state> q;
	q.push(start);
	visited[start.r][start.c][start.dir][start.color] = true;
	while(!q.empty()){
		state cur = q.front();
		q.pop();
		// check if reach the goal
		if(grid[cur.r][cur.c] == 'T' && cur.color==0){  //if steps is 5 times
			cout << "minimum time = "<<cur.time <<" sec" << endl;
			return;
		}
		//move forward;
		int r1 = cur.r+dr[cur.dir]; int c1 = cur.c+dc[cur.dir];
		if(r1>=0 && r1<R && c1>=0 && c1<C && grid[r1][c1] !='#' && !visited[r1][c1][cur.dir][(cur.color+1)%5]){
			visited[r1][c1][cur.dir][(cur.color+1)%5] = true;
			state s; s.set(r1,c1,cur.step+1, cur.time+1, cur.dir, cur.color+1);
			q.push(s);
		}
		for(int t=0; t<2; t++){ //turn left or right
			int dir = (4+cur.dir+turn[t]) %4;
			//if(!visited[cur.r][cur.c][dir][cur.color]){
			if(!visited[cur.r][cur.c][dir][cur.color]){
				visited[cur.r][cur.c][dir][cur.color]=true;
				state s;
				s.set(cur.r, cur.c,cur.step, cur.time+1, dir, cur.color);
				q.push(s);
			}
		}
	}		
	cout << "destination not reachable" << endl;
}	

int main(){
	int Case =0;
	while(cin>>R>>C && R>0 && C>0){
		Case++;
		if(Case >1) cout << endl;
		cout << "Case #" << Case << endl;
		
		for(int i=R-1; i>=0; i--){
			cin >> grid[i];
			for(int j=0; j<C; j++){
				if(grid[i][j] =='S'){
					start.set(i, j, 0,0,0,0);
				}
			}
		}
		solve();
		
	}
}
