#include<fstream.h>
#include<conio.h>
#include<math.h>
#include<dos.h>
#include<string.h>
#include<stdio.h>
#include<stdlib.h>
void multiplier(int &a,int &b,int &c)
{
 int i,j,k=0;
 int val1=(rand()%4)+0;
 int val2=(rand()%9)+1;
 int val3=(rand()%9)+1;
 for(i=0;i<4;i++)
 {
  for(j=0;j<10;j++)
  {
   for(k=0;k<10;k++)
   {
    clrscr();
    gotoxy(40,12);
    cout<<"x"<<i<<j<<"."<<k;
    delay(100-(i*10));
    if(val1==i && val2==j && val3==k)
    {
     a=i;
     b=j;
     c=k;
     return;
    }
    else
    continue;
   }
  }
 }
}


void crash(long double &balance)
{
 randomize();
 int p=0,q=0,r=0;
 char ch;
 char choice[50],choice1[50];
 long double bet, mul=1;
 do
 {
  cout<<"Would you like to 1)start playing     "<<endl;
  cout<<"                  2)want to go through a quick guide : ";
  gets(choice);
  if((strcmpi(choice,"2")==0) || (strcmpi(choice,"guide")==0))
  {
   clrscr();
   ifstream in("crash.txt",ios::in);
   char c;
   while(in)
   {
    in.get(c);
    cout<<c;
   }
   in.close();
   cout<<endl;
  }
 }while((strcmpi(choice,"2")==0) || (strcmpi(choice,"guide")==0));
 {
  do
  {
   clrscr();
   cout<<"-------------------------------------------------------------------------"<<endl;
   cout<<"                            WELCOME TO CRASH                          "<<endl;
   cout<<"-------------------------------------------------------------------------"<<endl;
   cout<<"Your current amount of chips are : "<<balance<<endl;
   cout<<"Would you like to do 1) autobetting  "<<endl;
   cout<<"                     2) manual bet : ";
   gets(choice1);
   if((strcmpi(choice1,"manual")==0) || (strcmpi(choice1,"2")==0))
   {
    cout<<"Place your bet : ";
    cin>>bet;
    balance=balance-bet;
    if(balance>=0)
    {
     cout<<"Type the multiplier you want to cashout at : x";
     cin>>mul;
     clrscr();
     gotoxy(35,12);
     cout<<"Crash will start in"<<endl;
     delay(500);
     clrscr();
     gotoxy(40,12);
     delay(1000);
     cout<<" 3";
     delay(1000);
     clrscr();
     gotoxy(40,12);
     cout<<" 2";
     delay(1000);
     clrscr();
     gotoxy(40,12);
     cout<<" 1";
     delay(1000);
     clrscr();
     multiplier(p,q,r);
     delay(2000);
     clrscr();
     cout<<"----------------------------------------------------------------------"<<endl;
     cout<<"                            WELCOME TO CRASH                          "<<endl;
     cout<<"----------------------------------------------------------------------"<<endl;
     cout<<endl<<"Your current amount of chips are :"<<balance<<endl;
     cout<<endl<<"Would you like to do 1)autobetting   ";
     cout<<endl<<"                     2)manual bet : "<<choice1<<endl;
     cout<<endl<<"Place your bet : "<<bet<<endl;
     cout<<endl<<"Type the multiplier u want to cashout at : x"<<mul<<endl;
     cout<<endl<<"Game crashed at : x"<<p<<q<<"."<<r<<endl;
     if(mul<=((p*10)+(q)+(r*0.1)))
     {
       textcolor(GREEN + BLINK);
       cprintf("                                   YOU WON                           ");cout<<endl;
       textcolor(WHITE);
       cout<<"New amount of chips are : "<<balance+(mul*bet)<<endl;
       balance=balance+(mul*bet);
     }
     else
     {
       textcolor(RED + BLINK);
       cprintf("                                   YOU LOST                   ");cout<<endl;
       textcolor(WHITE);
       cout<<"New amount of chips are : "<<balance<<endl;
     }
     cout<<endl<<"Would you like to continue playing [y/n] : ";
     cin>>ch;
    }
    if(balance<0)
    balance=0;
    else
    {
     cout<<"Not enough balance"<<endl;
    }
   }
   else if((strcmpi(choice1,"autobetting")==0)|| (strcmpi(choice1,"1")==0))
   {
    cout<<"Enter the number of times you want to bet : ";
    long double abet;
    int n=1,ic,dc,ic1,dc2;
    float amul=1;char ac;
    cin>>n;
    cout<<"Enter the first base bet : ";
    cin>>abet;
    cout<<"Enter the multiplier at which you want to cashout at : x";
    cin>>amul;
    cout<<"Do you want to return to base bet or increase the bet at win[r/i] : ";
    cin>>ac;
    if(ac=='r')
    {
     delay(1000);
     clrscr();
     for(int i=n;i>0;i--)
     {
      balance=balance-abet;
      if(balance>=0)
      {
       int ap,aq,ar;
       gotoxy(35,12);
       cout<<"Crash will start in"<<endl;
       delay(1000);
       clrscr();
       gotoxy(40,12);
       delay(1000);
       cout<<" 3";
       delay(1000);
       clrscr();
       gotoxy(40,12);
       cout<<" 2";
       delay(1000);
       clrscr();
       gotoxy(40,12);
       cout<<" 1";
       delay(1000);
       clrscr();
       multiplier(ap,aq,ar);
       delay(2000);
       clrscr();
       cout<<endl<<"                           Game crashed at : x"<<ap<<aq<<"."<<ar<<endl;
       if(amul<=((ap*10)+(aq)+(ar*0.1)))
       {
	textcolor(GREEN + BLINK);
	cprintf("                                   YOU WON                    ");cout<<endl;
	textcolor(WHITE);
	cout<<"                         New amount of chips are : "<<balance+(amul*abet)<<endl;
	balance = balance+(amul*abet);
       }
       else
       {
	textcolor(RED + BLINK);
	cprintf("                                   YOU LOST                  ");cout<<endl;
	textcolor(WHITE);
	cout<<"                         New amount of chips are : "<<balance<<endl;
       }
       delay(2000);
      }
      if(balance<0)
     { balance=0;
       cout<<"Not enough balance"<<endl;
       delay(1000);
       break;
      }
     }
       clrscr();
       cout<<"----------------------------------------------------------------------"<<endl;
       cout<<"                            WELCOME TO CRASH                          "<<endl;
       cout<<"----------------------------------------------------------------------"<<endl;
       cout<<endl<<"Your current amount of chips are :"<<balance<<endl;
       cout<<endl<<"Would you like to do 1)autobetting   ";
       cout<<endl<<"                     2)mannual bet : "<<choice1<<endl;
       cout<<endl<<"Place your bet : "<<abet<<endl;
       cout<<endl<<"Type the multiplier you want to cashout at : x"<<amul<<endl;
       cout<<endl<<"Enter the number of times you want to bet : "<<n;
       cout<<endl<<"Do you want to cash out at win or increase the bet at win[r/i] : "<<ac<<endl;
    }
    else if(ac=='i')
    {
     int am;
     cout<<"Enter the number by which you want to multiply the bet : ";
     cin>>am;
     delay(1000);
     clrscr();
     for(int i=n;i>0;i--)
     {
      if(balance>0)
      {
       balance =balance-abet;
       int ap,aq,ar;
       gotoxy(35,12);
       cout<<"crash will start in"<<endl;
       delay(1000);
       clrscr();
       gotoxy(40,12);
       delay(500);
       cout<<" 3";
       delay(500);
       clrscr();
       gotoxy(40,12);
       cout<<" 2";
       delay(500);
       clrscr();
       gotoxy(40,12);
       cout<<" 1";
       delay(1000);
       clrscr();
       multiplier(ap,aq,ar);
       delay(2000);
       clrscr();
       cout<<endl<<"                           Game crashed at : x"<<ap<<aq<<"."<<ar<<endl;
       if(amul<=((ap*10)+(aq)+(ar*0.1)))
       {
	delay(500);
	textcolor(GREEN +BLINK);
	cprintf("                                   YOU WON                   ");cout<<endl;
	textcolor(WHITE);
	cout<<"                          New amount of chips are : "<<balance+(amul*abet)<<endl;
	balance = balance+(amul*abet);
	abet=abet*am;
       }
       else
       {
	textcolor(RED + BLINK);
	cprintf("                                   YOU LOST                 ");cout<<endl;
	textcolor(WHITE);
	cout<<"                           New amount of chips are : "<<balance<<endl;
	abet=abet*am;
       }
       delay(2000);
       }
       else
       {
	cout<<"Not enough balance"<<endl;
	delay(1000);
	break;
       }
      }
	clrscr();
       cout<<"----------------------------------------------------------------------"<<endl;
       cout<<"                            WELCOME TO CRASH                          "<<endl;
       cout<<"----------------------------------------------------------------------"<<endl;
       cout<<endl<<"Your current amount of chips are :"<<balance<<endl;
       cout<<endl<<"Would you like to do 1)autobetting   ";
       cout<<endl<<"                     2)mannual bet : "<<choice1<<endl;
       cout<<endl<<"Place your bet : "<<abet<<endl;
       cout<<endl<<"Type the multiplier you want to cashout at : x"<<amul<<endl;
       cout<<endl<<"Enter the number of times you want to bet : "<<n;
       cout<<endl<<"Do you want to cash out at win or increase the bet at win[r/i] : "<<ac<<endl;

     }
     cout<<"Would you like to continue playing [y/n]===> ";
     cin>>ch;
    }
   }
   while(balance>0&&ch=='y');
   }

  }

