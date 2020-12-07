#include "pch.h"
#include "fstream"
#include "iostream"
#include "Windows.h"
#include "stdio.h"
#include "conio.h"
using namespace std;
void gotoxy(int, int);
void colour(int, int);
void multimatrix(void);
#define time(x) Sleep(x*1000)
class matric{
	private:
		int x, y, m[50][60];
	public:
		matric()
		{
			x = 0;
			y = 0;
			m[0][0] = 0;
		}
		void transp(void);
		void getmat(void);
		void deter(void);
}mat;

void matrice(){
	other:
	colour(7, 1);
	system("cls");
	gotoxy(52, 1);cout << "|choose from options|";
	cout << "\n\n 1) Transpose\n";
	cout << " 2) Equation solving\n";
	cout << " 3) Determinant\n";
	cout << " 4) Fun\n";
	cout << " 5) Multidimensional\n";
	switch (_getch()){
		case '1': mat.getmat();mat.transp(); break;
		case '2': cout << "\n Wierd flex but okay."; _getch(); break;
		case '3':mat.getmat();mat.deter();break;
		case '4': cout << "\n Am I a joke to you?";_getch(); break;
		case '5': multimatrix();
		case 'b':break;
		case 'x': exit(1);
		default: matrice();
	}
}
void matric::getmat(){
	system("cls");
	int x1, y1 = 7;
	cout << "\n First give me your matrix buddy.";
	cout << "\n number of rows?  ";cin >> y;cout << "\n columns?  ";cin >> x;
	
	cout << "\n Fill your matrix.";
	for (int R = 0;R < y;R++){
		x1 = 1;
		for (int C = 0;C < x;C++)
		{
			gotoxy(x1, y1);
			cout << "*";
			x1 += 2;
		}
		y1 += 1;

	}
	y1 = 7;
	for (int R = 0;R < y;R++){
		x1 = 1;
		for (int C = 0;C < x;C++)
		{
			gotoxy(x1, y1);
			cin >> m[R][C];
			x1 += 2;
		}
		y1 += 1;

	}
}
void matric::transp(){
	int T[50][50];int x1, y1 = 7;
	for (int R = 0;R < x;R++)
		for (int C = 0;C < y;C++)
			T[C][R]=m[R][C];
	for (int R = 0;R <y;R++){
		x1 = 1;
		for (int C = 0;C < x;C++)
		{
			gotoxy(x1, y1);
			cout<<T[R][C];
			x1 += 2;
		}
		y1 += 1;
	}_getch();
}
void matric::deter(){//sidebyside x,updown y
	if (y != x){
		cout << "\n Unfortunately, determination of determinant requires a square matrix (number of rows=columns). Sed.";_getch(); matrice();
	} else{
		int c=0, r=0;
		if(c==0){
			m[r][c] = m[r][c] * ((m[r + 1][c + 1] * m[r + 2][c + 2]) - (m[r][c + 1] * m[r + 1][c]));
			cout << " D = "<<m[r][c]; _getch();
		}
	}
}

void multimatrix() {
	system("cls");
	cout << "This is a 6-dimensional storage system.\n";
	_getch();
	int a[10][10][10][10][10][10], sum = 0;
	for (int i = 0;i < 4;i++) {
		for (int j = 0;j < 4;j++) {
			for (int k = 0;k < 4;k++) {
				for (int l = 0;l < 4;l++) {
					for (int m = 0;m < 4;m++) {
						for (int n = 0;n < 4;n++) {
							cin >> a[i][j][k][l][m][n];
							sum += a[i][j][k][l][m][n];
						}
					}
				}
			}
		}
	}
	_getch();
	cout << sum;
}