#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
void delay(unsigned int ms) {    
    clock_t start = clock();    
    while ((clock() - start) * 1000 / CLOCKS_PER_SEC < ms);    
}
struct book{
	int sn;
	char bname[30];
	char authname[30];
}b;
struct student{
	int id;
	char stname[30];
	char bname[30];
	char date[12];
	
}s;
void add();
void booklist();
//void issue();
//void rmove();
FILE *fb;
int main(){
	char x[]="devs";
	char y[4];
	int pass,p=2,choice;
	
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
	printf("\n\t\t 4.Book List");
	printf("\n\t\t 5.Exit");
	printf("\n\n\t\t Enter your choice :  ");
	scanf("%d",&choice);
	switch(choice)
	{
		case 1:
			add();
			break;
		case 2:
		//	issue();
			break;
		case 3:
		//	rmove();
			break;
		case 4:
			booklist();
			break;
		case 5:
			exit(0);
	}
	return 0;
	
}
void add()
{
	fb = fopen("library.txt","ab");
	
	printf("\nEnter Book id :  ");
	scanf("%d",&b.sn);
	
	printf("\nEnter Book name :  ");
	fflush(stdin);
	gets(b.bname);
	
	printf("\nEnter Author Name :  ");
	fflush(stdin);
	gets(b.authname);
	
	fwrite(&b,sizeof(b),1,fb);
	
	printf("\nBook Added Successfully!!!");
	
	fclose(fb);
}
void booklist()
{
	system("cls");
	system("color 0b");
	printf("________Available Books________\n\n");
	
	printf("%-10s %-30s %-20s\n\n","Book ID","Book Name","Author");
	
	fb=fopen("library.txt","rb");
//	rewind(fb);
	while(fread(&b,sizeof(b),1,fb) == 1)
	{
		printf("%-10d %-30s %-20s",b.sn,b.bname,b.authname);
	}
}
