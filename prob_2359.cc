#include<vector>
#include<cstring>
#include<iostream>
#include<iomanip>
#include<string>
using namespace std;
//solved
//idea using Floyd find the shortest Path and record the path;
const int MAXN = 31;
const int MAXD = 0x3f3f3f3f;
vector<int> apass[MAXN][MAXN];
int mdist[MAXN][MAXN];
int dist[MAXN][MAXN];
int next[MAXN][MAXN];
string city[MAXN];
int m, n;
int nCity;

void mSort(vector<int> &verc, int a, int b, int dis)
{
    int i, j, di, dj, t;
    for ( i = 0; i < verc.size(); i ++)
    {       
        for ( j = i + 1; j < verc.size(); j ++)
        {           
            di = ( dist[a][verc[i]] - dis + 50 ) / 100;
            dj = ( dist[a][verc[j]] - dis + 50 ) / 100;
            if ( di > dj || di == dj && city[verc[i]]  > city[verc[j]])
            {
                t = verc[i];
                verc[i] = verc[j];
                verc[j] = t;
            }
        }
    }
}

void Path() { // find path Floyd
        int dis,s, a, b; float d;
	for (a = 0; a < n; a ++ )
		for (b = 0; b < n; b ++ )
			if ( dist[a][b] < MAXD )
				next[a][b] = b;
	for (s = 0; s < n; s ++ )  //find shortest Path Floyd
		for (a = 0; a < n; a ++ )
			if ( dist[a][s] < MAXD )
				for (b = 0; b < n; b ++ )
					if (dist[a][b] > dist[a][s] + dist[s][b]){
						dist[a][b] = dist[a][s] + dist[s][b];
					}
	for (a = 0; a < n; a ++ )// find the next Node
		for (b = 0; b < n; b ++)
			if ( a != b)
				for (s = 0; s < n; s++)
					if ( s != a && s != b &&  mdist[a][s] < MAXD 
							&& dist[a][b] == dist[a][s] + dist[s][b] ){
						next[a][b] = s;
						break;
					}

	for ( int a = 0; a < n; a ++ )
		for ( int b = 0; b < n; b ++ )
			if ( a != b ){
				apass[a][next[a][b]].push_back(b);
			}

	cin >> s;
	for ( int i = 0 ; i < s ; i ++ ){
		if(i>0) cout << endl;
		cin >> a >> b >> d;
		dis = (int) ( d * 100 + 0.5f );
		mSort( apass[a][b], a, b, dis );
		for (int j = 0; j < apass[a][b].size(); j++){
			nCity = apass[a][b][j];
			if ( city[nCity] != "" )
				//cout << setw(20) << setiosflags(ios_base::left)
				cout<< city[nCity] <<" " << ( dist[a][nCity] - dis + 50 ) / 100 << endl;            
		}


	}
}
int main(){
    int Case;
	cin >>Case;
	for(int mCase=0; mCase<Case; mCase++){
		cin.ignore();
		if(mCase>0) cout << endl;
		int nCity,s;
		int a, b, dis, i, j;
		float d;
		for(i=0; i<MAXN; i++)  for(int j=0; j<MAXN; j++) apass[i][j].clear();
		cin >> n >> m >> nCity;
		for ( a = 0; a < n; a ++ ){
			for ( b = 0; b < n ; b ++ ){
				if(a==b) dist[a][b] = mdist[a][b] =0;
				else dist[a][b] = mdist[a][b] = MAXD;   
			}
		}
		for ( i = 0; i < m; i ++ ) // road
		{
			cin >> a >> b >> d;
			dis = (int) (d * 100 + 0.5f); 
			mdist[a][b] = mdist[b][a] 
				= dist[a][b] = dist[b][a] = dis;
		}
		for ( i = 0; i < nCity; i ++ ){
			cin >> a;
			cin >> city[a];
		}
		Path();
	}
    return 0;
}
