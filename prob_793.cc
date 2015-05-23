#include <iostream>
#include <vector>
#include <sstream>
using namespace std;
//solved
//basic idea is to implment union-find, include three functions:
//Union() to union two sets, findParent() and isSameSet();
int P[1000];
int R[1000];
int makeSet(int n){
	for(int i=1; i<=n; i++){
		P[i] = i;
		R[i] =0;
	}	
}

int findParent(int n){
	return (n ==P[n] ? n : findParent(P[n]));
}
bool isSameSet(int p, int k){
	return (findParent(P[p]) == findParent(P[k]) ?true :false);
}

void Union(int p, int k){
	if(findParent(P[p]) != findParent(P[k])){
		p = findParent(P[p]);
		k= findParent(P[k]);
		if(R[p] >= R[k]){
			R[p]++;
			P[k] = p;
		}
		else {
			R[k]++;
			P[p] = k;
		}
	}
}


int main(){
	int N;
	cin >> N;
	cin.ignore();
	cin.ignore();
	for(int x=0;x<N;x++){
		string str;
		int i=0;
		int suc=0; int unsuc=0;
		while(getline(cin, str)!=NULL && !str.empty()){
			i++;
			stringstream ss(str);
			if(i==1){
				int n;
				ss>>n;
				makeSet(n);
			}
			else {
			 	int m,n;
				char c;
				ss>>c>>m>>n;
				if(c=='c'){
					Union(m,n);
				}
				else {
					isSameSet(m,n) ? suc++ : unsuc++;
				}
					
		
			}
		}
		if(x>0) cout << endl;
		cout << suc << "," << unsuc << endl;
	}
}

