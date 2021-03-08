#include <stdio.h> 
int main(void){
  int a[10];/*定义数组*/
  int cnt,i;/* i循环变量 count 正数个数*/
  for(i=0;i<10;i++){/*循环输入*/
   	scanf("%d",&a[i]);
  }
  	cnt=0;
  for(i=0;i<10;i++){/*查找正数*/
    if(a[i]>0){
		cnt++;
  	} 
  }
	printf("数组中正数有：%d个/n",cnt);
	getchar();
	return 0;
}
