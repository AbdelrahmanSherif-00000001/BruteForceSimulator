/**************************************
forked from: Shreays KB
**************************************/
//Header files section

/*********     commented libraries are not needed
// #include<stdio.h> 
// #include<string.h>
// #include<stdlib.h>
// #include<dos.h>
// #include<ctype.h>               ***********/

#include<iostream> // cout,cin,endl
#include<conio.h> 
#include<cstdlib> //system()
#include<windows.h> //SetConsoleCursorPosition()
#include<thread> //for delay
#include<chrono>
using namespace std;

// build gotoxy() to control the position of the cursor on the screen as we can not use it directly in modern c++
void gotoxy(int x, int y){
  COORD coord; 
  coord.X = x;
  coord.Y = y;
  HANDLE h_console =  GetStdHandle(STD_OUTPUT_HANDLE);//handle the console screen buffer 
  SetConsoleCursorPosition(h_console, coord); 
}


//Global variable declaration
long int rpass=123,hpass=0,tpass=0,thpass=0,gpass=0,ghpass=0;
// r-real, t-temp, g-guess, h-hash,pass-password
char command[15];
int count=0,choice;

//function declation
void box(int x1, int y1,int x2,int y2);
void line(int x1, int y1, int x2);
void pa(void);
long int conv(long n); //for hashing

//Main section
int main()
{
  //kbhit checks whether a key has pressed without waiting for user to press enter, returns 1=>pressed  ,  0=>no key pressed 
  while(!kbhit())
  {
    system("cls");
    hpass = conv(rpass);
    gotoxy(31,7);
    cout<<"........Tool Menu........";
    box(20,5,65,23);
    line(20,9,65);
    line(20,19,65);
    gotoxy(30,11);
    cout<<"1.Administator tool";
    gotoxy(30,13);
    cout<<"2.Login page";
    gotoxy(30,15);
    cout<<"3.Start Brute force";
    gotoxy(30,17);
    cout<<"4.Exit";
    gotoxy(28,19);
    cout<<"  Please enter your choice  ";
    gotoxy(30,21);
    cin>>choice;
    switch(choice)
    {
      case 1:
      {
        system("cls");
        gotoxy(25,7);       cout<<"Enter the new password to change";
        box(20,5,65,23);
        line(20,9,65);
        box(30,13,55,16);
        gotoxy(32,14);      cout<<"Username: Admin ";
        gotoxy(32,15);      cout<<"Password:       ";
        gotoxy(42,15);      cout<<"******";
        line(20,19,65);
        gotoxy(42,15);      cin>>rpass;
        hpass = conv(rpass);
        break;
      }
      case 2:
      {
        system("cls");
        gotoxy(30,7);       cout<<"Login page";
        box(20,5,65,23);
        line(20,9,65);
        box(30,13,55,16);
        gotoxy(32,14);      cout<<"Username: Admin ";
        gotoxy(32,15);      cout<<"Password:       ";
        gotoxy(42,15);      cout<<"******";
        line(20,19,65);
        gotoxy(42,15);      cin>>tpass;
        thpass=conv(tpass);
        if(hpass!=thpass) {
           gotoxy(23,20);    cout<<"The username and password did not match!";
        }
	      else
          pa();
        this_thread::sleep_for(chrono::seconds(3));
        break;
      }
      case 3:
      {
        int k;
        gotoxy(35,20);      cout<<"Loading terminal...";
        for(k=22;k<64; k++)
        {
	        gotoxy(k,21);
          cout<<(char) 176;
        }
        for(k=22;k<64;k++)
        {
	        gotoxy(k,21);       cout<<(char)219;
	        this_thread::sleep_for(chrono::milliseconds(3));
        }
        system("cls");
        cout<<"Write brute-force to start brute force attack: ";
        cin>>command;
        if(strcmp(command,"brute-force")  == 0){
          while(true)
          {
            ghpass= conv(gpass);
            if(hpass==ghpass)
              {
                cout<<">>airtack -login - user 'Admin' - password '"<<gpass<<"' - Athentication Success.\nPassword is found as: "<<gpass<<endl;
                this_thread::sleep_for(chrono::seconds(10));     break;
              }
            else
              {
                cout<<">>airtack -login - user 'Admin' - password '"<<gpass<<"' - Access Denied "<<endl;  gpass++;
                if(count>0)
                {
                  this_thread::sleep_for(chrono::seconds(10));    count--;
                }
              } 
          }
        }break;
      }
      case 4:
        exit(0);
        break;
      default:
      {
        system("cls");
        gotoxy(25,5);
        printf("Invalid choice...!");
        getche();
        break;
      }

    }}
    getch();
}

//function to display the victim website
void pa(void)
{
     system("cls");
     cout<<"\n\nWelcome to Abdelrahman Sherif Github repo\n"<<endl;
     cout<<"A Computer Science Student, interseted in Low level | system_programming  | ML, and trying to use Arch linux :)";
     cout<<"\n\nUser\tPassword\nAdmin\t"<<hpass;
     this_thread::sleep_for(chrono::seconds(3));
}

//function to draw theboxx as dialogboxx
void box(int x1, int y1, int x2, int y2)
{
	int x;
	gotoxy(x1,y1); cout<<(char)201;   gotoxy(x2,y1); cout<<(char)187;
	gotoxy(x1,y2); cout<<(char)200;   gotoxy(x2,y2); cout<<(char)188;
	for(x=x1+1;x<x2;x++) {gotoxy(x,y1); cout<<(char)205;   gotoxy(x,y2); cout<<(char)205;}
	for(x=y1+1;x<y2;x++) {gotoxy(x1,x); cout<<(char)186;   gotoxy(x2,x); cout<<(char)186;}
}

//function to draw the linee which combine with theboxx
void line(int x1,int y1,int x2)
{
  int k;
  gotoxy(x1,y1); cout<<(char)204;  gotoxy(x2,y1); cout<<(char)185;
  for(k=x1+1;k<x2;k++) {gotoxy(k,y1); cout<<(char)205;}
}

long int conv(long n)
{
    long int rem,i=1,oct=0;
    while (n!=0)
    {
        rem = n%2;
        n=n/2;
        oct = oct+(rem*i);
        i=i*10;
    }
    return oct;
}