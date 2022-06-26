#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<fcntl.h>
int main()
{
	FILE *fp;
	int n,cnt=1,flag=0,pid,i=0;char func[50],cmd[50],fnm[50],op[50],pat[50],line[80],buff[80],ch;
	while(1)
	{
		printf("\n New Shell $ # ");
		gets(func);
		sscanf(func,"%s %s %s %s",cmd,op,pat,fnm);
		pid=fork();
		if(pid==0)
		{
			if(strcmp(cmd,"search")==0)
			{
				fp=open(fnm,O_RDONLY);
				if(fp==-1)
				{
					printf("\n File Not Found");
				}
				else
				{
					if(op[0]=='f')
					{
						while(read(fp,buff,1)!=0)
						{
							ch=buff[0];
							if(ch!='\n')
							{
								line[i]=ch;
								i++;
							}
							if(ch=='\n')
							{
								line[i]=ch;
								if(strstr(line,pat)!=NULL)
								{
									flag=1;
									printf("Pattern found %s cnt=%d",pat,cnt);
									break;
								}
								else
								{
									flag=0;
									cnt++;
								}
								i=0;
							}
						}
						if(flag==0)
						{
							printf("\nPattern not found\n");
						}}
					else if(op[0]=='a')
					{
						while(read(fp,buff,1)!=0)
						{
							ch=buff[0];
							if(ch!='\n')
							{
								line[i]=ch;
								i++;
							}
							if(ch=='\n')
							{
								if(strstr(line,pat)!=NULL)
								{
									flag=1;
									printf("\n Pattern found %s cnt=%d",pat,cnt);
									cnt++;
								}
								else
								{
									flag=0;
									cnt++;
								}
								i=0;
							}
						}
						if(flag==0)
						{
							printf("\nPattern not found\n");
						}
					}
					else if(op[0]=='c')
					{
						cnt=0;
						while(read(fp,buff,1)!=0)
						{
							ch=buff[0];
							if(ch!='\n')
							{
								line[i]=ch;
								i++;
							}
							if(ch=='\n')
							{
								if(strstr(line,pat)!=NULL)
								{
									flag=1;
									cnt++;}
								i=0;
							}
						}
						printf("\n\n Pattern %s and at cnt=%d",pat,cnt);
					}
				}
			}
			else if(strcmp(cmd,'exit')==0)
			{
				exit(0);
			}
		}
	}
}
