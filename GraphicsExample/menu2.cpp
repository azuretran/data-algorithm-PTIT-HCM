#include"menu2.h"
void hoanvi(pht& a, pht& b)
{
	pht t = a; a = b; b = t;
}

void draw_statistical_box_2() {
	setfillstyle(1, WHITE);
	bar(0, bottom1 - 25 * 2, 1520, 727);
	setcolor(blue_A);
	rectangle(right1 + 100, top1 + 25 * 2, 1380 - 100, bottom1 - 25 * 2);

	for (int i = 70 + 25 * 2; i < 270 - 25 * 2; i += 25) {
		line(right1 + 100, i, 1280, i);
	}settextstyle(9, 0, 1);
	line(1280 - 100, 70 + 25, 1280 - 100, bottom1 - 25 * 2);
	setfillstyle(1, BLUE); setcolor(WHITE);
	bar(right1 + 100, 70 + 25, 1280, 70 + 25 * 2); setbkcolor(BLUE);
	settextstyle(9, 0, 3);
	outtextxy(right1 + 320, 50 + 25 * 2 + 15, "Thong Ke Phong "); settextstyle(9, 0, 1);
	setbkcolor(WHITE); setcolor(BLACK);
	outtextxy(right1 + 210, 50 + 25 * 3 + 15, "Tong So Phong"); setcolor(red);
	outtextxy(1250, 50 + 25 * 3 + 15, "100"); setcolor(BLACK);
	outtextxy(right1 + 210, 50 + 25 * 4 + 15, "Phong Trong");
	outtextxy(right1 + 210, 50 + 25 * 5 + 15, "Dang Thue");
	outtextxy(right1 + 210, 50 + 25 * 6 + 15, "Da Du Nguoi");
	setfillstyle(1, blue);
	bar(0, 220, 1520, 220 + 29);
	setcolor(red);
	rectangle(0, bottom1 - 25 * 2, 1520, 727);
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
	setcolor(WHITE); setbkcolor(red);
	outtextxy(50, 240, "Phong");
	outtextxy(50 + 100, 240, "Gioi Tinh"); outtextxy(250, 240, "Dan Toc");
	outtextxy(400, 240, "Ho Ten");
	outtextxy(400 + 175, 240, "Ngay Sinh"); outtextxy(575 + 175, 240, "Ton Giao");
	outtextxy(575 + 175 * 2, 240, "So CMND");	outtextxy(575 + 175 * 3, 240, "Que Quan");
	outtextxy(575 + 175 * 4, 240, "Loai Phong"); outtextxy(560 + 175 * 5 - 10, 240, "Nghe Nghiep");

}
void menutimkiem() {
	setfillstyle(1, WHITE);
	bar(0, bottom1 - 25 * 2, 1520, 727);
	setfillstyle(1, blue);
	bar(0, 220, 1520, 220 + 29);
	setcolor(red);
	rectangle(0, bottom1 - 25 * 2, 1520, 727);
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
	setcolor(WHITE); setbkcolor(red);
	outtextxy(50, 240, "Phong");
	outtextxy(50 + 100, 240, "Gioi Tinh"); outtextxy(250, 240, "Dan Toc");
	outtextxy(400, 240, "Ho Ten");
	outtextxy(400 + 175, 240, "Ngay Sinh"); outtextxy(575 + 175, 240, "Ton Giao");
	outtextxy(575 + 175 * 2, 240, "So CMND");	outtextxy(575 + 175 * 3, 240, "Que Quan");
	outtextxy(575 + 175 * 4, 240, "Loai Phong"); outtextxy(560 + 175 * 5 - 10, 240, "Nghe Nghiep");

}

void input_user_menu2() {
	void menu2();
	cleardevice();
	listpht l; create_listpht_pht(l); pht sv;
	ifstream f; f.open("quanliphong_menu2.txt", ios::in);
	while (!f.eof())  //read into endfile.
	{
		pht sv;
		Read_1_pht(f, sv);
		nodepht* p = create_node_pht(sv);
		add_node_pht_tail(l, p);
	}

	int n = len2(l);
	setfillstyle(9, blue_d);
	bar(0, 0, 1520, 850);
	setfillstyle(1, yellow); setcolor(red); setbkcolor(yellow);
	bar(0, 0, 130, 40); outtextxy(60, 30, "<BACK"); setcolor(RED);
	rectangle(0, 0, 130, 40);
	int exit = 0, x, y, exit1 = 0;
	setfillstyle(1, xinh);
	setcolor(WHITE); setbkcolor(xinh);
	bar(130, 0, 1520, 40); settextjustify(1, 1);
	settextstyle(9, 0, 4);
	outtextxy(1520 / 2, 30, "Phan Nhap Thong Tin Phong");
	int i = 90;
	setcolor(red);
	rectangle(160, 50, 1200, 490);
	for (; i <= 520; i += 40) {
		line(160, i, 1200, i);
	}setcolor(GREEN);
	line(350, 90, 350, 690 - 40 * 5);
	//tên phòng
	setcolor(WHITE);
	setfillstyle(1, red); settextstyle(9, 0, 3); setbkcolor(red);
	bar(160, 50, 350, 90); 	setfillstyle(1, blue_B); outtextxy(250, 75, "Que Quan");
	//ho ten
	setbkcolor(blue_B);
	bar(160, 90, 350, 90 + 40); outtextxy(260, 75 + 40, "Nghe Nghiep");
	//ngaysinh
	setfillstyle(1, WhatsApp); setbkcolor(WhatsApp);
	bar(160, 90 + 40, 350, 90 + 40 * 2);  outtextxy(250, 75 + 40 * 2, "Ho Ten");
	setfillstyle(1, yellow); setbkcolor(yellow); setcolor(red);
	// gioi tinh
	bar(160, 90 + 40 * 2, 350, 90 + 40 * 3); outtextxy(250, 75 + 40 * 3, "Phong"); setbkcolor(LIGHTMAGENTA); setcolor(WHITE);
	// que quan
	setfillstyle(1, LIGHTMAGENTA);
	bar(160, 90 + 40 * 3, 350, 90 + 40 * 4); setfillstyle(1, BROWN); outtextxy(250, 75 + 40 * 4, "Gioi Tinh"); setbkcolor(BROWN);
	//dan toc
	bar(160, 90 + 40 * 4, 350, 90 + 40 * 5); outtextxy(260, 75 + 40 * 5, "Dan Toc");
	setfillstyle(1, LIGHTGRAY); setbkcolor(LIGHTGRAY);
	//ton giao
	bar(160, 90 + 40 * 5, 350, 90 + 40 * 6); outtextxy(250, 75 + 40 * 6, "Ton Giao");

	setcolor(red);
	setfillstyle(1, Snapchat); setbkcolor(Snapchat);
	bar(160, 90 + 40 * 6, 350, 90 + 40 * 7);
	outtextxy(250, 75 + 40 * 7, "Sinh Nhat");
	setfillstyle(1, green); setbkcolor(green);
	bar(160, 90 + 40 * 7, 350, 90 + 40 * 8);
	outtextxy(250 + 10, 75 + 40 * 8, "Loai Phong");
	setfillstyle(1, Snapchat); setbkcolor(Snapchat);
	bar(160, 90 + 40 * 8, 350, 90 + 40 * 9);
	outtextxy(260, 75 + 40 * 9, "So CMND"); setcolor(WHITE);
	setfillstyle(1, LIGHTMAGENTA); setbkcolor(LIGHTMAGENTA);
	bar(160, 90 + 40 * 9, 350, 90 + 40 * 10);
	outtextxy(260, 75 + 40 * 10, "Vi Tri"); setcolor(WHITE);
	bar(350, 720, 750, 760); setcolor(RED); rectangle(350, 720, 750, 760);
	outtextxy(550, 750, "Them Vao Danh Sach");
	setfillstyle(1, YELLOW); setbkcolor(YELLOW); settextstyle(9, 0, 3); settextjustify(1, 1);
	bar(760, 720, 1200, 760); setcolor(RED); rectangle(760, 720, 1200, 760);
	outtextxy(980, 750, "Sua Thong Tin"); setbkcolor(WHITE); int postion;
	int flag=0,dem1=0,flag11=0;
	while (exit1 == 0)
	{
		if (ismouseclick(WM_LBUTTONDOWN)) {
			getmouseclick(WM_LBUTTONDOWN, x, y);
			if ((x >= 160 && x <= 1200) && (y >= 50 && y <= 90)) {
				setfillstyle(9, blue_d);
				bar(350, 50,1200, 490);
				bar(0, 500, 1520, 715);
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
				rectangle(350, 90 + 40 * 9, 1200, 130 + 40 * 9);
				//
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
					char s1[50], s2[50] = " ";
					setcolor(YELLOW);
					rectangle(160, 90, 1200, 130); setcolor(red);
					Input(s1, s2, 700, 120, ' ', 'z', 160, 90, 1200, 130);
					strcpy(s2, s1);
					ofstream f; f.open("input_menu8.txt", ios::out | ios::app);
					f << s1 << ",";
					f.close();
				}
				else
					if ((x >= 160 && x <= 1200) && (y >= 90 + 40 && y <= 130 + 40)) {
						char s2[50], s3[50] = " ";
						setcolor(YELLOW);
						rectangle(160, 90 + 40, 1200, 130 + 40); setcolor(red);
						Input(s2, s3, 700, 120 + 40, ' ', 'z', 160, 90 + 40, 1200, 130 + 40);
						strcpy(s3, s2);
						ofstream f; f.open("input_menu8.txt", ios::out | ios::app);
						f << s2 << ",";
						f.close();
					}
					else
						if ((x >= 160 && x <= 1200) && (y >= 90 + 40 * 2 && y <= 130 + 40 * 2)) {
							
							setfillstyle(9, blue_d);
							bar(350, 90 + 40 * 2, 1200, 130 + 40 * 2);
							
							char s3[50], s4[50] = " ";
							setcolor(YELLOW);
							rectangle(160, 90 + 40 * 2, 1200, 130 + 40 * 2); setcolor(red);
							Input(s3, s4, 700, 120 + 40 * 2, '0', '9', 160, 90 + 40 * 2, 1200, 130 + 40 * 2);
							strcpy(s4, s3);
							int pos = atoi(s3);
							if (pos > 100 || pos < 0) flag = 1;
							dem1 = 0;
							for (nodepht* k = l.phead; k != NULL; k = k->pnext) {
								int mm = atoi(k->data.ton_giao.c_str());
								
								if (mm == pos) dem1++;
								
							}
							
							if (dem1 >=4) flag11 = 1;
							if ((flag11 == 0) && (flag == 0)) {
								ofstream f; f.open("input_menu8.txt", ios::out | ios::app);
								f << s3 << ",";
								f.close();
							}
						}
						else
							if ((x >= 160 && x <= 1200) && (y >= 90 + 40 * 3 && y <= 130 + 40 * 3)) {
								if (flag == 1) {
									setfillstyle(9, blue_d);
									bar(350, 90 + 40 * 2, 1200, 130 + 40 * 2); setcolor(YELLOW);
									rectangle(160, 90 + 40 * 2, 1200, 130 + 40 * 2); setcolor(red);
									setfillstyle(9, blue_d);
									bar(350, 90 + 40 * 2, 1200, 130 + 40 * 2);
									outtextxy(700, 120 + 40 * 2, "khong hop le! 0<phong<100"); flag = 0;  
								}
								 if (flag11 == 1) {
									setfillstyle(9, blue_d);
									bar(350, 90 + 40 * 2, 1200, 130 + 40 * 2); setcolor(YELLOW);
									rectangle(160, 90 + 40 * 2, 1200, 130 + 40 * 2); setcolor(red);
									setfillstyle(9, blue_d);
									bar(350, 90 + 40 * 2, 1200, 130 + 40 * 2);
									outtextxy(700, 120 + 40 * 2, "Phong Da Full!"); flag11 = 0;
								}
								
								else {
									
									char s4[50], s5[50] = " ";
									setcolor(YELLOW);
									rectangle(160, 90 + 40 * 3, 1200, 130 + 40 * 3); setcolor(red);
									Input(s4, s5, 700, 120 + 40 * 3, ' ', 'z', 160, 90 + 40 * 3, 1200, 130 + 40 * 3);
									strcpy(s5, s4);


									ofstream f; f.open("input_menu8.txt", ios::out | ios::app);
									f << s4 << ",";
									f.close();
								}
							}
							else
								if ((x >= 160 && x <= 1200) && (y >= 90 + 40 * 4 && y <= 130 + 40 * 4)) {
									char s5[50], s6[50] = " ";
									setcolor(YELLOW);
									rectangle(160, 90 + 40 * 4, 1200, 130 + 40 * 4); setcolor(red);
									Input(s5, s6, 700, 120 + 40 * 4, ' ', 'z', 160, 90 + 40 * 4, 1200, 130 + 40 * 4);
									strcpy(s6, s5);
									ofstream f; f.open("input_menu8.txt", ios::out | ios::app);
									f << s5 << ",";
									f.close();
								}
								else
									if ((x >= 160 && x <= 1200) && (y >= 90 + 40 * 5 && y <= 130 + 40 * 5)) {
										char s6[50], s7[50] = " ";
										setcolor(YELLOW);
										rectangle(160, 90 + 40 * 5, 1200, 130 + 40 * 5); setcolor(red);
										Input(s6, s7, 700, 120 + 40 * 5, ' ', 'z', 160, 90 + 40 * 5, 1200, 130 + 40 * 5);
										strcpy(s7, s6);
										ofstream f; f.open("input_menu8.txt", ios::out | ios::app);
										f << s6 << ",";
										f.close();
									}
									else
										if ((x >= 160 && x <= 1200) && (y >= 90 + 40 * 6 && y <= 130 + 40 * 6)) {
											char s7[50], s8[50] = " ";
											setcolor(YELLOW);
											rectangle(160, 90 + 40 * 6, 1200, 130 + 40 * 6); setcolor(red);
											Input(s7, s8, 700, 120 + 40 * 6, '/', '9', 160, 90 + 40 * 6, 1200, 130 + 40 * 6);
											strcpy(s8, s7);
											ofstream f; f.open("input_menu8.txt", ios::out | ios::app);
											f << s7 << ",";
											f.close();
										}
										else
											if ((x >= 160 && x <= 1200) && (y >= 90 + 40 * 7 && y <= 130 + 40 * 7)) {
												char s8[50], s9[50] = " ";
												setcolor(YELLOW);
												rectangle(160, 90 + 40 * 7, 1200, 130 + 40 * 7); setcolor(red);
												Input(s8, s9, 700, 120 + 40 * 7, '1', '3', 160, 90 + 40 * 7, 1200, 130 + 40 * 7);
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
														ofstream f; f.open("try.txt", ios::out);
														f << s77 << ',';
														f.close();
													}
													else if ((x >= 350 && x <= 750) && (y >= 720 && y <= 760)) {
														setcolor(green);
														rectangle(350, 720, 750, 760);
														ifstream fm; fm.open("try.txt", ios::in);
														fm >> postion; fm.close();
														ifstream f; f.open("input_menu8.txt", ios::in);
														Read_1_pht_2(f, sv);

														f.close();
														nodepht* p = create_node_pht(sv);
														ThemNode_p_VaoViTriBatKi(l, p, postion, n);
														ofstream fi; fi.open("quanliphong_menu2.txt", ios::out);
														for (nodepht* k = l.phead; k != NULL; k = k->pnext)
														{

															if (k == l.ptail) {

																fi << k->data.hometown << ',' << " "; fi << k->data.job << ',' << " ";
																fi << k->data.fullname << ',' << " "; fi << k->data.p << ',' << " ";
																fi << k->data.sex << ',' << " "; fi << k->data.dantoc << ',' << " ";
																fi << k->data.ton_giao << ',' << " "; fi << k->data.ngaysinh << ',' << " ";
																fi << k->data.vip << ',' << " "; fi << k->data.cmnd;
																break;
															}
															fi << k->data.hometown << ',' << " "; fi << k->data.job << ',' << " ";
															fi << k->data.fullname << ',' << " "; fi << k->data.p << ',' << " ";
															fi << k->data.sex << ',' << " "; fi << k->data.dantoc << ',' << " ";
															fi << k->data.ton_giao << ',' << " "; fi << k->data.ngaysinh << ',' << " ";
															fi << k->data.vip << ',' << " "; fi << k->data.cmnd << ',';
															fi << endl;

														}
														fi.close();
														setcolor(BLACK);
														rectangle(350, 720, 750, 760);
														outtextxy(350, 700, "Da Them Vao Danh Sach Lien Ket");
														exit = 1;
													}

													else if ((x>=760&&x<=1200)&&(y>=720&&y<=760)) {
														setfillstyle(1, green); setbkcolor(green); settextstyle(9, 0, 3); settextjustify(1, 1);
														bar(760, 720, 1200, 760); setcolor(yellow); rectangle(760, 720, 1200, 760); setcolor(WHITE);
														outtextxy(980, 750, "Sua Thong Tin"); setbkcolor(WHITE);
														setcolor(red);
														outtextxy(1000, 700, "Sua Thong Tin Thanh Cong");
														ifstream fm; fm.open("try.txt", ios::in);
														fm >> postion; fm.close();
														edit_by_postion_2(l, postion); ofstream fi; fi.open("quanliphong_menu2.txt", ios::out);
														for (nodepht* k = l.phead; k != NULL; k = k->pnext)
														{

															if (k == l.ptail) {

																fi << k->data.hometown << ',' << " "; fi << k->data.job << ',' << " ";
																fi << k->data.fullname << ',' << " "; fi << k->data.p << ',' << " ";
																fi << k->data.sex << ',' << " "; fi << k->data.dantoc << ',' << " ";
																fi << k->data.ton_giao << ',' << " "; fi << k->data.ngaysinh << ',' << " ";
																fi << k->data.vip << ',' << " "; fi << k->data.cmnd;
																break;
															}
															fi << k->data.hometown << ',' << " "; fi << k->data.job << ',' << " ";
															fi << k->data.fullname << ',' << " "; fi << k->data.p << ',' << " ";
															fi << k->data.sex << ',' << " "; fi << k->data.dantoc << ',' << " ";
															fi << k->data.ton_giao << ',' << " "; fi << k->data.ngaysinh << ',' << " ";
															fi << k->data.vip << ',' << " "; fi << k->data.cmnd << ',';
															fi << endl;

														}
														fi.close();

													}
													else if ((x>=580&&x<=770)&&(y>=70&&y<=140)) {
														setfillstyle(1, red);
														setcolor(BLACK);
														rectangle(580, 70, 770, 140); setcolor(WHITE);
														bar(580, 70, 770, 140);
														setbkcolor(red);
														settextstyle(9, 0, 4);
														outtextxy(680, 120, "BACKUP");
													}
			if ((x >= 0 && x <= 130) && (y >= 0 && y <= 40)) {
				exit = 1; setbkcolor(WHITE);
				menu2();
			}


		}
		
	}

}
void xuattheo_vitri(listpht l, int start, int endt) {
	int i = 230 + 40, dem = 0, dem2 = 0, j = 0; setbkcolor(WHITE);
	for (nodepht* k = l.phead; k != NULL; k = k->pnext)
	{
		dem++;
		dem2++;
		if (dem == start) {
			dem--;
			char* c = const_cast<char*>(k->data.p.c_str());
			outtextxy(230 + 175 * 3 - 20, i, c);
			char* cc = const_cast<char*>(k->data.sex.c_str());
			outtextxy(30 + 100, i, cc);
			char* ccc = const_cast<char*>(k->data.dantoc.c_str());
			outtextxy(230, i, ccc);
			char* cccb = const_cast<char*>(k->data.fullname.c_str());
			outtextxy(230 + 175 - 20, i, cccb);
			char* ccca = const_cast<char*>(k->data.vip.c_str());
			outtextxy(230 + 175 * 2, i, ccca);
			char* cccd = const_cast<char*>(k->data.ton_giao.c_str());
			outtextxy(30, i, cccd);
			char* cccde = const_cast<char*>(k->data.cmnd.c_str());
			outtextxy(230 + 175 * 4, i, cccde);
			char* cccdr = const_cast<char*>(k->data.hometown.c_str());
			outtextxy(230 + 175 * 5, i, cccdr);
			char* cccdq = const_cast<char*>(k->data.ngaysinh.c_str());
			outtextxy(230 + 175 * 6, i, cccdq);
			char* cccdv = const_cast<char*>(k->data.job.c_str());
			outtextxy(230 + 175 * 7 - 30, i, cccdv);
			i += 32;
		}
		if (dem2 == endt) break;

	}
}
void search_by_mp() {
	int exit = 0, x, y;
	void backup_daxoa();
	cleardevice();
	setbkcolor(WHITE);
	setfillstyle(1, yellow); setcolor(red); setbkcolor(yellow);
	bar(0, 0, 130, 40); outtextxy(60, 30, "<BACK"); setcolor(RED);
	rectangle(0, 0, 130, 40);
	setfillstyle(1, xinh);
	setcolor(WHITE); setbkcolor(xinh);
	bar(130, 0, 1520, 40); settextjustify(1, 1);
	settextstyle(9, 0, 4);
	outtextxy(1520 / 2, 30, "Phan Tim Thong Tin Da Xoa");
	setfillstyle(1, red);
	setcolor(BLACK);
	bar(80, 100, 350, 150); rectangle(80, 100, 350, 150); setcolor(WHITE); settextstyle(9, 0, 4); setbkcolor(red);
	outtextxy(200, 140, "Nhap Phong"); setcolor(red);
	rectangle(350, 100, 650, 150);
	setfillstyle(1, green);
	bar(700, 100, 900, 150); setcolor(yellow); setbkcolor(green);
	rectangle(700, 100, 900, 150); setcolor(WHITE);
	outtextxy(800, 140, "SEARCH");
	setfillstyle(1, yellow);
	bar(950, 100, 1150, 150); setcolor(BLUE); setbkcolor(yellow);
	rectangle(950, 100, 1150, 150); setcolor(BLUE);
	outtextxy(1050, 140, "RESET");
	int i = 270; setbkcolor(WHITE); setcolor(red);
	settextstyle(9, 0, 1);
	ifstream  f;
	f.open("back_up.txt", ios::in);
	listpht l; create_listpht_pht(l);
	 int demlist = 0, j = 0;
	int exit1 = 0;
	pht sv;
	while (!f.eof())  //read into endfile.
	{
		pht sv;
		Read_1_pht(f, sv);
		nodepht* p = create_node_pht(sv);
		add_node_pht_tail(l, p);
	}
	int len_list = len2(l);
	f.close();
	menutimkiem();
	while (exit == 0) {
		if (ismouseclick(WM_LBUTTONDOWN)) {
			getmouseclick(WM_LBUTTONDOWN, x, y);
			if ((x >= 0 && x <= 130) && (y >= 0 && y <= 40)) {
				exit = 1; setbkcolor(WHITE);
				backup_daxoa();
			}
			else if ((x >= 350 && x <= 650) && (y >= 100 && y <= 150)) {
				setbkcolor(WHITE);
				settextstyle(9, 0, 4);
				setfillstyle(1, WHITE);
				bar(350, 100, 650, 150);
				setcolor(yellow); rectangle(350, 100, 650, 150);
				char s[50], s1[50] = " "; setcolor(red);
				Input(s, s1, 450, 140, '0', '9', 350, 100, 650, 150);
				strcpy(s1, s);
				ofstream f; f.open("try.txt", ios::out);
				f << s; f.close(); settextstyle(9, 0, 1);
				menutimkiem();
			}
			else if ((x >= 700 && x <= 900) && (y >= 100 && y <= 150)) {
				setfillstyle(1, yellow);
				bar(700, 100, 900, 150); setcolor(red); setbkcolor(yellow);
				rectangle(700, 100, 900, 150); setcolor(BLUE);
				outtextxy(800, 140, "SEARCH");
				char position[15];
				ifstream f1; f1.open("try.txt", ios::in);
				f1 >> position; f1.close();
				listpht l; create_listpht_pht(l);
				ifstream  f; int x, y, exit = 0, demlist = 0, j = 0;
				int exit1 = 0;
				pht sv;
				f.open("back_up.txt", ios::in);
				if (f.fail())
					cout << "Error file! " << endl;
				while (!f.eof())  //read into endfile.
				{
					pht sv;
					Read_1_pht(f, sv);
					nodepht* p = create_node_pht(sv);
					add_node_pht_tail(l, p);
				}
				int len_list = len2(l);
				f.close(); int m = len2(l);
				int i = 230 + 40; danhso(l); setcolor(BLUE); settextstyle(9, 0, 1); setbkcolor(blue_d);
				cout << endl << position << endl;
				int flag = 0; setbkcolor(WHITE);
				for (nodepht* k = l.phead; k != NULL; k = k->pnext)
				{
					char* c = const_cast<char*>(k->data.ton_giao.c_str());

					if (strcmp(c, position) == 0) {
						flag = 1;
						char* c = const_cast<char*>(k->data.p.c_str());
						outtextxy(230 + 175 * 3 - 20, i, c);
						char* cc = const_cast<char*>(k->data.sex.c_str());
						outtextxy(30 + 100, i, cc);
						char* ccc = const_cast<char*>(k->data.dantoc.c_str());
						outtextxy(230, i, ccc);
						char* cccb = const_cast<char*>(k->data.fullname.c_str());
						outtextxy(230 + 175 - 20, i, cccb);
						char* ccca = const_cast<char*>(k->data.vip.c_str());
						outtextxy(230 + 175 * 2, i, ccca);
						char* cccd = const_cast<char*>(k->data.ton_giao.c_str());
						outtextxy(30, i, cccd);
						char* cccde = const_cast<char*>(k->data.cmnd.c_str());
						outtextxy(230 + 175 * 4, i, cccde);
						char* cccdr = const_cast<char*>(k->data.hometown.c_str());
						outtextxy(230 + 175 * 5, i, cccdr);
						char* cccdq = const_cast<char*>(k->data.ngaysinh.c_str());
						outtextxy(230 + 175 * 6, i, cccdq);
						char* cccdv = const_cast<char*>(k->data.job.c_str());
						outtextxy(230 + 175 * 7 - 30, i, cccdv);
						i += 32; j += 30;
					}

				}
				if (flag == 0)
				{
					setcolor(red);
					setfillstyle(1, WHITE);
					bar(350, 100, 650, 150); setbkcolor(WHITE);
					outtextxy(480, 140, "Phong Khong Ton Tai");
					setcolor(BLUE);
					menutimkiem(); setbkcolor(WHITE);
				}
			}
			else if ((x >= 950 && x <= 1150) && (y >= 100 && y <= 150)) {
				setfillstyle(1, red); settextstyle(9, 0, 4);
				bar(950, 100, 1150, 150); setcolor(BLUE); setbkcolor(red);
				rectangle(950, 100, 1150, 150); setcolor(WHITE);
				outtextxy(1050, 140, "RESET"); settextstyle(9, 0, 1);
				menutimkiem(); setbkcolor(yellow); setcolor(red); settextstyle(9, 0, 4);
			}
		}
	}
}
void backup_daxoa() {
	void menu2();

	setbkcolor(WHITE);
	cleardevice();
	
	ifstream fi;
	fi.open("back_up.txt", ios::in);
	listpht l; create_listpht_pht(l);
	ifstream  f; int x, y, exit = 0, demlist = 0, j = 0;
	int exit1 = 0;
	pht sv;
	while (!fi.eof())  //read into endfile.
	{
		pht sv;
		Read_1_pht(fi, sv);
		nodepht* p = create_node_pht(sv);
		add_node_pht_tail(l, p);
	}
	int len_list = len2(l);
	fi.close();

	settextstyle(9, 0, 4);
	setfillstyle(9, blue_d);
	bar(0, 0, 1520, 850); setfillstyle(1, red);
	setcolor(yellow); settextstyle(9, 0, 1);
	bar(1320, 750, 1460, 780);		setbkcolor(red); setcolor(YELLOW);
	rectangle(1320, 750, 1460, 780); setcolor(WHITE);
	outtextxy(1400, 770, "NEXT>>");
	setfillstyle(1, yellow); setcolor(red); setbkcolor(yellow);
	bar(0, 0, 130, 40); outtextxy(60, 30, "<BACK"); setcolor(RED);
	rectangle(0, 0, 130, 40);

	setfillstyle(1, xinh);
	setcolor(WHITE); setbkcolor(xinh);
	bar(130, 0, 1520, 40); settextjustify(1, 1);
	settextstyle(9, 0, 4);
	outtextxy(1520 / 2, 30, "Phan Thong Tin Da Xoa");
	setfillstyle(1, red);
	bar(1150, 0, 1380, 40); setcolor(yellow);
	rectangle(1150, 0, 1380, 40);
	setbkcolor(red);
	settextstyle(9, 0, 3); setcolor(WHITE);
	outtextxy(1250, 30, "SEARCH");
	settextstyle(9, 0, 1);
	menutimkiem();
	int i = 270; setbkcolor(WHITE); setcolor(red);
	for (nodepht* k = l.phead; k != NULL; k = k->pnext)
	{

		demlist++;
		char* c = const_cast<char*>(k->data.p.c_str());
		outtextxy(230 + 175 * 3 - 20, i, c);
		char* cc = const_cast<char*>(k->data.sex.c_str());
		outtextxy(30 + 100, i, cc);
		char* ccc = const_cast<char*>(k->data.dantoc.c_str());
		outtextxy(230, i, ccc);
		char* cccb = const_cast<char*>(k->data.fullname.c_str());
		outtextxy(230 + 175 - 20, i, cccb);
		char* ccca = const_cast<char*>(k->data.vip.c_str());
		outtextxy(230 + 175 * 2, i, ccca);
		char* cccd = const_cast<char*>(k->data.ton_giao.c_str());
		outtextxy(30, i, cccd);
		char* cccde = const_cast<char*>(k->data.cmnd.c_str());
		outtextxy(230 + 175 * 4, i, cccde);
		char* cccdr = const_cast<char*>(k->data.hometown.c_str());
		outtextxy(230 + 175 * 5, i, cccdr);
		char* cccdq = const_cast<char*>(k->data.ngaysinh.c_str());
		outtextxy(230 + 175 * 6, i, cccdq);
		char* cccdv = const_cast<char*>(k->data.job.c_str());
		outtextxy(230 + 175 * 7 - 30, i, cccdv);
		i += 32; j += 30;
		int postion;
		if (i > 727) {


			while (exit == 0)
			{
				if (kbhit())
				{
					char key = getch();
					if (key == 27) {
						cleardevice();
						menu2();
						exit = 1;
					}
				}
				if (ismouseclick(WM_LBUTTONDOWN))
				{
					getmouseclick(WM_LBUTTONDOWN, x, y);

					if ((x >= 1320 && x <= 1460) && (y >= 750 && y <= 780)) {

						i = 230 + 40;
						draw_statistical_box_2(); setcolor(red);
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
						outtextxy(50, 750, char_type5); outtextxy(70, 750, "-");
						outtextxy(90, 750, char_type5r);
						demlist += 15;
						if (demlist > 15) {
							setcolor(BLACK); setbkcolor(green);
							setfillstyle(1, green); bar(1180, 750, 1300, 780);
							setcolor(red); rectangle(1180, 750, 1300, 780); setcolor(WHITE);
							outtextxy(1240, 770, "<<PREV"); setcolor(red); setbkcolor(WHITE);

						}

					}
					else if ((x >= 1150 && x <= 1380) && (y >= 0 && y <= 40)) {
						search_by_mp();
					}
					else if ((x >= 1180 && x <= 1300) && (y >= 750 && y <= 780)) {
						setfillstyle(1, WHITE);
						bar(40, 730, 120, 780);
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


						i = 230 + 40;
						draw_statistical_box_2(); setcolor(red);
						xuattheo_vitri(l, demlist - 14, demlist);


					}

				}
			}
		}
	}
	while (exit == 0) {
		if (ismouseclick(WM_LBUTTONDOWN)) {
			getmouseclick(WM_LBUTTONDOWN, x, y);
			if ((x >= 0 && x <= 130) && (y >= 0 && y <= 40)) {
				exit = 1; setbkcolor(WHITE);
				menu2();
			}
			else if ((x >= 1150 && x <= 1380) && (y >= 0 && y <= 40)) {
				search_by_mp();
			}
		}
	}
}
void sort_by_room(){
	void xuli_data();
	listpht l; create_listpht_pht(l);
	ifstream  f; int x, y, exit = 0, demlist = 0, j = 0;
	int exit1 = 0;
	pht sv;
	f.open("quanliphong_menu2.txt", ios::in);
	if (f.fail())
		cout << "Error file! " << endl;
	while (!f.eof())  //read into endfile.
	{
		pht sv;
		Read_1_pht(f, sv);
		nodepht* p = create_node_pht(sv);
		add_node_pht_tail(l, p);
	}
	sort_by_room(l);


	ofstream fi; fi.open("quanliphong_menu2.txt", ios::out);
	for (nodepht* k = l.phead; k != NULL; k = k->pnext)
	{

		if (k == l.ptail) {

			fi << k->data.hometown << ',' << " "; fi << k->data.job << ',' << " ";
			fi << k->data.fullname << ',' << " "; fi << k->data.p << ',' << " ";
			fi << k->data.sex << ',' << " "; fi << k->data.dantoc << ',' << " ";
			fi << k->data.ton_giao << ',' << " "; fi << k->data.ngaysinh << ',' << " ";
			fi << k->data.vip << ',' << " "; fi << k->data.cmnd;
			break;
		}
		fi << k->data.hometown << ',' << " "; fi << k->data.job << ',' << " ";
		fi << k->data.fullname << ',' << " "; fi << k->data.p << ',' << " ";
		fi << k->data.sex << ',' << " "; fi << k->data.dantoc << ',' << " ";
		fi << k->data.ton_giao << ',' << " "; fi << k->data.ngaysinh << ',' << " ";
		fi << k->data.vip << ',' << " "; fi << k->data.cmnd << ',';
		fi << endl;

	}
	fi.close();

	draw_statistical_box_2();
	xuli_data();

}
void xuli_data() {
	void timkiem();
	setcolor(RED);
	listpht l; create_listpht_pht(l);
	ifstream  f; int x, y, exit = 0, demlist = 0, j = 0;
	int exit1 = 0;
	pht sv;
	f.open("quanliphong_menu2.txt", ios::in);
	if (f.fail())
		cout << "Error file! " << endl;
	while (!f.eof())  //read into endfile.
	{
		pht sv;
		Read_1_pht(f, sv);
		nodepht* p = create_node_pht(sv);
		add_node_pht_tail(l, p);
	}
	int len_list = len2(l);
	f.close();
	int dem = 1;
	danhso(l);
	int m = len2(l);
	int i = 230 + 40;

	setbkcolor(WHITE);
	// tinh toan phong
	int c[101];
	for (int i = 1; i <= 100; i++)
		c[i] = 0;
	int empty = 0;
	int dem_2 = 0;
	int full = 0;
	for (nodepht* k = l.phead; k != NULL; k = k->pnext)
	{
		int change = stoi(k->data.ton_giao);
		c[change]++;
	}
	for (int i = 1; i <= 100; i++)
	{
		if (c[i] == 0)
			empty++;
		else dem_2++;
	}
	for (int i = 1; i <= 100; i++)
	{
		if (c[i] == 4)
			full++;
	}
	ofstream fr; fr.open("list_phong_daco_nguoi.txt", ios::out);
	for (int i = 1; i <= 100; i++)
	{
		if (c[i]< 4)
		{
			fr << i << " ";
		}
	}
	fr.close();
	// TINH SO PHONG TRONG
	stringstream strs3;
	strs3 <<  empty;
	string m3 = strs3.str();
	char* char_type3 = (char*)m3.c_str();
	outtextxy(1250, 165, char_type3);
	//DANG THUE
	stringstream strs4;
	strs4 << 100-empty;
	string m34 = strs4.str();
	char* char_type34 = (char*)m34.c_str();
	outtextxy(1250, 190, char_type34);
	// phong full
	stringstream strs4e;
	strs4e <<full;
	string m34e = strs4e.str();
	char* char_type34e = (char*)m34e.c_str();
	outtextxy(1250, 190+25, char_type34e); 
	// danh so

	for (nodepht* k = l.phead; k != NULL; k = k->pnext)
	{
		
		demlist++;
		char* c = const_cast<char*>(k->data.p.c_str());
		outtextxy(230 + 175 * 3 - 20, i, c);
		char* cc = const_cast<char*>(k->data.sex.c_str());
		outtextxy(30 + 100, i, cc);
		char* ccc = const_cast<char*>(k->data.dantoc.c_str());
		outtextxy(230, i, ccc);
		char* cccb = const_cast<char*>(k->data.fullname.c_str());
		outtextxy(230 + 175 - 20, i, cccb);
		char* ccca = const_cast<char*>(k->data.vip.c_str());
		outtextxy(230 + 175 * 2, i, ccca);
		char* cccd = const_cast<char*>(k->data.ton_giao.c_str());
		outtextxy(30, i, cccd);
		char* cccde = const_cast<char*>(k->data.cmnd.c_str());
		outtextxy(230 + 175 * 4, i, cccde);
		char* cccdr = const_cast<char*>(k->data.hometown.c_str());
		outtextxy(230 + 175 * 5, i, cccdr);
		char* cccdq = const_cast<char*>(k->data.ngaysinh.c_str());
		outtextxy(230 + 175 * 6, i, cccdq);
		char* cccdv = const_cast<char*>(k->data.job.c_str());
		outtextxy(230 + 175 * 7 - 30, i, cccdv);
		i += 32; j += 30;
		
		int postion;
		if (i > 727) {


			while (exit == 0)
			{
				if (kbhit())
				{
					char key = getch();
					if (key == 27) {
						cleardevice();
						HomePageUIShow();
						exit = 1;
					}
				}
				if (ismouseclick(WM_LBUTTONDOWN))
				{
					getmouseclick(WM_LBUTTONDOWN, x, y);
				 if ((x >= 150 && x <= 340) && (y >= 0 && y <= 40)) {
					
					
					 exit = 1; input_user_menu2();

				}
				 else if ((x >= 400 && x <= 550) && (y >= 70 && y <= 140)) {
					 setfillstyle(1, blue_d);
					 setcolor(green);
					 rectangle(400, 70, 550, 140); setcolor(WHITE);
					 bar(400, 70, 550, 140);
					 setcolor(BLACK);
					 setbkcolor(blue_d);
					 settextstyle(9, 0, 4);
					 outtextxy(480, 120, "SapXep");
					 sort_by_room();
				 }
				 else if ((x>=220&&x<=450)&&(y>=150&&y<=200)){
					 setfillstyle(1, WHITE);
					 bar(220, 150, 450, 200);
					 int m;
					
					 setcolor(yellow); setbkcolor(WHITE);
					 rectangle(220, 150, 450, 200); 

					 setbkcolor(WHITE);
					 char  t[50], t1[50] = " "; setcolor(RED);
					 Input(t, t1, 320, 180, '0', '9', 220, 150, 450, 200); strcpy(t1, t); 
					
					 int postion = atoi(t); 					

					 listpht ty;
					 nodepht* p = search(l, postion);
					 nodepht* c = p;
					// c->pnext = NULL;
					 listpht mk;
					 create_listpht_pht(mk);
					 add_node_pht_tail(mk, c);
					 SaveFile_Backup(mk);
					 XoaNodeCoKhoaBatKy(l, postion);
					 ofstream fi; fi.open("quanliphong_menu2.txt", ios::out);
					
						 for (nodepht* k = l.phead; k != NULL; k = k->pnext)
						 {

							 if (k == l.ptail) {

								 fi << k->data.hometown << ',' << " "; fi << k->data.job << ',' << " ";
								 fi << k->data.fullname << ',' << " "; fi << k->data.p << ',' << " ";
								 fi << k->data.sex << ',' << " "; fi << k->data.dantoc << ',' << " ";
								 fi << k->data.ton_giao << ',' << " "; fi << k->data.ngaysinh << ',' << " ";
								 fi << k->data.vip << ',' << " "; fi << k->data.cmnd;
								 break;
							 }
							 fi << k->data.hometown << ',' << " "; fi << k->data.job << ',' << " ";
							 fi << k->data.fullname << ',' << " "; fi << k->data.p << ',' << " ";
							 fi << k->data.sex << ',' << " "; fi << k->data.dantoc << ',' << " ";
							 fi << k->data.ton_giao << ',' << " "; fi << k->data.ngaysinh << ',' << " ";
							 fi << k->data.vip << ',' << " "; fi << k->data.cmnd << ',';
							 fi << endl;

						 }
						 fi.close();
					 
					 draw_statistical_box_2();
					 xuli_data();
				 }
				 else
					if ((x >= 1320 && x <= 1460) && (y >= 750 && y <= 780)) {

						i = 230 + 40;
						draw_statistical_box_2(); setcolor(red);
						xuattheo_vitri(l, demlist+1, demlist + 15);
						

					
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
						outtextxy(50, 750, char_type5); outtextxy(70, 750, "-");
						outtextxy(90, 750, char_type5r);
						demlist += 15;
						if (demlist > 15) {
							setcolor(BLACK); setbkcolor(green);
							setfillstyle(1, green); bar(1180, 750, 1300, 780);
							setcolor(red); rectangle(1180, 750, 1300, 780); setcolor(WHITE);
							outtextxy(1240, 770, "<<PREV"); setcolor(red); setbkcolor(WHITE);

						}
						
					}
					else if ((x >= 1180 && x <= 1300) && (y >= 750 && y <= 780)) {
						setfillstyle(1, WHITE);
						bar(40, 730, 120, 780);
						setfillstyle(8, Plum1);
						bar(40, 730, 120, 780);
						demlist = demlist - 15;
						int next1 = demlist-15;
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
						

						i = 230 + 40;
						draw_statistical_box_2(); setcolor(red);
						xuattheo_vitri(l, demlist - 14, demlist);


					}


					else
						if ((x >= 0 && x <= 130) && (y >= 0 && y <= 40)) {
							exit = 1; HomePageUIShow();
						}
						else if ((x >= 580 && x <= 770) && (y >= 70 && y <= 140)) {
							setfillstyle(1, red);
							setcolor(BLACK);
							rectangle(580, 70, 770, 140); setcolor(WHITE);
							bar(580, 70, 770, 140);
							setbkcolor(red);
							settextstyle(9, 0, 4);
							outtextxy(680, 120, "BACKUP"); backup_daxoa();
						}
						else if ((x >= 50 && x <= 200) && (y >= 150 && y <= 240)) {

							timkiem();
						}
						/*else if ((x >= 220 && x <= 380) && (y >= 70 && y <= 140))
						{
							setbkcolor(blue_B);
							exit = 1;
						}*/
						
						
				}


			}
			
		}


	}
	


}
void timkiem() {
	cleardevice();
	void menu2();
	settextstyle(9, 0, 4);
	setfillstyle(9, blue_d);
	bar(0, 0, 1520, 850);
	setfillstyle(1, yellow); setcolor(red); setbkcolor(yellow);
	bar(0, 0, 130, 40); outtextxy(60, 30, "<BACK"); setcolor(RED);
	rectangle(0, 0, 130, 40);
	int exit = 0, x, y, exit1 = 0;
	setfillstyle(1, xinh);
	setcolor(WHITE); setbkcolor(xinh);
	bar(130, 0, 1520, 40); settextjustify(1, 1);
	settextstyle(9, 0, 4);
	outtextxy(1520 / 2, 30, "Phan Tim Kiem Thong Tin"); settextstyle(9, 0, 1);
	menutimkiem();
	setfillstyle(1, red);
	setcolor(BLACK);
	bar(80, 100, 350, 150); rectangle(80, 100, 350, 150); setcolor(WHITE); settextstyle(9, 0, 4);
	outtextxy(200, 140, "Nhap Phong"); setcolor(red);
	rectangle(350, 100, 650, 150);
	setfillstyle(1, green);
	bar(700, 100, 900, 150); setcolor(yellow); setbkcolor(green);
	rectangle(700, 100, 900, 150); setcolor(WHITE);
	outtextxy(800, 140, "SEARCH");
	setfillstyle(1, yellow);
	bar(950, 100, 1150, 150); setcolor(BLUE); setbkcolor(yellow);
	rectangle(950, 100, 1150, 150); setcolor(BLUE);
	outtextxy(1050, 140, "RESET");
	while (exit == 0) {
		if (ismouseclick(WM_LBUTTONDOWN)) {
			getmouseclick(WM_LBUTTONDOWN, x, y);
			if ((x >= 0 && x <= 130) && (y >= 0 && y <= 40)) {
				exit = 1; setbkcolor(WHITE);
				menu2();
			}
			else if ((x>=350&&x<=650)&&(y>=100&&y<=150)) {
				
				settextstyle(9, 0, 4);
				setfillstyle(1, WHITE);
				bar(350, 100, 650, 150);
				setcolor(yellow); rectangle(350, 100, 650, 150);
				char s[50], s1[50] = " "; setcolor(red);
				Input(s, s1, 450, 140, '0', '9', 350, 100, 650, 150);
				strcpy(s1, s);
				ofstream f; f.open("try.txt", ios::out);
				f << s; f.close(); settextstyle(9, 0, 1);
				menutimkiem();
			}
			else if ((x>=700&&x<=900)&&(y>=100&&y<=150)) {
				setfillstyle(1, yellow);
				bar(700, 100, 900, 150); setcolor(red); setbkcolor(yellow);
				rectangle(700, 100, 900, 150); setcolor(BLUE);
				outtextxy(800, 140, "SEARCH");
				char position[15];
				ifstream f1; f1.open("try.txt", ios::in);
				f1>>position; f1.close();
				listpht l; create_listpht_pht(l);
				ifstream  f; int x, y, exit = 0, demlist = 0, j = 0;
				int exit1 = 0;
				pht sv;
				f.open("quanliphong_menu2.txt", ios::in);
				if (f.fail())
					cout << "Error file! " << endl;
				while (!f.eof())  //read into endfile.
				{
					pht sv;
					Read_1_pht(f, sv);
					nodepht* p = create_node_pht(sv);
					add_node_pht_tail(l, p);
				}
				int len_list = len2(l);
				f.close(); int m = len2(l);
				int i = 230 + 40; danhso(l); setcolor(BLUE); settextstyle(9, 0, 1); setbkcolor(blue_d);
				cout << endl << position << endl;
				int flag = 0; setbkcolor(WHITE);
				for (nodepht* k = l.phead; k != NULL; k = k->pnext)
				{
					char* c = const_cast<char*>(k->data.ton_giao.c_str());
					
					if (strcmp(c,position)==0) {
						flag = 1;
						char* c = const_cast<char*>(k->data.p.c_str());
						outtextxy(230 + 175 * 3 - 20, i, c);
						char* cc = const_cast<char*>(k->data.sex.c_str());
						outtextxy(30 + 100, i, cc);
						char* ccc = const_cast<char*>(k->data.dantoc.c_str());
						outtextxy(230, i, ccc);
						char* cccb = const_cast<char*>(k->data.fullname.c_str());
						outtextxy(230 + 175 - 20, i, cccb);
						char* ccca = const_cast<char*>(k->data.vip.c_str());
						outtextxy(230 + 175 * 2, i, ccca);
						char* cccd = const_cast<char*>(k->data.ton_giao.c_str());
						outtextxy(30, i, cccd);
						char* cccde = const_cast<char*>(k->data.cmnd.c_str());
						outtextxy(230 + 175 * 4, i, cccde);
						char* cccdr = const_cast<char*>(k->data.hometown.c_str());
						outtextxy(230 + 175 * 5, i, cccdr);
						char* cccdq = const_cast<char*>(k->data.ngaysinh.c_str());
						outtextxy(230 + 175 * 6, i, cccdq);
						char* cccdv = const_cast<char*>(k->data.job.c_str());
						outtextxy(230 + 175 * 7 - 30, i, cccdv);
						i += 32; j += 30;
					}
					
				}
				if(flag==0)
				{
					setcolor(red);
					setfillstyle(1, WHITE);
					bar(350, 100, 650, 150); setbkcolor(WHITE);
					outtextxy(480, 140, "Phong Khong Ton Tai");
					setcolor(BLUE);
					menutimkiem(); setbkcolor(WHITE);
				}
			}
			else if ((x>=950&&x<=1150)&&(y>=100&&y<=150)) {
				setfillstyle(1, red); settextstyle(9, 0, 4);
				bar(950, 100, 1150, 150); setcolor(BLUE); setbkcolor(red);
				rectangle(950, 100, 1150, 150); setcolor(WHITE);
				outtextxy(1050, 140, "RESET"); settextstyle(9, 0, 1);
				menutimkiem(); setbkcolor(yellow); setcolor(red); settextstyle(9, 0, 4);
			}
		}
	}
}
void menu2() {
	int exit = 0, x, y;
	cleardevice();
	setbkcolor(Plum1);
	setfillstyle(8, Plum1);
	bar(0, 0, 1520, 850);
	setcolor(WHITE); setbkcolor(blue_B);
	bar(0, 0, 1520, 40); settextjustify(1, 1);
	settextstyle(9, 0, 0);
	outtextxy(1520 / 2, 30, "QUAN LI PHONG O SINH VIEN"); settextstyle(9, 0, 3);
	setfillstyle(1, yellow); setcolor(red); setbkcolor(yellow);
	bar(0, 0, 130, 40); outtextxy(60, 30, "<BACK"); setcolor(RED);
	rectangle(0, 0, 130, 40);
	setfillstyle(1, red); setcolor(WHITE); setbkcolor(red);
	bar(150, 0, 340, 40); outtextxy(250, 30, "ADD DATA"); setcolor(WHITE);
	rectangle(150, 0, 340, 40); settextstyle(9, 0, 1);
	setfillstyle(1, red);
	setcolor(green);
	rectangle(400, 70, 550, 140); setcolor(WHITE);
	bar(400, 70, 550, 140);
	setcolor(WHITE);
	setbkcolor(red);
	settextstyle(9, 0, 4);
	outtextxy(480, 120, "SapXep");
	// backup
	setfillstyle(1, yellow);
	setcolor(BLACK);
	rectangle(580, 70, 770, 140); setcolor(BLUE);
	bar(580, 70, 770, 140);
	setbkcolor(yellow);
	settextstyle(9, 0, 4);
	outtextxy(680, 120, "BACKUP");
	setfillstyle(1, blue_d);
	setcolor(RED);
	rectangle(50, 150, 200, 240);
	bar(50, 150, 200, 240);
	setbkcolor(blue_d);
	settextstyle(9, 0, 2);
	outtextxy(120, 190, "Tim Kiem");
	setfillstyle(1, blue);
	bar(220, 70, 380, 140);
	setcolor(yellow);
	setbkcolor(blue);
	settextstyle(9, 0, 1); settextstyle(4, 0,5);
	outtextxy(300, 120, "Xoa");
	setcolor(BLUE);
	rectangle(220, 150, 450, 200);
	setcolor(BLACK); settextstyle(9, 0, 1);
	outtextxy(270, 180, "VT:");
	setfillstyle(1, BLUE);
	setcolor(yellow); settextstyle(9, 0, 1);
	bar(1320, 750, 1460, 780);		setbkcolor(BLUE); setcolor(YELLOW);
	rectangle(1320, 750, 1460, 780); setcolor(WHITE);
	outtextxy(1400, 770, "NEXT>>");
	draw_statistical_box_2();
	xuli_data();
	while (exit == 0)
	{
		if (ismouseclick(WM_LBUTTONDOWN)) {
			getmouseclick(WM_LBUTTONDOWN, x, y);
			if ((x >= 0 && x <= 130) && (y >= 0 && y <= 40)) {
				exit = 1; HomePageUIShow();
			}
			else if ((x >= 150 && x <= 340) && (y >= 0 && y <= 40)) {
				setbkcolor(WHITE);
				input_user_menu2();
			}
			else if ((x>=50&&x<=200)&&(y>=150&&y<=240)) {
				
				timkiem();
			}
			else if ((x>=400&&x<=550)&&(y>=70&&y<=140)) {
				setfillstyle(1, blue_d);
				setcolor(green);
				rectangle(400, 70, 550, 140); setcolor(WHITE);
				bar(400, 70, 550, 140);
				setcolor(BLACK);
				setbkcolor(blue_d);
				settextstyle(9, 0, 4);
				outtextxy(480, 120, "SapXep");
				sort_by_room();
			}
			else if ((x >= 220 && x <= 450) && (y >= 150 && y <= 200)) {
				int m;
				listpht l; create_listpht_pht(l);
				ifstream  f; int x, y, exit = 0, demlist = 0, j = 0;
				int exit1 = 0;
				pht sv;
				f.open("quanliphong_menu2.txt", ios::in);
				if (f.fail())
					cout << "Error file! " << endl;
				while (!f.eof())  //read into endfile.
				{
					pht sv;
					Read_1_pht(f, sv);
					nodepht* p = create_node_pht(sv);
					add_node_pht_tail(l, p);
				}
				danhso(l);
				setcolor(yellow); setbkcolor(WHITE);
				rectangle(220, 150, 450, 200);
				char  t[50], t1[50] = " "; setbkcolor(WHITE);
				setcolor(red);
				Input(t, t1, 320, 180, '0', '9', 220, 150, 450, 200); strcpy(t1, t);
				
				
				int postion = atoi(t); 
				listpht ty;
				nodepht* p = search(l, postion);
				nodepht* c = p;
			//	c->pnext = NULL;
				listpht mk;
				create_listpht_pht(mk);
				add_node_pht_tail(mk, c);
				SaveFile_Backup(mk);
				
				XoaNodeCoKhoaBatKy(l, postion);
				ofstream fi; fi.open("quanliphong_menu2.txt", ios::out);
				
					for (nodepht* k = l.phead; k != NULL; k = k->pnext)
					{

						if (k == l.ptail) {

							fi << k->data.hometown << ',' << " "; fi << k->data.job << ',' << " ";
							fi << k->data.fullname << ',' << " "; fi << k->data.p << ',' << " ";
							fi << k->data.sex << ',' << " "; fi << k->data.dantoc << ',' << " ";
							fi << k->data.ton_giao << ',' << " "; fi << k->data.ngaysinh << ',' << " ";
							fi << k->data.vip << ',' << " "; fi << k->data.cmnd;
							break;
						}
						fi << k->data.hometown << ',' << " "; fi << k->data.job << ',' << " ";
						fi << k->data.fullname << ',' << " "; fi << k->data.p << ',' << " ";
						fi << k->data.sex << ',' << " "; fi << k->data.dantoc << ',' << " ";
						fi << k->data.ton_giao << ',' << " "; fi << k->data.ngaysinh << ',' << " ";
						fi << k->data.vip << ',' << " "; fi << k->data.cmnd << ',';
						fi << endl;

					}
					fi.close();
				
				draw_statistical_box_2();
				xuli_data();
			}
			else if ((x >= 580 && x <= 770) && (y >= 70 && y <= 140)) {
				setfillstyle(1, red);
				setcolor(BLACK);
				rectangle(580, 70, 770, 140); setcolor(WHITE);
				bar(580, 70, 770, 140);
				setbkcolor(red);
				settextstyle(9, 0, 4);
				outtextxy(680, 120, "BACKUP"); backup_daxoa();
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
	}

}