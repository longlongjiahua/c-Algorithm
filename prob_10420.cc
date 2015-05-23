#include <iostream>
#include <map>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
	string str;
	vector<string> cts;
	getline(cin, str);
	map<string, int> times;
	while(getline(cin, str)!=NULL){
		int a = str.find(" ", 0);
		times[str.substr(0, a)]++;
	}
	   for(map<string, int>::iterator i = times.begin(); i!=times.end();i++){
	   cout << i->first <<" " << i->second << endl;
	   }
}

