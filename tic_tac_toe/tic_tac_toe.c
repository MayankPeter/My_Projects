#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int a[3][3]={{0,0,0},{0,0,0},{0,0,0}};
int player=1;
int plotcount;
int n;

void game_layout(int);
int game_check();
int game_play(int );

int main()
{

system("clear");
printf("\n\n\n\n\n\n\t\t\t\tWelcome To Mayank's Tic-Tac-Toe.. Enjoy! :)\n");
sleep(2);
int i;
system("clear");
game_layout('X');

l2:
printf("\n\n\t\t\tPlayer 1 Choose your symbol:\n\t\t\t\t1) X\n\t\t\t\t2) O\n\t\t\t\t3)exit\n\t\t\t\tEnter your choice : ");
scanf(" %d",&n);

if(n==3)
{
printf("\n\t\t\t\tPlease come again!!\n");
return 0;
}
else if(n==1 || n==2 )
{
game_layout(11);
}
else
{
printf("\t\t\tInvalid Choice!!  Please Try Again\n");
goto l2;
}

game_play(n);

}

void game_layout(int pos)
{
system("clear");
int i,k;
int l=1,m=2,o=3;
static char ch_ar[3][3]={' ',' ',' ',' ',' ',' ',' ',' ',' '};
if(plotcount==0)
{
for(i=0;i<3;i++)
{
printf("\t\t\t \t|\t \t|\t \t\n");
printf("\t\t\t%d\t|\t%d\t|\t%d\t\n",l,m,o);
printf("\t\t\t \t|\t \t|\t \t\n");
if(i<2)
printf("\t\t  ---------------------------------------------\n");
l+=3,m+=3,o+=3;
}
}
else
{
char ch;
if(n==1)
{
if(player==1)
ch='X';
else
ch='O';
}
else
{
if(player==1)
ch = 'O';
else
ch = 'X';
}

switch(pos)
{
case 1:ch_ar[0][0]=ch;
	break;
case 2:ch_ar[0][1]=ch;
	break;
case 3:ch_ar[0][2]=ch;
	break;
case 4:ch_ar[1][0]=ch;
	break;
case 5:ch_ar[1][1]=ch;
	break;
case 6:ch_ar[1][2]=ch;
	break;
case 7:ch_ar[2][0]=ch;
	break;
case 8:ch_ar[2][1]=ch;
	break;
case 9:ch_ar[2][2]=ch;
	break;
}

l=0,m=1,o=2;
for(i=0;i<3;i++)
{
printf("\t\t\t \t|\t \t|\t \t\n");
printf("\t\t\t%c\t|\t%c\t|\t%c\t\n",ch_ar[i][l],ch_ar[i][m],ch_ar[i][o]);
printf("\t\t\t \t|\t \t|\t \t\n");
if(i<2)
printf("\t\t  ---------------------------------------------\n");
}

}
plotcount++;
}

int game_check()
{

if(a[0][0]==player && a[0][0]==a[0][1] && a[0][1]==a[0][2])
{
printf("\n\t\t\t\t Player %d Wins!!\n",player);
exit(0);
}

else if(a[0][2]==player && a[0][2]==a[1][2] && a[1][2]==a[2][2])
{
printf("\n\t\t\t\t Player %d Wins!!\n",player);
exit(0);
}

else if(a[2][0]==player && a[2][0]==a[2][1] && a[2][1]==a[2][2])
{
printf("\n\t\t\t\t Player %d Wins!!\n",player);
exit(0);
}

else if(a[0][0]==player && a[0][0]==a[1][0] && a[1][0]==a[2][0])
{
printf("\n\t\t\t\t Player %d Wins!!\n",player);
exit(0);
}

else if(a[0][1]==player && a[0][1]==a[1][1] && a[1][1]==a[2][1])
{
printf("\n\t\t\t\t Player %d Wins!!\n",player);
exit(0);
}

else if(a[1][0]==player && a[1][0]==a[1][1] && a[1][1]==a[1][2])
{
printf("\n\t\t\t\t Player %d Wins!!\n",player);
exit(0);
}

else if(a[0][0]==player && a[0][0]==a[1][1] && a[1][1]==a[2][2])
{
printf("\n\t\t\t\t Player %d Wins!!\n",player);
exit(0);
}

else if(a[0][2]==player && a[0][2]==a[1][1] && a[1][1]==a[2][0])
{
printf("\n\t\t\t\t Player %d Wins!!\n",player);
exit(0);
}

if(player==1)
player=2;
else
player=1;

static int counter=0;
if(counter<8)
{
counter++;
game_play(1);
}
}

int game_play(int c)
{
int i;
int j;
static int index = 0;
static int arr[9]={0,0,0,0,0,0,0,0,0};
int pos;

l1:

printf("\nEnter a position to play Player %d : ",player);
scanf(" %d",&pos);

arr[index++]=pos;

for(i=0;i<9;i++)
{
if((index-1)!=i)
{
if(pos==arr[i])
{
printf("\t\t\t\tPosition already used\n");
index--;
goto l1;
}
}
}


switch(pos)
{
case 1:a[0][0]=player;
	break;
case 2:a[0][1]=player;
	break;
case 3:a[0][2]=player;
	break;
case 4:a[1][0]=player;
	break;
case 5:a[1][1]=player;
	break;
case 6:a[1][2]=player;
	break;
case 7:a[2][0]=player;
	break;
case 8:a[2][1]=player;
	break;
case 9:a[2][2]=player;
	break;
default :printf("Invalid option\n");
		goto l1;
}

for(i=0;i<3;i++)
{
for(j=0;j<3;j++)
printf("%d ",a[i][j]);
printf("\n");
}

game_layout(pos);

game_check();
return 0;
}
