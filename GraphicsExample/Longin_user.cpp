#include"Longin_user.h"
#include<iostream>
#include"HOMEPAGE_UI.h"
#include<stdlib.h>
#include<fstream>
#include<Windows.h>
#include<ctime>
using namespace std;


#define WIDTH 1520
#define HEIGHT 850
void firework(int maxx);
void Input(char* str, char* oldStr, int x, int y, char start_char, char end_char, int left, int top, int right, int bottom);
void menu_main() 
{
	
	
	int exit = 0; 
	initwindow(WIDTH, HEIGHT, "CHUONG TRINH QUAN LI PHONG TRO");
	; cleardevice();
	
	setbkcolor(green);
	setfillstyle(8, LIGHTCYAN);
	bar(0, 0, 1520, 820);
	setfillstyle(6, WHITE);
	rectangle(6, 5, 1500, 820);
	;setbkcolor(RED);
	setcolor(WHITE); settextjustify(1, 1); settextstyle(9, 0, 2);
	outtextxy(WIDTH / 3+160, HEIGHT / 3+5, "CHAO MUNG BAN DEN VOI CHUONG TRINH QUAN LI PHONG TRO");
	setbkcolor(BLUE);
	outtextxy(700, 50, "HOC VIEN CONG NGHE BUU CHINH VIEN THONG CO SO TP.HCM"); outtextxy(620+100,100, "DO AN:DATA&ALGORITHM");
	firework(60);
	
	outtextxy(650, 580, "^-^....................LOADING...............-^-");
	
	for (int i = 100; i <= 1000; i++) {
		setbkcolor(red);
		setfillstyle(2, 3);
		rectangle(100+i, 600, 900 , 630);
		
		delay(1);
	}
	
	rectangle(120, HEIGHT / 3 - 20, 1350 - WIDTH / 3 + 200+200, HEIGHT / 3 + 20);
	setbkcolor(BLUE); settextjustify(1, 1);
	outtextxy(260, HEIGHT / 3 + 50, "TEN DANG NHAP");
	cout << textwidth("MAT KHAU           ");
	line(395, HEIGHT / 3 + 50, 1100, HEIGHT / 3 + 50);
	outtextxy(260, HEIGHT / 3 + 100, "MAT KHAU           "); 
	line(395, HEIGHT / 3 + 100, 1100, HEIGHT / 3 + 100);
	
	setbkcolor(GREEN); setcolor(RED);
	outtextxy(700, HEIGHT / 3 + 100 + 50, "DANG NHAP");
	setfillstyle(1, red);
	bar(610, 460, 790, 490);
	setcolor(YELLOW);
	rectangle(610, 460, 790, 490); setbkcolor(red); setcolor(WHITE);
	outtextxy(700, 480, "EXIT");
	while (!exit) {
		int x, y;
		if (ismouseclick(WM_MOUSEMOVE)) {
			getmouseclick(WM_MOUSEMOVE, x, y);
			if ((x >= 140 && x <= 260 + 245) && (y >= HEIGHT / 3 && y <= HEIGHT / 3 + 50 + 21)) {
				setbkcolor(RED); settextjustify(1, 1); setcolor(WHITE);
				
				line(395, HEIGHT / 3 + 50, 1100, HEIGHT / 3 + 50);
				outtextxy(260, HEIGHT / 3 + 50, "TEN DANG NHAP");
			}
			else
				if ((x >= 140 && x <= 260 + 251) && (y >= HEIGHT / 3 + 80 && y <= HEIGHT / 3 + 100 + 21)) {
					setbkcolor(BLACK); settextjustify(1, 1);
					
					line(395, HEIGHT / 3 +100, 1100, HEIGHT / 3 + 100);
					outtextxy(260, HEIGHT / 3 + 100, "MAT KHAU           ");
				}
				else if ((x >= 600 && x <= 650 + 120) && (HEIGHT / 3 + 100 + 50 && y <= HEIGHT / 3 + 100 + 50 + 20)) {
					setbkcolor(YELLOW); setcolor(BLACK);
					outtextxy(700, HEIGHT / 3 + 100 + 50, "DANG NHAP");

				}
				

				else {
					setbkcolor(BLUE); settextjustify(1, 1);
					outtextxy(260, HEIGHT / 3 + 50, "TEN DANG NHAP");
					line(395, HEIGHT / 3 + 50, 1100, HEIGHT / 3 + 50);
					outtextxy(260, HEIGHT / 3 + 100, "MAT KHAU           ");
					line(395, HEIGHT / 3 + 100, 1100, HEIGHT / 3 + 100);
					setbkcolor(GREEN); setcolor(WHITE);
					outtextxy(700, HEIGHT / 3 + 100 + 50, "DANG NHAP");

				}
		}
		if (ismouseclick(WM_LBUTTONDOWN))
		{
			getmouseclick(WM_LBUTTONDOWN, x, y);

			if ((x >= 140 && x <= 260 + 245) && (y >= HEIGHT / 3 && y <= HEIGHT / 3 + 50 + 21)) {
				setbkcolor(green);
				setfillstyle(8, LIGHTCYAN);
				bar(395, HEIGHT / 3 + 25, 1100, HEIGHT / 3 + 50);


				ofstream fo; fo.open("try1.txt", ios::out);
				
				Beep(600, 200);
				setbkcolor(WHITE); setcolor(RED);
				char s[50], s1[50] = " ";
				Input(s, s1, 600, HEIGHT / 3 + 48, '0', '9', 10, 0, 0, 0); strcpy(s1, s); fo << s;
				
				
			}
			else if ((x>=610&&x<=790)&&(y>=460&&y<=490)) {
				exit = 1;
			}
			else if ((x >= 140 && x <= 260 + 251) && (y >= HEIGHT / 3 + 80 && y <= HEIGHT / 3 + 100 + 21))
			{
				setbkcolor(green);
				setfillstyle(8, LIGHTCYAN);
				bar(395, HEIGHT / 3 + 60, 1100, HEIGHT / 3 + 110); line(395, HEIGHT / 3 + 100, 1100, HEIGHT / 3 + 100);
				Beep(600, 200);
				ofstream fo; fo.open("try1.txt", ios::out | ios::app);
				setbkcolor(WHITE); setcolor(RED);
				char s1[50], k[50] = " ";
				Input(s1, k, 600, HEIGHT / 3 + 90, '0', '9', 10, 0, 0, 0); strcpy(k, s1); fo << s1;
				
			}
			else if ((x >= 600 && x <= 650 + 80) && (HEIGHT / 3 + 100 + 50 && y <= HEIGHT / 3 + 100 + 50 + 20))
			{
				ifstream fo; fo.open("try1.txt", ios::in);
				int n,m;
				fo >> m; fo >> n; fo.close();
				int x1, y1;
				ifstream fk; fk.open("user_password.txt", ios::in);
				fk >> x1; fk.seekg(1, 1); fk >> y1; fk.close();
				 if ((m == x1) && (n == y1))
				 {
					 Beep(600, 200);
					 cleardevice();
					 setbkcolor(WHITE);
					 rectangle(6, 5, 20, 20);
					 while (1) {
						 
						 HomePageUIShow();
					 }
					
				 }
				 else
					
					if((m !=x1)&& (n != y1)) outtextxy(700, 520, "SAI MAT KHAU VA TEN DANG NHAP");
					else  if (m != x1)

					 outtextxy(700,520, "SAI TEN DANG NHAP");
				 else if (n != y1)
					 outtextxy(700, 520, "SAI MAT KHAU");
					 
				 
			}
				
		}

	}

}
void Input(char* str, char* oldStr, int x, int y, char start_char, char end_char, int left, int top, int right, int bottom)
{



	char tmpStr[50];
	strcpy(tmpStr, oldStr);

	int pos = strlen(tmpStr);

	bool inpFlag = true;

	while (inpFlag) 
	{

		
		while (!kbhit()) {
			int mouse_x, mouse_y;
			if (ismouseclick(WM_MOUSEMOVE)) {
				getmouseclick(WM_MOUSEMOVE, mouse_x, mouse_y);
				if (!(mouse_x >= left && mouse_x <= right && mouse_y >= top && mouse_y <= bottom)) {
					tmpStr[pos] = 0;
					inpFlag = false;
					break;
				}
			}
		}
		if (inpFlag == false) {
			break;
		}
		
			char c = getch();
			if (c == 13) break;
		switch ((int)c) {
		case 8:
			if (pos > 0) {
				tmpStr[--pos] = 0;
			}
			break;
			
		default:
			if (pos < 50 - 1 && c >= start_char && c <= end_char)
			{
				tmpStr[pos] = c;
				pos++;
				tmpStr[pos] = 0;
			}

		}

		strcat(tmpStr, (char*)" ");
		char tmpShow[50];
		strcpy(tmpShow, tmpStr);
		strcat(tmpShow, (char*)"      ");
		outtextxy(x, y, tmpShow);


	};
	if (strlen(tmpStr) != 0) {
		strcpy(str, tmpStr);
		
	}
	else {
		strcpy(str, "");
	}

}
void firework(int maxx)
{
	int x, y, color, i;
	while (!kbhit()) {
		x = maxx / 2 - rand()%40 + 20;
		y = rand() % 270 + 50; color = rand() % 7 + 9;
		for (i = 0; i < 120; i++)
		{
			
			putpixel(x + i, y + rand() % 4 + 10, color);
			putpixel(x + i, y - i / 3 + rand() % 4 + 10, color);
			putpixel(x + i / 2, y - i / 2 + rand() % 4 + 10, color);
			putpixel(x + i / 2, y + i / 2 + rand() % 4 + 10, color);
			putpixel(x + i, y + i / 4 + rand() % 4 + 10, color);
			setbkcolor(RED);
			outtextxy(650, 540, "NHAN PHIM BAT KI DE TIEP TUC");
			delay(1);
		}
		
		x = x - 160; y = rand() % 270 + 50;
	}
	setbkcolor(green);
	setfillstyle(8, LIGHTCYAN);
	bar(0, 500, 1520, 820);
}