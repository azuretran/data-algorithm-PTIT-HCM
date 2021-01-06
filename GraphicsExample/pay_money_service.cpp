#include"pay_money_service.h"
void read_info_electricity_water(ifstream&f,dg&sv) {
	f >> sv.dien; f.seekg(1, 1);
	f >> sv.nuoc; f.seekg(1, 1);
	f >> sv.nuoc_1_nguoi; f.seekg(1, 1);
	f >> sv.quanlixe; f.seekg(1, 1);
	f >> sv.vesinh; f.seekg(1, 1); f >> sv.thcap; f.seekg(1, 1);
	f >> sv.internet; f.seekg(1, 1);
	f >> sv.tienphong;
}
void xuattheo_vitri_4(list_pmn l, int start, int endt) {
	int i = 120, dem = 0, dem2 = 0, j = 0;
	setbkcolor(WHITE); dg rv;
	ifstream ff; ff.open("unit_price.txt", ios::in);
	read_info_electricity_water(ff, rv); settextstyle(11, 0, 4);
	for (nodepmn* k = l.phead; k != NULL; k = k->pnext)
	{
		dem++;
		dem2++; if (dem == start) {
			dem--;
			//ten phong
			setcolor(red);
			stringstream strs6;
			strs6 << k->data.tenphong;
			string temp_str6 = strs6.str();
			char* char_type6 = (char*)temp_str6.c_str();
			outtextxy(30, i, char_type6);
			//thang
			stringstream strs66;
			strs66 << k->data.month;
			string temp_str66 = strs66.str();
			char* char_type66 = (char*)temp_str66.c_str();
			outtextxy(30 + 45, i, char_type66);
			// dien so cu
			setcolor(green);
			stringstream strs3;
			strs3 << k->data.dsocu;
			string temp_str3 = strs3.str();
			char* char_type3 = (char*)temp_str3.c_str();
			outtextxy(30 + 45 * 2, i, char_type3);
			//dien so moi
			stringstream strs33;
			strs33 << k->data.dsomoi;
			string temp_str33 = strs33.str();
			char* char_type33 = (char*)temp_str33.c_str();
			outtextxy(30 + 45 * 3, i, char_type33);
			// don gia dien
			stringstream strs37;
			strs37 << rv.dien;
			string temp_str37 = strs37.str();
			char* char_type37 = (char*)temp_str37.c_str();
			outtextxy(30 + 45 * 4 + 15, i, char_type37);
			//so tien dien
			stringstream strs370;
			strs370 << (k->data.dsomoi - k->data.dsocu) * rv.dien;
			string temp_str370 = strs370.str();
			char* char_type370 = (char*)temp_str370.c_str();
			outtextxy(30 + 45 * 5 + 20, i, char_type370);
			//nuoc so cu
			setcolor(red);
			stringstream strs334;
			strs334 << k->data.nsocu;
			string temp_str334 = strs334.str();
			char* char_type334 = (char*)temp_str334.c_str();
			outtextxy(30 + 45 * 6 + 20, i, char_type334);
			// nuoc so moi
			stringstream strs335;
			strs335 << k->data.nsomoi;
			string temp_str335 = strs335.str();
			char* char_type335 = (char*)temp_str335.c_str();
			outtextxy(30 + 45 * 7 + 20, i, char_type335);
			//don gia nuoc
			stringstream strs3355;
			strs3355 << rv.nuoc;
			string temp_str3355 = strs3355.str();
			char* char_type3355 = (char*)temp_str3355.c_str();
			outtextxy(30 + 45 * 8 + 30, i, char_type3355);
			//so tien
			stringstream strs3y;
			strs3y << (k->data.nsomoi - k->data.nsocu) * rv.nuoc;
			string temp_str3y = strs3y.str();
			char* char_type3y = (char*)temp_str3y.c_str();
			outtextxy(30 + 45 * 9 + 40, i, char_type3y);
			// nuoc theo nguoi

			//so luong xe
			setcolor(green);
			stringstream strs3356;
			strs3356 << k->data.slxe;
			string temp_str3356 = strs3356.str();
			char* char_type3356 = (char*)temp_str3356.c_str();
			outtextxy(30 + 45 * 15 + 20, i, char_type3356);
			//don gia xe
			stringstream strso;
			strso << rv.quanlixe;
			string temp_stro = strso.str();
			char* char_typeo = (char*)temp_stro.c_str();
			outtextxy(30 + 45 * 16 + 20, i, char_typeo);
			// tong xe
			stringstream strsor;
			strsor << k->data.slxe * rv.quanlixe;
			string temp_stror = strsor.str();
			char* char_typeor = (char*)temp_stror.c_str();
			outtextxy(30 + 45 * 17 + 30, i, char_typeor);
			// chiphi khac
			//ve sinh
			setcolor(BLACK);
			stringstream strsoo;
			strsoo << rv.vesinh;
			string temp_stroo = strsoo.str();
			char* char_typeoo = (char*)temp_stroo.c_str();
			outtextxy(30 + 45 * 18 + 30, i, char_typeoo);
			//th cap
			stringstream strsooo;
			strsooo << rv.thcap;
			string temp_strooo = strsooo.str();
			char* char_typeooo = (char*)temp_strooo.c_str();
			outtextxy(30 + 45 * 19 + 40, i, char_typeooo);
			// internet
			stringstream strsn;
			strsn << rv.internet;
			string temp_strn = strsn.str();
			char* char_typen = (char*)temp_strn.c_str();
			outtextxy(30 + 45 * 20 + 40, i, char_typen);
			//
			//tien coc
			setcolor(BLUE);
			stringstream strsu;
			strsu << k->data.tiencoc;
			string temp_stru = strsu.str();
			char* char_typeu = (char*)temp_stru.c_str();
			outtextxy(30 + 45 * 24 + 15, i, char_typeu);
			// tien phong
			stringstream strsu1;
			strsu1 << rv.tienphong;
			string temp_stru1 = strsu1.str();
			char* char_typeu1 = (char*)temp_stru1.c_str();
			outtextxy(30 + 45 * 23 + 10, i, char_typeu1);
			//no cu
			stringstream strsub;
			strsub << k->data.nocu;
			string temp_strub = strsub.str();
			char* char_typeub = (char*)temp_strub.c_str();
			outtextxy(30 + 45 * 25 + 15, i, char_typeub);
			//total
			stringstream strsubc;
			strsubc << (k->data.dsomoi - k->data.dsocu) * rv.dien + (k->data.nsomoi - k->data.nsocu) * rv.nuoc + k->data.slxe * rv.quanlixe + rv.vesinh + rv.internet + rv.thcap + rv.tienphong + k->data.nocu;
			string temp_strubc = strsubc.str();
			char* char_typeubc = (char*)temp_strubc.c_str();
			outtextxy(30 + 45 * 26 + 30, i, char_typeubc);
			//da thu
			stringstream strsuc;
			strsuc << k->data.dathu;
			string temp_struc = strsuc.str();
			char* char_typeuc = (char*)temp_struc.c_str();
			outtextxy(30 + 45 * 27 + 25, i, char_typeuc);
			// con lai
			stringstream strsuyy;
			strsuyy << (k->data.dsomoi - k->data.dsocu) * rv.dien + (k->data.nsomoi - k->data.nsocu) * rv.nuoc + k->data.slxe * rv.quanlixe + rv.vesinh + rv.internet + rv.thcap + rv.tienphong + k->data.nocu - k->data.dathu;
			string temp_struyy = strsuyy.str();
			char* char_typeuyy = (char*)temp_struyy.c_str();
			outtextxy(30 + 45 * 28 + 33, i, char_typeuyy);
			//ghi chu
			char* c = const_cast<char*>(k->data.note.c_str());

			outtextxy(30 + 45 * 30 + 15, i, c);
			i += 25;
		}
		if (dem2 == endt) break;
	}
}
void xuli_pay_money() {
	void main_menu_pay_money_service();
	void input_user_menu4();
	void search_byvt();
	void xoa_by_pss();
	setcolor(BLACK);
	list_pmn l; create_list_pmn_pmn(l);
	ifstream  f; int x, y, exit = 0, demlist = 0, j = 0;
	int exit1 = 0;
	pmn sv;
	dg rv;
	f.open("paymoney_service.txt", ios::in);
	if (f.fail())
		cout << "Error file! " << endl;
	while (!f.eof())  //read into endfile.
	{
		pmn sv;
		read_data_pay_money(f, sv);
		nodepmn* p = create_nodepmn_pmn(sv);
		add_nodepmn_pmn_tail(l, p);
	}
	int len_list = len2(l); f.close(); 
	ifstream ff; ff.open("unit_price.txt", ios::in);
	read_info_electricity_water(ff, rv);
	settextstyle(9, 0, 3); setbkcolor(WHITE);
	outtextxy(50, 780, "0-26");
	settextstyle(11, 0,0); setbkcolor(WHITE);
	
	int i = 120;
	for (nodepmn* k = l.phead; k != NULL; k = k->pnext) {
		demlist++;
		//ten phong
		setcolor(red);
		stringstream strs6;
		strs6 <<k->data.tenphong;
		string temp_str6 = strs6.str();
		char* char_type6 = (char*)temp_str6.c_str();
		outtextxy(30, i, char_type6);
		//thang
		stringstream strs66;
		strs66 << k->data.month;
		string temp_str66 = strs66.str();
		char* char_type66 = (char*)temp_str66.c_str();
		outtextxy(30+45, i, char_type66);
		// dien so cu
		setcolor(green);
		stringstream strs3;
		strs3 << k->data.dsocu;
		string temp_str3 = strs3.str();
		char* char_type3 = (char*)temp_str3.c_str();
		outtextxy(30 + 45*2, i, char_type3);
		//dien so moi
		stringstream strs33;
		strs33 << k->data.dsomoi;
		string temp_str33 = strs33.str();
		char* char_type33 = (char*)temp_str33.c_str();
		outtextxy(30 + 45 * 3, i, char_type33);
		// don gia dien
		stringstream strs37;
		strs37 <<rv.dien;
		string temp_str37 = strs37.str();
		char* char_type37 = (char*)temp_str37.c_str();
		outtextxy(30 + 45 * 4+15, i, char_type37);
		//so tien dien
		stringstream strs370;
		strs370 << (k->data.dsomoi-k->data.dsocu)*rv.dien;
		string temp_str370 = strs370.str();
		char* char_type370 = (char*)temp_str370.c_str();
		outtextxy(30 + 45 * 5 + 20, i, char_type370);
		//nuoc so cu
		setcolor(red);
		stringstream strs334;
		strs334 << k->data.nsocu;
		string temp_str334 = strs334.str();
		char* char_type334 = (char*)temp_str334.c_str();
		outtextxy(30 + 45 * 6+20, i, char_type334);
		// nuoc so moi
		stringstream strs335;
		strs335 << k->data.nsomoi;
		string temp_str335 = strs335.str();
		char* char_type335 = (char*)temp_str335.c_str();
		outtextxy(30 + 45 * 7+20, i, char_type335);
		//don gia nuoc
		stringstream strs3355;
		strs3355 << rv.nuoc;
		string temp_str3355 = strs3355.str();
		char* char_type3355 = (char*)temp_str3355.c_str();
		outtextxy(30 + 45 * 8 +30, i, char_type3355);
		//so tien
		stringstream strs3y;
		strs3y << (k->data.nsomoi-k->data.nsocu)*rv.nuoc;
		string temp_str3y = strs3y.str();
		char* char_type3y = (char*)temp_str3y.c_str();
		outtextxy(30 + 45 * 9 + 40, i, char_type3y);
		// nuoc theo nguoi

		//so luong xe
		setcolor(green);
		stringstream strs3356;
		strs3356 << k->data.slxe;
		string temp_str3356 = strs3356.str();
		char* char_type3356 = (char*)temp_str3356.c_str();
		outtextxy(30 + 45 * 15 + 20, i, char_type3356);
		//don gia xe
		stringstream strso;
		strso << rv.quanlixe;
		string temp_stro = strso.str();
		char* char_typeo = (char*)temp_stro.c_str();
		outtextxy(30 + 45 * 16 + 20, i, char_typeo);
		// tong xe
		stringstream strsor;
		strsor << k->data.slxe*rv.quanlixe;
		string temp_stror = strsor.str();
		char* char_typeor = (char*)temp_stror.c_str();
		outtextxy(30 + 45 * 17 + 30, i, char_typeor);
		// chiphi khac
		//ve sinh
		setcolor(BLACK);
		stringstream strsoo;
		strsoo << rv.vesinh;
		string temp_stroo = strsoo.str();
		char* char_typeoo = (char*)temp_stroo.c_str();
		outtextxy(30 + 45 * 18 + 30, i, char_typeoo);
		//th cap
		stringstream strsooo;
		strsooo << rv.thcap;
		string temp_strooo = strsooo.str();
		char* char_typeooo = (char*)temp_strooo.c_str();
		outtextxy(30 + 45 * 19 + 40, i, char_typeooo);
		// internet
		stringstream strsn;
		strsn << rv.internet;
		string temp_strn= strsn.str();
		char* char_typen = (char*)temp_strn.c_str();
		outtextxy(30 + 45 * 20 + 40, i, char_typen);
		//
		//tien coc
		setcolor(BLUE);
		stringstream strsu;
		strsu << k->data.tiencoc;
		string temp_stru = strsu.str();
		char* char_typeu = (char*)temp_stru.c_str();
		outtextxy(30 + 45 * 24+15, i, char_typeu);
		// tien phong
		stringstream strsu1;
		strsu1 << rv.tienphong;
		string temp_stru1 = strsu1.str();
		char* char_typeu1 = (char*)temp_stru1.c_str();
		outtextxy(30 + 45 * 23 + 10, i, char_typeu1);
		//no cu
		stringstream strsub;
		strsub << k->data.nocu;
		string temp_strub = strsub.str();
		char* char_typeub = (char*)temp_strub.c_str();
		outtextxy(30 + 45 * 25 + 15, i, char_typeub);
		//total
		stringstream strsubc;
		strsubc << (k->data.dsomoi - k->data.dsocu) * rv.dien + (k->data.nsomoi - k->data.nsocu) * rv.nuoc + k->data.slxe * rv.quanlixe + rv.vesinh + rv.internet + rv.thcap + rv.tienphong + k->data.nocu;
		string temp_strubc = strsubc.str();
		char* char_typeubc = (char*)temp_strubc.c_str();
		outtextxy(30 + 45 * 26 + 30, i, char_typeubc);
		//da thu
		stringstream strsuc;
		strsuc << k->data.dathu;
		string temp_struc = strsuc.str();
		char* char_typeuc = (char*)temp_struc.c_str();
		outtextxy(30 + 45 * 27 + 25, i, char_typeuc);
		// con lai
		stringstream strsuyy;
		strsuyy << (k->data.dsomoi - k->data.dsocu) * rv.dien + (k->data.nsomoi - k->data.nsocu) * rv.nuoc + k->data.slxe * rv.quanlixe + rv.vesinh + rv.internet + rv.thcap + rv.tienphong + k->data.nocu - k->data.dathu;
		string temp_struyy = strsuyy.str();
		char* char_typeuyy = (char*)temp_struyy.c_str();
		outtextxy(30 + 45 * 28 + 33, i, char_typeuyy);
		//ghi chu
		char* c = const_cast<char*>(k->data.note.c_str());
		
		outtextxy(30 + 45 *30 + 15, i, c);
		i += 25;
		
		if (i > 750)
		{
			while (exit == 0)
			{
				if (ismouseclick(WM_LBUTTONDOWN)) {
					getmouseclick(WM_LBUTTONDOWN, x, y);
					if ((x >= 0 && x <= 130) && (y >= 0 && y <= 40)) {
						exit = 1; HomePageUIShow();
					}
					else if ((x>=1380&&x<=1520)&&(y>=760&&y<=800)) {
						i = 120;
						main_menu_pay_money_service();
						xuattheo_vitri_4(l, demlist + 1, demlist + 26);
						setbkcolor(WHITE);
						
						setfillstyle(6, blue_d);
						bar(40, 760, 200, 800);
						settextstyle(9, 0, 3);
						int next1 = demlist;
						int next2 = demlist + 26;
						stringstream strs5;
						strs5 << next1;
						string temp_str5 = strs5.str();
						char* char_type5 = (char*)temp_str5.c_str();
						stringstream strs5r;
						strs5r << next2;
						string temp_str5r = strs5r.str();
						char* char_type5r = (char*)temp_str5r.c_str();
						setcolor(red);
						outtextxy(30, 780, char_type5); outtextxy(70, 780, "-");
						outtextxy(90, 780, char_type5r);
						demlist += 26;
						if (demlist >26) {
							setfillstyle(1, red);
							bar(1200, 760, 1340, 800); setbkcolor(red);
							settextstyle(9, 0, 3); setcolor(WHITE);
							outtextxy(1270, 790, "<PREV");
							setcolor(yellow);
							rectangle(1200, 760, 1340, 800);
						}
					}
					else if ((x>=1200&&x<=1340)&&(y>=760&&y<=800)) {
						setbkcolor(WHITE);
						settextstyle(9, 0, 3);
						setfillstyle(6, blue_d);
						bar(0, 760, 200, 800);
						setfillstyle(8, Plum1);
						bar(0, 760, 200, 800);
						demlist = demlist - 26;
						int next1 = demlist - 26;
						int next2 = demlist;
						stringstream strs5;
						strs5 << next1;
						string temp_str5 = strs5.str();
						char* char_type5 = (char*)temp_str5.c_str();
						stringstream strs5r;
						strs5r << next2;
						string temp_str5r = strs5r.str();
						char* char_type5r = (char*)temp_str5r.c_str();
						setcolor(red);
						outtextxy(30, 780, char_type5); outtextxy(70, 780, "-");
						outtextxy(90, 780, char_type5r);
						i = 120;
						main_menu_pay_money_service(); settextstyle(11, 0, 4);
						xuattheo_vitri_4(l, demlist-25, demlist);
					}
					else if ((x >= 150 && x <= 340) && (y >= 0 && y <= 40)) {
						setbkcolor(WHITE); settextstyle(9, 0, 3);
						input_user_menu4();
					}
					else if ((x >= 350 && x <= 500) && (y >= 0 && y <= 40)) {
						setbkcolor(WHITE); settextstyle(9, 0, 3);
						xoa_by_pss();
					}
					else if ((x >= 1300 && x <= 1500) && (y >= 0 && y <= 40)) {
						setbkcolor(WHITE); settextstyle(9, 0, 3);
						search_byvt();
					}
					else if ((x >= 1100 && x <= 1310) && (y >= 0 && y <= 40)) {
						setfillstyle(1, yellow); setcolor(BLUE); setbkcolor(yellow); settextstyle(9, 0, 4);
						bar(1100, 0, 1310, 40); outtextxy(1210, 30, "Sap Xep");
						sort_by_room(l);
						save_file_pmn(l); main_menu_pay_money_service(); xuli_pay_money();
					}

				}
			}
		}
	}






}

void main_menu_pay_money_service() {
	setfillstyle(1, WHITE);
	bar(5, 50, 1500, 750);
	
	setcolor(BLACK); rectangle(5, 50, 1500, 750);
	int i = 100;
	for (; i < 750; i += 25) line(5, i, 1500, i);
	i = 50; line(100, 75, 1500, 75);
	for (; i < 1300; i += 50) line(i, 100, i, 750); setbkcolor(WHITE);
	i = 100;
	for (; i < 1450 - 50; i += 50) line(i, 75, i, 750);
	setcolor(red); settextstyle(3, 0, 1);
	outtextxy(30, 80, "Phong"); line(50, 50, 50, 100); line(50, 50, 50, 75);
	outtextxy(75, 80, "Thang");
	setfillstyle(1, green); setbkcolor(green);
	bar(100, 50, 300, 75); rectangle(100, 50, 300, 75); setcolor(WHITE); settextstyle(9, 0, 2);
	outtextxy(200, 70, "Dien");
	setcolor(GREEN); setbkcolor(WHITE); settextstyle(11, 0, 4);
	outtextxy(125, 95, "So Cu"); outtextxy(125 + 50, 95, "So Moi"); outtextxy(125 + 100, 95, "Don Gia"); outtextxy(125 + 150, 95, "So Tien");
	setfillstyle(1, yellow); setbkcolor(yellow); setcolor(red); settextstyle(3, 0, 1);
	bar(300, 50, 500, 75); rectangle(300, 50, 500, 75);
	outtextxy(400, 70, "Nuoc(theo dong ho)"); setcolor(RED); setbkcolor(WHITE); settextstyle(11, 0, 4);
	outtextxy(325, 95, "So Cu"); outtextxy(375, 95, "So Moi"); outtextxy(375 + 50, 95, "Don Gia"); outtextxy(475, 95, "So Tien"); settextstyle(3, 0, 1);
	setfillstyle(1, yellow); setbkcolor(yellow);
	bar(500, 50, 700, 75); rectangle(500, 50, 700, 75);
	outtextxy(600, 70, "Nuoc(theo so nguoi)"); setbkcolor(WHITE); settextstyle(11, 0, 4);
	outtextxy(475 + 50, 95, "So Nguoi"); outtextxy(575, 95, "Don Gia"); outtextxy(575 + 50, 95, "So Tien");
	outtextxy(675, 95, "Khac"); settextstyle(3, 0, 1);
	setfillstyle(1, green); setbkcolor(green); setcolor(BLUE);
	bar(700, 50, 850, 75); rectangle(700, 50, 850, 75); setcolor(WHITE); settextstyle(9, 0, 2);
	outtextxy(780, 70, "Quan Li xe"); setbkcolor(WHITE); setcolor(green); settextstyle(11, 0, 4);
	outtextxy(675 + 50, 95, "SL xe"); outtextxy(775, 95, "Don Gia"); outtextxy(775 + 50, 95, "So Tien");
	setfillstyle(1, yellow); setbkcolor(yellow); setcolor(red);
	bar(850, 50, 1050, 75); rectangle(850, 50, 1050, 75); settextstyle(3, 0, 1);
	outtextxy(950, 70, "Khoan Khac"); setbkcolor(WHITE); setcolor(BLACK); settextstyle(11, 0, 4);
	outtextxy(875, 95, "Ve Sinh"); outtextxy(875 + 50, 95, "TH cap"); outtextxy(975, 95, "internet"); outtextxy(975 + 50, 95, "Khac"); settextstyle(9, 0, 2);
	setfillstyle(1, green); setbkcolor(green); setcolor(red);
	bar(1050, 50, 1350, 75); rectangle(1050, 50, 1350, 75);
	outtextxy(1180, 70, "Tien"); setbkcolor(WHITE); setcolor(BLUE); settextstyle(11, 0, 2);
	outtextxy(1075, 95, "T.phong"); outtextxy(1075 + 50, 95, "T.coc"); outtextxy(1175, 95, "No Cu"); outtextxy(1175 + 50, 95, "Tong"); outtextxy(1275, 95, "Da Thu"); outtextxy(1275 + 50, 95, "Con Lai");
	setfillstyle(1, blue_B); setbkcolor(blue_B); setcolor(yellow);
	bar(1350, 50, 1500, 100); rectangle(1350, 50, 1500, 100); setcolor(WHITE); settextstyle(9, 0, 2);
	outtextxy(1410, 80, "Ghi chu ");
}
void menu_phu() {
	void search_byvt();
	void input_user_menu4(); int exit = 0, x, y;
	void xoa_by_pss();
	cleardevice();
	list_pmn l; create_list_pmn_pmn(l);
	ifstream  f;
	pmn sv;
	f.open("paymoney_service.txt", ios::in);
	if (f.fail())
		cout << "Error file! " << endl;
	while (!f.eof())  //read into endfile.
	{
		pmn sv;
		read_data_pay_money(f, sv);
		nodepmn* p = create_nodepmn_pmn(sv);
		add_nodepmn_pmn_tail(l, p);
	}
	setfillstyle(6, blue_d);
	bar(0, 0, 1520, 850);
	setfillstyle(1, green);
	setcolor(WHITE); setbkcolor(green);
	bar(0, 0, 1520, 40); settextjustify(1, 1);
	settextstyle(9, 0, 0);
	outtextxy(1520 / 2, 30, "Thanh Toan Tien Dich Vu"); settextstyle(9, 0, 3);
	setfillstyle(1, yellow); setcolor(red); setbkcolor(yellow);
	bar(0, 0, 130, 40); outtextxy(60, 30, "<BACK"); setcolor(RED); settextstyle(9, 0, 1);
	rectangle(0, 0, 130, 40);
	setfillstyle(1, blue_B);
	setcolor(yellow);
	bar(1380, 760, 1520, 800); rectangle(1380, 760, 1520, 800); setbkcolor(blue_B); settextstyle(9, 0, 3);
	outtextxy(1450,790, "NEXT>>");
	setfillstyle(1, xinh2); setcolor(WHITE); setbkcolor(xinh2);
	bar(1100, 0, 1310, 40); outtextxy(1210, 30, "Sap Xep"); setcolor(WHITE); rectangle(1100, 0, 1310, 40);
	setfillstyle(1, red); setcolor(WHITE); setbkcolor(red);
	bar(150, 0, 340, 40); outtextxy(250, 30, "ADD DATA"); setcolor(WHITE); rectangle(150, 0, 340, 40); setfillstyle(1, WhatsApp); setcolor(red); setbkcolor(WhatsApp);
	bar(350, 0, 500, 40); outtextxy(420, 30, "Xoa"); setcolor(WHITE); rectangle(350, 0, 500, 40); setfillstyle(1, red); setbkcolor(red);
	bar(1300, 0, 1500, 40); outtextxy(1400, 30, "SEARCH"); setcolor(WHITE); rectangle(1300, 0, 1500, 40);
	main_menu_pay_money_service();
	xuli_pay_money();
	while (exit == 0)
	{
		if (ismouseclick(WM_LBUTTONDOWN)) {
			getmouseclick(WM_LBUTTONDOWN, x, y);
			if ((x >= 0 && x <= 130) && (y >= 0 && y <= 40)) {
				exit = 1; HomePageUIShow();
			}
			else if ((x >= 150 && x <= 340) && (y >= 0 && y <= 40)) {
				setbkcolor(WHITE); settextstyle(9, 0, 3);
				input_user_menu4();
			}
			else if ((x >= 350 && x <= 500) && (y >= 0 && y <= 40)) {
				setbkcolor(WHITE); settextstyle(9, 0, 3);
				xoa_by_pss();
			}
			else if ((x >= 1300 && x <= 1500) && (y >= 0 && y <= 40)) {
				setbkcolor(WHITE); settextstyle(9, 0, 3);
				search_byvt();
			}
			else if ((x>=1100&&x<=1310)&&(y>=0&&y<=40)) {
				setfillstyle(1, yellow); setcolor(BLUE); setbkcolor(yellow); settextstyle(9, 0, 4);
				bar(1100, 0, 1310, 40); outtextxy(1210, 30, "Sap Xep");
				sort_by_room(l);
				save_file_pmn(l); main_menu_pay_money_service(); xuli_pay_money();
			}


		}
	}
}

void xoa_by_pss() {
	cleardevice();
	list_pmn l; create_list_pmn_pmn(l);
	ifstream  f;
	pmn sv;
	f.open("paymoney_service.txt", ios::in);
	if (f.fail())
		cout << "Error file! " << endl;
	while (!f.eof())  //read into endfile.
	{
		pmn sv;
		read_data_pay_money(f, sv);
		nodepmn* p = create_nodepmn_pmn(sv);
		add_nodepmn_pmn_tail(l, p);
	}
	int n = len2(l);
	int flag = 0;
	setfillstyle(6, blue_d);
	bar(0, 0, 1520, 850);
	setfillstyle(1, yellow); setcolor(red); setbkcolor(yellow);
	bar(0, 0, 130, 40); outtextxy(60, 30, "<BACK"); setcolor(RED);
	rectangle(0, 0, 130, 40);
	int exit = 0, x, y;
	setfillstyle(1, blue_B);
	setcolor(yellow);
	bar(1380, 760, 1520, 800); rectangle(1380, 760, 1520, 800); setbkcolor(blue_B); settextstyle(9, 0, 3);
	outtextxy(1450, 790, "NEXT>>");
	setfillstyle(1, xinh);
	setcolor(WHITE); setbkcolor(xinh);
	bar(130, 0, 1520, 40); settextjustify(1, 1);
	settextstyle(9, 0, 4);
	outtextxy(1520 / 2, 30, "Phan Xoa Thong Tin");

	 main_menu_pay_money_service(); xuli_pay_money();
	 setfillstyle(1, red);
	 bar(200,0,300,40);
	 setcolor(yellow); rectangle(200, 0, 300,40);
	 setcolor(WHITE); setbkcolor(red); settextstyle(9, 0, 3);
	 outtextxy(250,30, "VT:");
	 setfillstyle(1, WHITE);
	 bar(300, 0, 500, 40);
	 setcolor(red);
	 rectangle(300, 0, 500, 40);
	 while (exit == 0)
	 {
		 if (ismouseclick(WM_LBUTTONDOWN)) {
			 getmouseclick(WM_LBUTTONDOWN, x, y);
			 if ((x >= 0 && x <= 130) && (y >= 0 && y <= 40)) {
				 exit = 1; setbkcolor(WHITE);
				 menu_phu();
			 }
			 else if ((x>=300&&x<=500)&&(y>=0&&y<=40)) {
				 setfillstyle(1, WHITE);
				 bar(300, 0, 500, 40);
				 setcolor(yellow);
				 rectangle(300, 0, 500, 40);
				 setcolor(BLUE); setbkcolor(yellow);
				 char s[50], s1[50] = " "; settextstyle(9, 0, 3);
				 Input(s, s1, 400, 30, '0', '9', 300, 0, 500, 40); strcpy(s1, s);
				 int positon = atoi(s);
					XoanodepmnCoKhoaBatKy(l, positon);
				save_file_pmn(l); main_menu_pay_money_service(); xuli_pay_money();
				 
			 }
			 
		 }
	 }

}
void search_byvt() {
	cleardevice();
	list_pmn l; create_list_pmn_pmn(l);
	ifstream  f;
	pmn sv;
	f.open("paymoney_service.txt", ios::in);
	if (f.fail())
		cout << "Error file! " << endl;
	while (!f.eof())  //read into endfile.
	{
		pmn sv;
		read_data_pay_money(f, sv);
		nodepmn* p = create_nodepmn_pmn(sv);
		add_nodepmn_pmn_tail(l, p);
	}
	int n = len2(l);
	int flag = 0;
	setfillstyle(6, blue_d);
	bar(0, 0, 1520, 850);
	setfillstyle(1, yellow); setcolor(red); setbkcolor(yellow);
	bar(0, 0, 130, 40); outtextxy(60, 30, "<BACK"); setcolor(RED);
	rectangle(0, 0, 130, 40);
	int exit = 0, x, y;
	setfillstyle(1, xinh2);
	setcolor(WHITE); setbkcolor(xinh2);
	bar(130, 0, 1520, 40); settextjustify(1, 1);
	settextstyle(9, 0, 4);
	outtextxy(1520 / 2+100, 30, "Phan Tim Kiem Thong Tin");
	main_menu_pay_money_service(); 
	setfillstyle(1, red);
	bar(150, 0, 300, 40);
	setcolor(yellow); rectangle(150, 0, 300, 40);
	setcolor(WHITE); setbkcolor(red); settextstyle(9, 0, 3);
	outtextxy(230, 30, "Thang:");
	setfillstyle(1, WHITE);
	bar(300, 0, 550, 40);
	setcolor(red);
	rectangle(300, 0, 550, 40);
	
	while (exit == 0)
	{
		if (ismouseclick(WM_LBUTTONDOWN)) {
			getmouseclick(WM_LBUTTONDOWN, x, y);
			if ((x >= 0 && x <= 130) && (y >= 0 && y <= 40)) {
				exit = 1; setbkcolor(WHITE);
				menu_phu();
			}
			else if ((x>=300&&x<=550)&&(y>=0&&y<=40)) {
				setfillstyle(1, WHITE);
				bar(300, 0, 550, 40);
				setcolor(LIGHTMAGENTA);
				rectangle(300, 0, 550, 40);
				setcolor(BLUE); setbkcolor(yellow);
				char s[50], s1[50] = " "; settextstyle(9, 0, 3);
				Input(s, s1, 400, 30, '0', '9', 300, 0, 500, 40); strcpy(s1, s);
				int positon = atoi(s);
				int i = 120;
				dg rv;
				ifstream ff; ff.open("unit_price.txt", ios::in);
				read_info_electricity_water(ff, rv); ff.close(); main_menu_pay_money_service();
				setbkcolor(WHITE); settextstyle(11, 0, 0);
				for (nodepmn* k = l.phead; k != NULL; k = k->pnext) 
				{
					if (k->data.month ==positon) {
						flag = 1;
						setcolor(red);
						stringstream strs6;
						strs6 << k->data.tenphong;
						string temp_str6 = strs6.str();
						char* char_type6 = (char*)temp_str6.c_str();
						outtextxy(30, i, char_type6);
						//thang
						stringstream strs66;
						strs66 << k->data.month;
						string temp_str66 = strs66.str();
						char* char_type66 = (char*)temp_str66.c_str();
						outtextxy(30 + 45, i, char_type66);
						// dien so cu
						setcolor(green);
						stringstream strs3;
						strs3 << k->data.dsocu;
						string temp_str3 = strs3.str();
						char* char_type3 = (char*)temp_str3.c_str();
						outtextxy(30 + 45 * 2, i, char_type3);
						//dien so moi
						stringstream strs33;
						strs33 << k->data.dsomoi;
						string temp_str33 = strs33.str();
						char* char_type33 = (char*)temp_str33.c_str();
						outtextxy(30 + 45 * 3, i, char_type33);
						// don gia dien
						stringstream strs37;
						strs37 << rv.dien;
						string temp_str37 = strs37.str();
						char* char_type37 = (char*)temp_str37.c_str();
						outtextxy(30 + 45 * 4 + 15, i, char_type37);
						//so tien dien
						stringstream strs370;
						strs370 << (k->data.dsomoi - k->data.dsocu) * rv.dien;
						string temp_str370 = strs370.str();
						char* char_type370 = (char*)temp_str370.c_str();
						outtextxy(30 + 45 * 5 + 20, i, char_type370);
						//nuoc so cu
						setcolor(red);
						stringstream strs334;
						strs334 << k->data.nsocu;
						string temp_str334 = strs334.str();
						char* char_type334 = (char*)temp_str334.c_str();
						outtextxy(30 + 45 * 6 + 20, i, char_type334);
						// nuoc so moi
						stringstream strs335;
						strs335 << k->data.nsomoi;
						string temp_str335 = strs335.str();
						char* char_type335 = (char*)temp_str335.c_str();
						outtextxy(30 + 45 * 7 + 20, i, char_type335);
						//don gia nuoc
						stringstream strs3355;
						strs3355 << rv.nuoc;
						string temp_str3355 = strs3355.str();
						char* char_type3355 = (char*)temp_str3355.c_str();
						outtextxy(30 + 45 * 8 + 30, i, char_type3355);
						//so tien
						stringstream strs3y;
						strs3y << (k->data.nsomoi - k->data.nsocu) * rv.nuoc;
						string temp_str3y = strs3y.str();
						char* char_type3y = (char*)temp_str3y.c_str();
						outtextxy(30 + 45 * 9 + 40, i, char_type3y);
						// nuoc theo nguoi

						//so luong xe
						setcolor(green);
						stringstream strs3356;
						strs3356 << k->data.slxe;
						string temp_str3356 = strs3356.str();
						char* char_type3356 = (char*)temp_str3356.c_str();
						outtextxy(30 + 45 * 15 + 20, i, char_type3356);
						//don gia xe
						stringstream strso;
						strso << rv.quanlixe;
						string temp_stro = strso.str();
						char* char_typeo = (char*)temp_stro.c_str();
						outtextxy(30 + 45 * 16 + 20, i, char_typeo);
						// tong xe
						stringstream strsor;
						strsor << k->data.slxe * rv.quanlixe;
						string temp_stror = strsor.str();
						char* char_typeor = (char*)temp_stror.c_str();
						outtextxy(30 + 45 * 17 + 30, i, char_typeor);
						// chiphi khac
						//ve sinh
						setcolor(BLACK);
						stringstream strsoo;
						strsoo << rv.vesinh;
						string temp_stroo = strsoo.str();
						char* char_typeoo = (char*)temp_stroo.c_str();
						outtextxy(30 + 45 * 18 + 30, i, char_typeoo);
						//th cap
						stringstream strsooo;
						strsooo << rv.thcap;
						string temp_strooo = strsooo.str();
						char* char_typeooo = (char*)temp_strooo.c_str();
						outtextxy(30 + 45 * 19 + 40, i, char_typeooo);
						// internet
						stringstream strsn;
						strsn << rv.internet;
						string temp_strn = strsn.str();
						char* char_typen = (char*)temp_strn.c_str();
						outtextxy(30 + 45 * 20 + 40, i, char_typen);
						//
						//tien coc
						setcolor(BLUE);
						stringstream strsu;
						strsu << k->data.tiencoc;
						string temp_stru = strsu.str();
						char* char_typeu = (char*)temp_stru.c_str();
						outtextxy(30 + 45 * 24 + 15, i, char_typeu);
						// tien phong
						stringstream strsu1;
						strsu1 << rv.tienphong;
						string temp_stru1 = strsu1.str();
						char* char_typeu1 = (char*)temp_stru1.c_str();
						outtextxy(30 + 45 * 23 + 10, i, char_typeu1);
						//no cu
						stringstream strsub;
						strsub << k->data.nocu;
						string temp_strub = strsub.str();
						char* char_typeub = (char*)temp_strub.c_str();
						outtextxy(30 + 45 * 25 + 15, i, char_typeub);
						//total
						stringstream strsubc;
						strsubc << (k->data.dsomoi - k->data.dsocu) * rv.dien + (k->data.nsomoi - k->data.nsocu) * rv.nuoc + k->data.slxe * rv.quanlixe + rv.vesinh + rv.internet + rv.thcap + rv.tienphong + k->data.nocu;
						string temp_strubc = strsubc.str();
						char* char_typeubc = (char*)temp_strubc.c_str();
						outtextxy(30 + 45 * 26 + 30, i, char_typeubc);
						//da thu
						stringstream strsuc;
						strsuc << k->data.dathu;
						string temp_struc = strsuc.str();
						char* char_typeuc = (char*)temp_struc.c_str();
						outtextxy(30 + 45 * 27 + 25, i, char_typeuc);
						// con lai
						stringstream strsuyy;
						strsuyy << (k->data.dsomoi - k->data.dsocu) * rv.dien + (k->data.nsomoi - k->data.nsocu) * rv.nuoc + k->data.slxe * rv.quanlixe + rv.vesinh + rv.internet + rv.thcap + rv.tienphong + k->data.nocu - k->data.dathu;
						string temp_struyy = strsuyy.str();
						char* char_typeuyy = (char*)temp_struyy.c_str();
						outtextxy(30 + 45 * 28 + 33, i, char_typeuyy);
						//ghi chu
						char* c = const_cast<char*>(k->data.note.c_str());

						outtextxy(30 + 45 * 30 + 15, i, c);
						i += 25;
					}
				}
				
			}
			else if (flag == 0) {
			setfillstyle(1, WHITE);
			bar(300, 0, 550, 40); setcolor(red);
			outtextxy(300, 30, "Thang k co!");
		}

		}
	}
}
void input_user_menu4() {
	cleardevice();
	list_pmn l; create_list_pmn_pmn(l);
	ifstream  f; 
	pmn sv;
	f.open("paymoney_service.txt", ios::in);
	if (f.fail())
		cout << "Error file! " << endl;
	while (!f.eof())  //read into endfile.
	{
		pmn sv;
		read_data_pay_money(f, sv);
		nodepmn* p = create_nodepmn_pmn(sv);
		add_nodepmn_pmn_tail(l, p);
	}
	int n = len2(l);
	setfillstyle(6, blue_d);
	bar(0, 0, 1520, 850);
	setfillstyle(1, yellow); setcolor(red); setbkcolor(yellow);
	bar(0, 0, 130, 40); outtextxy(60, 30, "<BACK"); setcolor(RED);
	rectangle(0, 0, 130, 40);
	int exit = 0, x, y;
	setfillstyle(1, xinh);
	setcolor(WHITE); setbkcolor(xinh);
	bar(130, 0, 1520, 40); settextjustify(1, 1);
	settextstyle(9, 0, 4);
	outtextxy(1520 / 2, 30, "Phan Nhap Thong Tin");
	int i = 90;
	setcolor(red);
	rectangle(160, 50, 1200, 690-40*4);
	for (; i <=640+40*2-40*4; i += 40) {
		line(160, i, 1200, i);
	}setcolor(GREEN);
	line(350, 90, 350, 690-40*4);
	//tên phòng
	setcolor(WHITE);
	setfillstyle(1, red); settextstyle(9, 0, 3); setbkcolor(red);
	bar(160, 50, 350, 90); 	setfillstyle(1,blue_B); outtextxy(250, 75, "Ghi Chu");
	//THÁNG
	setbkcolor(blue_B);
	bar(160, 90, 350, 90+40); outtextxy(220+30, 75+40, "Ten Phong");
	//điện số mới
	setfillstyle(1, WhatsApp); setbkcolor(WhatsApp);
	bar(160, 90+40, 350, 90 + 40*2);  outtextxy(250, 75 + 40*2, "Thang");
	setfillstyle(1, yellow); setbkcolor(yellow); setcolor(red);
	//điện số cũ
	bar(160, 90 + 40 * 2, 350, 90 + 40 * 3); outtextxy(250, 75 + 40 * 3, "Dien So Cu"); setbkcolor(LIGHTMAGENTA); setcolor(WHITE);
	// nước 
	setfillstyle(1,LIGHTMAGENTA);//nước cũ
	bar(160, 90 + 40 * 3, 350, 90 + 40 * 4); setfillstyle(1, BROWN); outtextxy(250, 75 + 40 * 4, "Dien So Moi"); setbkcolor(BROWN);
	//nước mới
	bar(160, 90 + 40 * 4, 350, 90 + 40 * 5); outtextxy(260, 75 + 40*5, "Nuoc So Cu");
	setfillstyle(1, LIGHTGRAY); setbkcolor(LIGHTGRAY);
	//nước theo người
	bar(160, 90 + 40 * 5, 350, 90 + 40 * 6); outtextxy(250+8, 75 + 40 * 6, "Nuoc So Moi");
	
	setcolor(red);
	setfillstyle(1, Snapchat); setbkcolor(Snapchat);
	bar(160, 90 + 40 * 6, 350, 90 + 40 * 7);
	outtextxy(250, 75 + 40 * 7, "So Luong Xe");
	setfillstyle(1,green); setbkcolor(green);
	bar(160, 90 + 40 * 7, 350, 90 + 40 * 8);
	outtextxy(250, 75 + 40 * 8, "Tien Coc");
	setfillstyle(1, Snapchat); setbkcolor(Snapchat);
	bar(160, 90 + 40 * 8, 350, 90 + 40 *9);
	outtextxy(250, 75 + 40 * 9,"No Cu"); setcolor(WHITE);
	setfillstyle(1,blue_A); setbkcolor(blue_A);
	bar(160, 90 + 40 * 9, 350, 90 + 40 * 10);
	outtextxy(250, 75 + 40 * 10, "Da Thu");
	//vi tri
	setfillstyle(1, green); setbkcolor(green); setcolor(WHITE);
	bar(160, 90 + 40 * 10, 350, 90 + 40 * 11);
	outtextxy(250, 75 + 40 * 11, "Vi Tri");
	
	bar(350, 720, 750, 760); setcolor(RED); rectangle(350, 720, 750, 760);
	outtextxy(550, 750, "Them Vao Danh Sach");
	setfillstyle(1, YELLOW); setbkcolor(YELLOW); settextstyle(9, 0, 3); settextjustify(1, 1);
	bar(760, 720, 1200, 760); setcolor(RED); rectangle(760, 720, 1200, 760);
	outtextxy(980, 750, "Sua Thong Tin"); setbkcolor(blue_d);
	int postion,diencu,dienmoi,nuoccu,nuocmoi;
	int flag1 = 0,flag=0,checkthang=0;
	while (exit == 0)
	{
		if (ismouseclick(WM_LBUTTONDOWN)) {
			getmouseclick(WM_LBUTTONDOWN, x, y);
			if ((x >= 160 && x <= 1200) && (y >= 50 && y <= 90)) {
				setbkcolor(WHITE);
				setfillstyle(6, blue_d);
				bar(350, 50, 1200, 530);
				bar(0, 540, 1520, 715);
				setcolor(red);
				// draw table again
				rectangle(350, 50, 1200, 90);
				rectangle(350, 90, 1200, 130); rectangle(350, 90 + 40, 1200, 130 + 40);
				rectangle(350, 90 + 40 * 2, 1200, 130 + 40 * 2);
				rectangle(350, 90 + 40 * 3, 1200, 130 + 40 * 3);
				rectangle(350, 90 + 40 * 4, 1200, 130 + 40 * 4);
				rectangle(350, 90 + 40 * 5, 1200, 130 + 40 * 5); rectangle(350, 90 + 40 * 6, 1200, 130 + 40 * 6);
				rectangle(350, 90 + 40 * 7, 1200, 130 + 40 * 7);
				rectangle(350, 90 + 40 * 8, 1200, 130 + 40 * 8);
				rectangle(350, 90 + 40 * 9, 1200, 130 + 40 * 9); rectangle(160, 90 + 40 * 10, 1200, 130 + 40 * 10);
				char s[50], s1[50] = " ";
				setcolor(YELLOW);
				rectangle(160, 50, 1200, 90); setcolor(red);
				Input(s, s1, 700, 80, ' ', 'z', 160, 50, 1200, 90);
				strcpy(s1, s);
				ofstream f; f.open("input_menu8.txt", ios::out);
				f << s << ",";
				f.close();
			}
			else
				if ((x >= 160 && x <= 1200) && (y >= 90 && y <= 130)) {
					setfillstyle(6, blue_d);
					bar(350, 90, 1200, 130);
					char s1[50], s2[50] = " ";
					setcolor(YELLOW);
					rectangle(160, 90, 1200, 130); setcolor(red);
					Input(s1, s2, 700, 120, '0', '9', 160, 90, 1200, 130);
					strcpy(s2, s1);
					int pos = atoi(s1);
					if (pos > 100 ) flag1= 1;
					if (flag1 == 0) {
						ofstream f; f.open("input_menu8.txt", ios::out | ios::app);
						f << s1 << ",";
						f.close();
					}
				}
				else
					if ((x >= 160 && x <= 1200) && (y >= 90 + 40 && y <= 130 + 40)) {
						if (flag1 == 1) {
							setfillstyle(6, blue_d);
							bar(350, 90, 1200, 130); setcolor(YELLOW);
							rectangle(160, 90, 1200, 130); setcolor(red);
							outtextxy(700, 120, "Phong<100"); flag1 = 0;

						}
						else {
							char s2[50], s3[50] = " ";
							setbkcolor(WHITE);
							setfillstyle(6, blue_d);
							bar(350, 90 + 40, 1200, 130 + 40);
							setcolor(YELLOW);
							rectangle(160, 90 + 40, 1200, 130 + 40); setcolor(red);
							Input(s2, s3, 700, 120 + 40, '0', '9', 160, 90 + 40, 1200, 130 + 40);
							strcpy(s3, s2);
							int thangr = atoi(s2);
							if (thangr > 12) checkthang = 1;
							if (checkthang == 0) {
								ofstream f; f.open("input_menu8.txt", ios::out | ios::app);
								f << s2 << ",";
								f.close();
							}
						}
					}
					else
						if ((x >= 160 && x <= 1200) && (y >= 90 + 40 * 2 && y <= 130 + 40 * 2)) {
							if (checkthang == 1)
							{
								setbkcolor(WHITE);
								setfillstyle(6, blue_d);
								bar(350, 90 + 40, 1200, 130 + 40);
								setcolor(red);
								rectangle(350, 90 + 40, 1200, 130 + 40);
								outtextxy(700, 160, "Thang<12"); checkthang= 0;
							}
							else {
								// dien so cu
								char s3[50], s4[50] = " ";
								setcolor(YELLOW);
								rectangle(160, 90 + 40 * 2, 1200, 130 + 40 * 2); setcolor(red);
								Input(s3, s4, 700, 120 + 40 * 2, '0', '9', 160, 90 + 40 * 2, 1200, 130 + 40 * 2);
								strcpy(s4, s3);
								diencu = atoi(s3);
								ofstream f; f.open("input_menu8.txt", ios::out | ios::app);
								f << s3 << ",";
								f.close();
							}
						}
						else
							if ((x >= 160 && x <= 1200) && (y >= 90 + 40 * 3 && y <= 130 + 40 * 3)) {
								setfillstyle(6, blue_d);
								bar(350, 90 + 40 * 3, 1200, 130 + 40 * 3);
								// dien so moi
								char s4[50], s5[50] = " ";
								setcolor(YELLOW);
								rectangle(160, 90 + 40 * 3, 1200, 130 + 40 * 3); setcolor(red);
								Input(s4, s5, 700, 120 + 40 * 3, '0', '9', 160, 90 + 40 * 3, 1200, 130 + 40 * 3);
								strcpy(s5, s4);
								dienmoi = atoi(s4);
								if (dienmoi < diencu) flag1 = 1;
								if (dienmoi > diencu) {
								ofstream f; f.open("input_menu8.txt", ios::out | ios::app);
								f << s4 << ",";
								f.close();
							}
							}
							else
								if ((x >= 160 && x <= 1200) && (y >= 90 + 40 * 4 && y <= 130 + 40 * 4)) {
									// nuoc so cu
									if (flag1 == 1) {
										setfillstyle(6, blue_d);
										bar(350, 90 + 40 * 3, 1200, 130 + 40 * 3); setcolor(YELLOW);
										rectangle(160, 90 + 40 * 3, 1200, 130 + 40 * 3); setcolor(red);
										outtextxy(700, 120 + 40 * 3, "Dien So Moi>Dien So Cu"); flag1 = 0;
									}
									else {
										char s5[50], s6[50] = " ";
										setcolor(YELLOW);
										rectangle(160, 90 + 40 * 4, 1200, 130 + 40 * 4); setcolor(red);
										Input(s5, s6, 700, 120 + 40 * 4, '0', '9', 160, 90 + 40 * 4, 1200, 130 + 40 * 4);
										strcpy(s6, s5);
										nuoccu = atoi(s5);
										ofstream f; f.open("input_menu8.txt", ios::out | ios::app);
										f << s5 << ",";
										f.close();
									}
								}
								else
									if ((x >= 160 && x <= 1200) && (y >= 90 + 40 * 5 && y <= 130 + 40 * 5)) {
										setfillstyle(6, blue_d);
										bar(350, 90 + 40 * 5, 1200, 130 + 40 * 5);
										char s6[50], s7[50] = " ";
										setcolor(YELLOW);
										rectangle(160, 90 + 40 * 5, 1200, 130 + 40 * 5); setcolor(red);
										Input(s6, s7, 700, 120 + 40 * 5, '0', '9', 160, 90 + 40 * 5, 1200, 130 + 40 * 5);
										strcpy(s7, s6);
										// nuoc so moi
										nuocmoi = atoi(s6);
										if (nuocmoi < nuoccu) flag = 1;
										if (nuocmoi > nuoccu) {
											ofstream f; f.open("input_menu8.txt", ios::out | ios::app);
											f << s6 << ",";
											f.close();
										}
									}
									else
										if ((x >= 160 && x <= 1200) && (y >= 90 + 40 * 6 && y <= 130 + 40 * 6)) {
											if (flag == 1) {
												setfillstyle(6, blue_d);
												bar(350, 90 + 40 * 5, 1200, 130 + 40 * 5); setcolor(YELLOW);
												rectangle(160, 90 + 40 * 5, 1200, 130 + 40 * 5); setcolor(red);
												outtextxy(700, 120 + 40 * 5, "Nuoc So Moi>Nuoc So Cu"); flag = 0;
											}
											else {


												char s7[50], s8[50] = " ";
												setcolor(YELLOW);
												rectangle(160, 90 + 40 * 6, 1200, 130 + 40 * 6); setcolor(red);
												Input(s7, s8, 700, 120 + 40 * 6, '0', '9', 160, 90 + 40 * 6, 1200, 130 + 40 * 6);
												strcpy(s8, s7);

												ofstream f; f.open("input_menu8.txt", ios::out | ios::app);
												f << s7 << ",";
												f.close();
											}
											
										}
										else
											if ((x >= 160 && x <= 1200) && (y >= 90 + 40 * 7 && y <= 130 + 40 * 7)) {
												
													char s8[50], s9[50] = " ";
													setcolor(YELLOW);
													rectangle(160, 90 + 40 * 7, 1200, 130 + 40 * 7); setcolor(red);
													Input(s8, s9, 700, 120 + 40 * 7, '0', '9', 160, 90 + 40 * 7, 1200, 130 + 40 * 7);
													strcpy(s9, s8);
													ofstream f; f.open("input_menu8.txt", ios::out | ios::app);
													f << s8 << ",";
													f.close();
												
											}
											else
												if ((x >= 160 && x <= 1200) && (y >= 90 + 40 * 8 && y <= 130 + 40 * 8)) {
													char s9[50], s10[50] = " ";
													setcolor(YELLOW);
													rectangle(160, 90 + 40 * 8, 1200, 130 + 40 * 8); setcolor(red);
													Input(s9, s10, 700, 120 + 40 * 8, '0', '9', 160, 90 + 40 * 8, 1200, 130 + 40 * 8);
													strcpy(s10, s9);
													ofstream f; f.open("input_menu8.txt", ios::out | ios::app);
													f << s10;
													f.close();
												}
												else
													if ((x >= 160 && x <= 1200) && (y >= 90 + 40 * 9 && y <= 130 + 40 * 9)) {
														char s77[50], s87[50] = " ";
														setcolor(YELLOW);
														rectangle(160, 90 + 40 * 9, 1200, 130 + 40 * 9); setcolor(red);
														Input(s77, s87, 700, 120 + 40 * 9, '0', '9', 160, 90 + 40 * 9, 1200, 130 + 40 * 9);
														strcpy(s87, s77);
														ofstream f; f.open("input_menu8.txt", ios::out | ios::app);
														f << s77;
														f.close();
													}
													else
														if ((x >= 160 && x <= 1200) && (y >= 90 + 40 * 10 && y <= 130 + 40 * 10)) {
															char s99[50], s109[50] = " ";
															setcolor(YELLOW);
															rectangle(160, 90 + 40 * 10, 1200, 130 + 40 * 10); setcolor(red);
															Input(s99, s109, 700, 120 + 40 * 10, '0', '9', 160, 90 + 40 * 10, 1200, 130 + 40 * 10);
															strcpy(s109, s99);
					
															ofstream f; f.open("try.txt", ios::out);
															f << s99 << ",";
															f.close();
														}
														else if ((x >= 350 && x <= 750) && (y >= 720 && y <= 760)) {
															setcolor(yellow);
															rectangle(350, 720, 750, 760); setcolor(red);
															settextjustify(0, 1);
															outtextxy(350, 710, "Them Thanh Cong ");
															ifstream fm; fm.open("try.txt", ios::in);
															fm >> postion; fm.close();
															ifstream f; f.open("input_menu8.txt", ios::in);
															read_data_pay_money(f, sv);
															f.close();
															nodepmn* p = create_nodepmn_pmn(sv);
															Themnodepmn_p_VaoViTriBatKi(l, p, postion, n);
															save_file_pmn(l);
															
														}

													else if ((x >= 0 && x <= 130) && (y >= 0 && y <= 40)) {
														exit = 1; setbkcolor(WHITE);
														menu_phu();
													}
													else if ((x>=760&&x<=1200)&&(y>=720&&y<=760)) {
															setfillstyle(1, red); setbkcolor(red); settextstyle(9, 0, 3); settextjustify(1, 1);
															bar(760, 720, 1200, 760); setcolor(blue); rectangle(760, 720, 1200, 760); setcolor(WHITE);
															outtextxy(980, 750, "Sua Thong Tin"); setcolor(red);
															outtextxy(790, 710, "Sua Thanh Cong!");
															setbkcolor(blue_d);
															ifstream fm; fm.open("try.txt", ios::in);
															fm >> postion; fm.close();
															edit_by_vt(l, postion);
															save_file_pmn(l);
														}
		}
	}
}
void menu_chinh_4() {
	
	menu_phu();
	
	
}