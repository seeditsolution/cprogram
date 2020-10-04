#include<string.h>
#include<iostream.h>
#include<dos.h>
#include<stdlib.h>
#include<conio.h>
#include<stdio.h>
#include<process.h>
#include<fstream.h>
#include<ctype.h>
#include<graphics.h>

class account
{
 int acno;
 char name[50];
 int deposit, withdraw;
 char type;
 public:
	void create_account()
	{
	 cout<<"\n\nEnter The Name of The account Holder ";
	 cin.getline(name,50);
	 cout<<"\nPLEASE ENTER YOUR CONTACT NO.";
		 if(acno<0)
		 {
		  acno=-(acno+rand() %10) ;
		 }
	 cin>>acno;

	 cout<<"\nEnter Type of The account (C/S) ";
	 cin>>type;
	 type=toupper(type);
	 cout<<"\nEnter The Initial Amount )";
	 cin>>deposit;
	 cout<<endl;
	 cout<<"YOUR ACCOUNT NUMBER IS:"<<acno;
	 cout<<"\n\n\nAccount Created..";
	 }

	void show_account()
	{

	 cout<<"\nAccount No. : "<<acno;
	 cout<<"\nAccount Holder Name : ";
	 puts(name);
	 cout<<"\nType of Account : "<<type;
	 cout<<"\nBalance amount : "<<deposit;

	 }

	void modify_account()
	{
	 cout<<"\nAccount No. : "<<acno;
	 cout<<"\nModify Account Holder Name : ";
	 gets(name);
	 cout<<"\nModify Type of Account : ";cin>>type;
	 cout<<"\nModify Balance Amount : ";cin>>deposit;

	 }

void dep(int x)
{
  deposit+=x;
}

void draw(int x)
{
  deposit-=x;
}

void report()
{cout<<acno<<"\t"<<name<<"\t\t"<<type<<"\t\t"<<deposit<<endl;}

  int  retacno()
  {return acno;}

  float retdeposit()
  {return deposit;}

  char rettype()
  {return type;}

};
 fstream fp;
 account ac;

void write_account()
   {
    fp.open("account.dat",ios::out|ios::app);
    ac.create_account();
    fp.write((char*)&ac,sizeof(account));
    fp.close();
   }

void display_sp(int n)
{
    clrscr();
    cout<<"\nBALANCE DETAILS\n";
    int flag=0;
    fp.open("account.dat",ios::in);
    while(fp.read((char*)&ac,sizeof(account)))
	{
	 if(ac.retacno()==n)
		{
		 ac.show_account();
		 flag=1;
		}
	}
    fp.close();
if(flag==0)
 cout<<"\n\nAccount number does not exist";
    getch();
}


void modify_account()
{
    int no,found=0;
    clrscr();
    cout<<"\n\n\tTo Modify ";
    cout<<"\n\n\tEnter The account No. of The account";
    cin>>no;
    fp.open("account.dat",ios::in|ios::out);
    while(fp.read((char*)&ac,sizeof(account)) && found==0)
	   {
	    if(ac.retacno()==no)
		   {
		    ac.show_account();
		    cout<<"\nEnter The New Details of account"<<endl;
		    ac.modify_account();
		    int pos=-1*sizeof(ac);
		    fp.seekp(pos,ios::cur);
		    fp.write((char*)&ac,sizeof(account));
		    cout<<"\n\n\t Record Updated";
		    found=1;
		   }
	     }
    fp.close();
    if(found==0)
    cout<<"\n\n Record Not Found ";
    getch();
}

void delete_account()
   {
    int no;
    clrscr();
    cout<<"\n\n\n\tDelete Record";
    cout<<"\n\nEnter The account no. of the customer You Want To Delete";
    cin>>no;
    fp.open("account.dat",ios::in|ios::out);
    fstream fp2;
    fp2.open("Temp.dat",ios::out);
    fp.seekg(0,ios::beg);
    while(fp.read((char*)&ac,sizeof(account)))
	{
	 if(ac.retacno()!=no)
		{
		 fp2.write((char*)&ac,sizeof(account));
		 }
	 }
    fp2.close();
    fp.close();
    remove("account.dat");
    rename("Temp.dat","account.dat");
    cout<<"\n\n\tRecord Deleted ..";
    getch();
    }

    void display_all()
    {
     clrscr();
     fp.open("account.dat",ios::in);
     if(!fp)
    {
       cout<<"ERROR!!! FILE COULD NOT BE OPEN\n\n\n Go To Admin Menu to create File";
       getch();
       return;
     }

     cout<<"\n\n\t\tACCOUNT HOLDER LIST\n\n";
	  cout<<"====================================================\n";
	  cout<<"A/c no.\tNAME\t\tType\t\tBalance\n";
	  cout<<"====================================================\n";

      while(fp.read((char*)&ac,sizeof(account)))
	 {
	   ac.report();
	}
     fp.close();
}

void deposit_withdraw(int option)
{
    int no,found=0,amt;
    clrscr();
    cout<<"\n\n\tEnter The account No.";
    cin>>no;
    fp.open("account.dat",ios::in|ios::out);
    while(fp.read((char*)&ac,sizeof(account)) && found==0)
       {
	    if(ac.retacno()==no)
	   {
		    ac.show_account();
		    if(option==1)
		       {
			cout<<"\n\n\tTO DEPOSITE AMOUNT ";
			cout<<"\n\nEnter The amount to be deposited";
			cin>>amt;
			ac.dep(amt);
		       }
		     if(option==2)
		       {
			cout<<"\n\n\tTO WITHDRAW AMOUNT ";
			cout<<"\n\nEnter The amount to be withdraw";
			cin>>amt;
			 int bal=ac.retdeposit()-amt;
			 if((bal<500 && ac.rettype()=='S') || (bal<1000 && ac.rettype()=='C'))
			      cout<<"Insufficience balance";
				   else
			       ac.draw(amt);
		      }
			 int pos=-1*sizeof(ac);
			 fp.seekp(pos,ios::cur);
			 fp.write((char*)&ac,sizeof(account));
			 cout<<"\n\n\t Record Updated";
			 found=1;
	       }
	 }
    fp.close();
    if(found==0)
    cout<<"\n\n Record Not Found ";
    getch();
}




void intro()
{
 clrscr();

 int gd=DETECT,gm;
 initgraph(&gd,&gm,"c://turboc3//bgi");

	  int i=0;
	  int x1,q1,w1,q2,w2,co1=5,co2=7;
	  int x2;
	  q1=getmaxy()-co1;
	  w1=getmaxx()-co1;
	  q2=getmaxy()-co2;
	  w2=getmaxx()-co2;
	  rectangle(5,5,w1,q1);
	  rectangle(7,7,w2,q2);
	 settextstyle(7,0,5);
	 setbkcolor(12);
	 setcolor(WHITE);
	 outtextxy(110,10,"BANK OF STUDENTS'");
	 settextstyle(6,0,4);
	 outtextxy(200,120,"''ALWAYS WITH YOU''");
	 setcolor(YELLOW);
	 rectangle(0,300,639,320);
	 rectangle(0,300,639,320);
	 x1=2;
	 x2=0;
	 setcolor(LIGHTGRAY);
	 settextstyle(0,0,1);
	   for(i=0;i<320;i++)
	    {
	     setcolor(WHITE);
		  line(x1+2*i,300,x2+2*i,320);
		  delay(15);
		  if(i>100&&i<150||i<25)
		   {
			delay(20);
		   }
		 if(i%30==0)
		    {
		      setcolor(BLACK);
			   for(int k=1;k<10;k++)
			      {
				line(0,299-k,600,299-k);
				}
				  setcolor(WHITE);
				      outtextxy(0,290,"   Loading  Database............................");
				}
		 if(i%30==10)
		    {
		      setcolor(BLACK);
		      for(int k=1;k<10;k++)
		      {
			line(0,299-k,600,299-k);
		      }
			     setcolor(WHITE);
			     outtextxy(0,290,"   Loading user module................................");
		    }
		  if(i%30==20)
		    {

		      setcolor(BLACK);
		      for(int k=1;k<10;k++)
			{
			    line(0,299-k,600,299-k);
			}

			 setcolor(WHITE);
      outtextxy(0,290,"   Loading Manager module.....................................");
    }
    if(i%30==29)
    {
      setcolor(BLACK);
      for(int k=1;k<10;k++)
      {
	line(0,299-k,600,299-k);
      }
      setcolor(WHITE);
      outtextxy(0,290,"   Loading Menu............................................");
    }
    if(i%3==0)
    {
     setcolor(RED);
     outtextxy(180,308,"L  O  A  D  I  N  G      D A T A B A S E");
    }
    }
     closegraph();
    }
     void login()
    {

	 char *name1,*name2={"a"},*name3=("a"),*pass1,*pass2={"a"};
	 int cheku,cheku1,chekp;

	  clrscr();
	   int gdriver=DETECT,gmode;
initgraph(&gdriver,&gmode,"C:\\TC\\BGI");
setbkcolor(0);
setcolor(12);
rectangle(140,12,468,460);
//floodfill(145,20,12);
setcolor(14);
rectangle(144,24,462,456);
setcolor(10);
rectangle(148,38,456,452);
setcolor(9);
rectangle(152,50,450,448);
 setcolor(5);
// floodfill(160,280,9);
 circle(300,110,30);
 circle(300,125,60);
 arc(300,170,0,180,30);
 setcolor(10);
 settextstyle(3,0,3);

	  outtextxy(158,250,"USERNAME");
	  rectangle(285,250,440,275);

	  gotoxy(37,10);
	  scanf("%s",name1);

	  cheku=strcmp(name1,name2);
	  cheku1=strcmp(name1,name3);
	  if(cheku==0 || cheku1==0)
	   {
	    outtextxy(158,295,"PASSWORD");
  rectangle(285,300,440,325);

	    xy:
	      gotoxy(37,12);
	      scanf("%s",pass1);
	     chekp=strcmp(pass1,pass2);
	      if(chekp==0)
	       {
		clrscr();
		gotoxy(27,13);
		cout<<"LOGIN SUCCESSFULL";
	       }
	      else
		{
			clrscr();
			gotoxy(26,5);
			cout<<"  WRONG PASSWORD \n \t  \t please re-enter your password\n";

			gotoxy(20,12);
			cout<<"ENTER PASSWORD";

		goto xy;
	}
      }
    else
    {
	gotoxy(27,13);
	cout<<"YOU ARE NOT AUTHORISED MEMBER";
	exit(0);
    }

     closegraph();
  }

void user()
{
char ch;
 do
    {
	  clrscr();
	  int gdriver=DETECT,gmode;
  initgraph(&gdriver,&gmode,"C:\\TC\\BGI");
  setbkcolor(0);
  setcolor(12);
  rectangle(115,55,485,425);
  setcolor(10);
  rectangle(120,60,480,420);
  setcolor(11);
  rectangle(125,65,475,415);
  settextstyle(3,0,4);

 outtextxy(235,80,"USER");
   setcolor(13);
  settextstyle(3,0,1);
 outtextxy(150,135,"01. NEW ACCOUNT");
 outtextxy(150,165,"02. DEPOSIT AMOUNT");
 outtextxy(150,195,"03. WITHDRAW AMOUNT");
 outtextxy(150,225,"04. BALANCE ENQUIRY");
 outtextxy(150,255,"05. EXIT");
 setcolor(14);
 outtextxy(150,365,"Select Your Option (1-5) ");

	  ch=getche();
	  switch(ch)
	  {
		case '1': clrscr();
			  write_account();
			  getch();
			break;
		case '2': clrscr();
			  deposit_withdraw(1);
			  break;
		case '3': clrscr();
			  deposit_withdraw(2);
			  getch();
			  break;
		case '4': int num;
			  clrscr();
			  cout<<"\n\n\tEnter The account No. ";
			  cin>>num;
			  display_sp(num);
			  break;
		  case '5':exit(0);
		  default :cout<<"\a";
	}
    }while(ch!='5');
    closegraph();
}

void manager()
{


char ch;

do
    {

	  clrscr();
	  int gdriver=DETECT,gmode;
  initgraph(&gdriver,&gmode,"C:\\TC\\BGI");
  setbkcolor(0);
  setcolor(14);
  rectangle(115,55,485,410);
  setcolor(2);
  rectangle(120,60,480,405);
  setcolor(11);
  rectangle(125,65,475,400);
  settextstyle(3,0,4);
  setcolor(12);
  outtextxy(235,80,"MANAGER");
  setcolor(13);
  settextstyle(3,0,1);
  outtextxy(150,135,"01. NEW ACCOUNT");
  outtextxy(150,170,"02. BALANCE ENQUIRY");
  outtextxy(150,205,"03. ALL ACCOUNT HOLDER LIST");
  outtextxy(150,240,"04. CLOSE AN ACCOUNT");
  outtextxy(150,275,"05. MODIFY AN ACCOUNT");
  outtextxy(150,305,"06. EXIT");
  setcolor(11);
  outtextxy(150,350,"Select Your Option (1-6) ");


	  ch=getche();
	  switch(ch)
	  {
		case '1': clrscr();
			  write_account();
			  getch();
			break;

		case '2': int num;
			  clrscr();
			  cout<<"\n\n\tEnter The account No. ";
			  cin>>num;
			  display_sp(num);
			  break;
		case '3': clrscr();
			  display_all();
			getch();
			 break;
		case '4': delete_account();
			  break;
		 case '5': clrscr();
			   modify_account();
			   getch();
			   break;
		  case '6':exit(0);
		  default :cout<<"\a";
	}
    }while(ch!='6');
    closegraph();
}

void cashier()
{
char ch;

do
    {
	  clrscr();

	   int gdriver=DETECT,gmode;
  initgraph(&gdriver,&gmode,"C:\\TC\\BGI");
  setbkcolor(0);
  setcolor(12);
  rectangle(115,55,485,425);
  setcolor(10);
  rectangle(120,60,480,420);
  setcolor(11);
  rectangle(125,65,475,415);
  settextstyle(3,0,4);

 outtextxy(235,80,"CASHIER");
   setcolor(13);
  settextstyle(3,0,1);
 outtextxy(150,135,"01. NEW ACCOUNT");
 outtextxy(150,165,"02. DEPOSIT AMOUNT");
 outtextxy(150,195,"03. WITHDRAW AMOUNT");
 outtextxy(150,225,"04. BALANCE ENQUIRY");
 outtextxy(150,255,"05. ALL ACCOUNT HOLDER LIST");
 outtextxy(150,285,"06. CLOSE AN ACCOUNT");
 outtextxy(150,315,"07. EXIT");
 setcolor(14);
 outtextxy(150,365,"Select Your Option (1-7) ");

	  ch=getche();
	  switch(ch)
	  {
		case '1': clrscr();
			  write_account();
			  getch();
			break;
		case '2': clrscr();
			  deposit_withdraw(1);
			  break;
		case '3': clrscr();
			  deposit_withdraw(2);
			  getch();
			  break;
		case '4': int num;
			  clrscr();
			  cout<<"\n\n\tEnter The account No. ";
			  cin>>num;
			  display_sp(num);
			  break;
		case '5': clrscr();
			  display_all();
			getch();
			 break;
		case '6': delete_account();
			  break;
		  case '7':exit(0);
		  default :cout<<"\a";
	}
    }while(ch!='5');

}


void main()
{

  char ch;

 int gd=DETECT,gm;
 initgraph(&gd,&gm,"c://turboc3//bgi");
  intro();

  do
    {

	  textbackground(6);
	  clrscr();
	  int gdriver=DETECT,gmode;
  initgraph(&gdriver,&gmode,"C:\\TC\\BGI");
  setbkcolor(0);
  setcolor(9);
  rectangle(135,38,488,464);
   setcolor(10);
   rectangle(140,45,482,458);
   setcolor(13);
   rectangle(146,52,476,452);
    settextstyle(3,0,2);
    setcolor(12);
   outtextxy(250,100, "MAIN MENU");
   setcolor(11);
   outtextxy(160,150,"1. USER");
   outtextxy(160,200,"2. MANAGER");
   outtextxy(160,250,"3. CASHIER");
   outtextxy(160,300,"4. EXIT");
   setcolor(10);
   outtextxy(150,385," Select Your Option (1-4)");

	  ch=getche();
	  switch(ch)
	  {
		case '1': clrscr();
			  login();
			  user();
			  getch();
			break;
		case '2': clrscr();
			  login();
			  manager();
			  break;
		case '3': clrscr();
			  login();
			  cashier();
			  break;
		  case '4':exit(0);
		  default :cout<<"\a";
	}
    }while(ch!='4');


}
