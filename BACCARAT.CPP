#include<fstream.h>
#include<conio.h>
#include<string.h>
#include<stdio.h>
#include<ctype.h>
#include<dos.h>
#include<stdlib.h>
void baccarat(long double &bn)
{
 char bch;
 char o[50];
 do
 {
  cout<<"Would you like to 1)start playing     "<<endl;
  cout<<"                  2)want to go through a quick guide : ";
  gets(o);
  if((strcmpi(o,"2")==0) || (strcmpi(o,"guide")==0))
  {
   clrscr();
   ifstream in("bacca.txt",ios::in);
   char c;
   while(in)
   {
    in.get(c);
    cout<<c;
   }
   in.close();
   cout<<endl;
  }
 }while((strcmpi(o,"2")==0) || (strcmpi(o,"guide")==0));
 do
 {
  clrscr();
  long double bb;
  cout<<"--------------------------------------------------------------------------------";
  gotoxy(30,2);
  cout<<"WELCOME TO BACCARAT COUNTER"<<endl;
  cout<<"--------------------------------------------------------------------------------";
  delay(1000);
  cout<<"Your current amount of chips are : "<<bn<<endl;
  cout<<"Let's begin"<<endl;
  delay(1000);
  cout<<"Let's place a bet 1- bet on player                 "<<endl;
  cout<<"                  2- bet on banker(5%commission) : "<<endl;
  cout<<"                  3- bet on tie                  : "<<endl;
  delay(1000);
  cout<<"Choose your bet on : ";
  int bc;
  cin>>bc;
  delay(500);
  if(bc==1)
  {
   cout<<"Place your bet on the player : ";
   cin>>bb;
   cout<<"betting closed-----------------------------------------------------------------"<<endl;
  }
  else if(bc==2)
  {
   cout<<"Place your bet on the banker : ";
   cin>>bb;
   cout<<"betting closed-----------------------------------------------------------------"<<endl;
  }
  else if(bc==3)
  {
   cout<<"Place your bet on tie : ";
   cin>>bb;
   cout<<"betting closed-----------------------------------------------------------------"<<endl;
  }
  else
  {
   delay(1000);
   cout<<"You entered a wrong choice"<<endl;
   cout<<"bets closed--------------------------------------------------------------------";
   delay(2000);
   exit(0);
  }
  randomize();
  int bp1= random(10);
  int bp2= random(10);
  int bb1= random(10);
  int bb2= random(10);
  cout<<"Cards drawn by player are : ";
  delay(1000);
  cout<<bp1<<endl;
  cout<<"                            "<<bp2<<endl;
  cout<<"Cards drawn by banker are : ";
  delay(2000);
  cout<<bb1<<endl;
  cout<<"                            "<<bb2<<endl;
  int bfp =(bp1+bp2)%10;
  int bfb= (bb1+bb2)%10;
  delay(1000);
  cout<<"Player hand value : "<<bfp<<endl;
  delay(1000);
  cout<<"Banker hand value : "<<bfb<<endl;
  if(bfp==0||bfp==1||bfp==2||bfp==3||bfp==4||bfp==5)
  {
   cout<<"Player hand draws a card..."<<endl;
   int bp3=random(10);
   delay(3000);
   cout<<"Card drawn by player is : "<<bp3<<endl;
   bfp=(bp1+bp2+bp3)%10;
   delay(3000);
   cout<<"New player hand value is : "<<bfp<<endl;
   if(bfb==0||bfb==1||bfb==2)
   {
    delay(3000);
    cout<<"Banker draws a card..."<<endl;
    int bb3= random(10);
    delay(3000);
    cout<<"Card drawn by banker is : "<<bb3<<endl;
    bfb=(bb1+bb2+bb3)%10;
    delay(3000);
    cout<<"New banker hand value is : "<<bfb<<endl;
   }
   else if(bfb==3||bfb==4||bfb==5||bfb==6)
   {
    if(bfp>=bfb)
    {
     delay(3000);
     cout<<"Banker draws a card..."<<endl;
     int bb3 =random(10);
     delay(3000);
     cout<<"Card drawn by the banker is : "<<bb3<<endl;
     bfb=(bb1+bb2+bb3)%10;
     delay(3000);
     cout<<"New banker handd value is : "<<bfb<<endl;
    }
    else
    {
     delay(3000);
     cout<<"Banker stands"<<endl;
    }
   }
   else if(bfb==7)
   {
    delay(3000);
    cout<<"Banker stands"<<endl;
   }
   else
   {
    delay(3000);
    cout<<"Natural"<<endl; }
   }
   else if(bfp==6||bfp==7)
   {
    delay(3000);
    cout<<"Player stands"<<endl;
    if(bfb==0||bfb==1||bfb==2)
    {
     delay(3000);
     cout<<"Banker draws a card..."<<endl;
     int bb3= random(10);
     delay(3000);
     cout<<"card drawn by the banker is : "<<bb3<<endl;
     bfb=(bb1+bb2+bb3)%10;
     delay(3000);
     cout<<"New banker hand value is : "<<bfb<<endl;
    }
    else if(bfb==3||bfb==4||bfb==5||bfb==6)
    {
     if(bfp>=bfb)
     {
      delay(3000);
      cout<<"Banker draws a card..."<<endl;
      int bb3 =random(10);
      delay(3000);
      cout<<"Card drawn by the banker is : "<<bb3<<endl;
      bfb=(bb1+bb2+bb3)%10;
      delay(3000);
      cout<<"New banker hand value is : "<<bfb<<endl;
     }
    else
    {
     delay(3000);
     cout<<"Banker stands"<<endl;
    }
   }
   else if(bfb==7)
   {
    delay(3000);
    cout<<"Banker stands"<<endl;
   }
   else
   {
    delay(3000);
    cout<<"Natural"<<endl;
   }
  }
  else if(bfp==8||bfp==9)
  {
   delay(3000);
   cout<<"Natural"<<endl;
  }
  if(bfp>bfb)
  {
   cout<<"Player hand value > Banker hand value"<<endl;
   delay(3000);
   cout<<"                                   PLAYER HAND WINS                       "<<endl;
   delay(1500);
   if(bc==1)
    {
     delay(1000);
     textcolor(GREEN + BLINK);
     cprintf("                            CONGRATULATIONS YOU WON : ");
     cout<<bb<<" chips"<<endl;
     textcolor(WHITE);
     cout<<"New balance : "<<bn+bb<<endl;
     bn=bn+bb;
    }
    else
    {
     delay(2000);
     textcolor(RED + BLINK);
     cprintf("                                    YOU LOST                   ");cout<<endl;
     textcolor(WHITE);
     delay(1000);
     cout<<"new balance : "<<bn-bb<<endl;
     bn=bn-bb;
    }
  }
  else if(bfp<bfb)
  {
   cout<<"Banker hand value > Player hand value"<<endl;
   delay(3000);
   cout<<"                                   BANKER HAND WINS                       "<<endl;
   delay(1500);
   if(bc==2)
   {
    delay(1000);
    textcolor(GREEN + BLINK);
    cprintf("                                CONGRATULATOIONS YOU WON : ");
    cout<<bb-(5/100*bb)<<" chips"<<endl;
    textcolor(WHITE);
    cout<<endl<<"New balance : "<<bn+(bb-(5/100*bb))<<endl;
    bn=bn+(bb-(5/100*bb));
   }
   else
   {
    delay(3000);
    textcolor(RED + BLINK);
    cprintf("                                    YOU LOST                           ");cout<<endl;
    textcolor(WHITE);
    delay(3000);
    cout<<"New balance : "<<bn-bb<<endl;
    bn=bn-bb;
   }
  }
  else if(bfp==bfb)
  {
   cout<<"Player hand value = Banker hand value";
   delay(3000);
   cout<<"                                    IT'S A TIE                      "<<endl;
   delay(1500);
   if(bc==3)
   {
    delay(1000);
    textcolor(GREEN + BLINK);
    cprintf("                             CONGRATULATIONS YOU WON ");
    cout<<9*bb<<" chips"<<endl;
    textcolor(WHITE);
    cout<<endl<<"New balance : "<<bn+(9*bb)<<endl;
    bn= bn+(9*bb);
   }
   else
   {
    delay(3000);
    textcolor(RED + BLINK);
    cprintf("                                   YOU LOST                         ");cout<<endl;
    textcolor(WHITE);
    delay(3000);
    cout<<"New balance : "<<bn-bb<<endl;
    bn=bn-bb;}
   }
   cout<<"Do you want to continue playing[y/n] : ";
   cin>>bch;
   }while(bch=='y'&& bn>0);
   if(bn<0)
   bn=0;

 }
