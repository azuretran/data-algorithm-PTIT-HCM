#include"menu3.h"
#include"HOMEPAGE_UI.h"
#include"Longin_user.h"
#include<iostream>
#include <sstream>
#include<ctime>
using namespace std;
#define maxsize 13;
#define top 250
#define bottom 760
#define right 1520
void draw_table_2() {
	setfillstyle(1, WHITE);
	bar(550, 70,1520, 220);
	setcolor(green);
	rectangle(550, 70, 1520, 220);
	for (int i = 100; i <= 220; i += 30) {
		line(550, i, 1520, i);
	}setbkcolor(WHITE);
	setcolor(blue);
	line(700, 70, 700, 220);
	outtextxy(560, 75, "Khoan Chi");
	setcolor(RED);
	outtextxy(590, 55, "Them Thanh cong!");
	setcolor(blue);
	outtextxy(560, 105, "Ghi Chu");
	outtextxy(560, 135, "Ngay");
	outtextxy(560, 165, "So Tien"); outtextxy(560, 195, "Vi Tri");
	setbkcolor(red);
	setfillstyle(1, red);
	setcolor(WHITE);
	bar(1200, 190, 1520, 250);
	rectangle(1200, 190, 1520, 250);
	settextstyle(9, 0, 2);
	outtextxy(1220, 210, "Them");
	setfillstyle(1, blue); bar(1000, 190, 1200, 250); setcolor(YELLOW);
	rectangle(1000, 190, 1200, 250);
	setbkcolor(blue);
	outtextxy(1010, 210, "LOAD-DATA");

}
void reset_draw_main_table() {
	setfillstyle(1, WHITE);
	bar(10, top,right, bottom);
	int exit = 0;
	int x, y, j = 0, dem = 0;
	setfillstyle(1, green);
	bar(10, top, right, top + 30);
	for (int i = 280; i < 760; i += 30) {
		setcolor(BLACK);
		rectangle(10, top, right, bottom);
		line(10, i, 1520, i); dem++;
	}
	for (int i = 342; i < 1520; i += 342) {
		line(i, top, i, bottom); if (i == 342 * 3) break;
	}setcolor(blue);
	line(100, 250, 100, 760);
	setbkcolor(green);
	outtextxy(20, 255, "STT"); setcolor(WHITE);
	//time and days
	setbkcolor(WHITE); setcolor(red);
	time_t hientai = time(0);
	tm* ltm = localtime(&hientai);
	//printf day
	stringstream strs1;
	strs1 << ltm->tm_mday;
	string m1 = strs1.str();
	char* char_type1 = (char*)m1.c_str();
	outtextxy(720, 75*2-10, char_type1); outtextxy(760, 75*2-10,"/");
	//printf month
	stringstream strs2;
	strs2 << ltm->tm_mon+1;
	string m2 = strs2.str();
	char* char_type2 = (char*)m2.c_str();
	outtextxy(780, 75*2-10, char_type2); outtextxy(800, 75*2-10, "/");
	//printf years
	stringstream strs3;
	strs3 << ltm->tm_year+1900;
	string m3 = strs3.str();
	char* char_type3 = (char*)m3.c_str();
	outtextxy(820, 75*2-10, char_type3);
	outtextxy(120, 255, "Ngay"); setcolor(red); outtextxy(50 + 342, 255, "Khoan Chi"); setcolor(yellow); outtextxy(50 + 342 * 2, 255, "So Tien"); setcolor(BROWN); outtextxy(50 + 342 * 3, 255, "Ghi Chu");

}
void reset_draw_main_table_2() {
	setfillstyle(1, WHITE);
	bar(10, top, right, bottom);
	int exit = 0;
	int x, y, j = 0, dem = 0;
	setfillstyle(1, green);
	bar(10, top, right, top + 30);
	for (int i = 280; i < 760; i += 30) {
		setcolor(BLACK);
		rectangle(10, top, right, bottom);
		line(10, i, 1520, i); dem++;
	}
	for (int i = 342; i < 1520; i += 342) {
		line(i, top, i, bottom); if (i == 342 * 3) break;
	}setcolor(blue);
	line(100, 250, 100, 760);
	setbkcolor(green);
	outtextxy(20, 255, "STT"); setcolor(WHITE);
	
	outtextxy(120, 255, "Ngay"); setcolor(red); outtextxy(50 + 342, 255, "Khoan Chi"); setcolor(yellow); outtextxy(50 + 342 * 2, 255, "So Tien"); setcolor(BROWN); outtextxy(50 + 342 * 3, 255, "Ghi Chu");

}
void table_thongke() {
	
		setfillstyle(1, WHITE);
		bar(10, top, right, bottom);
		int exit = 0;
		int x, y, j = 0, dem = 0;
		setfillstyle(1, green);
		bar(10, top, right, top + 30);
		for (int i = 280; i < 760; i += 30) {
			setcolor(BLACK);
			rectangle(10, top, right, bottom);
			line(10, i, 1520, i); dem++;
		}
		for (int i = 342; i < 1520; i += 342) {
			line(i, top, i, bottom); if (i == 342 * 3) break;
		}setcolor(blue);
		line(100, 250, 100, 760);
		setbkcolor(green);
		outtextxy(20, 255, "STT"); setcolor(WHITE);
		outtextxy(120, 255, "Ngay"); setcolor(red); outtextxy(50 + 342, 255, "Khoan Chi"); setcolor(yellow); outtextxy(50 + 342 * 2, 255, "So Tien"); setcolor(BROWN); outtextxy(50 + 342 * 3, 255, "Ghi Chu");

 }
void input_listexpm() {
	void  thongket();
	void xuli();
	list l; create_list_expm(l);
	expm  sv,rv;
	
	ifstream  f; 
	f.open("expense_management.txt", ios::in);
	if (f.fail())
		cout << "Error file! " << endl;
	while (!f.eof())  //read into endfile.
	{
		expm sv;
		Read_1_SV(f, sv);
		nodexpm* p = create_node_expm(sv);
		add_node_expm_tail(l, p);
	}
	f.close();
	danhso(l);
	int n = len(l);
	int x, y,exit=0;
	char s[100], s1[100] = " ";
	int postion;
	
	while (exit == 0)
	{
		setbkcolor(WHITE);
		if (ismouseclick(WM_LBUTTONDOWN))
		{
			getmouseclick(WM_LBUTTONDOWN, x, y);
			if ((x >= 700 && x <= right) && (y >= 75 && y <= 105))
			{
				setfillstyle(1, WHITE);
				bar(700, 70, right, 100);
				setcolor(RED);
				rectangle(700, 70, right, 100);
				Input(s, s1, 710, 75, ' ', 'z', 700, 70, right, 100);
				strcpy(s1, s);
				ofstream fk; fk.open("input_menu8.txt", ios::out);
				fk << s << ",";
			}

			else
				if ((x >= 700 && x <= right) && (y >= 75 + 30 && y <= 105 + 30))
				{
					char s1[100], s2[100] = " ";
					setcolor(LIGHTMAGENTA);
					rectangle(700, 70 + 30, right, 100 + 30);
					Input(s1, s2, 710, 75 + 30, ' ', 'z', 700, 70 + 30, right, 100 + 30);
					strcpy(s2, s1);

					ofstream fk; fk.open("input_menu8.txt", ios::out | ios::app);

					fk << s1 << ",";
					fk.close();
				}


				else

					if ((x >= 700 && x <= right) && (y >= 75 + 30 * 2 && y <= 105 + 30 * 2))
					{
						setfillstyle(1, WHITE);
						bar(700, 70 + 30 * 2, right, 100 + 30 * 2);
						char s2[100], s3[100] = " ";
						setcolor(blue_A);
						rectangle(700, 70 + 30 * 2, right, 100 + 30 * 2);
						Input(s2, s3, 710, 75 + 30 * 2, '/', '9', 700, 70 + 30 * 2, right, 100 + 30 * 2);
						strcpy(s3, s2);
						ofstream fk; fk.open("input_menu8.txt", ios::out | ios::app);
						fk << s2 << ",";
						fk.close();
					}


					else

						if ((x >= 700 && x <= right) && (y >= 75 + 30 * 3 && y <= 105 + 30 * 3))
						{
							char s3[100], s4[100] = " ";
							
							setcolor(red);
							rectangle(700, 70 + 30 * 3, right, 100 + 30 * 3);
							Input(s3, s4, 710, 75 + 30 * 3, '0', '9', 700, 70 + 30 * 3, right, 100 + 30 * 3);
							strcpy(s4, s3);
							
							ofstream fk; fk.open("input_menu8.txt", ios::out | ios::app);
							fk << s3;
							fk.close();

						}


						else

							if ((x >= 700 && x <= 1000) && (y >= 75 + 30 * 4 && y <= 105 + 30 * 4))
							{
								char s5[100], s6[100] = " ";
								setcolor(BLACK);
								rectangle(700, 70 + 30 * 4, 1000, 100 + 30 * 4);
								Input(s5, s6, 710, 75 + 30 * 4, '0 ', '9', 700, 70 + 30 * 4, 1000, 100 + 30 * 4);
								strcpy(s6, s5);
								ofstream f; f.open("try.txt", ios::out); f << s5; f.close();
								
								
							}
							else if ((x >= 1220 && x <= 1520) && (y >= 190 && y <= 250)) {
								setbkcolor(WHITE);
								setcolor(BLUE);
								rectangle(1220, 190, 1520, 250);
								ifstream f; f.open("try.txt", ios::in);
								int postion;
								f >> postion; f.close();
								ifstream f1; f1.open("input_menu8.txt", ios::in);
								Read_1_SV(f1, rv);
								f1.close();
								nodexpm* p = create_node_expm(rv);
								ThemNode_p_VaoViTriBatKi(l, p, postion, n);
								ofstream fileout; fileout.open("expense_management.txt", ios::out);
								for (nodexpm* k = l.phead; k != NULL; k = k->pnext)
								{

									write_infoexpm(fileout, k->data);

								}

								fileout.close();
								reset_draw_main_table();
								draw_table_2(); xuli();
								
							}
							else if ((x >= 50 && x <= 200) && (y >= 150 && y <= 240)) {
								 thongket();

							}
							else if ((x >= 220 && x <= 380) && (y >= 150 && y <= 220)) {

								int postion;
								char t[50], t1[50] = " ";
								setfillstyle(1, WHITE);
								bar(220, 150, 380, 220); setbkcolor(WHITE);
								setcolor(yellow);
								rectangle(220, 150, 380, 220); setcolor(red);
								Input(t, t1, 300, 190, '0', '9', 220, 150, 380, 220);
								strcpy(t1, t);
								ofstream fy; fy.open("try.txt", ios::out);
								fy << t; fy.close();
								postion = atoi(t);
								XoaNodeCoKhoaBatKy(l, postion);
								ofstream fileout; fileout.open("expense_management.txt", ios::out);
								for (nodexpm* k = l.phead; k != NULL; k = k->pnext)
								{

									write_infoexpm(fileout, k->data);


								}
								fileout.close();
								reset_draw_main_table();
								xuli();
							}
							else if ((x >= 400 && x <= 550) &&(y>=150&&y<=240)){
								danhso(l);
								setfillstyle(1, red);
								setcolor(WHITE);
								rectangle(400, 150, 550, 240);
								bar(400, 150, 550, 240);
								setbkcolor(red);
								settextstyle(9, 0, 4);
								outtextxy(420, 180, "EDIT");
								ifstream fy; fy.open("try.txt", ios::in);
								int posti;
								fy >> posti; fy.close();
								
					
								edit_by_postion(l, posti);
								
								ofstream fileout; fileout.open("expense_management.txt", ios::out);
								for (nodexpm* k = l.phead; k != NULL; k = k->pnext)
								{
									
									write_infoexpm(fileout, k->data);


								}
								fileout.close(); settextstyle(9, 0, 1);
								reset_draw_main_table_2(); 
								xuli();

							}
							//else if ((x >= 1000 && x <= 1200) && (y >= 190 && y <= 250)) exit = 1;
							else if ((x >= 400 && x <= 550) && (y >= 70 && y <= 140)) {
								setfillstyle(1, yellow);
								setcolor(green);
								rectangle(400, 70, 550, 140); setcolor(WHITE);
								bar(400, 70, 550, 140);
								setcolor(BLUE);
								setbkcolor(yellow);
								settextstyle(9, 0, 4);
								outtextxy(405, 90, "SapXep");
								sort_by_months(l); sort_by_day(l); 
								sort_by_years(l);
								
								ofstream fileout; fileout.open("expense_management.txt", ios::out);
								for (nodexpm* k = l.phead; k != NULL; k = k->pnext)
								{

									write_infoexpm(fileout, k->data);


								} fileout.close();
								settextstyle(9, 0, 1);
								reset_draw_main_table_2();
								xuli();
							}
							else if ((x >= 50 && x <= 200) && (y >= 70 && y <= 140)) {
								cleardevice(); HomePageUIShow(); exit = 1;
							}


		}
	
			
		
			
	}
}
void xuattheo_vitri(list l, int start, int endt) {
	int i = 255 + 30, dem = 0, dem2 = 0, j = 0;
	setbkcolor(WHITE);
	for (nodexpm* k = l.phead; k != NULL; k = k->pnext)
	{
		dem++;
		dem2++;
		if (dem == start) {
			dem--;
			//printf notice
			char* c = const_cast<char*>(k->data.notice.c_str());
			outtextxy(50 + 342 * 3, i, c);
			//printf sv.khoanchi
			char* q = const_cast<char*>(k->data.khoanchi.c_str());
			outtextxy(50 + 342, i, q);
			//printf sv.ngay.day
			stringstream strs;
			strs << k->data.ngay.day;
			string temp_str = strs.str();
			char* char_type = (char*)temp_str.c_str();
			outtextxy(120, i, char_type);
			outtextxy(150, i, "/");
			//printf sv.ngay.month
			stringstream strs1;
			strs1 << k->data.ngay.month;
			string m1 = strs1.str();
			char* char_type1 = (char*)m1.c_str();
			outtextxy(160, i, char_type1);
			outtextxy(190, i, "/");
			//printf sv.ngay.year
			stringstream strs2;
			strs2 << k->data.ngay.year;
			string m2 = strs2.str();
			char* char_type2 = (char*)m2.c_str();
			outtextxy(200, i, char_type2);
			//printf sv.ngay.money
			stringstream strs3;
			strs3 << k->data.money;
			string m3 = strs3.str();
			char* char_type3 = (char*)m3.c_str();
			outtextxy(50 + 342 * 2, i, char_type3);
			//printf number
			stringstream strs4;
			strs4 << dem2;
			string m4 = strs4.str();
			char* char_type4 = (char*)m4.c_str();
			outtextxy(20, 285 + j, char_type4); j += 30;
			i += 30;
		}

		if (dem2 == endt) break;


	}
}
void xuattheo_vitri_2(list l, int start, int endt,int dk) {
	int i = 255 + 30, dem = 0, dem2 = 0, j = 0;
	setbkcolor(WHITE);
	for (nodexpm* k = l.phead; k != NULL; k = k->pnext)
	{
		if (k->data.ngay.month == dk) {
			dem++;
			dem2++;
			if (dem == start) {
				dem--;
				//printf notice
				char* c = const_cast<char*>(k->data.notice.c_str());
				outtextxy(50 + 342 * 3, i, c);
				//printf sv.khoanchi
				char* q = const_cast<char*>(k->data.khoanchi.c_str());
				outtextxy(50 + 342, i, q);
				//printf sv.ngay.day
				stringstream strs;
				strs << k->data.ngay.day;
				string temp_str = strs.str();
				char* char_type = (char*)temp_str.c_str();
				outtextxy(120, i, char_type);
				outtextxy(150, i, "/");
				//printf sv.ngay.month
				stringstream strs1;
				strs1 << k->data.ngay.month;
				string m1 = strs1.str();
				char* char_type1 = (char*)m1.c_str();
				outtextxy(160, i, char_type1);
				outtextxy(190, i, "/");
				//printf sv.ngay.year
				stringstream strs2;
				strs2 << k->data.ngay.year;
				string m2 = strs2.str();
				char* char_type2 = (char*)m2.c_str();
				outtextxy(200, i, char_type2);
				//printf sv.ngay.money
				stringstream strs3;
				strs3 << k->data.money;
				string m3 = strs3.str();
				char* char_type3 = (char*)m3.c_str();
				outtextxy(50 + 342 * 2, i, char_type3);
				//printf number
				stringstream strs4;
				strs4 << dem2;
				string m4 = strs4.str();
				char* char_type4 = (char*)m4.c_str();
				outtextxy(20, 285 + j, char_type4); j += 30;
				i += 30;
			}

			if (dem2 == endt) break;

		}
	}
}
void doanh_thu() {

}
void thongket() {
	
	setfillstyle(1,WHITE);
	bar(0, 0, 1520, 850);
	list l; create_list_expm(l);
	ifstream  f; int x, y, exit = 0, demlist = 0, j = 0;
	int exit1 = 0;
	expm sv;
	f.open("expense_management.txt", ios::in);
	if (f.fail())
		cout << "Error file! " << endl;
	while (!f.eof())  //read into endfile.
	{
		expm sv;
		Read_1_SV(f, sv);
		nodexpm* p = create_node_expm(sv);
		add_node_expm_tail(l, p);
	}
	f.close();
	int len_list = len(l);
	char s11[50], s12[50] = " ";
	void draw_button(); 
	setfillstyle(1, green); setbkcolor(green);
	bar(0, 40, 260, 80); setcolor(WHITE); settextstyle(9, 0, 3);
	outtextxy(10, 50, "Nhap Thang");
	setcolor(red); rectangle(260, 40,1520, 80);
	settextstyle(9, 0, 0);
	setfillstyle(1, yellow); setcolor(red); setbkcolor(yellow);

	bar(0, 0, 200, 40); outtextxy(10, 10, "<BACK");
	
	setcolor(RED);
	rectangle(0, 0, 200, 40);

	setfillstyle(1, xinh);
	setcolor(WHITE); setbkcolor(xinh);
	bar(200, 0, 1520, 40);
	settextstyle(9, 0, 4);
	outtextxy(1520 / 2 - 200, 10, "Thong Ke Theo Thang"); setbkcolor(WHITE);

	
	int yy,tong=0; settextstyle(9, 0, 1);
	danhso(l);
	int flag = 0;
	while (exit == 0)
	{
		setbkcolor(WHITE);
		if (ismouseclick(WM_LBUTTONDOWN)) {
			getmouseclick(WM_LBUTTONDOWN, x, y);
			if ((x >= 0 && x <= 200) && (y >= 0 && y <= 40)) {
				
				cleardevice();
				setbkcolor(WHITE); settextstyle(9, 0, 1);
				draw_button(); 
				
			}
			else if ((x >= 200 && x <= 600) && (y >= 40 && y <= 80)) {
				setfillstyle(1, WHITE);
				bar(270, 40, 1520, 80); settextstyle(9, 0, 4);
				
				setcolor(LIGHTMAGENTA); 
				rectangle(270, 40, 1520, 80);
				tong = 0;
				rectangle(270, 40, 1200, 80); setcolor(BLUE);
				Input(s11, s12, 270, 50, ' ', 'z', 270, 40,1200, 80); strcpy(s12, s11);
				
				setcolor(red);
				yy = atoi(s11); 
				cout << endl << yy;

				if (yy > 12 || yy <= 0) {
					settextstyle(9, 0, 1);
					setcolor(red); setbkcolor(blue_d);
					outtextxy(270, 100, "Thang khong hop le");
					
				}
				else {
					setfillstyle(6, blue_d);
					bar(270, 100, 600, 140);
					setfillstyle(1, red); bar(1210, 765, 1300, 800);
					setcolor(BLACK);
					outtextxy(1210, 765, "NEXT>>"); settextstyle(9, 0, 1);
					table_thongke();
					int i = 255 + 30; setbkcolor(WHITE);
					tong = 0;
					for (nodexpm* k = l.phead; k != NULL; k = k->pnext)
					{
						if (k->data.ngay.month == yy) {
							
							tong += k->data.money;

							setfillstyle(1, WHITE); bar(550, 210, 700, 250);
							bar(420, 220, 470, 250);
							settextstyle(9, 0, 3); setfillstyle(1, red);
							bar(50, 220, 400, 250); setcolor(YELLOW); rectangle(50, 220, 400, 250);	setcolor(WHITE); setbkcolor(red);
							outtextxy(50, 220, "BAO CAO CHI THANG"); outtextxy(420, 220, s11); setbkcolor(WHITE); setcolor(red);
							settextstyle(9, 0, 1);
							demlist++;
							//printf notice
							char* c = const_cast<char*>(k->data.notice.c_str());
							outtextxy(50 + 342 * 3, i, c);
							//printf sv.khoanchi
							char* q = const_cast<char*>(k->data.khoanchi.c_str());
							outtextxy(50 + 342, i, q);
							//printf sv.ngay.day
							stringstream strs;
							strs << k->data.ngay.day;
							string temp_str = strs.str();
							char* char_type = (char*)temp_str.c_str();
							outtextxy(120, i, char_type);
							outtextxy(150, i, "/");
							//printf sv.ngay.month
							stringstream strs1;
							strs1 << k->data.ngay.month;
							string m1 = strs1.str();
							char* char_type1 = (char*)m1.c_str();
							outtextxy(160, i, char_type1);
							outtextxy(190, i, "/");
							//printf sv.ngay.year
							stringstream strs2;
							strs2 << k->data.ngay.year;
							string m2 = strs2.str();
							char* char_type2 = (char*)m2.c_str();
							outtextxy(200, i, char_type2);
							//printf sv.ngay.money
							stringstream strs3;
							strs3 << k->data.money;
							string m3 = strs3.str();
							char* char_type3 = (char*)m3.c_str();
							outtextxy(50 + 342 * 2, i, char_type3);
							
							stringstream strs4;
							strs4 << k->data.vt;
							string temp_str1 = strs4.str();
							char* char_type4 = (char*)temp_str1.c_str();
							outtextxy(20,i, char_type4); 
							i += 30;
							if (i > 735)
							{


								while (exit == 0)
								{
									if (ismouseclick(WM_LBUTTONDOWN))
									{
										getmouseclick(WM_LBUTTONDOWN, x, y);
										if ((x >= 0 && x <= 200) && (y >= 0 && y <= 40)) {

											exit = 1; draw_button();
										}
										else if ((x >= 220 && x <= 450) && (y >= 0 && y <= 40)) exit = 1;
										else if ((x >= 1210 && x <= 1520) && (y >= 765 && y <= 780)) {
											i = 255 + 30;
											reset_draw_main_table_2(); setcolor(red);
											xuattheo_vitri_2(l, demlist + 1, demlist + 16, yy);
											demlist += 16;
											if (demlist > 16) {
												setfillstyle(1, red);
												bar(1000, 765, 1100, 780);
												outtextxy(1000, 765, "<<PREV");

											}
										}
										else if ((x >= 1000 && x <= 1150) && (y >= 765 && y <= 780)) {

											demlist = demlist - 16;
											i = 255 + 30;
											reset_draw_main_table_2(); setcolor(red);
											xuattheo_vitri_2(l, demlist - 15, demlist, yy);
										}


										else
											if ((x >= 50 && x <= 200) && (y >= 70 && y <= 140)) {
												cleardevice(); HomePageUIShow();
												exit = 1;
											}



									


								}


							}
								
						}
							if (tong != 0) {
								setfillstyle(1, WHITE);
								bar(50, 90, 270, 110);

								setcolor(red); settextstyle(9, 0, 4);
								stringstream strs1q;
								strs1q << tong;
								string m1q = strs1q.str();
								char* char_type1q = (char*)m1q.c_str();
								outtextxy(550, 210, char_type1q);
								outtextxy(800, 210, "VND"); settextstyle(9, 0, 1);
								
							}
							else
								if (tong==0) {
									setfillstyle(1, WHITE);
									bar(0, 80, 1520, 850);
									setcolor(RED);
									outtextxy(50, 90, "Thang chua co chi tieu");
								}
							settextstyle(9, 0, 1);

					}
				
						
					}
					
				}
				
				

			}
		}
	}
}

void xuli() 
{

	
	list l; create_list_expm(l);
	ifstream  f; int x, y,exit=0,demlist=0,j=0;
	int exit1 = 0;
	expm sv;
	f.open("expense_management.txt", ios::in);
	if (f.fail())               
		cout << "Error file! " << endl;
	while (!f.eof())  //read into endfile.
	{
		expm sv;
		Read_1_SV(f, sv);
		nodexpm* p = create_node_expm(sv);
		add_node_expm_tail(l, p);
	}
	f.close();	
		int len_list = len(l);
			int i = 255+30;
			danhso(l);
			exit = 0;
			setbkcolor(WHITE); setcolor(red); settextstyle(9, 0, 1);
			for (nodexpm* k = l.phead; k != NULL; k = k->pnext)
			{

				demlist++;
				//printf notice
				char* c = const_cast<char*>(k->data.notice.c_str());
				outtextxy(50 + 342 * 3, i, c);
				//printf sv.khoanchi
				char* q = const_cast<char*>(k->data.khoanchi.c_str());
				outtextxy(50 + 342, i, q);
				//printf sv.ngay.day
				stringstream strs;
				strs << k->data.ngay.day;
				string temp_str = strs.str();
				char* char_type = (char*)temp_str.c_str();
				outtextxy(120, i, char_type);
				outtextxy(150, i, "/");
				//printf sv.ngay.month
				stringstream strs1;
				strs1 << k->data.ngay.month;
				string m1 = strs1.str();
				char* char_type1 = (char*)m1.c_str();
				outtextxy(160, i, char_type1);
				outtextxy(190, i, "/");
				//printf sv.ngay.year
				stringstream strs2;
				strs2 << k->data.ngay.year;
				string m2 = strs2.str();
				char* char_type2 = (char*)m2.c_str();
				outtextxy(200, i, char_type2);
				//printf sv.ngay.money
				stringstream strs3;
				strs3 << k->data.money;
				string m3 = strs3.str();
				char* char_type3 = (char*)m3.c_str();
				outtextxy(50 + 342 * 2, i, char_type3);
				
				stringstream strs4;
				strs4 << k->data.vt;
				string temp_str1 = strs4.str();
				char* char_type4 = (char*)temp_str1.c_str();
				outtextxy(20, i, char_type4); 
				i += 30;
				if (i > 735) {


					while (exit == 0)
					{
						/*if (kbhit()) {
							char key = getch();
							if (key == 32);
							cleardevice(); HomePageUIShow(); exit = 1;
						}*/
						if (ismouseclick(WM_LBUTTONDOWN))
						{
							getmouseclick(WM_LBUTTONDOWN, x, y);
							if ((x >= 1210 && x <= 1520) && (y >= 765 && y <= 780)) {
								i = 255 + 30;
								reset_draw_main_table(); setcolor(red);
								xuattheo_vitri(l, demlist + 1, demlist + 16);
								demlist += 16;
								if (demlist > 16) {
									setfillstyle(1, red);
									bar(1000, 765, 1100, 780); setbkcolor(red); setcolor(WHITE);
									outtextxy(1000, 765, "<<PREV");
									

								}
							}
							else if ((x >= 1000 && x <= 1150) && (y >= 765 && y <= 780)) {

								demlist -= 16;
								i = 255 + 30;
								reset_draw_main_table(); setcolor(red);
								xuattheo_vitri(l, demlist-15, demlist);
							}
							

							else
								if ((x >= 50 && x <= 200) && (y >= 70 && y <= 140)) {
									cleardevice(); HomePageUIShow();
									exit = 1;
								}
								else if ((x >= 220 && x <= 380) && (y >= 70 && y <= 140))
								{
									setbkcolor(WHITE);

									exit = 1;
								}
								else if ((x >= 1200 && x <= 1520) && (y <= 190 && y >= 250)) exit = 1;
								else if ((x>=50&&x<=200)&&(y>=150&&y<=240)){
									exit = 1; thongket();

								}
								else if ((x >= 700 && x <= right) && (y >= 75 && y <= 105)) {
									input_listexpm();
								}
								else if ((x >= 400 && x <= 550) && (y >= 70 && y <= 140)) {
									setfillstyle(1, yellow);
									setcolor(green);
									rectangle(400, 70, 550, 140); setcolor(WHITE);
									bar(400, 70, 550, 140);
									setcolor(BLUE);
									setbkcolor(yellow);
									settextstyle(9, 0, 4);
									outtextxy(405, 90, "SapXep");
									sort_by_months(l); sort_by_day(l);
									sort_by_years(l);

									ofstream fileout; fileout.open("expense_management.txt", ios::out);
									for (nodexpm* k = l.phead; k != NULL; k = k->pnext)
									{

										write_infoexpm(fileout, k->data);


									} fileout.close();
									settextstyle(9, 0, 1);
									reset_draw_main_table_2();
									xuli();
								}
								else if ((x >= 400 && x <= 550) && (y >= 150 && y <= 240)) {
									danhso(l);
									setfillstyle(1, red);
									setcolor(WHITE);
									rectangle(400, 150, 550, 240);
									bar(400, 150, 550, 240);
									setbkcolor(red);
									settextstyle(9, 0, 4);
									outtextxy(420, 180, "EDIT");
									ifstream fy; fy.open("try.txt", ios::in);
									int posti;
									fy >> posti; fy.close();
									
									edit_by_postion(l, posti);
									
									ofstream fileout; fileout.open("expense_management.txt", ios::out);
									for (nodexpm* k = l.phead; k != NULL; k = k->pnext)
									{

										write_infoexpm(fileout, k->data);


									}
									fileout.close();
									reset_draw_main_table_2(); settextstyle(9, 0, 1);
									xuli();

								}
								else if ((x >= 220 && x <= 380) && (y >= 150 && y <= 220)) {

									int postion;
									char t[50], t1[50] = " ";
									setfillstyle(1, WHITE); setbkcolor(WHITE);
									bar(220, 150, 380, 220);
									setcolor(yellow);
									rectangle(220, 150, 380, 220); setcolor(red);
									Input(t, t1, 300, 190, '0', '9', 220, 150, 380, 220);
									strcpy(t1, t);
									ofstream fy; fy.open("try.txt", ios::out);
									fy << t; fy.close();
									postion = atoi(t);
									XoaNodeCoKhoaBatKy(l, postion);
									ofstream fileout; fileout.open("expense_management.txt", ios::out);
									for (nodexpm* k = l.phead; k != NULL; k = k->pnext)
									{

										write_infoexpm(fileout, k->data);


									}
									fileout.close();
									reset_draw_main_table();
									xuli();
								}
						}


					}


				}
				
			}
			

			
}

void delete_by_postion() {
	list l; create_list_expm(l);
	ifstream  f;
	expm sv;
	f.open("expense_management.txt", ios::in);
	if (f.fail())
		cout << "Error file! " << endl;
	while (!f.eof())  //read into endfile.
	{
		expm sv;
		Read_1_SV(f, sv);
		nodexpm* p = create_node_expm(sv);
		add_node_expm_tail(l, p);
	}
	f.close(); int len_list = len(l);

	int postion, exit1 = 0,x,y;
	char s[15], s1[50] = " "; danhso(l);
	while (exit1 == 0)
	{

		if (ismouseclick(WM_MOUSEMOVE)) {
			getmouseclick(WM_MOUSEMOVE, x, y);

			if ((x >= 220 && x <= 380) && (y >= 70 && y <= 200))
			{
				setcolor(BLACK);
				outtextxy(220, 160, "VT:");
				setcolor(red);

				line(260, 140, 260, 200);
				rectangle(220, 140, 380, 200);
				setcolor(BLACK);
				Input(s, s1, 260, 160, ' ', 'z', 220, 140, 380, 200);
				strcpy(s1, s);
				postion = atoi(s);
				XoaNodeCoKhoaBatKy(l, postion);
				
				ofstream fileout; fileout.open("expense_management.txt", ios::out);
				for (nodexpm* k = l.phead; k != NULL; k = k->pnext)
				{
					
					write_infoexpm(fileout, k->data);
					
				}

				fileout.close();
			}
			
			else {
				setfillstyle(1, WHITE);
				bar(220, 140, 390, 210);
			}
			if (ismouseclick(WM_LBUTTONDOWN)) {
				getmouseclick(WM_LBUTTONDOWN, x, y);
				if ((x >= 1000 && x <= 1200) && (y >= 190 && y <= 250))
				{
					reset_draw_main_table();
					xuli();
					exit1 = 1;

				}
				else if ((x >= 50 && x <= 200) && (y >= 70 && y <= 140)) {
					cleardevice(); HomePageUIShow(); exit1 = 1;
				}
				else if ((x >= 50 && x <= 200) && (y >= 150 && y <= 240)) {
					cleardevice(); setbkcolor(WHITE);
					thongket(); exit1 = 1;
				}
			}
		}
	}


}

void draw_table() {
	setcolor(green);
	rectangle(550, 70, 1520, 220);
	for (int i = 100; i <= 220; i += 30) {
		line(550, i, 15200, i);
	}setbkcolor(WHITE);
	setcolor(BLUE);
	line(700, 70, 700, 220);
	outtextxy(560, 75, "Khoan Chi");
	outtextxy(560, 105, "Ghi Chu");
	outtextxy(560, 135, "Ngay");
	outtextxy(560, 165, "So Tien"); outtextxy(560, 195, "Vi Tri");
	setbkcolor(red);
	setfillstyle(1, red);
	setcolor(WHITE);
	bar(1200, 190, 1520, 250);
	rectangle(1200, 190, 1520, 250);
	settextstyle(9, 0, 4);
	outtextxy(1300, 210, "Them");
	setfillstyle(1, blue); bar(1000, 190, 1200, 250); setcolor(YELLOW);
	rectangle(1000, 190, 1200, 250);
	setbkcolor(blue); settextstyle(9, 0, 2);
	outtextxy(1010, 210, "LOAD-DATA");

}
void draw_button() {
	setbkcolor(WHITE);
	cleardevice();
	list l; create_list_expm(l);
	ifstream  f;
	expm sv;
	f.open("expense_management.txt", ios::in);
	if (f.fail())
		cout << "Error file! " << endl;
	while (!f.eof())  //read into endfile.
	{
		expm sv;
		Read_1_SV(f, sv);
		nodexpm* p = create_node_expm(sv);
		add_node_expm_tail(l, p);
	}
	f.close(); int len_list = len(l);
	
	danhso(l);
	setcolor(red);
	rectangle(220, 150, 380, 220); setcolor(BLUE);
	outtextxy(230, 190, "VT:");
	reset_draw_main_table();
	setbkcolor(green);
	setfillstyle(1, green);
	setcolor(WHITE);
	settextstyle(9, 0, 4);
	rectangle(0, 0, 1520, 50);
	bar(0, 0, 1520, 50);
	outtextxy(500, 10, "QUAN LI CHI TIEU");	settextstyle(9, 0, 2);
	draw_table(); setcolor(BLACK);
	outtextxy(1210, 765, "NEXT>>");
	int exit = 0;
	setfillstyle(1, green);
	setcolor(BLACK);
	rectangle(50, 70, 200, 140);
	bar(50, 70, 200, 140);
	setcolor(red);
	setbkcolor(green);
	settextstyle(9, 0, 3);
	outtextxy(60, 100, "<<BACK");
	
	setfillstyle(1, blue_d);
	setcolor(RED);
	rectangle(50, 150, 200, 240);
	bar(50,150, 200, 240);
	setbkcolor(blue_d);
	settextstyle(9, 0, 3);
	outtextxy(60, 180, "Thong Ke");
	// sua

	setfillstyle(1, yellow);
	setcolor(BLUE);
	rectangle(400, 150, 550, 240);
	bar(400, 150, 550, 240);
	setbkcolor(yellow);
	settextstyle(9, 0, 4);
	outtextxy(420, 180, "EDIT");
	setfillstyle(1, blue);
	bar(220, 70, 380, 140); setcolor(red);
	rectangle(220, 70, 380, 140);
	setcolor(yellow);
	setbkcolor(blue);
	settextstyle(9, 0, 1); settextstyle(9, 0, 5);
	outtextxy(255, 85, "Xoa");
	setfillstyle(1, red);

	bar(400, 70, 550, 140);
	setcolor(blue_A);
	rectangle(400, 70, 550, 140);
	setcolor(WHITE);
	setbkcolor(red);
	settextstyle(9, 0, 4);
	outtextxy(405, 90, "SapXep");
	setbkcolor(green);

	
	int x, y;
	xuli(); 
	input_listexpm();
	delete_by_postion();
}

void menuthree() {
	int x, y, exit = 0;
	
	draw_button();
	
	while (exit == 0) {
		if (ismouseclick(WM_LBUTTONDOWN)) {
			getmouseclick(WM_LBUTTONDOWN, x, y);
			if ((x >= 50 && x <= 200) && (y >= 70 && y <= 140)) {
				cleardevice(); HomePageUIShow(); exit = 1;
			}
		}
	}

}