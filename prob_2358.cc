#include<iostream>
#include<queue>
using namespace std;
//solved
//using bfs to search six directions. adding an extra layer covering the whole box to make counting easy 
struct p{
	int x, y, z;
void	set(int a, int b, int c){
		x=a; y=b; z=c;
	}
		
};

int dx[]={1,0,0,-1,0,0};
int dy[]={0,1,0,0,-1,0};
int dz[]={0,0,1,0,0,-1};
int X, Y ,Z;
void bfs(bool m[][65][65]){ 
	bool visited[65][65][65]={{{false}}};
	queue<p> q;
	p w; w.set(0,0,0);
	visited[0][0][0] = true;
	int paint =0;
	q.push(w);
	while(!q.empty()){
		p f = q.front();
		q.pop();
		for(int i=0; i<6;i++){
			int x=f.x+dx[i];
			int y=f.y+dy[i];
			int z=f.z+dz[i];	

			if(x>=0 && x<=X+1 &&y>=0 && y<=Y+1 && z>=0 && z<=Z+1  && !visited[x][y][z]){
				if(!m[x][y][z]) {
					p g; g.set(x,y,z);
					visited[x][y][z] = true;
					q.push(g);
				}
				else { paint++;
				}

			}
		}
	}
	cout << "The number of faces needing shielding is "<<paint <<"."<< endl;
}
int main(){
	int N;
	while(cin>>X>>Y>>Z>>N &&X*Y*Z){
		bool m[65][65][65]={{{false}}};

		for(int i=0; i<N; i++){
			int x;
			cin >>x;
			m[x%(X*Y)%X +1][x%(X*Y)/X+1][x/(X*Y)+1] = true;
		}
		bfs(m);
	}
}
