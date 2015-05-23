#include<iostream>
#include<math.h>
#include<queue>
using namespace std;
//solved
//using kruskal algorithm. data structues are union find and priority-queue
int M, N;
typedef pair<int, int> P;
struct E{
	int x, y, d;
	void set(int a, int b, int c){
		x=a; y =b; d =c;
	}
};
struct Comp {
	bool operator()(const E& a, const E& b) const
	{
		return a.d > b.d;
	}
};
vector<P> v;
int a[1000]; int rank[1000];// for union-find
typedef priority_queue<E, vector<E>, Comp> PQ;
int  init(PQ &q){
	int states=0;
	for(int i=0; i<v.size()-1; i++){
		int x1 = v[i].first; int y1 = v[i].second;
		for(int j=i+1; j<v.size(); j++){
			int x2 = v[j].first; int y2 = v[j].second;
			//a = sqrt(pow(a, 2) + pow(b, 2))
			int  d =pow((x1-x2),2) + pow((y1-y2),2);
			if(d>=N*N) states++;
			E e; e.set(i, j, d);
			q.push(e);
		}
	}
	for(int i=0; i<v.size(); i++){
		a[i] = i; rank[i] =0;
	}
	return states;
}
int findParent(int n){
	return (n ==a[n] ? n : findParent(a[n]));
}
bool isSameSet(int p, int k){
	return (findParent(p) == findParent(k) ?true :false);
}

void Union(int p, int k){
	if(findParent(p) != findParent(k)){
		p = findParent(p);
		k= findParent(k);
		if(rank[p] >= rank[k]){
			rank[p]++;
			a[k] = p;
		}
		else {
			rank[k]++;
			a[p] = k;
		}
	}
}

void kruskal(){
	PQ q; init(q);
    int	states =1;
	double length_within =0;
	double length_across=0;
	while(!q.empty()){
		E e = q.top();	q.pop();
		if(findParent(e.x) !=findParent(e.y)){
			if(e.d >= N*N){
				length_across +=sqrt(e.d*1.0);
				states++;
			}
			else length_within +=sqrt(e.d*1.0);
			Union(e.x, e.y);
		}	
	}
	cout << states<< " " << (int) round(length_within) << " " << (int) round(length_across) <<endl;;
}

int main(){
	int Case;
	cin >> Case;
	int n=1;
	//cout << n << endl;
	while(cin >>M >>N){
		cout << "Case #"<< n++ <<": ";
		v.clear();
		for(int i=0; i<M; i++){
			int x, y;
			cin >> x >>y;
			P p1 =make_pair(x, y);
			v.push_back(p1);

		}
		kruskal();
	}
}
