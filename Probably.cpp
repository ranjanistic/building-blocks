#include "pch.h"
#include"iostream"
#include"fstream"
#include"string.h"
#include"Windows.h"
#include"conio.h"
#include"cwchar"
template<typename T>
constexpr auto time(T x){
	return Sleep(x * 1000);
}
using namespace std;
class recarrsug{
public:
	int n; float ar[90];
	void recorder(void);

	recarrsug(){
		n = 0;
		ar[0] = 0.0;
		ar[1] = 0.0;
		ar[2] = 0.0;
	}
}obj;

void anima(void);
void arrange(int&, float[]);
void matrice(void);
void gotoxy(int, int);
void colour(int, int);
void font(int);
void settings(void);

void recarrsug::recorder(){
	int  g = 0, i = 0;
	cout << "\n Enter the amount of data you want to be recorded.";Sleep(800);cout << "\a(The more this number, the better the future): ";
	cin >> n;
	cout << "\n Enter here the data " << n << " times.";
	while (g < n){
		if (g > 0){
			cout << "\n Enter again: ";
			cin >> ar[g];
		}
		else{
			cout << "\n Enter: ";
			cin >> ar[g];
		}
		if (n % 2 == 0){
			if (g == (n / 2))
				cout << "\n\a Just there.Keep entering.\n";
		}
		else if (n % 2 != 0){
			if (g == ((n + 1) / 2))
				cout << "\n\a Almost there.Keep entering.";
		}
		g++;
		if (g == 1)cout << "\a (Repetition is allowed)\n";
	}
	cout << "I have stored both 'n' and 'ar[]' now. cheers! 5 sec wait."; time(5);
}

char agan = 'n';
void arrange(int &nn, float arr[])
{
	float count[50], eve[90], prob[90];
	int pos[50], v = 0;
	int num = 0, max = 0, opt = 0;
	int b = 0, m = 0;
	float larg[90], tem = 0, temp = 0;
	char con = 'y';

	for (int x = 0;x < nn;x++){
		for (int y = 0;y < x;y++){
			if (arr[y] > arr[y+1]){
				temp = arr[y];
				arr[y] = arr[y+1];
				arr[y+1] = temp;
			}
		}
	}
	cout << "\n Arranged in ascending: ";
	for (int x = 0;x < nn;x++)
		cout << arr[x]<<" ";

	count[0] = 1;
	for (int k = 0;k < nn;k++)
	{
		if (arr[k] == arr[k + 1])
			count[m]++;
		else
		{
			if (v == 0)						//distinct event counter 'v'
			{
				eve[v] = arr[k];
				eve[v + 1] = arr[k + 1];
				v += 2;
			}
			else if (v != 0 && arr[k] == eve[v - 1])
			{
				eve[v] = arr[k + 1];
				v++;
			}
			else
			{
				eve[v] = arr[k];
				eve[v + 1] = arr[k + 1];
			}
			m++;
			count[m] = 1;
		}
	}
	cout << "\n\n The frequency distribution is following-\n\n Events: ";
	for (int s = 1;s < v;s++)
	{
		cout << eve[s] << " ";
	}
	cout << "\n Frqncy: ";
	for (int d = 1;d < v;d++)
	{
		cout << count[d] << " ";
	}
	cout << "\n Prblty: ";
	for (int h = 1;h < v;h++)
	{
		prob[h] = (count[h] / nn);
		cout << prob[h] << " ";
	}

	for (int x = 1;x < v;x++)
		eve[x - 1] = eve[x];
	for (int y = 1;y < v;y++)
		count[y - 1] = count[y];
	for (int z = 1;z < v;z++)
		prob[z - 1] = prob[z];
	cout << "v:" << v;
	int nnn = v - 1;
	for (int j = 0;j < nnn;j++)
		larg[j] = prob[j];
	for (int q = 0;q < nnn;q++)
	{
		for (int w = 0;w < nnn;w++)
			if (larg[w] < larg[w + 1])
			{
				tem = larg[w];
				larg[w] = larg[w + 1];
				larg[w + 1] = tem;
			}
	}

	for (int d = 0;d < nnn;d++)
	{
		for (int s = 0;s < nnn;s++)
			if (larg[d] == prob[s])
			{
				pos[b] = s;
				b++;
			}
	}
	cout << "Event:";
	for (int c = 0;c < nnn;c++)
		cout << " " << eve[c];cout << "\n";
	cout << "probab:";
	for (int c1 = 0;c1 < nnn;c1++)
		cout << " " << prob[c1];cout << "\n";
	cout << "desc probab:";
	for (int c2 = 0;c2 < nnn;c2++)
		cout << " " << larg[c2];cout << "\n";
	cout << "equal pos:";
	for (int c3 = 0;c3 < b;c3++)
		cout << " " << pos[c3];cout << "\n";
	if (agan != 'y')
	{
		cout << "\n in predict();";
		cout << "\n\n\a  Hey! Welcoming you to the intellisense predicting space."; time(2);
		cout << "\a So now I'm going to ask you whether your next number is this or not."; time(2);
		cout << "\n\n\a  Are";time(1);cout << "\a you";time(1);cout << "\a ready?";time(1);
		cout << "\n\n\a Type the number you would like, and if it is same as I predicted, then BINGO!.";time(2);
	}
	else if (agan == 'y')
	{
		do
		{
			cout << "\n  Is your next number " << eve[pos[max]] << "? ";
			cin >> opt;
			if (opt == eve[pos[max]])
			{
				cout << "\n\n\a  See, how smart I am.B-)\n";
				obj.ar[nn] = opt;
				nn++;
				obj.n = nn;
				agan = 'y';
				arrange(obj.n, obj.ar);
			}
			else if (opt != eve[pos[max]])
			{
				cout << "\n\n  Apologies. Will try better next time.:'("; time(2);
				cout << " Sed lyf.\n";
				obj.ar[nn] = opt;
				nn++;
				obj.n = nn;
				agan = 'y';
				arrange(obj.n, obj.ar);
			}
			max++;
			cout << "Shall we continue? ";
			con = _getch();
		} while (con == 'y');
	}
	cout << "Value of n after all this hell is: " << nn;
	cout << "\n value of ar[] :";
	for (int x = 0;x < nn;x++)
		cout << obj.ar[x] << " ";_getch();
}
void testing(void);

void testing() {
	int A[50], A_size, box;
	cout << "Size of array: ";
	cin >> A_size;
	cout << "\nThe array values.\n";
	for (int a = 0; a < A_size; a++) {
		cout << "Enter for pos " << a << ":";
		cin >> A[a];
	}
	cout << "\nCopy: ";
	for (int b = 0;b < A_size;b++) {
		cout << A[b] << "|";
	}
	cout << "\nPress enter to ascend.";_getch();
	for (int c = 0; c < A_size; c++) {
		for (int c1 = 0; c1 < c; c1++) {
			if (A[c1] > A[c]) {
				box = A[c1];
				A[c1] = A[c];
				A[c] = box;
			}
		}
	}
	cout << "\nAscended: ";
	for (int d = 0; d < A_size; d++) {
		cout << A[d] << "|";
	}
	cout << "\nPAK for individual items.";_getch();
	int B[50], B_size =0;
	/*for (int e = 0,f=0; e < A_size;e++) {
		for (int e1 = 1; e1 < A_size; e1++) {
			if (A[e1] == A[e]) {
				B[f] = A[e];
				f++;
			}
			else if (A[e1] != A[e]) {
				B[f] = A[e];
				B[f + 1] = A[e1];
				f += 2;
			}
		}
		B_size = f;
	}*/



	int m = 0, count[50], v =0;
		count[0] = 1;
	for (int k = 0;k < A_size;k++)
	{
		if (k == (A_size - 1)) {
			if (A[k] != A[k - 1]) {
				B[v] = A[k]; cout << B[v];
				v++;
				m++;cout << v << m;
				count[m] = 1; cout << count[m];
			}
			else count[m]++;
			
		}
		else if (A[k] == A[k + 1])
		{
			count[m]++; cout << count[m];
		}
		else
		{
			if (v == 0)						//distinct event counter 'v'
			{
				B[v] = A[k]; cout << B[v];
				B[v + 1] = A[k + 1]; cout << B[v + 1];
				v += 2; cout << v;
				
			}
			else if (v != 0 && A[k] == B[v - 1])
			{
				B[v] = A[k + 1]; cout << B[v];
				v++; cout << v;
			}
			else
			{
				B[v] = A[k]; cout << B[v];
				B[v + 1] = A[k + 1]; cout << B[v + 1];
			}
			m++; cout << m;
			count[m] = 1; cout << count[m];
		}
	}
	limitexceeded:
	cout << "individuals: v="<<v;
	for (int g = 0; g < B_size; g++) {
		cout << B[g] << "|";
	}

	_getch();
	exit(0);
}





int main()
{
	system("mode con COLS=700");
	ShowWindow(GetConsoleWindow(), SW_MAXIMIZE);char set = 'n', pro = 'n', ch = '0';

	int p = 0; 
	fstream fcout;
	int fn = 0;
	char momrec = 'n', filex = 'y', guess = 'n';
	ifstream fs;
	fs.open("fonsize.txt", ios::in | ios::_Nocreate);
	fs >> fn;
	if (fn)
		font(fn);
	fs.close();anima();
sett:
	system("cls");char conch;
	gotoxy(113, 0);colour(9, 0);cout << "[r]";colour(10, 0);cout << "[-]";colour(12, 0);cout<<"[x]";
	gotoxy(52, 1);cout << "|Choose what you want|";
	cout << "\n\n 1) Prediction using probability";
	cout << "\n 2) Matrix operations\n ";
	cout << "3) Settings\n";
	cout << "4) Testing\n";
	if (ch == '0')
	{
		ch = _getch();goto chag;
	}
	else 
	{ chag:
		switch (ch)
		{
		case '4': testing();break;
		case 'r': gotoxy(113, 0);colour(1, 0);cout << " r ";gotoxy(0, 6);time(0.1);anima();ch = '0';goto sett;
		case 'x': gotoxy(119, 0);colour(4, 0);cout << " x ";gotoxy(1, 6);time(0.5); exit(1);
		case 'X': gotoxy(119, 0);colour(4, 0);cout << " x ";gotoxy(1, 6);time(0.5);exit(1);
		case '-': gotoxy(116, 0);colour(2, 0);cout << " _ ";gotoxy(1, 6);time(0.5);ShowWindow(GetConsoleWindow(), SW_MINIMIZE);ch ='0' ; goto sett;
		case '3':
			gotoxy(1, 5); colour(10, 0); cout << " > Settings <";
			conch = _getch();
			switch (conch)
			{
			case '3':
				gotoxy(1, 5); colour(8, 0); cout << "\a   Settings";
				time(1); settings();
				main();
			case '2':
				ch = '2';goto sett;
			case '1':
				ch = '1';goto sett;
			case 'x': ch = 'x';goto sett;
			case 'X':ch = 'x';goto sett;
			case 'r':ch = 'r';goto sett;
			case '-': gotoxy(116, 0);colour(10, 0);cout << "[-]";gotoxy(1, 6);time(0.5);ShowWindow(GetConsoleWindow(), SW_MINIMIZE);ch = '0'; goto sett;
			default: ch = '0';goto sett;
			}
		case '2':
			gotoxy(1, 4);colour(10, 0);cout << " > Matrix operations <";
			conch = _getch();
			switch (conch)
			{
			case '2':gotoxy(1, 4);colour(8, 0);cout << "\a   Matrix operations";
				time(1); matrice();goto sett;
			case '3':ch = '3';goto sett;
			case '1':ch = '1';goto sett;
			case 'x': ch = 'x';goto sett;
			case 'X':ch = 'x';goto sett;
			case 'r':ch = 'r';goto sett;
			case '-': gotoxy(116, 0);colour(10, 0);cout << "[-]";gotoxy(1, 6);time(0.5);ShowWindow(GetConsoleWindow(), SW_MINIMIZE);ch = '0'; goto sett;
			default: ch = '0';goto sett;
			}
		case '1':
			gotoxy(1, 3);colour(10, 0);cout << " > Prediction using probability <";
			conch = _getch();
			switch (conch)
			{
			case '1':	gotoxy(1, 3);colour(8, 0);cout << "\a   Prediction using probability";
				time(1);

				system("cls");
				fcout.open("numdata.txt", ios::_Nocreate);
				char prev;colour(9, 0);
				cout << "\n\a Wanna start with previous data?\n ";
				cin >> prev;

				if (prev == 'n')
				{
					if (!fcout.is_open())							//if doesnt file exists
					{
						cout << "\n What a coincidence! No previous records found. Wanna add data this moment? ";
						cin >> momrec;
						if (momrec == 'n')
						{
							filex = 'n';
							goto sugg;
						}
						else if (momrec == 'y')
						{
							fcout.open("numdata.txt");
							obj.recorder();
							fcout << obj.n;
							for (int x = 0;x < obj.n;x++)
								fcout << obj.ar[x];
						}
					}
					else if (fcout.is_open())						//if file already exists
					{
						fcout.close();
						if (remove("numdata.txt") == 0)
						{
							cout << "Farewell to the previous data has been given. Sed.";
							filex = 'n';
						}
						else
						{
							cout << "Oops! Seems like previous data doesn't wanna leave us.";
							filex = 'y';
						}
						if (filex == 'n')
						{
							ofstream fcoutn;
							fcoutn.open("numdata.txt", ios::out);
							cout << "\n Do you want to add more data this moment? ";
							cin >> momrec;
							if (momrec == 'n')
							{
								fcoutn.close();
								goto sugg;
							}
							else if (momrec == 'y')
							{
								filex = 'y';
								obj.recorder();
								fcoutn << obj.n;
								for (int x = 0;x < obj.n;x++)
									fcoutn << obj.ar[x];
							}
						}
						else
						{
							cout << "Unable to remove previous records. Sed.";
							time(3);
							fcout.close();
							goto sett;
						}
					}
				}
				else if (prev == 'y')
				{
					if (!fcout.is_open())
					{
						cout << "\n Unfortunately, no previous data found. Wanna create new one this moment? ";
						cin >> momrec;
						if (momrec == 'n')
						{
							filex = 'n';
							goto sugg;
						}
						else if (momrec == 'y')
						{
							fcout.open("numdata.txt");
							obj.recorder();
							fcout << obj.n;
							for (int x = 0;x < obj.n;x++)
								fcout << obj.ar[x];
						}
					}
					else if (fcout.is_open())
					{
						cout << "\n Retriving your previous recorded data.\n ";
						filex = 'y';
						goto sugg;
					}
				}
			sugg:
				fcout.close();
				cout << "\n Wanna let me guess right now (parallel recording of responses will also go on)? \n ";
				cin >> guess;
				if (guess == 'y')
				{
					if (filex == 'y')
					{
						fstream fio;
						fio.open("numdata.txt", ios::_Nocreate);
						fio >> obj.n;
						for (int x = 0;x < obj.n;x++)
							fio >> obj.ar[x];
						/*cout << "\n Value of n is: " << obj.n;
						cout << "\n Value of ar[]:";
						for (int x = 0;x < obj.n;x++)
							cout << obj.ar[x]<<" ";
						_getch();*/
						arrange(obj.n, obj.ar);
						fio << obj.n;
						for (int x = 0;x < obj.n;x++)
							fio << obj.ar[x];
						fio.close();
					}
					else if (filex == 'n')
					{
						cout << "\n File isn't there, so I am creating a new one.";
						fstream fion;
						fion.open("numdata.txt", ios::out);
						cout << "\n Value of n is: " << obj.n;
						cout << "\n Value of ar[]:";
						for (int x = 0;x < obj.n;x++)
							cout << obj.ar[x] << " ";
						_getch();
						arrange(obj.n, obj.ar);
						fion << obj.n;
						for (int x = 0;x < obj.n;x++)
							fion << obj.ar[x];
						fion.close();
					}
				}
				else if (guess == 'n')
				{
					cout << "\n Then see you later.";time(2);cout << " By!";_getch();
					int q = 5;
					while (q >= 0)
					{
						system("cls");
						gotoxy(70, 10);cout << "\a Self destruct in T-" << q << " secs.";time(1);
						q--;
					}
				}

			case '2':	ch = '2';goto sett;
			case '3':  ch = '3';goto sett;
			case 'x': ch = 'x';goto sett;
			case 'X':ch = 'x';goto sett;
			case 'r':ch = 'r';goto sett;
			case '-': gotoxy(116, 0);colour(10, 0);cout << "[-]";gotoxy(1, 6);time(0.5);ShowWindow(GetConsoleWindow(), SW_MINIMIZE);ch = '0'; goto sett;
			default: ch = '0';goto sett;
			}
		default: ch = '0'; goto sett;
		}
	}
	cout << "\n So you had fun here! Please visit again! Stay safe, stay tuned.";time(3);
	gotoxy(81, 11);cout << " BOOM!";
	return(0);
}


// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu
// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file


// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file