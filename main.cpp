

#include <winbgim.h> 
#include <iostream>
#include "define.h"
#include "xuly.h"
#include "maybay.h"
#include "chuyenbay.h"
using namespace std;
main(int argc, char *argv[])
{
	
		
    unsigned short int **mapID = new unsigned short int *[CUASO_DOC];
	for(int i=0;i<= CUASO_DOC;i++)
	 	mapID[i]= new unsigned short int[CUASO_NGANG];
	 	
	danhsachmaybay dsmb;
	nodeCB *first = NULL;
    Node* root = NULL;

	Open_file_MB(dsmb);
	Open_file_chuyen_bay(first);
	Openfilekhachhang(root);
	
	Save_file_chuyen_bay(first);

	
	
	initwindow(CUASO_NGANG,CUASO_DOC);					// init window graphics
	setwindowtitle("Quan Li May Bay");	
	setbkcolor(WHITE);							// set background
   	cleardevice();
   	setfillstyle(1,WHITE);
   	bar(0,0,CUASO_NGANG,CUASO_DOC);
	settextstyle(8,0,2);
	vemenu(mapID);
	
	int id=0;
	int x,y;
	while (true) {
	    if (ismouseclick(WM_LBUTTONDOWN)) {
	        getmouseclick(WM_LBUTTONDOWN, x, y);
	        id = mapID[y][x];
	        clearmouseclick(WM_LBUTTONDOWN);
	    }
	    switch (id) {
	       case ID_MAYBAY: 
//				cout<<1;
				resetMapID(mapID);
				resetMH(mapID);
				vemenu(mapID);
				taoButton(ID_MAYBAY,0,150,249,225,BLACK,BLACK,WHITE,"MAY BAY",mapID);
				xulymaybay(mapID,id,dsmb,first);
				settextstyle(8,0,2);
			break;
			case ID_CHUYENBAY: 
//				cout<<2;
				resetMapID(mapID);
				resetMH(mapID);
				vemenu(mapID);
				taoButton(ID_CHUYENBAY,0,275,249,350,BLACK,BLACK,WHITE,"CHUYEN BAY",mapID);
				xulychuyenbay(mapID,id,first,dsmb);
				settextstyle(8,0,2);
			break;
	        case ID_VE:
	        	if (Empty(dsmb)) {
						MessageBox(NULL, "\n                     ERROR!	\n  Hien Chua Co may Nao Trong Danh Sach !", "THONG BAO", MB_ICONERROR | MB_OK);
							id=ID_MAYBAY;
							break;
					
				}else if (dsCBEmpty(first)) {
					MessageBox(NULL, "\n                     ERROR!	\n  Hien Chua Co Chuyen bay Nao Trong Danh Sach !", "THONG BAO", MB_ICONERROR | MB_OK);
					id=ID_CHUYENBAY;
					break;
				}else{
					kiemtra_thoigian_khoihanh_all(first, dsmb);
					Save_file_chuyen_bay(first);
					Save_file_MB(dsmb);
					resetMapID(mapID);
	                resetMH(mapID);
	                vemenu(mapID);
	                taoButton(ID_VE, 0, 400, 249, 475, BLACK, BLACK, WHITE, "DAT VE", mapID);
	                xulychuyenbayconkhadung(mapID,id,first,dsmb, root);
//	                if (first != NULL) {
//	                    xulyve(mapID, id, first->next->data ,dsmb);
//	                }
	                settextstyle(8, 0, 2);
//	                id=0;
	                break;
					
				}
	        case ID_THONGKE:
	            resetMapID(mapID);
	            resetMH(mapID);
	            vemenu(mapID);
	            taoButton(ID_THONGKE,0,525,249,600,BLACK,BLACK,WHITE,"THONG KE",mapID);
	            	        	if (Empty(dsmb)) {
						MessageBox(NULL, "\n                     ERROR!	\n  Hien Chua Co may Nao Trong Danh Sach !", "THONG BAO", MB_ICONERROR | MB_OK);
							id=ID_MAYBAY;
							break;
					
				}else if (dsCBEmpty(first)) {
					MessageBox(NULL, "\n                     ERROR!	\n  Hien Chua Co Chuyen bay Nao Trong Danh Sach !", "THONG BAO", MB_ICONERROR | MB_OK);
					id=ID_CHUYENBAY;
					break;
				}else{
					kiemtra_thoigian_khoihanh_all(first, dsmb);
					Save_file_chuyen_bay(first);
					Save_file_MB(dsmb);
					resetMapID(mapID);
	                resetMH(mapID);
	                vemenu(mapID);
	            	sapXepMayBayBubbleSort(dsmb);


    				xulythongke( mapID,id,dsmb);
	                settextstyle(8, 0, 2);
	                break;
					
				}
	            break;
	        case ID_THOAT:
	            resetMapID(mapID);
	            resetMH(mapID);
	            vemenu(mapID);
	            taoButton(ID_THOAT, 0, 775, 249, 850, BLACK, BLACK, RED, "THOAT", mapID);
	            if (MessageBox(NULL, "\n   [ Xac Nhan Thoat Chuong Trinh]   \n", "THONG BAO", MB_ICONWARNING | MB_OKCANCEL) == IDCANCEL) {
	                resetMapID(mapID);
	                resetMH(mapID);
	                vemenu(mapID);
	                id = 0;
	            } else {
	                exit(0);
	                return 0;
	            }
	            break;
	    }
	    delay(0.001);
	}

	while(!kbhit()) delay(1);	
	return 0;			// pause screen	
}

