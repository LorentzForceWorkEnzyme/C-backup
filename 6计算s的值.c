#include<stdio.h>
int main(void){
	int i[10]={0,},cnt;
	double s=0.0,sum;
	for(cnt=0;cnt<10;cnt++){
		scanf("%d",&i[cnt]);
	}
	for(cnt=0;cnt<10;cnt++){
		printf("%8d",i[cnt]);
		sum=sum+i[cnt];
		if(cnt%5==0)putchar(10);
	}
	sum=sum/10;
	for(cnt=0;cnt<10;cnt++){
		s=s+(sum-i[cnt])*(sum-i[cnt]);
	}
	printf("X0=%0.2f    s=%0.2f\n",sum,s);
	getchar();
	return 0;
}
