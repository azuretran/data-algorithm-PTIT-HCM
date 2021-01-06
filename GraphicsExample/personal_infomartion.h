#pragma once
#include <iostream>
#include<string>
#include<stdio.h>
#include <stdlib.h>
#include <fstream>

#define _CRT_SECURE_NO_DEPRECATE 

using namespace std;

#define MAX 100

struct SinhVien
{

	char Ho[50];
	string Ten;
	string SDT;
	int MaPhong;
	float pay;
	int come_day;

}; typedef struct sinhvien sv;
struct Node
{
	SinhVien data;
	Node* pNext;
};
struct ListSV
{
	Node* pHead;
	Node* pTail;
};
void CreateList(ListSV& l);
Node* CreateNode(SinhVien x);
void AddTail(ListSV& l, Node* p);
void Read_1_SV(ifstream& f, SinhVien& sv);
void XuatSv(SinhVien sv);
void ReadFile_to_list(ifstream& f, ListSV& l);
void AddUser(ListSV& l);
void SaveFile(ListSV& l);
void XuatTheoMaPhong(ListSV l);
int KTTen(string s);
void Menu(ListSV l);
void Selection_Sort_ID_Room(ListSV l);
void InterChange_Sort(ListSV& l);