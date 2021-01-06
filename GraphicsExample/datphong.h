#pragma once
#include"graphics.h"
#include"HOMEPAGE_UI.h"
#include<iostream>
#include<fstream>
#include"Longin_user.h"
using namespace std;
namespace {
	struct date9 {
		int ngay,thang,nam;
	};
	struct datphong {
		string name;
		string adress;
		string note;
		char std[15];
		char tiencoc[50];
		char ngaydat[50];
		char ngayvao[50];
		int lphong;
		int state;
		char tenphong[50];
		int vt;

	}; typedef struct datphong dtp;
	struct nodedtp {
		dtp data;
		struct nodedtp* pnext;
	};
	struct listdtp {
		nodedtp* phead;
		nodedtp* ptail;
	};
}
void create_listdtp_dtp(listdtp& l) {
	l.phead = NULL;
	l.ptail = NULL;
}
nodedtp* create_node_dtp(dtp x) {
	nodedtp* p = new nodedtp;
	p->data = x;
	p->pnext = NULL;
	return p;
}
void add_node_dtp_tail(listdtp& l, nodedtp* p)
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
void add_node_dtp_head(listdtp& l, nodedtp* p)
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
void danhso(listdtp& l) {
	int dem = 1;
	for (nodedtp* k = l.phead; k != NULL; k = k->pnext) {
		k->data.vt = dem; dem++;
	}
}
void ThemNode_p_VaoViTriBatKi(listdtp& l, nodedtp* p, int vt, int n)
{

	// danh sách đang rỗng
	if (l.phead == NULL || vt == 1)
	{
		// thêm node p vào đầu danh sách l
		add_node_dtp_head(l, p);
	}
	else if (vt == n + 1)
	{
		// thêm node p vào cuối danh sách l
		add_node_dtp_tail(l, p);
	}
	else // vt nằm trong đoạn [2, n]
	{
		int dem = 0; // xác định vt cần thêm
		// ============ CÁCH 2: TRONG DANH SÁCH TỒN TẠI TỪ 2 NODE Q TRỞ LÊN ============
		nodedtp* g = new nodedtp; // node g chính là node giữ liên kết với cái node nằm trước node q trong danh sách
		// duyệt danh sách từ đầu đến cuối để tìm node q <=> tìm ra cái vị trí vt cần thêm node p vào..
		for (nodedtp* k = l.phead; k != NULL; k = k->pnext)
		{
			dem++;
			// tìm vị trí vt cần thêm
			if (dem == vt)
			{
				nodedtp* h = create_node_dtp(p->data); // mỗi lần phát hiện 1 node q thì ta khởi tạo 1 node p mới <=> khởi tạo node h
				// thực hiện bài toán thêm node p vào sau node g là ra vấn đề <=> thêm node p vào trước node q
				h->pnext = k; // Bước 1: cho node h trỏ(liên kết) đến node k <=> cũng chính là cho node h trỏ đến node q
				g->pnext = h; // Bước 2: cho node g trỏ đến node h 
				break;
			}
			g = k; // giữ liên kết với cái node nằm trước node q trong danh sách
		}
	}
}
void XoaDau(listdtp& l)
{
	// nếu danh sách rỗng
	if (l.phead == NULL)
	{
		return;
	}
	nodedtp* p = l.phead; // node p là node sẽ xóa
	l.phead = l.phead->pnext;// cập nhật lại l.pHead là phần tử kế tiếp
	delete p;
}

// xóa cuối
void XoaCuoi(listdtp& l)
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
	for (nodedtp* k = l.phead; k != NULL; k = k->pnext)
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
void XoaNodeCoKhoaBatKy(listdtp& l, int x)
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

	nodedtp* g = new nodedtp; // node g là node trỏ đến node nằm trước node cần xóa: x
	// duyệt danh sách liên kết đơn để tìm
	for (nodedtp* k = l.phead; k != NULL; k = k->pnext)
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
int len2(listdtp l) {
	int count = 0;
	for (nodedtp* k = l.phead; k != NULL; k = k->pnext) {
		count++;
	}
	return count;
}
/*void Readdatedatphong_expm(ifstream& f, date9& d)
{
	f >> d.day;
	f.seekg(1, 1);
	f >> d.month;
	f.seekg(1, 1);
	f >> d.year;
	f.seekg(1, 1);
}*/
void Read_1_dpt(ifstream& f, dtp& sv) {
	getline(f, sv.name, ',');
	f.seekg(1, 1);
	getline(f, sv.adress, ',');
	f.seekg(1, 1);
	getline(f, sv.note, ','); f.seekg(1, 1);
	f >> sv.std; f.seekg(2, 1);
	f >> sv.tiencoc; f.seekg(2, 1);
	f >> sv.ngaydat; f.seekg(2, 1);
	f >> sv.ngayvao; f.seekg(2, 1);
	f >> sv.lphong; f.seekg(1, 1);
	f >> sv.state; f.seekg(1, 1);
	f >> sv.tenphong;
	string temp;
	getline(f, temp);
}

void ReadFile_to_list_pht(ifstream& f, listdtp& l)
{
	while (!f.eof())  //read into endfile.
	{
		dtp sv;
		Read_1_dpt(f, sv);
		nodedtp* p = create_node_dtp(sv);
		add_node_dtp_tail(l, p);
	}

}
void write_infoexpmdpt(ofstream& f,dtp& sv) {
	f << sv.name << "," << " ";
	f << sv.adress << "," << " ";
	f << sv.note << ", " << " ";
	f << sv.std << " " << "," << " "; f << sv.tiencoc << " " << "," << " ";
	f << sv.ngaydat << " " << "," << " ";
	f << sv.ngayvao << " " << "," << " ";
	f << sv.lphong << "," << " ";	f << sv.state << "," << " ";	f << sv.tenphong;
}
void save_file_pht_dpt(listdtp l) {
	ofstream fi; fi.open("datphong.txt", ios::out);
	for (nodedtp* k = l.phead; k != NULL; k = k->pnext)
	{
		fi << endl;
		write_infoexpmdpt(fi, k->data);
		
	}
	fi.close();
}
void edit_by_postion(listdtp l, int x) {
	danhso(l);
	dtp sv;
	ifstream f; f.open("input_menu8.txt", ios::in);
	Read_1_dpt(f, sv);
	for (nodedtp* k = l.phead; k != NULL; k = k->pnext) {
		if (k->data.vt == x) {
			 k->data.name = sv.name;
			 k->data.adress = sv.adress;
			 k->data.adress = k->data.adress;
			 k->data.note = sv.note;
			strcpy(k->data.std, sv.std);
			strcpy(k->data.tiencoc, sv.tiencoc);
			strcpy(k->data.ngaydat, sv.ngaydat);
			strcpy(k->data.ngayvao, sv.ngayvao);
			strcpy(k->data.tenphong, sv.tenphong);
			k->data.lphong = sv.lphong;
			k->data.state = sv.state;
			
		}
	}
}
void hoanviqqe(dtp& a, dtp& b)
{
	dtp t = a; a = b; b = t;
}
void sapxep(listdtp& l)
{
	for (nodedtp* p = l.phead; p; p = p->pnext)
		for (nodedtp* q = p->pnext; q; q = q->pnext) {
			string m = p->data.tenphong;
			string n = q->data.tenphong;
			int m1 = atoi(m.c_str());
			int n2 = atoi(n.c_str());
			if (m1 > n2) hoanviqqe(p->data, q->data);
		}
}

void main_menu_hopdong();