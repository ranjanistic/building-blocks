#include"pch.h"
#include"iostream"
#include"conio.h"
#include"Windows.h"
#include"fstream"
using namespace std;
void font(int);
void gotoxy(int, int);
void colour(int, int);
#define time(x) Sleep(x*1000)
void settings()
{
	system("cls");
	int fn; fstream f;char fsc = 'n', turn = 'o';
aga:colour(8, 0);
	gotoxy(112, 0);cout << " [<][-][x]";
	gotoxy(55, 0);cout << "Customize Section";
	cout << "\n\n 1) Change font size\n";
	cout << "\n 2) Feedback";
	cout << "\n 3) Full screen mode : ";
	if (fsc == 'n')
	{
		colour(12, 0);
		cout << "OFF";
		turn = 'o';
	}
	else 
	{
		colour(10, 0);
		cout << "ON ";
		turn = 'f';
	}
	char ch = _getch();
	switch (ch)
	{
	case '-': gotoxy(116, 0);colour(10, 0);cout << "[-]";gotoxy(1, 6);time(0.5);ShowWindow(GetConsoleWindow(), SW_MINIMIZE); goto aga;
	case'x':gotoxy(119, 0);colour(12, 0);cout << "[x]";time(0.5);exit(1);
	case '<':gotoxy(113, 0); colour(10, 0); cout << "[<]"; time(0.5);break;
	case '1':system("cls");f.open("fonsize.txt", ios::out);
		gotoxy(4, 2);colour(8, 0);cout << "Change font size\n";time(1.5);
		colour(10, 0);	cout << "\n Enter font size(optimal size is 24): ";
		cin >> fn;
		f << fn;
		font(fn);
		f.close();
		break;
	case '3':
		if (turn == 'o')
		{
			SendMessage(GetConsoleWindow(), WM_SYSKEYDOWN, VK_RETURN, 0x20000000); gotoxy(23, 3);
			fsc = 'y';
			goto aga;
		}
		else if(turn=='f')
		{
			SendMessage(GetConsoleWindow(), WM_SYSKEYUP, VK_RETURN, 0x20000000); gotoxy(23, 3);
			fsc = 'n';
			goto aga;
		}
	case '2': cout << "\n\n Provide every feedback at : priyanshuranjan88@gmail.com"; _getch();break;
	default: break;
	}
}