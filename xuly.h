#pragma once
#include <winbgim.h> 
#include "define.h"
#include <cctype>
#include <iostream>
#include "maybay.h"
#include "chuyenbay.h"
#include "khachhang.h"
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


char* tocharDate(Time &time)
{
	char *temp = new char[100];
	temp[0] = '\0';
	
	if (time.ngay < 10)  
	 	strcat(temp, "0");
	 	
	strcat(temp, toChars(time.ngay));
	strcat(temp, "/");
	
	if (time.thang < 10) 
		strcat(temp, "0");
		
	strcat(temp, toChars(time.thang));
	strcat(temp, "/");
	
	if (time.nam < 10)
		strcat(temp, "0");
	if (time.nam < 100)
		strcat(temp, "0");
	if (time.nam < 1000)
		strcat(temp, "0");
	strcat(temp, toChars(time.nam));
	
	strcat(temp, " ");
	if (time.gio < 10)  
	 	strcat(temp, "0");
	 	
	strcat(temp, toChars(time.gio));
	strcat(temp, ":");
	
	if (time.phut < 10)  
	 	strcat(temp, "0");
	 	
	strcat(temp, toChars(time.phut));
	return temp;
}
unsigned long long ChangeCharToNum (char str[]){
	
	unsigned long long n = 0;
	for(int i = 0; i<strlen(str); i++){
		
		n = n * 10;
		n += (str[i]-48);
	}
	return n;
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


void resetmb(maybay &mb){
	mb.sohieumaybay[0]='\0';
	mb.loaimaybay[0] = '\0';
	mb.soChuyenDaBay = 0;
	mb.soday = 0;
	mb.sodong = 0;
}

void resetcb(chuyenbay &cb) {
	cb.MaCB[0] = '\0';
	cb.SanBayDen[0] = '\0';
	cb.SHMB[0] = '\0';
	cb.trangthai = CON_VE;
	cb.time = time_now();
}

void resetkhungds(unsigned short int **mapID){
	
	setID(0,300,100,1350,440,mapID);
	setfillstyle(1,WHITE);
//	setcolor(BLACK);
	bar(300,100,1350,495);
			
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
	taoLabel(0,30,249,105,BLACK,BLACK,2,"MENU");
	
	settextstyle(8,0,2);
 	taoButton(ID_MAYBAY, 0, 150, 249, 225, BLACK, BLACK, GRAY, "MAY BAY", mapID);
    taoButton(ID_CHUYENBAY, 0, 275, 249, 350, BLACK, BLACK, GRAY, "CHUYEN BAY", mapID);
    taoButton(ID_VE, 0, 400, 249, 475, BLACK, BLACK, GRAY, "DAT VE", mapID);
    taoButton(ID_KHACHHANG, 0, 525, 249, 600, BLACK, BLACK, GRAY, "KHACH HANG", mapID);
    taoButton(ID_THONGKE, 0, 650, 249, 725, BLACK, BLACK, GRAY, "THONG KE", mapID);
    taoButton(ID_THOAT, 0, 775, 249, 850, BLACK, BLACK, GRAY, "THOAT", mapID);
}

int checkNhapLieu(char c, char s[]){
	if(strlen(s) == 0 && c == ' ') // Khoa Phim Cach Nhap Vao Chuoi Rong
		return 0;
	else if(strlen(s) != 0 && s[strlen(s)-1] == ' ' && c == ' ') //Khoa Nhap 2 Phim Cach Lien Tiep
			return 0;		
	return 1;	 
}

void Nhap(int x, int y,char c, char *s ) {
	if (checkNhapLieu(c,s) == 1) 
		strncat(s,&c,1);
		outtextxy(x,y,s);
}


void NhapLieu(int x, int y, int &id,unsigned short int ** mapID ,char s[]){
	int idtmp = id;
	char c;
	int xx,yy;
	setbkcolor(WHITE);
	setcolor(BLACK);
	while(true){
			if(ismouseclick(WM_LBUTTONDOWN)){
				getmouseclick(WM_LBUTTONDOWN, xx, yy);
				idtmp = mapID[yy][xx];
				clearmouseclick(WM_LBUTTONDOWN);
	      	  } 
	      	  
	      	  if (idtmp!=id){
	      	  	id = idtmp;
			    if(s[strlen(s)-1]==' ')
			    	s[strlen(s)-1]='\0';
			  	return ;
				}
	      	  	if(kbhit()) {
	      	  	char c= getch();
				if(c!=13 ) {
				
					if(c==8 && strlen(s) != 0)
					{
							outtextxy(x+textwidth(s),y," ");
							s[strlen(s)-1] = '\0';
					} else if( ('0'<=c&&c<='9')||(c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z' ) || (c == ' ')) {
					Nhap(x,y,c,s);		
					}
				}
				else {
					s[strlen(s)]='\0';// xoa dau cach o cuoi chuoi  
					return; 
					} 
				}
				else{
				outtextxy(x+textwidth(s),y,"|");
				delay(100);
				outtextxy(x+textwidth(s),y," ");
				delay(100);
				}	
}
}


void NhapLieuNoSpace(int x, int y, int &id,unsigned short int ** mapID ,char s[]){
	int idtmp = id;
	char c;
	int xx,yy;
	int l=strlen(s) ;
	s[l+1]='\0';
    s[l]='|'; 
	setbkcolor(WHITE);
	setcolor(BLACK);
	while(true){
			if(ismouseclick(WM_LBUTTONDOWN)){
				getmouseclick(WM_LBUTTONDOWN, xx, yy);
				idtmp = mapID[yy][xx];
				clearmouseclick(WM_LBUTTONDOWN);
	      	  } 
	      	  
	      	  if (idtmp!=id){
	      	  	id = idtmp;
//	      	  	s[l]='\0';
			    if(s[strlen(s)-1]==' ')
			    	s[strlen(s)-1]='\0';
			  	return ;
				}
	      	  	if(kbhit()) {
	      	  	char c= getch();
				if(c!=13 ) {
					if(c==8 && strlen(s) != 0)
					{
							outtextxy(x+textwidth(s),y," ");
							s[strlen(s)-1] = '\0';
					} else if( ('0'<=c&&c<='9')||(c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z' ) || (c != ' ')) {
					Nhap(x,y,c,s);		
					}
				}
				else {
					s[strlen(s)]='\0';// xoa dau cach o cuoi chuoi  
					return; 
					} 
				}
				else{
				outtextxy(x+textwidth(s),y,"|");
				delay(100);
				outtextxy(x+textwidth(s),y," ");
				delay(100);
				}	
}
}

void NhapLieuHoaThuong(int x, int y, int &id, unsigned short int **mapID, char s[]) {
    int idtmp = id;
    char c;
    int xx, yy;
    setbkcolor(WHITE);
    setcolor(BLACK);
    while (true) {
        if (ismouseclick(WM_LBUTTONDOWN)) {
            getmouseclick(WM_LBUTTONDOWN, xx, yy);
            idtmp = mapID[yy][xx];
            clearmouseclick(WM_LBUTTONDOWN);
        }

        if (idtmp != id) {
            id = idtmp;
            if (s[strlen(s) - 1] == ' ') {
                s[strlen(s) - 1] = '\0';
            }
            return;
    	}
        	if(kbhit()) {
	      	  	char c= getch();
				if(c!=13 ) {
				
					if(c==8 && strlen(s) != 0)
					{
							outtextxy(x+textwidth(s),y," ");
							s[strlen(s)-1] = '\0';
					} else if( ('0'<=c&&c<='9')||(c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z' ) || (c == ' ')) {
						
						if((strlen(s) != 0 && s[strlen(s)-1] == ' ' && c != ' ') || (strlen(s) == 0 && c != ' ')) {
							c =  toupper(c);
						}
					Nhap(x,y,c,s);		
					}
				}
				else {
					s[strlen(s)]='\0';// xoa dau cach o cuoi chuoi  
					return; 
				} 
			}
		else{
            outtextxy(x + textwidth(s), y, "|");
            delay(100);
            outtextxy(x + textwidth(s), y, " ");
            delay(100);
        }
    }
}


void NhapLieuInHoa(int x, int y, int &id,unsigned short int ** mapID ,char s[], int chieudai){
	int idtmp = id;
	char c;
	int xx,yy;
	int l=strlen(s) ;
//	
    s[l+1]='\0';
    s[l]='|'; 
	setbkcolor(WHITE);
	setcolor(BLACK);

	while(true){
			if(ismouseclick(WM_LBUTTONDOWN)){
				getmouseclick(WM_LBUTTONDOWN, xx, yy);
				idtmp = mapID[yy][xx];
				clearmouseclick(WM_LBUTTONDOWN);
	      	  } 
	      	  
	      	  if (idtmp!=id){
	      	  	id = idtmp;
			    s[l]='\0';
			  	return ;
				}
	      	  
	      	  	if(kbhit()) {
	      	  	char c= getch();
	      	  	if(c==8){ // bat phim backspace
				if(l>0)
				{
					s[l-1]='\0';
					s[l]=' ';
					outtextxy(x,y,s);
					l--;	
				}	
				} 
				else if (l<chieudai ){
					if(c!=13 && c>='a' && c<='z' )  {
					c=c-32;
					s[l]=c;
					l++;
					s[l+1]='\0';
					outtextxy(x,y,s);
				}  else if ('0'<=c&&c<='9' || c>='A' && c<='Z') {
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



void Nhapso(int x, int y ,int &luu_id,unsigned short int ** mapID, char s[],int chieudai)
{
	int x1=x;
	int y1=y;
	setbkcolor(WHITE);
	setcolor(BLACK);
	int l=strlen(s) ;
//	s[l+1]='\0';
//    s[l]='|'; 
	int id=luu_id;
    while(1){
       	
		outtextxy(x,y,s);
		
		if(ismouseclick(WM_LBUTTONDOWN)){
			getmouseclick(WM_LBUTTONDOWN, x, y);
			id = mapID[y][x];
			clearmouseclick(WM_LBUTTONDOWN);
		}
		if(id!=luu_id)
		{
			luu_id=id;
			s[l]='\0';
			return;
		}
		else
		{
			x=x1;
			y=y1;
		}
     	if(kbhit()){
	     	char c= getch();
	     	if(l<chieudai && '0'<=c&&c<='9' ) 
			{
		     	s[l]=c;
				l++;
				s[l+1]='\0';
				outtextxy(x,y,s);
			}
			else if(c==8){ // bat phim backspace
				if(l>0)
				{
					s[l-1]='\0';
					s[l]=' ';
					outtextxy(x,y,s);
					l--;	
				}	
			} 
			else if(c==13) {
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
//			Chuan_Hoa(s); 			 
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
	
	rectangle(300,90,1350,430);
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
	outtextxy(300+50*16-textwidth("So Dong")/2,100,"So Dong");
	outtextxy(300+55*16+(1350-300-55*16)/2-textwidth("So Day")/2,100,"So Day");
	

//	settextstyle(8,0,2);
	
	
}

void vekhungnhaplieu(unsigned short int ** mapID) {
	settextstyle(10, 0, 2);	
	rectangle(300,500,1350,750);
	line(300,550,1350,550);
	taoButton(MB_THEM,670,510,740,540,BLACK,BLACK,GRAY,"THEM",mapID);
	taoButton(MB_XOA,790,510,860,540,BLACK,BLACK,GRAY,"XOA",mapID);
    taoButton(MB_SUA,910,510,980,540,BLACK,BLACK,GRAY,"SUA",mapID);
    
    taoLabel(310,580,500,630,BLACK,BLACK,GRAY,"So hieu MB");
    taoLabel(310,665,570,715,BLACK,BLACK,GRAY,"Loai may bay");
    taoLabel(950,580,1150,630,BLACK,BLACK,GRAY,"So day");
    taoLabel(950,665,1150,715,BLACK,BLACK,GRAY,"So dong");
    taoEditText(0,500,580,900,630,BLACK,BLACK,GRAY,mapID);
    taoEditText(0,570,665,900,715,BLACK,BLACK,GRAY,mapID);
    
    taoEditText(0,1150,580,1340,630,BLACK,BLACK,GRAY,mapID);
    taoEditText(0,1150,665,1340,715,BLACK,BLACK,GRAY,mapID);
}

void resetthanhchucnangmb(unsigned short int ** mapID) {
	setID(0,300,500,1350,550,mapID);
	
	setfillstyle(1,WHITE);
	bar(302,502,1349,549);
}

void taodongmb(int stt, int x, int y, int x1, int y1, maybay &mb, unsigned short int **mapID,int bgcl){
		setcolor(BLACK);
		settextstyle(8, 0, 0);
		setusercharsize(1,2,1,2);
		line(x,y1,x1,y1);
		line(x+4*16,y,x+4*16,y1);
		line(x+20*16,y,x+20*16,y1);
		line(x+45*16,y,x+45*16,y1);
		line(x+55*16,y,x+55*16,y1);
		
		if(bgcl<15)
			setbkcolor(bgcl);
		else 
		setbkcolor(WHITE);
		outtextxy(x+2*16-textwidth(toChars(stt))/2,y+10,toChars(stt));
		outtextxy(x+12*16-textwidth(mb.sohieumaybay)/2,y+10,mb.sohieumaybay);
		outtextxy(x+30*16-textwidth(mb.loaimaybay)/2,y+10,mb.loaimaybay);
		outtextxy(x+50*16-textwidth(toChars(mb.sodong))/2,y+10,toChars(mb.sodong));
		outtextxy(x+58*16+(1300-x-58*16)/2-textwidth(toChars(mb.soday))/2,y+10,toChars(mb.soday));
		settextstyle(0, 0, 2);	
	

}

void clickmb(maybay &mb,int vitri,unsigned short int **mapID){

		setfillstyle(1,YELLOW);
        bar(300,130+(vitri-1)%10*30,1350,160+(vitri-1)%10*30);
        rectangle(300,130+(vitri-1)%10*30,1350,160+(vitri-1)%10*30);
//        setbkcolor(BLUE);
        taodongmb(vitri,300,130+(vitri-1)%10*30,1350,160+(vitri-1)%10*30,mb,mapID,YELLOW);
        setfillstyle(1,GRAY);
    	bar(501,581,900,630);
		bar(1151,581,1340,630);
		bar(571,666,900,715);
		bar(1151,666,1340,715);
		setbkcolor(GRAY);
    	outtextxy(505,595,mb.sohieumaybay);
    	outtextxy(1155,595,toChars(mb.soday));
    	outtextxy(575,680,mb.loaimaybay);
    	outtextxy(1155,680,toChars(mb.sodong));
	        
}

void movembfindmb(maybay &mb,int vitri,unsigned short int **mapID){

		setfillstyle(1,YELLOW);
        bar(300,130+(vitri-1)%10*30,1350,160+(vitri-1)%10*30);
        rectangle(300,130+(vitri-1)%10*30,1350,160+(vitri-1)%10*30);
        taodongmb(vitri,300,130+(vitri-1)%10*30,1350,160+(vitri-1)%10*30,mb,mapID,YELLOW);
        setfillstyle(1,GRAY);        
}

void unclickmbfind(maybay &mb,int vitri,unsigned short int **mapID){
		setfillstyle(1,WHITE);
        bar(300,130+(vitri-1)%10*30,1350,160+(vitri-1)%10*30);
        rectangle(300,130+(vitri-1)%10*30,1350,160+(vitri-1)%10*30);
        taodongmb(vitri,300,130+(vitri-1)%10*30,1350,160+(vitri-1)%10*30,mb,mapID,15);
        
}

void unclickmb(maybay &mb,int vitri,unsigned short int **mapID){
		setfillstyle(1,WHITE);
        bar(300,130+(vitri-1)%10*30,1350,160+(vitri-1)%10*30);
        rectangle(300,130+(vitri-1)%10*30,1350,160+(vitri-1)%10*30);
        taodongmb(vitri,300,130+(vitri-1)%10*30,1350,160+(vitri-1)%10*30,mb,mapID,15);
        setfillstyle(1,GRAY);
    	bar(501,581,900,629);
		bar(1151,581,1280,629);
		bar(571,666,900,714);
		bar(1151,666,1280,714);
}


void xulymaybay(unsigned short int ** mapID, int &luu_id,danhsachmaybay &dsmb, nodeCB *first){
	
	maybay mb;
	resetmb(mb);
	int tranghientai = 1;
	int trangcuoi = ceil(dsmb.soluong/10.0);
	char day[50]="";
	char dong[50]="";
	int idmb = 0;
	int x,y;
	int vitri =0;
	int kt=0;
	
	vekhungmaybay(mapID);
	vekhungnhaplieu(mapID);
	
	if (Empty(dsmb)) {
		outtextxy(825-strlen("! DANH SACH TRONG !")*4,135,"! DANH SACH TRONG !");
		
	   	taoButton(0,790,510,860,540,BLACK,BLACK,GRAY,"XOA",mapID);
    	taoButton(0,910,510,980,540,BLACK,BLACK,GRAY,"SUA",mapID);

	} else {
		for(int i=0; i< dsmb.soluong && i < 10 ;i++){
		taodongmb(i+1,300,130+i*30,1350,160+i*30,*dsmb.data[i],mapID,15);
		setID(1000+i,300,130+i*30,1350,160+i*30,mapID);
		mb=*dsmb.data[0];
		vitri=1;
		clickmb(mb,1,mapID);
		}
	}
	if (tranghientai < trangcuoi) {
		taoButton(NEXT_PAGE,1175,450,1350,480,BLACK,BLACK,GRAY,"NEXT PAGE",mapID);
	} else
	taoLabel(1175,450,1350,480,BLACK,BLACK,WHITE,"NEXT PAGE");
	taoLabel(300,450,475,480,BLACK,BLACK,WHITE,"BACK PAGE");
	while(true)
	{
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
				kt=1;
				if (FullDS(dsmb)) {
					MessageBox(NULL,"So luong may bay vuot qua gioi han cho phep !","ERROR!",MB_ICONWARNING|MB_OK);
				}
				else {
				unclickmb(mb,vitri,mapID);
				resetmb(mb);
				resetthanhchucnangmb(mapID);
				day[0]='\0';
				dong[0]='\0';
				taoButton(LUU_MB,720,510,790,540,BLACK,BLACK,GREEN,"LUU",mapID);
				taoButton(HUY_MB,840,510,910,540,BLACK,BLACK,RED,"HUY",mapID);
				
				taoEditText(ED_SHMB,500,580,900,630,BLACK,BLACK,WHITE,mapID);
			    taoEditText(ED_LOAIMB,570,665,900,715,BLACK,BLACK,WHITE,mapID);
			    taoEditText(ED_SODAY,1150,580,1340,630,BLACK,BLACK,WHITE,mapID);
			    taoEditText(ED_SODONG,1150,665,1340,715,BLACK,BLACK,WHITE,mapID);
				}
				idmb=0;
			break;
			case LUU_MB: 
				kt=0;
				add_may_bay(dsmb,mb);
				Save_file_MB(dsmb);
			 	if((dsmb.soluong % 10 == 1)) {
						trangcuoi++;
						  if(trangcuoi-tranghientai == 1 )
					        taoButton(NEXT_PAGE,1175,450,1350,480,BLACK,BLACK,GRAY,"NEXT PAGE",mapID);
					  }
					  if(tranghientai==trangcuoi ){
						if((dsmb.soluong==1) || (dsmb.soluong % 10 != 1)){
							vitri=dsmb.soluong ;
					     taodongmb(vitri,300,130+(vitri-1)%10*30,1350,160+(vitri-1)%10*30,*dsmb.data[vitri-1],mapID,15);
					     setID(1000+(vitri-1)%10,300,130+(vitri-1)%10*30,1350,160+(vitri-1)%10*30,mapID);
						}
						clickmb(mb,vitri,mapID);
				   	}
					else{
						mb = *dsmb.data[(tranghientai-1)*10];
						vitri=(tranghientai-1)*10+1;
						clickmb(mb,vitri,mapID);	
					}
				resetmb(mb);
				resetthanhchucnangmb(mapID);
				taoButton(11,670,510,740,540,BLACK,BLACK,GRAY,"THEM",mapID);
				taoButton(12,790,510,860,540,BLACK,BLACK,GRAY,"XOA",mapID);
			    taoButton(13,910,510,980,540,BLACK,BLACK,GRAY,"SUA",mapID);
			    
			    idmb=0;
			break;		
			
			case MB_SUA:
				kt=1;
				resetthanhchucnangmb(mapID);
				taoButton(LUU_MBEDIT,720,510,790,540,BLACK,BLACK,GREEN,"LUU",mapID);
				taoButton(HUY_MBEDIT,840,510,910,540,BLACK,BLACK,RED,"HUY",mapID);
				
				taoEditText(ED_SHMB,500,580,900,630,BLACK,BLACK,WHITE,mapID);
				setbkcolor(WHITE);
	        	outtextxy(505,595,mb.sohieumaybay);
				
			    taoEditText(ED_LOAIMB,570,665,900,715,BLACK,BLACK,WHITE,mapID);
			    setbkcolor(WHITE);
	        	outtextxy(575,680,mb.loaimaybay);
			    
			    strcpy(day,toChars(mb.soday));
			    taoEditText(ED_SODAY,1150,580,1340,630,BLACK,BLACK,WHITE,mapID);
			    setbkcolor(WHITE);
	        	outtextxy(1155,595,toChars(mb.soday));
	        	
				strcpy(dong,toChars(mb.sodong));
			    taoEditText(ED_SODONG,1150,665,1340,715,BLACK,BLACK,WHITE,mapID);
				setbkcolor(WHITE);
	        	outtextxy(1155,680,toChars(mb.sodong));
				idmb=0;
				break;
			
			case HUY_MB:
				kt=0;
				resetthanhchucnangmb(mapID);
				taoButton(11,670,510,740,540,BLACK,BLACK,GRAY,"THEM",mapID);
				taoButton(12,790,510,860,540,BLACK,BLACK,GRAY,"XOA",mapID);
			    taoButton(13,910,510,980,540,BLACK,BLACK,GRAY,"SUA",mapID);
			 	vekhungnhaplieu(mapID);
			 	mb = *dsmb.data[(tranghientai-1)*10];
					vitri=(tranghientai-1)*10+1;
					clickmb(mb,vitri,mapID);
			    idmb=0;
			break;
			
			case HUY_MBEDIT:
				kt=0;
				resetthanhchucnangmb(mapID);
				
				taoButton(11,670,510,740,540,BLACK,BLACK,GRAY,"THEM",mapID);
				taoButton(12,790,510,860,540,BLACK,BLACK,GRAY,"XOA",mapID);
			    taoButton(13,910,510,980,540,BLACK,BLACK,GRAY,"SUA",mapID);
			 		
			 	vekhungnhaplieu(mapID);
			 	mb = *dsmb.data[(vitri-1)];
			 	clickmb(mb,vitri,mapID);
			    idmb=0;
			break;
			
			case LUU_MBEDIT: 
			kt=0;
				edit_mb(dsmb,vitri -1,mb);
				clickmb(mb,vitri,mapID);

				Save_file_MB(dsmb);
				
				resetthanhchucnangmb(mapID);
				taoButton(11,670,510,740,540,BLACK,BLACK,GRAY,"THEM",mapID);
				taoButton(12,790,510,860,540,BLACK,BLACK,GRAY,"XOA",mapID);
			    taoButton(13,910,510,980,540,BLACK,BLACK,GRAY,"SUA",mapID);
			    
			    setID(0,500,580,900,630,mapID);
			    setID(0,570,665,900,715,mapID);
			    
			    setID(0,1150,580,1340,630,mapID);
			    setID(0,1150,665,1340,715,mapID);
			    idmb=0;
			break;
			case MB_XOA:
				if (timkiemmaybay(first,mb.sohieumaybay) == NULL) {
					MessageBox(NULL,"May Bay Da Thuc Hien Bay Khong The Xoa !","THONG BAO",MB_ICONWARNING|MB_OK);
				}
				
				else if (MessageBox(NULL,"Xac Nhan Xoa ","THONG BAO",MB_ICONWARNING|MB_OKCANCEL) == IDOK){
					delete_mb(dsmb,vitri-1);
					Save_file_MB(dsmb);
					setfillstyle(1,WHITE);
		        	bar(301,131+(vitri-1) % 10*30,1350,430);
		        	setcolor(BLUE);
		        	for(int i=(vitri-1)%10; i+(tranghientai-1)*10 < dsmb.soluong && i < 10 ;i++ )
		     		   taodongmb(i+1+(tranghientai-1)*10,300,130+i*30,1350,160+i*30,*dsmb.data[i+(tranghientai-1)*10],mapID,15);
				
				setcolor(BLACK);
				if( dsmb.soluong % 10 == 0){
		     			trangcuoi--;
		     			if(Empty(dsmb) ){
		     				setbkcolor(WHITE);
		     				outtextxy(825-strlen("! DANH SACH TRONG !")*4,135,"! DANH SACH TRONG !");
		     			  	taoButton(LUU_MB,720,510,790,540,BLACK,BLACK,GRAY,"LUU",mapID);
							taoButton(HUY_MB,840,510,910,540,BLACK,BLACK,GRAY,"HUY",mapID);
							
							taoEditText(ED_SHMB,500,580,900,630,BLACK,BLACK,WHITE,mapID);
						    taoEditText(ED_LOAIMB,570,665,900,715,BLACK,BLACK,WHITE,mapID);
						    taoEditText(ED_SODAY,1150,580,1340,630,BLACK,BLACK,WHITE,mapID);
						    taoEditText(ED_SODONG,1150,665,1340,715,BLACK,BLACK,WHITE,mapID);
						    setID(0,300,130,1350,160,mapID);
		     				resetmb(mb);
						 }
		     			else {
		     					if(trangcuoi < tranghientai){
		     						setfillstyle(1,WHITE);
									bar(300,130,1350,430);
									rectangle(300,130,1350,430);
									
									if (tranghientai=trangcuoi){
										taoButton(0,1175,450,1350,480,BLACK,BLACK,WHITE,"NEXT PAGE",mapID);
										taoButton(0,300,450,475,480,BLACK,BLACK,WHITE,"BACK PAGE",mapID);
										for(int i=0; i< dsmb.soluong && i < 10 ;i++){
										taodongmb(i+1,300,130+i*30,1350,160+i*30,*dsmb.data[i],mapID,15);
										setID(1000+i,300,130+i*30,1350,160+i*30,mapID);
										mb=*dsmb.data[0];
										vitri=1;
										clickmb(mb,1,mapID);
										}
									} else {
										for(int i=0; i+(tranghientai-1)*10 < dsmb.soluong && i < 10 ;i++ ){
										taodongmb(i+1+(tranghientai-1)*10,300,130+i*30,1350,160+i*30,*dsmb.data[i+(tranghientai-1)*10],mapID,15);	
										mb = *dsmb.data[(tranghientai-1)*10];
										vitri=(tranghientai-1)*10+1;
										clickmb(mb,vitri,mapID);
										}
									}	
								}
						 	}
					 	}				 
				if( !Empty(dsmb)){
     	      			mb = *dsmb.data[(tranghientai-1)*10];
						vitri=(tranghientai-1)*10+1;
						clickmb(mb,vitri,mapID);
						rectangle(300,130+(1-1)%10*30,1350,160+(1-1)%10*30);
				}
			}
				idmb=0;
				break;
			case ED_SHMB:
				do  {
					idmb = ED_SHMB;
					NhapLieuInHoa(505,595,idmb,mapID,mb.sohieumaybay,16);
					if (idmb == HUY_MB  || idmb == HUY_MBEDIT) {
						break;
					}
					if (timkiem(dsmb,mb.sohieumaybay ) != -1){
						MessageBox(NULL,"So Hieu May Bay Da Ton Tai \n   Vui Long Nhap Lai! !","THONG BAO",MB_ICONWARNING|MB_OK);
					} 
					
				} while (timkiem(dsmb,mb.sohieumaybay ) != -1);
			break;
			case ED_LOAIMB:
				idmb = ED_LOAIMB;
				NhapLieuHoaThuong(575,680,idmb,mapID,mb.loaimaybay);
				if (idmb == HUY_MB  || idmb == HUY_MBEDIT) {
						break;
					}
				break;
			case ED_SODAY:
				do  {
					idmb = ED_SODAY;
					Nhapso(1155,595,idmb,mapID,day,3);
					mb.soday=ChangeCharToNum(day);
					if (mb.sodong ==0 ) {
						break;
					}
					if (mb.sodong*mb.soday < 20){
						MessageBox(NULL,"So cho cua may bay phai lon hon 20. Vui long nhap lai !","THONG BAO",MB_ICONWARNING|MB_OK);
					} 
					if (idmb == HUY_MB  || idmb == HUY_MBEDIT) {
						break;
					}
				} while ( mb.sodong*mb.soday < 20);
				
				break;
			case ED_SODONG:
				do  {
					idmb = ED_SODONG;
					Nhapso(1155,680,idmb,mapID,dong,3);
					mb.sodong=ChangeCharToNum(dong);	
					if (mb.soday ==0 ) {
						break;
					}
					if (mb.sodong*mb.soday < 20){
						MessageBox(NULL,"So cho cua may bay phai lon hon 20. Vui long nhap lai !","THONG BAO",MB_ICONWARNING|MB_OK);
					} 
					if (idmb == HUY_MB  || idmb == HUY_MBEDIT) {
						break;
					}
				} while (mb.sodong*mb.soday < 20);
					
				break;
			case NEXT_PAGE:
				tranghientai++;
				if (tranghientai = trangcuoi){
					taoButton(0,1175,450,1350,480,BLACK,BLACK,WHITE,"NEXT PAGE",mapID);
				} else if ( tranghientai < trangcuoi)
					taoButton(NEXT_PAGE,1175,450,1350,480,BLACK,BLACK,GRAY,"NEXT PAGE",mapID);
				else{
					if(dsmb.soluong % 10 != 0)
							setID(0,300,130+(dsmb.soluong % 10)*30,1350,430,mapID);
					taoButton(0,300,450,475,480,BLACK,BLACK,WHITE,"BACK PAGE",mapID);
				} 
					
				taoButton(BACK_PAGE,300,450,475,480,BLACK,BLACK,GRAY,"BACK PAGE",mapID);
				
				setfillstyle(1,WHITE);
				bar(300,130,1350,430);
				rectangle(300,130,1350,430);
				for(int i=0; i+(tranghientai-1)*10 < dsmb.soluong && i < 10 ;i++ ){
					taodongmb(i+1+(tranghientai-1)*10,300,130+i*30,1350,160+i*30,*dsmb.data[i+(tranghientai-1)*10],mapID,15);	
					mb = *dsmb.data[(tranghientai-1)*10];
					vitri=(tranghientai-1)*10+1;
					clickmb(mb,vitri,mapID);
				}
				idmb=0;
				break;
			case BACK_PAGE:
				tranghientai--;
				if( tranghientai > 1)
				   	taoButton(BACK_PAGE,300,450,475,480,BLACK,BLACK,GRAY,"BACK PAGE",mapID);
				else 
					taoButton(0,300,450,475,480,BLACK,BLACK,WHITE,"BACK PAGE",mapID);
				if( tranghientai < trangcuoi){
					taoButton(NEXT_PAGE,1175,450,1350,480,BLACK,BLACK,GRAY,"NEXT PAGE",mapID);
				}
				setfillstyle(1,WHITE);
				bar(300,130,1350,430);
				rectangle(300,130,1350,430);
				for(int i=0; i+(tranghientai-1)*10 < dsmb.soluong && i < 10 ;i++ )
				{
					taodongmb(i+1+(tranghientai-1)*10,300,130+i*30,1350,160+i*30,*dsmb.data[i+(tranghientai-1)*10],mapID,15);
					setID(1000+i,350,130+i*30,1350,160+i*30,mapID);
				}

 				mb = *dsmb.data[(tranghientai-1)*10];
 				
				vitri=(tranghientai-1)*10+1;
				clickmb(mb,vitri,mapID);
				idmb=0;
				break;

			case 1000:case 1001:case  1002 :case 1003: case 1004 :case 1005: case 1006 :case 1007: case 1008: case 1009:
	        	
				if (!kt) {
					    	cout<<vitri;	
				unclickmb(mb,vitri,mapID);
				vitri = idmb-1000+1 + (tranghientai-1)*10;
				mb=*dsmb.data[idmb-1000+ (tranghientai-1)*10];
				clickmb(mb,vitri,mapID);
				idmb = 0;
				}
				break;
		}
		delay(0.001);
	}
}

void findmb(unsigned short int ** mapID, int &luu_id,danhsachmaybay &dsmb){
	
	maybay mb;
	resetmb(mb);
	int tranghientai = 1;
	int trangcuoi = ceil(dsmb.soluong/10.0);
	int idmb = 0;
	int x,y;
	int vitri =0;
	
	setID(0,300,100,1350,440,mapID);
	setfillstyle(1,WHITE);
//	setcolor(BLACK);
	bar(300,100,1351,495);
	settextstyle(8,0,2);
	
	rectangle(300,100,1350,430);
	line(300,140,1350,140);
	line(300+4*16,100,300+4*16,140);
	line(300+20*16,100,300+20*16,140);
	line(300+45*16,100,300+45*16,140);
	line(300+55*16,100,300+55*16,140);

//	setusercharsize(1,2,1,2);
	setbkcolor(WHITE);
	outtextxy(300+2*16-textwidth("STT")/2,105,"STT");
	outtextxy(300+12*16-textwidth("SoHieuMayBay")/2,105,"SoHieuMayBay");
	outtextxy(300+30*16-textwidth("Loai May Bay")/2,105,"Loai May Bay");
	outtextxy(300+50*16-textwidth("So Dong")/2,105,"So Dong");
	outtextxy(300+55*16+(1350-300-55*16)/2-textwidth("So Day")/2,105,"So Day");
	
	if (Empty(dsmb)) {
//		settextstyle(8,0,2);
		outtextxy(825-strlen("! DANH SACH TRONG !")*4,135,"! DANH SACH TRONG !");
		
	   	taoButton(0,790,510,860,540,BLACK,BLACK,GRAY,"XOA",mapID);
    	taoButton(0,910,510,980,540,BLACK,BLACK,GRAY,"SUA",mapID);

	} else {
		for(int i=0; i< dsmb.soluong && i<10 ;i++){
		taodongmb(i+1,300,130+i*30,1350,160+i*30,*dsmb.data[i],mapID,15);
		setID(1000+i,300,130+i*30,1350,160+i*30,mapID);
		mb=*dsmb.data[0];
		vitri=1;
		movembfindmb(mb,1,mapID);
		}
	}
		if (tranghientai < trangcuoi) {
		taoButton(NEXT_PAGE,1175,450,1350,480,BLACK,BLACK,GRAY,"NEXT PAGE",mapID);
	} else
		taoLabel(1175,450,1350,480,BLACK,BLACK,WHITE,"NEXT PAGE");
		taoLabel(300,450,475,480,BLACK,BLACK,WHITE,"BACK PAGE");
	
	while(true)
	{
		if(ismouseclick(WM_MOUSEMOVE)){
			getmouseclick(WM_MOUSEMOVE, x, y);
			idmb = mapID[y][x];
			clearmouseclick(WM_MOUSEMOVE);
		if (idmb<=5 && idmb>=1)//thoat ra v?o chuc nang khac
		{
			luu_id=idmb;
			break;
		}
		switch(idmb){
		
			case 1000:case 1001:case  1002 :case 1003: case 1004 :case 1005: case 1006 :case 1007: case 1008: case 1009:
	        	
	        	unclickmbfind(mb,vitri,mapID);
				vitri = idmb-1000+1 + (tranghientai-1)*10;
				mb=*dsmb.data[idmb-1000+ (tranghientai-1)*10];
				movembfindmb(mb,vitri,mapID);
				idmb = 0;
//				unclickmbfind(mb,vitri,mapID);
//				vitri = idmb-1000+1;
//				mb=*dsmb.data[idmb-1000];
//				movembfindmb(mb,vitri,mapID);
//				idmb=0;
				break;
		}
	
	} else
	 if (ismouseclick(WM_LBUTTONDOWN)) {
        getmouseclick(WM_LBUTTONDOWN, x, y);
        idmb = mapID[y][x];
        clearmouseclick(WM_LBUTTONDOWN);

        if (idmb <= 5 && idmb >= 1) {
            luu_id = idmb;
            break;
        }
        switch (idmb) {
        	case NEXT_PAGE:
        			tranghientai++;
				if (tranghientai = trangcuoi){
					taoButton(0,1175,450,1350,480,BLACK,BLACK,WHITE,"NEXT PAGE",mapID);
				} else if ( tranghientai < trangcuoi)
					taoButton(NEXT_PAGE,1175,450,1350,480,BLACK,BLACK,GRAY,"NEXT PAGE",mapID);
				else{
					if(dsmb.soluong % 10 != 0)
					setID(0,300,130+(dsmb.soluong % 10)*30,1350,430,mapID);
//					setID(0,300,430-(dsmb.soluong % 10)*30,1350,430,mapID);
					taoButton(0,300,450,475,480,BLACK,BLACK,WHITE,"BACK PAGE",mapID);
				} 
					
				taoButton(BACK_PAGE,300,450,475,480,BLACK,BLACK,GRAY,"BACK PAGE",mapID);
				
				setfillstyle(1,WHITE);
				bar(300,130,1350,430);
				rectangle(300,130,1350,430);
				for(int i=0; i+(tranghientai-1)*10 < dsmb.soluong && i < 10 ;i++ ){
					taodongmb(i+1+(tranghientai-1)*10,300,130+i*30,1350,160+i*30,*dsmb.data[i+(tranghientai-1)*10],mapID,15);	
					mb = *dsmb.data[(tranghientai-1)*10];
					vitri=(tranghientai-1)*10+1;
					movembfindmb(mb,vitri,mapID);
				}
				idmb=0;
				break;
			case BACK_PAGE:
				tranghientai--;
				if( tranghientai > 1)
				   	taoButton(BACK_PAGE,300,450,475,480,BLACK,BLACK,GRAY,"BACK PAGE",mapID);
				else 
					taoButton(0,300,450,475,480,BLACK,BLACK,WHITE,"BACK PAGE",mapID);
				if( tranghientai < trangcuoi){
					taoButton(NEXT_PAGE,1175,450,1350,480,BLACK,BLACK,GRAY,"NEXT PAGE",mapID);
				}
				setfillstyle(1,WHITE);
				bar(300,130,1350,430);
				rectangle(300,130,1350,430);
				for(int i=0; i+(tranghientai-1)*10 < dsmb.soluong && i < 10 ;i++ )
				{
					taodongmb(i+1+(tranghientai-1)*10,300,130+i*30,1350,160+i*30,*dsmb.data[i+(tranghientai-1)*10],mapID,15);
					setID(1000+i,350,130+i*30,1350,160+i*30,mapID);
				}

 				mb = *dsmb.data[(tranghientai-1)*10];
				vitri=(tranghientai-1)*10+1;
				movembfindmb(mb,vitri,mapID);
				idmb=0;
				break;

        	
            case 1000: case 1001: case 1002: case 1003: case 1004: case 1005: case 1006: case 1007: case 1008: case 1009:
        	
				unclickmbfind(mb,vitri,mapID);
				vitri = idmb-1000+1 + (tranghientai-1)*10;
				taoButton(0,300,450,475,480,WHITE,WHITE,WHITE,"BACK PAGE",mapID);
				taoButton(0,1175,450,1350,480,WHITE,WHITE,WHITE,"NEXT PAGE",mapID);
//					taoButton(1175,460,1350,490,BLACK,BLACK,WHITE,"NEXT PAGE");
//		taoButton(300,460,475,490,BLACK,BLACK,WHITE,"BACK PAGE");
				luu_id=vitri-1;	
				return;
				mb=*dsmb.data[idmb-1000 + (tranghientai-1)*10];
				movembfindmb(mb,vitri,mapID);
				idmb=0;
				break;
        }
    }
    	delay(0.001);
    }
}
////////////////////////////////// CHUYEN BAY /////////////////////////////////
void resetthanhchucnangcb(unsigned short int ** mapID) {
	setID(0,300,500,1350,550,mapID);
	
	setfillstyle(1,WHITE);
	bar(301,501,1349,549);
}

void vekhungchuyenbay(unsigned short int ** mapID) {
	
	setfillstyle(1,WHITE);
	bar(301,140,1349,440);
	setcolor(BLACK);
	rectangle(300,140,1350,440);
	
	
	settextstyle(10, 0, 4);
	taoLabel(595,0,995,50,BLACK,BLACK,GRAY,"DANH SACH CHUYEN BAY");
	
	settextstyle(8,0,2);
	
	rectangle(300,100,1350,440);
	line(300,140,1350,140);
	line(300+4*16,100,300+4*16,140);
	line(300+12*16,100,300+12*16,140);
	line(300+25*16,100,300+25*16,140);
	line(300+40*16,100,300+40*16,140);
	line(300+55*16,100,300+55*16,140);

	setusercharsize(1,2,1,2);
	setbkcolor(WHITE);
	outtextxy(300+2*16-textwidth("STT")/2,110,"STT");
	outtextxy(300+8*16-textwidth("MaCB")/2,110,"MaCB");
	outtextxy(300+18*16-textwidth("SHMB")/2,110,"SHMB");
	outtextxy(300+32*16-textwidth("Thoi Gian")/2,110,"Thoi Gian");
	outtextxy(300+47*16-textwidth("Diem Den")/2,110,"Diem Den");
	outtextxy(300+55*16+(1350-300-55*16)/2-textwidth("Trang Thai")/2,110,"Trang Thai");
	
	settextstyle(10,0,0);
	taoLabel(300,60,400,90,BLACK,BLACK,WHITE,"Ngay gio:");
	taoEditText(CBLOCNGAY,405,60,445,90,BLACK,BLACK,WHITE,mapID);
	settextstyle(10,0,3);
	outtextxy(447,60,":");
	
	taoEditText(CBLOCTHANG,460,60,500,90,BLACK,BLACK,WHITE,mapID);
	settextstyle(10,0,3);
	outtextxy(503,60,":");
	
	settextstyle(10,0,0);
	taoEditText(CBLOCNAM,515,60,575,90,BLACK,BLACK,WHITE,mapID);

	settextstyle(10,0,0);
	taoLabel(650,60,730,90,BLACK,BLACK,WHITE,"MaCB:");
	taoEditText(CBMACB,735,60,850,90,BLACK,BLACK,WHITE,mapID);
	
	settextstyle(10,0,0);
	taoLabel(900,60,1000,90,BLACK,BLACK,WHITE,"Diem den:");
	taoEditText(CBDIEMDEN,1005,60,1200,90,BLACK,BLACK,WHITE,mapID);
	
	settextstyle(10,0,0);
	taoButton(CBLOC,1250,60,1350,90,BLACK,BLACK,11,"LOC",mapID);
	
}

void nhaplieuchuyenbay(unsigned short int ** mapID) {
	settextstyle(10, 0, 2);	
	setcolor(BLACK);
	rectangle(300,500,1350,750);
	line(300,550,1350,550);

	taoButton(CB_THEM,670,510,740,540,BLACK,BLACK,GRAY,"THEM",mapID);
	taoButton(CB_HUYCB,790,510,880,540,BLACK,BLACK,GRAY,"HUY CB",mapID);
    taoButton(CB_SUA,930,510,1000,540,BLACK,BLACK,GRAY,"SUA",mapID);
    
    taoLabel(310,565,500,615,BLACK,BLACK,GRAY,"Ma CB");
    taoLabel(310,625,500,675,BLACK,BLACK,GRAY,"Diem Den");
    
    taoLabel(850,565,950,615,BLACK,BLACK,GRAY,"SHMB");
    taoLabel(950,625,1150,675,BLACK,BLACK,GRAY,"Trang Thai");
    
    taoLabel(310,685,410,735,BLACK,BLACK,GRAY,"NGAY");
    taoLabel(500,685,600,735,BLACK,BLACK,GRAY,"THANG");
    taoLabel(690,685,790,735,BLACK,BLACK,GRAY,"NAM");
    taoLabel(920,685,1070,735,BLACK,BLACK,GRAY,"Thoi Gian");
    outtextxy(1145,700,":");
    
    taoEditText(0,510,565,800,615,BLACK,BLACK,GRAY,mapID);
    taoEditText(0,510,625,900,675,BLACK,BLACK,GRAY,mapID);
    
    taoEditText(0,960,565,1200,615,BLACK,BLACK,GRAY,mapID);
    taoEditText(0,510,625,900,675,BLACK,BLACK,GRAY,mapID);
    taoLabel(1160,625,1340,675,BLACK,BLACK,GRAY,"");
    
    taoEditText(0,420,685,480,735,BLACK,BLACK,GRAY,mapID);
    taoEditText(0,610,685,670,735,BLACK,BLACK,GRAY,mapID);
    taoEditText(0,800,685,900,735,BLACK,BLACK,GRAY,mapID);
    
    taoEditText(0,1080,685,1140,735,BLACK,BLACK,GRAY,mapID);
    taoEditText(0,1160,685,1220,735,BLACK,BLACK,GRAY,mapID);
}



void taodongcb(int stt, int x, int y, int x1, int y1, chuyenbay &cb, unsigned short int **mapID,int bgcl){
		setcolor(BLACK);
		settextstyle(8, 0, 0);
		setusercharsize(1,2,1,2);
		
		line(x,y1,x1,y1);
		line(x+4*16,y,x+4*16,y1);
		line(x+12*16,y,x+12*16,y1);
		line(x+25*16,y,x+25*16,y1);
		line(x+40*16,y,x+40*16,y1);
		line(x+55*16,y,x+55*16,y1);
		
		if(bgcl<15)
			setbkcolor(YELLOW);
		else 
		setbkcolor(WHITE);
		outtextxy(x+2*16-textwidth(toChars(stt))/2,y+8,toChars(stt));
		outtextxy(x+8*16-textwidth(cb.MaCB)/2,y+8,cb.MaCB);
		outtextxy(x+18*16-textwidth(cb.SHMB)/2,y+8,cb.SHMB);
		outtextxy(x+32*16-textwidth(tocharDate(cb.time))/2,y+8,tocharDate(cb.time));
		outtextxy(x+47*16-textwidth(cb.SanBayDen)/2,y+8,cb.SanBayDen);
		
		if(cb.trangthai == 0)
			 outtextxy(x+58*16+(1300-x-58*16)/2-textwidth("HUYCHUYEN")/2,y+8,"HUYCHUYEN");
		else if(cb.trangthai == 1)
		    
		      outtextxy(x+58*16+(1300-x-58*16)/2-textwidth("CONVE")/2,y+8,"CONVE");
		 else if(cb.trangthai == 2)
		     
		      outtextxy(x+58*16+(1300-x-58*16)/2-textwidth("HETVE")/2,y+8,"HETVE");
		     
		else 
		      outtextxy(x+58*16+(1300-x-58*16)/2-textwidth("HOANTAT")/2,y+10,"HOANTAT");
		settextstyle(0, 0, 2);	
	

}

void clickcb(int vitri, chuyenbay &cb,unsigned short int **mapID) {
	setfillstyle(1,YELLOW);
    bar(300,140+(vitri-1)%10*30,1350,170+(vitri-1)%10*30);
    rectangle(300,140+(vitri-1)%10*30,1350,170+(vitri-1)%10*30);
    setbkcolor(RED);
	taodongcb(vitri,300,140+(vitri-1)%10*30,1350,170+(vitri-1)%10*30,cb,mapID,YELLOW);
    setfillstyle(1,GRAY);
    bar(511,566,800,615);
	bar(511,626,900,675);
	bar(961,566,1200,615);
	bar(1161,626,1240,675);
	bar(421,686,480,735);       // NGAY
	bar(611,686,670,735);		//THANG
	bar(801,686,900,735);
	bar(1081,686,1140,735);
	bar(1161,686,1220,735);
	setbkcolor(GRAY);
	settextstyle(0,0,2);
    outtextxy(515,580,cb.MaCB);
    outtextxy(965,580,cb.SHMB);
    outtextxy(515,640,cb.SanBayDen);
	if(cb.trangthai == 0)
    	     outtextxy(1245-textwidth("HUYCHUYEN")/2,640,"HUYCHUYEN");
	    else if(cb.trangthai == 1)
    	     outtextxy(1245-textwidth("CONVE")/2,640,"CONVE");
    	 else if(cb.trangthai == 2)
    	     outtextxy(1245-textwidth("HETVE")/2,640,"HETVE"); 
	    else 
    	     outtextxy(1245-textwidth("HOANTAT")/2,640,"HOANTAT"); 
		
	outtextxy(430,700,toChars(cb.time.ngay));
	outtextxy(620,700,toChars(cb.time.thang));
	outtextxy(815,700,toChars(cb.time.nam));
	outtextxy(1090,700,toChars(cb.time.gio));
	outtextxy(1170,700,toChars(cb.time.phut));
}

void unclickcb(int vitri,chuyenbay &cb,unsigned short int **mapID){
		
		setfillstyle(1,WHITE);
        bar(300,140+(vitri-1)%10*30,1350,170+(vitri-1)%10*30);
        rectangle(300,140+(vitri-1)%10*30,1350,170+(vitri-1)%10*30);
        setbkcolor(WHITE);
        taodongcb(vitri,300,140+(vitri-1)%10*30,1350,170+(vitri-1)%10*30,cb,mapID,15);
        setfillstyle(1,GRAY);
    	bar(511,566,800,615);
		bar(511,626,900,675);
		bar(961,566,1200,615);
		bar(1161,626,1240,675);
		bar(421,686,480,735);       // NGAY
		bar(611,686,670,735);		//THANG
		bar(801,686,900,735);
		bar(1081,691,1140,735);
		bar(1161,686,1220,735);
}

void xuatdanhsachchuyenbay(unsigned short int ** mapID,nodeCB *&first,int trangso){
	
	setfillstyle(1,WHITE);
	bar(301,140,1349,440);
	setcolor(BLACK);
	rectangle(300,140,1350,440);
	nodeCB *nodechay;
	int demsl=0;
	int i=0;
	for ( nodechay = first ;  nodechay != NULL  && demsl < 10;	) {
		i++;
		if(i-(trangso-1)*10>0 ) {
			taodongcb(i,300,110+(i-(trangso-1)*10)*30,1350,140+(i-(trangso-1)*10)*30,nodechay->data,mapID,15);
		   	setID(1000+(i-(trangso-1)*10)-1,300,110+(i-(trangso-1)*10)*30,1350,140+(i-(trangso-1)*10)*30,mapID);
		   	demsl++;
			}	
			nodechay=nodechay->next;
	}
}


//void xuatdanhsachchuyenbayver2(unsigned short int ** mapID,nodeCB *&first,int trangso, chuyenbay cb, char *locmacb, char *locdiemden, char *locngay, char *locthang, char *locnam ){
//	
//	setfillstyle(1,WHITE);
//	bar(301,140,1349,440);
//	setcolor(BLACK);
//	rectangle(300,140,1350,440);
//	nodeCB *nodechay;
//	int demsl=0;
//	int i=0;
//	for ( nodechay = first ;  nodechay != NULL  && demsl < 10;	) {
//		if(
//					(strlen(locmacb)==0 || strcmp(locmacb,nodechay->data.MaCB)==0)
//					&& (strlen(locdiemden)==0 || strcmp(locdiemden,nodechay->data.SanBayDen)==0)
//					&& (strlen(locngay)==0 || ChangeCharToNum(locngay)==nodechay->data.time.ngay)
//					&& (strlen(locthang)==0 || ChangeCharToNum(locthang)==nodechay->data.time.thang) 
//					&& (strlen(locnam)==0 || ChangeCharToNum(locnam)==nodechay->data.time.nam) 
//					
//		){
//		i++;
//		if(i-(trangso-1)*10>0 ) {
//			taodongcb(i,300,110+(i-(trangso-1)*10)*30,1350,140+(i-(trangso-1)*10)*30,nodechay->data,mapID,15);
//		   	setID(1000+(i-(trangso-1)*10)-1,300,110+(i-(trangso-1)*10)*30,1350,140+(i-(trangso-1)*10)*30,mapID);
//		   	demsl++;
//			}	
//			nodechay=nodechay->next;
//		}
//
//	}
//}

nodeCB *xuatdanhsachchuyenbayver2(unsigned short int** mapID, nodeCB *&first, int trangso, chuyenbay cb, char* locmacb, char* locdiemden, char* locngay, char* locthang, char* locnam) {
    setfillstyle(1, WHITE);
    bar(301, 140, 1349, 440);
    setcolor(BLACK);
    rectangle(300, 140, 1350, 440);

    nodeCB *nodechay = first;
    int demsl = 0;
    int vitri = 0;
    nodeCB* luu = NULL;
    while (nodechay != NULL && demsl < (trangso * 10)) {
        if (
            (strlen(locmacb) == 0 || strcmp(locmacb, nodechay->data.MaCB) == 0) &&
            (strlen(locdiemden) == 0 || strcmp(locdiemden, nodechay->data.SanBayDen) == 0) &&
            (strlen(locngay) == 0 || ChangeCharToNum(locngay) == nodechay->data.time.ngay) &&
            (strlen(locthang) == 0 || ChangeCharToNum(locthang) == nodechay->data.time.thang) &&
            (strlen(locnam) == 0 || ChangeCharToNum(locnam) == nodechay->data.time.nam)
        ) {
            demsl++;
            if (demsl > (trangso - 1) * 10) {
                vitri++;
                taodongcb(demsl, 300, 110 + (vitri ) * 30, 1350, 140 + (vitri ) * 30, nodechay->data, mapID, 15);
                setID(1000 + (vitri-1), 300, 110 + (vitri ) * 30, 1350, 140 + (vitri ) * 30, mapID);
                
            	
            	InsertTheoMaCB(luu,nodechay->data);
            }
        }
        
        nodechay = nodechay->next;
        
    }
    
    return luu;
    
}

void xulychuyenbay(unsigned short int ** mapID, int &luu_id, nodeCB *&first, danhsachmaybay &dsmb) {
	
	maybay mb;
	chuyenbay cb;
	resetcb(cb);
	resetthanhchucnangcb(mapID);
	vekhungchuyenbay(mapID);
	nhaplieuchuyenbay(mapID);
	
	int namhientai = cb.time.nam;
	nodeCB *nodechay;


	int slcb =0;
	int tranghientai=0;
	int trangcuoi = 0;

	char locngay[30]= "";
	char locthang[30]= ""; 
	char locnam[30]= "";
	char locmacb[30]= "";
	char locdiemden[30] = "";
	
	locngay[0]= '\0';
	locthang[0]= '\0'; 
	locnam[0]= '\0';
	locmacb[0]= '\0';
	locdiemden[0] = '\0';
	
	nodeCB *inMH = NULL;
	int idcb = 0;
	int x,y;
	
	
	if (dsCBEmpty(first)) {
		outtextxy(800-strlen("! DANH SACH TRONG !")*4,145,"! DANH SACH TRONG !");
		taoButton(0,790,510,880,540,BLACK,BLACK,WHITE,"HUY CB",mapID);
	    taoButton(0,930,510,1000,540,BLACK,BLACK,WHITE,"SUA",mapID);
	} else {
			tranghientai=1;
			slcb =0;
			for(nodechay = first; nodechay != NULL; nodechay = nodechay->next ){
				slcb++;
				if (slcb%10 ==1) {
					trangcuoi++;
				}
			}
//			for (nodechay = )
			
			
			inMH=xuatdanhsachchuyenbayver2(mapID,first,tranghientai,cb, locmacb,  locdiemden,  locngay,  locthang,  locnam);
			cb=first->data;
			clickcb(1,cb,mapID);
	if (slcb>10) {
		taoButton(NEXTPAGECB,1175,460,1350,490,BLACK,BLACK,GRAY,"NEXT PAGE",mapID);
	} else{
	
		taoLabel(1175,460,1350,490,BLACK,BLACK,WHITE,"NEXT PAGE");
		taoLabel(300,460,475,490,BLACK,BLACK,WHITE,"BACK PAGE");
	}
	}
	
	
	int vitri=1;
	int i=0;
	char day[30]= "";
	char month[30]= ""; 
	char year[30]= "";
	char hour[30]= "";
	char minute[30] = "";
	char s[50]="";

	
	while(true)
	{
//		idcb=0;
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
			
		
			case CB_THEM: 
				if (slcb==0) {
					inMH=xuatdanhsachchuyenbayver2(mapID,first,tranghientai,cb, locmacb,  locdiemden,  locngay,  locthang,  locnam);
					cb=first->data;
					clickcb(1,cb,mapID);
				}
				if (slcb>0) {
					unclickcb(vitri,cb,mapID);
				}
//				resetcb(cb);
				taoButton(FIND,1200,565,1340,615,BLACK,BLACK,WHITE,"FIND",mapID);
				resetcb(cb);
				resetthanhchucnangcb(mapID);
				taoLabel(1160,625,1340,675,BLACK,BLACK,GRAY,"");
				s[0]='\0';
				day[0]= '\0';
				month[0]= '\0';
				year[0]= '\0';
				hour[0]= '\0';
				minute[0]= '\0';
				taoButton(CB_LUU,720,510,790,540,BLACK,BLACK,GRAY,"LUU",mapID);
				taoButton(CB_HUYLUU,840,510,910,540,BLACK,BLACK,GRAY,"HUY",mapID);
				
				taoEditText(ED_MACB,510,565,800,615,BLACK,BLACK,WHITE,mapID);
			    taoEditText(ED_DIEMDEN,510,625,900,675,BLACK,BLACK,WHITE,mapID);
			    
			    taoEditText(0,960,565,1200,615,BLACK,BLACK,WHITE,mapID);
//			    taoLabel(1160,625,1340,675,BLACK,BLACK,WHITE,"");
			    setbkcolor(GRAY);
			    outtextxy(1245-textwidth("CONVE")/2,640,"CONVE");
			    
			    taoEditText(ED_NGAY,420,685,480,735,BLACK,BLACK,WHITE,mapID);
			    taoEditText(ED_THANG,610,685,670,735,BLACK,BLACK,WHITE,mapID);
			    taoEditText(ED_NAM,800,685,900,735,BLACK,BLACK,WHITE,mapID);
			    
			    taoEditText(ED_GIO,1080,685,1140,735,BLACK,BLACK,WHITE,mapID);
			    taoEditText(ED_PHUT,1160,685,1220,735,BLACK,BLACK,WHITE,mapID);
//	
			    outtextxy(430,700,toChars(cb.time.ngay));
				outtextxy(620,700,toChars(cb.time.thang));
			
				outtextxy(815,700,toChars(cb.time.nam));
				outtextxy(1090,700,toChars(cb.time.gio));
				outtextxy(1170,700,toChars(cb.time.phut));
				
				strcpy(day,toChars(cb.time.ngay));
				strcpy(month,toChars(cb.time.thang));
				strcpy(year,toChars(cb.time.nam));
				strcpy(hour,toChars(cb.time.gio));
				strcpy(minute,toChars(cb.time.phut));
				
				idcb=0;
			break;
			
			case CB_HUYCB:
				nodechay = timkiemMACB(first,cb.MaCB);
				Save_file_MB(dsmb);
	         	Save_file_chuyen_bay(first);
				if (nodechay->data.trangthai == CON_VE || nodechay->data.trangthai == HET_VE) {
					if(MessageBox(NULL,"\n           [XAC NHAN HUY CHUYEN] !           \n ","THONG BAO",MB_ICONWARNING|MB_OKCANCEL) == IDOK ){
					  	if( huychuyen(nodechay)){
							  		Save_file_chuyen_bay(first);
							  		cb.trangthai=HUY_CHUYEN;
				                    taodongcb(vitri-(tranghientai-1)*10,300,110+(vitri-(tranghientai-1)*10)*30,1350,140+(vitri-(tranghientai-1)*10)*30,nodechay->data,mapID,YELLOW);
							 }
				}
			} 
			else	{
					  	MessageBox(NULL,"\n    Chuyen Bay Khong Con Hoat Dong \n     Khong The Huy Chuyen Bay Nay !     \n ","THONG BAO",MB_ICONERROR); 
					  	taodongcb(vitri+(tranghientai-1)*10,300,110+vitri*30,1350,140+vitri*30,nodechay->data,mapID,YELLOW);
					  }
				idcb=0;
			break;
			
			case CB_SUA:
				
				taoButton(FIND,1200,565,1340,615,BLACK,BLACK,WHITE,"FIND",mapID);
				resetthanhchucnangcb(mapID);
				taoLabel(1160,625,1340,675,BLACK,BLACK,GRAY,"");
				s[0]='\0';
				taoButton(ED_LUUCB,720,510,790,540,BLACK,BLACK,GRAY,"LUU",mapID);
				taoButton(ED_HUYLUU,840,510,910,540,BLACK,BLACK,GRAY,"HUY",mapID);
				
				taoEditText(0,510,565,800,615,BLACK,BLACK,GRAY,mapID);

				outtextxy(515,580,cb.MaCB);
			    taoEditText(ED_DIEMDEN,510,625,900,675,BLACK,BLACK,WHITE,mapID);
			    outtextxy(515,640,cb.SanBayDen);
			    taoEditText(ED_SHMBCB,960,565,1200,615,BLACK,BLACK,WHITE,mapID);
				outtextxy(965,580,cb.SHMB);
			    setbkcolor(GRAY);
			    	if(cb.trangthai == 0)
			    	     outtextxy(1245-textwidth("HUYCHUYEN")/2,640,"HUYCHUYEN");
				    else if(cb.trangthai == 1)
			    	     outtextxy(1245-textwidth("CONVE")/2,640,"CONVE");
			    	else if(cb.trangthai == 2)
			    	     outtextxy(1245-textwidth("HETVE")/2,640,"HETVE"); 
				    else 
			    	     outtextxy(1245-textwidth("HOANTAT")/2,640,"HOANTAT"); 
			     
			    strcpy(day,toChars(cb.time.ngay));
			    taoEditText(ED_NGAY,420,685,480,735,BLACK,BLACK,WHITE,mapID);
			    outtextxy(430,700,toChars(cb.time.ngay));
			    
			    strcpy(month,toChars(cb.time.thang));
			    taoEditText(ED_THANG,610,685,670,735,BLACK,BLACK,WHITE,mapID);
			    outtextxy(620,700,toChars(cb.time.thang));
			    
			    strcpy(year,toChars(cb.time.nam));
			    taoEditText(ED_NAM,800,685,900,735,BLACK,BLACK,WHITE,mapID);
			  	outtextxy(815,700,toChars(cb.time.nam));
			  	
			  	strcpy(hour,toChars(cb.time.gio));
			    taoEditText(ED_GIO,1080,685,1140,735,BLACK,BLACK,WHITE,mapID);
			  	outtextxy(1090,700,toChars(cb.time.gio));
			  	
			  	strcpy(minute,toChars(cb.time.phut));
			    taoEditText(ED_PHUT,1160,685,1220,735,BLACK,BLACK,WHITE,mapID);
			    outtextxy(1170,700,toChars(cb.time.phut));
				
				idcb=0;
			break;
			
			case ED_LUUCB:
					if ( TGNew(cb.time) == false){
//						cout<<time.nam;
						MessageBox(NULL,"Khong duoc chon thoi gian trong qua khu!","THONG BAO",MB_ICONWARNING|MB_OK);
					} else {
				
				taoButton(0,1201,565,1340,615,WHITE,WHITE,WHITE,"",mapID);
				nodechay = timkiemMACB(first,cb.MaCB);
				EditChuyenBay(nodechay,cb);
				Save_file_chuyen_bay(first);
				
				MessageBox(NULL,"Chuyen Bay Da Duoc Sua Thanh Cong !!!","THONG BAO",MB_ICONINFORMATION|MB_OK);
			
				taoButton(0,1201,565,1340,615,WHITE,WHITE,WHITE,"",mapID);
				resetthanhchucnangcb(mapID);
				settextstyle(10, 0, 2);	
				taoButton(CB_THEM,670,510,740,540,BLACK,BLACK,GRAY,"THEM",mapID);
				taoButton(CB_HUYCB,790,510,880,540,BLACK,BLACK,GRAY,"HUY CB",mapID);
			    taoButton(CB_SUA,930,510,1000,540,BLACK,BLACK,GRAY,"SUA",mapID);
				}
				inMH=xuatdanhsachchuyenbayver2(mapID,first,tranghientai,cb,locmacb,locdiemden,locngay,locthang,locnam);

			    idcb=0;
				break;
			
			case ED_HUYLUU:
				taoButton(0,1201,565,1340,615,WHITE,WHITE,WHITE,"",mapID);
				resetthanhchucnangcb(mapID);
				settextstyle(10, 0, 2);	
			
				taoButton(CB_THEM,670,510,740,540,BLACK,BLACK,GRAY,"THEM",mapID);
				taoButton(CB_HUYCB,790,510,880,540,BLACK,BLACK,GRAY,"HUY CB",mapID);
			    taoButton(CB_SUA,930,510,1000,540,BLACK,BLACK,GRAY,"SUA",mapID);
			
				
				idcb=0;
				break;
			
			case CB_LUU:
				
				if ( TGNew(cb.time) == false){
						MessageBox(NULL,"Khong duoc chon thoi gian trong qua khu!","THONG BAO",MB_ICONWARNING|MB_OK);
					} else {
				slcb=demslcb(first);
				khoiTaoDanhSachVe(cb,dsmb);			
				InsertTheoMaCB(first,cb);
				Save_file_chuyen_bay(first);
				MessageBox(NULL,"Chuyen Bay Da Duoc Them Thanh Cong !!!","THONG BAO",MB_ICONINFORMATION|MB_OK);
//				resetcb(cb);
				taoButton(0,1201,565,1340,615,WHITE,WHITE,WHITE,"",mapID);
				resetthanhchucnangcb(mapID);
//				nhaplieuchuyenbay(mapID);
				settextstyle(10, 0, 2);	
				taoButton(CB_THEM,670,510,740,540,BLACK,BLACK,GRAY,"THEM",mapID);
				taoButton(CB_HUYCB,790,510,880,540,BLACK,BLACK,GRAY,"HUY CB",mapID);
			    taoButton(CB_SUA,930,510,1000,540,BLACK,BLACK,GRAY,"SUA",mapID);
				}
				slcb++;

				inMH = new nodeCB;
//				xuatdanhsachchuyenbay(mapID,first,1);
					vitri=1;
				inMH=xuatdanhsachchuyenbayver2(mapID,first,tranghientai,cb,locmacb,locdiemden,locngay,locthang,locnam);
				i=0;
					nodeCB *nodenext;
					for (nodenext = inMH ;  nodenext != NULL  ;	) {
						i++;	
						   	if (i-(vitri-((tranghientai-1)*10))==0) {
							cb=nodenext->data;
							cout<<cb.SHMB;
							clickcb(vitri,cb,mapID);
							break;
							}	
							nodenext=nodenext->next;
					}
				
				
			    idcb=0;
			break;
			
			case CB_HUYLUU:
				setcolor(BLACK);
				resetthanhchucnangcb(mapID);
				nhaplieuchuyenbay(mapID);
				settextstyle(10, 0, 2);	
				taoButton(CB_THEM,670,510,740,540,BLACK,BLACK,GRAY,"THEM",mapID);
				taoButton(CB_HUYCB,790,510,880,540,BLACK,BLACK,GRAY,"HUY CB",mapID);
			    taoButton(CB_SUA,930,510,1000,540,BLACK,BLACK,GRAY,"SUA",mapID);
			    taoButton(0,1201,565,1340,615,WHITE,WHITE,WHITE,"",mapID);
			    
			    idcb=0;
			break;
			
			case FIND:
				taoButton(FIND,1200,565,1340,615,BLACK,BLACK,RED,"FIND",mapID);
				idcb = FIND;
				resetkhungds(mapID);
				findmb(mapID,idcb,dsmb);
				strcpy(cb.SHMB,dsmb.data[idcb]->sohieumaybay);
				setfillstyle(1,WHITE);
				bar(961,566,1200,615);//SHMB
				setbkcolor(WHITE);
				setcolor(BLACK);
				outtextxy(970,580,cb.SHMB);
				settextstyle(0, 0, 2);	
				resetkhungds(mapID);
				vekhungchuyenbay(mapID);
				
				inMH=xuatdanhsachchuyenbayver2(mapID,first,1,cb,locmacb,locdiemden,locngay,locthang,locnam);
				Save_file_chuyen_bay(first);
				if (tranghientai==1) {
					taoButton(0,300,460,475,490,BLACK,BLACK,WHITE,"BACK PAGE",mapID);
				} 
				if(tranghientai < trangcuoi )
					taoButton(NEXTPAGECB,1175,460,1350,490,BLACK,BLACK,GRAY,"NEXT PAGE",mapID);
				else{
						taoButton(0,1175,460,1350,490,BLACK,BLACK,WHITE,"NEXT PAGE",mapID);
						if(slcb % 10 != 0)
					     	setID(0,300,140+(slcb % 10)*30,1350,440,mapID);
				   } 
				taoButton(BACKPAGECB,300,460,475,490,BLACK,BLACK,GRAY,"BACK PAGE",mapID);
				
				taoButton(FIND,1200,565,1340,615,BLACK,BLACK,GRAY,"FIND",mapID);
				idcb=0;
			break;
			
			case ED_MACB:
				do {
				settextstyle(0, 0, 2);	
					idcb = ED_MACB;
				NhapLieuInHoa(515,580,idcb,mapID,cb.MaCB,MAX_MACB+1);
				if ((timkiemMACB(first,cb.MaCB) !=NULL)){
						MessageBox(NULL,"Da tonn tai Ma chuyen bay nay \n Moi nhap lai!","THONG BAO",MB_ICONWARNING|MB_OK);
				}
				} while (timkiemMACB(first,cb.MaCB) !=NULL);
				
			break;
			
			case ED_SHMBCB:
				settextstyle(0, 0, 2);		
				idcb = ED_SHMBCB;
				NhapLieu(965,580,idcb,mapID,cb.SHMB);
			break;
			
			case ED_DIEMDEN:
				settextstyle(0, 0, 2);	
				idcb = ED_DIEMDEN;
				NhapLieuInHoa(515,640,idcb,mapID,cb.SanBayDen,MAX_SBDEN);
			break;
			case ED_TT:
				outtextxy(1165,640,"CON_VE");
			break;
			
			case ED_NGAY:
				do {
					settextstyle(0, 0, 2);
					idcb= ED_NGAY;
					Nhapso(430,700,idcb,mapID,day,2);
					cb.time.ngay=ChangeCharToNum(day);
					if (cb.time.ngay > 31 || cb.time.ngay <=0 || strlen(day)==0){
						MessageBox(NULL,"Ngay Khong Hop Le \n 1<= Ngay <= 31 !","THONG BAO",MB_ICONWARNING|MB_OK);
					}
					if(idcb == CB_HUYLUU || idcb==ED_HUYLUU)
					break;
				} while (cb.time.ngay > 31 || cb.time.ngay <=0 || strlen(day)==0);
				
				break;
			
			case ED_THANG:
				
				do {
					settextstyle(0, 0, 2);
					idcb= ED_THANG;
					Nhapso(620,700,idcb,mapID,month,2);
					cb.time.thang=ChangeCharToNum(month);
					if (cb.time.thang > 12 || cb.time.thang <=0 || strlen(month)==0){
						MessageBox(NULL,"Thang Khong Hop Le \n 1<= Thang <= 12 !","THONG BAO",MB_ICONWARNING|MB_OK);
					}
					if(idcb == CB_HUYLUU || idcb==ED_HUYLUU)
					break;
				} while (cb.time.thang > 12 || cb.time.thang <=0 || strlen(month)==0);				
			break;
			
			case ED_NAM:
				Time time;
				do{
					settextstyle(0, 0, 2);
					idcb= ED_NAM;
					Nhapso(815,700,idcb,mapID,year,4);
					cb.time.nam = ChangeCharToNum(year);
					if (cb.time.nam > 2025 || cb.time.nam < 2024) {
							MessageBox(NULL,"Nam Khong Hop Le \n 2024<= Nam < 2026 !","THONG BAO",MB_ICONWARNING|MB_OK);
					}
					if(idcb == CB_HUYLUU || idcb==ED_HUYLUU)
					break;					
				} while (cb.time.nam < 2024  || cb.time.nam > 2025  );
			break;

			case ED_GIO:
				do{
					settextstyle(0, 0, 2);
					idcb= ED_GIO;
					Nhapso(1090,700,idcb,mapID,hour,2);
					cb.time.gio = ChangeCharToNum(hour);
					if (cb.time.gio >= 24 || cb.time.gio < 0) {
							MessageBox(NULL,"Gio Khong Hop Le \n 0<= Gio <= 23 !","THONG BAO",MB_ICONWARNING|MB_OK);
					}
					if(idcb == CB_HUYLUU || idcb==ED_HUYLUU)
					break;
				} while (cb.time.gio < 0  || cb.time.gio > 23);
			break;
			
			case ED_PHUT:
				do {
					settextstyle(0, 0, 2);
					idcb = ED_PHUT;
					Nhapso(1170,700,idcb,mapID,minute,2);
					cb.time.phut=ChangeCharToNum(minute);
					if (cb.time.phut > 59 || cb.time.phut <0){
						MessageBox(NULL,"Phut Khong Hop Le \n 0<= Phut <= 59 !","THONG BAO",MB_ICONWARNING|MB_OK);
					}
					if(idcb == CB_HUYLUU || idcb==ED_HUYLUU)
					break;
					
				} while (cb.time.phut < 0  || cb.time.phut > 59);
			break;
			
			case NEXTPAGECB:
				setcolor(BLACK);
				rectangle(300,140,1350,440);
				tranghientai++;
				
//				xuatdanhsachchuyenbay(mapID,first,tranghientai,cb);
				inMH=xuatdanhsachchuyenbayver2(mapID,first,tranghientai,cb,locmacb,locdiemden,  locngay,  locthang,  locnam);
//				Save_file_chuyen_bay(first);
				if(tranghientai < trangcuoi )
					taoButton(NEXTPAGECB,1175,460,1350,490,BLACK,BLACK,GRAY,"NEXT PAGE",mapID);
				else{
						taoButton(0,1175,460,1350,490,BLACK,BLACK,WHITE,"NEXT PAGE",mapID);
						if(slcb % 10 != 0)
					     	setID(0,300,140+(slcb % 10)*30,1350,440,mapID);
				   } 
				taoButton(BACKPAGECB,300,460,475,490,BLACK,BLACK,GRAY,"BACK PAGE",mapID);
				vitri=(tranghientai-1)*10+1;
				
//				cout<<vitri;
					i=0;
					nodeCB *nodeluu;
					for (nodeluu = inMH ;  nodeluu != NULL  ;	) {
						i++;	
						   	if (i-(vitri-((tranghientai-1)*10))==0) {
							cb=nodeluu->data;
//							cout<<cb.SHMB;
							clickcb(vitri,cb,mapID);
							break;
							}	
							nodeluu=nodeluu->next;
					}
				idcb=0;
			break;
			
			case BACKPAGECB:
				setcolor(BLACK);
				rectangle(300,140,1350,440);
				tranghientai--;
				
//				vitri=(tranghientai-1)*10+1;
//				xuatdanhsachchuyenbay(mapID,first,tranghientai,cb);
				inMH=xuatdanhsachchuyenbayver2(mapID,first,tranghientai,cb,locmacb,locdiemden,  locngay,  locthang,  locnam);
//				Save_file_chuyen_bay(first);
				if(tranghientai != 1 ){
					taoButton(BACKPAGECB,300,460,475,490,BLACK,BLACK,GRAY,"BACK PAGE",mapID);
				}	
				else {
						taoButton(0,300,460,475,490,BLACK,BLACK,WHITE,"BACK PAGE",mapID);
					taoButton(NEXTPAGECB,1175,460,1350,490,BLACK,BLACK,GRAY,"NEXT PAGE",mapID);
				}
				vitri=(tranghientai-1)*10+1;
					i=0;
					nodeCB *back;
					for (back = inMH ;  back != NULL  ;	) {
						i++;						
						   	if (i-vitri==0) {
							cb=back->data;//						
							clickcb(vitri,cb,mapID);
							break;				//		}
							}	
							back=back->next;
					}
				idcb=0;
			break;
			
			case CBLOCNGAY: 
				do {
					settextstyle(10, 0, 1);	
					idcb=CBLOCNGAY;
					Nhapso(410,65,idcb,mapID,locngay,2);
					if (ChangeCharToNum(locngay) > 31 || ChangeCharToNum(locngay) <=0 && strlen(locngay)!=0){
						MessageBox(NULL,"Ngay Khong Hop Le \n 1<= Ngay <= 31 !","THONG BAO",MB_ICONWARNING|MB_OK);
					}
				} while (ChangeCharToNum(locngay) > 31 || ChangeCharToNum(locngay) <=0 && strlen(locngay)!=0);
			break;
			
			case CBLOCTHANG:
					do {
					settextstyle(10, 0, 1);	
					idcb=CBLOCTHANG;
					Nhapso(465,65,idcb,mapID,locthang,2);
					
					if (ChangeCharToNum(locthang) > 12 || ChangeCharToNum(locthang) <=0 && strlen(locthang)!=0){
						MessageBox(NULL,"Thang Khong Hop Le \n 1<= Thang <= 12 !","THONG BAO",MB_ICONWARNING|MB_OK);
					}
				} while (ChangeCharToNum(locthang) > 12 || ChangeCharToNum(locthang) <=0 && strlen(locthang)!=0);
			break;
			case CBLOCNAM:
					do {
					settextstyle(10, 0, 1);	
					idcb=CBLOCNAM;
					Nhapso(520,65,idcb,mapID,locnam,4);
					if (ChangeCharToNum(locnam) > 2026 || ChangeCharToNum(locnam) <2024 && strlen(locnam)!=0){
						MessageBox(NULL,"Nam Khong Hop Le \n 2024<= Nam < 2026 !","THONG BAO",MB_ICONWARNING|MB_OK);
					}
				} while (ChangeCharToNum(locnam) > 2026 || ChangeCharToNum(locnam) <2024 && strlen(locnam)!=0);
			break;
			
			case CBMACB:
					settextstyle(10, 0, 1);	
					idcb=CBMACB;
					NhapLieu(740,65,idcb,mapID,locmacb);
			break;
			
			case CBDIEMDEN:
					settextstyle(10, 0, 1);	
					idcb=CBDIEMDEN;
					NhapLieuInHoa(1010,65,idcb,mapID,locdiemden,MAX_SBDEN);
			break;
			
			case CBLOC:
				slcb=0;
				tranghientai=1;
				trangcuoi=0;
				setfillstyle(1,WHITE);
				bar(300,140,1350,440);
				setcolor(BLACK);
				rectangle(300,140,1350,440);
				setID(0,300,140,1350,440,mapID);
				setbkcolor(WHITE);
				
				
 				for (nodechay=first ; nodechay != NULL ; nodechay=nodechay->next){	
 					if(
 					(strlen(locmacb)==0 || strcmp(locmacb,nodechay->data.MaCB)==0)
 					&& (strlen(locdiemden)==0 || strcmp(locdiemden,nodechay->data.SanBayDen)==0)
 					&& (strlen(locngay)==0 || ChangeCharToNum(locngay)==nodechay->data.time.ngay)
 					&& (strlen(locthang)==0 || ChangeCharToNum(locthang)==nodechay->data.time.thang) 
 					&& (strlen(locnam)==0 || ChangeCharToNum(locnam)==nodechay->data.time.nam) 		
 					)
 					{
 						slcb++;
 						if (slcb % 10 ==1){
 							trangcuoi++;
 						}
 					}
 				}
 				
 				
 				if (slcb>0) {
 					inMH=xuatdanhsachchuyenbayver2(mapID,first,tranghientai,cb, locmacb,  locdiemden,  locngay,  locthang,  locnam);
 				
 					vitri=(tranghientai-1)*10+1;
					i=0;
					nodeCB *loc;
					for (loc = inMH ;  back != NULL  ;	) {
						i++;						
						   	if (i-vitri==0) {
							cb=loc->data;//						
							clickcb(vitri,cb,mapID);
							break;				//		}
							}	
							loc=loc->next;
					}
				idcb=0;
// 				Save_file_chuyen_bay(first);
				if (slcb>10) {
					taoButton(NEXTPAGECB,1175,460,1350,490,BLACK,BLACK,GRAY,"NEXT PAGE",mapID);
				} else{
				
					taoLabel(1175,460,1350,490,BLACK,BLACK,WHITE,"NEXT PAGE");
					taoLabel(300,460,475,490,BLACK,BLACK,WHITE,"BACK PAGE");
				}
				} else {
					outtextxy(800-strlen("! DANH SACH TRONG !")*4,145,"! DANH SACH TRONG !");
				}
 				
				
				idcb=0;
			break;
			
			
			case 1000: case 1001:case  1002 :case 1003: case 1004 :case 1005: case 1006 :case 1007: case 1008: case 1009:
				
			unclickcb(vitri,cb,mapID);
			nodechay = inMH;
			vitri =idcb-1000+1+ (tranghientai-1)*10 ;
			
			for (int i=0 ;  i <= vitri-1 && nodechay !=NULL ;) {
				if(i==(vitri-1-(tranghientai-1)*10)) {
		   		cb=nodechay->data;
				clickcb(vitri,cb,mapID);
				break;
				}
				i++;
				nodechay=nodechay->next;
			}
			idcb=0;			
			break;
		
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




void hienThiDanhSachVe(unsigned short int **mapID, chuyenbay &cb,  int &veDangChon, ve &veMoi, danhsachmaybay &dsmb) {
	int soDay,soDong;
    int marginX = 300; // L? tr�i
    int marginY = 100; // L? tr�n
    int boxWidth = 50; // Chi?u r?ng c?a m?i �
    int boxHeight = 30; // Chi?u cao c?a m?i �
    int gap = 5; // Kho?ng c�ch gi?a c�c �

	soDay = dsmb.data[timkiem(dsmb,cb.SHMB)]->soday;
	soDong = dsmb.data[timkiem(dsmb,cb.SHMB)]->sodong;
    int index = 0;
    for (char day = 'A'; day < 'A' + soDay; day++) {
        for (int dong = 1; dong <= soDong; dong++) {
            if (index >= cb.sove) break;

            int x = marginX + (dong - 1) * (boxWidth + gap);
            int y = marginY + (day - 'A') * (boxHeight + gap);
			
            char soVe[5];
            sprintf(soVe, "%c%02d", day, dong);

            if (index == veDangChon) {
                // V� dang ch?n
                setfillstyle(SOLID_FILL, YELLOW);
            } else if (strcmp(cb.dsve[index].cccd, "")>0) {
                // V� d� d?t
                setfillstyle(SOLID_FILL, RED);
            } else {
                // V� chua d?t
                setfillstyle(SOLID_FILL, WHITE);
            }
			settextstyle(8, 0, 2);
            bar(x, y, x + boxWidth, y + boxHeight);
            rectangle(x, y, x + boxWidth, y + boxHeight);

            setbkcolor(index == veDangChon ? YELLOW : (cb.dsve[index].cccd[0] != '\0' ? RED : WHITE));
            setcolor(BLACK);
            outtextxy(x + (boxWidth - textwidth(soVe)) / 2, y + (boxHeight - textheight(soVe)) / 2, soVe);

            setID(index, x, y, x + boxWidth, y + boxHeight, mapID); // G�n id c?a v� v�o mapID d? x? l� s? ki?n click
            index++;
        }
    }

    // V? ch� th�ch
    setbkcolor(WHITE);
    outtextxy(CUASO_NGANG - 200, CUASO_DOC - 100, "Chua Dat");
    setfillstyle(SOLID_FILL, WHITE);
    bar(CUASO_NGANG - 250, CUASO_DOC - 100, CUASO_NGANG - 220, CUASO_DOC - 80);
    rectangle(CUASO_NGANG - 250, CUASO_DOC - 100, CUASO_NGANG - 220, CUASO_DOC - 80);

    setbkcolor(RED);
    outtextxy(CUASO_NGANG - 200, CUASO_DOC - 70, "Da Dat");
    setfillstyle(SOLID_FILL, RED);
    bar(CUASO_NGANG - 250, CUASO_DOC - 70, CUASO_NGANG - 220, CUASO_DOC - 50);
    rectangle(CUASO_NGANG - 250, CUASO_DOC - 70, CUASO_NGANG - 220, CUASO_DOC - 50);

    setbkcolor(YELLOW);
    outtextxy(CUASO_NGANG - 200, CUASO_DOC - 40, "Dang Chon");
    setfillstyle(SOLID_FILL, YELLOW);
    bar(CUASO_NGANG - 250, CUASO_DOC - 40, CUASO_NGANG - 220, CUASO_DOC - 20);
    rectangle(CUASO_NGANG - 250, CUASO_DOC - 40, CUASO_NGANG - 220, CUASO_DOC - 20);

    // V? th�ng tin v� dang ch?n v� n�t "�?t V�" v� "H?y"
    if (veDangChon != -1 && cb.dsve[veDangChon].cccd[0] == '\0') {
        int infoX = marginX;
        int infoY = marginY + soDay * (boxHeight + gap) + 50;

        setbkcolor(WHITE);
        setcolor(BLACK);
        outtextxy(infoX, infoY, "CMND:");
        outtextxy(infoX, infoY + 40, "Ho:");
        outtextxy(infoX, infoY + 80, "Ten:");
        outtextxy(infoX, infoY + 120, "Phai:");
        outtextxy(infoX, infoY + 160, "So ghe:");

        rectangle(infoX + 100, infoY, infoX + 300, infoY + 30);
        rectangle(infoX + 100, infoY + 40, infoX + 300, infoY + 70);
        rectangle(infoX + 100, infoY + 80, infoX + 300, infoY + 110);
        rectangle(infoX + 100, infoY + 120, infoX + 300, infoY + 150);
        rectangle(infoX + 100, infoY + 160, infoX + 300, infoY + 190);

        setfillstyle(SOLID_FILL, veMoi.cccd[0] != '\0' && veMoi.vitri[0] != '\0' ? WHITE : LIGHTGRAY);
        bar(infoX, infoY + 200, infoX + 200, infoY + 250);
        rectangle(infoX, infoY + 200, infoX + 200, infoY + 250);
        setbkcolor(veMoi.cccd[0] != '\0' && veMoi.vitri[0] != '\0' ? WHITE : LIGHTGRAY);
        outtextxy(infoX + 50, infoY + 215, "Dat Ve");

        setfillstyle(SOLID_FILL, WHITE);
        bar(infoX + 220, infoY + 200, infoX + 420, infoY + 250);
        rectangle(infoX + 220, infoY + 200, infoX + 420, infoY + 250);
        setbkcolor(WHITE);
        outtextxy(infoX + 270, infoY + 215, "Huy");
    }
}



void xulyve(unsigned short int **mapID, int &luu_id, chuyenbay &cb, danhsachmaybay &dsmb) {
    setfillstyle(1, WHITE);
    bar(250, 0, CUASO_NGANG, CUASO_DOC);

    settextstyle(10, 0, 4);
    taoLabel(575, 0, 975, 55, BLACK, BLACK, GRAY, "DANH SACH VE");

    int veDangChon = -1; // Kh?i t?o gi� tr? c?a v� dang ch?n l� -1 (chua ch?n v� n�o)
    ve veMoi; // Kh?i t?o v� m?i tr?ng
    strcpy(veMoi.cccd, "");
    strcpy(veMoi.vitri, "");
	int soDay,soDong;
	soDay = dsmb.data[timkiem(dsmb,cb.SHMB)]->soday;
	soDong = dsmb.data[timkiem(dsmb,cb.SHMB)]->sodong;
     hienThiDanhSachVe(mapID, cb, veDangChon, veMoi, dsmb);

    int idve = 0;
    int x, y;

    while (true) {
        if (ismouseclick(WM_LBUTTONDOWN)) {
            getmouseclick(WM_LBUTTONDOWN, x, y);
            idve = mapID[y][x];
            clearmouseclick(WM_LBUTTONDOWN);

            // Ki?m tra n?u idve h?p l?
            if (idve >= 0 && idve < cb.sove) {
                if (cb.dsve[idve].cccd[0] == '\0') { // V� chua du?c d?t
                    veDangChon = idve;
                    sprintf(veMoi.vitri, "%c%02d", 'A' + veDangChon / soDong, veDangChon % soDong + 1);
                     hienThiDanhSachVe(mapID, cb, veDangChon, veMoi, dsmb);
                }
            } else if (x >= 300 && x <= 500 && y >= 650 && y <= 700) { // V? tr� c?a n�t "�?t V�"
                // X? l� s? ki?n click v�o n�t "�?t V�"
                if (veMoi.cccd[0] != '\0' && veMoi.vitri[0] != '\0') {
                    strcpy(cb.dsve[veDangChon].cccd, veMoi.cccd);
                    strcpy(cb.dsve[veDangChon].vitri, veMoi.vitri);
                    veDangChon = -1; // Reset v� dang ch?n
                    strcpy(veMoi.cccd, ""); // Reset v� m?i
                    strcpy(veMoi.vitri, "");
                    hienThiDanhSachVe(mapID, cb, veDangChon, veMoi, dsmb);
                } else {
                    // Hi?n th? th�ng b�o y�u c?u nh?p d?y d? th�ng tin
                    setbkcolor(WHITE);
                    outtextxy(300, 720, "Vui long nhap day du thong tin!");
                }
            } else if (x >= 520 && x <= 720 && y >= 650 && y <= 700) { // V? tr� c?a n�t "H?y"
                // X? l� s? ki?n click v�o n�t "H?y"
                veDangChon = -1; // Reset v� dang ch?n
                strcpy(veMoi.cccd, ""); // Reset v� m?i
                strcpy(veMoi.vitri, "");
                hienThiDanhSachVe(mapID, cb, veDangChon, veMoi, dsmb);
            }
        }
        if (idve <= 6 && idve >= 1) { // Tho�t ra v�o ch?c nang kh�c
            luu_id = idve;
            break;
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
		if (idtk<=6 && idtk>=1)//thoat ra v?o chuc nang khac
		{
			luu_id=idtk;
			break;
		}
		switch(idtk){
			
		}
		delay(0.001);
	}
}

void vekhungkhachhang(unsigned short int ** mapID) {
	

	setfillstyle(1,WHITE);
	bar(250,0,CUASO_NGANG,CUASO_DOC);
	
	settextstyle(10, 0, 4);
	taoLabel(575,0,975,55,BLACK,BLACK,GRAY,"DANH SACH KHACH HANG");
	setusercharsize(1, 2, 1, 2);
    setbkcolor(WHITE);
    outtextxy(300 + 2 * 16 - textwidth("STT") / 2, 110, "STT");
    outtextxy(300 + 9 * 16 - textwidth("CMND") / 2, 110, "CMND");
    outtextxy(300 + 25 * 16 - textwidth("HO") / 2, 110, "HO");
    outtextxy(300 + 45 * 16 - textwidth("TEN") / 2, 110, "TEN");
    outtextxy(300 + 60 * 16 - textwidth("PHAI") / 2, 110, "PHAI");
    settextstyle(8, 0, 2);
    rectangle(300, 100, 1350, 440);
    line(300, 140, 1350, 140);
    line(300 + 4 * 16, 100, 300 + 4 * 16, 140);
    line(300 + 15 * 16, 100, 300 + 15 * 16, 140);
    line(300 + 35 * 16, 100, 300 + 35 * 16, 140);
    line(300 + 55 * 16, 100, 300 + 55 * 16, 140);
    line(300 + 65 * 16, 100, 300 + 65 * 16, 140);
}

// H�m highlight d�ng kh�ch h�ng du?c ch?n
void highlightKhachHang(int vitri, khachhang &kh, unsigned short int **mapID) {
    setfillstyle(SOLID_FILL, BLACK); // B�i den ho�n to�n d�ng
    bar(300, 150 + vitri * 30, 1350, 180 + vitri * 30);
    setcolor(WHITE); // Ch? m�u tr?ng
    setbkcolor(BLACK);
    settextstyle(8, 0, 2);
    
    char stt[3];
    sprintf(stt, "%d", vitri + 1);
    outtextxy(300 + 2 * 16 - textwidth(stt) / 2, 150 + vitri * 30, stt);
    outtextxy(300 + 9 * 16 - textwidth(kh.cmnd) / 2, 150 + vitri * 30, kh.cmnd);
    outtextxy(300 + 25 * 16 - textwidth(kh.ho) / 2, 150 + vitri * 30, kh.ho);
    outtextxy(300 + 45 * 16 - textwidth(kh.ten) / 2, 150 + vitri * 30, kh.ten);
    outtextxy(300 + 60 * 16 - textwidth(kh.phai) / 2, 150 + vitri * 30, kh.phai);
}

void inorderStore(Node* root, Node* nodeArray[], int &customerCount) {
    if (root != NULL) {
        inorderStore(root->left, nodeArray, customerCount);
        nodeArray[customerCount++] = root;
        inorderStore(root->right, nodeArray, customerCount);
    }
}

void inorderDisplay(Node* root, int &index, unsigned short int **mapID) {
    if (root != NULL) {
        inorderDisplay(root->left, index, mapID);
        khachhang kh = root->data;
        setbkcolor(WHITE);
        char stt[15];
        sprintf(stt, "%d", index + 1);
        outtextxy(300 + 2 * 16 - textwidth(stt) / 2, 150 + index * 30, stt);
        outtextxy(300 + 9 * 16 - textwidth(kh.cmnd) / 2, 150 + index * 30, kh.cmnd);
        outtextxy(300 + 25 * 16 - textwidth(kh.ho) / 2, 150 + index * 30, kh.ho);
        outtextxy(300 + 45 * 16 - textwidth(kh.ten) / 2, 150 + index * 30, kh.ten);
        outtextxy(300 + 60 * 16 - textwidth(kh.phai) / 2, 150 + index * 30, kh.phai);
        setID(1000 + index, 300, 150 + index * 30, 1350, 150 + (index + 1) * 30 - 1, mapID);
        index++;
        inorderDisplay(root->right, index, mapID);
    }
}



void displayCustomers(Node* nodeArray[], int customerCount, int page, unsigned short int** mapID) {
    int start = page * CUSTOMERS_PER_PAGE;
    int end = min(start + CUSTOMERS_PER_PAGE, customerCount);
	cout<<customerCount;
  for (int i = start; i < end; i++) {
    	settextstyle(8, 0, 2);
        khachhang kh = nodeArray[i]->data;
        setbkcolor(WHITE);
        char stt[3];
    	sprintf(stt, "%d ", i + 1);
        sprintf(stt, "%d", (i-start+1));
        outtextxy(300 + 2 * 16 - textwidth(stt) / 2, 150 + (i-start) * 30, stt);
        outtextxy(300 + 9 * 16 - textwidth(kh.cmnd) / 2, 150 + (i-start) * 30, kh.cmnd);
        outtextxy(300 + 25 * 16 - textwidth(kh.ho) / 2, 150 +(i-start)* 30, kh.ho);
        outtextxy(300 + 45 * 16 - textwidth(kh.ten) / 2, 150 + (i-start) * 30, kh.ten);
        outtextxy(300 + 60 * 16 - textwidth(kh.phai) / 2, 150 + (i-start) * 30, kh.phai);
        setID(1000 + (i-start), 300, 150 + (i-start) * 30, 1350, 150 + ((i-start) + 1) * 30 - 1, mapID);
    }
}

void xulykhachhang(unsigned short int **mapID, int &luu_id) {
    Node* root = NULL;

    // Ch�n d? li?u m?u v�o c�y AVL
    khachhang kh1 = {"123456789", "Nguyen", "Van A", "Nam"};
    khachhang kh2 = {"987654321", "Tran", "Thi B", "Nu"};
    khachhang kh3 = {"654321987", "Le", "Van C", "Nam"};
    khachhang kh4 = {"123456788", "Nguyen", "Van B", "Nam"};
    khachhang kh5 = {"987654322", "Tran", "Thi C", "Nu"};
    khachhang kh6 = {"654321988", "Le", "Van D", "Nam"};
    khachhang kh7 = {"123456787", "Nguyen", "Van E", "Nam"};
    khachhang kh8 = {"987654323", "Tran", "Thi F", "Nu"};
    khachhang kh9 = {"654321987", "Le", "Van G", "Nam"};
    khachhang kh10 = {"123456786", "Nguyen", "Van H", "Nam"};
    khachhang kh11 = {"987654324", "Tran", "Thi I", "Nu"};
    khachhang kh12 = {"654321986", "Le", "Van J", "Nam"};
    khachhang kh13 = {"123456785", "Nguyen", "Van K", "Nam"};
    khachhang kh14 = {"987654325", "Tran", "Thi L", "Nu"};
    
    root = insert(root, kh1);
    root = insert(root, kh2);
    root = insert(root, kh3);
    root = insert(root, kh4);
    root = insert(root, kh5);
    root = insert(root, kh6);
    root = insert(root, kh7);
    root = insert(root, kh8);
    root = insert(root, kh9);
    root = insert(root, kh10);
    root = insert(root, kh11);
    root = insert(root, kh12);
    root = insert(root, kh13);
    root = insert(root, kh14);

    // Kh?i t?o m?ng nodeArray v� customerCount
    Node* nodeArray[MAX_CUSTOMERS];
    int customerCount = 0;

    // Duy?t c�y AVL v� luu kh�ch h�ng v�o m?ng t?m
    inorderStore(root, nodeArray, customerCount);

    // V? khung v� hi?n th? danh s�ch kh�ch h�ng
    int currentPage = 0;
    int totalPages = (customerCount + CUSTOMERS_PER_PAGE - 1) / CUSTOMERS_PER_PAGE;
    
    vekhungkhachhang(mapID);
    displayCustomers(nodeArray, customerCount, currentPage, mapID);
    
    // V? n�t "Next" v� "Previous"
    taoButton(7, 1400, 750, 1500, 800, BLACK, BLACK, GRAY, "Next", mapID);
    taoButton(8, 1150, 750, 1250, 800, BLACK, BLACK, GRAY, "Previous", mapID);
    
    // V? s? trang
    char pageNumber[10];
    sprintf(pageNumber, "%d / %d", currentPage + 1, totalPages);
    outtextxy(1300, 760, pageNumber);

    int idkh = 0;
    int x, y;
    int vitri = -1;

    while (true) {
        if (ismouseclick(WM_LBUTTONDOWN)) {
            getmouseclick(WM_LBUTTONDOWN, x, y);
            idkh = mapID[y][x];
            clearmouseclick(WM_LBUTTONDOWN);
        }
        if (idkh <= 6 && idkh >= 1) { // tho�t ra v�o ch?c nang kh�c
            luu_id = idkh;
            break;
        }
        if (idkh >= 1000 && idkh < 1000 + CUSTOMERS_PER_PAGE) {
            int newVitri = idkh - 1000;
            if (vitri != -1) { // N?u d� c� d�ng du?c ch?n tru?c d�, kh�i ph?c l?i n?n tr?ng
                setfillstyle(SOLID_FILL, WHITE);
                bar(300, 150 + vitri * 30, 1350, 180 + vitri * 30);
                khachhang kh = nodeArray[currentPage * CUSTOMERS_PER_PAGE + vitri]->data;
                setcolor(BLACK);
                setbkcolor(WHITE);
                char stt[3];
                sprintf(stt, "%d", currentPage * CUSTOMERS_PER_PAGE + vitri + 1);
                outtextxy(300 + 2 * 16 - textwidth(stt) / 2, 150 + vitri * 30, stt);
                outtextxy(300 + 9 * 16 - textwidth(kh.cmnd) / 2, 150 + vitri * 30, kh.cmnd);
                outtextxy(300 + 25 * 16 - textwidth(kh.ho) / 2, 150 + vitri * 30, kh.ho);
                outtextxy(300 + 45 * 16 - textwidth(kh.ten) / 2, 150 + vitri * 30, kh.ten);
                outtextxy(300 + 60 * 16 - textwidth(kh.phai) / 2, 150 + vitri * 30, kh.phai);
            }
            vitri = newVitri;
            khachhang kh = nodeArray[currentPage * CUSTOMERS_PER_PAGE + vitri]->data;
            highlightKhachHang(vitri, kh, mapID);
            idkh=0;
        } else if (idkh == 7 && currentPage < totalPages - 1) { // Next button
            currentPage++;
            // V? l?i khung v� hi?n th? danh s�ch kh�ch h�ng cho trang ti?p theo
            vekhungkhachhang(mapID);
            displayCustomers(nodeArray, customerCount, currentPage, mapID);
            // V? l?i n�t "Next" v� "Previous"
		    taoButton(7, 1400, 750, 1500, 800, BLACK, BLACK, GRAY, "Next", mapID);
		    taoButton(8, 1150, 750, 1250, 800, BLACK, BLACK, GRAY, "Previous", mapID);
            // V? l?i s? trang
            sprintf(pageNumber, "%d / %d", currentPage + 1, totalPages);
            outtextxy(1300, 760, pageNumber);
            vitri = -1; // Reset d�ng du?c ch?n
        } else if (idkh == 8 && currentPage > 0) { // Previous button
            currentPage--;
            // V? l?i khung v� hi?n th? danh s�ch kh�ch h�ng cho trang tru?c d�
            vekhungkhachhang(mapID);
            displayCustomers(nodeArray, customerCount, currentPage, mapID);
            // V? l?i n�t "Next" v� "Previous"
		    taoButton(7, 1400, 750, 1500, 800, BLACK, BLACK, GRAY, "Next", mapID);
		    taoButton(8, 1150, 750, 1250, 800, BLACK, BLACK, GRAY, "Previous", mapID);
            // V? l?i s? trang
            sprintf(pageNumber, "%d / %d", currentPage + 1, totalPages);
            outtextxy(1300, 760, pageNumber);
            vitri = -1; // Reset d�ng du?c ch?n
        }
        delay(0.001);
    }

    // Gi?i ph�ng b? nh? khi kh�ng c�n s? d?ng n?a
    deleteTree(root);
}


// H�m hi?n th? danh s�ch v� c?a m?t chuy?n bay


// H�m x? l� hi?n th? danh s�ch v� c?a chuy?n bay

