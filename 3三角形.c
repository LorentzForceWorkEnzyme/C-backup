#include<stdio.h>
int main(void){
	int a=0,b=0,c=0;
	printf("�����������ε������ߣ�\n");
	scanf("%d%d%d",&a,&b,&c);	
	if(a+b>c&&a+c>b&&b+c>a){
		printf("%5d%5d%5d��",a,b,c);
		if(a==b||b==c||c==a) printf("����");
	 	if(a*a+b*b==c*c||b*b+c*c==a*a||a*a+c*c==b*b)printf("ֱ��");	
		printf("������\n");
	}else printf("������������\n");
	return 0;
}
