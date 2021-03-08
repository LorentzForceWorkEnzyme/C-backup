#include<stdio.h>
 int main(void){
 	char str[100];
 	int cnt=0,i=0;
 	for(i=0;i<100;i++){
 			scanf("%c",&str[i]);
 			cnt=i;
 			if(str[i]==-1)break;
	 }
	 for(i=0;i<cnt;i++){
 		if(str[i]<='z'&&str[i]>='a') str[i]-=32;
 			else if(str[i]<='Z'&&str[i]>='A') str[i]+=32;
 		}
 	 for(i=0;i<cnt;i++)
	  {
	 	 putchar(str[i]);
	  }
	  getchar();
	  return 0;
 }
 