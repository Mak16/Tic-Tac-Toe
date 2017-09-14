//                          TIC TAC TOE

#include <iostream>
#include<conio.h> // to use the gotoxy() function
#include<time.h>        // to use the delay() function
#include<conio.h>
#include<windows.h>   // to use the getch() function
#define WIN 1           // define macro WIN having value 1
#define LOOSE 0         // define macro LOOSE having value 0


using namespace std;

struct Player          // create structure named player which contains basic info of player
{
    int pos;           // stores the position of sign from player
    char name[20];     // stores the name of the player
    int check;          // this stores the int value to check if player win the match
};

// this function takes two arguments as coordinates and shift the cursor depend on the argument passed on the console screen

void gotoxy(int x,int y)
{
    COORD c;
    c.X=x;
    c.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),c);
}

// this function takes one argument as time in micro seconds to delay for that time

void delay(unsigned int t)
{
    clock_t goal =t + clock();
    while(goal>clock());
}

// this function will clear the screen and print background

void background()
{
    system("cls");
    gotoxy(25,1);cout<<"TIC TAC TOE";
    delay(200);
     delay(200);
    gotoxy(60,3);cout<<"- BY MAHI "<<char(1);
}

// this function shows the table of tic tac toe

void show_table(char* c)
{
    int k=0;
    for(int i=5;i<=15;i=i+5)
    {
        for(int j=25;j<=35;j=j+5)
        {
            gotoxy(j,i);cout<<*(c+k);
            k++;
        }
    }
}

// the welcome screen is defined here

void welcome();

// this function will check if the position entered by the player is occupied or not
// if occupied return 0 else return 1

int check_occupied(Player* p,int a[])
{
   if( a[p->pos-1] == 1)
   {
       return 0;
   }
   else
    {
        return 1;
    }
}

// this will gets the position from player

void get_pos(Player* p)
{
    gotoxy(2,4);cout<<"Enter the position : ";
    cin>>p->pos;
}

// this will gets the position from player 1 and assign the value in char array

void get_pos_pl1(Player* p,char* c,int a[])
{
    background();
    gotoxy(25,3);cout<<p->name;
    get_pos(p);
     if(check_occupied(p,a)==1 && p->pos>=1 && p->pos<=9 )
    {
        a[(p->pos)-1]=1;
        *(c+(p->pos-1))='X';
    }
    else
    {
        gotoxy(2,6);cout<<"Invalid Position ! Enter different position . ";
        getch();
        get_pos_pl1(p,c,a);
    }
}

// this will gets the position from player 2 and assign the value in char array

void get_pos_pl2(Player* p,char* c,int a[])
{
    background();
    gotoxy(25,3);cout<<p->name;
    get_pos(p);
     if(check_occupied(p,a)==1 && p->pos>=1 && p->pos<=9 )
    {
        a[p->pos-1]=1;
        *(c+p->pos-1)='O';
    }
    else
    {
        gotoxy(2,6);cout<<"Invalid Position ! Enter different position . ";
        getch();
        get_pos_pl2(p,c,a);
    }
}

// this function will check if the player won the match or not

int check_won(char* c)
{
     if(( *(c+0)==*(c+4) && *(c+4)==*(c+8) ) ||( *(c+2)==*(c+4) && *(c+4)==*(c+6) ) ||( *(c+0)==*(c+3) && *(c+3)==*(c+6) ) ||( *(c+1)==*(c+4) && *(c+4)==*(c+7) ) ||( *(c+2)==*(c+5) && *(c+5)==*(c+8) ) ||( *(c+0)==*(c+1) && *(c+1)==*(c+2) ) ||( *(c+3)==*(c+4) && *(c+4)==*(c+5) ) ||( *(c+6)==*(c+7) && *(c+7)==*(c+8) ) )
        return WIN;
    else
        return LOOSE;
}

// this function will plays the game

void play(Player* p1,Player* p2,char* c,int a[])
{
     background();delay(200);
        int i=0;

     gotoxy(3,3);cout<<"Enter the name of the player ~";
    gotoxy(3,7);cout<<"Player 1 ( X ) : ";   // player 1 name
    cin>>p1->name;
    gotoxy(3,9);cout<<"Player 2 ( O ) : ";   // player 2 name
    cin>>p2->name;
    delay(100);

    background();
    show_table(c);                // show table
    getch();
    while(1)
    {
        background();

        if(i%2==0)                // player 1 chance
            {
                get_pos_pl1(p1,c,a);
                if(check_won(c)==WIN)   // check if player 1 won the match
                {
                    p1->check=WIN;
                    break;
                }
                 show_table(c);
                 getch();
                i++;
            }
        else                        // player 2 chance
            {
                if(i<9)
                 {
                    get_pos_pl2(p2,c,a);
                    if(check_won(c)==WIN)  // check if player 2 won the match
                        {
                        p2->check=WIN;
                        break;
                        }
                 }
                else
                    break;

                show_table(c);
                getch();
                i++;
            }
    }
}

// this function will print the instructions of the game

void instructions()
{
    background();
    gotoxy(2,4);cout<<"HOW IT WORKS !!! \n\n\n";
    cout<<char(175)<<" Check the player name .\n"<<char(175)<<" Then enter the position of the marks you want to choose .";
    getch();
    welcome();
}

// this is the welcome screen of the game

void welcome()
{
    system("cls");

    int a[9]={0};                                       // int array to check the pos is occupied or not
    char c[9] = {'1','2','3','4','5','6','7','8','9'};
    int choice=0;
    Player player_1,player_2;
    Player *p1,*p2;
    p1 = &player_1;
    p2 = &player_2;

    p1->check=LOOSE;
    strcpy(p1->name,"XXX");
    p1->pos=-1;

    p2->check=LOOSE;
    strcpy(p2->name,"OOO");
    p2->pos=-1;

    background();

    gotoxy(3,5);cout<<"1) Play ";
    gotoxy(3,7);cout<<"2) Instructions ";
    gotoxy(3,9);cout<<"3) Quit ";
    gotoxy(3,12);cin>>choice;
    switch(choice)
    {
        case 1: play(p1,p2,c,a);
        break;

        case 2:instructions();
        break;

        case 3:gotoxy(10,20);cout<<"THANK U "<<char(1)<<"\n\n\n";
            exit(0);
        break;

        default: gotoxy(5,14);cout<<"INVALID OPTION !!! ";
        delay(300);
        welcome();
        break;
    }

    if(player_1.check==WIN)
    {
        gotoxy(5,5);cout<<"player 1 wins ! "<<char(15);
        show_table(c);
        getch();
    }
    else if(player_2.check==WIN)
    {
        gotoxy(5,5);cout<<"player 2 wins ! "<<char(15);
        show_table(c);
        getch();
    }
    else
    {
        gotoxy(5,5);cout<<"Draw Match !!! "<<char(1);
        show_table(c);
        getch();
    }

    welcome();
}

int main()       // main function
{
    welcome();

    return 0;
}
