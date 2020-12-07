#include "pch.h"
#include "Windows.h"
#include "iostream"
#include "conio.h"
using namespace std;
#define time(x) Sleep(x*1000)

void gotoxy(int x, int y){
	COORD cdns;     
	cdns.X = x;     
	cdns.Y = y;     
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cdns);
}

void colour(int txtcol, int bgcol){
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (txtcol + (bgcol * 16)));
}

void font(int y){
	CONSOLE_FONT_INFOEX cfi;
	cfi.cbSize = sizeof(cfi);
	cfi.nFont = 0;
	cfi.dwFontSize.X = 0;                   
	cfi.dwFontSize.Y = y;                  
	cfi.FontFamily = FF_DONTCARE;
	cfi.FontWeight = FW_BOLD;
	wcscpy_s(cfi.FaceName, L"Consolas"); 
	SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &cfi);
}


void anima(){
	int i = 0;gotoxy(0, 0);colour(9, 0);
	while (i < 10240){
		cout << "|_";i++;
	}
	i = 0;gotoxy(0, 0);
	Sleep(200);
	while (i < 10240){
		cout << "  ";i++;
	}
	Sleep(200);
	system("cls");
}

char exile(char term){
	switch (term){
		case 'r': gotoxy(113, 0);colour(1, 0);cout << " r ";gotoxy(0, 6);time(0.1);anima();//ch = '0';goto sett;
		case 'x': gotoxy(119, 0);colour(4, 0);cout << " x ";gotoxy(1, 6);time(0.5); exit(1);
		case 'X': gotoxy(119, 0);colour(4, 0);cout << " x ";gotoxy(1, 6);time(0.5);exit(1);
		case '-': gotoxy(116, 0);colour(2, 0);cout << " _ ";gotoxy(1, 6);time(0.5);ShowWindow(GetConsoleWindow(), SW_MINIMIZE);//ch = '0'; goto sett;
	}
}
/*0 = Black 
 8 = Gray
 1 = Blue 
  2 = Green 
  3 = Aqua 
   4 = Red 
   9 = Light Blue

 A = Light Green
 
 B = Light Aqua

 C = Light Red
 5 = Purple 
 D = Light Purple
 6 = Yellow 
 E = Light Yellow
 7 = White 
 F = BringWhite*/