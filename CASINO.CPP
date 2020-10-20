#include"baccarat.cpp"
#include"jackpot.cpp"
#include"black.cpp"
#include"crash.cpp"
#include"roulette.cpp"
#include<iostream.h>
#include<fstream.h>
#include<conio.h>
#include<string.h>
#include<stdio.h>
#include<ctype.h>
#include"starting.cpp"
void main()
{
 clrscr();
 char menue[50];
 int temp=0;
 login();
 while(temp==0)
 {
  clrscr();
  cout<<"--------------------------------------------------------------------------------"<<endl;
  cout<<"             WELCOME WE HAVE TONS OF WAYS FOR YOU TO EARN MONEY                 "<<endl;
  cout<<"--------------------------------------------------------------------------------"<<endl;
  cout<<"which game would you like to play today 1)crash          "<<endl;
  cout<<"                                        2)roulette       "<<endl;
  cout<<"                                        3)blackjack      "<<endl;
  cout<<"                                        4)slot machine   "<<endl;
  cout<<"                                        5)baccarat       "<<endl;
  textcolor(RED);
  cprintf("                                        6)exit         : ");
  textcolor(WHITE);
  gets(menue);
  if((strcmpi(menue,"1")==0) || (strcmpi(menue,"crash")==0))
  {
   crash(netamu);
  }
  else if((strcmpi(menue,"2")==0) || (strcmpi(menue,"roulette")==0))
  {
   roulette(netamu);
  }
  else if((strcmpi(menue,"3")==0) || (strcmpi(menue,"blackjack")==0))
  {
   black(netamu);
  }
  else if((strcmpi(menue,"4")==0) || (strcmpi(menue,"slot machine")==0))
  {
   jackpot(netamu);
  }
  else if((strcmpi(menue,"5")==0) || (strcmpi(menue,"baccarat")==0))
  {
   baccarat(netamu);
  }
  else if((strcmpi(menue,"6")==0) || (strcmpi(menue,"exit")==0))
  {
   temp=1;
  }
  else
  cout<<"you have entered the wrong choice"<<endl;
 }
 finalupdate();
 cout<<endl<<"Your final amount of chips are : "<<netamu<<endl;
 cout<<"-------------------------------------------------------------------------------"<<endl;
 cout<<"                        THANK YOU FOR PLAYING WITH US TODAY                    "<<endl;
 cout<<"-------------------------------------------------------------------------------";
 getch();
}

