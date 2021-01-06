#include"doimatkhau.h"


void love_2()
{
	int x = 500, y = 400, x1 = 510, yy =400, ll=0;
	setcolor(red);
	int iloveyou[22] = { x,y,x + 22,y - 15,x + 44,y - 27,x + 88,y - 12,x + 102,y,x + 117,y + 22,x + 125,y + 44,x + 125,y + 47,x + 120,y + 66,x + 105,y + 88,x,y + 220 };
	int iloveyou2[22] = { x1,yy,x1 - 22,yy - 15,x1 - 44,yy - 27,x1 - 88,yy - 12,x1 - 102,yy,x1 - 117,yy + 22,x1 - 125,yy + 44,x1 - 125,yy + 47,x1 - 120,yy + 66,x1 - 105,yy + 88,x1,yy + 220 };
	setcolor(blue_d); setfillstyle(1, 0);
	fillpoly(11, iloveyou);
	fillpoly(11, iloveyou2);
	if (ll == 0) { x++; x1--; }
	else if (ll == 1) { x--; x1++; }
	int ily[22] = { x,y,x + 22,y - 15,x + 44,y - 27,x + 88,y - 12,x + 102,y,x + 117,y + 22,x + 125,y + 44,x + 125,y + 47,x + 120,y + 66,x + 105,y + 88,x,y + 220 };
	int ily2[22] = { x1,yy,x1 - 22,yy - 15,x1 - 44,yy - 27,x1 - 88,yy - 12,x1 - 102,yy,x1 - 117,yy + 22,x1 - 125,yy + 44,x1 - 125,yy + 47,x1 - 120,yy + 66,x1 - 105,yy + 88,x1,yy + 220 };
	if (x == 440) { setcolor(green); setfillstyle(1, 15); }
	else { setcolor(12); setfillstyle(1, 12); }
	fillpoly(11, ily);
	fillpoly(11, ily2);
	settextstyle(9, 0, 4); setcolor(yellow); setbkcolor(red);
	outtextxy(500, 470, "THANKS!");
	
}
void menu_doipass() {
	
	setfillstyle(1, red);
	setcolor(yellow); rectangle(150, 100, 450, 150);
	bar(150, 100, 450, 150);
	love_2();
	setcolor(WHITE); setbkcolor(red); settextjustify(0, 1);
	settextstyle(9, 0, 4); outtextxy(170, 140, "Mat Khau Cu");
	setcolor(BLACK);
	rectangle(450, 100,900, 150);
	//mk moi
	setfillstyle(1, yellow);
	setcolor(BLUE); rectangle(150, 150, 450, 200);
	bar(150, 100+50, 450,200); setcolor(BLUE); setbkcolor(yellow); settextjustify(0, 1);
	settextstyle(9, 0, 4); outtextxy(170, 140+50, "Mat Khau Moi");
	setcolor(BLACK); rectangle(450, 100+50, 900, 150+50);
	//xac nhan
	setfillstyle(1, LIGHTMAGENTA);
	setcolor(BLUE); rectangle(150, 200, 450, 250);
	bar(150, 100 + 50*2, 450, 250); setcolor(BLUE); setbkcolor(LIGHTMAGENTA); settextjustify(0, 1);
	settextstyle(9, 0, 4); outtextxy(170,240, "Xac Nhan");
	setcolor(BLACK); rectangle(450, 100 + 50*2,900, 150 + 50*2);
	// doi thanh cong
	setfillstyle(1, green);
	setcolor(red); rectangle(1000, 100,1300, 150);
	bar(1000, 100,1300, 150); setcolor(WHITE); setbkcolor(green); settextjustify(0, 1);
	settextstyle(9, 0, 4); outtextxy(1010, 140, "Doi Mat Khau");
	setcolor(xinh2); settextstyle(9, 0, 3); setbkcolor(blue_d);
	outtextxy(150, 675, "CAM ON CO VA CAC BAN DA THEO DOI PHAN MEM CUA CHUNG EM");
	setcolor(red);
	rectangle(140, 655, 1240, 680);
}
void input_pass() {
	int exit = 0,x,y;
	int t1 = 0, t2 = 0, t3 = 0;
	int user, password,user1,password1;
	while (exit == 0) {
		if (ismouseclick(WM_LBUTTONDOWN)) {
			getmouseclick(WM_LBUTTONDOWN, x, y);
		 if ((x >= 0 && x <= 130) && (y >= 0 && y <= 40)) {
			exit = 1; HomePageUIShow();
		}
			else if ((x >= 150 && x <= 900) && (y>=100 && y<=150)) {
			 setbkcolor(WHITE);
			 
			 setfillstyle(6, blue_d);
			 bar(450, 100, 900, 150); bar(450, 100 + 50, 900, 150 + 50); bar(450, 100 + 50 * 2, 900, 150 + 50 * 2);
			 bar(0,40, 1520, 90);
			 bar(910, 160, 1520, 300);
			 setcolor(blue);
			 rectangle(450, 100 + 50, 900, 150 + 50); rectangle(450, 100 + 50 * 2, 900, 150 + 50 * 2);
			 setfillstyle(1, green);
			 setcolor(red); rectangle(1000, 100, 1300, 150);
			 bar(1000, 100, 1300, 150); setcolor(WHITE); setbkcolor(green); settextjustify(0, 1);
			 settextstyle(9, 0, 4); outtextxy(1010, 140, "Doi Mat Khau"); setbkcolor(WHITE);
				char s[50], s1[50] = " ";
				setcolor(yellow);
				rectangle(450, 100, 900, 150); settextjustify(0, 1); settextstyle(9, 0, 4); setcolor(red);
				Input(s, s1, 460, 140, '0', '9', 450, 100, 900, 150);
				strcpy(s1, s);
				ofstream f; f.open("try.txt", ios::out);
				f << s;
			}
			else if ((x >=150 && x <= 900) && (y>= 100+50 && y<=150+50)) {
			 setfillstyle(6, blue_d);
			 bar(450, 100 + 50, 900, 150 + 50);
			 setbkcolor(WHITE);
				char s1[50], s2[50] = " ";
				setcolor(yellow);
				rectangle(450, 100+50, 900, 150+50); settextjustify(0, 1); settextstyle(9, 0, 4); setcolor(red);
				Input(s1, s2, 460, 140+50, '0', '9', 450, 100+50, 900, 150+50);
				strcpy(s2, s1);
				ofstream f; f.open("input_menu8.txt", ios::out);
				f << s1 << ",";
				f.close();
			}
			else if ((x >= 150 && x <= 900) && (y >= 100 + 50*2 && y <= 150 + 50*2)) {
			 setfillstyle(6, blue_d);
			 bar(450, 100 + 50 * 2, 900, 150 + 50 * 2);
			 setbkcolor(WHITE);
				char s2[50], s3[50] = " ";
				setcolor(yellow);
				rectangle(450, 100 + 50*2, 900, 150 + 50*2); settextjustify(0, 1); settextstyle(9, 0, 4); setcolor(red);
				Input(s2, s3, 460, 140 + 50*2, '0', '9', 450, 100 + 50*2, 900, 150 + 50*2);
				strcpy(s3, s2);
				ofstream f; f.open("input_menu8.txt", ios::out|ios::app);
				f << s2;
				f.close();
			}
			else if ((x>=1000&&x<=1300)&&(y>=100&&y<=150)) {
				setfillstyle(1, red);
				setcolor(red); rectangle(1000, 100, 1300, 150);
				bar(1000, 100, 1300, 150); setcolor(WHITE); setbkcolor(red); settextjustify(0, 1);
				settextstyle(9, 0, 4); outtextxy(1010, 140, "Doi Mat Khau");
				settextstyle(9, 0, 1);
				ifstream f; f.open("try.txt", ios::in);
				f >> t1;
				ifstream fl; fl.open("user_password.txt", ios::in);
				ifstream ft; ft.open("input_menu8.txt", ios::in);
				ft >> user1; ft.seekg(1, 1); ft >> password1;
				fl >> user; fl.seekg(1, 1); fl >> password;
				settextstyle(9, 0, 3);
				if (t1 != password)
				{
					outtextxy(960, 190, "Mat Khau Cu khong Chinh Xac");
				}
				else if(user1!=password1){
					outtextxy(960, 190, "Mat Khau Nhap Lai khong Chinh Xac");
				}
				else {
					setfillstyle(1, WHITE);
					bar(1150, 160, 1300, 190);
					outtextxy(1000, 180, "Doi Mat Khau thanh Cong");
					ifstream ft; ft.open("input_menu8.txt", ios::in);
					ft >> user1; ft.close();
					ofstream fl; fl.open("user_password.txt", ios::out);
					fl << "7723" << "," << " ";
					fl << user1;
					exit = 1;
				}
			}
		}
	}
}
void doipass() {
	int exit = 0, x, y;
	cleardevice();
	setfillstyle(1, green);
	setcolor(red); setbkcolor(green);
	bar(0, 0, 1520, 40); settextjustify(1, 1);
	settextstyle(9, 0, 0);
	outtextxy(1520 / 2, 30, "DOI MAT KHAU"); settextstyle(9, 0, 3);
	setfillstyle(1, yellow); setcolor(red); setbkcolor(yellow);
	bar(0, 0, 130, 40); outtextxy(60, 30, "<BACK"); setcolor(RED);
	rectangle(0, 0, 130, 40); setbkcolor(WHITE);
	setfillstyle(6, blue_d);  
	bar(0, 40, 1520, 820); menu_doipass();
	input_pass();
	while (exit == 0)
	{
		if (ismouseclick(WM_LBUTTONDOWN)) {
			getmouseclick(WM_LBUTTONDOWN, x, y);
			if ((x >= 0 && x <= 130) && (y >= 0 && y <= 40)) {
				exit = 1; HomePageUIShow();
			}
		}
	}
}