#include<fstream.h>
#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
#include<dos.h>
class hitting
{
   int val,ace;
  public:
   void hit()
   {
    randomize();
    cout<<"Hitting";
    delay(1000) ;
    cout<<".";
    delay(1000);
    cout<<"."<<endl;
    delay(500);
    val=(rand()%13)+1;
    if(val==1)
    {
     cout<<"You got a ACE"<<endl;
     cout<<"Would you like to treat this ace as a 1 or 11 : ";
     cin>>ace;
     val=ace;
    }
    else if(val==2 || val==3 || val==4 || val==5 || val==6 || val==7 || val==8 || val==9 || val==10)
    {
     cout<<"You got a "<<val<<endl;
    }
    else if(val==11)
    {
     val=val-1;
     cout<<"You got a JACK"<<endl;
    }
     else if(val==12)
    {
     val=val-2;
     cout<<"You got a QUEEN"<<endl;
    }
     else if(val==13)
    {
     val=val-3;
     cout<<"You got a KING"<<endl;
    }
   }
   int rval()
   {
     return val;
   }
};
class stand
{
 int deal,val1;
public:
 stand()
 {
  val1=0;
 }
 void dealing()
 {
  randomize();
  cout<<"No more bets------------------------------------------------------------------"<<endl<<"now its time for dealer's card"<<endl;
  cout<<"Dealer is drawing";
  delay(1000);
  cout<<".";
  delay(1000);
  cout<<"."<<endl;
  for(int i=0;i<20;i++)
  {
   if(val1<17)
   {
    deal=(rand()%13)+1;
    if(deal==1)
    {
     if(val1<=10)
     deal=11;
     else
     deal=1;
     delay(1000);
     cout<<"       ACE"<<endl;
    }
    else if(deal==2 || deal==3 || deal==4 || deal==5 || deal==6 || deal==7 || deal==8 || deal==9 || deal==10)
    {
     delay(1000);
     cout<<"      "<<deal<<endl;
    }
    else if(deal==11)
    {
     deal=deal-1;
     delay(1000);
     cout<<"      "<<"JACK"<<endl;
    }
    else if(deal==12)
    {
     deal=deal-2;
     delay(1000);
     cout<<"      "<<"QUEEN"<<endl;
    }
    else if(deal==13)
    {
     deal=deal-3;
     delay(1000);
     cout<<"      "<<"KING"<<endl;
    }
    val1=val1+deal;
   }
   else
   break;
  }
 }
 int value()
 {
  return val1;
 }
};
void black(long double &amu)
{
 char k[50];
 do
 {
  cout<<"Would you like to 1)start playing     "<<endl;
  cout<<"                  2)go through a quick guide : ";
  gets(k);
  if((strcmpi(k,"2")==0) || (strcmpi(k,"guide")==0))
  {
   clrscr();
   ifstream in("black.txt",ios::in);
   char c;
   while(in)
   {
    in.get(c);
    cout<<c;
   }
   in.close();
   cout<<endl;
  }
 }while((strcmpi(k,"2")==0) || (strcmpi(k,"guide")==0));
 char pa;
 do
 {
  clrscr();
  cout<<"-----------------------------------------------------------------------------"<<endl;
  cout<<"                                WELCOME TO BLACKJACK                         "<<endl;
  cout<<"-----------------------------------------------------------------------------"<<endl;
  stand s;
  hitting h;
  int fval=0,ch1;
  long double prof,bet;
  cout<<"Your current amount of chips are : "<<amu<<endl;
  cout<<"Enter the amount of chips you want to bet on : ";
  cin>>bet;
  amu=amu-bet;
  if(amu>=0)
  {
   for(int i=0;i<=10;i++)
   {
    cout<<"Would you like to 1)Hit     "<<endl;
    cout<<"                  2)Stand : " ;
    cin>>ch1;
    if(ch1==1 )
    {
     h.hit();
     int c=h.rval() ;
     fval=fval+c;
     cout<<"Your total card worth is : "<<fval<<endl;
     if(fval>21)
     {
      textcolor(RED + BLINK);
      cprintf("                                      BUST");cout<<endl;
      cprintf("                                   YOU LOST");cout<<endl;
      textcolor(WHITE);
      cout<<"Your current amount of chips are : "<<amu;
      break;
     }
     else if(fval==21)
     {
      textcolor(GREEN + BLINK);
      cprintf("                                 BLACKJACK                                    ");cout<<endl;
      prof=bet*1.5;
      cprintf("                                 YOU WON  ");cout<<endl;
      textcolor(WHITE);
      amu=amu+prof;
      cout<<"Your current amount of chips are : "<<amu;
      break;
     }
    }
    else if(ch1==2)
    {
     s.dealing();
     int a=s.value();
     cout<<"Dealer's card worth is:"<<a<<endl;
     if(a>21)
     {
      textcolor(GREEN + BLINK);
      prof=bet*1.5;
      cprintf("                                    DEALER BUSTS");cout<<endl;
      cprintf("                                      YOU WON  ");cout<<endl;
      textcolor(WHITE);
      amu=amu+prof;
      cout<<"Your current amount of chips are : "<<amu;
      break;
     }
     else if(fval==a)
     {
      cout<<"                                  IT'S A TIE"<<endl;
      amu=amu+bet/2;
      cout<<"Your current amount of chips are : "<<amu;
      break;
     }
     else if((fval==21 || fval>=a || a>21)&& fval<22)
     {
      textcolor(GREEN + BLINK);
      cprintf("                                BLACKJACK                                      ");cout<<endl;
      prof=bet*1.5;
      cprintf("                                 YOU WON  ");cout<<endl;
      textcolor(WHITE);
      amu=amu+prof;
      cout<<"Your current amount of chips are : "<<amu;
      break;
     }
     else
     {
      textcolor(RED + BLINK);
      cprintf("                                 YOU LOST");cout<<endl;
      textcolor(WHITE);
      cout<<"Your current amount of chips are : ";
      cout<<amu;
      break;
     }
    }
    else
    cout<<"You have entered the wrond choice"<<endl;
   }
   cout<<endl<<"Would you like to play again(y/n) : ";
   cin>>pa;
  }
  else
  {
   cout<<"not enough balance";
   break;
  }
 }while(pa=='y' && amu>0) ;
 cout<<"                      THANK YOU FOR PLAYING BLACKJACK                          "<<endl;
if(amu<0)
amu=0;
}








