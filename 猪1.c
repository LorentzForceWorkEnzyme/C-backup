#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<windows.h>
#define N 100
#define M 20
#include <stdio.h>
/*�û���Ϣ�� ���ţ��û��������룬����ǰ�����½����*/
struct Account
{
	int id;
	char name[M];
	char password[M];
	int money;
	int count;
};

//int myid;
//char myname[M];
//char mypassword[M];
//int mymoney;
//int mycount;
static struct Account ID[N];
static int usernum=0;/*�û�����*/
int mypos;/*��ǰ�û�����*/
int topos;/*ת���˻��±�λ��*/
int count=0;
//int void
void Edit();					//�˵� 
void query();					//��ѯ 
int check(int cid,char*cpw);
void lnitialization();			//��ʼ�� 
void clear(char s[]);
void deposit();					// ��� 
void land();					//��½ 
void getdata();					 
void welcomeUI();
void welcome();					//��ӭ 
int  isExist(int iid);
void Openaccount();				//���� 
void Withdrawmoney();			//ȡ�� 
void savedata();
void Signout ();				//�˳� 
void twopw(char*p);
void wdlqzt();
void Modifythepassword ();		//�޸����� 
void ydlhzt(int pos);
int  Accountnumber ();			//�˺� 
void Transferaccounts ();		//ת�� 
int gettopos(int toid);


int main()
{
	system("color 3f");
	system("title С��ATM��"); 
	
	lnitialization();
	return 0;
}


/*��ʼ������*/
void lnitialization()
{
	/*��ʼ�����ݣ����ı��ļ��ж�ȡ���ݵ�������*/
	getdata();
	welcome();
}

/*��ӡ��ӭ�Ľ��溯��*/
void welcomeUI()
{
	system("cls");
	printf("\n\n			\t\t\t\n");
	printf("			*��ӭʹ��С��ATM�Զ�ȡ���ϵͳ*\n");
	printf("			\t\t\t\t\t\n");
	printf("			---------------\n");
	printf("			| 0 �˳�ATM��ϵͳ	|\a\t\t\n");
	printf("			---------------\n");
	printf("			| 1 ����	  	|\a\t\t\n");
	printf("			---------------\n");
	printf("			| 2 ��¼	  	|\a\t\t\n");
	printf("			---------------\n");
	printf("			| 3 ��ѡ���������� 	|\a\t\t\n");
	printf("			---------------\t\t\n");
	printf("			");
	
}
void welcome()
{
	int x;
	int i;
	while(1){
		welcomeUI();
		scanf("%d",&x);
		
		switch(x)
		{
			case 0:savedata();exit(0);/*�����˳�ATM��ϵͳ���������������н������ʺ��治��Ҫbreak*/
			case 1:system("cls");/*"cls"����*/
				Openaccount();       /*���ÿ�������*/
				break;
				
			case 2:system("cls");
				land();       /*���õ�½����*/
				break;
			default:printf("\n			��������룬��ע������\n");
				Sleep(1000);
				system("pause");
				break;				 
		}
	}
}
/*��½ ��д*/
void land()
{
	int did;
	char dpw[M];
	int pos;
	/*���ε�½����*/
	do
	{
		system("cls");
		printf("\n		�����������˺ţ�");
		scanf("%d",&did);
		printf("\n		�������������룺");
		scanf("%s",dpw);
		if(isExist(did))
		{
			pos=gettopos(did);
			/*�������ϴ����ܵ�½*/
			if(ID[pos].count<=3)
			{
				if(check(did,dpw))
				{/*У��������˺Ž�������˵�*/
		  		 /*У��ͨ������count��¼Ϊ0*/
				   ID[pos].count=0;
				   count=0;
				   Edit();					
				}
				else
				{
					printf("\n		��������˺Ż��������д���½���ɹ�\n");
					printf("\n		ͬһ�˺�����������󽫶����½�����δ����������\n");
					printf("\n		���δ������������ᣬ�뵽��̨�˹�����\n");
					count++;
					ID[pos].count++;
					printf("\nid:%d,pos:%d,count:%d\n",ID[pos].id,pos,ID[pos].count);
					system("pause");
					//system("pausse");/*����dos������ͣ�������������*/
					/*У��������˺Ų���ȷ �˳���½����*/ 
				}
			}else
			{
				//printf("�����˺��Ѿ����ᣬ�뵽��̨�˹�����%d,%d",ID[pos].id,ID[pos].count);
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
			
	}while(count<=3);
	
}

/*���*/

void deposit()
{
	int i;
	int money;
	system("cls");
	printf("\n\n\n\n\n		��ѡ����Ҫ����Ľ��\n");
	printf("		\t\t\t\t\t\t\n");
	printf("		\t1:100Ԫ\t\t2:200Ԫ\t\n");
	printf("		\t\t\t\t\t\n");
	printf("		\t3:300Ԫ\t\t4:400Ԫ\t\n");
	printf("		\t\t\t\t\t\n");
	printf("		\t5:500Ԫ\t\t6:600Ԫ\t\n");
	printf("		\t\t\t\t\t\n");
	printf("		\t\t��ѡ�����Ĵ��ѡ�");
	scanf("%d",&i);
	if(i>6||i<=0)         /*�������뷶Χ*/ 
	{
		printf("		�Բ���������������\n\n");
		//system("pause");
		system("cls");
		return;
	}
	else
	{
		money=i*100;
		ID[mypos].money=ID[mypos].money+money;
			printf("		���Ѵ���%.2fԪ\n",money*1.0);
			system("pause");
			system("cls"); 
	}
}

/*ȡ���  ��д*/
void Withdrawmoney()
{
	int i;
	int money;
	system("cls");
	printf("\n\n\n\t\t		�밴Ҫ��ѡ����Ҫȡ��Ľ��\n");
	printf("		\t\t\t\t\t\n");
	printf("		\t1:100Ԫ\t\t2:200Ԫ\t\n");
	printf("		\t\t\t\t\t\n");
	printf("		\t3:300Ԫ\t\t4:400Ԫ\t\n");
	printf("		\t\t\t\t\t\n");
	printf("		\t5:500Ԫ\t\t6:600Ԫ\t\n");
	printf("		\t\t\t\t\t\n");
	printf("		\t\t��ѡ�����Ĵ��ѡ�");
	scanf("%d",&i);
	if(i>6||i<=0)            /*�������뷶Χ*/ 
 	{
		printf("		�Բ���������������\n\n");
			//system("pause");
			//system("cls");
	return;
	}
	else
	{
		money=i*100;
		if(money>ID[mypos].money)//���� 
		{
			printf("		�Բ�����������\n");
			system("pause");
			system("cls");
		}
		else
		{
			ID[mypos].money=ID[mypos].money-money;
			
			printf("\n		���ѳɹ�ȡ��%.2fԪ\n",money*1.0);
			system("pause");
			system("cls");
		}
	} 
}

/*ת�˺��� ��д���*/
void Transferaccounts()
{
	/*a�˺ţ�kת�˽��*/
	int a,k;
	int c;
	int money;
	printf("\n\n\n\n\n		������ת����˺ţ�");
	scanf("%d",&a);
	/*�ȼ���˺��Ƿ����*/
	if(isExist(a))
	{
		gettopos(a);
		if(a==ID[mypos].id)
		{
			printf("\n\n\n		�������ת���˺����Լ����˺���ͬ����������ͬ�˻�ת�ˣ�ת��ʧ��\n");
			system("pause");
			return;
		}
		else
		{
			system("cls");
			printf("\n\n		������ת�˽��\n");
			printf("		\t\t\t\t\t\n");
			printf("		\t1:100Ԫ\t\t2:200Ԫ \t\n");
			printf("		\t\t\t\t\t\n");
			printf("		\t3:300Ԫ\t\t4:400Ԫ\t\n");
			printf("		\t\t\t\t\t\n");
			printf("		\t5:500Ԫ\t\t6:600Ԫ\t\n");
			printf("		\t\t\t\t\t\n");
			printf("		\t\t����������ѡ��");
			
			scanf("%d",&k);
			if(k>6||k<=0)            /*�������뷶Χ*/ 
			{
				printf("�Բ���������������\n\n");
				//system("pause");
				system("cls");
				return;
			}
			else
			{
				money=k*100;
				
				if(money>ID[mypos].money)        /*���������ж�*/ 
				{
					printf("		�Բ����������㣬ת��ʧ��\n");
				 	system("pause");
				 	system("cls");
			 	//  caidan();
				}
				else
				{
					printf("\n		������ת��%.2fԪ���˺�Ϊ%d,�û�����Ϊ%s���˺���\n",money*1.0,ID[topos].name);
					printf("\n		ͬ��������1:\n");
					printf("\n		��ͬ��������2:");
					scanf("%d",&c);
					switch(c)
					{
						case 1:ID[mypos].money=ID[mypos].money-money;
								ID[mypos].money=ID[mypos].money+money;
							   printf("\n		���ѳɹ�ת��%.2fԪ���˺�Ϊ%s���û�\n",money*1.0f,ID[topos].name);
							   break;
							   
				    	case 2:printf("\n		��ȡ����ת�˲�����ת�˲���ʧ��\n");break;
				    	default:printf("\n		 ���Ĳ�������ת�˲���ʧ��\n");
					}
					
					system("pause");
					system("cls");
				}
			}
		}
	}
	else
	{
		printf("\n		�������ת���˺Ų����ڣ�ת��ʧ��\n");
	}
	
}
/*�޸����뺯�� ��д����*/
void Modifythepassword ()
{
	char p1[M],p2[M],p3[M];
	printf("\n\n\n		����������ԭ���룺");
	scanf("%s",p1);
	if(strcmp(p1,ID[mypos].password)==0)
	{
		printf("\n\n		���������������룺");
		scanf("%s",p2);
		printf("\n\n		���ٴ��������������룺");
		scanf("%s",p3);
		if(strcmp(p2,p3)==0)
		{
			strcpy(ID[mypos].password,p2);
			
			printf("\n		�����޸ĳɹ�!\n");
		}
		else
		{
			printf("\n		�����������벻�ɹ��������޸�ʧ��\n");
			
		}
	}
	else
	{
		printf("\n		����������������޸�ʧ��\n");
		
	}


}
/*��ѯ��ǰ�û����� �����Ѿ���д*/
void query()
{
	//system("cls");
	printf("\n\n		����ǰ����ǣ�%d\n",ID[mypos].money);
	Sleep(500);
	system("pause");
	
}
/*�������� �Ѿ���д*/
void Openaccount()
{
	int kid;
	char kname[M];	/*��ǰ�û�����*/
	char kp1[M]; /*��ǰ�û�����*/
	clear(kp1);
	int kmoney=0;	/*��ǰ�û������*/
	int kcount=0;
	/*�����˺ţ�����˺��Ƿ���ڼ��˺ŵĺϷ���*/
	kid=Accountnumber();
	printf("\n		�����������û���:");
	scanf("%s",kname);
	/*�����˺�����*/
	twopw(kp1);
	
	/*������Ϣ��������*/
	ID[usernum].id=kid;   /*����kid��������id*/
	strcpy(ID[usernum].name,kname);   /*�������û�����������name*/
	strcpy(ID[usernum].password,kp1);
	ID[usernum].money=0;
	ID[usernum].count=kcount;
	usernum++;
	printf("\n");
	printf("		��ϲ�������ɹ������½\n");
	system("pause");
	system("cls"); 
}

void Signout()
{
	/*�������ֵ�浽�ĵ��У��������ǰ�û���״̬*/
	wdlqzt();
	
	//huanying();
	
	
	 
}
/*δ��½ǰ�û�״̬*/

void wdlqzt()
{
	int i;
/*  for(i=0;i<M;i++)
	{
		myname[i]='\0';
		
	}
	clear(mypassword);
	*/
	mypos=-1;   /*λ��Ϊ-1���޷���ȡ�������*/
//   mymoney=0;
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


/*���в˵�����  ��д*/

void Edit()
{
	int i;
	system("cls");
	
	while(1)
	{	system("cls");
		printf("\n\n\n\n\n		�𾴵Ŀͻ���%s����ӭ����",ID[mypos].name);   /*����ҵ��˵�*/
		printf("\n		  ��ѡ������Ҫ��ҵ��\n");/*����ҵ��˵�*/
		printf("		\t\t\t\t\t\n");
		printf("		\t1ȡ��\t\t2��ѯ\t\n");
		printf("		\t\t\t\t\t\n");
		printf("		\t3ת��\t\t4�޸�����\t\n");
		printf("		\t\t\t\t\t\n");
		printf("		\t5���\t\t6�˳�\t\n");
		printf("		\t\t\t\t\t\n");
		printf("		\t\t��ѡ��ҵ���ţ�\n");
		scanf("%d",&i);
		if(i<6||i>0)
		{
			switch(i)
			{
				case 1:					/*��������ȡ���*/
					Withdrawmoney();
					system("cls");
					break;
				case 2:					/*�������в�ѯ����*/ 
					//system("cls");
					query();
					system("cls");
					break;
				case 3:					/*��������ת�˺���*/ 
					system("cls");
					Transferaccounts();
					break;
				case 4:					/*���������޸����뺯��*/
					system("cls");
					Modifythepassword();
					break;
				case 5:					/*�������д���*/
					deposit();
					system("cls");
					break;
				case 6:
										/*���������˳�����*/
					system("cls");
					return; 			/*�˳���ǰ����*/
					
			}
		}
		else
		{
			printf("		������������\n");
			system("pause");
			system("cls");
		}
		
	}
	//Edit();
}

/*���ĵ��ж�ȡ���ݵ�������*/
void getdata()
{
	char ch;
	char*p;
	char str[100];
	int i=0;
	FILE*fp;
	char*strid;
	char*strname;
	char*strpw;
	char*strmoney;
	char*strcount;
	
	fp=fopen("d:\\stu.txt","r");   /*��ֻ����ʽ��*/
	if(!fp)
	{
		printf("�ļ����ܱ��򿪣������ļ�������\n");
		return;
	}
	ch=fgetc(fp);    /*��ȡһ���ַ�*/
	while(!feof(fp))   /*���û�е��ļ�������ѭ��������*/
	{
		if(ch=='\n')
		{
			str[i]='\0';
			p=strtok(str,"\t");
			ID[usernum].id=atoi(p);
			p=strtok(NULL,"\t");
			strcpy(ID[usernum].name,p);
			p=strtok(NULL,"\t");
			strcpy(ID[usernum].password,p);
			p=strtok(NULL,"\t");
			ID[usernum].money=atoi(p);
			p=strtok(NULL,"\t");
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

/*���ڴ��е����ݴ��浽�ĵ���*/
void savedata()
{
	
	int i;
	char s[128];
	clear(s);
	char p[128];
	FILE*fp;
	fp=fopen("d:\\stu.txt","w");  /*��ֻ��д��ʽ��*/
	if(!fp)
	{
		printf("�ļ����ܱ��򿪣������ļ�������\n");
		return;
	}
	
	
	
	for(i=0;i<usernum;i++)
	{
		itoa(ID[i].id,p,10);  /*��id[i]ת��Ϊʮ���Ƶ��ַ���������p��*/
		strcat(s,p);
		
		strcat(s,"\t");
		
		strcat(s,ID[i].name);
		strcat(s,"\t");
		
		
		strcat(s,ID[i].password);
		strcat(s,"\t");
		/*������ת��Ϊ�ַ���*/
		itoa(ID[i].money,p,10);
		
		strcat(s,p);
		strcat(s,"\t");
		
		/*printf("\ncount=%d\n",ID[usernum].count);*/
		itoa(ID[usernum].count,p,10);
		strcat(s,p);
		strcat(s,"\n");
		fputs(s,fp);
		clear(s);		 
	}
	fclose(fp);
}


/*����˺��Ƿ���ڣ������򷵻�1�����򷵻�0 ��д���*/
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
		printf("\n		�����������п�����:");
		scanf("%s",p1);
		printf("\n		���ٴ����������п�����:");
		scanf("%s",p2);
		/*�������벻һ��ʱҪ���ظ���������*/
		if(strcmp(p1,p2)!=0)
		{
			printf("		�����������벻һ�£���������������");
			
		}else{
			  strcpy(p,p1);
			  break;
		}
	}
	
}

/*¼���˺����*/
int  Accountnumber()
{
	int kid;
	system("cls");
	printf("\n		���������Ŀ���(4λ����):");
	
	scanf("%d",&kid);
	/*�����˺�ǰ�����ȼ���˺��Ƿ�Ϸ�*/
	if(isExist(kid)||(kid<1000||kid>10000))
	{
		printf("		�˺�%d�Ѿ����ڻ��߲��Ϸ����޷����д���!\n",kid);
		//Sleep(3000);
		system("pause");
		kid=Accountnumber();
	}
	return kid;
}
/*�˺����������*/
int check(int cid,char*cpw)
{
	int i;
	for(i=0;i<usernum;i++)
	{
		if(cid==ID[i].id)
			if(strcmp(ID[i].password,cpw)==0)
				{
					/*����û������������ȷ���½��������1*/
					mypos=i;
					return 1;
				}
	}
	
	return 0;
}

int gettopos(int toid)
{
	topos=-1;
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
