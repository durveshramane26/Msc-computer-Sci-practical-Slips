#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<fcntl.h>
int main()
{
	FILE *fp;
	int n,cnt2,cnt=1,flag=0,pid,i=0;
	char func[50],cmd[50],fnm[50],op[50],line[80],buff[80],ch;
	while(1)
	{
		printf("\n New Shell $ # ");
		gets(func);
		sscanf(func,"%s %s %s",cmd,op,fnm);
		if(strcmp(cmd,"typeline")==0)
		{
			fp=open(fnm,O_RDONLY);
			if(fp==-1)
			{
				printf("\n File Not Found");
			}
			else
			{
				if(op[0]=='+')
				{
					cnt=1;n=atoi(op);
					printf("\n First %d lines are",n);
					while(cnt<=n)
					{
						read(fp,buff,1);
						ch=buff[0];
						printf("%c",ch);
						if(ch=='\n')
							cnt++;
					}
					close(fp);
				}
				else if(op[0]=='a')
				{
					fp=open(fnm,O_RDONLY);
					while(read(fp,buff,1)!=0)
					{
						ch=buff[0];
						printf("%c",ch);
					}
					close(fp);
				}
				else if(op[0]=='-')
				{
					cnt=0;
					fp=open(fnm,O_RDONLY);
					n=atoi(op);
					printf("Print last %d lines \n",n);
					while(read(fp,buff,1)!=0)
					{
						ch=buff[0];
						if(ch=='\n')
						{
							cnt++;
						}
					}
					cnt2=cnt+n;
					int x=1;
					cnt=0;
					lseek(fp,0,SEEK_SET);
					while(x<=cnt2)
					{
						read(fp,buff,1);
						ch=buff[0];
						if(ch=='\n')
						{
							x++;
						}
					}
					while(read(fp,buff,1)!=0)
					{
						ch=buff[0];printf("%c",ch);
					}
					close(fp);
				}
			}
		}
	}
}
