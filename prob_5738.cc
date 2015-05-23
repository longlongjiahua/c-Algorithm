#include <string>
#include <iostream>
#include <queue>
#include <map>
using namespace std;
//solved
//dfs : when the distance is smaller than current one, set path; if equal, old path + new path
#define MAXN 1005
#define MAX_INT (int)0x7FFFFFFF
string m[MAXN];

int dr[]={-1,0,1,0};
int dc[]={0,1,0,-1};
int d[] ={0,1,2,3};  //respresent N E S W
map<char, int> dirs;
struct State{
	int r,c;
	int face;
};
int mindist[MAXN][MAXN][4]; //the minimum distance from the start position to (i, j) with certain direction
int npaths[MAXN][MAXN][4]; //the number of shortest paths from the start position to (i, j) with certain direction
int R,C;
int x1, y1; //start
int x2, y2; //end
int  MOD;
int final_steps = MAX_INT;
int final_results=0;
void init(){
	for(int i=0; i<R;i++){
		for(int j=0; j<C; j++){
			for(int k =0; k<4;k++){
				mindist[i][j][k] = MAX_INT;
				npaths[i][j][k] = 0;
			}
		}
	}
	final_steps = MAX_INT;
	final_results=-1;// can't initialize final_results to 0, because 0 is a
}

void check(int r, int c, int face,int dist,int path, queue<State> &q){	//r2 c2
	if(dist > mindist[r][c][face]-1) return;
	else {
		if(dist == mindist[r][c][face]-1)
			npaths[r][c][face] = (npaths[r][c][face]+ path)%MOD;
		else {// if mindist[r][c][face] >dist+1 first time reach this place r c with direcion face or a new small distance
			if(mindist[r][c][face] >dist+1){  //update
				mindist[r][c][face]=dist+1;
				npaths[r][c][face]=path;
			}
			State st;
			st.r =r, st.c = c, st.face= face;
			q.push(st);
		}
	}
}

void solve( int Face){
	init(); 
	queue<State>q;
	State start;
	mindist[x1][y1][Face] = 0;
	npaths[x1][y1][Face]=1;
	start.r=x1, start.c=y1, start.face = Face;
	q.push(start);
	while(!q.empty()){
		State curr = q.front();
		q.pop();
		int face = curr.face;
		int mDist = mindist[curr.r][curr.c][face];
		int mPath = npaths[curr.r][curr.c][face] %MOD;
		//check before you move forward. You may already be at the destination
		if (curr.r == x2 && curr.c == y2) {
		  final_results = mPath;
		  return;
		}
		//move forward;
		int r2=curr.r+dr[face];
		int c2=curr.c+dc[face];	
		if(r2==x2 && c2==y2){  //reach target
			if(mDist<final_steps-1) {
				final_steps = mDist+1;
				final_results = npaths[curr.r][curr.c][face]%MOD;
				mindist[r2][c2][face] = final_steps;
			}
			else if(mDist==final_steps-1){
				final_results = (final_results + npaths[curr.r][curr.c][face])%MOD;
			}
			continue;
		}
		if(r2>=0 && r2<R && c2>=0 && c2<C &&m[r2][c2] !='*'){
			check(r2,c2, face,mDist,mPath, q);
		}
		for(int f=1; f <4; f+=2){  //just turn left and right
			face = (curr.face + f)%4;
			check(curr.r,curr.c,face, mDist,mPath, q);
		}
	}
}
int main(){
	string st = "NESW";
	for(int i=0; i<st.length(); i++){
		dirs[st[i]] = i;
	}
	int Case=0;
	while(cin>>R>>C>>MOD && MOD){
		Case++;
		cin.ignore();
		for(int i=0; i<R;i++){
			string str;
			getline(cin, str);
			m[i] = str;
			//	cout << str << endl;
		}
		char d;
		cin>>x1>>y1>>x2>>y2>>d;
		int face = dirs[d];
		solve(face);
		cout << "Case "<<Case<<": "<<MOD << " ";
		// for impossible case
		if(final_results == -1)  cout << "-1" << endl;
		else {
			cout << final_results%MOD << endl;
		}
	}
}


