#include"inhoadon.h"
void hienthi_hoadon() {
	ifstream f; f.open("hostel_information.txt", ios::in);
	infor_hostel sv;
	Read_1_info(f, sv);
	char* c = const_cast<char*>(sv.name.c_str());
	setcolor(xinh2);
	settextstyle(9, 0, 2); settextjustify(0, 1);
	outtextxy(210, 80, c);
	char* b = const_cast<char*>(sv.adress.c_str()); char* a = const_cast<char*>(sv.phonenumber.c_str()); char* d = const_cast<char*>(sv.content.c_str());
	char* e = const_cast<char*>(sv.notice.c_str());
	outtextxy(120, 80+30, b);
	outtextxy(120, 140, a);
	outtextxy(300, 750, e); outtextxy(300, 770, d);
	outtextxy(45 + 20, 750, "THONG BAO:");
	unitprice rv;
	ifstream fk; fk.open("unit_price.txt", ios::in);
	Read_1_unitprice(fk, rv); fk.close();
	stringstream strs4;
	strs4 << rv.clean;
	string temp_str4 = strs4.str();
	char* char_type4 = (char*)temp_str4.c_str(); outtextxy(680, 320 + 35 * 4, char_type4);
	stringstream strs5;
	strs5 << rv.cabletv;
	string temp_str5 = strs5.str();
	char* char_type5 = (char*)temp_str5.c_str(); outtextxy(680, 320 + 35 * 5, char_type5);
	stringstream strs6;
	strs6 << rv.internet;
	string temp_str6 = strs6.str();
	char* char_type6 = (char*)temp_str6.c_str(); outtextxy(680, 320 + 35 * 6, char_type6);
	stringstream strs7;
	strs7 << rv.roomcost;
	string temp_str7 = strs7.str();
	char* char_type7 = (char*)temp_str7.c_str(); outtextxy(680, 320 + 35 * 7, char_type7);
}
void input_hoadon_12() {
	void thiekehoadon();
	unitprice rv;
	int room_name, month;
	ifstream ft; ft.open("paymoney_service.txt", ios::in); list_pmn l; create_list_pmn_pmn(l);
	while (!ft.eof())  //read into endfile.
	{
		pmn sv;
		read_data_pay_money(ft, sv);
		nodepmn* p = create_nodepmn_pmn(sv);
		add_nodepmn_pmn_tail(l, p);
	}
	ifstream fk; fk.open("unit_price.txt", ios::in);
	Read_1_unitprice(fk, rv); fk.close();
	ft.close();
	int exit = 0,x,y,sum=0,soxe;
	setbkcolor(Seashell1);
	while (exit == 0) {
		if (ismouseclick(WM_LBUTTONDOWN)) {
			getmouseclick(WM_LBUTTONDOWN, x, y);
			if ((x >= 1120 && x <= 1400) && (y >= 120 && y <= 160)) {
				setfillstyle(1, WHITE); bar(1120, 120, 1400, 160);
				setcolor(red);
				rectangle(1120, 120, 1400, 160);
				char s[50], s1[50] = " ";
				ofstream f; f.open("input_menu8.txt", ios::out); settextjustify(0, 1);
				Input(s, s1, 1130, 150, '0', '9', 1120, 120, 1400, 160);
				f << s << ",";
				f.close();
			}
			else
				if ((x >= 1120 && x <= 1400) && (y >= 230&& y <= 270)) {
					setfillstyle(1, WHITE);
					bar(1120, 230, 1400, 270);
					setcolor(green);
					rectangle(1120, 230, 1400, 270);
					char s1[50], s2[50] = " ";
					ofstream f; f.open("input_menu8.txt", ios::out|ios::app); settextjustify(0, 1);
					Input(s1, s2, 1130, 260, '0', '9', 1120, 230, 1400, 270);
					f << s1; f.close();
				}
				else if ((x >= 1120 && x <= 1400) && (y >= 300&& y <= 340)) {
					setcolor(BLUE);
					rectangle(1120, 230 + 70, 1400, 270 + 70);
					setfillstyle(1, yellow);
					bar(1120, 230 + 70, 1400, 270 + 70);
					setcolor(BLUE); setbkcolor(yellow);
					settextjustify(1, 1); settextstyle(9, 0, 4);
					outtextxy(1250, 260 + 70, "IN"); setcolor(RED);
					rectangle(1120, 230 + 70, 1400, 270 + 70); setbkcolor(Seashell1);
					ifstream f; f.open("input_menu8.txt", ios::in); f >> month; f.seekg(1, 1);
					f >> room_name; f.close();
					for (nodepmn* k = l.phead; k != NULL; k = k->pnext) {
						if ((k->data.month == month) && (k->data.tenphong == room_name)) {
							setcolor(xinh2);
							settextjustify(0, 1);
							settextstyle(9, 0, 2);
							stringstream strs;
							strs << k->data.tenphong;
							string temp_str = strs.str();
							char* char_type = (char*)temp_str.c_str();
							outtextxy(245, 235, char_type);
							stringstream strs1;
							strs1 << k->data.month;
							string temp_str1 = strs1.str();
							char* char_type1 = (char*)temp_str1.c_str();
							outtextxy(245, 265, char_type1);
							stringstream strs2;
							strs2 << k->data.tiencoc;
							string temp_str2 = strs2.str();
							char* char_type2 = (char*)temp_str2.c_str();
							outtextxy(680, 320 + 35 * 8, char_type2);
							stringstream strs3;
							strs3 << k->data.nocu;
							string temp_str3 = strs3.str();
							char* char_type3 = (char*)temp_str3.c_str();
							outtextxy(680, 320 + 35 * 9, char_type3);
							stringstream strs4;
							strs4 << k->data.dsomoi;
							string temp_str4 = strs4.str();
							char* char_type4 = (char*)temp_str4.c_str();
							outtextxy(280, 320 + 35, char_type4);
							stringstream strs5;
							strs5 <<k->data.dsocu;
							string temp_str5 = strs5.str();
							char* char_type5 = (char*)temp_str5.c_str();
							outtextxy(280+140, 320 + 35, char_type5);
							stringstream strs55;
							strs55 << k->data.dsomoi-k->data.dsocu;
							string temp_str55 = strs55.str();
							char* char_type55 = (char*)temp_str55.c_str();
							outtextxy(560, 320 + 35, char_type55);
							// tong dien
							stringstream strs55t;
							strs55t << (k->data.dsomoi - k->data.dsocu) * rv.electric;
							string temp_str55t = strs55t.str();
							char* char_type55t = (char*)temp_str55t.c_str();
							outtextxy(680, 320 + 35, char_type55t);
							// nuoc
							stringstream strs44;
							strs44 << k->data.nsomoi;
							string temp_str44 = strs44.str();
							char* char_type44 = (char*)temp_str44.c_str();
							outtextxy(280, 320 + 35*2, char_type44);
							stringstream strs51;
							strs51 << k->data.nsocu;
							string temp_str51 = strs51.str();
							char* char_type51 = (char*)temp_str51.c_str();
							outtextxy(280 + 140, 320 + 35*2, char_type51);
							stringstream strs50;
							strs50 << k->data.nsomoi - k->data.nsocu;
							string temp_str50 = strs50.str();
							char* char_type50 = (char*)temp_str50.c_str();
							outtextxy(560, 320 + 35*2, char_type50);
							//tong nuoc
							stringstream strs50w;
							strs50w << (k->data.nsomoi - k->data.nsocu) * rv.water;
							string temp_str50w = strs50w.str();
							char* char_type50w = (char*)temp_str50w.c_str();

							outtextxy(680, 320 + 35 * 2, char_type50w);
							// quan li xe
							soxe = k->data.slxe * rv.car_manage;
							stringstream strs5i;
							strs5i << k->data.slxe;
							string temp_str5i = strs50.str();
							char* char_type5i = (char*)temp_str5i.c_str();
							outtextxy(360, 320 + 35 * 3, char_type5i);
							stringstream strs6;
							strs6 << soxe;
							string temp_str6 = strs6.str();
							char* char_type6 = (char*)temp_str6.c_str();
							outtextxy(680, 320 + 35 * 3, char_type6);
							
							//total
							stringstream strs58;
							strs58 <<( k->data.slxe * rv.car_manage) + (k->data.dsomoi - k->data.dsocu) * rv.electric + (k->data.nsomoi - k->data.nsocu) * rv.water + rv.cabletv + rv.clean + rv.roomcost + rv.internet + k->data.nocu;
							string temp_str58 = strs58.str();
							char* char_type58 = (char*)temp_str58.c_str();
							outtextxy(680, 320 + 35 * 11, char_type58);
							outtextxy(420, 265, char_type58);
							break;
						}
					}
					settextstyle(9, 0, 4);
				}
				else if ((x >= 1120 && x <= 1400) && (y >= 370 && y <= 410)) {
					setfillstyle(1, green);
					bar(1120, 230 + 100 + 40, 1400, 270 + 70 + 70);
					setcolor(WHITE); setbkcolor(green);
					settextjustify(1, 1); settextstyle(9, 0, 4);
					outtextxy(1250, 260 + 70 + 40 + 30, "RESET"); setcolor(GREEN);
					rectangle(1120, 230 + 100 + 40, 1400, 270 + 70 + 70); setbkcolor(Seashell1);
					thiekehoadon(); settextstyle(9, 0, 4);
				}
			else 
				if ((x >= 0 && x <= 130) && (y >= 0 && y <= 40)) {
					exit = 1; HomePageUIShow();
				}
				else {
					setfillstyle(1, blue_d);
					bar(1120, 230 + 70, 1400, 270 + 70);
					setcolor(RED); setbkcolor(blue_d);
					settextjustify(1, 1); settextstyle(9, 0, 4);
					outtextxy(1250, 260 + 70, "IN"); setcolor(RED);
					rectangle(1120, 230 + 70, 1400, 270 + 70);
					setfillstyle(1, LIGHTMAGENTA);
					bar(1120, 230 + 100 + 40, 1400, 270 + 70 + 70);
					setcolor(BLUE); setbkcolor(LIGHTMAGENTA);
					settextjustify(1, 1); settextstyle(9, 0, 4);
					outtextxy(1250, 260 + 70 + 40 + 30, "RESET"); setcolor(GREEN);
					rectangle(1120, 230 + 100 + 40, 1400, 270 + 70 + 70); setbkcolor(Seashell1);
				}
		}
	}
}
void thiekehoadon() {
	setfillstyle(1, WHITE);
	bar(0, 40, 1000, 850);
	
	setcolor(RED); settextstyle(9, 0, 2); setbkcolor(Seashell1);
	outtextxy(80 + 20, 80, "Ten Nha Tro:");
	outtextxy(50 + 20, 80 + 30, "Dia Chi:");
	outtextxy(45 + 20, 140, "So DT:");
	// tra ve date / time hien tai dua tren system hien tai
	time_t hientai = time(0);
	// chuyen doi hientai thanh dang chuoi
	char* dt = ctime(&hientai);
	outtextxy(550, 140, "Ngay In:"); setcolor(BLUE);
	outtextxy(800, 140, dt); setcolor(RED);
	settextstyle(4, 0, 2);
	outtextxy(450, 190, "GIAY THANH TOAN TIEN PHONG");
	setfillstyle(1, RED);
	rectangle(50, 210, 300, 270);
	outtextxy(110, 225 + 10, "Phong:"); outtextxy(110, 255 + 10, "Thang:");
	line(50, 240, 300, 240); line(200, 210, 200, 270);
	// tong tien phai thu
	rectangle(350, 210, 800, 270);
	outtextxy(600 - 30, 230, "Tong Cong So Tien Phai Thu");
	line(350, 240, 800, 240);
	int i = 290 + 40;
	int j = 1;
	rectangle(50, 290, 800, 710);
	for (; i <= 710; i += 35) {
		line(50, i, 800, i);
		stringstream strs2;
		strs2 << j;
		string m2 = strs2.str();
		char* char_type2 = (char*)m2.c_str();
		outtextxy(70, i + 25, char_type2); j++;
	}
	line(100, 290, 100, 710);
	i = 140 + 100;
	for (; i <= 800; i += 140) line(i, 290, i, 330);
	line(240, 330, 240, 330 + 40 * 3 - 13); line(240 + 140, 330, 240 + 140, 330 + 40 * 2 - 12); line(240 + 140 * 2, 330, 240 + 140 * 2, 330 + 40 * 2 - 12);
	line(240 + 140 * 3, 330, 240 + 140 * 3, 710);	settextstyle(9, 0, 1);
	// noi dung
	outtextxy(75, 320, "STT"); outtextxy(75 + 100, 320, "Loai Tien"); outtextxy(75 + 240, 320, "So Moi"); outtextxy(75 + 240 + 140, 320, "So Cu");
	outtextxy(75 + 240 * 2 + 40, 320, "Da Dung"); outtextxy(75 + 240 * 2 + 140 + 40, 320, "Thanh Tien");
	settextjustify(0, 1);
	outtextxy(110, 320 + 35, "Dien"); outtextxy(110, 320 + 35 * 2, "Nuoc");
	outtextxy(110, 320 + 35 * 3, "Quan Li Xe"); outtextxy(480, 320 + 35 * 3, "xe");
	outtextxy(110, 320 + 35 * 4, "Rac"); outtextxy(110, 320 + 35 * 5, "TH.cap"); outtextxy(110, 320 + 35 * 6, "Internet"); outtextxy(110, 320 + 35 * 7, "Tien Phong");
	outtextxy(110, 320 + 35 * 8, "Tien Coc"); outtextxy(110, 320 + 35 * 9, "No Cu");
	outtextxy(110, 320 + 35 * 10, "Khac"); outtextxy(110, 320 + 35 * 11, "Tong Cong");
	hienthi_hoadon();
}

void input_hoadon_t() {
	//hienthi_hoadon();
	setfillstyle(1, green);
	bar(1120, 80, 1400, 120);
	setcolor(WHITE); setbkcolor(green);
	settextjustify(0, 1); settextstyle(9, 0, 4);
	outtextxy(1150, 110, "Nhap Thang"); setcolor(RED);
	rectangle(1120, 80, 1400, 120); setcolor(BLUE);
	rectangle(1120, 80 + 40, 1400, 120 + 40);
	// nhap phong
	setfillstyle(1, red);
	bar(1120, 80 + 40 * 2 + 30, 1400, 120 + 40 * 2 + 30);
	setcolor(WHITE); setbkcolor(red);
	settextjustify(0, 1); settextstyle(9, 0, 4);
	outtextxy(1150, 110 + 40 * 2 + 30, "Nhap Phong"); setcolor(RED);
	rectangle(1120, 80 + 40 * 2 + 30, 1400, 120 + 40 * 2 + 30); setcolor(BLACK);
	rectangle(1120, 80 + 40 + 40 * 2 + 30, 1400, 120 + 40 + 40 * 2 + 30);
	//in
	setfillstyle(1, blue_d);
	bar(1120, 230 + 70, 1400, 270 + 70);
	setcolor(RED); setbkcolor(blue_d);
	settextjustify(1, 1); settextstyle(9, 0, 4);
	outtextxy(1250, 260 + 70, "IN"); setcolor(RED);
	rectangle(1120, 230 + 70, 1400, 270 + 70);
	//reset
	setfillstyle(1, LIGHTMAGENTA);
	bar(1120, 230 + 100 + 40, 1400, 270 + 70 + 70);
	setcolor(BLUE); setbkcolor(LIGHTMAGENTA);
	settextjustify(1, 1); settextstyle(9, 0, 4);
	outtextxy(1250, 260 + 70 + 40 + 30, "RESET"); setcolor(GREEN);
	rectangle(1120, 230 + 100 + 40, 1400, 270 + 70 + 70);
}
void main_menu_hoadon() {
	int exit = 0, x, y;
	cleardevice();
	setfillstyle(7, Seashell1);
	bar(0, 40, 1520, 850);
	setfillstyle(7, yellow);
	setcolor(BLUE); setbkcolor(yellow);
	bar(0, 0, 1520, 40); settextjustify(1, 1);
	settextstyle(9, 0, 0);
	outtextxy(1520 / 2 - 100, 30, "IN HOA DON CHI TIET 12 THANG"); settextstyle(9, 0, 3);
	setfillstyle(1, yellow); setcolor(red); setbkcolor(yellow);
	bar(0, 0, 130, 40); outtextxy(60, 30, "<BACK"); setcolor(RED);
	rectangle(0, 0, 130, 40);
	setfillstyle(7, BLACK);
	setlinestyle(1, 0, 1);
	line(1000, 40, 1000, 850); thiekehoadon(); input_hoadon_t();
	input_hoadon_12();
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