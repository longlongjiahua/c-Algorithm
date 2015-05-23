#include <iostream>
#include <algorithm>
#include <queue>
#include<vector>
using namespace std;
//solved
// use max priority_queue to keep the n lowest numbers, the biggest one
//is we are looking for
int a[30000];
queue<int> get;
void solve(int M){
	priority_queue<int, vector<int>, less<int> > maxpq;
	priority_queue<int, vector<int>, greater<int> > minpq;
	int index = get.front(); get.pop();
	int times=0;
	for(int i=0; i<M; i++){		
		if(minpq.empty() || a[i] <minpq.top()){
		//	cout << "addMac::"<<a[i]<< endl;
			maxpq.push(a[i]);
		}
		else minpq.push(a[i]);
		while(i ==(index -1)){
			times++;
			while(maxpq.size() !=times){
				while(maxpq.size()>times){
				minpq.push(maxpq.top());
				maxpq.pop();
				}
				while(minpq.size()>i-times+1){
					maxpq.push(minpq.top());
					//cout << "tt:" << times << minpq.size() << endl;
					minpq.pop();
				}
			}
			cout << maxpq.top()<<endl;
			if(get.size()==0) return;
				index = get.front();
				get.pop();
		}
	}
}
			
int main(){
	int K;
	cin>>K;
	for(int t=0; t<K; t++){
		cin.ignore();
		cin.ignore();
		int M,N;
		cin >> M >> N;
		for(int i=0; i<M; i++){
			int x1;
			cin >>a[i];
		}
		for(int i=0; i<N; i++){
			int x2;
			cin >> x2;
			get.push(x2);
		}
		if(t>0) cout << endl;
		solve(M);
	}
}
