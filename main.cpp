#include <windows.h>
#include <cstdlib>
#include <conio.h>
using namespace std;
void gotoxy( int column, int line );
struct Point{
    int x,y;
};
class CONRAN{
public:
    struct Point A[100];
    int DoDai;
    CONRAN(){
        DoDai = 3;
        A[0].x = 10; A[0].y = 10,
        A[1].x = 11; A[1].y = 10;
        A[2].x = 12; A[2].y = 10;
    }
    void Ve(){
        for (int i = 0; i < DoDai; i++){
            gotoxy(A[i].x,A[i].y);
            cout<<"X";
        }
    }
    void DiChuyen(int Huong){
        for (int i = DoDai-1; i>0;i--)
            A[i] = A[i-1];
        if (Huong==0) A[0].x = A[0].x + 1;
        if (Huong==1) A[0].y = A[0].y + 1;
        if (Huong==2) A[0].x = A[0].x - 1;
        if (Huong==3) A[0].y = A[0].y - 1;

    }
};

int main()
{
    CONRAN r;
    int Huong = 0;
    char t;

    while (1){
        if (kbhit()){
            t = getch();
            if (t=='a') Huong = 2;
            if (t=='w') Huong = 3;
            if (t=='d') Huong = 0;
            if (t=='x') Huong = 1;
        }
        system("cls");
        r.Ve();
        r.DiChuyen(Huong);
        Sleep(300);
    }

    return 0 ;
}


void gotoxy( int colum, int line )
  {
  COORD coord;
  coord.X = column;
  coord.Y = line;
  SetConsoleCursorPosition(
    GetStdHandle( STD_OUTPUT_HANDLE ),
    coord
    );
  }
// menu game;
void Menu() {
	int lc = 1;
	while (lc != 3) {
		system("cls");
		SetColor(6);
		gotoXY(40, 10);
		cout << "===============MENU===============";
		gotoXY(40, 11); cout << "|\t   1.Play                |";
		gotoXY(40, 12); cout << "|\t   2.Speed               |";
		gotoXY(40, 13); cout << "|\t   3.Quit                |";
		gotoXY(40, 14); cout << "===============MENU===============";
		gotoXY(40, 15); cout << "Nhap lua chon cua ban: ";
		cin >> lc;
		system("cls");
		if (lc == 1) {
			sl = 7;
			play(55);
		}
		else if (lc == 2) {
			gotoXY(40, 10); cout << "1.Nhanh";
			gotoXY(40, 11); cout << "2.Trung Binh";
			gotoXY(40, 12); cout << "3.Cham";
			gotoXY(40, 13); cout << endl;
			int choice = 2;
			cin >> choice;
			if (choice == 1) play(40);
			else if (choice == 2) play(70);
			else if (choice == 3) play(120);
		}
	}
}
