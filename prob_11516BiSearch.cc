#include <iostream>
#include<algorithm>
#include <iomanip>
//solved
//binary search. From one end to the other end, if the house is not within the two times
//of given distance( 2* mid), add a wifi.
using namespace std;
int a[100001];
int M, N;
bool check(int mid){
	mid *=2;
	int location = a[0] + mid;
	int wifi =1;
	for(int i=1; i<N; i++){
		if(location < a[i]){
			location = a[i]+mid;
			wifi++;
		}
		if(wifi>M) break;
	}
	if(wifi<=M) return true;
	else return false;
}
void solve(){
	if(M>=N) { cout << "0.0" << endl; return;}
	int low =0; int hi = a[N-1];
	while( hi - low >1){
		int mid = (hi+low)/2;
		if(check(mid)){
			hi=mid;
		}
		else low =mid;
	}
	double out = hi/10.0;
	cout << fixed<<setprecision(1)<< out  << endl;
}
int main(){
	int Case;
	cin >>Case;
	while(Case--){
		cin >>M>>N;
		for(int i=0; i<N;i++){
			int x;
			cin>>x; a[i] = x*10;
		}
		sort(a,a+N);
		solve();
	}
}
