 #include<iostream>            
 #include<cstring>
 #include<string>
 #include<algorithm>
 #include<map>               
 #include<set>
 using namespace std;
 const int MAXN = 30;
 //solved
//idea 1) id could not be a name if it is not stay=>build graph g[i][j] =false if i is not  j; 
//	2) calculate the max match number matchN; then, if g[i][i]=false change to g[i][i] =true, the max match number < matchN, then i is j
 string real[MAXN], int2name[MAXN];    
 map< string, int >map1, map2;  //username and id
 bool g[MAXN][MAXN], vis[MAXN];   
 int n, cx[MAXN], cy[MAXN], nx, ny;
 set<int>stay;                   
 pair<string, int>pair1[MAXN];  
 int relation[MAXN];                    
 void init(){
	 memset( g, true, sizeof(g) );
	 map1.clear(); map2.clear();
	 stay.clear();
 }
 
int dfs( int u ){
	int v;
	for( v = 1; v <= ny; v++ ){
		if( g[u][v] && !vis[v] ){
			vis[v] = true;
			if( !cy[v] || dfs( cy[v] ) ){
				cx[u] = v;
				cy[v] = u;
				return 1;
			}
		}
	}
	return 0;
}
 
int MaxMatch(){
	int u, ret;
	memset( cx, 0, sizeof(cx) );
	memset( cy, 0, sizeof(cy) );
	ret = 0;
	for( u = 1; u <= nx; u++ ){
		if( !cx[u] ){
			memset( vis, false, sizeof(vis) );
			ret += dfs( u );
		}
	}
	return ret;
}
 
void solved(int matchN){   
	for(int i = 1; i <= n; i++ ){
		pair1[i] = make_pair(int2name[i], i);
		relation[i] = 0;
		for(int j = 1; j <= n; j++ ){
			if( g[j][i] ){
				g[j][i] = false;
				int tmp = MaxMatch();
				if(tmp<matchN){
					relation[i] = j;
				}
				g[j][i] = true;
			}    
		}
	}
	sort(pair1 + 1, pair1 + n +1 ); 
}
 
void print(){
	for( int i = 1; i <= n; i++ ){
		cout<< pair1[i].first << ":"; 
		if( relation[pair1[i].second] == 0 )
			cout<< "???" << endl; 
		else 
			cout<< real[relation[pair1[i].second]] << endl; 
	}
}
int main() {
	int Case; cin >>Case;
	for(int mCase=0; mCase<Case;mCase++){
		if(mCase>0) cout << endl;
		init();
		while(cin >> n){//read real name
			for( int i = 1; i <= n; i++ ){
				cin>>real[i];
				map1[real[i]] = i;
			}
			int cnt =0;
			string head, name;
			getline(cin, name); // consume blank
			while(getline(cin, name) !=NULL && name[0] !='Q'){
				head = name[0];
				name = name.substr(2);
				if(head == "E" ){
					if(map2[name] == 0 ){
						map2[name] = ++cnt;
						int2name[cnt] = name;
					}
					int y = map2[name];
					stay.insert( y );    // set 的插入 
				}
				else if( head == "L" ){
					int y = map2[name];
					stay.erase(y);        // set 的消去元素 
				}
				else{ //'M'
					int x = map1[name];
					for( int i = 1; i <= n; i++ )if( stay.find( i ) == stay.end() )
						g[x][i] = false;    // 去掉没有关系的边 
				}
			}
			nx = ny = n; 
			break;
		}
		int matchN=MaxMatch();
		solved(matchN);
		print();
	}
}
