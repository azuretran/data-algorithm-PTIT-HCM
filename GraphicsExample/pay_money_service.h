#pragma once
#include"graphics.h"
#include<fstream>
#include"HOMEPAGE_UI.h"
#include"Longin_user.h"
using namespace std;
void menu_chinh_4();
namespace {
	struct paymoney {
		int tenphong;
		int month;
		int dsocu;
		int dsomoi;
		int nsocu;
		int nsomoi;
		int slxe;
		int tiencoc;
		int dathu;
		int nocu;
		
		int vt;
		string note;
	}; typedef struct paymoney pmn;
	struct dongia {
		int dien;
		int nuoc;
		int nuoc_1_nguoi;
		int quanlixe;
		int vesinh;
		int thcap;
		int internet;
		int tienphong;
	}; typedef struct dongia dg;
	struct nodepmn {
		pmn data;
		struct nodepmn* pnext;
	}; typedef struct nodepmn nodepmn;
	struct list_pmn {
		nodepmn* phead; nodepmn* ptail;
	};

}
void create_list_pmn_pmn(list_pmn& l) {
	l.phead = NULL;
	l.ptail = NULL;
}
nodepmn* create_nodepmn_pmn(pmn x) {
	nodepmn* p = new nodepmn;
	p->data = x;
	p->pnext = NULL;
	return p;
}
void add_nodepmn_pmn_tail(list_pmn& l, nodepmn* p)
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
void add_nodepmn_pmn_head(list_pmn& l, nodepmn* p)
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
int danhso(list_pmn& l) {
	int dem = 1;
	for (nodepmn* k = l.phead; k != NULL; k = k->pnext) {
		k->data.vt = dem; dem++;
	}
	return dem;
}
void Themnodepmn_p_VaoViTriBatKi(list_pmn& l, nodepmn* p, int vt, int n)
{

	// danh sách đang rỗng
	if (l.phead == NULL || vt == 1)
	{
		// thêm nodepmn p vào đầu danh sách l
		add_nodepmn_pmn_head(l, p);
	}
	else if (vt == n + 1)
	{
		// thêm nodepmn p vào cuối danh sách l
		add_nodepmn_pmn_tail(l, p);
	}
	else // vt nằm trong đoạn [2, n]
	{
		int dem = 0; // xác định vt cần thêm
		// ============ CÁCH 2: TRONG DANH SÁCH TỒN TẠI TỪ 2 nodepmn Q TRỞ LÊN ============
		nodepmn* g = new nodepmn; // nodepmn g chính là nodepmn giữ liên kết với cái nodepmn nằm trước nodepmn q trong danh sách
		// duyệt danh sách từ đầu đến cuối để tìm nodepmn q <=> tìm ra cái vị trí vt cần thêm nodepmn p vào..
		for (nodepmn* k = l.phead; k != NULL; k = k->pnext)
		{
			dem++;
			// tìm vị trí vt cần thêm
			if (dem == vt)
			{
				nodepmn* h = create_nodepmn_pmn(p->data); // mỗi lần phát hiện 1 nodepmn q thì ta khởi tạo 1 nodepmn p mới <=> khởi tạo nodepmn h
				// thực hiện bài toán thêm nodepmn p vào sau nodepmn g là ra vấn đề <=> thêm nodepmn p vào trước nodepmn q
				h->pnext = k; // Bước 1: cho nodepmn h trỏ(liên kết) đến nodepmn k <=> cũng chính là cho nodepmn h trỏ đến nodepmn q
				g->pnext = h; // Bước 2: cho nodepmn g trỏ đến nodepmn h 
				break;
			}
			g = k; // giữ liên kết với cái nodepmn nằm trước nodepmn q trong danh sách
		}
	}
}
void XoaDau(list_pmn& l)
{
	// nếu danh sách rỗng
	if (l.phead == NULL)
	{
		return;
	}
	nodepmn* p = l.phead; // nodepmn p là nodepmn sẽ xóa
	l.phead = l.phead->pnext;// cập nhật lại l.pHead là phần tử kế tiếp
	delete p;
}

// xóa cuối
void XoaCuoi(list_pmn& l)
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
	for (nodepmn* k = l.phead; k != NULL; k = k->pnext)
	{
		// phát hiện thằng kế cuối
		if (k->pnext == l.ptail)
		{
			delete l.ptail; // xóa đi phần tử cuối
			k->pnext = NULL; // cho con trỏ của nodepmn kế cuối trỏ đến vùng nhớ null
			l.ptail = k; // cập nhật lại l.pTail
			return;
		}
	}
}
void XoanodepmnCoKhoaBatKy(list_pmn& l, int x)
{
	danhso(l);
	// nếu danh sách rỗng thì không làm gì hết
	if (l.phead == NULL)
	{
		return;
	}
	// nếu nodepmn cần xóa nằm đầu danh sách
	if (l.phead->data.vt == x)
	{
		XoaDau(l);
		return;
	}
	// nếu nodepmn cần xóa nằm ở cuối danh sách
	if (l.ptail->data.vt == x)
	{
		XoaCuoi(l);
		return;
	}

	nodepmn* g = new nodepmn; // nodepmn g là nodepmn trỏ đến nodepmn nằm trước nodepmn cần xóa: x
	// duyệt danh sách liên kết đơn để tìm
	for (nodepmn* k = l.phead; k != NULL; k = k->pnext)
	{
		// phát hiện phần tử cần xóa
		if (k->data.vt == x)
		{
			g->pnext = k->pnext; // cập nhật mối liên kết giữa nodepmn k với nodepmn sau nodepmn h
			delete k; // xóa nodepmn nằm sau nodepmn k	
			return;
		}
		g = k; // cho nodepmn g trỏ đến nodepmn k
	}

}
int len2(list_pmn l) {
	int count = 0;
	for (nodepmn* k = l.phead; k != NULL; k = k->pnext) {
		count++;
	}
	return count;
}
void read_data_pay_money(ifstream& f, pmn&sv) {
	getline(f, sv.note, ','); f.seekg(1, 1);
	f >>sv.tenphong; 
	f.seekg(1, 1); f >> sv.month; f.seekg(1, 1);
	f >> sv.dsocu; f.seekg(1, 1);
	f >> sv.dsomoi; f.seekg(1, 1);
	f >> sv.nsocu; f.seekg(1, 1);
	f >> sv.nsomoi; f.seekg(1, 1);
	f >> sv.slxe; f.seekg(1, 1);
	f >> sv.tiencoc; f.seekg(1, 1);
	f >> sv.nocu; f.seekg(1, 1);
	f >> sv.dathu; f.seekg(1, 1);
	string temp;
	getline(f, temp);
}
void write_list_pmn(ofstream& f, pmn& sv) {
	f << sv.note << "," << " "; f << sv.tenphong << "," << " ";
	f << sv.month << "," << " "; f << sv.dsocu << "," << " "; f << sv.dsomoi << "," << " ";
	f << sv.nsocu << "," << " "; f << sv.nsomoi << "," << " "; f << sv.slxe << "," << " ";
	f << sv.tiencoc << "," << " "; f << sv.nocu << "," << " ";
	f << sv.dathu;
}
void save_file_pmn(list_pmn l) {
	ofstream fi; fi.open("paymoney_service.txt", ios::out);

	for (nodepmn* k = l.phead; k != NULL; k = k->pnext)
	{
		fi << endl;
		write_list_pmn(fi, k->data);
		
	}
	fi.close();
}
void edit_by_vt(list_pmn& l,int x) {
	danhso(l);
	pmn sv;
	ifstream f; f.open("input_menu8.txt", ios::in);
	read_data_pay_money(f, sv); f.close();
	for (nodepmn* k = l.phead; k != NULL; k = k->pnext) {
		if (k->data.vt == x) {
			k->data.note = sv.note;
			k->data.tenphong = sv.tenphong;
			k->data.month = sv.month;
			k->data.dsocu = sv.dsocu; k->data.dsomoi = sv.dsomoi;
			k->data.nsocu = sv.nsocu; k->data.nsomoi = sv.nsomoi;
			k->data.slxe = sv.slxe; k->data.tiencoc = sv.tiencoc;
			k->data.nocu = sv.nocu; k->data.dathu = sv.dathu;
		}
	}
}
void hoanvie(pmn& a, pmn& b)
{
	pmn t = a; a = b; b = t;
}
void sort_by_room(list_pmn& l) {
	for (nodepmn* p = l.phead; p; p = p->pnext)
		for (nodepmn* q = p->pnext; q; q = q->pnext)
		{
			if (p->data.tenphong > q->data.tenphong)
				hoanvie(p->data, q->data);
		}
}