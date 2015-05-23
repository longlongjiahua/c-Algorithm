#include<string>
#include<iostream>
#include<stdio.h>
using namespace std;
//solved
//always has O：4*n-1  H：4*n-3
char h2os[60][60];
void lr(int i,int j){
        h2os[4*i-4][4*j-1]='|';
        h2os[4*i-5][4*j-1]='H';
}
void nr(int i,int j){
        h2os[4*i-2][4*j-1]='|';
        h2os[4*i-1][4*j-1]='H';
}
int main(){
	int i,j,Case=0,n,mark[15][15];
	while(scanf("%d",&n),n!=0){
		for(i=0;i<50;i++)
			for(j=0;j<50;j++)
				h2os[i][j]=' ';
		for(i=1;i<=n;i++)
			for(j=1;j<=n;j++){
				scanf("%d",&mark[i][j]);
				h2os[4*i-3][4*j-1]='O';
				h2os[4*i-3][4*j-3]='H';
				if(j==n)h2os[4*i-3][4*j+1]='H';
			}
		for(i=1;i<=n;i++)
			for(j=1;j<=n;j++){
				if(mark[i][j]==1)
					h2os[4*i-3][4*j-2]=h2os[4*i-3][4*j]='-';
				else if(mark[i][j]==-1){
					h2os[4*i-2][4*j-1]=h2os[4*i-4][4*j-1]='|';
					h2os[4*i-1][4*j-1]=h2os[4*i-5][4*j-1]='H';
				}
				else{
					if(i==1){
						nr(i,j);
					}
					else if(i==n){
						lr(i,j);
					}
					else{
						if(h2os[4*i-5][4*j-1]==' ')
							lr(i,j);
						else nr(i,j);
					}
					if(j==1)h2os[4*i-3][4*j-2]='-';
					else if(j==n)h2os[4*i-3][4*j]='-';
					else{
						if(h2os[4*i-3][4*j-4]=='-')
							h2os[4*i-3][4*j]='-';
						else h2os[4*i-3][4*j-2]='-';
					}
				}
			}
		Case++;
		if(Case>1)puts("");
		printf("Case %d:\n\n",Case);
		for(i=1;i<=4*n+3;i++)
			printf("*");
		printf("\n");
		for(i=1;i<=4*n-3;i++){
			printf("*");
			for(j=1;j<=4*n+1;j++)
				printf("%c",h2os[i][j]);
			printf("*\n");
		}
		for(i=1;i<=4*n+3;i++)
			printf("*");
		printf("\n");

	}
}
