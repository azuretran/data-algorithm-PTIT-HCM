#pragma once
#include"graphics.h"
#include<iostream>
#include<string>
using namespace std;
#define max 120;
void info_nhatro();

void init_record();
struct infor_hostel {
	string name, adress, phonenumber, content, notice;

}; typedef struct infor_hostel infor_hostel;
struct unitprice {
	int electric, water, water1, car_manage, clean, cabletv, internet, roomcost;
}; typedef struct unitprice unitprice;
void Read_1_info(ifstream& f, infor_hostel& sv);
void Read_1_unitprice(ifstream& f, unitprice& rv);