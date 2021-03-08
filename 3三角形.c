#include<stdio.h>
int main(void){
	int a=0,b=0,c=0;
	printf("请输入三角形的三个边：\n");
	scanf("%d%d%d",&a,&b,&c);	
	if(a+b>c&&a+c>b&&b+c>a){
		printf("%5d%5d%5d是",a,b,c);
		if(a==b||b==c||c==a) printf("等腰");
	 	if(a*a+b*b==c*c||b*b+c*c==a*a||a*a+c*c==b*b)printf("直角");	
		printf("三角形\n");
	}else printf("构不成三角形\n");
	return 0;
}
