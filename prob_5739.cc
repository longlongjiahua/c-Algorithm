#include <iostream>  
#include<string>
#include <cstdio>  
#include <cstring>  
#include <map>   
using namespace std; 
//solved
//use a map to store the username and check the existance
map<string,int> username;  
char tName[90], s[90];  
int len;  
int mLen,n; 
int main(){  
    int Case = 0;  
    while(scanf("%d %d",&n,&mLen)==2 &&  n!=0&&mLen!=0){ 
        Case++;
	cout << "Case " << Case << endl;
        username.clear();  
        int ct = 0;  
        char re;  
        for (int k=0;k<n;k++) {
            scanf("%s",tName);  
            len = 0;  
            re = getchar();  
            int i=0;  
	    while(i<strlen(tName)){
		    if((tName[i]>='A'&&tName[i]<='Z')  ||(tName[i]>='a'&&tName[i]<='z')){
			    s[len++] = tolower(tName[i]);
				break;
		    }  
		 i++;  
	    }
            scanf("%s",tName);  
            re = getchar();  
            while (re!='\n')  
            {  
                scanf("%s",tName);  
                re = getchar();  
            }  
            i=0;  
            while(i<strlen(tName)&&len<mLen){  
		    if((tName[i]>='A'&&tName[i]<='Z')  ||(tName[i]>='a'&&tName[i]<='z')){
			    s[len++] = tolower(tName[i]);
		    }  
		 i++;  
	    }
            s[len] = '\0';  
            string toj (s);  
            int no = 0;  
            char num[255];  
            while(username[toj]==1)  
            {  
                no++;  
                if (no==1&&len==mLen)  
                    s[len-1]='\0';  
                if (no==10)  
                {  
                    if (len==mLen)  
                        s[len-2]='\0';  
                    if (len==(mLen-1))  
                        s[len-1]='\0';  
                }  
                sprintf(num, "%d", no);  
                toj = s;  
                toj += num;  
            }  
            username[toj]++;  
            printf("%s\n",toj.c_str());  
        }  
  
    }  
    return 0;  
}
