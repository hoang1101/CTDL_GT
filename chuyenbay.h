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
	char SHMB[MAXSHMB+1];
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


void InsertTheoMaCB(nodeCB *&first, chuyenbay &cb ){
	 nodeCB *p = taonodemoi(cb);
    
    // Tru?ng h?p danh s?ch r?ng
    if (first == NULL) {
        first = p;
        return;
    }
    // them vao dau danh sach
   if (strcmp(first->data.MaCB, cb.MaCB) >= 0) {
        p->next = first;
        first = p;
        return;
    }
    
    // Tru?ng h?p th?m v?o cu?i danh s?ch ho?c gi?a danh s?ch
    nodeCB *nodechay = first;
    while (nodechay->next != NULL && strcmp(nodechay->next->data.MaCB, cb.MaCB) < 0) {
        nodechay = nodechay->next;
    }
//    cout<<nodechay->data.MaCB;
    p->next = nodechay->next;
    nodechay->next = p;
}

void InsertLast(nodeCB *&first, chuyenbay &cb) {
	nodeCB *p = taonodemoi(cb);
    if (first == NULL) {
        first = p;
    } else {
       nodeCB *nodechay = first ;
		for(nodechay = first; nodechay->next != NULL; nodechay = nodechay-> next );
			nodechay-> next = p;
    }
}

int demslcb(nodeCB *first){
	nodeCB *p;
	int dem=0;
	for (p = first; p!=NULL;p=p->next){
		dem++;
	}	
	return dem;
}

void EditChuyenBay(nodeCB *temp,chuyenbay &cb){
	
	
	temp->data=cb;

//	try {
//		if (first == NULL )
//	{
//		cout<<"hihi";
//		return;
//	}
//	nodeCB *nodechay = first;
//	for(int i=0; i < vitri - 1 && nodechay->next != NULL; i++ ){
//		nodechay= nodechay-> next;
//	}
//	nodechay->data = cb;
//	} catch (const std::runtime_error& e) {
//        std::cerr << "L?i runtime: " << e.what() << std::endl;
//}
}
 
bool dsCBEmpty(nodeCB *first) {
	return (first == NULL);
}

int huychuyen(nodeCB *First) {
	
//	|| First->data.trangthai== HET_VE
	if (First->data.trangthai == CON_VE || First->data.trangthai== HET_VE ){
//		cout<<First->data.SHMB;
		First->data.trangthai = HUY_CHUYEN;
		return 1;
	}
	 return 0;
}

nodeCB *timkiemmaybay(nodeCB *first, char *x) {
	
	nodeCB *p;
	for (p = first; p!=NULL;p=p->next){
		if (strcmp(p->data.SHMB,x) == 0)
		return p;
	}
	
	return NULL;
}

nodeCB *timkiemMACB(nodeCB *first, char *x){
	nodeCB *p;
	for (p = first; p!=NULL;p=p->next){
		if (strcmp(p->data.MaCB,x) == 0)
		return p;
	}
	
	return NULL;
}

void khoiTaoDanhSachVe(chuyenbay &cb, danhsachmaybay &dsmb) {
	
	
	cb.trangthai = CON_VE;
	int soday,sodong;
	soday = dsmb.data[timkiem(dsmb,cb.SHMB)]->soday;
	sodong = dsmb.data[timkiem(dsmb,cb.SHMB)]->sodong;
		
    cb.sove = soday * sodong;
    cb.dsve = new ve[cb.sove+1];

    int index = 0;
    for (char day = 'A'; day < 'A' + soday; day++) {
        for (int dong = 1; dong <= sodong; dong++) {
            sprintf(cb.dsve[index].vitri, "%c%02d", day, dong);
            strcpy(cb.dsve[index].cccd, ""); // Kh?i t?o CCCD r?ng
            index++;

        }
    }
    

}

int sovekhadung(chuyenbay &cb){
	int dem=0;
//	int index=0;
	for (int i=1; i<=cb.sove ;i++) {
		if(strcmp(cb.dsve[i-1].cccd, "")==0){
			dem++;
		}
	}
	return dem;
}


void chuyenbayquakhu(nodeCB *&first, danhsachmaybay &dsmb) {
	nodeCB *nodechay;
	   for( nodechay=first; nodechay != NULL ; nodechay = nodechay->next){
	   	 if (nodechay->data.trangthai== CON_VE || nodechay->data.trangthai==HET_VE ) {
	   	 
		if (TGquakhu(nodechay->data.time)==true) {
			nodechay->data.trangthai= HOAN_TAT;
			dsmb.data[timkiem(dsmb,nodechay->data.SHMB)]->soChuyenDaBay++;
		}
	}
	   	    
	   }
	
}

//void chuyenbayquakhu(nodeCB *&first, danhsachmaybay &dsmb) {
//	nodeCB *nodechay;
//	   for( nodechay=first; nodechay != NULL ; nodechay = nodechay->next){
//	   	 if (nodechay->data.trangthai==HUY_CHUYEN || nodechay->data.trangthai==HOAN_TAT ) {
////		if (TGquakhu(nodechay->data.time)==true) {
////			cout<<TGquakhu(nodechay->data.time);
//			nodechay->data.trangthai= CON_VE;
////			dsmb.data[timkiem(dsmb,nodechay->data.SHMB)]->soChuyenDaBay++;
////		}
//	}
//	   	    
//	   }
//	
//}


int swapTime(Time t1, Time t2) {

    if (t1.nam < t2.nam) return -1;
    if (t1.nam > t2.nam) return 1;


    if (t1.thang < t2.thang) return -1;
    if (t1.thang > t2.thang) return 1;


    if (t1.ngay < t2.ngay) return -1;
    if (t1.ngay > t2.ngay) return 1;

    return 0;
}

int tinhgio(int gio, int phut) {
	 int kt = gio*60 + phut;	
	 return kt;
}


// if (result < 0) {
//        printf("Ng?y 24/06/2024 x?y ra tru?c ng?y 24/06/2024.\n");
//    } else if (result > 0) {
//        printf("Ng?y 24/06/2024 x?y ra sau ng?y 24/06/2024.\n");
//    } else {
//        printf("Hai ng?y 24/06/2024 l? gi?ng nhau.\n");
//    }

bool KTCB12h (nodeCB *first, char *x, chuyenbay cb) {
	nodeCB *nodechay;
	for(nodechay = first; nodechay != NULL; nodechay= nodechay->next) {
		if (strcmp(nodechay->data.SHMB,x) == 0 && nodechay->data.trangthai == CON_VE ) {
			
			if (swapTime(nodechay->data.time,cb.time) > 0 ) {
				return true;
			} 
				else if (swapTime(nodechay->data.time,cb.time) == 0 )  {
					if (strcmp(nodechay->data.MaCB, cb.MaCB) != 0) {
				cout<<nodechay->data.MaCB<<endl;
				int time1 = tinhgio(nodechay->data.time.gio,nodechay->data.time.phut);
				int time2 = tinhgio(cb.time.gio,cb.time.phut);
				if (time2>time1) {
					cout<<time2-time1<<"hihi"<<endl;
					if(time2-time1 <= 12*60) {
					return false;
				}
				} else {
					cout<<time1-time2<<"hhi"<<endl;
					if(time1-time2 <= 12*60) {
					return false;
				}
		}
			
				}
					
			}
		}
	}
	return true;
}


void xoaAllCB(nodeCB *&first){
	nodeCB *nodechay = first;
    while (nodechay != NULL) {

        for (int i = 1; i < nodechay->data.sove; i++) {
            delete[] nodechay->data.dsve[i].cccd;
            delete[] nodechay->data.dsve[i].vitri;
        }
        delete[] nodechay->data.dsve;
        nodeCB *next = nodechay->next;

        delete nodechay;

        nodechay = next;
    }

    first = NULL;
}


void Save_file_chuyen_bay(nodeCB *first){

		 FILE * PTR1;
		 if ((PTR1=fopen(file_chuyen_bay,"wb"))==NULL)
		 {  	cout<<"ERROR! Khong The Mo File Chuyen Bay"<<endl;
		 		 return ;
		 }
		 
		 nodeCB *temp= first;
		 while(temp != NULL){
		 	fwrite(&(temp->data), sizeof(chuyenbay), 1, PTR1);
		 	
		 	for(int i=1 ;i <= temp->data.sove; i++){
		 		fwrite(&temp->data.dsve[i], sizeof(ve), 1, PTR1);
			 }
		 	temp= temp->next;
		 }
		 fclose(PTR1);
}

void Open_file_chuyen_bay(nodeCB *&first ){
	 FILE * PTR1;
	 chuyenbay cb;
	 if ((PTR1=fopen(file_chuyen_bay,"rb"))==NULL)
	 {  cout<<"ERROR! Khong The Mo File Chuyen Bay"<<endl;
	 	return ;
	 }	 
 
	 while(fread (&cb, sizeof (chuyenbay), 1, PTR1) != 0) {

			cb.dsve= new ve [cb.sove+1];
			for(int i=1 ; i<= cb.sove ; i++){
		  	 strcpy(cb.dsve[i].vitri, "");
            strcpy(cb.dsve[i].cccd, ""); // Kh?i t?o CCCD r?ng
		  
	       }

		 	for(int i=1 ;i <= cb.sove ; i++){
		 		fread(&cb.dsve[i], sizeof(ve), 1, PTR1);
//		 		fread(&(*cb.dsve[i]), sizeof(char[MAXLENGHT_CMND+1]), 1, PTR1);
			 }
 	   
 	   
			InsertLast(first,cb);
	}	
 fclose(PTR1);
}
////-----------------------FILE CHUYEN BAY--------------------------------------
//void Save_file_chuyen_bay(nodeCB *first){
//
//	FILE *f = fopen (file_chuyen_bay, "wb");
//	if (f==NULL) 
//	{  	cout<<"ERROR! Khong The Mo File Chuyen Bay"<<endl;
//		 		 return ;
//	}
//
//	for (nodeCB *p=first ; p!=NULL ; p=p->next)
//	 {
//	 	 chuyenbay &data = p->data; // Khai b o bi?n sv trong v ng l?p
//        fwrite(&data, sizeof(chuyenbay), 1, f);
//        fwrite(data.dsve, sizeof(ve), p->data.sove, f);
//	 }
//	  
//	fclose (f);
//}
//
//
//
//void Open_file_chuyen_bay(nodeCB *&first ){
//	FILE *f;
//	nodeCB *p;
//	chuyenbay cb;
//	if ((f=fopen(file_chuyen_bay,"rb"))==NULL)
//	{  cout<<"ERROR! Khong The Mo File Chuyen Bay"<<endl;
//	 	return ;
//	}	 
// 
//	while (first != NULL) {
//        p = first;
//        first = p->next;
//        delete p;
//    }
//
//	while (fread(&cb, sizeof(chuyenbay), 1, f) == 1) {
//        cb.dsve = new ve;
//        fread(cb.dsve, sizeof(ve), 1, f);
//        InsertLast(first, cb);
//    }
//
//    fclose(f);
//}




