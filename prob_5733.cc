#include <iostream>
#include<algorithm>
using namespace std;
//solved
int ns[20];

void solve (int N){
	int p=0;
	while(1){
		bool equal = true;
		for(int i=0; i<N-1; i++){
			equal&=ns[i]==ns[i+1];
		}
		if(equal) {
			cout << p <<" iterations" << endl;
				return;
		}
		if(p>=1000){
			cout << "not attained" << endl;
			return;
		}
		int n0 = ns[0];
		for(int i=0; i<N-1; i++){
			ns[i] =abs( ns[i] -ns[i+1]);
		}
		ns[N-1] = abs(n0- ns[N-1]);
		p++;
	}
}

int main(){
	int N, i=0;
	while(1){
		i++;
		if(i%2 ==1){
			cin>>N;
			if(N==0) break;
		}
		else{
			for(int m=0; m<N; m++){
				cin>>ns[m];
			}
			cout << "Case " << (int) i/2 << ": ";
			solve(N);
		}
	}
}
