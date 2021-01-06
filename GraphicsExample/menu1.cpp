#include"menu1.h"
#include"graphics.h"
#include"HOMEPAGE_UI.h"
#include"Longin_user.h"
#include<fstream>
#include <sstream>
int x = 1350, y = 70, x1 = 1360, yy =70, ll;

void love()
{
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
	if (x == 440) { setcolor(YELLOW); setfillstyle(1, 15); }
	else { setcolor(12); setfillstyle(1, 12); }
	fillpoly(11, ily);
	fillpoly(11, ily2);
	
}
void set_color() {
	setcolor(red); rectangle(100, 150, 1200, 200); rectangle(100, 200, 1200, 250); rectangle(100, 250, 1200, 300); rectangle(100, 350, 1200, 400);
	rectangle(100, 350, 1200, 400); rectangle(100, 460, 1200, 490); rectangle(100, 610, 1200, 640);	rectangle(100, 640, 1200, 670);
	rectangle(100, 490, 1200, 520); rectangle(100, 520, 1200, 550);	rectangle(100, 580, 1200, 610); rectangle(100, 670, 1200, 700);
}
void Read_1_unitprice(ifstream& f, unitprice& rv) {
	f >> rv.electric;
	f.seekg(1, 1);
	f >> rv.water;
	f.seekg(1, 1);
	f >> rv.water1; 
	f.seekg(1, 1);
	f >> rv.car_manage;
	f.seekg(1, 1);
	f >> rv.clean;
	f.seekg(1, 1);
	f >> rv.cabletv;
	f.seekg(1, 1);
	f >> rv.internet;
	f.seekg(1, 1);
	f >> rv.roomcost;
	string tmp;
	getline(f, tmp);
}
void printf_info_unitprice(unitprice rv) {
	//transform int  to char*
	//electric
	stringstream strs;
	strs << rv.electric;
	string temp_str = strs.str();
	char* char_type = (char*)temp_str.c_str();
	outtextxy(320, 470, char_type);
	//water
	stringstream strs1;
	strs1 << rv.water;
	string temp_str1 = strs1.str();
	char* char_type1 = (char*)temp_str1.c_str();
	outtextxy(320, 500, char_type1);
	//water1
	stringstream strs2;
	strs2 << rv.water1;
	string temp_str2 = strs2.str();
	char* char_type2 = (char*)temp_str2.c_str();
	outtextxy(320, 530, char_type2);
	//car_manage
	stringstream strs3;
	strs3 << rv.car_manage;
	string temp_str3 = strs3.str();
	char* char_type3 = (char*)temp_str3.c_str();
	outtextxy(320, 560, char_type3);
	//clean
	stringstream strs4;
	strs4 << rv.clean;
	string temp_str4 = strs4.str();
	char* char_type4 = (char*)temp_str4.c_str();
	outtextxy(320, 590, char_type4);
	//cabletv
	stringstream strs5;
	strs5 << rv.cabletv;
	string temp_str5 = strs5.str();
	char* char_type5 = (char*)temp_str5.c_str();
	outtextxy(320, 620, char_type5);
	//internet
	stringstream strs6;
	strs6 << rv.internet;
	string temp_str6 = strs6.str();
	char* char_type6 = (char*)temp_str6.c_str();
	outtextxy(320, 650, char_type6);
	//roomcost
	stringstream strs7;
	strs7 << rv.roomcost;
	string temp_str7 = strs7.str();
	char* char_type7 = (char*)temp_str7.c_str();
	outtextxy(320, 680, char_type7);
}

void Read_1_info(ifstream& f, infor_hostel& sv) {
	getline(f, sv.name, ',');
	f.seekg(1, 1);
	getline(f, sv.adress, ',');
	f.seekg(1, 1);
	getline(f, sv.phonenumber, ',');
	f.seekg(1, 1);
	getline(f, sv.content, ',');
	f.seekg(1, 1);
	getline(f, sv.notice, ',');
	string tmp;
	getline(f, tmp);
}
void rewrite_info(ofstream& f, infor_hostel& sv) {
	f << sv.name << "," << " "; f << sv.adress << "," << " "; f << sv.phonenumber << "," << " "; f << sv.content << "," << " ";
	f << sv.notice;
}
void rewrite_info_price(ofstream& f, unitprice& rv) {
	f << rv.electric << "," << " "; f << rv.water << "," << " "; f << rv.water1 << "," << " "; f << rv.car_manage << "," << " ";
	f << rv.clean << "," << " "; f << rv.cabletv << "," << " "; f << rv.internet << "," << " "; f << rv.roomcost;
}
void printf_info_hostel(infor_hostel sv) {
	setbkcolor(red); setcolor(WHITE);
	char* c = const_cast<char*>(sv.name.c_str());
	outtextxy(320,170, c);
	char* b = const_cast<char*>(sv.adress.c_str());
	outtextxy(320, 230, b);
	char* a = const_cast<char*>(sv.phonenumber.c_str());
	outtextxy(320, 270, a);
	char* d = const_cast<char*>(sv.content.c_str());
	outtextxy(320, 320, d);
	char* e = const_cast<char*>(sv.notice.c_str());
	outtextxy(320, 370,e);
}
void info_nhatro() {
	
	char s[100],s1[100]=" "; int exit = 0, mn = 0;
	infor_hostel sv;
	unitprice rv;
	ifstream fo; fo.open("hostel_information.txt", ios::in);
	if (fo.fail()) outtextxy(getmaxx() / 2, getmaxy() / 2, "file khong mo duoc");
	Read_1_info(fo, sv);
	printf_info_hostel(sv);
	fo.close();
	ifstream fn; fn.open("unit_price.txt", ios::in);
	if (fn.fail()) outtextxy(getmaxx() / 2, getmaxy() / 2, "file khong mo duoc");
	Read_1_unitprice(fn, rv);
	printf_info_unitprice(rv);
	fn.close();
	
	Read_1_info(fo, sv);
	rectangle(600,750, 700,770);
	outtextxy(600, 755, "<<BACK");
	
	setcolor(WHITE);
	setbkcolor(blue_d);
	setfillstyle(1, blue_d);
	bar(100, 50, 1200, 100);
	settextstyle(9, 0, 1); setcolor(red);
	outtextxy(550, 70, "THONG TIN PHONG TRO");
	 setfillstyle(1, green);
	bar(100, 100, 1200, 150);
	setbkcolor(green);
	outtextxy(110, 120, "1.Thong Tin Nha Tro");
	setcolor(red);
	for (int i = 200; i <= 400; i += 50) {
		line(100, i, 1200, i);
	}
	for (int i = 490; i <= 700; i += 30) {
		line(100, i, 1200, i);
	}
	setcolor(WHITE);
	outtextxy(110, 470, "Dien:");
	outtextxy(110, 500, "Nuoc(KW):");
	outtextxy(110, 530, "Nuoc/nguoi:");
	outtextxy(110, 560, "Quan Li xe");
	outtextxy(110, 590, "Ve Sinh");
	outtextxy(110, 620, "Truyen Hinh Cap:");
	outtextxy(110, 650, "Internet:");
	outtextxy(110, 680, "Tien Phong:");
	setcolor(BLACK);
	line(300, 150, 300, 400);
	line(300,460, 300, 700);
	setcolor(WHITE);
	outtextxy(320, 720, "Don Gia Mac Dinh Co The Thay Doi Theo Tung Phong");
	settextstyle(9, 0, 1);
	outtextxy(110, 170, "Ten Nha Tro");
	outtextxy(110, 230, "Dia Chi");
	outtextxy(110, 270, "So DT");
	outtextxy(110, 320, "Noi Dung");
	outtextxy(110, 370, "Thong Bao");
	setfillstyle(1, WhatsApp); setcolor(red3); setbkcolor(WhatsApp);
	bar(100, 420, 1200, 460);
	outtextxy(110, 430, "2.DON GIA MAC DINH");
	while (mn == 0)
	{
		int x, y;
		if (ismouseclick(WM_MOUSEMOVE)) {
			getmouseclick(WM_MOUSEMOVE, x, y);
			if ((x >= 100 && x <= 1200) && (y >= 150 && y <= 200))
			{
				setcolor(YELLOW); rectangle(100, 150, 1200, 200);
				if (ismouseclick(WM_LBUTTONDOWN)) {
						setcolor(BLACK); fflush(stdin);
						ofstream fm; fm.open("hostel_information.txt", ios::out);
						Input(s, s1, 320, 170, ' ', 'z', 320, 170, 600, 190);
						strcpy(s1, s);//rewrite success
						sv.name = s;
						rewrite_info(fm, sv);
						
						fm.close();
					
				}
			}
			else if ((x >= 100 && x <= 1200) && (y >= 200 && y <= 250)) {
				setcolor(blue);
				rectangle(100, 200, 1200, 250);
				
				if (ismouseclick(WM_LBUTTONDOWN)) {
					getmouseclick(WM_LBUTTONDOWN, x, y);

					if ((x >= 100 && x <= 1200) && (y >= 200 && y <= 250))
					{
						
						setcolor(BLACK);
						ofstream fm; fm.open("hostel_information.txt", ios::out);
						char s1[100], s2[100] = " "; 
						Input(s1, s2, 320, 230, ' ', 'z', 320, 200, 600,250);
						strcpy(s2, s1);
						sv.adress = s1;
						rewrite_info(fm, sv); 
						fm.close();
					}
				}

			}
			else if ((x >= 100 && x <= 1200) && (y >= 250 && y <= 300)) {
				setcolor(BLACK);
				rectangle(100, 250, 1200, 300);
				if (ismouseclick(WM_LBUTTONDOWN)) {
					getmouseclick(WM_LBUTTONDOWN, x, y);

					if ((x >= 100 && x <= 1200) && (y >= 250 && y <= 300))
					{
						setcolor(BLACK);
						ofstream fm; fm.open("hostel_information.txt", ios::out);
						char s2[100], s3[100] = " ";
						Input(s2, s3, 320, 270, ' ', 'z', 320, 250, 600, 300);
						strcpy(s3, s2);
						sv.phonenumber = s2;
						rewrite_info(fm, sv); 
						fm.close();
					}
				}
			}
			else if ((x >= 100 && x <= 1200) && (y >= 300 && y <= 350)) {
				setcolor(LIGHTBLUE);
				rectangle(100, 300, 1200, 350);
				if (ismouseclick(WM_LBUTTONDOWN)) {
					getmouseclick(WM_LBUTTONDOWN, x, y);

					if ((x >= 100 && x <= 1200) && (y >= 300 && y <= 350))
					{
						setcolor(BLACK);
						ofstream fm; fm.open("hostel_information.txt", ios::out);
						char s3[100], s4[100] = " ";
						Input(s3, s4, 320, 320, ' ', 'z', 320, 300, 600, 350);
						strcpy(s4, s3);
						sv.content = s3;
						rewrite_info(fm, sv); 
						fm.close();
					}
				}
			}
			else if ((x >= 100 && x <= 1200) && (y >= 350 && y <= 400)) {
				setcolor(blue);
				rectangle(100, 350, 1200, 400);
				if (ismouseclick(WM_LBUTTONDOWN)) {
					getmouseclick(WM_LBUTTONDOWN, x, y);

					if ((x >= 100 && x <= 1200) && (y >= 350 && y <= 400))
					{
						setcolor(BLACK);
						ofstream fm; fm.open("hostel_information.txt", ios::out); 
						char s4[100], s5[100] = " ";
						Input(s4, s5, 320, 370, ' ', 'z', 320, 350, 600, 400);
						strcpy(s5, s4);
						sv.notice = s4;
						rewrite_info(fm, sv); 
						fm.close();
					}
				}
			}	//divide two parts
			else if ((x >= 100 && x <= 1200) && (y >= 460 && y <= 490))
			{
				setcolor(blue);
				rectangle(100, 460, 1200, 490);
				if (ismouseclick(WM_LBUTTONDOWN)) {
					getmouseclick(WM_LBUTTONDOWN, x, y);

					if ((x >= 100 && x <= 1200) && (y >= 460 && y <= 490))
					{
						setcolor(BLACK);
						ofstream fm; fm.open("unit_price.txt", ios::out);
						char x[100], x1[100] = " ";
						Input(x, x1, 320, 470, '0 ', '9', 320, 460, 600, 490);
						strcpy(x1, x); 
						rv.electric = atoi(x);
						rewrite_info_price(fm, rv);
						fm.close();
					}
				}
			}
		
			else if ((x >= 100 && x <= 1200) && (y >= 490 && y <= 520))
			 {
				setcolor(BLACK);
				rectangle(100, 490, 1200, 520);
				if (ismouseclick(WM_LBUTTONDOWN)) {
					getmouseclick(WM_LBUTTONDOWN, x, y);

					if ((x >= 100 && x <= 1200) && (y >= 490 && y <= 520))
					{
						setcolor(BLACK);
						ofstream fm; fm.open("unit_price.txt", ios::out);
						char x1[100], x2[100] = " ";
						Input(x1, x2, 320, 500, '0 ', '9', 320, 490, 600, 520);
						strcpy(x2, x1);
						rv.water = atoi(x1);
						rewrite_info_price(fm, rv);
						fm.close();
					}
				}
			}
			else if ((x >= 100 && x <= 1200) && (y >= 520 && y <= 550)) {
				setcolor(BROWN);
				rectangle(100, 520, 1200, 550);
				if (ismouseclick(WM_LBUTTONDOWN)) {
					getmouseclick(WM_LBUTTONDOWN, x, y);

					if ((x >= 100 && x <= 1200) && (y >= 520 && y <= 550))
					{
						setcolor(BLACK);
						ofstream fm; fm.open("unit_price.txt", ios::out);
						char x2[100], x3[100] = " ";
						Input(x2, x3, 320, 530, '0 ', '9', 320, 520, 600, 550);
						strcpy(x3, x2);
						rv.water1 = atoi(x2);
						rewrite_info_price(fm, rv);
						fm.close();
					}
				}
			}
			else if ((x >= 100 && x <= 1200) && (y >= 550 && y <= 580)) {
				setcolor(LIGHTCYAN);
				rectangle(100, 550, 1200, 580);
				if (ismouseclick(WM_LBUTTONDOWN)) {
					getmouseclick(WM_LBUTTONDOWN, x, y);

					if ((x >= 100 && x <= 1200) && (y >= 550 && y <= 580))
					{
						setcolor(BLACK);
						ofstream fm; fm.open("unit_price.txt", ios::out);
						char x3[100], x4[100] = " ";
						Input(x3, x4, 320, 560, '0 ', '9', 320, 550, 600, 580);
						strcpy(x4, x3);
						rv.car_manage = atoi(x3);
						rewrite_info_price(fm, rv);
						fm.close();
					}
				}
			}
			else if ((x >= 100 && x <= 1200) && (y >= 580 && y <= 610)) {
				setcolor(MAGENTA);
				rectangle(100, 580, 1200, 610);
				if (ismouseclick(WM_LBUTTONDOWN)) {
					getmouseclick(WM_LBUTTONDOWN, x, y);

					if ((x >= 100 && x <= 1200) && (y >= 580 && y <= 610))
					{
						setcolor(BLACK);
						ofstream fm; fm.open("unit_price.txt", ios::out);
						char x4[100], x5[100] = " ";
						Input(x4, x5, 320, 590, '0 ', '9', 320, 580, 600, 610);
						strcpy(x5, x4);
						rv.clean = atoi(x4);
						rewrite_info_price(fm, rv);
						fm.close();
					}
				}
			}
			else if ((x >= 100 && x <= 1200) && (y >= 610 && y <= 640)) {
				setcolor(grey);
				rectangle(100, 610, 1200, 640);
				if (ismouseclick(WM_LBUTTONDOWN)) {
					getmouseclick(WM_LBUTTONDOWN, x, y);

					if ((x >= 100 && x <= 1200) && (y >= 610&& y <= 640))
					{
						setcolor(BLACK);
						ofstream fm; fm.open("unit_price.txt", ios::out);
						char x5[100], x6[100] = " ";
						Input(x5, x6, 320, 620, '0 ', '9', 320, 580, 600, 610);
						strcpy(x6, x5);
						rv.cabletv = atoi(x6);
						rewrite_info_price(fm, rv);
						fm.close();
					}
				}

			}
			else if ((x >= 100 && x <= 1200) && (y >= 640 && y <= 670)) {
				setcolor(blue);
				rectangle(100, 640, 1200, 670);
				if (ismouseclick(WM_LBUTTONDOWN)) {
					getmouseclick(WM_LBUTTONDOWN, x, y);

					if ((x >= 100 && x <= 1200) && (y >= 640 && y <= 670))
					{
						setcolor(BLACK);
						ofstream fm; fm.open("unit_price.txt", ios::out);
						char x5[100], x6[100] = " ";
						Input(x5, x6, 320, 650, '0 ', '9', 320, 640, 600,670);
						strcpy(x6, x5);
						rv.internet = atoi(x5);
						rewrite_info_price(fm, rv);
						fm.close();
					}
				}
			}
			else if ((x >= 100 && x <= 1200) && (y >= 670 && y <= 700)) {
				setcolor(yellow);
				rectangle(100, 670, 1200, 700);
				if (ismouseclick(WM_LBUTTONDOWN)) {
					getmouseclick(WM_LBUTTONDOWN, x, y);

					if ((x >= 100 && x <= 1200) && (y >= 670 && y <= 700))
					{
						setcolor(BLACK);
						ofstream fm; fm.open("unit_price.txt", ios::out);
						char x6[100], x7[100] = " ";
						Input(x6, x7, 320, 680, '0 ', '9', 320, 670, 600, 700);
						strcpy(x7, x6);
						rv.roomcost = atoi(x6);
						rewrite_info_price(fm, rv);
						fm.close();
					}
				}
			}
			
			else if ((x >= 620 &&x <= 720) && (y >= 750 && y <= 770)) {
			if (ismouseclick(WM_LBUTTONDOWN)) {
				mn = 1;
			}
			
	}
			
		else {
				set_color();
			}
		}
		if (kbhit())
		{
			char key = getch();
			if (key == 27) {
				cleardevice();
				HomePageUIShow();
				exit = 1;
			}
		}
	}
	while (exit == 0) {
		int x, y;
		if (ismouseclick(WM_LBUTTONDOWN))
		{
			getmouseclick(WM_LBUTTONDOWN, x, y);
			if ((x >=600 &&x <= 710) && (y >= 750 && y <= 770)) {
				
				HomePageUIShow(); 
				
			}
		}
		
	}
}
void init_record() {
	cleardevice();
	setbkcolor(Plum1); settextstyle(9, 0, 0);
	setfillstyle(6, blue_d);
	bar(0, 0, 1520, 850);
	love(); setcolor(BLUE); setbkcolor(red);
	outtextxy(1280, 90, "P"); setcolor(YELLOW);
	outtextxy(1320, 90, "T"); setcolor(WHITE);
	outtextxy(1380, 90, "I"); setcolor(GREEN);
	outtextxy(1420, 90, "T");
	setcolor(red); setbkcolor(blue_d); settextstyle(9, 0, 3);
	outtextxy(1220, 500, "Hot key: ESC-Thoat");
	setcolor(BLACK);
	rectangle(100, 50, 1200, 750); settextstyle(9, 0, 1);
	info_nhatro();
}