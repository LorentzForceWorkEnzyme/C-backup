#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<windows.h>
#define N 100
#define M 20

//�û���Ϣ�п��ţ��û���������ǰ�����½����
struct Account/*�˻��ṹ*/
{
	int id;
	char name[M];
	char password[M];/*����*/ 
	int money;
	int count;/*ȡ�����*/ 
};

//	int myid;
//	char myname[M];
//	char mypassword[M];/*����*/ 
//	int mymoney;
//	int mycount;/*ȡ�����*/ 
static struct Account ID[N];
static int usernum=0;/*�û�����*/
int mypos;/*��ǰ�û�����*/
int topos;/*ת���˻��±�λ��*/
int count=0;

void caidan();
void chaxun();
int check(int cid,char*cpw);/*����*/
void chushihua();
void clear(char s[]);/*����*/
void cunkuan();
void denglu();
void getdata();/*��������*/ 
void huanyingUI();
void huanying();
int isExist(int iid);/*��������˻�*/
void kaihu();
void qukuan();
void savedata();/*�洢����*/ 
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

/*��ʼ������*/
void chushihua()
{
	/*��ʼ�����ݣ��������ݵ������� */
	getdata();
	huanying();
} 

/*��ӡ��ӭ�Ľ��溯��*/
void huanyingUI()
{
	system("cls");
	printf("\n\n\t\t******************************\n");
	printf("\t\t**��ӭʹ��ATM�Զ�ȡ���ϵͳ**\n");
	printf("\t\t******************************\n\n\n\n");
	printf("\t\t-----------------\n");
	printf("\t\t| 0 �˳�ATM��ϵͳ   |\n");
	printf("\t\t-----------------\n");
	printf("\t\t| 1 ����        |\n");
	printf("\t\t-----------------\n");
	printf("\t\t| 2 ��¼        |\n");
	printf("\t\t-----------------\n");
	printf("\t\t|   ��ѡ����������  |\n");
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
			case 0:savedata();exit(0);/*�����˳�ATM��ϵͳ���������������н��� ���ʺ��治��Ҫ break*/
			case 1:system("cls");
			kaihu();/*���ÿ�������*/ 
			break;
			
			case 2:system("cls");
			denglu();/*���õ�½����*/ 
			break;
			default:printf("\n\t\t��������룬��ע������\n");
			sleep(1000);
			system("pause");//ϵͳ 
			break;
		}
	}
}

/*��¼ ��д*/
void denglu()
{
	int did;
	char dpw[M];
	int pos;
	/*���ε�¼����*/
	do
	{
		system("cls");
		printf("\n\t\t�����������˺ţ�");
		scanf("%d",&did); 
		printf("\n\t\t�������������룺");
		scanf("%s",dpw);
		if(isExist(did))
		{
			pos=gettopos(did);
			/*���δ����ܵ�¼*/
			if(ID[pos].count<=3)
			{
				if(check(did,dpw))
				{/*У��������˺Ž���ٳ��˵�*/
				 /*У��ͨ������count��¼Ϊ0*/
				 ID[pos].count=0;
				 count=0;
				 caidan(); 
				}
				else
				{
					printf("\n\t\t��������˺ź��������󣬵�¼���ɹ�\n");
					printf("\n\t\tͬһ�˺�����������󽫶����˺ţ����δ����������\n");
					printf("\n\t\t���δ������������ᣬ�뵽��̨�˹�����\n");
					count++;
					ID[pos].count++;
					printf("\nid:%d,pos:%d,count:%d\n",ID[pos].id,pos,ID[pos].count);
					system("pause");
					//system("pause");/*����dos������ͣ�������������*/
					/*У��������˺Ų���ȷ �˳���¼����*/ 
				}
			} else
			{
				//printf("�Բ��������˺��Զ��ᣬ�뵽��̨�˹�����%d,%d",ID[POS].id,pos,ID[pos].count);
				system("pause");
				break;
			}
		}
		else
		{
			count++;
			printf("\n��������˺Ų����ڣ���ע�����룡\n");
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

/*���*/

void cunkuan()
{
	int i;
	int money;
	system("cls");
	printf("\n\n\n\n\n\t\t��ѡ����Ҫ����Ľ��\n");
	printf("\t\t******************************\n"); 
	printf("\t\t** 1:100Ԫ ***** 2:200Ԫ **\n");
	printf("\t\t******************************\n");
	printf("\t\t** 3:300Ԫ ***** 4:400Ԫ **\n");
	printf("\t\t******************************\n");
	printf("\t\t** 5:500Ԫ ***** 6:600Ԫ **\n");
	printf("\t\t******************************\n");
	printf("\t\t��ѡ�����Ĵ��ѡ�");
	scanf("%d",&i);
	if(i>6||i<=0)     /*�������뷶Χ*/ 
	{
		printf("\t\t�Բ���������������\n\n");
		//system("pause");
		system("cls");
		return;
	}
	else
	{
		money=i*100;
		ID[mypos].money=ID[mypos].money+money;
		printf("\t\t���ѳɹ�����%.2fԪ\n",money*1.0);
	    system("pause");
		system("cls");
	}
} 

/*ȡ��� ��д*/
void qukuan()
{
	int i;
	int money;
	system("cls");
	printf("\n\n\n\n\n\t\t��ѡ����Ҫȡ��Ľ��\n");
	printf("\t\t******************************\n"); 
	printf("\t\t** 1:100Ԫ ***** 2:200Ԫ **\n");
	printf("\t\t******************************\n");
	printf("\t\t** 3:300Ԫ ***** 4:400Ԫ **\n");
	printf("\t\t******************************\n");
	printf("\t\t** 5:500Ԫ ***** 6:600Ԫ **\n");
	printf("\t\t******************************\n\n");
	printf("\t\t��ѡ������ȡ��ѡ�");
	scanf("%d",&i);
	if(i>6||i<=0)  /*�������뷶Χ*/ 
	{
		printf("\t\t�Բ���������������\n\n");
		//system("pause");
		//system("cls");
		return;
	}
	else
	{
		money=i*100;
		if(money>ID[mypos].money);//����
		{
			printf("\t\t�Բ�����������\n");
	        system("pause");
		    system("cls");
		}
        else
    	{
    		ID[mypos].money=ID[mypos].money-money;
		
		    printf("\n\t\t���ѳɹ�ȡ��%.2fԪ\n",money*1.0);
	        system("pause");
		    system("cls");
		}
	}
}

/*ת�˺�����д*/ 
void zhuanzhang()
{
	/*a�˺ţ�kת�˽��*/
	int a,k;
	int c;
	int money;
	printf("\n\n\n\n\n\t\t������ת����˺ţ�");
	scanf("%d,&a");
	/*�ȼ���˺��Ƿ����*/
	if(isExist(a))
	{
		gettopos(a);
		if(a==ID[mypos].id)
		{
			printf("\n\n\n\t\t�������ת���˺����Լ����˺���ͬ����������ͬ�˻�ת�ˣ�ת��ʧ��\n");
			system("pause");
			return;
		}
		else
		{
		     system("cls");
	         printf("\n\n\t\t������ת�˽��\n");
	         printf("\t\t******************************\n"); 
             printf("\t\t** 1:100Ԫ ***** 2:200Ԫ **\n");
	         printf("\t\t******************************\n");
	         printf("\t\t** 3:300Ԫ ***** 4:400Ԫ **\n");
             printf("\t\t******************************\n");
	         printf("\t\t** 5:500Ԫ ***** 6:600Ԫ **\n");
	         printf("\t\t******************************\n\n");
	         printf("\t\t����������ѡ��");
	         
			 scanf("%d",&k);
	         if(k>6||k<=0)  /*�������뷶Χ*/ 
	         {
		         printf("\t\t�Բ���������������\n\n");
		         //system("pause");
		         system("cls");
	             return;
	         }
			 else
			 {
		          money=k*100;
		          
		          if(money>ID[mypos].money);//�������ж� 
		          {
			           printf("\t\t�Բ����������㣬ת��ʧ��\n");
	                   system("pause");
		               system("cls");
		               //caidan(); 
		          }
	              else
    	          {
    		          printf("\n\t\t������ת��%.2fԪ���˺�Ϊ%d��������Ϊ%s���˺���\n",money*1.0,ID[topos].id,ID[topos].name);
					  printf("\n\t\tͬ�������� 1:\n");
					  printf("\n\t\t��ͬ�������� 2:");
					  scanf("%d",&c);
					  switch(c)
					  {
					  	case 1:ID[mypos].money=ID[mypos].money-money;
					  	       ID[mypos].money=ID[mypos].money-money;
					  	       printf("\n\t\t���ѳɹ�ת��%.2fԪ���ʺ�Ϊ%s���û�\n",money*1.0f,ID[topos].name);
							   break;
							   
					    case 2:printf("\n\t\t��ȡ����ת�˲�����ת�˲���ʧ��\n");break;
					    default:printf("\n\t\t���Ĳ�������ת�˲���ʧ��\n"); 
					  }
					  
					  system("pause");
					  system("cls");  
		          }
             }
	    }
	}
	else
	{
		printf("\n\t\t�������ת���˺Ų����ڣ�ת�˲���ʧ��\n");
	}	          

}		         
 /*x�޸����뺯�� ��д����*/
 void xgmm()
 {
 	char p1[M],p2[M],p3[M];
 	printf("\n\n\n\t\t����������ԭ����:");
 	scanf("%s",p1);
 	if(strcmp(p1,ID)[mypos].password)==0) 
 	{
 		printf("\n\n\t\t����������������:");
 		scanf("%s",p2);
 		printf("\n\n���ٴ���������������:");
 		scanf("%s",p3);
 		if(strcmp(p2,p3)==0)
 		{
		  strcpy(ID[mypos].password,p2);
		   
		   printf("\n\t\t�����޸ĳɹ�!\n");
		}
		else
		{
			printf("\n\t\t�����������벻�ɹ��������޸�ʧ��\n");
			
		}
	}
	else
	{
		printf("\n\t\t����������������޸�ʧ��\n");
		
	}
	

 }
 /*��ѯ��ǰ�û����������Ѿ���д*/
 void chaxun() 
 {
 	//system("cls");
 	printf("\n\n\t\t��ĵ�ǰ�����:%d\n",ID[mypos].money);
 	Sleep(500);
 	system("pause");
 	
 }
 /*�������� �Ѿ���д*/
 void kaihu() 
 {
 	int kid;
 	char kname[M];/*��ǰ�û�����*/
 	char kp1[M];/*��ǰ�û�����*/
	clear(kp1);
	int kmoney=0;/*��ǰ�û������*/
	int kcount=0;
	/*�����˺ţ�����˻��Ƿ���ڼ��˺ŵĺϷ���*/
	kid=zhanghao();
	printf("\n\t\t���������û���:");
	scanf("%s",kname);
	/*�����˺�����*/
	twopw(kp1);
	
	/*������Ϣ��������*/
	ID[usernum].id=kid;/*����kid��������id*/
	strcpy(ID[usernum].name,kname);/*�������û�����������name*/
	strcpy(ID[usernum].password,kp1);
	ID[usernum].money=0;
	ID[usernum].count=kcount;
	usernum++;
	printf("\n");
	printf("\t\t��ϲ�������ɹ� ���¼\n");
	system("pause");
	sysrem("cls");
 }
 
void tuichu()
{
	/*�������ֵ�浽�ĵ��У��������ǰ�û���״̬*/
	wdlqzt();
	
	//huanying();
	
	
	
}
/*δ��¼ǰ�û�״̬*/

void wdlgzt() 
{
	int i;
/*  for(i=0;i<M;i++)
 	{
 		myname[i]='\0';
 		
     }
     clear(mypassword);
*/
     mypos=-1;/*λ��Ϊ-1���޷���ȡ�������*/
     //    mymoney=0;
     topos=-1;
}



/*��½��ǰ�û���״̬*/
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


/*���в˵����� ��д*/

void caidan()
{
	int i;
	system("cls");
	
	while(1)
	{  system("cls");
	   printf("\n\n\n\n\n\t\t�𾴵Ŀͻ���%s,��ӭ����",ID[mypos].name);/*����ҵ��˵�*/
	   printf("\n\t\t��ѡ������Ҫ��ҵ��\n")/*����ҵ��˵�*/ 
	   printf("\n\t\t******************************\n");
	   printf("\t\t** 1ȡ�� *****  2��ѯ   **\n");
	   printf("\t\t******************************\n");
	   printf("\t\t** 3ȡ�� *****  4��ѯ   **\n");
	   printf("\t\t******************************\n");
	   printf("\t\t** 5ȡ�� *****  6�˳�   **\n");
	   printf("\t\t******************************\n");
	   printf("\t\t��ѡ��ҵ���ţ�");
	   scanf("%d",&i);
	   if("i<6||i>0")
	   {
	   	   switch(i)
	   	   {
	   	   	  case 1:               /*��������ȡ���*/ 
	   	   	  	    qukuan();
	   	   	  	    system("cls");
	   	   	  	    break;
	   	   	  case 2:               /*�������в�ѯ����*/ 
	   	   	  	    //system("cls");
					chaxun();
	   	   	  	    system("cls");
	   	   	  	    break;
	   	   	  case 3:               /*��������ת�˺���*/ 
                    system("cls");
                    zhuanzhang();
	   	   	  	    break;
	   	   	  case 4:               /*���������޸����뺯��*/ 
	   	   	  	    system("cls");
	   	   	  	    xgmm();
	   	   	  	    break;
			  case 5:               /*�������д���*/ 
	   	   	  	    cunkuan();
	   	   	  	    system("cls");
	   	   	  	    break;
			  case 6:               /*���������˳�����*/ 
	   	   	  	    
	   	   	  	    system("cls");
	   	   	  	    return;	
											    
	   	   }
	   }
	   else
	   {
	   	 printf("\t\t������������\n");
	   	 system("pause");
	   	 system("cls");
	   }
    
	}
    //caidan();
}

/*���ĵ��ж�ȡ���ݵ�������*/
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
	
	fp=fopen("d:\\stu.txt","r");/*��ֻ����ʽ��*/
	if(!fp)
	{
		printf("�ļ����ܱ��򿪣������ļ�������\n");
		return;
	}
	ch=fgetc(fp);/*���û�е��ļ�������ѭ��������*/
	while(!feof(fp))/*���û�е��ļ�������ѭ��������*/ 
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

/*���ڴ��е����ݴ洢���ĵ���*/
void savedata() 
{
	
	int i;
	char s[128];
	clear(s);
	char p[128];
	FILE*fp;
	fp=fopen("d:\\stu.txt","w");/*��ֻ��д�ķ�ʽ��*/
	if(!fp)
	{
		printf("�ļ����ܱ��򿪣������ļ�������\m");
		return;
	}
	
	

	for(i=0;i<usernum;i++)
	{
		itoa(ID[i].id,p,10);/*��id[i]ת��Ϊʮ���Ƶ��ַ���������p��*/
		strcat(s,p);
		
		strcat(s,"\t");
		
		strcat(s,ID[i].name);
		strcat(s,"\t");
		
		
		strcat(s,ID[i].password);
		strcat(s,"t");
		/*������ת��Ϊ�ַ���*/
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


/*����˺��Ƿ���ڣ������򷵻�1�����߷���0��д���*/
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
/*�������п�����*/
void twopw(char*p)
{ char p1[M],p2[M];
   while(1)
   {
   	    printf("\n\t\t�����������п�����:");
   	    scanf("%s",p1);
   	    printf("\n\t\t���ٴ����������п�����:");
   	    scanf("%",p2);
   	    /*�������벻һ��ʱ�����ظ���������*/
	    if(strcmp(p1,p2)!=0)
	   	{
	   		printf("\t\t�����������벻һ�£���������������");
	   		
	   	}else{
	   		  strcpy(p.p1);
	   		  break;  
	   	}
	}

}

/*¼���˺����*/
int zhanghao()
{
	int kid;
	system("cls");
	printf("\n\t\t���������Ŀ���(4λ����):");
	
	scanf("%d",&kid);
	/*c�����˺�ǰ�����ȼ���˺��Ƿ�Ϸ�*/
	if(isExist(kid)||(kid<1000||kid>1000))
	{
		printf("\t\t�˺�%d�ѽ����ڻ��߲��Ϸ����޷����д���!\n",kid);
		//Sleep(3000);
		system("pause");
		kid=zhanghao();
	} 
	return kid;
}
/*�˺������� ���*/
int check(int cid,char*cpw)
{
	int i:
	for(i=0;i<usernum;i++)
	{
		if(cid==ID[i].id)
		     if(strcmp(ID[i].password,cpw)==0)
		        {
		        	/*����û�����������������¼��������1*/
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
 


		
	
	 
	
	 
	






















 
