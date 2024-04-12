#pragma once
#include "define.h"	
#define file_may_bay "datamaybay"					
using namespace std;
struct maybay {
	char sohieumaybay[15];
	char loaimaybay[50];
	int soday,sodong;
	int soChuyenDaBay = 0;
};

struct danhsachmaybay{
	maybay *data[MAXMB];
	int soluong = 0;
};

maybay *newmb(maybay mb) {
	maybay *temp = new maybay;
	*temp = mb;
	return temp;
}

void add_may_bay(danhsachmaybay &dsmb, maybay &mb) {
	dsmb.data[dsmb.soluong] = newmb(mb);
	dsmb.soluong++;
}

void Open_file_MB (danhsachmaybay &dsmb) {
	       FILE * PTR;
	       maybay temp;
		 if ((PTR=fopen(file_may_bay,"rb"))==NULL)
		 {  
		 	cout<<"ERROR! Khong The Mo File May Bay"<<endl;
		 	return;
		 }
		  dsmb.soluong=0;
		 while  (fread (&temp, sizeof (maybay), 1, PTR)!=0) {
		 	
		add_may_bay(dsmb,temp);
	 }
	 	fclose(PTR);
	}
