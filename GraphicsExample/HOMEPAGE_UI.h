#pragma once
#include"graphics.h"
#define WIDTH 1800
#define HEIGHT 700

#define LEFT_TITLE 1350/3

#define MENU_LEFT 0
#define MENU_RIGHT 350
#define MENU_HEIGHT 50
#define MENU_SIZE 12

#define FONT 9
namespace

{
	struct ItemMenu {
		char text[50];
		int top;
		int bottom;
		bool hover;

	}
	menu[] = {
		{"THONG TIN NHA TRO"},
		{"QUAN LI PHONG O"},
		{"QUAN LI CHI TIEU"},
		{"THANH TOAN TIEN DICHVU"},
		{"IN HOA DON"},
		{"BAO CAO"},
		{"QUAN LI THIET BI"},
		{"HOP DONG"},
		{"DAT PHONG"},
		{"THAY DOI TAI KHOAN"},
		{"THONG TIN PHAN MEM"},
		{"LUU VA THOAT"}
	};
}
void ChooseItem(ItemMenu item);
void OutItem(ItemMenu item);
bool isTrue();
void MouseListener();
void InitMenu();
void ShowItem(ItemMenu item);
void ShowMenu();
void HomePageUIShow();
