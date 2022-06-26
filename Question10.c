#include <stdio.h>
#include <dirent.h>
int main()
{
	struct dirent *de; //pointer to directory entry
	DIR *dr = opendir("."); //open current directory
	int cnt = 0;
	if(dr == NULL) // check if directory not exist
	{
		printf("Cannot open a file \n");
		return 0;
	}
	printf("Files in current Directory :\n");
	while((de = readdir(dr))!= NULL )
	{
		printf("%s \n", de->d_name);
		cnt++;
	}
	printf("\nTotal Number of Files in current directory : %d\n",cnt);
	return 1;
}
