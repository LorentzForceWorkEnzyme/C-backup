#include "stdio.h"
int main(void){
  int x;
  printf("请输入一个数：\n");/*提示输入*/
  scanf("%d",&x);
  if(x%2==0)printf("x是偶数\n");
 	else printf("x是奇数\n");
	return 0;
} 
