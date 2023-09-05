#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
void delay(unsigned int ms) {    
    clock_t start = clock();    
    while ((clock() - start) * 1000 / CLOCKS_PER_SEC < ms);    
}
void add()
{
	
}
void issue()
{
	
}
void retarn()
{
	
}
int main(){
	char x[]="devs";
	char y[4];
	int pass,p=2,choice;
	FILE *f;
	Log:
	printf(" \n____________Library Login____________\n");
	printf("\n\t\t Username: ");
	gets(y);
	printf("\n\t\t PIN: ");
	scanf("%d",&pass);
	system("cls");
	int cmp=strcmp(x,y);
//	printf("%d",cmp);
	if(cmp==0 && pass==p)
	{
		printf("\n\t\t Login successful.....");	
		delay(1000);  
	}
	else{
		printf("\n\t\tProvided Username and PIN didnt matchh ...");
		goto Log;
	}
	printf(" \n____________Library Menu____________\n");
	printf("\n\t\t 1.Add a Book ");
	printf("\n\t\t 2.Issue a Book ");
	printf("\n\t\t 3.Return a Book");
	printf("\n\t\t 4.Exit");
	printf("\n\n\t\t Enter your choice :  ");
	scanf("%d",&choice);
	switch(choice)
	{
		case 1:
			add();
			break;
		case 2:
			issue();
			break;
		case 3:
			retarn();
			break;
		case 4:
			exit(0);
	}
	return 0;
	
}
