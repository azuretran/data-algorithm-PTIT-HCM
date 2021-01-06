#pragma once
#include"graphics.h"
#include"HOMEPAGE_UI.h"
#include"Longin_user.h"
#include<fstream>
#include<iostream>
#include<ctime>
using  namespace std;
#define left1 40
#define right1 700
#define top1 45
#define bottom1 270
void menu8();
void menu_chinh();
namespace
{
	struct date8{
		int day, month, year;
	};
	struct person_hostel {
		char id[10];
		string name;
		char sex[10];
		date8 ngayki;
		date8 ngayhethan;
		char phone_number[15];
		char id_card[20];
		string adress;
		date8 brith;
		int vt;
		int pos;
	}; typedef struct person_hostel psh;
	struct node{
		psh data;
		struct node* pnext;
	};
	struct list_psh {
		node* phead; node* ptail;
	};

}
void create_list_psh_psh(list_psh& l) {
	l.phead = NULL;
	l.ptail = NULL;
}
node* create_node_psh(psh x) {
	node* p = new node;
	p->data = x;
	p->pnext = NULL;
	return p;
}
void add_node_psh_tail(list_psh& l, node* p)
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
void add_node_psh_head(list_psh& l, node* p)
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
int danhso(list_psh& l) {
	int dem = 1;
	for (node* k = l.phead; k != NULL; k = k->pnext) {
		k->data.pos = dem; dem++;
	}
	return dem;
}
void ThemNode_p_VaoViTriBatKi(list_psh& l, node* p, int vt, int n)
{

	// danh sách đang rỗng
	if (l.phead == NULL || vt == 1)
	{
		// thêm node p vào đầu danh sách l
		add_node_psh_head(l, p);
	}
	else if (vt == n + 1)
	{
		// thêm node p vào cuối danh sách l
		add_node_psh_tail(l, p);
	}
	else // vt nằm trong đoạn [2, n]
	{
		int dem = 0; // xác định vt cần thêm
		// ============ CÁCH 2: TRONG DANH SÁCH TỒN TẠI TỪ 2 NODE Q TRỞ LÊN ============
		node* g = new node; // node g chính là node giữ liên kết với cái node nằm trước node q trong danh sách
		// duyệt danh sách từ đầu đến cuối để tìm node q <=> tìm ra cái vị trí vt cần thêm node p vào..
		for (node* k = l.phead; k != NULL; k = k->pnext)
		{
			dem++;
			// tìm vị trí vt cần thêm
			if (dem == vt)
			{
				node* h = create_node_psh(p->data); // mỗi lần phát hiện 1 node q thì ta khởi tạo 1 node p mới <=> khởi tạo node h
				// thực hiện bài toán thêm node p vào sau node g là ra vấn đề <=> thêm node p vào trước node q
				h->pnext = k; // Bước 1: cho node h trỏ(liên kết) đến node k <=> cũng chính là cho node h trỏ đến node q
				g->pnext = h; // Bước 2: cho node g trỏ đến node h 
				break;
			}
			g = k; // giữ liên kết với cái node nằm trước node q trong danh sách
		}
	}
}
void XoaDau(list_psh& l)
{
	// nếu danh sách rỗng
	if (l.phead == NULL)
	{
		return;
	}
	node* p = l.phead; // node p là node sẽ xóa
	l.phead = l.phead->pnext;// cập nhật lại l.pHead là phần tử kế tiếp
	delete p;
}

// xóa cuối
void XoaCuoi(list_psh& l)
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
	for (node* k = l.phead; k != NULL; k = k->pnext)
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
void XoaNodeCoKhoaBatKy(list_psh& l, int x)
{
	danhso(l);
	// nếu danh sách rỗng thì không làm gì hết
	if (l.phead == NULL)
	{
		return;
	}
	// nếu node cần xóa nằm đầu danh sách
	if (l.phead->data.pos == x)
	{
		XoaDau(l);
		return;
	}
	// nếu node cần xóa nằm ở cuối danh sách
	if (l.ptail->data.pos == x)
	{
		XoaCuoi(l);
		return;
	}

	node* g = new node; // node g là node trỏ đến node nằm trước node cần xóa: x
	// duyệt danh sách liên kết đơn để tìm
	for (node* k = l.phead; k != NULL; k = k->pnext)
	{
		// phát hiện phần tử cần xóa
		if (k->data.pos == x)
		{
			g->pnext = k->pnext; // cập nhật mối liên kết giữa node k với node sau node h
			delete k; // xóa node nằm sau node k	
			return;
		}
		g = k; // cho node g trỏ đến node k
	}

}
void Readdate8_expm(ifstream& f, date8& d)
{
	f >> d.day;
	f.seekg(1, 1);
	f >> d.month;
	f.seekg(1, 1);
	f >> d.year;
	f.seekg(1, 1);
}
void read_1_infopsh(ifstream& f, psh& sv) {
	getline(f, sv.name, ','); f.seekg(1, 1); f>>sv.sex; f.seekg(2, 1);
	getline(f, sv.adress, ','); f.seekg(1, 1);
	f >> sv.id; f.seekg(2, 1);
	Readdate8_expm(f, sv.ngayki); f.seekg(1, 1);
	Readdate8_expm(f, sv.ngayhethan); f.seekg(1, 1);
	f >> sv.phone_number; f.seekg(2, 1);
	f >> sv.id_card; f.seekg(2, 1);
	Readdate8_expm(f, sv.brith); f.seekg(1, 1);
	f >> sv.vt;
}
void write_info_to_listpsh(ofstream& f, psh& t) {
	f << t.name << "," << " "; f << t.sex << " " << "," << " ";
	f << t.adress << "," << " "; f << t.id << " " << "," << " ";
	f << t.ngayki.day << "/" << t.ngayki.month << "/" << t.ngayki.year << "," << " ";
	f << t.ngayhethan.day << "/" << t.ngayhethan.month << "/" << t.ngayhethan.year << "," << " ";
	f << t.phone_number<< " " << "," << " "; f << t.id_card << " " << "," << " ";
	f << t.brith.day << "/" << t.brith.month << "/" << t.brith.year << "," << " ";
	f << t.vt;
}
void ReadFile_to_list_expm(ifstream& f, list_psh& l)
{
	while (!f.eof())  //read into endfile.
	{
		psh sv;
		read_1_infopsh(f, sv);
		node* p = create_node_psh(sv);
		add_node_psh_tail(l, p);
	}

}
bool search_by_name(list_psh l,string s) {
	for (node* k = l.phead; k != NULL; k = k->pnext) {
		if (k->data.name == s) return true; 
	}
	return false;
}
int len_8(list_psh l) {
	int count = 0;
	for (node* k = l.phead; k != NULL; k = k->pnext) {
		count++;
	}
	return count;
}
void LayNgayGioHT(date8& d)
{
	//    int ngay,thang,nam ;
	tm today;
	time_t ltime;
	time(&ltime);
	// today = localtime( &ltime );
	localtime_s(&today, &ltime);
	d.day = today.tm_mday;
	d.month = today.tm_mon + 1;
	d.year = today.tm_year + 1900;
}

/*int LayNamHT()
{
	tm today;
	time_t ltime;
	time(&ltime);
	// today = localtime( &ltime );
	localtime_s(&today, &ltime);
	return (today.tm_year + 1900);
}*/
int tinhNgay(date8 dt)
{
	if (dt.month < 3) {
		dt.year--;
		dt.month += 12;
	}
	return 365 * dt.year+ dt.year / 4 - dt.year / 10 + dt.year / 400 + (153 * dt.month - 457) / 5 + dt.day - 306;
}
int KhoangCachNgay(date8 nt1)
{
	date8 nt2;
	LayNgayGioHT(nt2);
	return (tinhNgay(nt2) - tinhNgay(nt1));
}

int SoSanhNgay(date8 nt1, date8 nt2)
{
	return (tinhNgay(nt2) - tinhNgay(nt1));
}
void edit_by_postion_8(list_psh&l,int x) {
	psh sv;
	danhso(l);	ifstream f; f.open("input_menu8.txt", ios::in);
	read_1_infopsh(f, sv);
	f.close();
	for (node* k = l.phead; k != NULL; k = k->pnext) {
		

		if (k->data.pos == x) {
			strcpy(k->data.id, sv.id);
			strcpy(k->data.sex, sv.sex);
			strcpy(k->data.phone_number, sv.phone_number);
			strcpy(k->data.id_card, sv.id_card);
			k->data.name = sv.name;
			k->data.ngayhethan = sv.ngayhethan;
			k->data.ngayki = sv.ngayki;
			k->data.adress = sv.adress;
			k->data.brith = sv.brith;
			}
	}
}