#include<stdio.h>
int main(void){
	char str[100]="asassassaaasasasasasasghsdejQAWBHUJIGQWEADRfhjun8ik9olefrqwANBUJ8IKOEDRQWAfbhnqa2WE";
	int cnt=0,change=1;
	for(cnt=0;cnt<sizeof(str)/sizeof(str[0])&&str[cnt]!='\0';cnt++){
		if(str[cnt]=='a'){
			str[cnt]=str[cnt+change];
			change++;
			cnt--;
		}
	}
	puts(str);
	return 0;
} 
