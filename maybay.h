#pragma once
#include "define.h"	
#define file_may_bay "datamaybay"					
using namespace std;

struct maybay {
	char sohieumaybay[MAXSHMB+1];
	char loaimaybay[MAXLOAIMB+1];
	int soday,sodong;
	int soChuyenDaBay = 0;
};

struct danhsachmaybay{
	maybay *data[MAXMB];
	int soluong = 0;
};

// cap phat vung nho va sao chep ddud lieu tu mot doi tuong may bay vao vung nho do
maybay *newmb(maybay mb) {
	maybay *temp = new maybay;
	*temp = mb;
	return temp;
}

void add_may_bay(danhsachmaybay &dsmb, maybay &mb) {
	dsmb.data[dsmb.soluong] = newmb(mb);
	dsmb.soluong++;
}

bool Empty(danhsachmaybay &dsmb){
	return (dsmb.soluong == 0 ? true : false);
}

bool FullDS(danhsachmaybay &dsmb) {
	return (dsmb.soluong > MAXMB ? true : false);
}

void delete_mb(danhsachmaybay &dsmb, int vitri){
	delete dsmb.data[vitri];
	for (int i= vitri; i<dsmb.soluong-1;i++)
		dsmb.data[i] = dsmb.data[i+1];
	dsmb.soluong--;
	
}
int timkiem(danhsachmaybay &dsmb,char *sohieumb) {
	for(int i =0; i<dsmb.soluong;i++){
		if (strcmp(dsmb.data[i]->sohieumaybay,sohieumb) == 0)
		return i;
	}
	return -1;
}

void edit_mb(danhsachmaybay &dsmb, int vitri , maybay &mb){
	*dsmb.data[vitri] = mb;
}

void sapXepMayBayBubbleSort(danhsachmaybay &dsmb) {
    for (int i = 0; i < dsmb.soluong - 1; ++i) {
        for (int j = 0; j < dsmb.soluong - i - 1; ++j) {
            if (dsmb.data[j]->soChuyenDaBay < dsmb.data[j + 1]->soChuyenDaBay) {
                // Ho�n d?i hai ph?n t?
                maybay* temp = dsmb.data[j];
                dsmb.data[j] = dsmb.data[j + 1];
                dsmb.data[j + 1] = temp;
            }
        }
    }
}

void xoaAllMayBay(danhsachmaybay &dsmb) {
for (int i = 0; i < dsmb.soluong; ++i) {
	if (dsmb.data[i] == NULL) {
		return;
	}
        delete dsmb.data[i]; // Gi?i ph�ng c?u tr�c maybay m� con tr? dang tr? t?i
    }

    // �?t l?i s? lu?ng ph?n t? v? 0
    dsmb.soluong = 0;
}

///// FILE

void Open_file_MB (danhsachmaybay &dsmb) {
	       FILE * PTR;
	       maybay temp;
		 if ((PTR=fopen(file_may_bay,"rb"))==NULL)
		 {  
		 	cout<<"Khong The Mo File May Bay"<<endl;
		 	return;
		 }
		  dsmb.soluong=0;
		 while  (fread (&temp, sizeof (maybay), 1, PTR)!=0) {
		 	
		add_may_bay(dsmb,temp);
	 }
	 	fclose(PTR);
	}
	
	
void Save_file_MB (danhsachmaybay &dsmb) {
	FILE *PTR;
	if ((PTR=fopen(file_may_bay,"wb"))==NULL) {
		cout<<"Khong The Mo File May Bay"<<endl;
		return;
	}
	for (int i=0;i<dsmb.soluong;i++){
		fwrite(dsmb.data[i],sizeof(maybay),1,PTR);
		
	}
	fclose(PTR);
}
