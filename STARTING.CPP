#include<iostream.h>
#include<fstream.h>
#include<conio.h>
#include<string.h>
#include<stdio.h>
#include<ctype.h>
#include<dos.h>
#include<stdlib.h>
char tempna[50];
char un[50],pass3[50];
int a=0;
class casino
{
  char uname[50];
  long double amount;
  long double up;
  char password[50];
  public:
   void getdata()
   {
    char p,p1,p2;
    char pass[50];
    cout<<"Enter your name : ";
    gets(uname);
    cout<<"Enter password (enter sapce after password): ";
    for(int i=0;i<50;i++)
    {
     p=getch();
     if(p==' ')
     {
      password[i]='\0';
      break;
     }
     else
     {
      password[i]=p;
      cout<<"*";
     }
    }
    int c=0;
    do
    {
     cout<<endl<<"confirm password: ";
     for(i=0;i<50;i++)
     {
      p1=getch();
      if(p1==' ')
      {
       pass[i]='\0';
       break;
      }
      else
      {
       pass[i]=p1;
       cout<<"*";
      }
     }
     c++;
     if(c%2==0)
     {
      cout<<endl<<"Show password [y/n]- ";
      cin>>p2;
      if(p2=='y')
      puts(password);
     }
    }while(strcmpi(password,pass)!=0);
    cout<<endl<<"Enter your amount of chips: ";
    cin>>amount;
   }

   void update()
   {
    char pass1[50],p3;
    cout<<"enter the password(press space after the password) - ";
    for(int i=0;i<50;i++)
    {
     p3=getch();
     if(p3==' ')
     {
      pass1[i]='\0';
      break;
     }
     else
     {
      pass1[i]=p3;
      cout<<"*";
     }
    }
    if(strcmpi(pass1,password)==0)
    {
     char x;
     int n;
     do
     {
      cout<<endl<<"what would you like to update - "<<endl;
      cout<<"                     1)username"<<endl;
      cout<<"                     2)password"<<endl;
      cout<<"                     3)chips - ";
      cin>>n;
      switch(n)
      {
       case 1:
       {
	cout<<endl<<"Enter the new username - ";
	gets(un);
	strcpy(uname,un);
	break;
       }
       case 2:
       {
	cout<<endl<<"enter the new password(press space after the password) - ";
	char p5;
	for(i=0;i<50;i++)
	{
	 p5=getch();
	 if(p5==' ')
	 {
	  pass3[i]='\0';
	  break;
	 }
	 else
	 {
	  pass3[i]=p5;
	  cout<<"*";
	 }
	}
	strcpy(password,pass3);
	break;
       }
       case 3:
       {
	char w;
	cout<<endl<<"would you like to withdraw or deposite amount[w/d] - ";
	cin>>w;
	if(w=='d')
	{
	 cout<<endl<<"Enter the amount you want to add : ";
	 cin>>up;
	 amount=amount+up;
	}
	else if(w=='w')
	{
	 cout<<endl<<"Enter the amount you want to withdraw : ";
	 cin>>up;
	 amount=amount-up;
	}
	break;
       }
       default:
       {
	cout<<endl<<"Wrong input";
	break;
       }
      }
      cout<<endl<<"Would you like to continue updating[y/n] - ";
      cin>>x;
     }while(x=='y');
    }
    else
    {
     cout<<endl<<"                               wrong password"<<endl;
     textcolor(RED);
     cprintf("                                  LAST CHANCE");
     textcolor(WHITE);
     cout<<endl<<"enter the password(press space after the password) - ";
     char pass2[50],p4;
     for(i=0;i<50;i++)
     {
      p4=getch();
      if(p4==' ')
      {
       pass2[i]='\0';
       break;
      }
      else
      {
       pass2[i]=p4;
       cout<<"*";
      }
     }
     if(strcmpi(pass2,password)==0)
    {
     char x;
     int n;
     do
     {
      cout<<endl<<"what would you like to update - "<<endl;
      cout<<"                     1)username"<<endl;
      cout<<"                     2)password"<<endl;
      cout<<"                     3)chips - ";
      cin>>n;
      switch(n)
      {
       case 1:
       {
	cout<<endl<<"Enter the new username - ";
	gets(un);
	strcpy(uname,un);
	break;
       }
       case 2:
       {
	cout<<endl<<"enter the new password(press space after the password) - ";
	char p5;
	for(i=0;i<50;i++)
	{
	 p5=getch();
	 if(p5==' ')
	 {
	  pass3[i]='\0';
	  break;
	 }
	 else
	 {
	  pass3[i]=p5;
	  cout<<"*";
	 }
	}
	strcpy(password,pass3);
	break;
       }
       case 3:
       {
	char w;
	cout<<endl<<"would you like to withdraw or deposite amount[w/d] - ";
	cin>>w;
	if(w=='d')
	{
	 cout<<endl<<"Enter the amount you want to add : ";
	 cin>>up;
	 amount=amount+up;
	}
	else if(w=='w')
	{
	 cout<<endl<<"Enter the amount you want to withdraw : ";
	 cin>>up;
	 amount=amount-up;
	}
	break;
       }
       default:
       {
	cout<<endl<<"Wrong input";
	break;
       }
      }
      cout<<endl<<"Would you like to continue updating[y/n] - ";
      cin>>x;
     }while((x=='y'));
    }
     else
     {
      clrscr();
      gotoxy(34,12);
      cout<<"WRONG PASSWORD";
      delay(2000);
      gotoxy(34,13);
      textcolor(RED + BLINK);
      cprintf("SECURITY ALERT");
      delay(4000);
      a++;
     }
    }
   }
   char* rname()
   {
    return uname;
   }
   char* rpassword()
   {
    return password;
   }
   long double ramu()
   {
    return amount;
   }
   void fn(long double k ,char lname[50] , char lpass[50])
   {
    strcpy(uname,lname);
    strcpy(password,lpass);
    amount=k;
   }
}ca;

long double netamu;
char ch1[50];
void login()
{
   char ch3[50],ch2[10];
   int pass,temp=0;
   long double amu;
   long pos;
   cout<<"-----------------------------------------------------------------------------"<<endl;
   gotoxy(30,2);
   cout<<"WELCOME TO CASINO++ "<<endl;
   cout<<"-----------------------------------------------------------------------------"<<endl;
   gotoxy(25,4);
   cout<<" HERE YOUR DREAMS CAN COME TRUE "<<endl;
   cout<<"Are you a 1)existing user  "<<endl;
   cout<<"          2)new user     : ";
 gets(ch1);
 if((strcmpi(ch1,"2")==0) || (strcmpi(ch1,"new")==0))
 {
  fstream inout("entry.dat",ios::binary | ios::in | ios::out | ios::ate);
  pos=inout.tellg();
  ca.getdata();
  strcpy(un,ca.rname());
  strcpy(pass3,ca.rpassword());
  inout.write((char*)&ca,sizeof(ca));
  clrscr();
  cout<<"-----------------------------------------------------------------------------"<<endl;
  cout<<"                                  WELCOME  "<<endl;
  cout<<"-----------------------------------------------------------------------------"<<endl;
  cout<<"You have successfully entered.Now you can be a part of this casino"<<endl;
  cout<<"Your current chips are : "<<ca.ramu()<<endl;
  netamu=ca.ramu();
  cout<<"Would you like to 1)update account  "<<endl;
  cout<<"                  2)start playing : ";
  gets(ch3);
  if((strcmpi(ch3,"1")==0) || (strcmpi(ch3,"update")==0))
  {
   ca.update();
   inout.seekp(pos);
   inout.write((char*)&ca,sizeof(ca));
   if(a!=0)
   {
    exit(0);
   }
   cout<<endl<<"your current chips are : "<<ca.ramu()<<endl;
   netamu=ca.ramu();
  }
  inout.close();
 }

 else if((strcmpi(ch1,"1")==0) || (strcmpi(ch1,"existing")==0))
 {
  char en[50],ep[50];
  cout<<"Enter your registered username : ";
  gets(en);
  cout<<"enter the password(press space after the password) - ";
  char p6;
  for(int i=0;i<50;i++)
  {
   p6=getch();
   if(p6==' ')
   {
    ep[i]='\0';
    break;
   }
   else
   {
    ep[i]=p6;
    cout<<"*";
   }
  }
  fstream inout("entry.dat",ios::binary|ios::in | ios::out );
  while(inout)
  {
   pos=inout.tellg();
   inout.read((char*)&ca,sizeof(ca));
   if(strcmpi(en,ca.rname())==0)
   {
    if(strcmp(ep,ca.rpassword())==0)
    {
     temp++;
     clrscr();
     strcpy(un,en);
     strcpy(pass3,ep);
     cout<<"-----------------------------------------------------------------------------"<<endl;
     cout<<"                                    WELCOME                                   "<<endl;
     cout<<"-----------------------------------------------------------------------------"<<endl;
     cout<<"You have successfully entered.Now you can be a part of this casino"<<endl;
     cout<<"Your current chips are : "<<ca.ramu()<<endl;
     netamu=ca.ramu();
     cout<<"would you like to 1)update account  "<<endl;
     cout<<"                  2)use balance : ";
     gets(ch3);
     if((strcmpi(ch3,"1")==0) || (strcmpi(ch3,"update")==0))
     {
      ca.update();
      inout.seekg(pos);
      inout.write((char*)&ca,sizeof(ca));
      if(a!=0)
      {
       exit(0);
      }
      cout<<"Now your current chips are :"<<ca.ramu()<<endl;
      netamu=ca.ramu();
     }
    }
   }
  }
  inout.close();
  if(temp==0)
  {
   cout<<endl<<"                             INVALID USERNAME OR PASSWORD"<<endl;
   textcolor(RED + BLINK);
   cprintf("                                     LAST ATTEMPT");
   char en[50],ep[50];
   textcolor(WHITE);
   cout<<endl<<"Enter your registered username : ";
   gets(en);
   cout<<"enter the password(press space after the password) - ";
   char p6;
   for(int i=0;i<50;i++)
   {
    p6=getch();
    if(p6==' ')
    {
     ep[i]='\0';
     break;
    }
    else
    {
     ep[i]=p6;
     cout<<"*";
    }
   }
   fstream inout("entry.dat",ios::binary|ios::in | ios::out );
   while(inout)
   {
    pos=inout.tellg();
    inout.read((char*)&ca,sizeof(ca));
    if(strcmpi(en,ca.rname())==0)
    {
     if(strcmp(ep,ca.rpassword())==0)
     {
      temp++;
      clrscr();
      strcpy(un,en);
      strcpy(pass3,ep);
      cout<<"-----------------------------------------------------------------------------"<<endl;
      cout<<"                                    WELCOME                                   "<<endl;
      cout<<"-----------------------------------------------------------------------------"<<endl;
      cout<<"You have successfully entered.Now you can be a part of this casino"<<endl;
      cout<<"Your current chips are : "<<ca.ramu()<<endl;
      netamu=ca.ramu();
      cout<<"would you like to 1)update account  "<<endl;
      cout<<"                  2)use balance : ";
      gets(ch3);
      if((strcmpi(ch3,"1")==0) || (strcmpi(ch3,"update")==0))
      {
       ca.update();
       inout.seekg(pos);
       inout.write((char*)&ca,sizeof(ca));
       if(a!=0)
       {
	exit(0);
       }
       cout<<"Now your current chips are :"<<ca.ramu()<<endl;
       netamu=ca.ramu();
      }
     }
    }
   }
   inout.close();
   if(temp==0)
   {
    clrscr();
    gotoxy(32,12);
    cout<<"NO SUCH ACCOUNT EXISTS";
    delay(2000);
    gotoxy(36,13);
    textcolor(RED + BLINK);
    cprintf("SECURITY ALERT");
    textcolor(WHITE);
    delay(4000);
    exit(0);
   }
  }
 }
}
void finalupdate()
{
 ifstream in("entry.dat",ios::binary | ios::in );
 ofstream out("temp.dat",ios::binary | ios::out);
 while(in)
 {
  in.read((char*)&ca,sizeof(ca));
  if(in.eof())break;
  if(strcmpi(ca.rname(),un)==0)
  {
   ca.fn(netamu,un,pass3);
   out.write((char*)&ca,sizeof(ca));
  }
  else
  out.write((char*)&ca,sizeof(ca));
 }
 in.close();
 out.close();
 remove("entry.dat");
 rename("temp.dat","entry.dat");
}