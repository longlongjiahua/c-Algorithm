#include<iostream>
using namespace std;
//solved
//base case m[i][0] =0 (i from 0 to  total money)
//          m[0][j] =1( j #of coins )
// transation: m[t][k] = f(t-d[k], k) + f(t, k-1). here f(t-d[k], k) represents choosing k-th coins, and f(t, k-1) represents choosing (k-1)th coins

int N = 7490;
int M=6;
int d[] ={0,1,5,10,25,50};
long long  m[7490][6];
 
long long  f(int t, int k){
	//cout << t << " " << k << endl;
	if(t<0 ||k<0) return 0;
	if(m[t][k] !=-1) return m[t][k];
	m[t][k] = f(t-d[k], k) + f(t, k-1);
	return m[t][k];
}
	



int main(){
	//fill( &m[0][0], &m[0][0]+sizeof(m), -1); 
	for(int i=0; i<N; i++) {
		for (int k=0; k<M; k++) m[i][k] = -1;
	}

	for(int i=0; i<N; i++){
		m[i][0] =0;
	}
	for(int i=0; i<M;i++){
		m[0][i] =1;
	}
	int n;
	while(cin>>n){
         cout << f(n, 5)<< endl;
	}


}
