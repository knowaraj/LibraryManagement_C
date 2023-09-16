#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include <unistd.h>
struct book{
	int sn;
	char bname[30];
	char authname[30];
	char date[15];
}b;
struct student{
	int id;
	char stname[30];
	int bid;
	int clas;
	char bname[30];
	char date[15];
	
}s;
void add();
void booklist();
void issue();
void rmove();
void issuelist();
void login();
FILE *fb;
FILE *fi;
FILE *fp;
FILE *fd;
int main(){
	system("COLOR 70");
	int choice;
	login();
	MENU:
	printf(" \n\t____________Library Menu____________\n");
	printf("\n\t\t 1.Add a Book ");
	printf("\n\t\t 2.Issue a Book ");
	printf("\n\t\t 3.Remove a Book");
	printf("\n\t\t 4.Book List");
	printf("\n\t\t 5.Issued Book List");
	printf("\n\t\t 6.Return Issued Book");
	printf("\n\t\t 0.Exit");
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
			rmove();
			break;
		case 4:
			booklist();
			break;
		case 5:
			issuelist();
			break;
		case 6:
			retbook();
			break;
		case 0:
			exit(0);
		default:
			printf("Enter Correct choice. ");
			goto MENU;
	}
	goto MENU;
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

	printf("\nEnter date in year/month/day order : ");
	fflush(stdin);
	gets(b.date);
	
	fwrite(&b,sizeof(b),1,fb);
	
	printf("\nBook Added Successfully!!!\n\n\n\n\n\n\n");
	
	fclose(fb);
}
void booklist()
{
	system("cls");
	printf("\n\t\t________Available Books________\n\n");
	
	printf("%-10s %-30s %-20s %-15s\n\n","Book ID","Book Name","Author","Date");
	
	fb=fopen("library.txt","rb");
	while(fread(&b,sizeof(b),1,fb) == 1)
	{
		printf("%-10d %-30s %-20s %-15s\n\n",b.sn,b.bname,b.authname,b.date);
	}
	printf("\n\n\n\n\n\n\n");
}
void rmove()
{
	
	int id,check=0;
	system("cls");
	
	fb=fopen("library.txt","rb");
	
	printf("\n\tEnte Book id to Remove : ");
	scanf("%d",&id);
	
	
	fd =fopen("dlt.txt","wb");	
	
	while(fread(&b,sizeof(b), 1, fb)==1)
	{
		if(id==b.sn)
		{
			check=1;
			
			continue;
		}
		else
		{
			fwrite(&b,sizeof(b),1,fd);
		}
	}
	
	if(check==1)
	{
		printf("\n\tBook Deleted Successfully.\n\n\n\n\n\n");	
	}
	if(check!=1)
	{
		printf("\n\tRecord not found!!\n\n\n\n\n\n");	
	}
	fclose(fb);
	fclose(fd);
	
	remove("library.txt");
	rename("dlt.txt","library.txt");
	check=0;
}
void issue()
{
	int check=0;
	system("cls");
	
	fb=fopen("library.txt","rb");
	bk:
	printf("\n\tEnter book id to Issue : ");
	scanf("%d",&s.bid);
	
	while(fread(&b, sizeof(b), 1, fb)==1)
	{
		if(b.sn==s.bid)
		{
			check=1;
			strcpy(s.bname,b.bname);
			break;
		}
		else {
			check=2;
		}

	}
	if(check==2)
	{
		printf("\n\tRecord not found!!");
		printf("\n\tPlease enter correct book id. ");
		sleep(2);
		goto bk;
	}
	fi =fopen("issue.txt","ab");
	
	printf("\n\tEnter student name : ");
	fflush(stdin);
	gets(s.stname);
	
	printf("\n\tEnter student class : ");
	scanf("%d",&s.clas);
	
	printf("\n\tEnter student id : ");	
	fflush(stdin);
	scanf("%d",&s.id);
	 
	printf("\n\tEnter date in year/month/day order : ");
	fflush(stdin);
	gets(s.date);
	
	printf("\n\tBook Issued Successfully \n\n\n\n\n");	
	
	fwrite(&s,sizeof(s),1,fi);
	fclose(fi);
}

void retbook(){
	FILE *fs;
	int id,sn,check=0;
	system("cls");
	
	fi=fopen("issue.txt","rb");
	
	printf("\n\n\tEnter std id and book id to Remove : ");
	scanf("%d",&id);
	scanf("%d",&sn);
	
	
	fs =fopen("dl.txt","wb");	
	
	while(fread(&s,sizeof(s),1,fi)==1)
	{
		if(id ==s.id&&sn==s.bid)
		{
			check=1;
			continue;
		}
		else
		{
			fwrite(&s,sizeof(s),1,fs);
		}
	}
	
	if(check==1)
	{
	//	system("color 02");
		printf("\n\tBook returned Successfully..\n\n\n\n\n");	
	}
	if(check!=1)
	{
		//system("color 04");
		printf("\n\tRecord not found!!\n\n\n\n\n\n");	
	}
	fclose(fi);
	fclose(fs);
	
	remove("issue.txt");
	rename("dl.txt","issue.txt");
	check=0;
	
}
void issuelist()
{
	system("cls");
	printf("\n\t\t Issued Book list : ");
	
	printf("\n%-10s %-20s %-10s %-10s %-20s %-15s\n\n","Student ID","Student Name","Student Class","Book ID","Book name","Date");
	fi=fopen("issue.txt","rb");
	while(fread(&s,sizeof(s),1,fi)==1)
	{
		printf("\n%-10d %-20s %-13d %-10d %-20s %-15s\n\n",s.id,s.stname,s.clas,s.bid,s.bname,s.date);
			
	}
	printf("\n\n\n\n\n");
	fclose(fi);
}
void login()
{
 char us[]="devs";
 char pas[20];
 char ok[10];
 char ne[10];
 char get[10];
 int f,s;
	log:
   printf("\n%20.s-------------------------------------------");
   printf("\n\n\n\n%20.s     LIBRARY MANAGEMENT SYSTEM");
   printf("\n\n\n%20.s--------------------------------------------\n\n");
  printf("\n\tEnter the username  : ");
  gets(ok);
  fflush(stdin);
  printf("\n\n\tEnter the password/pin  :");
  gets(pas);
  fflush(stdin);
  system("cls");
    fp = fopen("LOG.txt","rb+");
	fgets(get,20,fp);
	if(strcmp(us,ok)!=0)
	{
		printf("\n\tUsername wrong try again !");
		sleep(3);
		goto log;
	}
	if(strcmp(us,ok)==0&&strcmp(pas,get)==0)
	{
		printf("\n\n\n\t\t\tLOGGED IN SUCCESSFULLY\n");
		sleep(3);
		system("cls");
	}
	else
	{
		rewind(fp);
		printf("\n\tPassword wrong!!\n\tIf forgot password Press 1 and any otherr to retry: ");
		scanf("%d",&f);
		fflush(stdin);
		
		if(f==1)
		{
			printf("\n\tEnter Security pin to change password : ");
			scanf("%d",&s);
			if(s==62)
			{
				fflush(stdin);
				printf("\n\tEnter New password/pin max length 8 : ");
				gets(ne);
				
				fprintf(fp, "%s", ne);
				printf("\n\tPassword changed Successfully . ");
				sleep(3);
				system("cls");
				
				
			}
		}
		else 
		{
			goto log;
		}
	}
   fclose(fp);
}

