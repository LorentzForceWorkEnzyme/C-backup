#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<windows.h>
#define N 100
#define M 20

//用户信息有卡号，用户名，金额，当前错误登陆次数
struct Account/*账户结构*/
{
	int id;
	char name[M];
	char password[M];/*密码*/ 
	int money;
	int count;/*取款次数*/ 
};

//	int myid;
//	char myname[M];
//	char mypassword[M];/*密码*/ 
//	int mymoney;
//	int mycount;/*取款次数*/ 
static struct Account ID[N];
static int usernum=0;/*用户数量*/
int mypos;/*当前用户姓名*/
int topos;/*转账账户下标位置*/
int count=0;

void caidan();
void chaxun();
int check(int cid,char*cpw);/*查找*/
void chushihua();
void clear(char s[]);/*清屏*/
void cunkuan();
void denglu();
void getdata();/*输入数据*/ 
void huanyingUI();
void huanying();
int isExist(int iid);/*存在这个账户*/
void kaihu();
void qukuan();
void savedata();/*存储数据*/ 
void tuichu();
void twopw(char*p);
void wdlqzt();
void xgmm();
void ydlqzt(int pos);
int zhanghao();
void zhuanzhang();


int main()
{
	chushihua();
	return 0;
}

/*初始化界面*/
void chushihua()
{
	/*初始化数据，输入数据到数组中 */
	getdata();
	huanying();
} 

/*打印欢迎的界面函数*/
void huanyingUI()
{
	system("cls");
	printf("\n\n\t\t******************************\n");
	printf("\t\t**欢迎使用ATM自动取款机系统**\n");
	printf("\t\t******************************\n\n\n\n");
	printf("\t\t-----------------\n");
	printf("\t\t| 0 退出ATM机系统   |\n");
	printf("\t\t-----------------\n");
	printf("\t\t| 1 开户        |\n");
	printf("\t\t-----------------\n");
	printf("\t\t| 2 登录        |\n");
	printf("\t\t-----------------\n");
	printf("\t\t|   请选择您的需求  |\n");
	printf("\t\t-----------------\n");
	printf("\t\t");
	
} 
void huanying()
{
	int x;
	int i;
	while(1){
		huanyingUI();
		scanf("%d",&x);
		
		switch(x)
		{
			case 0:savedata();exit(0);/*正常退出ATM机系统，即整个程序运行结束 ，故后面不需要 break*/
			case 1:system("cls");
			kaihu();/*调用开户函数*/ 
			break;
			
			case 2:system("cls");
			denglu();/*调用登陆函数*/ 
			break;
			default:printf("\n\t\t错误的输入，请注意输入\n");
			sleep(1000);
			system("pause");//系统 
			break;
		}
	}
}

/*登录 重写*/
void denglu()
{
	int did;
	char dpw[M];
	int pos;
	/*三次登录机会*/
	do
	{
		system("cls");
		printf("\n\t\t请输入您的账号：");
		scanf("%d",&did); 
		printf("\n\t\t请输入您的密码：");
		scanf("%s",dpw);
		if(isExist(did))
		{
			pos=gettopos(did);
			/*三次错误不能登录*/
			if(ID[pos].count<=3)
			{
				if(check(did,dpw))
				{/*校验密码和账号进入操场菜单*/
				 /*校验通过则将其count记录为0*/
				 ID[pos].count=0;
				 count=0;
				 caidan(); 
				}
				else
				{
					printf("\n\t\t您输入的账号和密码有误，登录不成功\n");
					printf("\n\t\t同一账号三次密码错误将冻结账号！三次错误如需继续\n");
					printf("\n\t\t三次错误如需解除冻结，请到柜台人工处理\n");
					count++;
					ID[pos].count++;
					printf("\nid:%d,pos:%d,count:%d\n",ID[pos].id,pos,ID[pos].count);
					system("pause");
					//system("pause");/*调用dos命令暂停，按任意键继续*/
					/*校验密码和账号不正确 退出登录界面*/ 
				}
			} else
			{
				//printf("对不起您的账号以冻结，请到柜台人工处理！%d,%d",ID[POS].id,pos,ID[pos].count);
				system("pause");
				break;
			}
		}
		else
		{
			count++;
			printf("\n您输入的账号不存在，请注意输入！\n");
			system("pause");
			system("cls");
		}
		if(mypos>=0)
		{
			wdlqzt();
			break;	
		}
		
	} while(count<=3);
	
} 

/*存款*/

void cunkuan()
{
	int i;
	int money;
	system("cls");
	printf("\n\n\n\n\n\t\t请选择您要存入的金额\n");
	printf("\t\t******************************\n"); 
	printf("\t\t** 1:100元 ***** 2:200元 **\n");
	printf("\t\t******************************\n");
	printf("\t\t** 3:300元 ***** 4:400元 **\n");
	printf("\t\t******************************\n");
	printf("\t\t** 5:500元 ***** 6:600元 **\n");
	printf("\t\t******************************\n");
	printf("\t\t请选择您的存款选项：");
	scanf("%d",&i);
	if(i>6||i<=0)     /*限制输入范围*/ 
	{
		printf("\t\t对不起，您的输入有误！\n\n");
		//system("pause");
		system("cls");
		return;
	}
	else
	{
		money=i*100;
		ID[mypos].money=ID[mypos].money+money;
		printf("\t\t您已成功存入%.2f元\n",money*1.0);
	    system("pause");
		system("cls");
	}
} 

/*取款函数 重写*/
void qukuan()
{
	int i;
	int money;
	system("cls");
	printf("\n\n\n\n\n\t\t请选择您要取款的金额\n");
	printf("\t\t******************************\n"); 
	printf("\t\t** 1:100元 ***** 2:200元 **\n");
	printf("\t\t******************************\n");
	printf("\t\t** 3:300元 ***** 4:400元 **\n");
	printf("\t\t******************************\n");
	printf("\t\t** 5:500元 ***** 6:600元 **\n");
	printf("\t\t******************************\n\n");
	printf("\t\t请选择您的取款选项：");
	scanf("%d",&i);
	if(i>6||i<=0)  /*限制输入范围*/ 
	{
		printf("\t\t对不起，您的输入有误！\n\n");
		//system("pause");
		//system("cls");
		return;
	}
	else
	{
		money=i*100;
		if(money>ID[mypos].money);//余额不足
		{
			printf("\t\t对不起，您的余额不足\n");
	        system("pause");
		    system("cls");
		}
        else
    	{
    		ID[mypos].money=ID[mypos].money-money;
		
		    printf("\n\t\t您已成功取走%.2f元\n",money*1.0);
	        system("pause");
		    system("cls");
		}
	}
}

/*转账函数重写*/ 
void zhuanzhang()
{
	/*a账号，k转账金额*/
	int a,k;
	int c;
	int money;
	printf("\n\n\n\n\n\t\t请输入转入的账号：");
	scanf("%d,&a");
	/*先检测账号是否存在*/
	if(isExist(a))
	{
		gettopos(a);
		if(a==ID[mypos].id)
		{
			printf("\n\n\n\t\t您输入的转入账号与自己的账号相同，不允许相同账户转账，转账失败\n");
			system("pause");
			return;
		}
		else
		{
		     system("cls");
	         printf("\n\n\t\t请输入转账金额\n");
	         printf("\t\t******************************\n"); 
             printf("\t\t** 1:100元 ***** 2:200元 **\n");
	         printf("\t\t******************************\n");
	         printf("\t\t** 3:300元 ***** 4:400元 **\n");
             printf("\t\t******************************\n");
	         printf("\t\t** 5:500元 ***** 6:600元 **\n");
	         printf("\t\t******************************\n\n");
	         printf("\t\t请输入您的选择：");
	         
			 scanf("%d",&k);
	         if(k>6||k<=0)  /*限制输入范围*/ 
	         {
		         printf("\t\t对不起，您的输入有误！\n\n");
		         //system("pause");
		         system("cls");
	             return;
	         }
			 else
			 {
		          money=k*100;
		          
		          if(money>ID[mypos].money);//余额进行判断 
		          {
			           printf("\t\t对不起，您的余额不足，转账失败\n");
	                   system("pause");
		               system("cls");
		               //caidan(); 
		          }
	              else
    	          {
    		          printf("\n\t\t您即将转入%.2f元到账号为%d，用姓名为%s的账号中\n",money*1.0,ID[topos].id,ID[topos].name);
					  printf("\n\t\t同意请输入 1:\n");
					  printf("\n\t\t不同意请输入 2:");
					  scanf("%d",&c);
					  switch(c)
					  {
					  	case 1:ID[mypos].money=ID[mypos].money-money;
					  	       ID[mypos].money=ID[mypos].money-money;
					  	       printf("\n\t\t您已成功转入%.2f元到帐号为%s的用户\n",money*1.0f,ID[topos].name);
							   break;
							   
					    case 2:printf("\n\t\t您取消了转账操作，转账操作失败\n");break;
					    default:printf("\n\t\t您的操作有误，转账操作失败\n"); 
					  }
					  
					  system("pause");
					  system("cls");  
		          }
             }
	    }
	}
	else
	{
		printf("\n\t\t您输入的转入账号不存在，转账操作失败\n");
	}	          

}		         
 /*x修改密码函数 重写函数*/
 void xgmm()
 {
 	char p1[M],p2[M],p3[M];
 	printf("\n\n\n\t\t请输入您的原密码:");
 	scanf("%s",p1);
 	if(strcmp(p1,ID)[mypos].password)==0) 
 	{
 		printf("\n\n\t\t请输入您的新密码:");
 		scanf("%s",p2);
 		printf("\n\n请再次输入您的新密码:");
 		scanf("%s",p3);
 		if(strcmp(p2,p3)==0)
 		{
		  strcpy(ID[mypos].password,p2);
		   
		   printf("\n\t\t密码修改成功!\n");
		}
		else
		{
			printf("\n\t\t两次密码输入不成功，密码修改失败\n");
			
		}
	}
	else
	{
		printf("\n\t\t密码输入错误，密码修改失败\n");
		
	}
	

 }
 /*查询当前用户余额函数函数已经重写*/
 void chaxun() 
 {
 	//system("cls");
 	printf("\n\n\t\t你的当前余额是:%d\n",ID[mypos].money);
 	Sleep(500);
 	system("pause");
 	
 }
 /*开户函数 已经重写*/
 void kaihu() 
 {
 	int kid;
 	char kname[M];/*当前用户姓名*/
 	char kp1[M];/*当前用户密码*/
	clear(kp1);
	int kmoney=0;/*当前用户存款额度*/
	int kcount=0;
	/*输入账号，检查账户是否存在及账号的合法性*/
	kid=zhanghao();
	printf("\n\t\t请设置您用户名:");
	scanf("%s",kname);
	/*设置账号密码*/
	twopw(kp1);
	
	/*开户信息存入数组*/
	ID[usernum].id=kid;/*开户kid存入数组id*/
	strcpy(ID[usernum].name,kname);/*将开户用户名存入数组name*/
	strcpy(ID[usernum].password,kp1);
	ID[usernum].money=0;
	ID[usernum].count=kcount;
	usernum++;
	printf("\n");
	printf("\t\t恭喜您开户成功 请登录\n");
	system("pause");
	sysrem("cls");
 }
 
void tuichu()
{
	/*将数组的值存到文档中，并清除当前用户的状态*/
	wdlqzt();
	
	//huanying();
	
	
	
}
/*未登录前用户状态*/

void wdlgzt() 
{
	int i;
/*  for(i=0;i<M;i++)
 	{
 		myname[i]='\0';
 		
     }
     clear(mypassword);
*/
     mypos=-1;/*位置为-1则无法读取数组的组*/
     //    mymoney=0;
     topos=-1;
}



/*登陆后当前用户的状态*/
/*
void ydlhzt(int pos)
{
	myid=ID[mypos].id;
	strcpy(myname,ID[mypos].name);
	strcpy(myname,ID[mypos].password);
	mymoney=ID[mypos].money;
	mycount=ID[mypos].count;
}
*/


/*银行菜单函数 重写*/

void caidan()
{
	int i;
	system("cls");
	
	while(1)
	{  system("cls");
	   printf("\n\n\n\n\n\t\t尊敬的客户；%s,欢迎您！",ID[mypos].name);/*银行业务菜单*/
	   printf("\n\t\t请选择您需要的业务\n")/*银行业务菜单*/ 
	   printf("\n\t\t******************************\n");
	   printf("\t\t** 1取款 *****  2查询   **\n");
	   printf("\t\t******************************\n");
	   printf("\t\t** 3取款 *****  4查询   **\n");
	   printf("\t\t******************************\n");
	   printf("\t\t** 5取款 *****  6退出   **\n");
	   printf("\t\t******************************\n");
	   printf("\t\t请选择业务编号；");
	   scanf("%d",&i);
	   if("i<6||i>0")
	   {
	   	   switch(i)
	   	   {
	   	   	  case 1:               /*调用银行取款函数*/ 
	   	   	  	    qukuan();
	   	   	  	    system("cls");
	   	   	  	    break;
	   	   	  case 2:               /*调用银行查询函数*/ 
	   	   	  	    //system("cls");
					chaxun();
	   	   	  	    system("cls");
	   	   	  	    break;
	   	   	  case 3:               /*调用银行转账函数*/ 
                    system("cls");
                    zhuanzhang();
	   	   	  	    break;
	   	   	  case 4:               /*调用银行修改密码函数*/ 
	   	   	  	    system("cls");
	   	   	  	    xgmm();
	   	   	  	    break;
			  case 5:               /*调用银行存款函数*/ 
	   	   	  	    cunkuan();
	   	   	  	    system("cls");
	   	   	  	    break;
			  case 6:               /*调用银行退出函数*/ 
	   	   	  	    
	   	   	  	    system("cls");
	   	   	  	    return;	
											    
	   	   }
	   }
	   else
	   {
	   	 printf("\t\t您的输入有误\n");
	   	 system("pause");
	   	 system("cls");
	   }
    
	}
    //caidan();
}

/*从文档中读取数据到数组中*/
void getdata()
{
	char ch
	char *p
	char str[100];
	int i=0;
	FILE *fp;
	char *strid;
	char *strname;
	char *strpw;
	char *strmoney;
	char *stcount;
	
	fp=fopen("d:\\stu.txt","r");/*以只读方式打开*/
	if(!fp)
	{
		printf("文件不能被打开，或者文件不存在\n");
		return;
	}
	ch=fgetc(fp);/*如果没有到文件结束符循环进行中*/
	while(!feof(fp))/*如果没有到文件结束符循环进行中*/ 
	{
		if(ch=='\n')
		{
			str[i]='\0';
			p=strtok(str,"\t");
			ID[usernum].id=atoi(p);
			p=strtpk(NULL,"\t");
			strcpy(ID)[usernum].name,p);
			p=strtok(NULL,"t");
			strcpy(ID)[usernum].password,p);
			p=strtok(NULL,"t");
			ID[usernum].money=atof(p);
			p=strtok(NULL,"t");
			ID[usernum].count=atoi(p);
			usernum++;
			i=0;
			clear(str);
		}
		else{
			str[i++]=ch;
		}
		//putchar(ch);
		ch=fgetc(fp);
	}
	
	//printf("\nusernum=%d\n",usernum);
	Sleep(1000);
	system("cls");
	fclose(fp);
	system("pause");
	
}

/*将内存中的数据存储到文档中*/
void savedata() 
{
	
	int i;
	char s[128];
	clear(s);
	char p[128];
	FILE*fp;
	fp=fopen("d:\\stu.txt","w");/*以只读写的方式打开*/
	if(!fp)
	{
		printf("文件不能被打开，或者文件不存在\m");
		return;
	}
	
	

	for(i=0;i<usernum;i++)
	{
		itoa(ID[i].id,p,10);/*将id[i]转化为十进制的字符串，存入p中*/
		strcat(s,p);
		
		strcat(s,"\t");
		
		strcat(s,ID[i].name);
		strcat(s,"\t");
		
		
		strcat(s,ID[i].password);
		strcat(s,"t");
		/*浮点型转换为字符型*/
		itoa(ID[i].money,p,10);
		
		strcat(s,p);
		strcat(s,"\t");
		
		/*printf("\ncount=%d\n"ID[usernum].count);*/
		itoa(ID[usernum].count,p,10);
		strcat(s,p);
		strcat(s,"\n");
		fputs(s,fp);
		clear(s);
	}
	fclose(fp);
}


/*检查账号是否存在，存在则返回1，否者返回0重写完成*/
int isExist(int iid)
{
	int i;
	for(i=0;i<usernum;i++)
	{
		if(iid==ID[i].id)
		return 1;
	}
	return 0;
} 
/*设置银行卡密码*/
void twopw(char*p)
{ char p1[M],p2[M];
   while(1)
   {
   	    printf("\n\t\t请设置您银行卡密码:");
   	    scanf("%s",p1);
   	    printf("\n\t\t请再次设置您银行卡密码:");
   	    scanf("%",p2);
   	    /*两次密码不一样时请求重复输入密码*/
	    if(strcmp(p1,p2)!=0)
	   	{
	   		printf("\t\t两次密码输入不一致，请重新输入密码");
	   		
	   	}else{
	   		  strcpy(p.p1);
	   		  break;  
	   	}
	}

}

/*录入账号完成*/
int zhanghao()
{
	int kid;
	system("cls");
	printf("\n\t\t请输入您的卡号(4位数字):");
	
	scanf("%d",&kid);
	/*c创建账号前必须先检测账号是否合法*/
	if(isExist(kid)||(kid<1000||kid>1000))
	{
		printf("\t\t账号%d已将存在或者不合法，无法进行创建!\n",kid);
		//Sleep(3000);
		system("pause");
		kid=zhanghao();
	} 
	return kid;
}
/*账号密码检测 完成*/
int check(int cid,char*cpw)
{
	int i:
	for(i=0;i<usernum;i++)
	{
		if(cid==ID[i].id)
		     if(strcmp(ID[i].password,cpw)==0)
		        {
		        	/*如果用户名和密码均正常则登录，并返回1*/
					mypos=i;
					return 1;
		        }
	}
	
	return 0;
} 

int gettopos(int toid)
{
	topos=-1
	int i;
	for(i=0;i<usernum;i++)
	{
		if(toid==ID[i].id)
		{
			topos=i;
			return topos;
		}
	}
	
	return topos;
}

void clear(char s[])
{
	int i;
	for(i=0;i<strlen(s);i++)
	    s[i]='\0';
}
 


		
	
	 
	
	 
	






















 
