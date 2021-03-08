#include<stdio.h>
int main(void){
	int number[4][4]={{0}};//全部初始化为0 
	int i,j,cnt=10;
	for(i=0;i<4;i++){
		for(j=3;j>=3-i;j--){
			number[i][j]=cnt;
			cnt--;
		}
	}
	for(i=0;i<4;i++){
		for(j=0;j<4;j++){
			printf("%4d",number[i][j]);
		}
		putchar('\n');
	}
	return 0;
} 
