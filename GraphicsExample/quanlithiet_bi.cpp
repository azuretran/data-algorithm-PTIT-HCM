#include"quanlithiet_bi.h"
void xuattheo_vitri(list_tbi l, int start, int endt) {

	int i = 230 + 40, dem = 0, dem2 = 0, j = 1;
	setbkcolor(WHITE); setcolor(BLUE);
	for (nodetbi* k = l.phead; k != NULL; k = k->pnext)
	{
		dem++;
		dem2++;
		if (dem == start) {
			dem--;
			stringstream strsab;
			strsab << k->data.vt;
			string temp_strab = strsab.str();
			char* char_type12b = (char*)temp_strab.c_str();
			outtextxy(30, i, char_type12b);
			stringstream strsa;
			strsa << k->data.p;
			string temp_stra = strsa.str();
			char* char_type12 = (char*)temp_stra.c_str();
			outtextxy(30 + 100, i, char_type12);
			char* cccb = const_cast<char*>(k->data.nametb.c_str());
			outtextxy(210, i, cccb);
			outtextxy(210 + 220, i, k->data.costtb);
			outtextxy(210 + 220 * 2, i, k->data.sl); outtextxy(210 + 220 * 4, i, k->data.day_check);
			char* cq = const_cast<char*>(k->data.state.c_str()); outtextxy(210 + 220 * 3, i, cq);
			char* ct = const_cast<char*>(k->data.note.c_str());
			outtextxy(210 + 220 * 5, i, ct);
			i += 32;
			j++;
		}
		if (dem2 == endt) break;
	}
}
void input_thietbi() {
	void xuli_thietbi(); void draw_inbox_m();
	void draw_statistical_thietbi();
	void search_thietbi();
	int exit = 0, x, y, postion = 0, exit1 = 0;
	list_tbi l; create_list_tbi_tbi(l);
	ifstream  f;

	tbi sv;
	f.open("quanli_thietbi.txt", ios::in);
	if (f.fail())
		cout << "Error file! " << endl;
	ReadFile_to_list_dbi(f, l);
	int n = len2(l);
	danhso(l); rectangle(800, 165, 950, 220);
	setcolor(red); setbkcolor(WHITE);
	rectangle(1050, 165, 1200, 220); 
	outtextxy(1060, 200, "VT:");
	int flag = 0;
	while (exit == 0)
	{
		setbkcolor(BLUE);
		if (ismouseclick(WM_LBUTTONDOWN)) {
			getmouseclick(WM_LBUTTONDOWN, x, y);
		
			if ((x >= 0 && x <= 130) && (y >= 0 && y <= 40)) {
				exit = 1; HomePageUIShow();
			}
			else
			if ((x >= 50 && x <= 650) && (y >= 40 && y <= 40 + 25)) {
				setcolor(YELLOW);
				rectangle(50, 40, 650, 40 + 25);
				char s[50], s1[50] = " ";
				Input(s, s1, 260, 60, ' ', 'z', 50, 40, 650, 65); strcpy(s1, s);
				ofstream f; f.open("input_menu8.txt", ios::out);
				f << s << ","; f.close();
			}
			else
				if ((x >= 50 && x <= 650) && (y >= 40 + 25 && y <= 40 + 25 * 2)) {
					setcolor(YELLOW);
					rectangle(50, 40 + 25, 650, 40 + 25 * 2);
					char s1[50], s2[50] = " ";
					Input(s1, s2, 260, 60 + 25, ' ', 'z', 50, 40 + 25, 650, 65 + 25); strcpy(s2, s1);
					ofstream f; f.open("input_menu8.txt", ios::out | ios::app);
					f << s1 << ","; f.close();
				}
				else
					if ((x >= 50 && x <= 650) && (y >= 40 + 25 * 2 && y <= 40 + 25 * 3)) {
						setcolor(YELLOW);
						rectangle(50, 40 + 25 * 2, 650, 40 + 25 * 3);
						char s2[50], s3[50] = " ";
						Input(s2, s3, 260, 60 + 25 * 2, ' ', 'z', 50, 40 + 25 * 2, 650, 65 + 25 * 2); strcpy(s3, s2);
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
							f << s3 << " " << ","; f.close();
						}
						else
							if ((x >= 50 && x <= 650) && (y >= 40 + 25 * 4 && y <= 40 + 25 * 5)) {
								setcolor(YELLOW);
								rectangle(50, 40 + 25 * 4, 650, 40 + 25 * 5);
								char s4[50], s5[50] = " ";
								Input(s4, s5, 260, 60 + 25 * 4, '0', '9', 50, 40 + 25 * 4, 650, 65 + 25 * 4); strcpy(s5, s4);
								ofstream f; f.open("input_menu8.txt", ios::out | ios::app);
								f << s4 << " " << ","; f.close();
							}
							else
								if ((x >= 50 && x <= 650) && (y >= 40 + 25 * 5 && y <= 40 + 25 * 6)) {
									setcolor(YELLOW);
									rectangle(50, 40 + 25 * 5, 650, 40 + 25 * 6);
									char s5[50], s6[50] = " ";
									Input(s5, s6, 260, 60 + 25 * 5, '/', '9', 50, 40 + 25 * 5, 650, 65 + 25 * 5); strcpy(s6, s5);
									ofstream f; f.open("input_menu8.txt", ios::out | ios::app);
									f << s5 << " " << ","; f.close();
								}
								else
									if ((x >= 50 && x <= 650) && (y >= 40 + 25 * 6 && y <= 40 + 25 * 7)) {
										// phong
										setfillstyle(1, WHITE);
										bar(250, 40 + 25 * 6, 650, 40 + 25 * 7);
										setcolor(YELLOW);
										rectangle(50, 40 + 25 * 6, 650, 40 + 25 * 7);
										char s6[50], s7[50] = " ";
										Input(s6, s7, 260, 60 + 25 * 6, '0', '9', 50, 40 + 25 * 6, 650, 65 + 25 * 6); strcpy(s7, s6);
										int ckeck = atoi(s6);
										if (ckeck > 100) flag = 1;
										if (flag == 0) {
											ofstream f; f.open("input_menu8.txt", ios::out | ios::app);
											f << s6; f.close();
										}
									}
									else
										if ((x > 650 && x <= 1050) && (y >= 40 && y <= 40 + 25)) {
											if (flag == 1) {
												setfillstyle(1, WHITE);
												bar(250, 40 + 25 * 6, 650, 40 + 25 * 7);
												setcolor(BLUE);
												rectangle(50, 40 + 25 * 6, 650, 40 + 25 * 7); 
												setbkcolor(WHITE); setcolor(red);
												outtextxy(260, 60 + 25 * 6, "!phong<100"); flag = 0;
											}
											else {
												setcolor(LIGHTMAGENTA);
												rectangle(650, 40, 1050, 40 + 25);
												char s7[50], s8[50] = " "; setcolor(WHITE); setbkcolor(red);
												Input(s7, s8, 820, 60, '0', '9', 650, 40, 1050, 65); strcpy(s8, s7);
												ofstream f; f.open("try.txt", ios::out);
												f << s7 << ","; f.close();
											}
										}
										else if ((x >= 650 && x <= 800) && (y >= 165 && y <= 220)) {
											danhso(l);
											ifstream f; f.open("try.txt", ios::in);
											f >> postion; f.close();
											ifstream fk; fk.open("input_menu8.txt", ios::in);
											Read_1_dbi(fk, sv);
											fk.close();
											nodetbi* p = create_node_tbi(sv);
											ThemNode_p_VaoViTriBatKi(l, p, postion, n);
											ofstream fi; fi.open("quanli_thietbi.txt", ios::out);
											save_file_pht_dtbi(l);
											draw_inbox_m(); draw_statistical_thietbi(); settextjustify(0, 1); setcolor(BLUE);
											xuli_thietbi();
											fi.close();
										}
										else if ((x >= 950 && x <= 1050) && (y >= 165 && y <= 220)) {
											ifstream f; f.open("try.txt", ios::in);
											f >> postion; f.close();
											ifstream fk; fk.open("input_menu8.txt", ios::in);
											Read_1_dbi(fk, sv); fk.close();	
											ofstream fi; fi.open("quanli_thietbi.txt", ios::out);
											edit_by_postion_tbi(l, postion); save_file_pht_dtbi(l); 
											draw_inbox_m(); draw_statistical_thietbi(); settextjustify(0, 1); setcolor(BLUE);
											xuli_thietbi();
											fi.close();
										}
										else if ((x >= 1050 && x <= 1200) && (y >= 165 && y <= 220)) {
											setcolor(BLACK);
											setbkcolor(WHITE);
											char t[50], t1[50] = " ";
											setcolor(BLACK);
											Input(t, t1, 1120, 200, '0', '9', 1050, 165, 1200, 220);
											strcpy(t1, t);
											postion = atoi(t);
											XoaNodeCoKhoaBatKy(l, postion); ofstream fi; fi.open("quanli_thietbi.txt", ios::out);
											save_file_pht_dtbi(l); 
											draw_inbox_m(); draw_statistical_thietbi(); settextjustify(0, 1); setcolor(BLUE);
											xuli_thietbi();
											fi.close();
										}
										else if ((x>=950&&x<=1050)&&(y>=110&&y<=165)) {
											setfillstyle(1, yellow);
											setcolor(red);
											rectangle(950, 110, 1050, 165); setcolor(red);
											bar(950, 110, 1050, 165);
											settextjustify(0, 1); setbkcolor(yellow); settextstyle(9, 0, 4);
											outtextxy(960, 140, "Sort"); settextjustify(1, 1);
											sort_by_ros(l);
											ofstream fi; fi.open("quanli_thietbi.txt", ios::out);
											save_file_pht_dtbi(l);
											draw_inbox_m(); draw_statistical_thietbi(); settextjustify(0, 1); setcolor(BLUE);
											xuli_thietbi();
											fi.close();
										}
										else
											if ((x >= 0 && x <= 130) && (y >= 0 && y <= 40)) {
												exit = 1; HomePageUIShow();
											}
											else if ((x>=150&&x<=340)&&(y>=0&&y<=40)) {
												search_thietbi();
											}

		}
	}
}

void xuli_thietbi() {
	void draw_statistical_thietbi();
	void draw_inbox_m();
	int exit = 0, x, y, postion = 0, exit1 = 0,demlist=0;
	list_tbi l; create_list_tbi_tbi(l);
	ifstream  f;

	tbi sv;
	f.open("quanli_thietbi.txt", ios::in);
	if (f.fail())
		cout << "Error file! " << endl;
	ReadFile_to_list_dbi(f, l);
	int len_list = len2(l);
	f.close(); int i = 230 + 40; danhso(l); setbkcolor(WHITE); settextjustify(0, 1);
	int j = 1;
	for (nodetbi* k = l.phead; k != NULL; k = k->pnext) {
		demlist++;
		stringstream strsab;
		strsab << k->data.vt;
		string temp_strab = strsab.str();
		char* char_type12b = (char*)temp_strab.c_str();
		outtextxy(30, i, char_type12b);
		stringstream strsa;
		strsa << k->data.p;
		string temp_stra = strsa.str();
		char* char_type12 = (char*)temp_stra.c_str();
		outtextxy(30+100, i, char_type12);
		char* cccb = const_cast<char*>(k->data.nametb.c_str());
		outtextxy(210, i, cccb);
		outtextxy(210+220, i, k->data.costtb);
		outtextxy(210 + 220*2, i, k->data.sl); outtextxy(210 + 220 * 4, i, k->data.day_check);
		char* cq = const_cast<char*>(k->data.state.c_str()); outtextxy(210 + 220 * 3, i,cq);
		char* ct = const_cast<char*>(k->data.note.c_str());
		outtextxy(210 + 220 * 5, i, ct);
		i += 32;
		
		
		if (i > 727) {
			while (exit == 0)
			{
				if (ismouseclick(WM_LBUTTONDOWN))
				{
					getmouseclick(WM_LBUTTONDOWN, x, y);
					if ((x >= 0 && x <= 130) && (y >= 0 && y <= 40)) {
						exit = 1; HomePageUIShow();
					}
					else if ((x >= 50 && x <= 650) && (y >= 40 && y <= 40 + 25)) {
						exit = 1; input_thietbi();
					}
					else if ((x>=800&&x<=950)&&(y>=165&&y<=220)) {
						input_thietbi();
					}
					else if ((x >= 1320 && x <= 1460) && (y >= 750 && y <= 780)) {
						i = 230 + 40; settextjustify(1, 1);
						draw_statistical_thietbi(); setcolor(red); settextjustify(0, 1);
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
						bar(40, 730, 120, 780);
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
						i = 255 + 30; settextjustify(1, 1);
						draw_statistical_thietbi(); setcolor(red); settextjustify(0, 1);
						xuattheo_vitri(l, demlist - 14, demlist);
					}

					else if ((x >= 1050 && x <= 1200) && (y >= 165 && y <= 220)) {
						setcolor(BLACK);
						setfillstyle(1, WHITE);
						bar(1110, 165, 220, 1190);
						setbkcolor(WHITE);
						char t[50], t1[50] = " ";
						setcolor(BLACK);
						Input(t, t1, 1120, 200, '0', '9', 1050, 165, 1200, 220);
						strcpy(t1, t);
						postion = atoi(t);
						XoaNodeCoKhoaBatKy(l, postion); ofstream fi; fi.open("quanli_thietbi.txt", ios::out);
						save_file_pht_dtbi(l);
						draw_inbox_m(); draw_statistical_thietbi(); settextjustify(0, 1); setcolor(BLUE);
						xuli_thietbi();
						fi.close();
					}
					else
						if ((x >= 50 && x <= 200) && (y >= 70 && y <= 140)) {
							cleardevice(); HomePageUIShow();
							exit = 1;
						}
						else if ((x >= 950 && x <= 1050) && (y >= 110 && y <= 165)) {
							setfillstyle(1, yellow);
							setcolor(red);
							rectangle(950, 110, 1050, 165); setcolor(red);
							bar(950, 110, 1050, 165);
							settextjustify(0, 1); setbkcolor(yellow); settextstyle(9, 0, 4);
							outtextxy(960, 140, "Sort"); settextjustify(1, 1);
							sort_by_ros(l);
							ofstream fi; fi.open("quanli_thietbi.txt", ios::out);
							save_file_pht_dtbi(l);
							draw_inbox_m(); draw_statistical_thietbi(); settextjustify(0, 1); setcolor(BLUE);
							xuli_thietbi();
							fi.close();
						}
				}
			}
		}

	}
}
void draw_inbox_m() {
	setfillstyle(1, WHITE);
	bar(50, 40, 650, 220);
	setcolor(BLACK);
	rectangle(50, 40, 650, 215);
	int i = 40 + 25;
	for (; i < 220; i += 25)
		line(50, i, 650, i);
	line(250, 40, 250, 215); setbkcolor(WHITE);
	setcolor(BLUE); settextjustify(0, 1);
	settextstyle(9, 0, 1); outtextxy(700, 60, "Vi Tri:");
	outtextxy(55, 60, "Ten Thiet Bi:");
	outtextxy(55, 60 + 25, "Ghi Chu:");	outtextxy(55, 110, "Tinh Trang:");
	outtextxy(55, 60 + 25 * 3, "Gia Thiet Bi:");
	outtextxy(55, 60 + 25 * 4, "So Luong:");
	outtextxy(55, 60 + 25 * 5, "Ngay Kiem Tra:"); outtextxy(55, 60 + 25 * 6, "Phong:"); 
	setcolor(BLACK);
	
	rectangle(650, 40, 1050, 40 + 25);
	line(650, 40, 650, 220); line(800, 40, 800, 40 + 25 );
}
void draw_statistical_thietbi() {
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
	for (; i <= 200; i += 100) {
		line(i, 220, i, 727);
	}
	i = 200;
	for (; i <= 1520; i += 220) {
		line(i, 220, i, 727);
	}
	//noi dung 
	setcolor(Crimson); setbkcolor(blue);
	outtextxy(50, 240, "STT");
	outtextxy(50 + 100, 240, "Phong");
	settextjustify(0, 1);
	outtextxy(210, 240, "Ten Thiet Bi"); outtextxy(210+220, 240, "Gia Thiet Bi");
	outtextxy(210+440, 240, "So Luong");
	outtextxy(210+660, 240, "Tinh Trang");	outtextxy(210 + 660+220, 240, "Ngay Kiem Tra");
	outtextxy(210 + 660+440+20, 240, "Ghi Chu");
}
void search_thietbi() {
	list_tbi l; create_list_tbi_tbi(l);
	ifstream  f;

	tbi sv;
	f.open("quanli_thietbi.txt", ios::in);
	if (f.fail())
		cout << "Error file! " << endl;
	ReadFile_to_list_dbi(f, l);
	int exit = 0, x, y; setbkcolor(WHITE);
	cleardevice();
	setfillstyle(2, blue_d);
	bar(0, 0, 1520, 850);
	setfillstyle(1, blue_B);
	setcolor(WHITE); setbkcolor(blue_B);
	bar(0, 0, 1520, 40); settextjustify(1, 1);
	settextstyle(9, 0, 0);
	outtextxy(1520 / 2, 30, "Tim Kiem Theo phong "); settextstyle(9, 0, 3);
	setfillstyle(1, yellow); setcolor(red); setbkcolor(yellow);
	bar(0, 0, 130, 40); outtextxy(60, 30, "<BACK"); setcolor(RED); settextstyle(9, 0, 5); settextjustify(0, 1);
	rectangle(0, 0, 130, 40);
	setfillstyle(1, red);
	bar(100, 100, 450, 150);
	setcolor(yellow); setbkcolor(red);
	rectangle(100, 100, 450, 150);
	setcolor(WHITE);
	outtextxy(110, 140, "Nhap Phong:"); settextstyle(9, 0, 3);
	setcolor(GREEN);
	rectangle(450, 100,800, 150);
	settextjustify(1, 1);
	draw_statistical_thietbi(); settextstyle(9, 0, 5); danhso(l);
	while (exit == 0)
	{
		if (ismouseclick(WM_LBUTTONDOWN)) {
			getmouseclick(WM_LBUTTONDOWN, x, y);
			if ((x >= 0 && x <= 130) && (y >= 0 && y <= 40)) {
				exit = 1; setbkcolor(WHITE);
				main_menu_thietbi();

			}
			else if ((x>=450&&x<=800)&&(y>=100&&y<=150)) {
				settextstyle(9, 0, 5); 
				char s[50], s1[50] = " ";
				setfillstyle(1, WHITE);
				bar(450, 100, 800, 150);
				setcolor(yellow);
				rectangle(450, 100, 800, 150);
				Input(s, s1, 600, 140, '0', '9', 450, 100, 800, 150); strcpy(s1, s);
				int postion = atoi(s);
				settextstyle(9, 0, 1); setbkcolor(WHITE); setcolor(red); settextjustify(1, 1);
				draw_statistical_thietbi(); setbkcolor(WHITE);
				int i = 230 + 40;
				for (nodetbi* k = l.phead; k != NULL; k = k->pnext) {
					if (k->data.p == postion) {
						stringstream strsab;
						strsab << k->data.vt;
						string temp_strab = strsab.str();
						char* char_type12b = (char*)temp_strab.c_str();
						outtextxy(30, i, char_type12b);
						stringstream strsa;
						strsa << k->data.p;
						string temp_stra = strsa.str();
						char* char_type12 = (char*)temp_stra.c_str();
						outtextxy(30 + 100, i, char_type12);
						char* cccb = const_cast<char*>(k->data.nametb.c_str());
						outtextxy(210, i, cccb);
						outtextxy(210 + 220, i, k->data.costtb);
						outtextxy(210 + 220 * 2, i, k->data.sl); outtextxy(210 + 220 * 4, i, k->data.day_check);
						char* cq = const_cast<char*>(k->data.state.c_str()); outtextxy(210 + 220 * 3, i, cq);
						char* ct = const_cast<char*>(k->data.note.c_str());
						outtextxy(210 + 220 * 5, i, ct);
						i += 32;
					}
				}

			}
		}
			}
}
void main_menu_thietbi() {
	int exit = 0, x, y;
	cleardevice();
	setfillstyle(1, blue_B);
	setcolor(WHITE); setbkcolor(blue_B);
	bar(0, 0, 1520, 40); settextjustify(1, 1);
	settextstyle(9, 0, 0);
	outtextxy(1520 / 2, 30, "QUAN LI THIET BI"); settextstyle(9, 0, 3);
	setfillstyle(1, yellow); setcolor(red); setbkcolor(yellow);
	bar(0, 0, 130, 40); outtextxy(60, 30, "<BACK"); setcolor(RED);
	rectangle(0, 0, 130, 40);
	//
	setfillstyle(1, red); setcolor(WHITE); setbkcolor(red);
	bar(150, 0, 340, 40); outtextxy(250, 30, "SEARCH"); setcolor(WHITE);
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
	outtextxy(960, 200, "EDIT"); settextjustify(1, 1);
	// sap xep
	setfillstyle(1, green);
	setcolor(yellow);
	rectangle(950, 110, 1050, 165); setcolor(WHITE);
	bar(950,110, 1050, 165);
	settextjustify(0, 1); setbkcolor(green); settextstyle(9, 0, 4);
	outtextxy(960, 140, "Sort"); settextjustify(1, 1);
	rectangle(150, 0, 340, 40); 
	setfillstyle(1, BLUE);
	setcolor(yellow); settextstyle(9, 0, 1);
	bar(1320, 750, 1460, 780);		setbkcolor(BLUE); setcolor(YELLOW);
	rectangle(1320, 750, 1460, 780); setcolor(WHITE);
	outtextxy(1400, 770, "NEXT>>"); 

	draw_statistical_thietbi(); draw_inbox_m();
	xuli_thietbi(); input_thietbi();
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