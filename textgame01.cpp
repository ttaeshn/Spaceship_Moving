#include<stdio.h>
#include <conio.h>
#include <windows.h>

void gotoxy(short x, short y)
{ 
COORD c = { x, y };
SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE) , c); 
}

void draw_ship(short x,short y)
{  
    gotoxy(x,y);
    printf(" <-0-> ");
}
void erase_ship(short x,short y)
{
    gotoxy(x,y);
    printf("      ");
}

int main()
{
char ch = ' ';
short x = 10,y = 5;
draw_ship(x,y);

do 
{
if (_kbhit())
{
ch=_getch();
if(ch =='a') 
{
    erase_ship(x,y);
    draw_ship(--x,y);
}
if(ch =='d') 
{
    erase_ship(x,y);
    draw_ship(++x,y);
}
if(ch =='s') 
{
    erase_ship(x,y);
    draw_ship(x,++y);
} 
if(ch == 'w') 
{
    erase_ship(x,y);
    draw_ship(x,--y);
}
fflush(stdin);
}
Sleep(75);
} 
while (ch!='x');
return 0;
}