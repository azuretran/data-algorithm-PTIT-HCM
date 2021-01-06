#include"baocao.h"
#include"HOMEPAGE_UI.h"
void draw_main_table_focus() {
	setfillstyle(1, blue_d); setcolor(YELLOW); rectangle(0, 40, 1520, 65);

	bar(0, 40, 1520, 65);
	int i = 90;
//	setfillstyle(1, Seashell1); 
	setcolor(green);
	for (int i = 90; i < 390; i += 23) {
		line(0, i, 1520, i);
		//bar(0, i + 25, 1520, i);
	}
	line(40, 40, 40, 365);
	i = 114+40;
	for (; i <1414; i += 100) {
		line(i, 40, i, 365);
	}
	setcolor(BLACK); settextstyle(3, 0,1); setbkcolor(blue_d);
	outtextxy(20, 60, "STT"); outtextxy(77, 60, "Dien"); outtextxy(77+110, 60, "Nuoc"); outtextxy(77 + 110 * 8-50, 60, "Tien coc");
	outtextxy(77+110*2, 60, "Quan li xe"); outtextxy(77+110*3, 60, "Ve Sinh"); outtextxy(77 + 110 * 4, 60, "Th cap");
	outtextxy(77 + 110 * 5-20, 60, "Internet"); outtextxy(77 + 110 * 6-30, 60, "khac"); 
	outtextxy(77 + 110 * 7-40, 60, "Tien phong");
	outtextxy(77 + 110 * 9-50, 60, "No Cu"); outtextxy(77 + 110 * 10-70, 60, "Tong Cong"); outtextxy(77 + 110 * 11-80, 60, "Da Thu");
	outtextxy(77 + 110 * 12-90, 60, "Con No"); outtextxy(77 + 110 * 12+10, 60, "Tien Chi"); settextstyle(9, 0, 0);
}
void tieuthu_dien_water() {
	setfillstyle(1, WHITE);
	bar(0, 375, 1520, 850);
	setfillstyle(1, blue_d); setcolor(YELLOW); rectangle(0, 375, 1520, 415); setcolor(LIGHTMAGENTA);
	setbkcolor(blue_d);
	bar(0, 375, 1520, 415); outtextxy(1520 / 2, 400, "BAO CAO MUC TIEU THU DIEN NUOC");
	setcolor(green); rectangle(0, 415, 1520, 465); line(40, 440, 1520, 440);
	int i =465 + 25;
	for (; i < 850; i += 25) {
		line(0, i, 1520, i);
	}
	line(40,415, 40, 850);
	i = 503;
	for (; i < 1520; i += 503) {
		line(i, 415, i, 850);
	}
	line(232, 440, 232, 850);	line(735, 440, 735, 850); line(1238, 440,1238, 850);
	settextstyle(3, 0, 1); setbkcolor(WHITE); setcolor(BLACK);
	outtextxy(20, 435, "STT"); settextstyle(9, 0, 3);
	setcolor(BLUE); outtextxy(250, 435, "Tinh Toan");
	outtextxy(140, 460, "Dien"); outtextxy(140+232, 460, "Nuoc");
	setcolor(GREEN); outtextxy(250+500, 435, "Thuc Te"); outtextxy(140+232*2, 460, "Dien"); outtextxy(140 + 232*3, 460, "Nuoc");
	setcolor(RED); outtextxy(250 + 535*2-80, 435, "Hao Hut"); outtextxy(140+232*4+50, 460, "Dien"); outtextxy(140 + 232*5+50, 460, "Nuoc");


}
int demdiennuoc(list_pmn l,int x) {
	int dem = 0;
	for (nodepmn* k = l.phead; k != NULL; k = k->pnext) {
		if (k->data.month == x) dem++;
	}
	return dem;
}
int check_t(int a[100], int x,int n) {
	
	int dem = 1;
	for (int i = 1; i <= n; i++)
		if (x == a[i]) dem++;
	return dem;
}
void xuli_Data() {
	
	

	unitprice qk;
	ifstream fk; fk.open("unit_price.txt", ios::in);
	Read_1_unitprice(fk, qk);
	fk.close();
	int a[50];
	ifstream f; list l; create_list_expm(l);
	// tien chi
	expm sv;
	f.open("expense_management.txt", ios::in);
	if (f.fail())
		cout << "Error file! " << endl;
	while (!f.eof())  //read into endfile.
	{
		expm sv;
		Read_1_SV(f, sv);
		nodexpm* p = create_node_expm(sv);
		add_node_expm_tail(l, p);
	}
	f.close();
	// list dien nuoc
	pmn rv;
	list_pmn l1; create_list_pmn_pmn(l1);
	ifstream fm;
	fm.open("paymoney_service.txt", ios::in);
	if (fm.fail())
		cout << "Error file! " << endl;
	while (!fm.eof())  //read into endfile.
	{
		pmn rv;
		read_data_pay_money(fm, rv);
		nodepmn* p = create_nodepmn_pmn(rv);
		add_nodepmn_pmn_tail(l1, p);
	}
	int r= 1,tong=0,dem=60+25,tong1=0; 
	//list thu chi truoc


	list_dn lt; create_list_dn_dn(lt);
	ifstream fo; fo.open("baocao_diennuoc.txt", ios::in);
	dn svt;
	while (!fo.eof())  //read into endfile.
	{
		dn svt;
		read_baocao(fo, svt);
		nodedn* p = create_nodedn_dn(svt);
		add_nodedn_dn_tail(lt, p);
	}
	fo.close();
	setcolor(GREEN); settextstyle(11, 0, 10);
	int j1 = 485;	
	int dem11 = 0,tonghaohutd=0,tonghaohutn=0;
	while (dem11 <= 12)
	{
		for (nodedn* k = lt.phead; k != NULL; k = k->pnext) 
		{
		
			for (nodedn* k = lt.phead; k != NULL; k = k->pnext) {
				if (k->data.month == dem11)
				{
					
					stringstream strs2;
					strs2 << k->data.dien;
					tonghaohutd+= k->data.dien;
					string m2 = strs2.str();
					char* char_type2 = (char*)m2.c_str();
					outtextxy(250 + 140 * 2 + 50, j1 + dem11 * 25-25, char_type2);
					//nuoc

					stringstream strs21;
					strs21 << k->data.nuoc;
					tonghaohutn += k->data.nuoc;
					string m21 = strs21.str();
					char* char_type21 = (char*)m21.c_str();
					outtextxy(250 + 140 * 2 + 50 + 200 + 50, j1 + dem11 * 25-25, char_type21);

				}
				
			}
			dem11++;
			
			
		}
	}
	
		//tong dien tieu tu hao hut
		stringstream strs21pqr1qzte;
		strs21pqr1qzte << tonghaohutd;
		string m21pqr1qzte = strs21pqr1qzte.str();
		char* char_type21pqr1qzte = (char*)m21pqr1qzte.c_str();
		outtextxy(250 + 140 * 2 + 50, 785, char_type21pqr1qzte);
		//tong nuoc
		stringstream strs21pqr1qztce;
		strs21pqr1qztce << tonghaohutn;
		string m21pqr1qztce = strs21pqr1qztce.str();
		char* char_type21pqr1qztce = (char*)m21pqr1qztce.c_str();
		outtextxy(250 + 140 * 2 + 50 + 200 + 50, 785, char_type21pqr1qztce);
		setcolor(BLUE);
		outtextxy(250 + 140 * 2 + 50 + 50, 785, "KW");
		outtextxy(250 + 140 * 2 + 50 + 200 + 50 + 70, 785, "khoi");
		setcolor(red);
		settextstyle(11, 0, 10);




		while (r <= 12) {
			for (nodexpm* k = l.phead; k != NULL; k = k->pnext)
			{
				for (nodexpm* k = l.phead; k != NULL; k = k->pnext)
				{
					if (k->data.ngay.month == r) {
						tong += k->data.money;
					}

				}
				a[r] = tong;
				tong1 += tong;

				if (a[r] != 0) {
					stringstream strs2;
					strs2 << a[r];

					string m2 = strs2.str();
					char* char_type2 = (char*)m2.c_str();
					outtextxy(1407, dem, char_type2);

				}
				dem += 23;
				tong = 0;
				r++;

				stringstream strs21;
				strs21 << tong1;
				string m21 = strs21.str();
				char* char_type21 = (char*)m21.c_str();
				outtextxy(1407, 361, char_type21);

			}
		}
		int mr[50];
		r = 1; tong = 0, dem = 60 + 25, tong1 = 0;
		int tongdien = 0, tongnuoc = 0, tongxe = 0, tongcoc = 0, tongnocu = 0, tongdathu = 0, total = 0, dem2 = 485;
		int td = 0, tn = 0, tx = 0, tc = 0, tno = 0, tdathu = 0, tongtotal = 0, tvs = 0, thcap = 0, tinter = 0, tphong = 0, tongconno = 0, tongnuoc1 = 0, tongdien1 = 0, tongnuoc11 = 0, tongdien11 = 0;
		int count = 0;
		int arr[50], rr = 1;
		dem11 = 1;
		while (r <= 12)
		{
			for (nodepmn* k = l1.phead; k != NULL; k = k->pnext) {
				for (nodepmn* k = l1.phead; k != NULL; k = k->pnext) {
					if ((k->data.month == r)&&(dem<340)) {
						tongdien += (k->data.dsomoi - k->data.dsocu) * qk.electric;
						tongnuoc += (k->data.nsomoi - k->data.nsocu) * qk.water;
						tongnuoc1 += (k->data.nsomoi - k->data.nsocu);
						tongdien1 += (k->data.dsomoi - k->data.dsocu);
						tongxe += k->data.slxe * qk.car_manage;
						tongcoc += k->data.tiencoc;
						tongnocu += k->data.nocu;
						tongdathu += k->data.dathu;
						count++;
					}
				}
				arr[rr] = tongdien1;
				tongdien11 += tongdien1;
				tongnuoc11 += tongnuoc1;
				td += tongdien;
				tn += tongnuoc;
				tx += tongxe;
				tc += tongcoc;
				tno += tongnocu;
				tdathu += tongdathu;
				if (dem < 340) {
					stringstream strs2y;
					strs2y << tongdien;
					string m2y = strs2y.str();
					char* char_type2y = (char*)m2y.c_str();
					outtextxy(80, dem, char_type2y);
					//nuoc
					stringstream strs2ye;
					strs2ye << tongnuoc;

					string m2ye = strs2ye.str();
					char* char_type2ye = (char*)m2ye.c_str();
					outtextxy(80 + 100, dem, char_type2ye);
					//xe
					stringstream strs2yr;
					strs2yr << tongxe;

					string m2yr = strs2yr.str();
					char* char_type2yr = (char*)m2yr.c_str();
					outtextxy(80 + 200, dem, char_type2yr);
					//ve sinh
					stringstream strs6;
					tvs += count * qk.clean;
					strs6 << count * qk.clean;
					string temp_str6 = strs6.str();
					char* char_type6 = (char*)temp_str6.c_str();
					outtextxy(80 + 300, dem, char_type6);
					// th cap
					stringstream strs67;
					strs67 << count * qk.cabletv;
					thcap += count * qk.cabletv;
					string temp_str67 = strs67.str();
					char* char_type67 = (char*)temp_str67.c_str();
					outtextxy(80 + 400, dem, char_type67);
					//internet
					stringstream strs6t;
					strs6t << count * qk.internet;
					tinter += count * qk.internet;
					string temp_str6t = strs6t.str();
					char* char_type6t = (char*)temp_str6t.c_str();
					outtextxy(80 + 500, dem, char_type6t);
					//tien phong
					stringstream strs6te;
					strs6te << count * qk.roomcost;
					tphong += count * qk.roomcost;
					string temp_str6te = strs6te.str();
					char* char_type6te = (char*)temp_str6te.c_str();
					outtextxy(80 + 730, dem, char_type6te);
					//tiencoc
					stringstream strs6tq;
					strs6tq << tongcoc;
					string temp_str6tq = strs6tq.str();
					char* char_type6tq = (char*)temp_str6tq.c_str();
					outtextxy(80 + 820, dem, char_type6tq);
					//no cu
					stringstream strs6tqq;
					strs6tqq << tongnocu;
					string temp_str6tqq = strs6tqq.str();
					char* char_type6tqq = (char*)temp_str6tqq.c_str();
					outtextxy(80 + 930, dem, char_type6tqq);
					//tong cong
					stringstream strsw;
					strsw << tongdien + tongnuoc + tongxe + count * qk.clean + count * qk.cabletv + count * qk.internet + count * qk.roomcost + tongnocu;
					tongtotal += tongdien + tongnuoc + tongxe + count * qk.clean + count * qk.cabletv + count * qk.internet + count * qk.roomcost + tongnocu;
					string temp_strsw = strsw.str();
					char* char_typew = (char*)temp_strsw.c_str();
					outtextxy(80 + 930 + 100, dem, char_typew);
					//da thu
					stringstream strs6tqqe;
					strs6tqqe << tongdathu;
					string temp_str6tqqe = strs6tqqe.str();
					char* char_type6tqqe = (char*)temp_str6tqqe.c_str();
					outtextxy(80 + 930 + 200, dem, char_type6tqqe);
					//con no
					stringstream strs6tqqer;
					strs6tqqer << tongdien + tongnuoc + tongxe + count * qk.clean + count * qk.cabletv + count * qk.internet + count * qk.roomcost + tongnocu - tongdathu;
					tongconno += tongdien + tongnuoc + tongxe + count * qk.clean + count * qk.cabletv + count * qk.internet + count * qk.roomcost + tongnocu - tongdathu;
					string temp_str6tqqer = strs6tqqer.str();
					char* char_type6tqqer = (char*)temp_str6tqqer.c_str();
					outtextxy(80 + 930 + 300, dem, char_type6tqqer);
					//bao cao tieu thu dien nuoc
					//---- phan hao hut dien nuoc


				}
				
					//---- tinh toan dien nuoc
					stringstream strspv;
					strspv << tongdien1;
					string temp_str2pv = strspv.str();
					char* char_type2pv = (char*)temp_str2pv.c_str();

					outtextxy(90, dem2, char_type2pv);
					//nuoc
					stringstream strspvc;
					strspvc << tongnuoc1;
					string temp_str2pvc = strspvc.str();
					char* char_type2pvc = (char*)temp_str2pvc.c_str();

					outtextxy(90 + 250, dem2, char_type2pvc);
			
				rr++;
				count = 0;
				dem += 23;
				dem2 += 25;
				r++;
				tongdien = 0;
				tongxe = 0;
				tongnuoc = 0;
				tongcoc = 0;
				tongnocu = 0; tongdathu = 0;
				tongdien1 = 0; tongnuoc1 = 0;
				if (k == l1.ptail) {
					stringstream strs21p;
					strs21p << td;
					string m21p = strs21p.str();
					char* char_type21p = (char*)m21p.c_str();
					outtextxy(90, 361, char_type21p);

					stringstream strs21pr;
					strs21pr << tn;
					string m21pr = strs21pr.str();
					char* char_type21pr = (char*)m21pr.c_str();
					outtextxy(90 + 100, 361, char_type21pr);
					stringstream strs21pq;
					strs21pq << tx;
					string m21pq = strs21pq.str();
					char* char_type21pq = (char*)m21pq.c_str();
					outtextxy(90 + 200, 361, char_type21pq);
					stringstream strs21pqr;
					strs21pqr << tvs;
					string m21pqr = strs21pqr.str();
					char* char_type21pqr = (char*)m21pqr.c_str();
					outtextxy(90 + 300, 361, char_type21pqr);
					stringstream strs21pqrt;
					strs21pqrt << thcap;
					string m21pqrt = strs21pqrt.str();
					char* char_type21pqrt = (char*)m21pqrt.c_str();
					outtextxy(90 + 400, 361, char_type21pqrt);
					stringstream strs21pqrw;
					strs21pqrw << tinter;
					string m21pqrw = strs21pqrw.str();
					char* char_type21pqrw = (char*)m21pqrw.c_str();
					outtextxy(90 + 500, 361, char_type21pqrw);
					stringstream strs21pqr1;
					strs21pqr1 << tphong;
					string m21pqr1 = strs21pqr1.str();
					char* char_type21pqr1 = (char*)m21pqr1.c_str();
					outtextxy(90 + 700+20, 361, char_type21pqr1);
					stringstream strs21pqr1e;
					strs21pqr1e << tc;
					string m21pqr1e = strs21pqr1e.str();
					char* char_type21pqr1e = (char*)m21pqr1e.c_str();
					outtextxy(90 + 800, 361, char_type21pqr1e);
					stringstream strs21pqr1q;
					strs21pqr1q << tno;
					string m21pqr1q = strs21pqr1q.str();
					char* char_type21pqr1q = (char*)m21pqr1q.c_str();
					outtextxy(90 + 900+20, 361, char_type21pqr1q);
					//total
					stringstream strs21pqr1qe;
					strs21pqr1qe << tongtotal;
					string m21pqr1qe = strs21pqr1qe.str();
					char* char_type21pqr1qe = (char*)m21pqr1qe.c_str();
					outtextxy(90 + 1000, 361, char_type21pqr1qe);
					//da thu
					stringstream strs21pqr1qet;
					strs21pqr1qet << tdathu;
					string m21pqr1qet = strs21pqr1qet.str();
					char* char_type21pqr1qet = (char*)m21pqr1qet.c_str();
					outtextxy(90 + 1100+20, 361, char_type21pqr1qet);
					//con no
					stringstream strs21pqr1qz;
					strs21pqr1qz << tongconno;
					string m21pqr1qz = strs21pqr1qz.str();
					char* char_type21pqr1qz = (char*)m21pqr1qz.c_str();
					outtextxy(1190 + 100, 361, char_type21pqr1qz);
					//tong dien
					stringstream strs21pqr1qzt;
					strs21pqr1qzt << tongdien11;
					string m21pqr1qzt = strs21pqr1qzt.str();
					char* char_type21pqr1qzt = (char*)m21pqr1qzt.c_str();
					outtextxy(90, 785, char_type21pqr1qzt);
					//tong nuoc
					stringstream strs21pqr1qztc;
					strs21pqr1qztc << tongnuoc11;
					string m21pqr1qztc = strs21pqr1qztc.str();
					char* char_type21pqr1qztc = (char*)m21pqr1qztc.c_str();
					outtextxy(90 + 250, 785, char_type21pqr1qztc);
					setcolor(BLUE);
					outtextxy(170, 785, "KW");
					outtextxy(250 + 140, 785, "khoi");
					// tong  thuc te tieu thu

					break;

				}
			}

			settextstyle(11, 0, 5);
			setcolor(BLUE);
			int j = 85;
			for (int i = 1; i <= 12; i++) {
				stringstream strs4;
				strs4 << i;
				string temp_str4 = strs4.str();
				char* char_type4 = (char*)temp_str4.c_str();
				outtextxy(15, j, char_type4);
				j += 23;
			}
			int i = 90 + 23 * 12 - 5; setcolor(red);
			outtextxy(15, i, "Tong");
			// bao cao nuoc
			settextstyle(11, 0, 4);
			j = 485;
			for (int i = 1; i <= 12; i++) {
				stringstream strs4;
				strs4 << i;
				string temp_str4 = strs4.str();
				char* char_type4 = (char*)temp_str4.c_str();
				outtextxy(15, j, char_type4);
				j += 25;
			}
			i = 490 + 23 * 13 - 5; setcolor(red);
			outtextxy(15, i, "Tong");
		}
		tonghaohutd = 0, tonghaohutn = 0;
		
		
		ofstream fl; fl.open("try.txt", ios::out);
		ofstream fot; fot.open("input_menu8.txt", ios::out);
		for (nodepmn* q = l1.phead; q != NULL; q = q->pnext)
		{
			for (nodedn* k = lt.phead; k != NULL; k = k->pnext)
			{

				if (k->data.month == q->data.month) {
					stringstream strs2xx;
					strs2xx << k->data.dien - (q->data.dsomoi - q->data.dsocu) * demdiennuoc(l1, q->data.month);
					fl << k->data.dien - (q->data.dsomoi - q->data.dsocu) * demdiennuoc(l1, q->data.month)<<" ";
					string m2xx = strs2xx.str();
					char* char_type2xx = (char*)m2xx.c_str();
					
					outtextxy(250 + 140 * 2 + 50 + 500, j1 + (k->data.month) * 25 - 25, char_type2xx);
					//nuoc
					stringstream strs21e;
					strs21e << k->data.nuoc - (q->data.nsomoi - q->data.nsocu) * demdiennuoc(l1, q->data.month);
					fot << k->data.nuoc - (q->data.nsomoi - q->data.nsocu) * demdiennuoc(l1, q->data.month) << " ";
					string m21e = strs21e.str();
					char* char_type21e = (char*)m21e.c_str();
					
					outtextxy(1220 + 100, j1 + (k->data.month) * 25 - 25, char_type21e);
					
				
					
				}
				


			}

		}
		fot.close();
		int ai[100], countt = 0;

		fl.close();
		ifstream ft; ft.open("try.txt", ios::in);
		while (ft.eof() == false) {
			ft >> ai[countt];
			countt++;
		}
		countt--;
		for (int i = 0; i < countt; i++) {
			
				if(ai[i]!=ai[i+1])
				tonghaohutd += ai[i];
			
		}

		ft.close();

		ifstream fote; fote.open("input_menu8.txt", ios::in);
		// tinh tong nuoc
		int bi[100], countc = 0;
		while (!fote.eof())
		{
			fote >> bi[countc];
			countc++;
		}
		countc--;
		for (int i = 0; i < countc; i++) {
			if (bi[i] != bi[i + 1])
				tonghaohutn += bi[i];
		}

		fote.close();



		//tong dien
		stringstream strs21pqr1qztq;
		strs21pqr1qztq << tonghaohutd;
		string m21pqr1qztq = strs21pqr1qztq.str();
		char* char_type21pqr1qztq = (char*)m21pqr1qztq.c_str();
		outtextxy(250 + 140 * 2 + 50 + 500, 785, char_type21pqr1qztq);
		//tong nuoc
		stringstream strs21pqr1qztcr;
		strs21pqr1qztcr << tonghaohutn;
		string m21pqr1qztcr = strs21pqr1qztcr.str();
		char* char_type21pqr1qztcr = (char*)m21pqr1qztcr.c_str();
		outtextxy(250 + 140 * 2 + 50 + 500 + 240, 785, char_type21pqr1qztcr);
		setcolor(BLUE);
		outtextxy(250 + 140 * 2 + 50 + 500 + 100, 785, "KW");
		outtextxy(250 + 140 * 2 + 50 + 500 + 240 + 70, 785, "khoi");
	
}
void input_user_baocao() {
	cleardevice();
	
	void  main_menu_report();
	settextstyle(9, 0, 4);
	setfillstyle(9, blue_d);
	bar(0, 0, 1520, 850);
	setfillstyle(1, yellow); setcolor(red); setbkcolor(yellow);
	bar(0, 0, 130, 40); outtextxy(60, 30, "<BACK"); setcolor(RED);
	rectangle(0, 0, 130, 40);
	int exit = 0, x, y, exit1 = 0;
	setfillstyle(1, xinh);
	setcolor(WHITE); setbkcolor(xinh);
	bar(130, 0, 1520, 40); settextjustify(1, 1);
	settextstyle(9, 0, 4);
	outtextxy(1520 / 2, 30, "Phan Nhap Thong Cap Nhat");
	setfillstyle(1, yellow);
	bar(100, 100, 400, 150);
	setcolor(red); setbkcolor(yellow);
	rectangle(100, 100, 400, 150); settextstyle(9, 0, 4);
	outtextxy(240, 140, "Nhap So Dien");
	rectangle(400, 100, 700, 150);
	setfillstyle(1, green);
	bar(100, 150, 400, 200);
	setcolor(red); setbkcolor(green);
	rectangle(100, 150, 400, 200); settextstyle(9, 0, 4); setcolor(WHITE);
	outtextxy(240, 190, "Nhap So Nuoc"); setcolor(red);
	rectangle(400, 150, 700, 200);
	setfillstyle(1, red);
	bar(100,200, 400, 250);
	setcolor(red); setbkcolor(red);
	rectangle(100, 200, 400, 250); settextstyle(9, 0, 4); setcolor(WHITE);
	outtextxy(240, 190+50, "Nhap Thang"); setcolor(red);
	rectangle(400, 200, 700, 250);
	//
	setfillstyle(1, LIGHTMAGENTA);
	bar(900, 100, 1300, 150);
	setcolor(BLUE); setbkcolor(LIGHTMAGENTA); setcolor(yellow);
	rectangle(900, 100, 1300, 150); settextstyle(9, 0, 5); setcolor(BLUE);
	outtextxy(1120, 140, "Xac Nhan");
	setfillstyle(1, green);
	bar(900, 150, 1300, 200);
	setcolor(red); setbkcolor(green); 
	rectangle(900, 150, 1300, 200); settextstyle(9, 0, 5); setcolor(WHITE);
	outtextxy(1100, 140+50, "XOA"); list_dn l; create_list_dn_dn(l);
	ifstream f1; f1.open("baocao_diennuoc.txt", ios::in);
	dn sv;
	while (!f1.eof())  //read into endfile.
	{
		dn sv;
		read_baocao(f1, sv);
		nodedn* p = create_nodedn_dn(sv);
		add_nodedn_dn_tail(l, p);
	}
	while (exit == 0) {
		if (ismouseclick(WM_LBUTTONDOWN))
		{
			getmouseclick(WM_LBUTTONDOWN, x, y);
			if ((x >= 0 && x <= 130) && (y >= 0 && y <= 40)) {
				exit = 1; setbkcolor(WHITE);
				main_menu_report();
			}
			else if ((x>=400&&x<=700)&&(y>=100&&y<=150)) {
				setbkcolor(WHITE);
				setfillstyle(9, blue_d);
				bar(850, 40, 1400, 100); bar(850, 200, 1400, 300); bar(400, 100 + 50, 700, 150 + 50); bar(400, 200, 700, 250);
				bar(400, 200, 700, 250);
				setcolor(red);
				rectangle(400, 200, 700, 250); rectangle(400, 150, 700, 200);
				setfillstyle(1, WHITE); bar(400, 100, 700, 150);
				setcolor(yellow);
				rectangle(400, 100, 700, 150); setcolor(red); setbkcolor(WHITE);
				char t[20], t1[30] = " ";
				Input(t, t1, 600, 140, '0', '9', 400, 100, 700, 150);
				strcpy(t1, t);
				ofstream f; f.open("input_menu8.txt", ios::out);
				f << t << ",";

			}
			else if ((x >= 400 && x <= 700) && (y >= 100+50 && y <= 150+50)) {
				setfillstyle(9, blue_d);
				bar(400, 100 + 50, 700, 150 + 50);
				setcolor(yellow);
				rectangle(400, 100 + 50, 700, 150 + 50); setcolor(red); setbkcolor(WHITE);
				char t1[20], t2[30] = " ";
				Input(t1, t2, 600, 140+50, '0', '9', 400, 100+50, 700, 150+50);
				strcpy(t2, t1);
				ofstream f; f.open("input_menu8.txt", ios::out|ios::app);
				f << t1 << ",";

			}
			else if ((x >= 400 && x <= 700) && (y >=200 && y <= 250)) {
				setfillstyle(9, blue_d);
				bar(400, 200, 700, 250);
				setcolor(yellow);
				rectangle(400, 200, 700, 250); setcolor(red);
				char t2[20], t12[30] = " "; setbkcolor(WHITE);
				Input(t2, t12, 600, 240, '0', '9', 400, 200, 700, 250);
				strcpy(t12, t2);
				ofstream f; f.open("input_menu8.txt", ios::out | ios::app);
				f << t2;
				ofstream f1; f1.open("try.txt", ios::out);
				f1 << t2;
				f1.close();

			}
			else if ((x>=900&&x<=1300)&&(y>=100&&y<=150)) {
				setfillstyle(9, blue_d);
				bar(1120, 70, 1300, 90); 
				setfillstyle(1, red);
				bar(900, 100, 1300, 150);
				setcolor(BLUE); setbkcolor(red); setcolor(yellow);
				rectangle(900, 100, 1300, 150); settextstyle(9, 0, 5); setcolor(WHITE);
				outtextxy(1120, 140, "Xac Nhan");
				outtextxy(1120, 90, "Them Thanh Cong!");
				ifstream f; f.open("input_menu8.txt", ios::in);
				read_baocao(f, sv);
				nodedn* p = create_nodedn_dn(sv);
				add_nodedn_dn_tail(l, p); sort_by_month(l);
								ofstream f1; f1.open("baocao_diennuoc.txt", ios::out);
				for (nodedn* k = l.phead; k != NULL; k = k->pnext) {
					f1 << endl;
					write_info(f1, k->data);
				
				}
				f1.close();
			}
			else if ((x>=900&&x<=1300)&&(y>=150&&y<=200)) {
				setfillstyle(1, red);
				bar(900, 150, 1300, 200);
				setcolor(red); setbkcolor(red);
				rectangle(900, 150, 1300, 200); settextstyle(9, 0, 5); setcolor(WHITE);
				outtextxy(1100, 140 + 50, "XOA");
				ifstream f; f.open("try.txt", ios::in);
				int postion;
				f >> postion;
				XoanodednCoKhoaBatKy(l, postion);
				ofstream f1; f1.open("baocao_diennuoc.txt", ios::out);
				for (nodedn* k = l.phead; k != NULL; k = k->pnext) {
					f1 << endl;
					write_info(f1, k->data);

				}
				f1.close();
				outtextxy(1120, 240, "Xoa Thanh Cong!");
			}
		}

		if (kbhit())
		{
			char key = getch();
			if (key == 27) {
				exit = 1; setbkcolor(WHITE);
				main_menu_report();
			}
		}
	}
}
void main_menu_report() {
	int exit = 0,x,y;
	cleardevice();
	setfillstyle(1, blue_B);
	setcolor(WHITE); setbkcolor(blue_B);
	bar(0, 0, 1520, 40); settextjustify(1, 1);
	settextstyle(9, 0, 0);
	outtextxy(1520 / 2, 30, "BAO CAO CHI TIET 12 THANG"); settextstyle(9, 0, 3);
	setfillstyle(1, yellow); setcolor(red); setbkcolor(yellow);
	bar(0, 0, 130, 40); outtextxy(60, 30, "<BACK"); setcolor(RED);
	rectangle(0, 0, 130, 40);
	//
	setfillstyle(1,red); setcolor(WHITE); setbkcolor(red);
	bar(150, 0, 340, 40); outtextxy(250, 30, "CAP NHAT"); setcolor(WHITE);
	rectangle(150, 0, 340, 40); draw_main_table_focus(); tieuthu_dien_water(); xuli_Data();
	while (exit==0)
	{
		if (ismouseclick(WM_LBUTTONDOWN)) {
			getmouseclick(WM_LBUTTONDOWN, x, y);
			if ((x >= 0 && x <= 130) && (y >= 0 && y <= 40)) {
				exit = 1; HomePageUIShow();
			}
			else if ((x >= 150 && x <= 340) && (y >= 0 && y <= 40)) {
				setbkcolor(WHITE);
				input_user_baocao();
			}
		}
		if (kbhit())
		{
			char key = getch();
			if (key == 27) {
				cleardevice();
				HomePageUIShow();
				exit = 1;
			}
			else if (key==59) {
				setbkcolor(WHITE);
				input_user_baocao();
			}
		}
	}
}