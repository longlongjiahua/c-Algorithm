#include<cstdio>  
#include<iostream>  
#include<cstring>  
#include<string>  
#include<queue>  
#include<cstdlib>  
#include<algorithm>
using namespace std;  
#define N 201  
#define inf 45000000  
//solved 
//bfs and check  
int dir[8][2] = { { 0, 1 }, { 1, 1 }, { 1, 0 }, { 1, -1 }, { 0, -1 },  
        { -1, -1 }, { -1, 0 }, { -1, 1 } };  
int visited[N][N], done[N * N], result[N * N];  
char grid[N][N];  
int n, m, idx, Total;  
int T = 1;
struct Pos {  
	int x, y;  
} u, v, qu[N * N];  
  
void bfs(int x, int y) {  
	visited[x][y] = idx;  
	grid[x][y] = '0';  
	u.x = x;  
	u.y = y;  
	int l = 0, r = 1;  
	qu[0] = u;  
	while (l < r) {  
		u = qu[l++];  
		for (int i = 0; i < 8; i++) {  
			v.x = u.x + dir[i][0];  
			v.y = u.y + dir[i][1];  
			if (v.x >= 1 && v.x <= n && v.y >= 1 && v.y <= m && grid[v.x][v.y] == '1') {  
				visited[v.x][v.y] = idx;  
				grid[v.x][v.y] = '0';  
				qu[r++] = v;  
			}  
		}  
	}  
	if (r < 5)  
		done[idx] = 1;  
}  
  
void solve(int x, int y) {  
	u.x = x;  
	u.y = y;  
	int i = 1, to = 6;  
	qu[0] = u;  
	for (;;) {  
		int flag = 0;  
		for (int j = to; j != to || !flag; j = (j + 1) % 8) {  
			if (j == to)  
				flag = 1;  
			v.x = u.x + dir[j][0];  
			v.y = u.y + dir[j][1];  
			if (v.x >= 1 && v.x <= n && v.y >= 1 && v.y <= m && visited[v.x][v.y] == visited[x][y]) {  
				u.x = u.x + dir[(j + 7) % 8][0];  
				u.y = u.y + dir[(j + 7) % 8][1];  
				for (j = 0; j < 8; j++) {  
					if (v.x + dir[j][0] == u.x && v.y + dir[j][1] == u.y) {  
						to = j;  
						break;  
					}  
				}  
				qu[i++] = v;  
				u = v;  
				if (i >= 4 && qu[0].x == qu[i - 2].x && qu[0].y == qu[i - 2].y  
						&& qu[1].x == qu[i - 1].x && qu[1].y == qu[i - 1].y) {  
					result[Total++] = i - 2;  
					return;  
				}  
				break;  
			}  
		}  
	}  
}  
  
int main() {  
	while (scanf("%d%d", &n, &m) && n && m){
		for (int i = 1; i <= n; i++)  
			scanf("%s", grid[i] + 1);  
		idx = 0;  
		memset(visited, 0, sizeof(visited));  
		for (int i = 1; i <= n; i++) {  
			for (int j = 1; j <= m; j++) {  
				if (grid[i][j] == '1') {  
					idx++;  
					done[idx] = 0;  
					bfs(i, j);  
				}  
			}  
		}  
		Total = 0;  
		for (int i = 1; i <= n; i++) {  
			for (int j = 1; j <= m; j++) {  
				if (visited[i][j] && !done[visited[i][j]]) {  
					done[visited[i][j]] = 1;  
					solve(i, j);  
				}  
			}  
		}  
		printf("Case %d\n", T++);  
		if (Total) {  
			sort(result, result + Total);  
			for (int i = 0; i < Total; i++)  
				printf("%d%s", result[i], (i == Total - 1) ? "\n" : " ");  
		} else  
			printf("no objects found\n");  
	}  
	return 0;  
}  
