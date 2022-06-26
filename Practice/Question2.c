#include<stdio.h>
#include<fcntl.h>
#include"string.h"

int main() {
	int n=creat("file.txt","w");
	char ch[16]="hello world how are";
	char str[20]="od -c file.txt";
	system("chmod 777 file.txt");
	write(n,ch,16);
	lseek(n,48,SEEK_SET);
	write(n,ch,16);
	system(str);
	return(0);
}
