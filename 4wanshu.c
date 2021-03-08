#include<stdio.h>
int mian(){
	int number=0,cnt=0,i,j=1,sum=0;
	for(i=1;i<1001;i++){
		number=i;
		for(j=1;j<number;j++){
			sum=sum*number;
		}
		if(number==sum)printf("%dÊÇÍêÊı\n");
		sum=0; 
	} 
	return 0;
}
  