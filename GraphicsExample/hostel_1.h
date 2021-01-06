#include<iostream>
#define MAX_hostels 300

struct hostels {
	char fname[15];
	char phone[15];
	char room_name[50];
	char nvp[50]; 
	char bill[100];
	char name[20];
};

struct hostelLists {
	hostels* list[MAX_hostels];
	int size = 0;
} hostelAddArray;

hostels hostelCreate(char* id, char* kind, char*sr,char*b,char*m,char*n) {
	hostels tmp;
	strcpy(tmp.fname, id);
	strcpy(tmp.bill,m);
	strcpy(tmp.name, n);
	strcpy(tmp.phone, kind);
	strcpy(tmp.nvp, b);
	strcpy(tmp.room_name, sr);
	return tmp;
}

void PlaneAdd(hostels plane) {
	hostelAddArray.list[hostelAddArray.size] = new hostels;
	*hostelAddArray.list[hostelAddArray.size] = plane;
	hostelAddArray.size++;
}

void PlaneRemoveByIndex(int index) {
	delete hostelAddArray.list[index];
	for (int i = index; i < hostelAddArray.size - 1; i++) {
		hostelAddArray.list[i] = hostelAddArray.list[i + 1];
	}
	hostelAddArray.size--;
}

void PlaneEditByIndex(int index, char* kind) {
	strcpy(hostelAddArray.list[index]->fname, kind);
}