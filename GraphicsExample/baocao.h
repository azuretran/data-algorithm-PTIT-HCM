#pragma once
#include"graphics.h"
#include<fstream>
#include<sstream>
#include"menu3.h"
#include"pay_money_service.h"
#include"menu1.h"
using namespace std;
namespace {
	struct  dien_nuoc {
		int dien;
		int nuoc;
		int month;
	}; typedef struct dien_nuoc dn;
	struct nodedn {
		dn data;
		struct nodedn* pnext;
	};
	struct list_dn {
		nodedn* phead; nodedn* ptail;
	};
}
void create_list_dn_dn(list_dn& l) {
	l.phead = NULL;
	l.ptail = NULL;
}
nodedn* create_nodedn_dn(dn x) {
	nodedn* p = new nodedn;
	p->data = x;
	p->pnext = NULL;
	return p;
}
void add_nodedn_dn_tail(list_dn& l, nodedn* p)
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
void add_nodedn_dn_head(list_dn& l, nodedn* p)
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

void Themnodedn_p_VaoViTriBatKi(list_dn& l, nodedn* p, int vt, int n)
{

	// danh sách đang rỗng
	if (l.phead == NULL || vt == 1)
	{
		// thêm nodedn p vào đầu danh sách l
		add_nodedn_dn_head(l, p);
	}
	else if (vt == n + 1)
	{
		// thêm nodedn p vào cuối danh sách l
		add_nodedn_dn_tail(l, p);
	}
	else // vt nằm trong đoạn [2, n]
	{
		int dem = 0; // xác định vt cần thêm
		// ============ CÁCH 2: TRONG DANH SÁCH TỒN TẠI TỪ 2 nodedn Q TRỞ LÊN ============
		nodedn* g = new nodedn; // nodedn g chính là nodedn giữ liên kết với cái nodedn nằm trước nodedn q trong danh sách
		// duyệt danh sách từ đầu đến cuối để tìm nodedn q <=> tìm ra cái vị trí vt cần thêm nodedn p vào..
		for (nodedn* k = l.phead; k != NULL; k = k->pnext)
		{
			dem++;
			// tìm vị trí vt cần thêm
			if (dem == vt)
			{
				nodedn* h = create_nodedn_dn(p->data); // mỗi lần phát hiện 1 nodedn q thì ta khởi tạo 1 nodedn p mới <=> khởi tạo nodedn h
				// thực hiện bài toán thêm nodedn p vào sau nodedn g là ra vấn đề <=> thêm nodedn p vào trước nodedn q
				h->pnext = k; // Bước 1: cho nodedn h trỏ(liên kết) đến nodedn k <=> cũng chính là cho nodedn h trỏ đến nodedn q
				g->pnext = h; // Bước 2: cho nodedn g trỏ đến nodedn h 
				break;
			}
			g = k; // giữ liên kết với cái nodedn nằm trước nodedn q trong danh sách
		}
	}
}
void XoaDau(list_dn& l)
{
	// nếu danh sách rỗng
	if (l.phead == NULL)
	{
		return;
	}
	nodedn* p = l.phead; // nodedn p là nodedn sẽ xóa
	l.phead = l.phead->pnext;// cập nhật lại l.pHead là phần tử kế tiếp
	delete p;
}

// xóa cuối
void XoaCuoi(list_dn& l)
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
	for (nodedn* k = l.phead; k != NULL; k = k->pnext)
	{
		// phát hiện thằng kế cuối
		if (k->pnext == l.ptail)
		{
			delete l.ptail; // xóa đi phần tử cuối
			k->pnext = NULL; // cho con trỏ của nodedn kế cuối trỏ đến vùng nhớ null
			l.ptail = k; // cập nhật lại l.pTail
			return;
		}
	}
}
void XoanodednCoKhoaBatKy(list_dn& l, int x)
{
	// nếu danh sách rỗng thì không làm gì hết
	if (l.phead == NULL)
	{
		return;
	}
	// nếu nodedn cần xóa nằm đầu danh sách
	if (l.phead->data.month == x)
	{
		XoaDau(l);
		return;
	}
	// nếu nodedn cần xóa nằm ở cuối danh sách
	if (l.ptail->data.month == x)
	{
		XoaCuoi(l);
		return;
	}

	nodedn* g = new nodedn; // nodedn g là nodedn trỏ đến nodedn nằm trước nodedn cần xóa: x
	// duyệt danh sách liên kết đơn để tìm
	for (nodedn* k = l.phead; k != NULL; k = k->pnext)
	{
		// phát hiện phần tử cần xóa
		if (k->data.month == x)
		{
			g->pnext = k->pnext; // cập nhật mối liên kết giữa nodedn k với nodedn sau nodedn h
			delete k; // xóa nodedn nằm sau nodedn k	
			return;
		}
		g = k; // cho nodedn g trỏ đến nodedn k
	}

}
void read_baocao(ifstream&f, dn& sv) {
	f >> sv.dien; f.seekg(1, 1); f >> sv.nuoc; f.seekg(1, 1); f >> sv.month;

}
void write_info(ofstream& f, dn& sv) {
	f << sv.dien << "," << " ";
	f << sv.nuoc << "," << " ";
	f << sv.month;
}

void hoanvi_r(dn& a, dn& b)
{
	dn t = a; a = b; b = t;
}
void sort_by_month(list_dn& l) {
	for (nodedn* p = l.phead; p; p = p->pnext)
		for (nodedn* q = p->pnext; q; q = q->pnext)
		
			if (p->data.month > q->data.month) hoanvi_r(p->data, q->data);
		
}

void main_menu_report();