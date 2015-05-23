#include <iostream>
#include<cmath>
#include <string>
using namespace std;
int N, count;
int row[16];
//solved
//basically I use backgrack and bit operation to attach this problem.
void solve(int r, int c, int d1, int d2){//d1 and d2 represent diagonal 1 and 2 respectively
	if(r==N){
		count++;
		return;
	}
	int nd1 = d1>>r;
	int nd2 = d2>>(N-r-1);//nd1 and nd2: the current diagonals by shift d1 r and d2 N-r-1
	int canput = row[r] & c & nd1 & nd2; //computer the place can put queen
	int cput;
	while(canput){
	 cput = canput & (-canput); //the position in this loop used to put queeue;
		//c^cput, d1^(cput<<r), d2^(cput<<(N-r-1)): the rest place that can put queen after exclusion of cput 
		solve(r+1, c^cput, d1^(cput<<r), d2^(cput<<(N-r-1)));
		canput ^=cput;
	}
}

int main(){
	int mcase =0;
	while(cin>>N && N>0){
		mcase++;
		cin.ignore();
		for(int i=0; i<N; i++){
			string st;
			getline(cin, st);
			row[i] = (1<<N)-1;
//This for loop will generate row[i] and indicate the place with bit set can  put queen
			for(int k=0; k<N; k++){
			   if(st[k] =='*') row[i] ^= 1<<(N-k-1);
			}
		}
		count = 0;
		solve(0, (1<<N)-1, (1<<(2*N-1)) -1, (1<<(2*N-1))-1);////initialize all places can put queen
		cout << "Case " << mcase << ": " << count << endl;
	}
}
