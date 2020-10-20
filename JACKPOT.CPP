#include<fstream.h>
#include<conio.h>
#include<string.h>
#include<dos.h>
#include<stdio.h>
#include<stdlib.h>
void jackpot(long double &j)
{
 int ch2,count=0;
 char ch1[50],play;
 long double bet,temp=j;
 do
 {
  cout<<"Would you like to 1)start playing     "<<endl;
  cout<<"                  2)go through a quick guide : ";
  gets(ch1);
  if((strcmpi(ch1,"2")==0) || (strcmpi(ch1,"guide")==0))
  {
   clrscr();
   char c;
   ifstream in("jack.txt",ios::in);
   while(in)
   {
    in.get(c);
    cout<<c;
   }
   in.close();
  }
 }while((strcmpi(ch1,"2")==0) || (strcmpi(ch1,"guide")==0));
 do
 {
  clrscr();
  cout<<"--------------------------------------------------------------------------------"<<endl;
  cout<<"                              WELCOME TO JACKPOT MACHINE                        "<<endl;
  cout<<"--------------------------------------------------------------------------------"<<endl;
  randomize();
  cout<<"Your current amount of chips are : "<<j<<endl;
  cout<<"would you like to 1)pull the lever  "<<endl;
  cout<<"                  2)quit          : ";
  cin>>ch2;
  if(ch2==1)
  {
   cout<<"Enter your bet amount : ";
   cin>>bet;
   if(bet<=j)
   {
    j=j-bet;
    clrscr();
    gotoxy(32,12);
    cout<<"Slot machine will roll in";
    delay(1000);
    clrscr();
    gotoxy(35,12);
    delay(500);
    cout<<"3";
    delay(500);
    clrscr();
    gotoxy(35,12);
    delay(500);
    cout<<" 2";
    delay(500);
    clrscr();
    gotoxy(35,12);
    delay(500);
    cout<<"1"<<endl;
    delay(500);
    clrscr();
    randomize();
    char a[6][50] = {"@","#","$","&","?","!"};
    int i,r1c1,r1c2,r1c3,r2c1,r2c2,r2c3,r3c1,r3c2,r3c3;
    for(i=0; i<100; ++i)
    {
     clrscr();
     gotoxy(35,12);
     textcolor(YELLOW);
     cprintf(a[r1c1=random(6)]);cout << "   " ;cprintf(a[r1c2=random(6)]);cout << "   ";cprintf(a[r1c3=random(6)]);cout<<endl;
     textcolor(CYAN);
     gotoxy(35,13);
     cprintf(a[r2c1=random(6)]);cout << "   " ;cprintf(a[r2c2=random(6)]);cout << "   " ;cprintf(a[r2c3=random(6)]);cout<< endl;
     textcolor(GREEN);
     gotoxy(35,14);
     cprintf(a[r3c1=random(6)]);cout << "   " ;cprintf(a[r3c2=random(6)]);cout << "   "; cprintf(a[r3c3=random(6)]);cout<< endl;
     gotoxy(44,14);
     delay(i*2);
     textcolor(WHITE);
    }
    delay(3000);
    clrscr();
    textcolor(WHITE);
    cprintf("--------------------------------------------------------------------------------");cout<<endl;
    cout<<"                              WELCOME TO SLOT MACHINE                        "<<endl;
    cout<<"--------------------------------------------------------------------------------"<<endl;
    cout<<"Your current amount of chips are : "<<temp<<endl;
    cout<<"would you like to 1)pull the lever  "<<endl;
    cout<<"                  2)quit          : "<<ch2<<endl;
    cout<<"Enter your bet amount:"<<bet<<endl;
    cout<<"Slot machine will roll in"<<endl;
    cout<<"                           SLOT MACHINE HAS STOPPED "<<endl;
    cout<<"The combinations are : "<<a[r1c1]<<" "<<a[r1c2]<<" "<<a[r1c3]<<endl
	<<"                       "<<a[r2c1]<<" "<<a[r2c2]<<" "<<a[r2c3]<<endl
	<<"                       "<<a[r3c1]<<" "<<a[r3c2]<<" "<<a[r3c3]<<endl;
    if(r1c1==r1c2 && r1c1==r1c3)
     count++;
    if(r2c1==r2c2 && r2c1==r2c3)
     count++;
    if(r3c1==r3c2 && r3c1==r3c3)
     count++;
    if(count==1)
    {
     cout<<"                    CONGRATULAIONS , YOU HAVE WON THE JACKPOT"<<endl;
     j=j+bet*5;
     cout<<"Your current amount of chips are : "<<j;
    }
    else if(count==2)
    {
     cout<<"                     CONGRATULATIONS , YOU HAVE WON THE JACKPOT"<<endl;
     j=j+bet*10;
     cout<<"Your current amount of chip are : "<<j;
    }
    else if(count==3)
    {
     cout<<"                     CONGRATULATIONS , YOU HAVE WON THE JACKPOT"<<endl;
     j=j+bet*100;
     cout<<"Your current amount of chips are : "<<j;
    }
    else if(count==0)
    {
     textcolor(RED + BLINK);
     cprintf("                            YOU HAVE LOST THE GAME");cout<<endl;
     textcolor(WHITE);
     cout<<"Your current amount of chips are : "<<j;
    }
   }
   else
   cout<<"                                YOU DON'T HAVE ENOUGH BALANCE"<<endl;
  }
  else
  break;
  cout<<endl<<"Would you like to play again[y/n] : ";
  cin>>play;
 }
 while(j>0 && play=='y');
 cout<<"                      THANK YOU FOR VISITING THE SLOT MACHINE               "<<endl;
 if(j<0)
 j=0;
}