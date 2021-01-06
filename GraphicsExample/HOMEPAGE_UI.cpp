#include"HOMEPAGE_UI.h"
#include<fstream>
#include<Windows.h>
#include"menu1.h"
#include"menu3.h"
#include"menu2.h"
#include"menu8.h"
#include"baocao.h"
#include"inhoadon.h"
#include"pay_money_service.h"
#include"datphong.h"
#include"doimatkhau.h"
#include"quanlithiet_bi.h"
#include"thongtinphanmem.h"

void ChooseItem(ItemMenu item) {
	setfillstyle(SOLID_FILL, BLUE);
	bar(MENU_LEFT, item.top, MENU_RIGHT, item.bottom);
	setcolor(red);
	outtextxy(MENU_LEFT + 20, item.top + MENU_HEIGHT / 4, item.text);
}


void OutItem(ItemMenu item) {
	setcolor(BLUE);
	setfillstyle(SOLID_FILL, WHITE);
	bar(MENU_LEFT, item.top, MENU_RIGHT, item.bottom);
	setbkcolor(WHITE);
	rectangle(MENU_LEFT, item.top, MENU_RIGHT, item.bottom);
	outtextxy(MENU_LEFT + 20, item.top + MENU_HEIGHT / 4, item.text);
}

bool isTrue() {
	int mouse_x;
	int mouse_y;
	if (ismouseclick(WM_LBUTTONDOWN)) {
		getmouseclick(WM_LBUTTONDOWN, mouse_x, mouse_y);
		if (mouse_x >= MENU_LEFT && mouse_x <= MENU_RIGHT && mouse_y >= MENU_HEIGHT && mouse_y <= MENU_HEIGHT * MENU_SIZE + MENU_HEIGHT) {
			return true;
		}
		else {
			return false;
		}
	}
	return false;
}

void MouseListener() {
	while (!isTrue()) {
		int mouse_x;
		int mouse_y;
		if (ismouseclick(WM_MOUSEMOVE))
		{
			getmouseclick(WM_MOUSEMOVE, mouse_x, mouse_y);


			for (int i = 0; i < MENU_SIZE; i++) {
				if (mouse_x >= MENU_LEFT && mouse_x <= MENU_RIGHT && mouse_y >= menu[i].top && mouse_y <= menu[i].bottom - 1) {
					if (menu[i].hover == false) {
						ChooseItem(menu[i]);
					}
					menu[i].hover = true;
				}
				else {
					if (menu[i].hover) {
						menu[i].hover = false;
						OutItem(menu[i]);
					}
				}
			}
		}
		delay(0.0001);
	}
	for (int i = 0; i < MENU_SIZE; i++) {
		if (menu[i].hover) {
			//Goto new Intent

			if (i + 1 == 1) {
				Beep(600, 200);
				init_record();
			}
			else if (i + 1 == 2) {
				Beep(600, 200);
				menu2();
			}
			else if (i + 1 == 3) {
				cleardevice();
				menuthree();
			}
			else if (i + 1 == 4) {

				menu_chinh_4();

			}
			else if (i + 1 == 5) {

				main_menu_hoadon();

			}
			else if (i + 1 == 6) {

				main_menu_report();

			}
			else if (i + 1 == 7) {

				 main_menu_thietbi();

			}
			else if (i + 1 == 8) {

				menu_chinh();

			}
			else if (i + 1 == 9) {
				main_menu_hopdong();

			}
			else if (i + 1 == 10) {

				doipass();

			}
			else if (i + 1 == 11) {

				infor_sofware();
			}
			else if (i + 1 == 12) {
				menu_main();
				

			}
			menu[i].hover = false;
			//			break;
		}
	}
}

void InitMenu() {
	for (int i = 1; i <= MENU_SIZE; i++) {
		menu[i - 1].top = MENU_HEIGHT * i;
		menu[i - 1].bottom = menu[i - 1].top + MENU_HEIGHT;
	}
}

void ShowItem(ItemMenu item) {
	setcolor(BLUE);
	rectangle(MENU_LEFT, item.top, MENU_RIGHT, item.bottom);
	outtextxy(MENU_LEFT + 20, item.top + MENU_HEIGHT / 4, item.text);
}

void ShowMenu() {

	InitMenu();

	setcolor(BLUE);
	settextstyle(FONT, 0, 2);
	rectangle(0, 0, MENU_RIGHT, (MENU_SIZE + 1) * MENU_HEIGHT);
	settextjustify(1, 2);
	outtextxy((MENU_LEFT + MENU_RIGHT) / 2, MENU_HEIGHT * 0 + MENU_HEIGHT / 4, "MENU");
	settextstyle(FONT, 0, 1);
	settextjustify(0, 2);
	for (int i = 1; i <= MENU_SIZE; i++) {
		ShowItem(menu[i - 1]);
	}

}

void HomePageUIShow() {

	cleardevice();

	setbkcolor(WHITE);
	setfillstyle(7, blue_d);
	bar(0, 0, 1520, 850);
	setcolor(red);
	setlinestyle(0, 1, 1);
	settextjustify(0, 2); floodfill(LEFT_TITLE, 3 * HEIGHT / 4 - 10, 2);
	rectangle(LEFT_TITLE + 15, 240, 1060, 3 * HEIGHT / 4);
	rectangle(LEFT_TITLE + 25, 230, 1050, 3 * HEIGHT / 4 + 10);
	settextstyle(FONT, 0, 7);
	outtextxy(LEFT_TITLE, 200, "HOSTEL");
	settextstyle(FONT, 0, 6);
	outtextxy(LEFT_TITLE, 270, "MANAGER");
	settextstyle(FONT, 0, 1);
	outtextxy(LEFT_TITLE + 50, 320, "A project of: ");
	line(LEFT_TITLE + 50, 340, LEFT_TITLE + 185, 340);
	outtextxy(LEFT_TITLE + 80, 350, "Le Ngoc Hieu -N18DCAT022(Nhom Truong)");
	outtextxy(LEFT_TITLE + 80, 400, "Trinh Van Trung - N18DCAT098");
	outtextxy(LEFT_TITLE + 80, 450, "Tran Quang Linh-N18DCAT040");
	outtextxy(LEFT_TITLE + 80, 500, "Luong Van Loi- N18DCAT048");
	ShowMenu();
	MouseListener();

}