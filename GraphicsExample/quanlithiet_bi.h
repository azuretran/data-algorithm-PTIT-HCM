#pragma once
#include"graphics.h"
#include"Longin_user.h"
#include"HOMEPAGE_UI.h"
#include<fstream>
using namespace std;
namespace {
	struct thietbi {
		int vt;
		int p;
		string nametb;
		char costtb[50];
		char sl[50];
		string state;
		char day_check[50];
		string note;
	}; typedef struct thietbi tbi;
	struct nodetbi
	{
		tbi data;
		struct nodetbi* pnext;
	};
	struct list_tbi {
		nodetbi* phead;
		nodetbi* ptail;

	};
}
void create_list_tbi_tbi(list_tbi& l) {
	l.phead = NULL;
	l.ptail = NULL;
}
nodetbi* create_node_tbi(tbi x) {
	nodetbi* p = new nodetbi;
	p->data = x;
	p->pnext = NULL;
	return p;
}
void add_node_tbi_tail(list_tbi& l, nodetbi* p)
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
void add_node_tbi_head(list_tbi& l, nodetbi* p)
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
void danhso(list_tbi& l) {
	int dem = 1;
	for (nodetbi* k = l.phead; k != NULL; k = k->pnext) {
		k->data.vt = dem; dem++;
	}
}
void ThemNode_p_VaoViTriBatKi(list_tbi& l, nodetbi* p, int vt, int n)
{
	danhso(l);
	// danh sách đang rỗng
	if (l.phead == NULL || vt == 1)
	{
		// thêm node p vào đầu danh sách l
		add_node_tbi_head(l, p);
	}
	else if (vt == n + 1)
	{
		// thêm node p vào cuối danh sách l
		add_node_tbi_tail(l, p);
	}
	else // vt nằm trong đoạn [2, n]
	{
		int dem = 0; // xác định vt cần thêm
		// ============ CÁCH 2: TRONG DANH SÁCH TỒN TẠI TỪ 2 NODE Q TRỞ LÊN ============
		nodetbi* g = new nodetbi; // node g chính là node giữ liên kết với cái node nằm trước node q trong danh sách
		// duyệt danh sách từ đầu đến cuối để tìm node q <=> tìm ra cái vị trí vt cần thêm node p vào..
		for (nodetbi* k = l.phead; k != NULL; k = k->pnext)
		{
			dem++;
			// tìm vị trí vt cần thêm
			if (dem == vt)
			{
				nodetbi* h = create_node_tbi(p->data); // mỗi lần phát hiện 1 node q thì ta khởi tạo 1 node p mới <=> khởi tạo node h
				// thực hiện bài toán thêm node p vào sau node g là ra vấn đề <=> thêm node p vào trước node q
				h->pnext = k; // Bước 1: cho node h trỏ(liên kết) đến node k <=> cũng chính là cho node h trỏ đến node q
				g->pnext = h; // Bước 2: cho node g trỏ đến node h 
				break;
			}
			g = k; // giữ liên kết với cái node nằm trước node q trong danh sách
		}
	}
}
void XoaDau(list_tbi& l)
{
	// nếu danh sách rỗng
	if (l.phead == NULL)
	{
		return;
	}
	nodetbi* p = l.phead; // node p là node sẽ xóa
	l.phead = l.phead->pnext;// cập nhật lại l.pHead là phần tử kế tiếp
	delete p;
}

// xóa cuối
void XoaCuoi(list_tbi& l)
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
	for (nodetbi* k = l.phead; k != NULL; k = k->pnext)
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
void XoaNodeCoKhoaBatKy(list_tbi& l, int x)
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

	nodetbi* g = new nodetbi; // node g là node trỏ đến node nằm trước node cần xóa: x
	// duyệt danh sách liên kết đơn để tìm
	for (nodetbi* k = l.phead; k != NULL; k = k->pnext)
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
int len2(list_tbi l) {
	int count = 0;
	for (nodetbi* k = l.phead; k != NULL; k = k->pnext) {
		count++;
	}
	return count;
}
void Read_1_dbi(ifstream& f, tbi& sv) {
	getline(f, sv.nametb, ',');
	f.seekg(1, 1); getline(f, sv.note, ',');
	f.seekg(1, 1);
	getline(f, sv.state, ',');
	f.seekg(1, 1);
	f >> sv.costtb; f.seekg(2, 1);
	f >> sv.sl; f.seekg(2, 1);
	f >> sv.day_check; f.seekg(2, 1);
	f >> sv.p;
}void ReadFile_to_list_dbi(ifstream& f, list_tbi& l)
{
	while (!f.eof())  //read into endfile.
	{
		tbi sv;
		Read_1_dbi(f, sv);
		nodetbi* p = create_node_tbi(sv);
		add_node_tbi_tail(l, p);
	}

}
void write_infoexpmtbi(ofstream& f, tbi& sv) {
	f << sv.nametb << "," << " ";
	f << sv.note << "," << " ";
	f << sv.state << "," << " ";
	f << sv.costtb << " " << "," << " ";
	f << sv.sl << " " << "," << " ";
	f << sv.day_check << " " << "," << " ";
	f << sv.p;
}
void save_file_pht_dtbi(list_tbi l) {
	ofstream fi; fi.open("quanli_thietbi.txt", ios::out);
	for (nodetbi* k = l.phead; k != NULL; k = k->pnext)
	{
		fi << endl;
		write_infoexpmtbi(fi, k->data);
	
	}
	fi.close();
}
void edit_by_postion_tbi(list_tbi l, int x) {
	danhso(l);
	tbi sv;
	ifstream f; f.open("input_menu8.txt", ios::in);
	Read_1_dbi(f, sv); f.close();
	for (nodetbi* k = l.phead; k != NULL; k = k->pnext) {
		if (k->data.vt == x) {
			k->data.nametb = sv.nametb;
			k->data.note = sv.note;
			k->data.state = sv.state;
			strcpy(k->data.costtb, sv.costtb);
			strcpy(k->data.sl, sv.sl);
			strcpy(k->data.day_check, sv.day_check);
			k->data.p = sv.p;
		}
	}
}
void hoanviqq(tbi& a, tbi& b)
{
	tbi t = a; a = b; b = t;
}
void sort_by_ros(list_tbi& l)
{
	for (nodetbi* p = l.phead; p; p = p->pnext)
		for (nodetbi* q = p->pnext; q; q = q->pnext)
			if (p->data.p > q->data.p)
				hoanviqq(p->data, q->data);
}

void main_menu_thietbi();