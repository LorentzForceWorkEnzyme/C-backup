#include<stdio.h>
#include<windows.h>
int main(void){
	system("color FC");
	int x=0,y=0,temp,;
	for(y=0;y<20;y++){
		for(x=0;x<20;x++){
			temp=y;
			if(y>10)temp=20-temp; 
			putchar(x>10-temp&&x<10+temp?'*':' ');
		}
		putchar('\n');
	}
	return 0;
}
