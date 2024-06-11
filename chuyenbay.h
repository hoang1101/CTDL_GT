#pragma once
#include "define.h"
#include "time.h"
#define file_chuyen_bay "datachuyenbay"

// trang thai
enum TrangThai{
	HUY_CHUYEN,
	CON_VE,
	HET_VE,
	HOAN_TAT
};

struct ve {
	char cccd[12];
	char vitri[5];
};

struct chuyenbay {
	char MaCB[MAX_MACB+1];
	char SanBayDen[MAX_SBDEN+1];
	char SHMB[MAXSHMB];
	TrangThai trangthai;
	Time time;
	ve *dsve = NULL;
	int sove;
	
};

struct nodeCB {
	chuyenbay data;
	nodeCB *next = NULL;
	
};

nodeCB *taonodemoi(chuyenbay &cb){
	nodeCB *temp = new nodeCB;
	temp->data = cb;
	temp->next = NULL;
	return temp;
}

void InsertLast(nodeCB *&first, chuyenbay cb) {
	nodeCB *p = taonodemoi(cb);

    if (first == NULL) {
        first = p;
    } else {
       nodeCB *nodechay = first ;
		for(nodechay = first; nodechay->next != NULL; nodechay = nodechay-> next );
			nodechay-> next = p;
    }

	
//    nodeCB p = taonodemoi(cb);
//    if (first == NULL) {
//        first = p;
//        first->next=NULL;
//    } else {
//        for(nodeCB nodechay = first; nodechay -> nodeCB != NULL; nodechay = nodechay -> nodeCB );
//			nodechay -> nodeCB = p ;
//    }
}

bool dsCBEmpty(nodeCB *first) {
	return (first == NULL);
}

int huychuyen(nodeCB *First) {
	if (First->data.trangthai== CON_VE || First->data.trangthai== HET_VE){
		First->data.trangthai = HUY_CHUYEN;
		return 1;
	}
	 return 0;
}
////-----------------------FILE CHUYEN BAY--------------------------------------
void Save_file_chuyen_bay(nodeCB *first){

	FILE *f = fopen (file_chuyen_bay, "wb");
	if (f==NULL) 
	{  	cout<<"ERROR! Khong The Mo File Chuyen Bay"<<endl;
		 		 return ;
	}

	for (nodeCB *p=first ; p!=NULL ; p=p->next)
	 {
	 	 chuyenbay &data = p->data; // Khai b o bi?n sv trong v ng l?p
        fwrite(&data, sizeof(chuyenbay), 1, f);
        fwrite(data.dsve, sizeof(ve), 1, f);
	 }
	  
	fclose (f);
}



void Open_file_chuyen_bay(nodeCB *&first ){
	FILE *f;
	nodeCB *p;
	chuyenbay cb;
	if ((f=fopen(file_chuyen_bay,"rb"))==NULL)
	{  cout<<"ERROR! Khong The Mo File Chuyen Bay"<<endl;
	 	return ;
	}	 
 
	while (first != NULL) {
        p = first;
        first = p->next;
        delete p;
    }

	while (fread(&cb, sizeof(chuyenbay), 1, f) == 1) {
        cb.dsve = new ve;
        fread(cb.dsve, sizeof(ve), 1, f);
        InsertLast(first, cb);
    }

    fclose(f);
}



