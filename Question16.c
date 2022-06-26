#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<sys/stat.h>
int main()
{
	char cmd[80],t1[20],t2[20],t3[20],ch;
	int charcnt=0,linecnt=0,wcnt=0;
	FILE *fp;
	int pid;
	pid=vfork();printf("PP = %d",pid);
	if(pid==0)
	{
		while(1)
		{
			printf("\n NewShell$:");
			gets(cmd);
			sscanf(cmd,"%s %s %s",t1,t2,t3);
			if(strcmp(t1,"count")==0)
			{
				switch(t2[0])
				{
					case 'c' : fp=fopen(t3,"r");
						   while((ch=getc(fp))!=EOF)
						   {
							   charcnt++;
						   }
						   printf("\n No of chars = %d",charcnt);
						   fclose(fp);
						   break;
					case 'l' : fp=fopen(t3,"r");
						   while((ch=getc(fp))!=EOF)
						   {
							   if(ch=='\n')linecnt++;
						   }
						   printf("\n No of lines = %d",linecnt);
						   fclose(fp);
						   break;
					case 'w' : fp=fopen(t3,"r");
						   while((ch=getc(fp))!=EOF)
						   {
							   if(ch=='\n' || ch==' ')
								   wcnt++;
						   }
						   printf("\n No of words = %d",wcnt);
						   fclose(fp);
						   break;
					default : printf("Invalid Choice");
						  break;
				}
			}
			else
			{
				printf("Invalid Option");
				exit(0);
			}
		}
	}
}
