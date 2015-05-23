#include<iostream>
using namespace std;
//sloved
//using ans to track the max range sum, and using sum to record the local accumulation
//if sum to current below zero, change sum to zero and start recalculate
int N; 
int a[10000];
void dp(){
	int sum=0;
	int ans=0;
	for(int i=0; i<N; i++){
		sum+=a[i];
		ans=max(ans, sum);
		if(sum<0) sum=0;
	}
	if(ans>0) cout <<"The maximum winning streak is " << ans <<"."<<endl;
		else cout <<"Losing streak." << endl;
}

int main(){
	while(cin>>N && N){
		for(int i=0; i<N; i++){
			cin>>a[i];
		}
		dp();
	}
}
