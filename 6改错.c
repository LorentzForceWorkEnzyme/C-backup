#include <stdio.h> 
int main(void){
  int a[10];/*��������*/
  int cnt,i;/* iѭ������ count ��������*/
  for(i=0;i<10;i++){/*ѭ������*/
   	scanf("%d",&a[i]);
  }
  	cnt=0;
  for(i=0;i<10;i++){/*��������*/
    if(a[i]>0){
		cnt++;
  	} 
  }
	printf("�����������У�%d��/n",cnt);
	getchar();
	return 0;
}
