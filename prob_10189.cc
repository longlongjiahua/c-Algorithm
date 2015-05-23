#include <string>
#include <iostream>
#include <vector>
//solved
using namespace std;
//represent 8 directions as arrays and
loop through those 8 directions to get solution
string ms[100];

int dr[8] = {-1, -1, 0,1, 1, 1 , 0,-1};
int dc[8] = {0,  1,  1,1, 0,  -1,-1,-1};

void solve(int M, int N){
	for(int r=0; r<M; r++){
		string o1;
		for(int c=0;c<N; c++){
			int a=0;
			if(ms[r][c] =='*') { 
				cout << "*"; continue;
				o1+="*";
			}
			//loop eight direction
			for(int d=0; d<8;d++){
				int r2 = r + dr[d];
				int c2 = c +dc[d];
				if(r2>=0 && r2<M && c2>=0 && c2<N &&ms[r2][c2]=='*'){
					a++;
				}
			}
			cout << a;
			o1+=a;
		}
		cout << endl;
	}	

}
int main(){
	int M,N;
	int n=0;
	while(cin>>M>>N){
		n++;
		cin.ignore();
		for(int i=0;i<M;i++){
			string x;
			getline(cin, x);
			ms[i] = x;
	//		cout << x << endl;
		}
		if(M>0 && N>0){
			if(n>1){cout <<endl;}
			cout << "Field #"<<n<<":"<<endl;
			solve(M,N);
		}
	}

}
		
	

