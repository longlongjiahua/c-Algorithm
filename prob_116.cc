#include<iostream>
#include<algorithm>
using namespace std;
//solved
//idea: walk from righ to left. and base case is the last columns 	m[i][N-1]=a[i][N-1];
//to calculate the row i-1, i, i+1 by using for(int dr=-1; dr<=1; dr++) int r1 = (i+dr+M)%M;
typedef pair<int, int> P;
int M, N;
long long a[101][101];
long long m[101][101];
P track[101][101];

void dp(){
	if(N==1){
		long long mMin =a[0][0]; int choose =0;
		for(int i=1;i<M;i++){
			if(mMin>a[i][0]) {mMin=a[i][0]; choose = i;}
		}
		cout << (choose+1) << endl << mMin<< endl;
	}
	else {
		for(int j=N-2; j>=0; j--){
			for(int i=0; i<M; i++){
				long long mMin = 1<<30; 
				int b[3];
				for(int dr=-1; dr<=1; dr++){
					int r1 = (i+dr+M)%M;						
					b[dr+1] = r1;
				}
				sort(b, b+3);
				for(int e=0; e<3; e++){
					int r1 = b[e];	
					if(m[r1][j+1]<mMin) {
						mMin = m[r1][j+1];
						P t = make_pair(r1,j+1);
						track[i][j]=t;     						
					}
					m[i][j] = mMin+a[i][j];
				}
			}
		}
		int out=m[0][0]; int choose=0;
		for(int i=1; i<M; i++){
			if(out >m[i][0]){
				choose = i;
				out = m[i][0];
			}
		}
		P cur = track[choose][0];
		cout << (choose+1) << " " << (cur.first+1);
		while(cur.second <N-1){
			cur = track[cur.first][cur.second];
			cout << " "<<(cur.first+1);
		}

		cout << endl<<out << endl;
	}
}
int main(){
	while(cin>>M>>N &&M && N){
		for(int i=0; i<M;i++){
			for(int j=0; j<N;j++){
				cin>>a[i][j];
				m[i][j] = 1<<30;
			}
		}
		for(int i=0; i<M; i++){
			m[i][N-1]=a[i][N-1];
		}
		dp();
	}

}

