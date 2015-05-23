#include <cstdio>
#include <string>
#include<cstring>
#include <iostream>     
#include <algorithm>    
#include <stdio.h>     
using namespace std;
#define MAX_N 200100                                
//solved. SA code from textbook. O(n logn) 
//find the first suffix with length >= original length

 
string T;                        // the input string, up to 100K characters
int n;                                             // the length of input string
int RA[MAX_N], tempRA[MAX_N];             // rank array and temporary rank array
int SA[MAX_N], tempSA[MAX_N];         // suffix array and temporary suffix array
int c[MAX_N];
 
void countingSort(int k)
{
    int i, sum, maxi = max(300, n);        // up to 255 ASCII chars or length of n
    memset(c, 0, sizeof c);                               // clear frequency table
    for (i = 0; i < n; i++)                    // count the frequency of each rank
        c[i + k < n ? RA[i + k] : 0]++;
    for (i = sum = 0; i < maxi; i++)
    {
        int t = c[i];
        c[i] = sum;
        sum += t;
    }
    for (i = 0; i < n; i++)               // shuffle the suffix array if necessary
        tempSA[c[SA[i] + k < n ? RA[SA[i] + k] : 0]++] = SA[i];
    for (i = 0; i < n; i++)                          // update the suffix array SA
        SA[i] = tempSA[i];
}
 
void constructSA()                // this version can go up to 100000 characters
{
    int i, k, r;
    for (i = 0; i < n; i++) RA[i] = T[i] - '.';                // initial rankings
    for (i = 0; i < n; i++) SA[i] = i;          // initial SA: {0, 1, 2, ..., n-1}
    for (k = 1; k < n; k <<= 1)              // repeat sorting process log n times
    {
        countingSort(k);       // actually radix sort: sort based on the second item
        countingSort(0);               // then (stable) sort based on the first item
        tempRA[SA[0]] = r = 0;                  // re-ranking; start from rank r = 0
        for (i = 1; i < n; i++)                         // compare adjacent suffices
            tempRA[SA[i]] =      // if same pair => same rank r; otherwise, increase r
                (RA[SA[i]] == RA[SA[i-1]] && RA[SA[i]+k] == RA[SA[i-1]+k]) ? r : ++r;
        for (i = 0; i < n; i++)                          // update the rank array RA
            RA[i] = tempRA[i];
    }
}
int main()
{
    char cc[MAX_N];
    int t;
    scanf("%d", &t);
 
    for(int i = 0 ; i < t ; i++)
    {
        scanf("%s", cc);
        T = cc;
 
        T += cc;
        n = T.size();
        T[n++] = '~';
        constructSA();
 
        for (int j = 0; j < n; j++)
        {
            if(SA[j] < n/2)
 
            {
                printf("%d\n", (SA[j] + 1));
                break;
            }
        }
    }
    return 0;
}
