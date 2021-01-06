#include"thongtinphanmem.h"
void infor_sofware() {
	int exit = 0, x, y;
	cleardevice();
	setfillstyle(1, blue_B);
	setcolor(WHITE); setbkcolor(blue_B);
	bar(0, 0, 1520, 40); settextjustify(1, 1);
	settextstyle(9, 0, 0);
	outtextxy(1520 / 2, 30, "THONG TIN PHAN MEM"); settextstyle(9, 0, 3);
	setfillstyle(1, yellow); setcolor(red); setbkcolor(yellow);
	bar(0, 0, 130, 40); outtextxy(60, 30, "<BACK"); setcolor(RED);
	rectangle(0, 0, 130, 40);
	

	setcolor(red); setlinestyle(1, 0, 1); setbkcolor(WHITE);
	setfillstyle(7, blue_d);
	bar(0, 40, 1520, 850); settextstyle(9, 0, 4);
	outtextxy(700, 130, "DO AN MON CAU TRUC DU LIEU VA GIAI THUAT");
	rectangle(200, 150, 1200, 750); setcolor(BLACK);
	
	settextstyle(9, 0, 10); settextjustify(0, 1);
	setcolor(YELLOW); setbkcolor(RED);
	outtextxy(300, 500, "THANKS!");
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