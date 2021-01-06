#include"menu8.h"
// rent management contract
void draw_input_user() {
	setfillstyle(1, WHITE);
	bar(left1, top1, right1, bottom1);
	setcolor(red);
	rectangle(left1, top1, right1, bottom1 + 25);

	line(left1 + 255, top1, left1 + 255, bottom1 + 25);
	for (int i = 70; i < 295; i += 25) {
		line(left1, i, right1, i);
	}
	settextstyle(9, 0, 1);
	setcolor(BLUE); setbkcolor(WHITE);
	outtextxy(left1 + 10, 50, "Ho Ten");
	outtextxy(left1 + 10, 50 + 25, "Gioi Tinh");
	outtextxy(left1 + 10, 50 + 25 * 2, "Dia Chi Thuong Tru");
	outtextxy(left1 + 10, 50 + 25 * 3, "Phong");
	outtextxy(left1 + 10, 50 + 25 * 4, "Ngay Ki Hop Dong");
	outtextxy(left1 + 10, 50 + 25 * 5, "Ngay Het Han");
	outtextxy(left1 + 10, 50 + 25 * 6, "So DT");
	outtextxy(left1 + 10, 50 + 25 * 7, "CMND");
	outtextxy(left1 + 10, 50 + 25 * 8, "Ngay Sinh"); outtextxy(left1 + 10, 50 + 25 * 9, "Vi Tri");
	setfillstyle(1, blue_B);
	bar(right1, 225, right1 + 100, 50 + 25 * 9); setcolor(yellow); settextstyle(9, 0, 2); setbkcolor(blue_B); settextstyle(9, 0, 3);
	outtextxy(right1+10, 240, "Them");
	setcolor(RED);
	setfillstyle(1, green); bar(right1, 95, right1 + 100, 240 - 15); setbkcolor(green); setcolor(WHITE);
	rectangle(right1, 95, right1 + 100, 240 - 15);
	settextstyle(9, 0, 3); outtextxy((2 * right1 + 50) / 2 - 20, 90 + 50, "DATA"); settextstyle(9, 0, 4);

	rectangle(right1, 225, right1 + 100, 50 + 25 * 9); setcolor(BLACK);
	setfillstyle(1, red); rectangle(right1 + 130, 225, right1 + 230, 50 + 25 * 9);
	bar(right1 + 130, 225, right1 + 230, 50 + 25 * 9); setbkcolor(red); setcolor(WHITE);
	outtextxy(right1 + 150, 240, "Xoa"); setbkcolor(WHITE); settextstyle(9, 0, 3); setfillstyle(1, green);
	bar(right1 + 250, 225, right1 + 230 + 130, 50 + 25 * 9); setbkcolor(green); setcolor(WHITE); setcolor(YELLOW);
	rectangle(right1 + 250, 225, right1 + 230 + 130, 50 + 25 * 9);
	outtextxy((right1 + 250 + right1 + 230 + 130) / 2 - 30, 240, "IN"); setbkcolor(WHITE); settextstyle(9, 0, 1);
	setcolor(red);
	rectangle(right1 + 230 + 130, 225, right1 + 500, 50 + 25 * 9);
	setcolor(BLACK); 
	outtextxy(right1 + 365, 240, "VT:"); 
	setfillstyle(1, yellow);
	bar(right1 + 500+50, 225, right1 + 500 + 50+150, 275);
	setcolor(xinh2);
	rectangle(right1 + 500 + 50, 225, right1 + 500 + 50 + 150, 275); setcolor(xinh2); settextstyle(9, 0, 4); setbkcolor(yellow);
	outtextxy(right1 + 500 + 50 + 20, 240, "EDIT"); settextstyle(9, 0, 1);
	setbkcolor(WHITE);
}
void xuattheo_vitri(list_psh l, int start, int endt) {
	int i = 330, dem = 0, dem2 = 0, j = 0, dema = 0, demb = 0, demc = 0, demlist = 0; setbkcolor(WHITE);
	danhso(l); setcolor(red);
	setbkcolor(WHITE);
	settextstyle(3, 0, 1);
	for (node* k = l.phead; k != NULL; k = k->pnext)
	{
		dem++;
		dem2++;
		if (dem == start) {
			dem--;
			setcolor(BLACK);
			int y = KhoangCachNgay(k->data.ngayhethan);
			// tinh toan tinh trang
			if (y < 0) {
				setcolor(green);
				demc++;
			}
			if (y > 0) {
				setcolor(BLACK); dema++;
			}
			if (y <= -1 && y > -30) {
				setcolor(red);
				demb++;
			}

			demlist++;
			stringstream strsn;
			//printf pos
			strsn << k->data.pos;
			string temp_str1 = strsn.str();
			char* char_type = (char*)temp_str1.c_str();
			outtextxy(10, i, char_type);
			//printf id
			outtextxy(50, i, k->data.id);
			char* c = const_cast<char*>(k->data.name.c_str());
			outtextxy(130, i, c);
			outtextxy(300, i, k->data.sex);
			//printf sv.ngayki.day
			stringstream strs;
			strs << k->data.ngayki.day;
			string temp_str = strs.str();
			char* char_type1 = (char*)temp_str.c_str();
			outtextxy(380, i, char_type1);
			outtextxy(420, i, "/");
			//printf sv.ngay.month
			stringstream strs1;
			strs1 << k->data.ngayki.month;
			string m1 = strs1.str();
			char* char_type11 = (char*)m1.c_str();
			outtextxy(430, i, char_type11);
			outtextxy(460, i, "/");
			//printf sv.ngay.year
			stringstream strs2;
			strs2 << k->data.ngayki.year;
			string m2 = strs2.str();
			char* char_type2 = (char*)m2.c_str();
			outtextxy(470, i, char_type2);
			//printf sv.ngayhethan
			stringstream strsa;
			strsa << k->data.ngayhethan.day;
			string temp_stra = strsa.str();
			char* char_type12 = (char*)temp_stra.c_str();
			outtextxy(560, i, char_type12);
			outtextxy(590, i, "/");
			//printf sv.ngayhethan.month
			stringstream strsab;
			strsab << k->data.ngayhethan.month;
			string temp_strab = strsab.str();
			char* char_type12b = (char*)temp_strab.c_str();
			outtextxy(620, i, char_type12b);
			outtextxy(650, i, "/");
			//printf sv.ngayhethan.month
			stringstream strsabc;
			strsabc << k->data.ngayhethan.year;
			string temp_strabc = strsabc.str();
			char* char_type12bc = (char*)temp_strabc.c_str();
			outtextxy(670, i, char_type12bc);
			//tinh trang 
			stringstream ty; int y1 = abs(y); if (y1 == 0) y1 += 30;
			ty << y1;
			string temp_strabcc = ty.str();
			char* char_type12bcc = (char*)temp_strabcc.c_str();
			outtextxy(560 + 180 + 10, i, char_type12bcc);
			outtextxy(780, i, "Ngay");
			outtextxy(850, i, k->data.phone_number);
			outtextxy(1000, i, k->data.id_card);
			//printf sv.namsinh
			stringstream stru;
			stru << k->data.brith.day;
			string temp_stru = stru.str();
			char* char_type12u = (char*)temp_stru.c_str();
			outtextxy(1130, i, char_type12u);
			outtextxy(1160, i, "/");
			stringstream strut;
			strut << k->data.brith.month;
			string temp_strut = strut.str();
			char* char_type12ut = (char*)temp_strut.c_str();
			outtextxy(1180, i, char_type12ut);
			outtextxy(1200, i, "/");
			stringstream strup;
			strup << k->data.brith.year;
			string temp_strup = strup.str();
			char* char_type12up = (char*)temp_strup.c_str();
			outtextxy(1210, i, char_type12up);
			char* cb = const_cast<char*>(k->data.adress.c_str());
			outtextxy(1280, i, cb);
			//xong



			i += 25;
		}
		if (dem2 == endt) break;
	}
}
void input_statiscal() {
	void draw_statistical_box();
	void hoadon();
	list_psh l; create_list_psh_psh(l); psh sv;
	void 	main_table_menu8();
	void 	xuli_info();
	void timkiem_menu8();
	ifstream  f;
	f.open("rent management contract.txt", ios::in);
	if (f.fail())
		cout << "Error file! " << endl;
	while (!f.eof())  //read into endfile.
	{
		psh sv;
		read_1_infopsh(f, sv);
		node* p = create_node_psh(sv);
		add_node_psh_tail(l, p);
	}
	f.close();
	int len_list = len_8(l); int n = len_8(l);
	int exit = 0, x, y; int postion,flag1=0,flag11=0;
	setbkcolor(WHITE);
	danhso(l);
	date8 ngayki, ngayhethan;
	int xxx;
	while (exit != 1) {
		if (ismouseclick(WM_LBUTTONDOWN))
		{
			getmouseclick(WM_LBUTTONDOWN, x, y);
			if ((x >= left1 && x <= right1) && (y >= top1 && y <= 70))
			{
				setfillstyle(1, WHITE);
				bar(left1 + 260, 70, right1, 295);
				setcolor(red);
				rectangle(left1 + 255, top1 + 25, right1, 70 + 25);
				rectangle(left1 + 255, top1 + 25 * 2, right1, 70 + 25 * 2);
				rectangle(left1 + 255, top1 + 25 * 3, right1, 70 + 25 * 3);
				rectangle(left1 + 255, top1 + 25 * 3, right1, 70 + 25 * 3);
				rectangle(left1 + 255, top1 + 25 * 5, right1, 70 + 25 * 5);
				rectangle(left1 + 255, top1 + 25 * 6, right1, 70 + 25 * 6);
				rectangle(left1 + 255, top1 + 25 * 7, right1, 70 + 25 * 7);
				rectangle(left1 + 255, top1 + 25 * 8, right1, 70 + 25 * 8);
				rectangle(left1 + 255, top1 + 25 * 9, right1, 70 + 25 * 9);
				rectangle(left1+255, top1, right1, 70);

				char s[50], s1[50] = " ";
				setcolor(blue_B); rectangle(left1, top1, right1, 70);
				Input(s, s1, left1 + 260, 50, ' ', 'z', left1 + 260, 45, right1, 65); strcpy(s1, s);
				ofstream f; f.open("input_menu8.txt", ios::out);
				f << s << ","; f.close();

			}
			else if ((x >= left1 && x <= right1) && (y >= top1 + 25 && y <= 70 + 25))
			{
				char s1[50], s2[50] = " ";
				setcolor(YELLOW); rectangle(left1, top1 + 25, right1, 70 + 25); setcolor(green);
				Input(s1, s2, left1 + 260, 75, 'a', 'z', left1 + 260, 45 + 25, right1, 65 + 25);
				strcpy(s2, s1);
				ofstream f1; f1.open("input_menu8.txt", ios::out | ios::app);
				f1 << s1 << " " << ","; f1.close();
			}
			else if ((x >= left1 && x <= right1) && (y >= top1 + 25 * 2 && y <= 70 + 25 * 2))
			{
				char s2[50], s3[50] = " ";
				setcolor(BROWN); rectangle(left1, top1 + 25 * 2, right1, 70 + 25 * 2); setbkcolor(WHITE);
				setcolor(red);
				Input(s2, s3, left1 + 260, 100, ' ', 'z', left1 + 260, 45 + 25 * 2, right1, 65 + 25 * 2);
				strcpy(s3, s2);
				ofstream f2; f2.open("input_menu8.txt", ios::out | ios::app);
				f2 << s2 << " " << ","; f2.close();
			}
			else if ((x >= left1 && x <= right1) && (y >= top1 + 25 * 3 && y <= 70 + 25 * 3))
			{
				setfillstyle(1, WHITE);
				bar(left1 + 260, top1 + 25 * 3, right1, 70 + 25 * 3);
				char s21[50], s31[50] = " ";
				setcolor(LIGHTBLUE); rectangle(left1, top1 + 25 * 3, right1, 70 + 25 * 3); setcolor(LIGHTMAGENTA);
				Input(s21, s31, left1 + 260, 125, '0', '9', left1 + 260, 45 + 25 * 3, right1, 65 + 25 * 3);
				strcpy(s31, s21);
				int pp = atoi(s21);
				
				if (pp > 100) flag11 = 1;
				if (flag11 == 0) {
					ofstream f3; f3.open("input_menu8.txt", ios::out | ios::app);
					f3 << s21 << " " << ","; f3.close();
				}
			}
			else if ((x >= left1 && x <= right1) && (y >= top1 + 25 * 4 && y <= 70 + 25 * 4))
			{
				//setfillstyle(1, WHITE);
				//ngay ki
				if (flag11 ==1) {
					setfillstyle(1, WHITE);
					bar(left1 + 260, top1 + 25 * 3, right1, 70 + 25 * 3); 
					setcolor(LIGHTBLUE); rectangle(left1+260, top1 + 25 * 3, right1, 70 + 25 * 3);
					setcolor(red);
					outtextxy(left1 + 270, 125, "!Phong<100"); flag11 = 0;
				}
				else {
					char s3[50], s4[50] = " ";
					setcolor(LIGHTMAGENTA); rectangle(left1, top1 + 25 * 4, right1, 70 + 25 * 4); setcolor(LIGHTRED);
					Input(s3, s4, left1 + 260, 150, '/', '9', left1 + 260, 45 + 25 * 4, right1, 65 + 25 * 4);
					strcpy(s4, s3);
					ofstream f; f.open("try.txt", ios::out);
					f << s3; f.close();
					ofstream f4; f4.open("input_menu8.txt", ios::out | ios::app);
					f4 << s3 << ","; f4.close();
				}
			}
			else if ((x >= left1 && x <= right1) && (y >= top1 + 25 * 5 && y <= 70 + 25 * 5))
			{//ngay het han
				setfillstyle(1, WHITE);
				bar(left1+257, top1 + 25 * 5, right1, 70 + 25 * 5);
				char s4[50], s5[50] = " ";
				setcolor(BLUE); rectangle(left1, top1 + 25 * 5, right1, 70 + 25 * 5); setcolor(LIGHTGREEN);
				Input(s4, s5, left1 + 260, 175, '/', '9', left1 + 260, 45 + 25 * 5, right1, 70 + 25 * 5);
				strcpy(s5, s4);
				ofstream f; f.open("sv-khoanchi.txt", ios::out);
				f << s4;
				if(flag1==0)
				{
					ofstream f5; f5.open("input_menu8.txt", ios::out | ios::app);
					f5 << s4 << ","; f5.close();
				}
			}
			else if ((x >= left1 && x <= right1) && (y >= top1 + 25 * 6 && y <= 70 + 25 * 6))
			{
				
				ifstream fe; fe.open("try.txt", ios::in);
				Readdate8_expm(fe, ngayki);
				ifstream fh; fh.open("sv-khoanchi.txt", ios::in);
				Readdate8_expm(fh, ngayhethan);
				
				int mt = KhoangCachNgay(ngayhethan);
				int nn = KhoangCachNgay(ngayki);

				if (mt > nn) flag1 = 1; fe.close();
			
				if (flag1 == 1)
				{
					setfillstyle(1, WHITE);
					bar(left1 + 255, top1 + 25 * 5, right1, 70 + 25 * 5);
					setcolor(BLUE); rectangle(left1 + 255, top1 + 25 * 5, right1, 70 + 25 * 5); setcolor(RED);
					outtextxy(left1 + 260 + 20, 175, "Ngay het han phai lon hon ngay ki !"); flag1 = 0;
				}
				else {
					char s5[50], s6[50] = " ";
					setcolor(GREEN); rectangle(left1, top1 + 25 * 6, right1, 70 + 25 * 6); setcolor(blue_B);
					Input(s5, s6, left1 + 260, 200, '0', '9', left1 + 260, 45 + 25 * 6, right1, 70 + 25 * 6);
					strcpy(s6, s5);
					ofstream f6; f6.open("input_menu8.txt", ios::out | ios::app);
					f6 << s5 << " " << ","; f6.close();
				}
			}
			else if ((x >= left1 && x <= right1) && (y >= top1 + 25 * 7 && y <= 70 + 25 * 7))
			{
				char s51[50], s61[50] = " ";
				setcolor(BLUE); rectangle(left1, top1 + 25 * 7, right1, 70 + 25 * 7); setcolor(green);
				Input(s51, s61, left1 + 260, 225, '0 ', '9', left1 + 260, 45 + 25 * 7, right1, 70 + 25 * 7);
				strcpy(s61, s51);
				ofstream f7; f7.open("input_menu8.txt", ios::out | ios::app);
				f7 << s51 << " " << ","; f7.close();
			}
			else if ((x >= left1 && x <= right1) && (y >= top1 + 25 * 8 && y <= 70 + 25 * 8))
			{
				char s6[50], s7[50] = " ";
				setcolor(BLACK); rectangle(left1, top1 + 25 * 8, right1, 70 + 25 * 8); setcolor(blue);
				Input(s6, s7, left1 + 260, 250, '/ ', '9', left1 + 260, 45 + 25 * 8, right1, 70 + 25 * 8);
				strcpy(s7, s6);
				ofstream f8; f8.open("input_menu8.txt", ios::out | ios::app);
				f8 << s6 << ","; f8.close();

			}
			else if ((x >= left1 && x <= right1) && (y >= top1 + 25 * 9 && y <= 70 + 25 * 9))
			{
				char s7[50], s8[50] = " ";
				setcolor(LIGHTCYAN); rectangle(left1, top1 + 25 * 9, right1, 70 + 25 * 9); setcolor(DARKGRAY);
				Input(s7, s8, left1 + 260, 275, '0', '9', left1 + 260, 45 + 25 * 9, right1, 70 + 25 * 9);
				strcpy(s8, s7); 
				ofstream fk; fk.open("try.txt", ios::out);
				fk << s7;
				ofstream f9; f9.open("input_menu8.txt", ios::out | ios::app);
				f9 << s7; f9.close();
				
			}
			else if ((x >= 10 && x <= 125) && (y >= 0 && y <= 40))
			{
				cleardevice(); HomePageUIShow();
				exit = 1;
			}
			else if ((x >= right1 && x <= right1 + 100) && (y >= 225 && y <= 275)) {
				settextstyle(9, 0, 0); setcolor(RED);
				outtextxy(right1 + 20, 50, "^_^");
				ifstream ft; ft.open("try.txt", ios::in);
				ft >> postion;
				ifstream f; f.open("input_menu8.txt", ios::in);
				read_1_infopsh(f, sv);
				node* p = create_node_psh(sv);
				ThemNode_p_VaoViTriBatKi(l, p, postion, n);
				ofstream fk;
				fk.open("rent management contract.txt", ios::out);
				for (node* k = l.phead; k != NULL; k = k->pnext)
				{

					write_info_to_listpsh(fk, k->data);

				}fk.close();
				draw_input_user();
				main_table_menu8();
				xuli_info();


			}
			else if ((x >= right1 && x <= right1 + 100) && y >= 95 && y <= 225) {
				exit = 1;

			}
			else if ((x >= right1 + 250 && x <= right1 + 360) && (y >= 225 && y <= 275)) {

			hoadon();
					}
			else if ((x>=right1+360&&x<=right1+500)&&(y>=225&&y<=275)) {
			setfillstyle(1, WHITE);
			bar(right1 + 230 + 130, 225, right1 + 500, 50 + 25 * 9);
			setcolor(LIGHTBLUE);
			rectangle(right1 + 230 + 130, 225, right1 + 500, 50 + 25 * 9);
			setcolor(BLACK);
			setbkcolor(WHITE);

			char t[50], t1[50] = " "; settextstyle(9, 0, 2);
			Input(t, t1, right1 + 450, 240, '0', '9', right1 + 360, 225, right1 + 500, 50 + 25 * 9);
			strcpy(t1, t);
			postion = atoi(t);
			
			XoaNodeCoKhoaBatKy(l, postion);
			ofstream fk;
			fk.open("rent management contract.txt", ios::out);
			for (node* k = l.phead; k != NULL; k = k->pnext)
			{

				write_info_to_listpsh(fk, k->data);

			}fk.close();
			draw_input_user();
			main_table_menu8(); draw_statistical_box();
			xuli_info();
			}
			else if ((x >= 1100 && x <= 1300) && (y >= 0 && y <= 40)) {
			timkiem_menu8();
					}
			else if ((x>= right1 + 500 + 50&&x<= right1 + 500 + 50 + 150)&&(y>=225&&y<=275)) {
			setfillstyle(1, red);
			bar(right1 + 500 + 50, 225, right1 + 500 + 50 + 150, 275);
			setcolor(BLACK);
			rectangle(right1 + 500 + 50, 225, right1 + 500 + 50 + 150, 275); setcolor(WHITE); settextstyle(9, 0, 4); setbkcolor(red);
			outtextxy(right1 + 500 + 50 + 20, 240, "EDIT"); settextstyle(9, 0, 1);
			setbkcolor(WHITE);
			ifstream ft; ft.open("try.txt", ios::in);
			ft >> postion; ft.close();

			edit_by_postion_8(l, postion);
			ofstream fk;
			fk.open("rent management contract.txt", ios::out);
			for (node* k = l.phead; k != NULL; k = k->pnext)
			{

				write_info_to_listpsh(fk, k->data);

			}fk.close();
			draw_input_user();
			main_table_menu8();
			xuli_info();
			}
			else {
				setcolor(RED); rectangle(left1, top1, right1, 70); rectangle(left1, top1 + 25, right1, 70 + 25);
				rectangle(left1, top1 + 25 * 2, right1, 70 + 25 * 2); rectangle(left1, top1 + 25 * 3, right1, 70 + 25 * 3);
				rectangle(left1, top1 + 25 * 4, right1, 70 + 25 * 4);
				rectangle(left1, top1 + 25 * 5, right1, 70 + 25 * 5); rectangle(left1, top1 + 25 * 6, right1, 70 + 25 * 6);
				rectangle(left1, top1 + 25 * 7, right1, 70 + 25 * 7);
				rectangle(left1, top1 + 25 * 8, right1, 70 + 25 * 8); rectangle(left1, top1 + 25 * 9, right1, 70 + 25 * 9);

			}

		}
		if (kbhit()) {
			char key = getch();
			if (key == 59) {
				cleardevice(); HomePageUIShow();
				exit = 1;
			}
		}
	}
}
void tinhngay_hethan(list_psh l) {

	
	 int x, y, exit = 0, demlist = 0, j = 0, dem = 0, dema = 0, demb = 0, demc = 0;
	int exit1 = 0;
	
	int len_list = len_8(l); int i = 330;
	danhso(l); setcolor(red); dem = danhso(l);
	setbkcolor(WHITE);
	settextstyle(3, 0, 1);
	for (node* k = l.phead; k != NULL; k = k->pnext)
	{
		int y = KhoangCachNgay(k->data.ngayhethan);
		// tinh toan tinh trang
		if ((y<0)&&(y>-1)||(y<-30)) {
			setcolor(green);
			demc++;
		}

		if (y > 0) {
			setcolor(BLACK); dema++;
		}
		if (y <= -1 && y >=-30) {
			setcolor(red);
			demb++;
		}

	}
	setcolor(red);
	//hop dong con han
	stringstream strupc;
	strupc << demc+1;
	string temp_strupc = strupc.str();
	char* char_type12upc = (char*)temp_strupc.c_str();
	outtextxy(1230, 125, char_type12upc);
	//fix lai
	//hopdong gan het han
	stringstream strupcb;
	strupcb << demb;
	string temp_strupcb = strupcb.str();
	char* char_type12upcb = (char*)temp_strupcb.c_str();
	outtextxy(1230, 150, char_type12upcb);
	//tong so hop dong het han
	stringstream strupct;
	strupct << dema;
	string temp_strupct = strupct.str();
	char* char_type12upct = (char*)temp_strupct.c_str();
	outtextxy(1230, 175, char_type12upct);
	//tong so hop dong 
	stringstream strupcr;
	strupcr << dem-1 ;
	string temp_strupcr = strupcr.str();
	char* char_type12upcr = (char*)temp_strupcr.c_str();
	outtextxy(1230, 200, char_type12upcr);
	
}
void timkiem_menu8() {
	cleardevice();
	setbkcolor(WHITE);
	void 	menu_chinh();
	void main_table_menu8();
	int x, y, exit = 0, demlist = 0, j = 0, dem = 0, dema = 0, demb = 0, demc = 0;;
	list_psh l; create_list_psh_psh(l); psh sv; ifstream  f;
	f.open("rent management contract.txt", ios::in);
	if (f.fail())
		cout << "Error file! " << endl;
	while (!f.eof())  //read into endfile.
	{
		psh sv;
		read_1_infopsh(f, sv);
		node* p = create_node_psh(sv);
		add_node_psh_tail(l, p);
	}
	f.close();
	setfillstyle(3, blue_d);
	bar(0, 0, 1520, 850);	main_table_menu8();
	setfillstyle(1, blue_B);
	setcolor(WHITE); setbkcolor(blue_B);
	bar(0, 0, 1520, 40);
	settextstyle(9, 0, 4);
	outtextxy(1520 / 2-300, 5, "Tim Kiem Phong "); settextstyle(9, 0, 3);
	setfillstyle(1, yellow); setcolor(red); setbkcolor(yellow);
	bar(0, 0, 130, 40); outtextxy(10, 10, "<BACK"); setcolor(RED); settextstyle(9, 0, 5);// settextjustify(0, 1);
	rectangle(0, 0, 130, 40);
	setfillstyle(1, red);
	bar(100, 100, 450, 150);
	setcolor(yellow); setbkcolor(red);
	rectangle(100, 100, 450, 150);
	setcolor(WHITE);
	outtextxy(110, 105, "Nhap Phong:"); settextstyle(9, 0, 3);
	setcolor(GREEN);
	rectangle(450, 100, 800, 150); setcolor(WHITE);

	while (exit == 0)
	{
		if (ismouseclick(WM_LBUTTONDOWN)) {
			getmouseclick(WM_LBUTTONDOWN, x, y);
			if ((x >= 0 && x <= 130) && (y >= 0 && y <= 40)) {
				exit = 1; setbkcolor(WHITE); 
				menu_chinh();

			}
			else if ((x>=450&&x<=800)&&(y>=100&&y<=150)) {
				settextstyle(9, 0, 4);
				setfillstyle(1, WHITE);
				bar(450, 100, 800, 150);
				setcolor(yellow);
				rectangle(450, 100, 800, 150); setcolor(red);
				setbkcolor(WHITE);
				char s[50], s1[50] = " ";
				Input(s, s1, 500, 110, ' ', 'z', 450, 100, 800, 150);
				strcpy(s1, s); int i = 330;
				int pos = atoi(s);
				setbkcolor(WHITE); settextstyle(11, 0, 4); danhso(l);
				main_table_menu8();
				for (node* k = l.phead; k != NULL; k = k->pnext)
				{
					int poss = atoi(k->data.id);
					
					if (pos==poss) {
						int y = KhoangCachNgay(k->data.ngayhethan);
						// tinh toan tinh trang
						if (y < 0) {
							setcolor(green);
							demc++;
						}

						if (y > 0) {
							setcolor(BLACK); dema++;
						}
						if (y <= -1 && y > -30) {
							setcolor(red);
							demb++;
						}

						demlist++;
						stringstream strsn;
						//printf pos
						strsn << k->data.pos;
						string temp_str1 = strsn.str();
						char* char_type = (char*)temp_str1.c_str();
						outtextxy(10, i, char_type);
						//printf id
						outtextxy(50, i, k->data.id);
						char* c = const_cast<char*>(k->data.name.c_str());
						outtextxy(130, i, c);
						outtextxy(300, i, k->data.sex);
						//printf sv.ngayki.day
						stringstream strs;
						strs << k->data.ngayki.day;
						string temp_str = strs.str();
						char* char_type1 = (char*)temp_str.c_str();
						outtextxy(380, i, char_type1);
						outtextxy(420, i, "/");
						//printf sv.ngay.month
						stringstream strs1;
						strs1 << k->data.ngayki.month;
						string m1 = strs1.str();
						char* char_type11 = (char*)m1.c_str();
						outtextxy(430, i, char_type11);
						outtextxy(460, i, "/");
						//printf sv.ngay.year
						stringstream strs2;
						strs2 << k->data.ngayki.year;
						string m2 = strs2.str();
						char* char_type2 = (char*)m2.c_str();
						outtextxy(470, i, char_type2);
						//printf sv.ngayhethan
						stringstream strsa;
						strsa << k->data.ngayhethan.day;
						string temp_stra = strsa.str();
						char* char_type12 = (char*)temp_stra.c_str();
						outtextxy(560, i, char_type12);
						outtextxy(590, i, "/");
						//printf sv.ngayhethan.month
						stringstream strsab;
						strsab << k->data.ngayhethan.month;
						string temp_strab = strsab.str();
						char* char_type12b = (char*)temp_strab.c_str();
						outtextxy(620, i, char_type12b);
						outtextxy(650, i, "/");
						//printf sv.ngayhethan.month
						stringstream strsabc;
						strsabc << k->data.ngayhethan.year;
						string temp_strabc = strsabc.str();
						char* char_type12bc = (char*)temp_strabc.c_str();
						outtextxy(670, i, char_type12bc);
						//tinh trang 
						stringstream ty; int y1 = abs(y); if (y1 == 0) y1 += 30;
						ty << y1;
						string temp_strabcc = ty.str();
						char* char_type12bcc = (char*)temp_strabcc.c_str();
						outtextxy(560 + 180 + 10, i, char_type12bcc);
						outtextxy(780, i, "Ngay");
						outtextxy(850, i, k->data.phone_number);
						outtextxy(1000, i, k->data.id_card);
						//printf sv.namsinh
						stringstream stru;
						stru << k->data.brith.day;
						string temp_stru = stru.str();
						char* char_type12u = (char*)temp_stru.c_str();
						outtextxy(1130, i, char_type12u);
						outtextxy(1160, i, "/");
						stringstream strut;
						strut << k->data.brith.month;
						string temp_strut = strut.str();
						char* char_type12ut = (char*)temp_strut.c_str();
						outtextxy(1180, i, char_type12ut);
						outtextxy(1200, i, "/");
						stringstream strup;
						strup << k->data.brith.year;
						string temp_strup = strup.str();
						char* char_type12up = (char*)temp_strup.c_str();
						outtextxy(1210, i, char_type12up);
						char* cb = const_cast<char*>(k->data.adress.c_str());
						outtextxy(1280, i, cb);
						i += 25;
					}
				
				}
				
			}
		}
	}
}
void xuli_info() {
	void main_table_menu8();
	void draw_statistical_box();
	void hoadon();
	list_psh l; create_list_psh_psh(l); psh sv;
	ifstream  f; int x, y, exit = 0, demlist = 0, j = 0, dem = 0, dema = 0, demb = 0, demc = 0;
	int exit1 = 0;
	f.open("rent management contract.txt", ios::in);
	if (f.fail())
		cout << "Error file! " << endl;
	while (!f.eof())  //read into endfile.
	{
		psh sv;
		read_1_infopsh(f, sv);
		node* p = create_node_psh(sv);
		add_node_psh_tail(l, p);
	}
	f.close();
	int len_list = len_8(l); int i = 330;
	danhso(l); setcolor(red); dem = danhso(l);
	setbkcolor(WHITE);
	settextstyle(3, 0, 1);
	tinhngay_hethan(l);
	int postion;
	for (node* k = l.phead; k != NULL; k = k->pnext)
	{
		int y = KhoangCachNgay(k->data.ngayhethan);
		// tinh toan tinh trang
		if (y < 0) {
			setcolor(green);
			demc++;
		}

		if (y > 0) {
			setcolor(BLACK); dema++;
		}
		if (y <= -1 && y >-30) {
			setcolor(red);
			demb++;
		}

		demlist++;
		stringstream strsn;
		//printf pos
		strsn << k->data.pos;
		string temp_str1 = strsn.str();
		char* char_type = (char*)temp_str1.c_str();
		outtextxy(10, i, char_type);
		//printf id
		outtextxy(50, i, k->data.id);
		char* c = const_cast<char*>(k->data.name.c_str());
		outtextxy(130, i, c);
		outtextxy(300, i, k->data.sex);
		//printf sv.ngayki.day
		stringstream strs;
		strs << k->data.ngayki.day;
		string temp_str = strs.str();
		char* char_type1 = (char*)temp_str.c_str();
		outtextxy(380, i, char_type1);
		outtextxy(420, i, "/");
		//printf sv.ngay.month
		stringstream strs1;
		strs1 << k->data.ngayki.month;
		string m1 = strs1.str();
		char* char_type11 = (char*)m1.c_str();
		outtextxy(430, i, char_type11);
		outtextxy(460, i, "/");
		//printf sv.ngay.year
		stringstream strs2;
		strs2 << k->data.ngayki.year;
		string m2 = strs2.str();
		char* char_type2 = (char*)m2.c_str();
		outtextxy(470, i, char_type2);
		//printf sv.ngayhethan
		stringstream strsa;
		strsa << k->data.ngayhethan.day;
		string temp_stra = strsa.str();
		char* char_type12 = (char*)temp_stra.c_str();
		outtextxy(560, i, char_type12);
		outtextxy(590, i, "/");
		//printf sv.ngayhethan.month
		stringstream strsab;
		strsab << k->data.ngayhethan.month;
		string temp_strab = strsab.str();
		char* char_type12b = (char*)temp_strab.c_str();
		outtextxy(620, i, char_type12b);
		outtextxy(650, i, "/");
		//printf sv.ngayhethan.month
		stringstream strsabc;
		strsabc << k->data.ngayhethan.year;
		string temp_strabc = strsabc.str();
		char* char_type12bc = (char*)temp_strabc.c_str();
		outtextxy(670, i, char_type12bc);
		//tinh trang 
		stringstream ty; int y1 = abs(y); if (y1 == 0) y1 += 30;
		ty << y1;
		string temp_strabcc = ty.str();
		char* char_type12bcc = (char*)temp_strabcc.c_str();
		outtextxy(560 + 180 + 10, i, char_type12bcc);
		outtextxy(780, i, "Ngay");
		outtextxy(850, i, k->data.phone_number);
		outtextxy(1000, i, k->data.id_card);
		//printf sv.namsinh
		stringstream stru;
		stru << k->data.brith.day;
		string temp_stru = stru.str();
		char* char_type12u = (char*)temp_stru.c_str();
		outtextxy(1130, i, char_type12u);
		outtextxy(1160, i, "/");
		stringstream strut;
		strut << k->data.brith.month;
		string temp_strut = strut.str();
		char* char_type12ut = (char*)temp_strut.c_str();
		outtextxy(1180, i, char_type12ut);
		outtextxy(1200, i, "/");
		stringstream strup;
		strup << k->data.brith.year;
		string temp_strup = strup.str();
		char* char_type12up = (char*)temp_strup.c_str();
		outtextxy(1210, i, char_type12up);
		char* cb = const_cast<char*>(k->data.adress.c_str());
		outtextxy(1280, i, cb);
		i += 25;
	
		if (i > 750) {

			while (exit == 0 )
			{
				if (ismouseclick(WM_LBUTTONDOWN))
				{
					getmouseclick(WM_LBUTTONDOWN, x, y);
					if ((x >= 10 && x <= 125) && (y >= 0 && y <= 40))
					{
						cleardevice(); HomePageUIShow();
						exit = 1;
					}
					else if ((x >= right1 + 360 && x <= right1 + 500) && (y >= 225 && y <= 275)) {
						exit = 1; input_statiscal();
					}
					else if ((x>=right1+250&&x<=right1+360)&&(y>=225&&y<=275)) {

						hoadon();
					}
					else if ((x >= left1 && x <= right1) && (y >= top1 && y <= 70))
					{
						exit = 1; input_statiscal();

					}
					else if ((x >= right1 + 360 && x <= right1 + 500) && (y >= 225 && y <= 275)) {
						setfillstyle(1, WHITE);
						bar(right1 + 230 + 130, 225, right1 + 500, 50 + 25 * 9);
						setcolor(LIGHTBLUE);
						rectangle(right1 + 230 + 130, 225, right1 + 500, 50 + 25 * 9);
						setcolor(BLACK);
						setbkcolor(WHITE);

						char t[50], t1[50] = " "; settextstyle(9, 0, 2);
						Input(t, t1, right1 + 450, 240, '0', '9', right1 + 360, 225, right1 + 500, 50 + 25 * 9);
						strcpy(t1, t);
						postion = atoi(t);

						XoaNodeCoKhoaBatKy(l, postion);
						ofstream fk;
						fk.open("rent management contract.txt", ios::out);
						for (node* k = l.phead; k != NULL; k = k->pnext)
						{

							write_info_to_listpsh(fk, k->data);

						}fk.close();
						draw_input_user();
						main_table_menu8(); draw_statistical_box();
						xuli_info();
					}
					else if ((x >= right1 + 500 + 50 && x <= right1 + 500 + 50 + 150) && (y >= 225 && y <= 275)) {
						setfillstyle(1, red);
						bar(right1 + 500 + 50, 225, right1 + 500 + 50 + 150, 275);
						setcolor(BLACK);
						rectangle(right1 + 500 + 50, 225, right1 + 500 + 50 + 150, 275); setcolor(WHITE); settextstyle(9, 0, 4); setbkcolor(red);
						outtextxy(right1 + 500 + 50 + 20, 240, "EDIT"); settextstyle(9, 0, 1);
						setbkcolor(WHITE);
						ifstream ft; ft.open("try.txt", ios::in);
						ft >> postion; ft.close();

						edit_by_postion_8(l, postion);
						ofstream fk;
						fk.open("rent management contract.txt", ios::out);
						for (node* k = l.phead; k != NULL; k = k->pnext)
						{

							write_info_to_listpsh(fk, k->data);

						}fk.close();
						draw_input_user();
						main_table_menu8();
						xuli_info();
					}
					else if ((x>= right1 + 500 + 50&&x<= right1 + 500 + 50 + 150)&&(y>=225&&y<=275)) {
			setfillstyle(1, red);
			bar(right1 + 500 + 50, 225, right1 + 500 + 50 + 150, 275);
			setcolor(BLACK);
			rectangle(right1 + 500 + 50, 225, right1 + 500 + 50 + 150, 275); setcolor(WHITE); settextstyle(9, 0, 4); setbkcolor(red);
			outtextxy(right1 + 500 + 50 + 20, 240, "EDIT"); settextstyle(9, 0, 1);
			setbkcolor(WHITE);

			}
					else if ((x >= 1380 && x <= 1500) && (y >= 760 && y <= 800)) {
						i = 330;
						main_table_menu8();
						xuattheo_vitri(l, demlist + 1, demlist + 17);
						demlist += 17;
						if (demlist > 15) {
							settextstyle(9, 0, 2);
							setcolor(BLACK); setbkcolor(green);
							setfillstyle(1, green); bar(1180, 760, 1300, 800);
							setcolor(red); rectangle(1180, 760, 1300, 800); setcolor(WHITE);
							outtextxy(1187, 770, "<<PREV");
							settextstyle(9, 0, 1); setcolor(BLACK);
						}
						setbkcolor(WHITE);
					}
					else if ((x >= 1180 && x <= 1300) && (y >= 760 && y <= 800)) {

						demlist = demlist - 17;
						i = 330;
						main_table_menu8();
						xuattheo_vitri(l, demlist - 16, demlist);
						setbkcolor(WHITE);

					}
					else if ((x>=1100&&x<=1300)&&(y>=0&&y<=40)) {
						timkiem_menu8();
					}
				}
				if (kbhit()) {
					char key = getch();
					if (key == 59) {
						cleardevice(); HomePageUIShow();
						exit = 1;
					}
				}
			}
		}
	}
	setcolor(red);
	
}
void draw_statistical_box() {
	setfillstyle(1, WHITE);
	bar(right1 + 100, top1 + 25 * 2, 1380 - 100, bottom1 - 25 * 2);
	setcolor(blue_A);
	rectangle(right1 + 100, top1 + 25 * 2, 1380 - 100, bottom1 - 25 * 2);
	rectangle(right1 + 100, top1, 1280, 70);
	setcolor(BLACK);
	outtextxy(right1 + 110, 50, "So Ngay Bao Truoc Han");
	setcolor(red);
	outtextxy(1380 - 150, 50, "30");
	for (int i = 70 + 25 * 2; i < 270 - 25 * 2; i += 25) {
		line(right1 + 100, i, 1280, i);
	}
	line(1280 - 100, 45, 1180, 70);
	line(1280 - 100, 70 + 25, 1280 - 100, bottom1 - 25 * 2);
	setfillstyle(1, BLUE); setcolor(WHITE);
	bar(right1 + 100, 70 + 25, 1280, 70 + 25 * 2); setbkcolor(BLUE);
	outtextxy(right1 + 200, 50 + 25 * 2, "Thong Ke Hop Dong");
	setbkcolor(WHITE); setcolor(BLACK);
	outtextxy(right1 + 110, 50 + 25 * 3, "Tong So Hop Dong Con Han");
	outtextxy(right1 + 110, 50 + 25 * 4, "Tong So Hop Dong Gan Het Han");
	outtextxy(right1 + 110, 50 + 25 * 5, "Tong So Hop Dong Het Han");
	outtextxy(right1 + 110, 50 + 25 * 6, "Tong So Hop Dong");
}
void main_table_menu8() {
	setfillstyle(1, WHITE);
	bar(0, 325, 1520, 750);
	setfillstyle(3, blue_B);
	bar(0, 300, 1520, 325);
	rectangle(0, 300, 1520, 750); setcolor(LIGHTMAGENTA);
	for (int i = 325; i < 750; i += 25) {
		line(0, i, 1520, i);
	}
	line(45, 305, 45, 750); line(120, 305, 120, 750);
	line(280, 305, 280, 750); line(360, 305, 360, 750);
	line(460 + 70, 305, 460 + 70, 750); line(565 + 180, 305, 565 + 180, 750); line(660 + 180, 305, 660 + 180, 750); line(800 + 180, 305, 800 + 180, 750);
	line(940 + 180, 305, 940 + 180, 750);
	line(1070 + 180 + 20, 305, 1070 + 180 + 20, 750);
	setcolor(red);
	outtextxy(0, 305, "STT"); outtextxy(50, 305, "Phong"); outtextxy(160, 305, "Ho Ten");
	outtextxy(300, 305, "GT"); outtextxy(370 + 20, 305, "NgayKi"); outtextxy(470 + 90, 305, "Ngay Het Han"); outtextxy(560 + 180, 305, "TinhTrang");
	outtextxy(690 + 180, 305, "SODT");
	outtextxy(820 + 180, 305, "CMND"); outtextxy(950 + 180, 305, "NamSinh");
	outtextxy(1250 + 20, 305, "Dia Chi Thuong Tru");

}

void menu8() {

	int exit = 0, x, y;
	void hoadon(); settextstyle(9, 0, 1);
	setbkcolor(green);
	draw_input_user();
	draw_statistical_box();
	setbkcolor(green);
	setfillstyle(1, green); setcolor(WHITE);
	settextstyle(9, 0, 3);
	bar(0, 0, 1520, 40); outtextxy(300, 10, "QUAN LI HOP DONG NGUOI THUE TRO");
	setfillstyle(1, yellow); setcolor(BLACK);
	setbkcolor(yellow); settextstyle(9, 0, 1);
	main_table_menu8(); setbkcolor(YELLOW);
	bar(10, 0, 125, 40); outtextxy(19, 5, "<BACK");
	setfillstyle(1, red);
	bar(1100, 0, 1300, 40);
	setcolor(yellow);
	rectangle(1100, 0, 1300, 40); settextstyle(9, 0, 4); setcolor(WHITE); setbkcolor(red);
	outtextxy(1120, 5, "SEARCH");
	setfillstyle(1, blue_B); settextstyle(9, 0, 1);
	setcolor(yellow);
	bar(1380, 760, 1500, 800); rectangle(1380, 760, 1500, 800); setbkcolor(blue_B);
	outtextxy(1400, 770, "NEXT>>");
	
	xuli_info();
	input_statiscal();
	settextstyle(9, 0, 1);
	while (exit == 0) {
		if (ismouseclick(WM_LBUTTONDOWN)) {

			getmouseclick(WM_LBUTTONDOWN, x, y);
			if ((x >= 10 && x <= 125) && (y >= 0 && y <= 40))
			{
				cleardevice(); HomePageUIShow();
				exit = 1;
			}
			else if ((x >= right1 + 250 && x <= (right1 + 230 + 130)) && (y >= 225 && y <= 50 + 25 * 9)) {
				exit = 1; setbkcolor(WHITE);
				hoadon();
			}
		}
	}

}
void conghoa_xahoi(string se, char m[50], string t, char phone[20], char room[50], date8 ngayhethan, date8 ngayki) {
	ifstream f; f.open("hostel_information.txt", ios::in);
	string s, adress, phone_number;
	char electric[50], water[50], water1[50], car_manage[50], clean[50], cabletv[50], roomcost[50], internet[50];
	getline(f, s, ',');
	f.seekg(1, 1);
	getline(f, adress, ',');
	f.seekg(1, 1);
	getline(f, phone_number, ',');
	f.seekg(1, 1); f.close();
	ifstream fo; fo.open("unit_price.txt", ios::in);
	fo >> electric;
	fo.seekg(1, 1);
	fo >> water;
	fo.seekg(1, 1);
	fo >> water1;
	fo.seekg(1, 1);
	fo >> car_manage;
	fo.seekg(1, 1);
	fo >> clean;
	fo.seekg(1, 1);
	fo >> cabletv;
	fo.seekg(1, 1);
	fo >> internet;
	fo.seekg(1, 1);
	fo >> roomcost; fo.close();
	setbkcolor(WHITE); setcolor(BLACK);
	settextstyle(9, 0, 1);
	int n = getmaxx() / 2, y = getmaxy() / 2;
	setfillstyle(7, blue_d);
	bar(0, 89, 1520, 850);
	outtextxy(600, 100, "Cong Hoa Xa Hoi Chu Nghia Viet Nam");
	settextstyle(3, 0, 1);
	outtextxy(650, 120, "Doc Lap-Tu Do-Hanh Phuc"); settextstyle(9, 0, 4);
	outtextxy(500, 140, "Hop Dong Thue Phong Tro"); settextstyle(9, 0, 1);
	outtextxy(1000, 180, "Tp HCM,ngay");
	//time and days
	setbkcolor(WHITE); setcolor(red);
	time_t hientai = time(0);
	tm* ltm = localtime(&hientai);
	//printf day
	stringstream strs1;
	strs1 << ltm->tm_mday;
	string m1 = strs1.str();
	char* char_type1 = (char*)m1.c_str();
	outtextxy(1200, 180, char_type1); outtextxy(1240, 180, "/");
	//printf month
	stringstream strs2;
	strs2 << ltm->tm_mon + 1;
	string m2 = strs2.str();
	char* char_type2 = (char*)m2.c_str();
	outtextxy(1260, 180, char_type2); outtextxy(1280, 180, "/");
	//printf years
	stringstream strs3;
	strs3 << ltm->tm_year + 1900;
	string m3 = strs3.str();
	char* char_type3 = (char*)m3.c_str();
	outtextxy(1310, 180, char_type3);
	setcolor(BLACK); settextstyle(9, 0, 1);

	outtextxy(50, 190, "Chung Toi Gom"); outtextxy(50, 190 + 20, "I.BEN CHO THUE(BEN A):"); char* c = const_cast<char*>(s.c_str()); setcolor(red);
	outtextxy(400, 190 + 20, c); setcolor(BLACK); char* b = const_cast<char*>(phone_number.c_str());
	outtextxy(850, 190 + 20, "So DT:"); setcolor(red); outtextxy(1000, 190 + 20, b); setcolor(BLACK); char* bb = const_cast<char*>(adress.c_str());
	outtextxy(50, 190 + 20 * 2, "Hien la chu so huu can nha dia chi:"); setcolor(red); outtextxy(450, 190 + 20 * 2, bb); setcolor(BLACK);
	outtextxy(50, 190 + 20 * 3, "II.Ben thue (ben B):"); setcolor(red); char* c1 = const_cast<char*>(se.c_str());
	outtextxy(300, 190 + 20 * 3, c1); setcolor(BLACK);
	outtextxy(50, 190 + 20 * 4, "CMND so"); setcolor(red); outtextxy(300, 190 + 20 * 4, m); setcolor(BLACK);
	outtextxy(50, 190 + 20 * 5, "Dia Chi Thuong Tru:"); setcolor(red); char* cc = const_cast<char*>(t.c_str()); outtextxy(300, 190 + 20 * 5, cc); setcolor(BLACK);
	outtextxy(50, 190 + 20 * 6, "Dien Thoai Lien Lac:"); setcolor(red); outtextxy(300, 190 + 20 * 6, phone); setcolor(BLACK);
	outtextxy(50, 190 + 20 * 7, "Ben A cho ben B thue phong so:"); setcolor(red); outtextxy(380, 190 + 20 * 7, room); setcolor(BLACK);
	outtextxy(600, 190 + 20 * 7, "tai dia chi neu tren voi dieu kien nhu sau:");
	outtextxy(50, 190 + 20 * 8, "1.Gia thue "); setcolor(red); outtextxy(250, 190 + 20 * 8, roomcost); setcolor(BLACK);
	outtextxy(600, 190 + 20 * 8, "VND/THANG");
	outtextxy(50, 190 + 20 * 9, "Tien coc duoc thanh toan vao ngay 15 hang thang");
	outtextxy(50, 190 + 20 * 10, "2.Tien coc la:"); outtextxy(300, 190 + 20 * 10, "VND");
	outtextxy(50, 190 + 20 * 11, "Tien coc se hoan lai cho ben B khi ben B thanh toan cac chi phi lien quan ma ben B su dung hoac gay hu hong  ");
	outtextxy(50, 190 + 20 * 12, "3.Dien Tinh Theo Don Gia "); setcolor(red); outtextxy(350, 190 + 20 * 12, electric); setcolor(BLACK);
	outtextxy(600, 190 + 20 * 12, "VND/KW.");
	outtextxy(800, 190 + 20 * 12, "Chi so dien ban dau la:");
	outtextxy(50, 190 + 20 * 13, "Nuoc tinh theo don gia "); setcolor(red);
	outtextxy(350, 190 + 20 * 13, water); setcolor(BLACK);
	outtextxy(600, 190 + 20 * 13, "VND/KW.");
	outtextxy(800, 190 + 20 * 13, "Chi so nuoc ban dau la:");
	outtextxy(50, 190 + 20 * 14, "Phi Dich Vu WIFI:"); setcolor(red); outtextxy(350, 190 + 20 * 14, internet); setcolor(BLACK);
	outtextxy(600, 190 + 20 * 14, "VND/phong/thang.");
	outtextxy(50, 190 + 20 * 15, "Phi Dich Vu truyen hinh cap:"); setcolor(red); outtextxy(350, 190 + 20 * 15, cabletv); setcolor(BLACK);
	outtextxy(600, 190 + 20 * 15, "VND/phong/thang.");
	outtextxy(50, 190 + 20 * 16, "Phi Dich Vu do rac:");  setcolor(red); outtextxy(350, 190 + 20 * 16, clean); setcolor(BLACK);
	outtextxy(600, 190 + 20 * 16, "VND/phong/thang.");
	outtextxy(50, 190 + 20 * 17, "Phi Dich Vu Giu Xe:"); setcolor(red); outtextxy(350, 190 + 20 * 17, car_manage); setcolor(BLACK);
	outtextxy(600, 190 + 20 * 17, "VND/phong/thang.");
	outtextxy(50, 190 + 20 * 18, "4.Chia khoa, trang thiet bi di kem theo gia phong duoc liet ke trong bien ban ban giao tai san: Ben B khong duoc giao chia khoa cho ai khac");
	outtextxy(50, 190 + 20 * 19, "Nhung thiet bi di kem,ben B su dung phai bao quan can than,chiu trach nhiem hoan toan khi hu hong mat mat.  ");
	outtextxy(50, 190 + 20 * 20, "5.Neu mot trong hai vi pham quy dinh cua hop dong thi phai boi thuong thiet hai va bi phat gap doi so tien coc cho ben con lai");
	outtextxy(50, 190 + 20 * 21, "6.Ben B vui long tuan thu theo dung thoi gian thue phong nhu da thoa thuan ,neu ben B tu y cham dut hop dong truoc thoi han thoa thuan thi   ");
	outtextxy(50, 190 + 20 * 22, "ben A se khong hoan tien coc");
	outtextxy(50, 190 + 20 * 23, "7.Thoi han hop dong:"); int y3 = KhoangCachNgay(ngayhethan); setcolor(red);
	if (y3 > 0) outtextxy(300, 190 + 20 * 23, "hop dong da het han");
	else {
		stringstream strsab;
		strsab << -y3;
		string temp_strab = strsab.str();
		char* char_type12b = (char*)temp_strab.c_str(); outtextxy(300, 190 + 20 * 23, char_type12b);
		setcolor(BLACK); outtextxy(500, 190 + 20 * 23, "ngay");
	}
	setcolor(BLACK);
	outtextxy(450 + 300, 190 + 20 * 23, "Hop dong co gia tri tu ngay:"); setcolor(red);
	stringstream strs0;
	strs0 << ngayki.day;
	string temp_str0 = strs0.str();
	char* char_type10 = (char*)temp_str0.c_str();
	outtextxy(750 + 300, 190 + 20 * 23, char_type10);
	outtextxy(780 + 300, 190 + 20 * 23, "/");
	//printf sv.ngay.month
	stringstream strs10;
	strs10 << ngayki.month;
	string m10 = strs10.str();
	char* char_type110 = (char*)m10.c_str();
	outtextxy(820 + 300, 190 + 20 * 23, char_type110);
	outtextxy(850 + 300, 190 + 20 * 23, "/");
	//printf sv.ngay.year
	stringstream strs20;
	strs20 << ngayki.year;
	string m20 = strs20.str();
	char* char_type20 = (char*)m20.c_str();
	outtextxy(890 + 300, 190 + 20 * 23, char_type20); setcolor(BLACK);
	outtextxy(50, 190 + 20 * 24, "8.Hop dong co gia tri phap ly nhu nhau moi ben giu mot ban,co gia tri ke tu ngay ki  ");
	settextstyle(10, 0, 3);
	outtextxy(50, 190 + 20 * 25, "DAI DIEN BEN CHO THUE"); settextstyle(5, 0, 4);
	setcolor(RED); outtextxy(50, 190 + 20 * 27, c); setcolor(BLACK); settextstyle(10, 0, 3);
	outtextxy(800, 190 + 20 * 25, "BEN THUE"); setcolor(red); outtextxy(800, 190 + 20 * 27, c1);

}
void hoadon() {
	char s[50], s1[50] = " ";
	list_psh l; create_list_psh_psh(l); psh sv; ifstream  f; f.open("rent management contract.txt", ios::in);
	if (f.fail())
		cout << "Error file! " << endl;
	while (!f.eof())  //read into endfile.
	{
		psh sv;
		read_1_infopsh(f, sv);
		node* p = create_node_psh(sv);
		add_node_psh_tail(l, p);
	}
	f.close();
	cleardevice(); settextstyle(9, 0, 0);
	setfillstyle(1, yellow); setcolor(red); setbkcolor(yellow);
	bar(0, 0, 200, 40); outtextxy(10, 10, "<BACK");
	//bar(1200, 0, 1520, 40); outtextxy(1310, 10, "XEM TRUOC ");
	setcolor(RED);
	rectangle(0, 0, 200, 40);
	int exit = 0, x, y;
	setfillstyle(1, xinh);
	setcolor(WHITE); setbkcolor(xinh);
	bar(200, 0, 1520, 40);
	settextstyle(9, 0, 4);
	outtextxy(1520 / 2 - 200, 10, "In Hoa Don Nguoi Thue Tro"); setfillstyle(1, green); setcolor(YELLOW);
	rectangle(250, 0, 450, 40); setbkcolor(green); setcolor(WHITE);
	bar(250, 0, 450, 40); outtextxy(320, 10, "IN");
	setfillstyle(1, green); setbkcolor(green);
	bar(0, 40, 260, 80); setcolor(WHITE);
	outtextxy(10, 50, "Nhap CMND");
	setcolor(red); rectangle(260, 40, 600, 80);
	setfillstyle(1, red); setbkcolor(red);
	bar(600, 40, 900, 80); setcolor(WHITE);
	outtextxy(610, 50, " Ho Ten");
	setcolor(BLACK); rectangle(900, 40, 1520, 80);
	setbkcolor(WHITE); settextstyle(9, 0, 3);
	int flag = 0;
	while (exit == 0)
	{
		if (ismouseclick(WM_LBUTTONDOWN)) {
			getmouseclick(WM_LBUTTONDOWN, x, y);
			if ((x >= 0 && x <= 200) && (y >= 0 && y <= 40)) {
				setbkcolor(WHITE);
				cleardevice();
				exit = 1;
				menu8();
			}
			else if ((x >= 200 && x <= 600) && (y >= 40 && y <= 80)) {
				setcolor(LIGHTMAGENTA);
				rectangle(270, 40, 600, 80); setcolor(BLUE);
				Input(s, s1, 270, 50, ' ', 'z', 270, 40, 600, 80); strcpy(s1, s);
				ofstream f; f.open("try.txt", ios::out); f << s; f.close();
				
				
			}
		

		
			else if ((x >= 250 && x <= 450) && (y >= 0 && y <= 40) ) {
				
				ifstream f1; f1.open("try.txt", ios::in); char e1[30]; f1 >> e1; f1.close();
				for (node* k = l.phead; k != NULL; k = k->pnext) {
					if (strcmp(k->data.id_card, e1) == 0) {
						flag = 1;
						char* c = const_cast<char*>(k->data.name.c_str());
						outtextxy(910, 50, c);
						conghoa_xahoi(k->data.name, k->data.id_card, k->data.adress, k->data.phone_number, k->data.id, k->data.ngayhethan, k->data.ngayki);
					}
				}
				if (flag != 1) {
					setcolor(red);
					outtextxy(100, 100, "CMND Khong chinh xac");
				}

			}
			
		}
	}
	
	


}
void menu_chinh() {
	cleardevice();
	int x, y;
	int exit = 0;
	menu8();
	//hoadon();
	while (exit == 0) {
		if (ismouseclick(WM_MOUSEMOVE)) {
			getmouseclick(WM_MOUSEMOVE, x, y);
			if ((x >= 10 && x <= 120) && (y >= 0 && y <= 40)) {
				setcolor(red);
				rectangle(10, 0, 125, 40);
			}
			else {
				setcolor(BLACK);
				rectangle(10, 0, 125, 40);
			}
		}
		/*if (ismouseclick(WM_LBUTTONDOWN)){

			getmouseclick(WM_LBUTTONDOWN,x,y);
			if ((x >= 10 && x <= 125) && (y >= 0 && y <= 40))
			{
				cleardevice(); HomePageUIShow();
				exit = 1;
			}
		}*/
	}
}