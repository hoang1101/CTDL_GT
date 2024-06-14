#pragma once
#include "define.h"
#include "time.h"
#define file_chuyen_bay "datachuyenbay"
#include <stdexcept>
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
	cout<<p->data.sove;
	for (int i = 0; i < p->data.sove; i++) {
			    // In thông tin c?a t?ng ph?n t? ve
			    std::cout << "V? trí: " << p->data.dsve[i].vitri << std::endl;
//			    std::cout << "CCCD: " << cb.dsve[i].cccd << std::endl;
}
	
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

void EditChuyenBay(nodeCB *&first,int vitri ,chuyenbay cb){

//	try {
		if (first == NULL )
	{
		cout<<"hihi";
		return;
	}
	nodeCB *nodechay = first;
	for(int i=0; i < vitri - 1 && nodechay->next != NULL; i++ ){
		nodechay= nodechay-> next;
	}
	nodechay->data = cb;
//	} catch (const std::runtime_error& e) {
//        std::cerr << "L?i runtime: " << e.what() << std::endl;
//}
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

int timkiemmaybay(nodeCB *first, char *x) {
	
	for (nodeCB *p = first; p!=NULL;p=p->next){
		if (strcmp(p->data.SHMB,x) == 0)
		return 1;
	}
	
	return 0;
}

void khoiTaoDanhSachVe(chuyenbay &cb, danhsachmaybay &dsmb) {
	
	
	cb.trangthai = CON_VE;
	int soday,sodong;
	soday = dsmb.data[timkiem(dsmb,cb.SHMB)]->soday;
	sodong = dsmb.data[timkiem(dsmb,cb.SHMB)]->sodong;
		
    cb.sove = soday * sodong;
    
    cout<<cb.sove;
    cb.dsve = new ve[cb.sove+1];

    int index = 0;
    for (char day = 'A'; day < 'A' + soday; day++) {
        for (int dong = 1; dong <= sodong; dong++) {
            sprintf(cb.dsve[index].vitri, "%c%02d", day, dong);
            strcpy(cb.dsve[index].cccd, ""); // Kh?i t?o CCCD r?ng
            index++;
//            cout<<cb.dsve[index].vitri;
        }
    }
    
//    for (int i = 0; i < cb.sove; i++) {
//    // In thông tin c?a t?ng ph?n t? ve
//    std::cout << "V? trí: " << cb.dsve[i].vitri << std::endl;
//    std::cout << "CCCD: " << cb.dsve[i].cccd << std::endl;
//}
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



