#include<stdio.h>
#include<string.h>
#define M 20
#define N 6
int main( )
{
	char no[M][20];
	char name[M][20];
	char sub[N][20];
	float total[M];
	float aver[M];
	int score[M][N];
	int i,j,s,p;
	char n;
	do
	{
		printf("Please enter the number of subject:");
		scanf("%d",&s);
		getchar();
		if(s<=N&&s>0) break;
		printf("Please enter a number no more than 6\n");
	}while(s>N||s<=0);
	do
	{
		printf("Please enter the number of people:");
		scanf("%d",&p);
		getchar();
		if(p<=M&&p>0) break;
		printf("Please enter a number no more than 20\n");
	}while(p>M||p<=0);
	while(1)
	{
		printf("\n\n\t\t 菜单\n");
		printf("\t======================\n");
		printf("\t\t1.输入\n");
		printf("\t\t2.查询\n");
		printf("\t\t3.显示\n");
		printf("\t\t4.排序\n");
		printf("\t\t0.退出\n");
		printf("\t======================\n");
		printf("please enter your choice:");
		scanf("%c",&n);
		getchar();
		switch(n)
		{
			case '1':
			{
				printf("please enter the name of %d subjects:",s);
				for(i=0;i<s;i++)
					{
					scanf("%s",&sub[i]);
					}
				for(i=0;i<p;i++)
					{
						total[i]=0;
						printf("please enter a number and a name:");
						scanf("%s%s",&no[i],&name[i]);
						printf("please enter the student's score:");
						for(j=0;j<s;j++)
						{
							scanf("%d",&score[i][j]);
							total[i]=total[i]+score[i][j];
							aver[i]=total[i]/s;
						}
					}
				getchar();
				break;
			}
			case '2':
			{
				int m;
				printf("\n\t\t查询内容\n");
				printf("\t======================\n");
				printf("\t\t1.姓名\n");
				printf("\t\t2.学号\n");
				printf("\t\t3.学科\n");
				printf("\t======================\n");
				printf("Please choose a way you want to search:");
				scanf("%d",&m);
				getchar();
				switch(m)
				{
					case 1:
					{
						char NAME[20];
						printf("Please enter the student's name:");
						scanf("%s",NAME);
						getchar();
						for(i=0;i<p;i++)
						{
							if(!strcmp(name[i],NAME))
							{
								printf("The student's information as follows:\n");
								printf("姓名:%s\n",name[i]);
								printf("学号:%s\n",no[i]);
								for(j=0;j<s;j++) printf("%s:%d\n",sub[j],score[i][j]);
								printf("总分:%.0f\n",total[i]);
								printf("平均:%.2f\n",aver[i]);
								break;
							}
						}
						if(i==p) printf("The student's message is not included\n");
						break;
					}
					case 2:
					{
						char NO[20];
						printf("Please enter the student's number:");
						scanf("%s",NO);
						getchar();
						for(i=0;i<p;i++)
						{
							if(!strcmp(no[i],NO))
							{
								printf("The student's information as follows:\n");
								printf("姓名:%s\n",name[i]);
								printf("学号:%s\n",no[i]);
								for(j=0;j<s;j++) printf("%s:%d\n",sub[j],score[i][j]);
								printf("总分:%.0f\n",total[i]);
								printf("平均:%.2f\n",aver[i]);
								break;
							}
						}
						if(i==p) printf("The student's message is not included\n");
						break;
					}
					case 3:
					{
						char SUB[20];
						printf("Please enter a subject:");
						scanf("%s",SUB);
						getchar();
						for(j=0;j<s;j++)
						{
							if(!strcmp(sub[j],SUB))
							{
								printf("The student's inforamation as follows:\n");
								printf("学科:%s\n",sub[j]);
								for(i=0;i<p;i++) printf("%s %s:%d\n",no[i],name[i],score[i][j]);
								break;
							}
						}
						if(j==s) printf("The subject's message is not included\n");
						break;
					}
					default:printf("Your entered a wrong choice\n");
				}
				break;
			}
			case '3':
			{
				printf("学号\t");
				printf("姓名\t");
				for(i=0;i<s;i++) printf("%s\t",sub[i]);
				printf("总分\t");
				printf("平均分\n");
				for(i=0;i<p;i++)
				{
					printf("%s\t",no[i]);
					printf("%s\t",name[i]);
					for(j=0;j<s;j++) printf("%d\t",score[i][j]);
					printf("%.0f\t",total[i]);
					printf("%.2f\n",aver[i]);
				}
				break;
			}
			case '4':
			{
				int m,z;
				float f;
				int str;
				char middle[20];
				printf("\n\t\t排序方式\n");
				printf("\t======================\n");
				printf("\t\t1.学号\n");
				printf("\t\t2.总分\n");
				printf("\t\t3.学科\n");
				printf("\t======================\n");
				printf("Please choose a way you want to search:");
				scanf("%d",&m);
				getchar();
				switch(m)
				{
					case 1:
					{
						printf("The solution:\n");
						for(i=0;i<p-1;i++)
						{
							for(j=0;j<p-i-1;j++)
							{
								str=strcmp(no[j],no[j+1]);
								if(str<0)
								{
									strcpy(middle,no[j]);
									strcpy(no[j],no[j+1]);
									strcpy(no[j+1],middle);
									strcpy(middle,name[j]);
									strcpy(name[j],name[j+1]);
									strcpy(name[j+1],middle);
									for(z=0;z<s;z++)
									{
										m=score[j][z];
										score[j][z]=score[j+1][z];
										score[j+1][z]=m;
									}
									f=total[j];
									total[j]=total[j+1];
									total[j+1]=f;
									f=aver[j];
									aver[j]=aver[j+1];
									aver[j+1]=f;
								}
							}
						}
					printf("学号\t");
					printf("姓名\t");
					for(i=0;i<s;i++) printf("%s\t",sub[i]);
					printf("总分\t");
					printf("平均分\n");
					for(i=0;i<p;i++)
					{
						printf("%s\t",no[i]);
						printf("%s\t",name[i]);
						for(j=0;j<s;j++) printf("%d\t",score[i][j]);
						printf("%.0f\t",total[i]);
						printf("%.2f\n",aver[i]);
					}
					break;	
					}
					case 2:break;
					case 3:break;
					default:printf("please give a right choice.\n");
				} 
			}
			case '0':break;
			default:printf("please enter a right choice from 0 to 4\n");
		}
		if(n=='0') break;
	}
	return 0;
} 