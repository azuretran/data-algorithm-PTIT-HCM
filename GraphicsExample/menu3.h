#pragma once
#include"graphics.h"
#include<string>
#include<iostream>
#include<fstream>
#include <sstream>
#include<ctime>
using namespace std;

namespace
{
	struct date {
		int day, month, year;
	};
	struct expense_management {
		date ngay;
		string khoanchi;
		int money;
		string notice;
		int vt;
	}; typedef struct expense_management expm;
	struct nodexpm {
		expm data;
		struct nodexpm* pnext;
	};
	struct list {
		nodexpm* phead; nodexpm* ptail;
	};
}
	
		



void create_list_expm(list& l) {
	l.phead = NULL;
	l.ptail = NULL;
}
nodexpm* create_node_expm(expm x) {
	nodexpm* p = new nodexpm;
	p->data = x;
	p->pnext = NULL;
	return p;
}
void add_node_expm_tail(list& l, nodexpm* p)
{

		if (l.phead == NULL)
		{
			l.phead = l.ptail = p;
		}
		else
		{
			l.ptail->pnext = p;
			l.ptail = p;
		}
}
void add_node_expm_head(list& l, nodexpm* p)
{

	if (l.phead == NULL)
	{
		l.phead = l.ptail = p;
	}
	else
	{
		p->pnext = l.phead; 
		l.phead = p; 
	}
}
void danhso(list&l) {
	int dem = 1;
	for (nodexpm* k = l.phead; k != NULL; k = k->pnext) {
		k->data.vt = dem; dem++;
	}
}
void ThemNode_p_VaoViTriBatKi(list&l, nodexpm* p, int vt,int n)
{

	// danh sách đang rỗng
	if (l.phead == NULL || vt == 1)
	{
		// thêm node p vào đầu danh sách l
		add_node_expm_head(l, p);
	}
	else if (vt == n + 1)
	{
		// thêm node p vào cuối danh sách l
		add_node_expm_tail(l, p);
	}
	else // vt nằm trong đoạn [2, n]
	{
		int dem = 0; // xác định vt cần thêm
		// ============ CÁCH 2: TRONG DANH SÁCH TỒN TẠI TỪ 2 NODE Q TRỞ LÊN ============
		nodexpm* g = new nodexpm; // node g chính là node giữ liên kết với cái node nằm trước node q trong danh sách
		// duyệt danh sách từ đầu đến cuối để tìm node q <=> tìm ra cái vị trí vt cần thêm node p vào..
		for (nodexpm* k = l.phead; k != NULL; k = k->pnext)
		{
			dem++;
			// tìm vị trí vt cần thêm
			if (dem == vt)
			{
				nodexpm* h = create_node_expm(p->data); // mỗi lần phát hiện 1 node q thì ta khởi tạo 1 node p mới <=> khởi tạo node h
				// thực hiện bài toán thêm node p vào sau node g là ra vấn đề <=> thêm node p vào trước node q
				h->pnext = k; // Bước 1: cho node h trỏ(liên kết) đến node k <=> cũng chính là cho node h trỏ đến node q
				g->pnext = h; // Bước 2: cho node g trỏ đến node h 
				break;
			}
			g = k; // giữ liên kết với cái node nằm trước node q trong danh sách
		}
	}
}
void XoaDau(list& l)
{
	// nếu danh sách rỗng
	if (l.phead == NULL)
	{
		return;
	}
	nodexpm* p = l.phead; // node p là node sẽ xóa
	l.phead = l.phead->pnext;// cập nhật lại l.pHead là phần tử kế tiếp
	delete p;
}

// xóa cuối
void XoaCuoi(list& l)
{

	// nếu danh sách rỗng
	if (l.phead == NULL)
	{
		return;
	}
	// trường hợp danh sách có phần tử
	if (l.phead->pnext == NULL)
	{
		XoaDau(l);
		return;
	}
	// duyệt từ đầu danh sách đến thằng kế cuối
	for (nodexpm* k = l.phead; k != NULL; k = k->pnext)
	{
		// phát hiện thằng kế cuối
		if (k->pnext == l.ptail)
		{
			delete l.ptail; // xóa đi phần tử cuối
			k->pnext = NULL; // cho con trỏ của node kế cuối trỏ đến vùng nhớ null
			l.ptail = k; // cập nhật lại l.pTail
			return;
		}
	}
}
void XoaNodeCoKhoaBatKy(list&l, int x)
{
	danhso(l);
	
	// nếu danh sách rỗng thì không làm gì hết
	if (l.phead == NULL)
	{
		return;
	}
	// nếu node cần xóa nằm đầu danh sách
	if (l.phead->data.vt == x)
	{
		XoaDau(l);
		return;
	}
	// nếu node cần xóa nằm ở cuối danh sách
	if (l.ptail->data.vt == x)
	{
		XoaCuoi(l);
		return;
	}

	nodexpm* g = new nodexpm; // node g là node trỏ đến node nằm trước node cần xóa: x
	// duyệt danh sách liên kết đơn để tìm
	for (nodexpm* k = l.phead; k != NULL; k = k->pnext)
	{
		// phát hiện phần tử cần xóa
		if (k->data.vt == x)
		{
			g->pnext = k->pnext; // cập nhật mối liên kết giữa node k với node sau node h
			delete k; // xóa node nằm sau node k	
			return;
		}
		g = k; // cho node g trỏ đến node k
	}

}

void ReadDate_expm(ifstream& f, date& d)
{
	f >> d.day;
	f.seekg(1, 1);
	f >> d.month;
	f.seekg(1, 1);
	f >> d.year;
	f.seekg(1, 1);
}
void Read_1_SV(ifstream& f, expm& sv) {
	getline(f, sv.khoanchi, ',');
	f.seekg(1, 1);
	getline(f, sv.notice, ',');
	f.seekg(1, 1);
	ReadDate_expm(f, sv.ngay);
	f.seekg(1, 1);
	f >> sv.money;
}

void ReadFile_to_list_expm(ifstream& f, list& l)
{
	while (!f.eof())  //read into endfile.
	{
		expm sv;
		Read_1_SV(f, sv);
		nodexpm* p = create_node_expm(sv);
		add_node_expm_tail(l, p);
	}

}

void ReadData_expm(list& l)
{
	ifstream  f;
	f.open("Text.txt", ios::in);
	if (f.fail())                     //neu mo file that bai
		cout << "Error FIle! " << endl;
	ReadFile_to_list_expm(f, l);           // doc du lieu tu file vao dslk don
	f.close();
}
int len(list l) {
	int count = 0;
	for (nodexpm* k = l.phead; k != NULL; k = k->pnext) {
		count++;
	}
	return count;
}

void write_infoexpm(ofstream& fo, expm&t) {
	
	fo << t.khoanchi << "," << " ";
	fo << t.notice << "," << " ";
	fo << t.ngay.day << "/" << t.ngay.month << "/" << t.ngay.year << "," << " ";
	fo << t.money;
}
void save_file_expm(list l) {
	
	
	ofstream fileout; fileout.open("expense_management.txt", ios::out);
	for (nodexpm*k=l.phead; k != NULL; k = k->pnext)
	{
		write_infoexpm(fileout,k->data); fileout << endl;
		fileout << endl;
	}
	fileout.close();

}
void hoanvi(expm& a, expm& b)
{
	expm t = a; a = b; b = t;
}
void sort_by_months(list&l)
{
	for (nodexpm* p = l.phead; p; p = p->pnext)
		for (nodexpm* q = p->pnext; q; q = q->pnext)
			if (p->data.ngay.month > q->data.ngay.month)
				hoanvi(p->data, q->data);
}
void sort_by_day(list&l)
{
	for (nodexpm* p = l.phead; p; p = p->pnext)
		for (nodexpm* q = p->pnext; q; q = q->pnext)
			if (p->data.ngay.day > q->data.ngay.day)
				hoanvi(p->data, q->data);
}
void sort_by_years(list&l)
{
	for (nodexpm* p = l.phead; p; p = p->pnext)
		for (nodexpm* q = p->pnext; q; q = q->pnext)
			if (p->data.ngay.year > q->data.ngay.year)
				hoanvi(p->data, q->data);
}
void edit_by_postion(list&l, int x) {
	
	expm sv;
	danhso(l);	ifstream f; f.open("input_menu8.txt", ios::in);
	Read_1_SV(f, sv); f.close();
	for (nodexpm* k = l.phead; k != NULL; k = k->pnext)
	{
		
		if (k->data.vt == x) {
			
			k->data.khoanchi = sv.khoanchi;
			
			k->data.notice = sv.notice;

			k->data.ngay = sv.ngay;
			k->data.money = sv.money;
			
			break;
			
		}
		
		
	}
}
void menuthree();