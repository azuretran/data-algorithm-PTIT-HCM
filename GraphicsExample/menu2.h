#pragma once
#include"graphics.h"
#include"HOMEPAGE_UI.h"
#include"menu8.h"
#include<string>

using namespace std;
const int MAX = 1e6;
void menu2();
namespace
{
	int cnt[MAX];

	struct phongtro {

		string fullname;
		string hometown;
		string job;
		string dantoc;
		string ngaysinh;
		string sex;
		string ton_giao;
		string p;
		string vip;

		string cmnd;
		int vt;
	}; typedef struct  phongtro pht;
	struct nodepht {
		pht data;
		struct nodepht* pnext;
	};
	struct listpht {
		nodepht* phead; nodepht* ptail;
	};
}
void create_listpht_pht(listpht& l) {
	l.phead = NULL;
	l.ptail = NULL;
}
nodepht* create_node_pht(pht x) {
	nodepht* p = new nodepht;
	p->data = x;
	p->pnext = NULL;
	return p;
}
void add_node_pht_tail(listpht& l, nodepht* p)
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
void add_node_pht_head(listpht& l, nodepht* p)
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
void danhso(listpht& l) {
	int dem = 1;
	for (nodepht* k = l.phead; k != NULL; k = k->pnext) {
		k->data.vt = dem; dem++;
	}
}
void ThemNode_p_VaoViTriBatKi(listpht& l, nodepht* p, int vt, int n)
{

	// danh sách đang rỗng
	if (l.phead == NULL || vt == 1)
	{
		// thêm node p vào đầu danh sách l
		add_node_pht_head(l, p);
	}
	else if (vt == n + 1)
	{
		// thêm node p vào cuối danh sách l
		add_node_pht_tail(l, p);
	}
	else // vt nằm trong đoạn [2, n]
	{
		int dem = 0; // xác định vt cần thêm
		// ============ CÁCH 2: TRONG DANH SÁCH TỒN TẠI TỪ 2 NODE Q TRỞ LÊN ============
		nodepht* g = new nodepht; // node g chính là node giữ liên kết với cái node nằm trước node q trong danh sách
		// duyệt danh sách từ đầu đến cuối để tìm node q <=> tìm ra cái vị trí vt cần thêm node p vào..
		for (nodepht* k = l.phead; k != NULL; k = k->pnext)
		{
			dem++;
			// tìm vị trí vt cần thêm
			if (dem == vt)
			{
				nodepht* h = create_node_pht(p->data); // mỗi lần phát hiện 1 node q thì ta khởi tạo 1 node p mới <=> khởi tạo node h
				// thực hiện bài toán thêm node p vào sau node g là ra vấn đề <=> thêm node p vào trước node q
				h->pnext = k; // Bước 1: cho node h trỏ(liên kết) đến node k <=> cũng chính là cho node h trỏ đến node q
				g->pnext = h; // Bước 2: cho node g trỏ đến node h 
				break;
			}
			g = k; // giữ liên kết với cái node nằm trước node q trong danh sách
		}
	}
}

void XoaDau(listpht& l)
{
	// nếu danh sách rỗng
	if (l.phead == NULL)
	{
		return;
	}
	nodepht* p = l.phead; // node p là node sẽ xóa

	l.phead = l.phead->pnext;// cập nhật lại l.pHead là phần tử kế tiếp
	delete p;
}

// xóa cuối
void XoaCuoi(listpht& l)
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
	for (nodepht* k = l.phead; k != NULL; k = k->pnext)
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
void XoaNodeCoKhoaBatKy(listpht& l, int x)
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

	nodepht* g = new nodepht; // node g là node trỏ đến node nằm trước node cần xóa: x
	// duyệt danh sách liên kết đơn để tìm
	for (nodepht* k = l.phead; k != NULL; k = k->pnext)
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
int len2(listpht l) {
	int count = 0;
	for (nodepht* k = l.phead; k != NULL; k = k->pnext) {
		count++;
	}
	return count;
}

void Read_1_pht(ifstream& f, pht& sv) {

	getline(f, sv.hometown, ','); f.seekg(1, 1);
	getline(f, sv.job, ','); f.seekg(1, 1);
	getline(f, sv.fullname, ','); f.seekg(1, 1);
	getline(f, sv.p, ','); f.seekg(1, 1);
	getline(f, sv.sex, ','); f.seekg(1, 1);
	getline(f, sv.dantoc, ','); f.seekg(1, 1);
	getline(f, sv.ton_giao, ','); f.seekg(1, 1);
	getline(f, sv.ngaysinh, ','); f.seekg(1, 1);
	getline(f, sv.vip, ','); f.seekg(1, 1);
	getline(f, sv.cmnd, ',');
	string temp;
	getline(f, temp);
}
void Read_1_pht_2(ifstream& f, pht& sv) {

	getline(f, sv.hometown, ','); f.seekg(1, 1);
	getline(f, sv.job, ','); f.seekg(1, 1);
	getline(f, sv.fullname, ','); f.seekg(1, 1);
	getline(f, sv.ton_giao, ','); f.seekg(1, 1);
	getline(f, sv.sex, ','); f.seekg(1, 1);
	getline(f, sv.dantoc, ','); f.seekg(1, 1);
	getline(f, sv.p, ','); f.seekg(1, 1);
	getline(f, sv.vip, ','); f.seekg(1, 1);
	getline(f, sv.ngaysinh, ','); f.seekg(1, 1);
	getline(f, sv.cmnd, ',');
	string temp;
	getline(f, temp);
}
void write_infoexpmpht(ofstream& f, pht& sv) {
	f << sv.hometown << ',' << " "; f << sv.job << ',' << " ";
	f << sv.fullname << ',' << " "; f << sv.p << ',' << " ";
	f << sv.sex << ',' << " "; f << sv.dantoc << ',' << " ";
	f << sv.ton_giao << ',' << " "; f << sv.ngaysinh << ',' << " ";
	f << sv.vip << ',' << " "; f << sv.cmnd << ',';
}
void save_file_pht(listpht l) {
	ofstream fi; fi.open("quanliphong_menu2.txt", ios::out);
	for (nodepht* k = l.phead; k != NULL; k = k->pnext)
	{
		write_infoexpmpht(fi, k->data);
		fi << endl;
	}
	fi.close();
}
void ReadFile_to_list_pht(ifstream& f, listpht& l)
{
	while (!f.eof())  //read into endfile.
	{
		pht sv;
		Read_1_pht(f, sv);
		nodepht* p = create_node_pht(sv);
		add_node_pht_tail(l, p);
	}

}
void hoanvi_1(pht& a, pht& b)
{
	pht t = a; a = b; b = t;
}
void sort_by_room(listpht&l)
{
	for (nodepht* p = l.phead; p; p = p->pnext)
		for (nodepht* q = p->pnext; q; q = q->pnext)
		{
			int m= atoi(p->data.ton_giao.c_str());
			int n = atoi(q->data.ton_giao.c_str());
			if(m>n) hoanvi_1(p->data, q->data);
		}
}
nodepht* search(listpht l, int x) {
	for (nodepht* k = l.phead; k != NULL; k = k->pnext) {
		if (k->data.vt == x) return k;
	}
	return NULL;
}
void SaveFile_Backup(listpht& l) {
	ofstream fi;
	fi.open("back_up.txt", ios::app);
	fi << "," << endl;
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
void edit_by_postion_2(listpht& l, int x) {
	pht sv;
	danhso(l);
	ifstream f; f.open("input_menu8.txt", ios::in);
	Read_1_pht_2(f, sv);
	f.close();
	for (nodepht* k = l.phead; k != NULL; k = k->pnext) {
		if (k->data.vt == x) {
			k->data.fullname = sv.fullname;
			k->data.hometown = sv.hometown;
			k->data.job = sv.job;
			k->data.dantoc = sv.dantoc;
			k->data.ngaysinh = sv.ngaysinh;
			k->data.sex = sv.sex;
			k->data.ton_giao = sv.ton_giao;
			k->data.p = sv.p; k->data.vip = sv.vip;
			k->data.cmnd = sv.cmnd;

		}
	}
}