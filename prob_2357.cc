#include<iostream>
using namespace std;
//solved

//recursively find the total number nodes and the left nodes and right nodes;

int a[20];//the number of different tree shapes for a given node
int b[20]; // the accumulate number of tree shapes for a give node;

void init()
{
     a[0] = a[1] = 1;
     b[0] = 0;
     b[1] = 1;
     for (int i = 2; i < 20; i++) {
         for (int j = 0; j < i; j++) {
             a[i] += a[j]*a[i-j-1];
         }
         b[i] = b[i-1] + a[i];
     }
}

void solve(int n)
{
     int i, j, tem;
     if (n == 0) return;
     if (n == 1) {
           cout << 'X';
           return;
     }
//find the number of node
     for (i = 0; n > b[i]; i++);
//the rest
     n -= b[i-1];
     for (j = 0; j < i; j++) {
         tem = a[j]*a[i-1-j];
         if (n > tem)
            n -= tem;
         else
             break;
     }
//left and right node number: j, i-j-1;
//left child
     if (j) {
            cout << '(';
            solve(b[j-1]+1+(n-1)/a[i-1-j]);
            cout << ')';
     }
     cout << 'X';
//right child
     if (j != i-1) {
           cout << '(';
           solve(b[i-1-j-1]+1+(n-1)%a[i-1-j]);
           cout << ')';
     }
}

int main()
{
    init();
    int N;
    while (cin >> N && N) {
          solve(N);
          cout << "\n";
    }
    
    return 0;
}
