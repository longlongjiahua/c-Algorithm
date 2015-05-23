#include<iostream>
#include<string>
#include<sstream>
#include<stack>
#include <stdlib.h> 
using namespace std;
//sloved
//idea: base case a[0]
//to get i-th longest increasing subset(LIS), scan from 0 to i-1 to find a j and make LIS of j is the largest
int a[10000];
struct lis {
	int p;
	int len;
	void set(int x, int y) {
		p=x; len = y;
	}
} LIS[10000];
int N;

void f(){
	if(N==1) { cout << "Max hits: 1"<< endl <<a[0]<<endl; return;}
	lis l; l.set(0, 1);
	LIS[0] = l;
	int mlen=0;	int mi; //remember the i which has the longgest inreasing length
	for(int i=1; i<N; i++){
		int ans =0;
		for(int j=0; j<i; j++){
			if(a[i] <= a[j]) continue;
			if(ans<LIS[j].len){	
				ans = LIS[j].len;
				lis l; l.set(j, LIS[j].len+1);
				LIS[i]=l;
				if(LIS[j].len+1 >mlen){
					mlen = LIS[j].len+1;
					mi = i;
				}
			}
		}
		if(ans==0) {// a new start point; 
			lis l; l.set(i,1); LIS[i] = l;
		}
	}
	cout << "Max hits: "<< mlen << endl;
	stack<int> v; v.push(a[mi]);//cout <<a[mi];
	while(mi != LIS[mi].p){
		mi = LIS[mi].p; v.push(a[mi]);
	}
	while(!v.empty()) {cout << v.top()<< endl; v.pop();}
}


int main(){
	int M;
	cin>>M;
	cin.ignore();
	string str;
	getline(cin, str);
	for(int i=0; i<M; i++){
		N=0;
		while(getline(cin, str)!=NULL && !str.empty()){
			a[N] = atoi( str.c_str() );
			N++;	
		}
		if(i>0) cout << endl;
		f();
	}
}
