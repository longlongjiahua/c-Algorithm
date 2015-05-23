#include <iostream>
#include<cstring>
typedef long long LL;
using namespace std;
//solved
//dp  d[w][h] = d[w-1][h+1]; ||	d[w][h] = d[w-1][h+1] + d[w][h-1]; 
LL d[31][61];
int M=30;
void dp(){
	memset(d, -1, sizeof(d));
	for(int i=0; i<=2*M; i++)  d[0][i]=1;
	d[0][0]=0;
	for(int w=1; w<=M; w++){
	for(int h=0; h<=2*M; h++){
			if(h==0){
				d[w][h] = d[w-1][h+1];
			}
			else {
				d[w][h] = d[w-1][h+1] + d[w][h-1];
			}
		}
	}
}
	
int main(){
	
  dp();
	int N;
	while(cin>>N && N){
		cout << d[N][0] << endl;

	}
}
