#include"datphong.h"
void draw_statistical_box_2_1() {
	setfillstyle(1, WHITE);
	bar(0, 270 - 25 * 2, 1520, 727);
	setcolor(blue_d);
	
	setfillstyle(1, blue);
	bar(0, 220, 1520, 220 + 29);
	setcolor(green);
	rectangle(0, 270 - 25 * 2, 1520, 727);
	int i = 247;
	for (; i <= 727; i += 32) {
		line(0, i, 1520, i);
	}
	i = 0;
	for (; i <= 300; i += 100) {
		line(i, 220, i, 727);
	}
	i = 300;
	for (; i <= 1520; i += 175) {
		line(i, 220, i, 727);
	}
	//noi dung 
	setcolor(BLUE); setbkcolor(yellow);
	outtextxy(50, 240, "Phong");
	outtextxy(50 + 100, 240, "T.Trang"); outtextxy(250, 240, "L.Phong");
	outtextxy(400, 240, "Ho Ten");
	outtextxy(400 + 175, 240, "Ngay Vao"); outtextxy(575 + 175, 240, "Ngay Dat");
	outtextxy(575 + 175 * 2, 240, "Tien Coc");	outtextxy(575 + 175 * 3, 240, "SO DT");
	outtextxy(575 + 175 * 4, 240, "Ghi Chu"); outtextxy(560 + 175 * 5 - 10, 240, "Dia Chi");

}void xuattheo_vitri(listdtp l, int start, int endt) {
	
	int i=230 + 40, dem = 0, dem2 = 0, j = 0;
	setbkcolor(WHITE);
	for (nodedtp* k = l.phead; k != NULL; k = k->pnext)
	{
		dem++;
		dem2++;
		if (dem == start) {
			dem--;
			outtextxy(30, i, k->data.tenphong);
			stringstream strs2;
			strs2 << k->data.state;
			string m2 = strs2.str();
			char* char_type2 = (char*)m2.c_str();
			outtextxy(30 + 100, i, char_type2);
			//loai phong
			stringstream strs23;
			strs23 << k->data.lphong;
			string m23 = strs23.str();
			char* char_type23 = (char*)m23.c_str();
			outtextxy(230, i, char_type23);
			char* cccb = const_cast<char*>(k->data.name.c_str());
			outtextxy(230 + 175 - 90, i, cccb);

			outtextxy(230 + 175 * 2 - 80, i, k->data.ngaydat);
			outtextxy(230 + 175 * 3 - 80, i, k->data.ngayvao);
			outtextxy(230 + 175 * 4 - 80, i, k->data.tiencoc);
			outtextxy(230 + 175 * 5 - 80, i, k->data.std);
			char* c = const_cast<char*>(k->data.note.c_str());
			outtextxy(230 + 175 * 6 - 80, i, c);
			char* cr = const_cast<char*>(k->data.adress.c_str());
			outtextxy(230 + 175 * 7 - 80, i, cr);

			i += 32;
		}
		if (dem2 == endt) break;
	}
}
void draw_inbox() {
	setfillstyle(1, WHITE);
	bar(50, 40,650, 220);
	setcolor(BLACK);
	rectangle(50, 40, 650, 215);
	int i = 40 + 25;
	for (; i <220; i += 25)
		line(50, i,650, i);
	line(250, 40, 250, 215); setbkcolor(WHITE);
	setcolor(BLUE); settextjustify(0, 1);
	settextstyle(9, 0,1);
	outtextxy(55, 60, "Ho Ten:");
	outtextxy(55, 60+25, "Dia Chi:");	outtextxy(55, 110, "Ghi Chu:");
	outtextxy(55, 60 + 25*3, "So Dien Thoai:");
	outtextxy(55, 60 + 25 * 4, "Tien Coc:");
	outtextxy(55, 60 + 25 * 5, "Ngay Dat:"); outtextxy(55, 60 + 25 * 6, "Ngay Vao:");
	setcolor(BLACK);
	setfillstyle(1, WHITE);
	bar(650, 40, 1050, 40 + 25 * 4);
	rectangle(650, 40, 1050, 40 + 25 * 4);
	 i = 40 + 25;
	for (; i <40+25*4; i += 25)
		line(650, i, 1050, i);
	line(800, 40, 800, 40 + 25 * 4); setcolor(red);
	outtextxy(655, 60, "Loai Phong:"); outtextxy(655, 60+25*2, " Phong:"); outtextxy(655, 60 + 25 , "Tinh Trang:");
	outtextxy(655, 60+25*3, "Vi Tri:");
}
void empty_room() {
	int exit = 0, x, y;
	int a[100];
	int r[100];
	for (int rr = 1; rr <= 100; rr++)
		r[rr] = rr;
	void main_menu_hopdong();
	setbkcolor(WHITE);
	cleardevice();
	setfillstyle(8, blue_d);
	bar(0, 0, 1520, 850);
	setfillstyle(1, xinh2);
	setcolor(WHITE); setbkcolor(xinh2);
	bar(0, 0, 1520, 40); settextjustify(1, 1);
	settextstyle(9, 0, 0);
	outtextxy(1520 / 2, 30, "DANH SACH PHONG TRONG"); settextstyle(9, 0, 3);
	setfillstyle(1, yellow); setcolor(red); setbkcolor(yellow);
	bar(0, 0, 130, 40); outtextxy(60, 30, "<BACK"); setcolor(RED);
	rectangle(0, 0, 130, 40);
	setcolor(red); rectangle(200, 100, 900, 700);
	int i = 270;
	for (; i <= 900; i += 70) line(i, 100, i, 700);
	i = 160; setcolor(YELLOW);
	for (; i <= 700; i += 60) line(200, i, 900,i);
	ifstream f; f.open("list_phong_daco_nguoi.txt", ios::in);
	i = 1;
	int dem = 1;
	while (f.eof() == false) {
		f >> a[i];
		dem++;
		i++;
		
	}
	
	int m=230,n=150;
	int kk = 1;
	setbkcolor(WHITE); setcolor(red);
	for (int i = 1; i <= 10; i++)
	{
		for (int j = 1; j <= 10; j++) {
			if ((a[kk] > 0)) {
				stringstream strs4;
				strs4 << a[kk];
				string temp_str4 = strs4.str();
				char* char_type4 = (char*)temp_str4.c_str();
				outtextxy(m, n, char_type4);
				m += 70; kk++;
			}
			
		}
		m = 230;
		n += 60;
	}setlinestyle(1, 1, 1);
	setfillstyle(1, red);
	bar(980, 220, 1320, 290);
	setcolor(yellow);
	rectangle(980, 220, 1320, 290); setcolor(WHITE); setbkcolor(red);
	outtextxy(1150, 260, "Tong So Phong Trong");
	setcolor(LIGHTMAGENTA);
	rectangle(980, 290, 1320, 290 + 50);
	setcolor(BLACK); setbkcolor(WHITE);
	stringstream strs4;
	strs4 << dem-2;
	string temp_str4 = strs4.str();
	char* char_type4 = (char*)temp_str4.c_str(); settextstyle(9, 0, 5);
	outtextxy(1130, 260+70, char_type4);
	while (exit == 0)
	{
		if (ismouseclick(WM_LBUTTONDOWN)) {
			getmouseclick(WM_LBUTTONDOWN, x, y);
			if ((x >= 0 && x <= 130) && (y >= 0 && y <= 40)) {
				exit = 1; setbkcolor(WHITE); setlinestyle(0, 0, 0);
				main_menu_hopdong();
			}
			
		}
	}
	
}
void search_phong() {
	int exit = 0, x, y; setbkcolor(WHITE);
	cleardevice(); 
	void main_menu_hopdong();
	listdtp l; create_listdtp_dtp(l);
	ifstream  f;

	dtp sv;
	f.open("datphong.txt", ios::in);
	if (f.fail())
		cout << "Error file! " << endl;
	while (!f.eof())  //read into endfile.
	{
		dtp sv;
		Read_1_dpt(f, sv);
		nodedtp* p = create_node_dtp(sv);
		add_node_dtp_tail(l, p);
	}

	setfillstyle(1, blue_B);
	setcolor(WHITE); setbkcolor(blue_B);
	bar(0, 0, 1520, 40); settextjustify(1, 1);
	settextstyle(9, 0, 0);
	outtextxy(1520 / 2, 30, "TIM KIEM THEO PHONG"); settextstyle(9, 0, 3);
	setfillstyle(1, yellow); setcolor(red); setbkcolor(yellow);
	bar(0, 0, 130, 40); outtextxy(60, 30, "<BACK"); setcolor(RED);
	rectangle(0, 0, 130, 40); settextstyle(9, 0, 1);
	draw_statistical_box_2_1();
	settextstyle(9, 0, 5);
	rectangle(0, 0, 130, 40);
	setfillstyle(1, red);
	bar(100, 100, 450, 150);
	setcolor(yellow); setbkcolor(red);
	rectangle(100, 100, 450, 150);
	setcolor(WHITE);
	outtextxy(270, 140, "Nhap Phong:"); 
	settextstyle(9, 0, 3);
	setcolor(GREEN); setcolor(red);
	rectangle(450, 100, 800, 150); setcolor(WHITE); int i = 230 + 40; danhso(l); setcolor(red);
	while (exit == 0)
	{
		if (ismouseclick(WM_LBUTTONDOWN)) {
			getmouseclick(WM_LBUTTONDOWN, x, y);
			if ((x >= 0 && x <= 130) && (y >= 0 && y <= 40)) {
				setbkcolor(WHITE);
				exit = 1; main_menu_hopdong();
			}
			else if ((x>=450&&x<=800)&&(y>=100&&y<=150)) {
				
				settextstyle(9, 0, 4);
				setfillstyle(1, WHITE);
				bar(450, 100, 800, 150);
				setcolor(yellow);
				rectangle(450, 100, 800, 150);
				char t[50], t1[50] = " "; setcolor(BLACK); setbkcolor(WHITE);
				Input(t, t1, 600, 130, '0', '9', 450, 100, 800, 150);
				strcpy(t1, t); setcolor(red);
				int postion = atoi(t); settextstyle(9, 0, 1);
				draw_statistical_box_2_1(); setbkcolor(WHITE); i = 230 + 40;
				for (nodedtp* k = l.phead; k != NULL; k = k->pnext) {
					int uu = atoi(k->data.tenphong);
					
					if (uu==postion) {
						outtextxy(30, i, k->data.tenphong);
						stringstream strs2;
						strs2 << k->data.state;
						string m2 = strs2.str();
						char* char_type2 = (char*)m2.c_str();
						outtextxy(30 + 100, i, char_type2);
						//loai phong
						stringstream strs23;
						strs23 << k->data.lphong;
						string m23 = strs23.str();
						char* char_type23 = (char*)m23.c_str();
						outtextxy(230, i, char_type23);
						char* cccb = const_cast<char*>(k->data.name.c_str());
						outtextxy(230 + 175 - 20, i, cccb);

						outtextxy(230 + 175 * 2 - 50, i, k->data.ngaydat);
						outtextxy(230 + 175 * 3 - 50, i, k->data.ngayvao);
						outtextxy(230 + 175 * 4 - 50, i, k->data.tiencoc);
						outtextxy(230 + 175 * 5 - 50, i, k->data.std);
						char* c = const_cast<char*>(k->data.note.c_str());
						outtextxy(230 + 175 * 6 - 50, i, c);
						char* cr = const_cast<char*>(k->data.adress.c_str());
						outtextxy(230 + 175 * 7 - 40, i, cr);

						i += 32;
					}
				}
			}
		}
		
		
	}
}
void guid() {
	setbkcolor(WHITE);
	cleardevice();
	int x, y,exit=0;
	setfillstyle(6, blue_d);
	bar(0, 0, 1520, 850);
	setfillstyle(1, xinh2);
	setcolor(WHITE); setbkcolor(xinh2);
	bar(0, 0, 1520, 40); settextjustify(1, 1);
	settextstyle(9, 0, 0);
	outtextxy(1520 / 2, 30, "HUONG DAN"); settextstyle(9, 0, 3);
	setfillstyle(1, yellow); setcolor(red); setbkcolor(yellow);
	bar(0, 0, 130, 40); outtextxy(60, 30, "<BACK"); 
	settextstyle(9, 0, 3);
	setcolor(red); setbkcolor(WHITE); settextjustify(0, 1);
	outtextxy(400, 100, "I.Co 3 Trang Thai");
	outtextxy(400, 120, "1.Da Vao");
	outtextxy(400, 140, "2.Chua Vao");
	outtextxy(400, 160, "0.Huy");
	outtextxy(400, 200, "Xem Phong Trong Truoc Khi Dat Phong.");
	outtextxy(400, 250, "Co  3 loai phong la 1,2,3");
	while (exit == 0)
	{
		if (ismouseclick(WM_LBUTTONDOWN)) {
			getmouseclick(WM_LBUTTONDOWN, x, y);
			if ((x >= 0 && x <= 130) && (y >= 0 && y <= 40)) {
				exit = 1; setbkcolor(WHITE); setlinestyle(0, 0, 0);
				main_menu_hopdong();
			}

		}
	}

}
void nhap_datphong() {
	void xuli_hopdong();
	int exit = 0,x,y,postion=0,exit1=0;
	listdtp l; create_listdtp_dtp(l);
	ifstream  f; 
	
	dtp sv;
	f.open("datphong.txt", ios::in);
	if (f.fail())
		cout << "Error file! " << endl;
	while (!f.eof())  //read into endfile.
	{
		dtp sv;
		Read_1_dpt(f, sv);
		nodedtp* p = create_node_dtp(sv);
		add_node_dtp_tail(l, p);
	}
	

	


	rectangle(800, 165, 950, 220);
	setcolor(red); setbkcolor(WHITE);
	rectangle(1050, 165, 1200, 220); //settextjustify(0, 1);
	outtextxy(1060, 200, "VT:");
	setfillstyle(1, red);
	bar(1210, 165, 1350, 220); setcolor(BLUE);
	rectangle(1210, 165, 1350, 220); setcolor(WHITE);
	settextstyle(9, 0, 4);
	setbkcolor(red);
	outtextxy(1250, 200, "Sort");
	int n = len2(l); 
	danhso(l);
	int flag = 0;
	settextstyle(9, 0, 1);
	while (exit==0)
	{
		setbkcolor(BLUE);
		if (ismouseclick(WM_LBUTTONDOWN)) {
			getmouseclick(WM_LBUTTONDOWN, x, y);
			if ((x >= 50 && x <= 650) && (y >= 40 && y <= 40 + 25)) {
				setcolor(YELLOW);
				rectangle(50, 40, 650, 40 + 25);
				char s[50], s1[50] = " ";
				Input(s, s1, 260, 60, ' ', 'z', 50, 40, 650, 65); strcpy(s1, s);
				ofstream f; f.open("input_menu8.txt", ios::out);
				f << s << ","; f.close();
			}
			else
				if ((x >= 50 && x <= 650) && (y >= 40+25 && y <= 40 + 25*2)) {
					setcolor(YELLOW);
					rectangle(50, 40+25, 650, 40 + 25*2);
					char s1[50], s2[50] = " ";
					Input(s1, s2, 260, 60+25, ' ', 'z', 50, 40+25, 650, 65+25); strcpy(s2, s1);
					ofstream f; f.open("input_menu8.txt", ios::out|ios::app);
					f << s1 << ","; f.close();
				}
				else
					if ((x >= 50 && x <= 650) && (y >= 40 + 25*2 && y <= 40 + 25 * 3)) {
						setcolor(YELLOW);
						rectangle(50, 40 + 25*2, 650, 40 + 25 * 3);
						char s2[50], s3[50] = " ";
						Input(s2, s3, 260, 60 + 25*2, ' ', 'z', 50, 40 + 25*2, 650, 65 + 25*2); strcpy(s3, s2);
						ofstream f; f.open("input_menu8.txt", ios::out | ios::app);
						f << s2 << ","; f.close();
					}
					else
						if ((x >= 50 && x <= 650) && (y >= 40 + 25 * 3 && y <= 40 + 25 * 4)) {
							setcolor(YELLOW);
							rectangle(50, 40 + 25 * 3, 650, 40 + 25 * 4);
							char s3[50], s4[50] = " ";
							Input(s3, s4, 260, 60 + 25 * 3, '0', '9', 50, 40 + 25 * 3, 650, 65 + 25 * 3); strcpy(s4, s3);
							ofstream f; f.open("input_menu8.txt", ios::out | ios::app);
							f << s3 <<" "<< ","; f.close();
						}
						else
							if ((x >= 50 && x <= 650) && (y >= 40 + 25 * 4 && y <= 40 + 25 * 5)) {
								setcolor(YELLOW);
								rectangle(50, 40 + 25 * 4, 650, 40 + 25 * 5);
								char s4[50], s5[50] = " ";
								Input(s4, s5, 260, 60 + 25 * 4, '0', '9', 50, 40 + 25 * 4, 650, 65 + 25 * 4); strcpy(s5, s4);
								ofstream f; f.open("input_menu8.txt", ios::out | ios::app);
								f << s4 <<" "<< ","; f.close();
							}
							else
								if ((x >= 50 && x <= 650) && (y >= 40 + 25 * 5 && y <= 40 + 25 * 6)) {
									//ngay dat
									setcolor(YELLOW);
									rectangle(50, 40 + 25 * 5, 650, 40 + 25 * 6);
									char s5[50], s6[50] = " ";
									Input(s5, s6, 260, 60 + 25 * 5, '/', '9', 50, 40 + 25 * 5, 650, 65 + 25 * 5); strcpy(s6, s5);
									ofstream fr; fr.open("try.txt", ios::out);
									fr << s5;
									ofstream f; f.open("input_menu8.txt", ios::out | ios::app);
									f << s5 << " " << ","; f.close();
								}
								else
									if ((x >= 50 && x <= 650) && (y >= 40 + 25 * 6 && y <= 40 + 25 * 7)) {
										//ngay vao
										setcolor(YELLOW);
										rectangle(50, 40 + 25 * 6, 650, 40 + 25 * 7);
										char s6[50], s7[50] = " ";
										Input(s6, s7, 260, 60 + 25 * 6, '/', '9', 50, 40 + 25 * 6, 650, 65 + 25 * 6); strcpy(s7, s6);
										ofstream fe; fe.open("sv-khoanchi.txt", ios::out);

										ofstream f; f.open("input_menu8.txt", ios::out | ios::app);
										f << s6 << " " << ","; f.close();
									}
									else
										if ((x >650 && x <= 1050) && (y >= 40  && y <= 40 + 25)) {
											
											setcolor(LIGHTMAGENTA);
											rectangle(650, 40 , 1050, 40 + 25 );
											char s7[50], s8[50] = " "; setcolor(WHITE); setbkcolor(red);
											Input(s7, s8, 820, 60, '1', '3', 650, 40, 1050, 65 ); strcpy(s8, s7);
											ofstream f; f.open("input_menu8.txt", ios::out | ios::app);
											f << s7 << ","; f.close();
										}
										else
											if ((x >650 && x <= 1050) && (y >= 40 + 25 && y <= 40 + 25 * 2)) {
												setcolor(YELLOW);
												rectangle(650, 40 + 25 , 1050, 40 + 25*2);
												char s8[50], s9[50] = " ";
												Input(s8, s9, 820, 60 + 25, '0', '9', 650, 40 + 25, 1050, 65 + 25); strcpy(s9, s8);
												ofstream f; f.open("input_menu8.txt", ios::out | ios::app);
												f << s8 << ","; f.close();
											}
											else
												if ((x > 650 && x <= 1050) && (y >= 40 + 25 * 2 && y <= 40 + 25 * 3)) {
													setfillstyle(1, WHITE);
													bar(800, 40 + 25 * 2, 1050, 40 + 25 * 3);
													setcolor(YELLOW);
													rectangle(800, 40 + 25 * 2,1050, 40 + 25 * 3);
													char s9[50], s10[50] = " ";
													Input(s9, s10,820, 60 + 25 * 2, '0', '9', 820, 40 + 25 * 2, 1050, 65 + 25*2 ); strcpy(s10, s9);
													int check1 = atoi(s9);
													if (check1 > 100) flag = 1;
													if (flag == 0) {
														ofstream f; f.open("input_menu8.txt", ios::out | ios::app);
														f << s9; f.close();
													}
												}
												else
													if ((x > 650 && x <= 1050) && (y >= 40 + 25 * 3 && y <= 40 + 25 * 4)) {
														if (flag == 1) {

															setfillstyle(1, WHITE);
															bar(800, 40 + 25 * 2, 1050, 40 + 25 * 3);
															setcolor(BLACK);
															rectangle(800, 40 + 25 * 2, 1050, 40 + 25 * 3);
															setcolor(red); setbkcolor(WHITE);
															outtextxy(820, 60 + 25 * 2, "Phong<100"); flag = 0;
														}
														else {
															setcolor(YELLOW);
															rectangle(650, 40 + 25 * 3, 1050, 40 + 25 * 4);
															char s99[50], s109[50] = " ";
															Input(s99, s109, 820, 60 + 25 * 3, '0', '9', 820, 40 + 25 * 3, 1050, 65 + 25 * 3); strcpy(s109, s99);
															ofstream f; f.open("try.txt", ios::out);
															f << s99; f.close();
														}
													}
													else if ((x>=650&&x<=800)&&(y>=165&&y<=220)){
														ifstream f; f.open("try.txt", ios::in);
														f >> postion; f.close();
														ifstream fk; fk.open("input_menu8.txt", ios::in);
														Read_1_dpt(fk, sv); fk.close();
														nodedtp* p = create_node_dtp(sv);
														ThemNode_p_VaoViTriBatKi(l, p, postion, n);
														ofstream fi; fi.open("datphong.txt", ios::out);
														save_file_pht_dpt(l);
														fi.close(); draw_inbox(); settextjustify(1, 1);
														draw_statistical_box_2_1(); setcolor(red); settextjustify(0, 1);
														xuli_hopdong();
													}
													else if ((x>=950&&x<=1050)&&(y>=165&&y<=220)) {
														ifstream f; f.open("try.txt", ios::in);
														f >> postion; f.close();
														ifstream fk; fk.open("input_menu8.txt", ios::in);
														Read_1_dpt(fk, sv); fk.close();
														edit_by_postion(l, postion);
														ofstream fi; fi.open("datphong.txt", ios::out);
														save_file_pht_dpt(l);
														fi.close(); draw_inbox(); settextjustify(1, 1);
														draw_statistical_box_2_1(); setcolor(red); settextjustify(0, 1);
														xuli_hopdong();
													}
													else if ((x>=1050&&x<=1200)&&(y>=165&&y<=220)) {
														setcolor(BLACK);
														setbkcolor(WHITE);
														char t[50], t1[50] = " ";
														 setcolor(BLACK);
														Input(t, t1,1120, 200, '0', '9', 1050, 165, 1200, 220);
														strcpy(t1, t);
														postion = atoi(t);
														XoaNodeCoKhoaBatKy(l, postion);
														save_file_pht_dpt(l);
														 draw_inbox();
														draw_statistical_box_2_1(); setcolor(red);
														xuli_hopdong();
													}
													else if ((x>=1320&&x<=1460)&&(y<=780&&y>=750)){

														xuli_hopdong();
													}
													else
														if ((x >= 0 && x <= 130) && (y >= 0 && y <= 40)) {
															exit = 1; HomePageUIShow();
														}
														else if ((x>=1000&&x<=1100)&&(y>=0&&y<=40)) {
															guid();

														}
														else if ((x>=1210&&x<=1350)&&(y>=165&&y<=220)) {
															setfillstyle(1, green);
															bar(1210, 165, 1350, 220); setcolor(red);
															rectangle(1210, 165, 1350, 220); setcolor(WHITE);
															settextstyle(9, 0, 5);
															setbkcolor(green);
															outtextxy(1230, 200, "Sort");
															sapxep(l);
															save_file_pht_dpt(l);
															
															draw_inbox();

															draw_statistical_box_2_1(); setcolor(red);
															xuli_hopdong();
														}
														else if ((x>=150&&x<=500)&&(y>=0&&y<=40)) {
															empty_room(); setbkcolor(WHITE);
														}
														else if ((x>=1150&&x<=1350)&&(y>=0&&y<=40)) {
															search_phong(); setbkcolor(WHITE);
														}

		}
	}
	
}

void xuli_hopdong() {
	
	setcolor(RED);
	listdtp l; create_listdtp_dtp(l);
	ifstream  f; int x, y, exit = 0, demlist = 0, j = 0;
	int exit1 = 0,postion;
	dtp sv;
	f.open("datphong.txt", ios::in);
	if (f.fail())
		cout << "Error file! " << endl;
	while (!f.eof())  //read into endfile.
	{
		dtp sv;
		Read_1_dpt(f, sv);
		nodedtp* p = create_node_dtp(sv);
		add_node_dtp_tail(l, p);
	}
	// ve chu nhat
	setfillstyle(1, WHITE);
	bar(1080, 50, 1200, 120); setbkcolor(WHITE);
	setcolor(green);
	outtextxy(1090, 60, "Da Vao:");
	setcolor(BLUE);
	outtextxy(1090, 60 + 25, "Chua Vao:"); setcolor(red);
	outtextxy(1090, 60 + 25 * 2, "Huy:");
	int vao = 0, chuavao = 0, huy = 0;
	for (nodedtp* k = l.phead; k != NULL; k = k->pnext) {
		if (k->data.state == 1) vao++;
		if (k->data.state == 0) huy++;
		if (k->data.state == 2) chuavao++;
	}
	//da vao
	setcolor(GREEN);
	stringstream strs2;
	strs2 << vao;
	string m2 = strs2.str();
	char* char_type2 = (char*)m2.c_str();
	outtextxy(1190, 60, char_type2);
	// chua vao
	setcolor(BLUE);
	stringstream strs22;
	strs22 << chuavao;
	string m22 = strs22.str();
	char* char_type22 = (char*)m22.c_str();
	outtextxy(1210, 60+25, char_type22);
	//da vao
	setcolor(red);
	stringstream strs223;
	strs223 << huy;
	string m223 = strs223.str();
	char* char_type223 = (char*)m223.c_str();
	outtextxy(1190, 60 + 25*2, char_type223);

	int len_list = len2(l);
	f.close();
	int i = 230 + 40; danhso(l); setbkcolor(WHITE); settextjustify(0, 1);
	for (nodedtp* k = l.phead; k != NULL; k = k->pnext) {
		demlist++;
		outtextxy(30, i, k->data.tenphong);
		stringstream strs2;
		strs2 << k->data.state;
		string m2 = strs2.str();
		char* char_type2 = (char*)m2.c_str();
		outtextxy(30 + 100, i, char_type2);
		//loai phong
		stringstream strs23;
		strs23 << k->data.lphong;
		string m23 = strs23.str();
		char* char_type23 = (char*)m23.c_str();
		outtextxy(230, i, char_type23);
		char* cccb = const_cast<char*>(k->data.name.c_str());
		outtextxy(230 + 175-90, i, cccb); 
		
		outtextxy(230 + 175*2-80, i, k->data.ngaydat);
		outtextxy(230 + 175 * 3-80, i, k->data.ngayvao);
		outtextxy(230 + 175 * 4-80 , i, k->data.tiencoc);
		outtextxy(230 + 175 * 5 -80, i, k->data.std);
		char* c = const_cast<char*>(k->data.note.c_str());
		outtextxy(230 + 175 * 6-80, i, c);
		char* cr = const_cast<char*>(k->data.adress.c_str());
		outtextxy(230 + 175 * 7-80, i, cr);
		
		i += 32;
		if (i > 727) {
			while (exit == 0)
			{
				if (ismouseclick(WM_LBUTTONDOWN))
				{
					getmouseclick(WM_LBUTTONDOWN, x, y);
					if ((x >= 50 && x <= 650) && (y >= 40 && y <= 40 + 25)) {
						exit = 1; nhap_datphong();
					}
					else if ((x >= 1320 && x <= 1460) && (y >= 750 && y <= 780)) {
						i = 230 + 40; settextjustify(1, 1);
						draw_statistical_box_2_1(); setcolor(red); settextjustify(0, 1);
						xuattheo_vitri(l, demlist + 1, demlist + 15);
						int next1 = demlist;
						int next2 = demlist + 15;
						stringstream strs5;
						strs5 << next1;
						string temp_str5 = strs5.str();
						char* char_type5 = (char*)temp_str5.c_str();
						stringstream strs5r;
						strs5r << next2;
						string temp_str5r = strs5r.str();
						char* char_type5r = (char*)temp_str5r.c_str();
						setcolor(red);
						outtextxy(30, 750, char_type5); outtextxy(70, 750, "-");
						outtextxy(90, 750, char_type5r);
						demlist += 15;
						if (demlist > 15) {
							setcolor(BLACK); setbkcolor(green);
							setfillstyle(1, green); bar(1180, 750, 1300, 780);
							setcolor(red); rectangle(1180, 750, 1300, 780); setcolor(WHITE);
							outtextxy(1200, 770, "<<PREV"); setcolor(red); setbkcolor(WHITE);


						}
					}
					else if ((x >= 1180 && x <= 1300) && (y >= 750 && y <= 780)) {
						setfillstyle(1, WHITE);
						bar(20, 730, 120, 780);
						setfillstyle(8, Plum1);
						bar(20, 730, 120, 780);
						demlist = demlist - 15;
						int next1 = demlist - 15;
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
						outtextxy(50, 750, char_type5); outtextxy(70, 750, "-");
						outtextxy(90, 750, char_type5r);

						demlist = demlist - 15;
						i = 255 + 30; settextjustify(1, 1);
						draw_statistical_box_2_1(); setcolor(red); settextjustify(0, 1);
						xuattheo_vitri(l, demlist - 14, demlist);

					}
					else if ((x >= 1000 && x <= 1100) && (y >= 0 && y <= 40)) {
						guid();

					}
					else if ((x >= 1150 && x <= 1350) && (y >= 0 && y <= 40)) {
						search_phong(); setbkcolor(WHITE);
					}
					else if ((x >= 1050 && x <= 1200) && (y >= 165 && y <= 220)) {
						setcolor(BLACK);
						setbkcolor(WHITE);
						char t[50], t1[50] = " ";
						setcolor(BLACK);
						Input(t, t1, 1120, 200, '0', '9', 1050, 165, 1200, 220);
						strcpy(t1, t);
						postion = atoi(t);
						XoaNodeCoKhoaBatKy(l, postion);
						save_file_pht_dpt(l);
						draw_inbox();
						draw_statistical_box_2_1(); setcolor(red);
						xuli_hopdong();
					}
					else if ((x >= 150 && x <= 500) && (y >= 0 && y <= 40)) {
						empty_room(); setbkcolor(WHITE);
					}
					else
						if ((x >= 50 && x <= 200) && (y >= 70 && y <= 140)) {
							cleardevice(); HomePageUIShow();
							exit = 1;
						}
				}
			}
		}
	}
}
void main_menu_hopdong() {
	int exit = 0, x, y;
	cleardevice();
	setfillstyle(6, blue_d);
	setcolor(WHITE); setbkcolor(blue_d);
	bar(0, 0, 1520, 40); settextjustify(1, 1);
	settextstyle(9, 0, 0); setcolor(red);
	outtextxy(1520 / 2, 30, "DAT PHONG"); settextstyle(9, 0, 3);
	setfillstyle(1, yellow); setcolor(red); setbkcolor(yellow);
	bar(0, 0, 130, 40); outtextxy(60, 30, "<BACK"); setcolor(RED);
	rectangle(0, 0, 130, 40);
	//
	setfillstyle(1, red); setcolor(WHITE); setbkcolor(red);
	bar(150, 0, 500, 40); outtextxy(330, 30, "XEM PHONG TRONG"); setcolor(WHITE);
	rectangle(150, 0, 500, 40); 
	setfillstyle(1, green); setcolor(WHITE); setbkcolor(green);
	bar(1150, 0, 1350, 40); outtextxy(1250, 30, "SEARCH"); setcolor(yellow);
	rectangle(1150, 0, 1350, 40);
	setfillstyle(1, LIGHTMAGENTA);
	bar(1000, 0, 1100, 40); setcolor(RED);
	rectangle(1000, 0, 1100, 40); setcolor(YELLOW);
	settextstyle(9, 0, 5); setbkcolor(LIGHTMAGENTA);
	outtextxy(1050, 32, "?");
	settextstyle(9, 0, 1);
	draw_statistical_box_2_1(); draw_inbox();
	setfillstyle(1, yellow);
	setcolor(BLACK);
	rectangle(650, 40 + 25 * 5, 800, 220);
	bar(650, 40 + 25 * 5, 800, 220);
	setcolor(BLUE); settextjustify(0, 1); setbkcolor(yellow); settextstyle(9, 0, 3);
	outtextxy(660, 200, "THEM");
	// xoa
	setfillstyle(1, green);
	setcolor(red);
	rectangle(800, 40 + 25 * 5, 950, 220);
	bar(800, 40 + 25 * 5, 950, 220);
	 settextjustify(0, 1); setbkcolor(green); settextstyle(9, 0, 4);
	 outtextxy(820, 200, "XOA"); settextstyle(9, 0, 1); setbkcolor(WHITE);
	 // edit
	 setfillstyle(1, red);
	 setcolor(BLACK);
	 rectangle(950, 40 + 25 * 5, 1050, 220); setcolor(WHITE);
	 bar(950, 40 + 25 * 5, 1050, 220); 
	 settextjustify(0, 1); setbkcolor(red); settextstyle(9, 0, 3);
	 outtextxy(960, 200, "EDIT"); settextstyle(9, 0, 1); setbkcolor(WHITE);
	setcolor(green);
	outtextxy(1090, 60, "Da Vao:");
	setcolor(BLUE);
	outtextxy(1090, 60 + 25, "Chua Vao:"); setcolor(red);
	outtextxy(1090, 60+25*2, "Huy:");
	setfillstyle(1, BLUE);
	setcolor(yellow); settextstyle(9, 0, 1);
	bar(1320, 750, 1460, 780);		setbkcolor(BLUE); setcolor(YELLOW);
	rectangle(1320, 750, 1460, 780); setcolor(WHITE);
	outtextxy(1350, 770, "NEXT>>"); 
	xuli_hopdong(); nhap_datphong();
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