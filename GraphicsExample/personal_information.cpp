#include"personal_infomartion.h"
void CreateList(ListSV& l) {                        //Khoi tao slist sinh vien
	l.pHead = NULL;
	l.pTail = NULL;
}
Node* CreateNode(SinhVien x) {                    //Tao node
	Node* p = new Node;
	if (p == NULL)
		cout << "Cap phat bo nho that bai! ";
	else {
		p->data = x;
		p->pNext = NULL;
	}
	return p;
}
void AddTail(ListSV& l, Node* p)
{

	if (l.pHead == NULL)            //neu list rong thi p la nut dau
		l.pHead = l.pTail = p;
	else
	{
		l.pTail->pNext = p;
		l.pTail = p;
	}
}

void Read_1_SV(ifstream& f, SinhVien& sv) {


	
	getline(f, sv.Ten, ',');
	f.seekg(1, 1);
	getline(f, sv.SDT, ',');
	f.seekg(1, 1);
	f >> sv.MaPhong;
	f.seekg(1, 1);
	f >> sv.come_day;
	f.seekg(1, 1);
	f >> sv.pay;
	f.seekg(1, 1);
	f >> sv.Ho;
	f.seekg(1, 1);
	string tmp;
	getline(f, tmp);


}
void XuatSv(SinhVien sv)
{

	cout << "\n\tHo va Ten:" << sv.Ho << " " << sv.Ten;

	cout << "\n\tSDT: " << sv.SDT;

	cout << "\n\tMa phong: " << sv.MaPhong << "\n";
}
void XuatAllSV(ListSV l)
{

	int dem = 1;
	for (Node* k = l.pHead; k != NULL; k = k->pNext)
	{
		cout << "Sinh Vien Thu " << dem++;
		XuatSv(k->data);
	}
	cout << endl;
}
void ReadFile_to_list(ifstream& f, ListSV& l)
{
	while (!f.eof())  //read into endfile.
	{
		SinhVien sv;
		Read_1_SV(f, sv);
		Node* p = CreateNode(sv);
		AddTail(l, p);

	}

}

/*
void AddUser(ListSV& tmp)           //them thong tin nguoi tro
{
	SinhVien sv;
	cout << "Nhap Ho: ";
	cin >> ws;
	getline(cin, sv.Ho);
	while (KTTen(sv.Ho) == 0)
	{
		cout << "Nhap H khong hop le! ";
		cout << "Nhap Ho: ";
		cin >> ws;
		getline(cin, sv.Ho);
	}
	cout << "Nhap Ten: ";
	cin >> ws;
	getline(cin, sv.Ten);
	while (KTTen(sv.Ten) == 0)
	{
		cout << "Nhap ten khong hop le! ";
		cout << "Nhap Ten: ";
		cin >> ws;
		getline(cin, sv.Ho);
	}
	cout << "Nhap SDT: ";
	getline(cin, sv.SDT);


	cout << "Nhap ma phong: ";
	cin >> sv.MaPhong;
	Node* p = CreateNode(sv);

	AddTail(tmp, p);

	SaveFile(tmp);

}

void SaveFile(ListSV& l)
{
	ofstream f2;
	f2.open("data.txt", ios::app);
	for (Node* k = l.pHead; k != NULL; k = k->pNext)
	{
		f2 << endl << k->data.Ho << ", " << k->data.Ten << ", " << ", " << k->data.SDT << ", " << k->data.MaPhong;
	}


	f2.close();
}
void ReadData(ListSV& l)
{
	ifstream  f;
	f.open("data.txt", ios::in);
	if (f.fail())                     //neu mo file that bai
		cout << "Error FIle! " << endl;
	ReadFile_to_list(f, l);           // doc du lieu tu file vao dslk don
	f.close();
}
void XuatTheoMaPhong(ListSV l)
{
	int s;
	cout << "\nThong ke Nguoi o theo ma phong! ";
	cout << "\nNhap ma phong ban muon thong ke! ";

	cin >> s;
	for (Node* k = l.pHead; k != NULL; k = k->pNext)
	{
		if (k->data.MaPhong == s)
		{
			XuatSv(k->data);
		}

	}
}

void Selection_Sort_ID_Room(ListSV l)
{
	Node* p, * q, * min;
	p = l.pHead;
	SinhVien temp;
	while (p != l.pTail)
	{
		min = p;
		q = p->pNext;
		while (q != NULL)
		{
			if (q->data.MaPhong < min->data.MaPhong)
				min = q;
			q = q->pNext;
		}
		temp = p->data;
		p->data = min->data;
		min->data = temp;
		p = p->pNext;
	}
}
void InterChange_Sort(ListSV& l)
{
	Node* p, * q, * min;
	p = l.pHead;
	SinhVien temp;
	while (p != l.pTail)
	{
		q = p->pNext;
		while (q != NULL)
		{
			if (q->data.Ten < p->data.Ten) //sap xep tang dan theo ten
			{
				temp = p->data;
				p->data = q->data;
				q->data = temp;
			}
			if (q->data.Ten == p->data.Ten) //neu ten trung
			{
				if (q->data.Ho < p->data.Ho) //thi sap theo ho
				{
					temp = p->data;
					p->data = q->data;
					q->data = temp;
				}
			}
			q = q->pNext;
		}
		p = p->pNext;
	}
}
void OutputAllSV(ListSV l)
{
	ofstream fout;
	fout.open("outputAllSv.txt", ios::out);
	for (Node* k = l.pHead; k != NULL; k = k->pNext)
	{
		fout << endl << k->data.Ho << ", " << k->data.Ten << ", " << k->data.SDT << ", " << k->data.MaPhong;
	}
}
void ReadOutput(ListSV l)
{

}
void Menu(ListSV l)
{
	int opt;
	while (true)
	{
		do
		{

			system("cls");
			cout << "\n\t\tQUAN LI NGUOI TRO! ";
			cout << "\n\n\t\t============= Menu ============";
			cout << "\n\t1. THEM NGUOI TRO ";
			cout << "\n\t2. XEM TAT CA THONG TIN NGUOI TRO ";
			cout << "\n\t3. XUAT THONG TIN NGUOI TRO THEO MA PHONG";
			cout << "\n\t6. SAP XEP SINH VIEN TANG DAN THEO SO PHONG ";
			cout << "\n\t7. SORT BY NAME ";
			cout << "\n\t0. Cancle";
			cout << "\n\n\t\t========== The-End ===========";
			cout << " Your option: ";
			cin >> opt;
			if (opt < 0)
				cout << "vui long nhap lai lua chon: ";
		} while (opt < 0 | opt>7);
		if (opt == 1)
		{
			ListSV tmp;

			CreateList(tmp);

			AddUser(tmp);
		}
		if (opt == 2)
		{
			ReadData(l);

			OutputAllSV(l); //save data into file
			//ReadOutput(l);
			system("pause");
			l.pHead = l.pTail = NULL;

		}
		if (opt == 3) {
			ReadData(l);
			XuatTheoMaPhong(l);
			system("pause");
			l.pHead = l.pTail = NULL; // Giai phong du lieu cua list
		}


		if (opt == 6)
		{
			ReadData(l);
			Selection_Sort_ID_Room(l);
			XuatAllSV(l);
			system("pause");
		}
		if (opt == 7)
		{
			ReadData(l);
			InterChange_Sort(l);
			XuatAllSV(l);
			system("pause");
		}
	}

}*/