#include<fstream.h>
#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#include<dos.h>
#include<string.h>
void roulette(long double &balance)
{
 char n;
 long double bet;
 char ch[50];
 do
 {
  cout<<"Would you like to 1)start playing     "<<endl;
  cout<<"                  2)go through a quick guide : ";
  gets(ch);
  if((strcmpi(ch,"2")==0) || (strcmpi(ch,"guide")==0))
  {
   clrscr();
   ifstream in("roul.txt",ios::in);
   char c;
   while(in)
   {
    in.get(c);
    cout<<c;
   }
   in.close();
   cout<<endl;
  }
 }while((strcmpi(ch,"2")==0) || (strcmpi(ch,"guide")==0));
 randomize();
 char a[12][50]={"00","01","02","03","04","05","06","07","08","09","10","11"};
 {
  char ch1;
  do
  {
   clrscr();
   cout<<"-----------------------------------------------------------------------------"<<endl;
   cout<<"                          WELCOME TO ROULETTE"<<endl;
   cout<<"-----------------------------------------------------------------------------"<<endl;
   cout<<"Your current amount of chips are : "<<balance<<endl;
   delay(1000);
   cout<<"bet on 1)even(betx2)"<<endl;
   cout<<"       2)odd(betx2) "<<endl;
   cout<<"       3)0(betx24)  : ";
   cin>>n;
   delay(1000);
   cout<<"enter the bet : ";
   cin>>bet;
   balance= balance-bet;
   if(balance>=0)
   {
    clrscr();
    gotoxy(32,12);
    cout<<"ROULETTE WILL START IN";
    delay(1000);
    clrscr();
    delay(500);
    gotoxy(40,12);
    cout<<"3";
    delay(500);
    clrscr();
    gotoxy(40,12);
    delay(500);
    cout<<"2";
    delay(500);
    clrscr();
    gotoxy(40,12);
    delay(500);
    cout<<"1";
    delay(500);
    char val[50];
    for(int i=0;i<200;i++)
    {
     clrscr();
     cout<<endl<<endl<<endl<<endl<<endl<<endl;
     int k=random(12);
     strcpy(val,a[k]);
     cout<<"                                       ";
     if(strcmpi(val,"00")==0)
     {
      textcolor(GREEN);
      cprintf(val);
      cout<<endl;
     }
     else if((strcmpi(val,"02")==0) || (strcmpi(val,"04")==0) || (strcmpi(val,"06")==0) || (strcmpi(val,"08")==0) || (strcmpi(val,"10")==0))
     {
      textcolor(RED);
      cprintf(val);
      cout<<endl;
     }
     else if((strcmpi(val,"01")==0) || (strcmpi(val,"03")==0) || (strcmpi(val,"05")==0) || (strcmpi(val,"07")==0) || (strcmpi(val,"09")==0) || (strcmpi(val,"11")==0))
     {
      textcolor(YELLOW);
      cprintf(val);
      cout<<endl;
     }
     textcolor(WHITE);
     cout<<"                                "<<a[random(12)]<<"     "<<"^^"<<"     "<<a[random(12)]<<endl;
     cout<<"                                "<<"       ||"<<endl;
     cout<<"                            "<<a[random(12)]<<"         ||         "<<a[random(12)]<<endl;
     cout<<"                                "<<"       ||"<<endl;
     cout<<"                           "<<a[random(12)]<<"                      "<<a[random(12)]<<endl<<endl;
     cout<<"                            "<<a[random(12)]<<"                    "<<a[random(12)]<<endl<<endl;
     cout<<"                                "<<a[random(12)]<<"           "<<a[random(12)]<<endl;
     cout<<"                                       "<<a[random(12)]<<endl;
     delay(i*1.5);
    }
    delay(1000);
    gotoxy(40,12);
    if(strcmpi(val,"00")==0)
    {
     textcolor(GREEN + BLINK);
     cprintf(val);
     textcolor(WHITE);
    }
    else if((strcmpi(val,"02")==0) || (strcmpi(val,"04")==0) || (strcmpi(val,"06")==0) || (strcmpi(val,"08")==0) || (strcmpi(val,"10")==0))
    {
     textcolor(RED + BLINK);
     cprintf(val);
     textcolor(WHITE);
    }
    else if((strcmpi(val,"01")==0) || (strcmpi(val,"03")==0) || (strcmpi(val,"05")==0) || (strcmpi(val,"07")==0) || (strcmpi(val,"09")==0) || (strcmpi(val,"11")==0))
    {
     textcolor(YELLOW + BLINK);
     cprintf(val);
     textcolor(WHITE);
    }
    delay(3000);
    clrscr();
    cout<<"-----------------------------------------------------------------------------"<<endl;
    cout<<"                          WELCOME TO ROULETTE"<<endl;
    cout<<"-----------------------------------------------------------------------------"<<endl;
    cout<<"Your current amount of chips are : "<<balance<<endl;
    delay(1000);
    cout<<"Bet on 1)even(betx2)"<<endl;
    cout<<"       2)odd(betx2)"<<endl;
    cout<<"       3)0(betx24) : "<<n<<endl;
    delay(1000);
    cout<<"Enter the bet : "<<bet<<endl;
    delay(2000);
    if((strcmpi(val,"00")==0) && n=='3')
    {
     textcolor(CYAN + BLINK);
     cprintf("                                YOU ARE SUPER LUCKY");cout<<endl;
     gotoxy(35,8);
     cprintf("                                     YOU WON");cout<<endl;
     textcolor(WHITE);
     delay(2000);
     cout<<" You won : "<<bet*24<<" chips"<<endl;
     cout<<"Your current amount of chips are : "<<balance+(bet*24);
     balance=balance+(bet*24);
    }
    else if(((strcmpi(val,"02")==0) || (strcmpi(val,"04")==0) || (strcmpi(val,"06")==0) || (strcmpi(val,"08")==0) || (strcmpi(val,"10")==0)) && (n=='1'))
    {
     textcolor(GREEN  + BLINK);
     cprintf("                                     YOU WON");cout<<endl;
     textcolor(WHITE);
     cout<<"You won : "<<bet*2<<" chips"<<endl;
     cout<<"Your current amount of chips are : "<<balance+(bet*2)<<endl;
     balance =balance+(bet*2);
    }
    else if(((strcmpi(val,"01")==0) || (strcmpi(val,"03")==0) || (strcmpi(val,"05")==0) || (strcmpi(val,"07")==0) || (strcmpi(val,"09")==0) || (strcmpi(val,"11")==0)) && (n=='2'))
    {
     textcolor(GREEN + BLINK);
     cprintf("                                     YOU WON");cout<<endl;
     textcolor(WHITE);
     cout<<"You won : "<<bet*2<<" chips"<<endl;
     cout<<"Your current amount of chips are : "<<balance+(bet*2)<<endl;
     balance =balance+(bet*2);
    }
    else
    {
     textcolor(RED + BLINK);
     cprintf("                                     YOU LOST");cout<<endl;
     textcolor(WHITE);
     cout<<"Your current amount of chips are : "<<balance<<endl;
    }
   }
   else
   cout<<"                         NOT ENOUGH BALANCE";
   cout<<endl<<"Would you like to continue playing [y/n] : ";
   cin>>ch1;
  }while(balance>0&&ch1=='y');
  if(balance<0)
  balance=0;
 }
}
