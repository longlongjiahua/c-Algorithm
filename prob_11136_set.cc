#include <set>
#include <iostream>
using namespace std;
//solved
//take advantage of the feature of STL set which is sorted. So I just need to get the 
//difference between first and last elements and erase them each round
int main(){
	int N;
	while(cin>>N && N>0){
		
		multiset<int> a;
		long long out =0;
		multiset<int>::iterator st, end;
		for(int i=0; i<N; i++){
			if(i==0){
				out=0;
				a.clear();
			}
			int M;
			cin>>M;
			while(M--){
				int x;
				cin>>x;
				a.insert(x);
			}
			st = a.begin();
			end = a.end();
			end--;
			out+=(*end -*st);
			a.erase(end);
			a.erase(st);
		}
		cout << out << endl;
	}
}
				



