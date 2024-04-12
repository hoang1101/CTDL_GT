#pragma once

#include "define.h"
#include <iostream>
#include "maybay.h"
using namespace std;

#include<math.h>
char* toChars(unsigned long long num){
	
	char* a = new char[100];
	if (num == 0)
	{
		a[0] = '0';
		a[1] = '\0';
	}
	else
	{
		int l = floor(log10(num)+1);
		a[l--] = '\0';
		while(num>0)
		{
			a[l--] = num%10+48; //to char
			num/=10;
		}
	}
	return a;
}

//////////////////////////////////// MAN HINH ////////////////////////////////////////
void setID(int id,int x1,int y1, int x2,int y2,unsigned short int ** mapID){
	
	for(int i=y1 ; i<=y2 ; i++)
		for(int j=x1; j <= x2; j++)
			mapID[i][j] = id ;
		
}

void resetMapID(unsigned short int ** mapID){
	
	setID(0,0,0,CUASO_NGANG,CUASO_DOC,mapID);

}

void resetMH(unsigned short int **mapID){
		setID(0,250,0,CUASO_NGANG,CUASO_DOC,mapID);
		
		setfillstyle(1,WHITE);	
		bar(250,0,CUASO_NGANG,CUASO_DOC);
}

void taoButton(int id, int x1, int y1, int x2, int y2, int mauChu, int mauVien, int mauBG, char text[],unsigned short int ** mapID){
	setcolor(mauVien);
	setfillstyle(1, mauBG);
	bar(x1, y1, x2, y2);
	rectangle(x1, y1, x2, y2);
		
	setcolor(mauChu);
	setbkcolor(mauBG);
	outtextxy(x1+(x2-x1-textwidth(text))/2,y1+(y2-y1-textheight(text))/2, text);
	setID(id,x1,y1,x2,y2,mapID);
}

void taoLabel(int x1, int y1, int x2, int y2, int mauChu, int mauVien, int mauBG, char text[]) {
	setcolor(mauVien);
	setfillstyle(1, mauBG);
	bar(x1, y1, x2, y2);
	rectangle(x1, y1, x2, y2);
		
	setcolor(mauChu);
	setbkcolor(mauBG);
	outtextxy(x1+(x2-x1-textwidth(text))/2,y1+(y2-y1-textheight(text))/2, text);
}

void taoEditText(int id, int x1, int y1, int x2, int y2, int mauChu, int mauVien, int mauBG, unsigned short int ** mapID ){
	setcolor(mauVien);
	setfillstyle(1, mauBG);
	bar(x1, y1, x2, y2);
	rectangle(x1, y1, x2, y2);
		
	setcolor(mauChu);
	setbkcolor(mauBG);
//	outtextxy(x1+(x2-x1-textwidth(text))/2,y1+(y2-y1-textheight(text))/2, text);
	setID(id,x1,y1,x2,y2,mapID);
}

void vemenu(unsigned short int ** mapID){

	setfillstyle(1,GRAY1);
	bar(0,0,250,770);
	
	settextstyle(10, 0, 4);
	taoLabel(0,30,249,105,BLACK,BLACK,GREEN1,"MENU");
	
	settextstyle(8,0,2);
	taoButton(ID_MAYBAY,0,150,249,225,BLACK,BLACK,GRAY,"MAY BAY",mapID);
	taoButton(ID_CHUYENBAY,0,275,249,350,BLACK,BLACK,GRAY,"CHUYEN BAY",mapID);
	taoButton(ID_VE,0,400,249,475,BLACK,BLACK,GRAY,"DAT VE",mapID);
	taoButton(ID_THONGKE,0,525,249,600,BLACK,BLACK,GRAY,"THONG KE",mapID);
	taoButton(ID_THOAT,0,650,249,725,BLACK,BLACK,GRAY,"THOAT",mapID);
}


void NhapLieu(int x, int y, int &id,unsigned short int ** mapID ,char s[]){
//	cout<<"hihi";

	int idtmp = id;
//	char temp[100]=""; // Bi?n t?m d? luu giá tr? ban d?u c?a chu?i
//	strcpy(temp, s); // Sao chép chu?i s vào bi?n temp
	char c;
	int xx,yy;
	int l=strlen(s) ;
    s[l+1]='\0';
    s[l]='|'; 
	setbkcolor(WHITE);
	setcolor(BLACK);
//	 strcpy(s, temp);
	while(true){
//			outtextxy(x,y,s);
//			    strcpy(s, temp);
			if(ismouseclick(WM_LBUTTONDOWN)){
				getmouseclick(WM_LBUTTONDOWN, xx, yy);
				idtmp = mapID[yy][xx];
				clearmouseclick(WM_LBUTTONDOWN);
	      	  } 
	      	  
	      	  if (idtmp!=id){
	      	  	id = idtmp;
//	      	  	s[l]='\0';
//	      	  	l--;
//				if(s[strlen(s)-1]==' ')
			    s[strlen(s)-1]='\0';
			  	return ;
				}
	      	  
	      	  	if(kbhit()) {
	      	  	char c= getch();
				if(c!=13) {
					s[l]=c;
					l++;
					s[l+1]='\0';
					outtextxy(x,y,s);
				} 
				else {
					s[l]='\0';// xoa dau cach o cuoi chuoi  
					return; 
					} 
				}
				else{
				s[l]='|';
				delay(100);
				outtextxy(x,y,s);
				s[l]=' ';
				delay(100);			 
				outtextxy(x,y,s);
				}	
	    }
}


////////////////////////////// MAU BAY //////////////////////////////////
void vekhungmaybay(unsigned short int ** mapID) {
	

	setfillstyle(1,WHITE);
	bar(250,0,CUASO_NGANG,CUASO_DOC);
	
	settextstyle(10, 0, 4);
	taoLabel(575,0,975,55,BLACK,BLACK,GRAY,"DANH SACH MAY BAY");
	
	settextstyle(8,0,2);
	
	rectangle(300,90,1350,490);
	line(300,130,1350,130);
	line(300+4*16,90,300+4*16,130);
	line(300+20*16,90,300+20*16,130);
	line(300+45*16,90,300+45*16,130);
	line(300+55*16,90,300+55*16,130);

//	setusercharsize(1,2,1,2);
	setbkcolor(WHITE);
	outtextxy(300+2*16-textwidth("STT")/2,100,"STT");
	outtextxy(300+12*16-textwidth("SoHieuMayBay")/2,100,"SoHieuMayBay");
	outtextxy(300+30*16-textwidth("Loai May Bay")/2,100,"Loai May Bay");
	outtextxy(300+50*16-textwidth("So Dong")/2,110,"So Dong");
	outtextxy(350+55*16+(1300-350-55*16)/2-textwidth("So Day")/2,110,"So Day");
	

	
	rectangle(300,500,1350,750);
	line(300,550,1350,550);
	taoButton(11,670,510,740,540,BLACK,BLACK,GRAY,"THEM",mapID);
	taoButton(12,790,510,860,540,BLACK,BLACK,GRAY,"XOA",mapID);
    taoButton(13,910,510,980,540,BLACK,BLACK,GRAY,"SUA",mapID);
    
    taoEditText(ED_SHMB,310,580,900,630,BLACK,BLACK,GRAY,mapID);
    taoEditText(ED_LOAIMB,310,665,900,715,BLACK,BLACK,GRAY,mapID);
    
    taoEditText(ED_SODAY,950,580,1340,630,BLACK,BLACK,GRAY,mapID);
    taoEditText(ED_SODONG,950,665,1340,715,BLACK,BLACK,GRAY,mapID);
	
}

void resetthanhchucnangmb(unsigned short int ** mapID) {
	setID(0,300,500,1350,550,mapID);
	
	setfillstyle(1,WHITE);
	bar(302,502,1349,549);
}

void taodongmb(int stt, int x, int y, int x1, int y1, maybay &mb, unsigned short int **mapID){
		setcolor(BLACK);
		settextstyle(8, 0, 0);
		setusercharsize(1,2,1,2);
		line(x,y1,x1,y1);
		line(x+4*16,y,x+4*16,y1);
		line(x+20*16,y,x+20*16,y1);
		line(x+45*16,y,x+45*16,y1);
		line(x+55*16,y,x+55*16,y1);
		
//		if(isclick)
//			setbkcolor(RED);
//		else 
			setbkcolor(WHITE);
		outtextxy(x+2*16-textwidth(toChars(stt))/2,y+10,toChars(stt));
		outtextxy(x+12*16-textwidth(mb.sohieumaybay)/2,y+10,mb.sohieumaybay);
		outtextxy(x+30*16-textwidth(mb.loaimaybay)/2,y+10,mb.loaimaybay);
		outtextxy(x+50*16-textwidth(toChars(mb.sodong))/2,y+10,toChars(mb.sodong));
		outtextxy(x+55*16+(1300-x-55*16)/2-textwidth(toChars(mb.soday))/2,y+10,toChars(mb.soday));
		settextstyle(0, 0, 2);	
	

}

void clickmb(maybay &mb,int vitri,unsigned short int **mapID){

		setfillstyle(1,BLUE);
        bar(300,130+(vitri-1)%10*30,1350,160+(vitri-1)%10*30);
        rectangle(300,130+(vitri-1)%10*30,1350,160+(vitri-1)%10*30);
        taodongmb(vitri,300,130+(vitri-1)%10*30,1350,160+(vitri-1)%10*30,mb,mapID);
        setfillstyle(1,GRAY);

    	bar(501,581,900,629);
		bar(1151,666,1280,714);
		bar(571,581,900,629);
		bar(1151,666,1280,714);
		setbkcolor(GRAY);
    	outtextxy(505,595,mb.sohieumaybay);
    	outtextxy(1155,595,toChars(mb.soday));
    	outtextxy(575,680,mb.loaimaybay);
    	outtextxy(1155,680,toChars(mb.sodong));
	        
}

void unclickmb(maybay &mb,int vitri,unsigned short int **mapID){

		setfillstyle(1,WHITE);
        bar(300,130+(vitri-1)%10*30,1350,160+(vitri-1)%10*30);
        rectangle(300,130+(vitri-1)%10*30,1350,160+(vitri-1)%10*30);
        taodongmb(vitri,300,130+(vitri-1)%10*30,1350,160+(vitri-1)%10*30,mb,mapID);
        setfillstyle(1,GRAY);
    	bar(501,581,900,629);
		bar(1151,666,1280,714);
		bar(571,581,900,629);
		bar(1151,666,1280,714);
}


void xulymaybay(unsigned short int ** mapID, int &luu_id,danhsachmaybay &dsmb){
	
	maybay mb;
	vekhungmaybay(mapID);
	char day[50]="";
	char dong[50]="";
	int idmb = 0;
	int x,y;
	int vitri =0;
	
	char ktday[50]="";
	char ktdong[50]="";
	
	
	for(int i=0; i< dsmb.soluong ;i++){
		taodongmb(i+1,300,130+i*30,1350,160+i*30,*dsmb.data[i],mapID);
		setID(1000+i,300,130+i*30,1350,160+i*30,mapID);
		mb=*dsmb.data[0];
		vitri=1;
		clickmb(mb,1,mapID);
	}
	
	
	while(true)
	
	{
		strcpy(day, ktday);
		strcpy(dong, ktdong);
		if(ismouseclick(WM_LBUTTONDOWN)){
			getmouseclick(WM_LBUTTONDOWN, x, y);
			idmb = mapID[y][x];
			clearmouseclick(WM_LBUTTONDOWN);
		}
		if (idmb<=5 && idmb>=1)//thoat ra v?o chuc nang khac
		{
			luu_id=idmb;
			break;
		}
		switch(idmb){
			case MB_THEM: 
				resetthanhchucnangmb(mapID);
				taoButton(LUU_MB,720,510,790,540,BLACK,BLACK,GRAY,"LUU",mapID);
				taoButton(HUY_MB,840,510,910,540,BLACK,BLACK,GRAY,"HUY",mapID);
				
				taoEditText(ED_SHMB,310,580,900,630,BLACK,BLACK,WHITE,mapID);
			    taoEditText(ED_LOAIMB,310,665,900,715,BLACK,BLACK,WHITE,mapID);
			    
			    taoEditText(ED_SODAY,950,580,1340,630,BLACK,BLACK,WHITE,mapID);
			    taoEditText(ED_SODONG,950,665,1340,715,BLACK,BLACK,WHITE,mapID);
				idmb=0;
			break;
			case LUU_MB: 
				resetthanhchucnangmb(mapID);
				taoButton(11,670,510,740,540,BLACK,BLACK,GRAY,"THEM",mapID);
				taoButton(12,790,510,860,540,BLACK,BLACK,GRAY,"XOA",mapID);
			    taoButton(13,910,510,980,540,BLACK,BLACK,GRAY,"SUA",mapID);
			    
			    taoEditText(ED_SHMB,310,580,900,630,BLACK,BLACK,GRAY,mapID);
			    taoEditText(ED_LOAIMB,310,665,900,715,BLACK,BLACK,GRAY,mapID);
			    
			    taoEditText(ED_SODAY,950,580,1340,630,BLACK,BLACK,GRAY,mapID);
			    taoEditText(ED_SODONG,950,665,1340,715,BLACK,BLACK,GRAY,mapID);
			    idmb=0;
			break;			
			
			case HUY_MB:
				resetthanhchucnangmb(mapID);
				taoButton(11,670,510,740,540,BLACK,BLACK,GRAY,"THEM",mapID);
				taoButton(12,790,510,860,540,BLACK,BLACK,GRAY,"XOA",mapID);
			    taoButton(13,910,510,980,540,BLACK,BLACK,GRAY,"SUA",mapID);
			    
			 
			    idmb=0;
			break;
			
			case MB_XOA:
				break;
			case ED_SHMB:
//				outtextxy(315,595,"hihi");
//				NhapLieu(315,595,ED_SHMB,mapID,s)
				break;
			case ED_LOAIMB:
				outtextxy(315,680,"hihi");
				break;
			case ED_SODAY:
				idmb = ED_SODAY;
				NhapLieu(955,595,idmb,mapID,day);
				cout<<day<<endl;
//				taoEditText(ED_SHMB,310,580,900,630,BLACK,BLACK,GRAY,mapID);
//			    taoEditText(ED_LOAIMB,310,665,900,715,BLACK,BLACK,GRAY,mapID);
//			    
//			    taoEditText(ED_SODAY,950,580,1340,630,BLACK,BLACK,GRAY,mapID);
//			    taoEditText(ED_SODONG,950,665,1340,715,BLACK,BLACK,GRAY,mapID);
				break;
			case ED_SODONG:
//				outtextxy(955,680,"hihi");
				idmb = ED_SODONG;
				NhapLieu(955,680,idmb,mapID,dong);
				cout<<dong<<endl;
//				taoEditText(ED_SHMB,310,580,900,630,BLACK,BLACK,GRAY,mapID);
//			    taoEditText(ED_LOAIMB,310,665,900,715,BLACK,BLACK,GRAY,mapID);
//			    
//			    taoEditText(ED_SODAY,950,580,1340,630,BLACK,BLACK,GRAY,mapID);
//			    taoEditText(ED_SODONG,950,665,1340,715,BLACK,BLACK,GRAY,mapID);				
				break;
			case 1000:case 1001:case  1002 :case 1003: case 1004 :case 1005: case 1006 :case 1007: case 1008: case 1009:
	        	
							cout<<vitri;
							unclickmb(mb,vitri,mapID);
							vitri = idmb-1000+1;
							mb=*dsmb.data[idmb-1000];
				        	clickmb(mb,vitri,mapID);
				        	cout<<"+>"<<"haha"<<vitri;
				        	
							idmb = 0;
				        	break;

		}
		delay(0.001);
	}
}


////////////////////////////////// CHUYEN BAY /////////////////////////////////
void vekhungchuyenbay(unsigned short int ** mapID) {
	

	setfillstyle(1,WHITE);
	bar(250,0,CUASO_NGANG,CUASO_DOC);
	
	settextstyle(10, 0, 4);
	taoLabel(575,0,975,55,BLACK,BLACK,GRAY,"DANH SACH CHUYEN BAY");
	
	
	
	

}
void xulychuyenbay(unsigned short int ** mapID, int &luu_id) {
	
	vekhungchuyenbay(mapID);
	
	int idcb = 0;
	int x,y;
	
	
	
	while(true)
	{
		if(ismouseclick(WM_LBUTTONDOWN)){
			getmouseclick(WM_LBUTTONDOWN, x, y);
			idcb = mapID[y][x];
			clearmouseclick(WM_LBUTTONDOWN);
		}
		if (idcb<=5 && idcb>=1)//thoat ra v?o chuc nang khac
		{
			luu_id=idcb;
			break;
		}
		switch(idcb){
			
		}
		delay(0.001);
	}
}

////////////////////////////////// VE /////////////////////////////////
void vekhungve(unsigned short int ** mapID) {
	

	setfillstyle(1,WHITE);
	bar(250,0,CUASO_NGANG,CUASO_DOC);
	
	settextstyle(10, 0, 4);
	taoLabel(575,0,975,55,BLACK,BLACK,GRAY,"DANH SACH VE");
	
	
	
	

}
void xulyve(unsigned short int ** mapID, int &luu_id) {
	
	vekhungve(mapID);
	
	int idv = 0;
	int x,y;
	
	
	
	while(true)
	{
		if(ismouseclick(WM_LBUTTONDOWN)){
			getmouseclick(WM_LBUTTONDOWN, x, y);
			idv = mapID[y][x];
			clearmouseclick(WM_LBUTTONDOWN);
		}
		if (idv<=5 && idv>=1)//thoat ra v?o chuc nang khac
		{
			luu_id=idv;
			break;
		}
		switch(idv){
			
		}
		delay(0.001);
	}
}

////////////////////////////////// THONG KE /////////////////////////////////
void vekhungthongke(unsigned short int ** mapID) {
	

	setfillstyle(1,WHITE);
	bar(250,0,CUASO_NGANG,CUASO_DOC);
	
	settextstyle(10, 0, 4);
	taoLabel(575,0,975,55,BLACK,BLACK,GRAY,"DANH SACH THONG KE");
	
	
	
	

}
void xulythongke(unsigned short int ** mapID, int &luu_id) {

	vekhungthongke(mapID);
	
	int idtk = 0;
	int x,y;
	
	
	
	while(true)
	{
		if(ismouseclick(WM_LBUTTONDOWN)){
			getmouseclick(WM_LBUTTONDOWN, x, y);
			idtk = mapID[y][x];
			clearmouseclick(WM_LBUTTONDOWN);
		}
		if (idtk<=5 && idtk>=1)//thoat ra v?o chuc nang khac
		{
			luu_id=idtk;
			break;
		}
		switch(idtk){
			
		}
		delay(0.001);
	}
}


