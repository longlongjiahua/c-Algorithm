#include<cstdio>  
#include<iostream>  
using namespace std;  
  
int solve(int k){  
    int pre;  
    int m = k+1;  
    int n = 2*k;  
    while(m){  
        if((m-1)%n >= k){  
            pre = (m-1)%n;  
            int i;  
            for(i = 2 ; i <= k ; i++){  
               int x = (pre+m-1)%(n-i+1);   
               if(x < k || x >= 2*k)  
                   break;  
               else  
                   pre = x;  
            }   
            if(i == k+1)  
                return m;  
        }  
        m++;  
    }  
}  
  
int main(){  
    int k , mas[16];  
    for(int i = 1 ; i <=14 ; i++)  
        mas[i] = solve(i);  
    while(scanf("%d" , &k) && k)  
        printf("%d\n" , mas[k]);  
    return 0;  
}  
