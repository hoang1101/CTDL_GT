#pragma once

#include "define.h"
#include <cctype>
#include <iostream>
#include "maybay.h"
#include "chuyenbay.h"
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


char *Chuan_Hoa(char *a)// chuan hoa nhap vao, chuyen thanh dang Anh Em Oi  
{


    strlen(a);
	int start=0;
	char *res='\0';
	while(start< strlen(a) && a[start]==' ') start++;
	if(start== strlen(a)) return res;
	if(a[start]>='a'&&a[start<='z']) a[start]+='A'-'a';
	res+=a[start];
	for(int i=start+1;i< strlen(a);i++)
	{
		if(a[i-1]!=' '&&a[i]!=' ')
		{
			if(a[i]>='A'&&a[i]<='Z') 
			a[i]+='a'-'A';
			res+=a[i];
		}
		else if(a[i-1]==' '&&a[i]!=' ') {
			if(a[i]>='a'&&a[i]<='z') a[i]+='A'-'a';
			res+=a[i];
		}
	}
	int i,j;
	int n=strlen(a);
		for(i=0;i<n;i++)
		{
		if((a[i]==' ')&&(a[i+1]==' '))
		{
			for(j=i;j<n;j++)
			{
				a[j]=a[j+1];
			}
			n--;
			i--; 
		}
	}
		
	return res;
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
					} else if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z' ) || (c == ' ')) {
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


void NhapLieuInHoa(int x, int y, int &id,unsigned short int ** mapID ,char s[]){
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
			    s[strlen(s)-1]='\0';
			  	return ;
				}
	      	  
	      	  	if(kbhit()) {
	      	  	char c= getch();
	      	  	if(c==8){
				if(l>0)
				{
					s[l-1]='\0';
					s[l]=' ';
					outtextxy(x,y,s);
					l--;	
				}	
				} 
				else if(c!=13 && c>='a' && c<='z' )  {
					c=c-32;
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

void Nhapso(int x, int y ,int &luu_id,unsigned short int ** mapID, char s[],int chieudai)
{
	int x1=x;
	int y1=y;
	setbkcolor(WHITE);
	setcolor(BLACK);
	int l=strlen(s) ;
	s[l+1]='\0';
    s[l]='|'; 
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
//			l--;
			return;
		}
		else
		{
			x=x1;
			y=y1;
		}
     	if(kbhit()){
	     	char c= getch();
	     	if(strlen(s)<=chieudai && '0'<=c&&c<='9')
			{
		     	s[l]=c;
				l++;
				s[l+1]='\0';
				outtextxy(x,y,s);
			}
			else if(c==8){
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
    taoEditText(ED_SHMB,500,580,900,630,BLACK,BLACK,GRAY,mapID);
    taoEditText(ED_LOAIMB,570,665,900,715,BLACK,BLACK,GRAY,mapID);
    
    taoEditText(ED_SODAY,1150,580,1340,630,BLACK,BLACK,GRAY,mapID);
    taoEditText(ED_SODONG,1150,665,1340,715,BLACK,BLACK,GRAY,mapID);
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
		outtextxy(x+58*16+(1300-x-58*16)/2-textwidth(toChars(mb.soday))/2,y+10,toChars(mb.soday));
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
	resetmb(mb);
	int tranghientai = 1;
	int trangcuoi = ceil(dsmb.soluong/10.0);
	char day[50]="";
	char dong[50]="";
	int idmb = 0;
	int x,y;
	int vitri =0;
	
	
	vekhungmaybay(mapID);
	vekhungnhaplieu(mapID);
	
	if (Empty(dsmb)) {
//		settextstyle(8,0,2);
		outtextxy(825-strlen("! DANH SACH TRONG !")*4,135,"! DANH SACH TRONG !");
		
	   	taoButton(0,790,510,860,540,BLACK,BLACK,GRAY,"XOA",mapID);
    	taoButton(0,910,510,980,540,BLACK,BLACK,GRAY,"SUA",mapID);

	} else {
		for(int i=0; i< dsmb.soluong ;i++){
		taodongmb(i+1,300,130+i*30,1350,160+i*30,*dsmb.data[i],mapID);
		setID(1000+i,300,130+i*30,1350,160+i*30,mapID);
//		cout<<*dsmb.data[i]->loaimaybay<<endl;
		mb=*dsmb.data[0];
		vitri=1;
		clickmb(mb,1,mapID);
		}
	}
	
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
				if (FullDS(dsmb)) {
					MessageBox(NULL,"So luong may bay vuot qua gioi han cho phep !","ERROR!",MB_ICONWARNING|MB_OK);
				}
				else {
					unclickmb(mb,vitri,mapID);
				resetmb(mb);
				resetthanhchucnangmb(mapID);
				day[0]='\0';
				dong[0]='\0';
				taoButton(LUU_MB,720,510,790,540,BLACK,BLACK,GRAY,"LUU",mapID);
				taoButton(HUY_MB,840,510,910,540,BLACK,BLACK,GRAY,"HUY",mapID);
				
				taoEditText(ED_SHMB,500,580,900,630,BLACK,BLACK,WHITE,mapID);
			    taoEditText(ED_LOAIMB,570,665,900,715,BLACK,BLACK,WHITE,mapID);
			    taoEditText(ED_SODAY,1150,580,1340,630,BLACK,BLACK,WHITE,mapID);
			    taoEditText(ED_SODONG,1150,665,1340,715,BLACK,BLACK,WHITE,mapID);
				}
			
				idmb=0;
			break;
			case LUU_MB: 
			
				add_may_bay(dsmb,mb);
				Save_file_MB(dsmb);
			 	if((dsmb.soluong % 10   == 1)) {
						trangcuoi++;
						  if(trangcuoi-tranghientai ==1 )
					         taoButton(55,1200,450,1275,480,BLACK,BLACK,WHITE,"NEXT",mapID);
					  }
					  if(tranghientai==trangcuoi ){
						if((dsmb.soluong==1) || (dsmb.soluong % 10 != 1)){
							vitri=dsmb.soluong ;
					     taodongmb(vitri,300,130+(vitri-1)%10*30,1350,160+(vitri-1)%10*30,*dsmb.data[vitri-1],mapID);
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
			    
				taoEditText(ED_SHMB,500,580,900,630,BLACK,BLACK,GRAY,mapID);
			    taoEditText(ED_LOAIMB,570,665,900,715,BLACK,BLACK,GRAY,mapID);
			    
			    taoEditText(ED_SODAY,1150,580,1340,630,BLACK,BLACK,GRAY,mapID);
			    taoEditText(ED_SODONG,1150,665,1340,715,BLACK,BLACK,GRAY,mapID);
			    idmb=0;
			break;		
			
			case MB_SUA:
				resetthanhchucnangmb(mapID);
				taoButton(LUU_MBEDIT,720,510,790,540,BLACK,BLACK,GRAY,"LUU",mapID);
				taoButton(HUY_MBEDIT,840,510,910,540,BLACK,BLACK,GRAY,"HUY",mapID);
				
				taoEditText(ED_SHMB,500,580,900,630,BLACK,BLACK,GRAY,mapID);
				setbkcolor(WHITE);
	        	outtextxy(505,595,mb.sohieumaybay);
				
			    taoEditText(ED_LOAIMB,570,665,900,715,BLACK,BLACK,GRAY,mapID);
			    setbkcolor(WHITE);
	        	outtextxy(575,680,mb.loaimaybay);
			    
			    strcpy(day,toChars(mb.soday));
			    taoEditText(ED_SODAY,1150,580,1340,630,BLACK,BLACK,GRAY,mapID);
			    setbkcolor(WHITE);
	        	outtextxy(1155,595,toChars(mb.soday));
	        	
				strcpy(dong,toChars(mb.sodong));
			    taoEditText(ED_SODONG,1150,665,1340,715,BLACK,BLACK,GRAY,mapID);
				setbkcolor(WHITE);
	        	outtextxy(1155,680,toChars(mb.sodong));
				idmb=0;
				break;
			
			case HUY_MB:
				resetthanhchucnangmb(mapID);
				taoButton(11,670,510,740,540,BLACK,BLACK,GRAY,"THEM",mapID);
				taoButton(12,790,510,860,540,BLACK,BLACK,GRAY,"XOA",mapID);
			    taoButton(13,910,510,980,540,BLACK,BLACK,GRAY,"SUA",mapID);
			 
			    idmb=0;
			break;
			
			case HUY_MBEDIT:
				resetthanhchucnangmb(mapID);
				taoButton(11,670,510,740,540,BLACK,BLACK,GRAY,"THEM",mapID);
				taoButton(12,790,510,860,540,BLACK,BLACK,GRAY,"XOA",mapID);
			    taoButton(13,910,510,980,540,BLACK,BLACK,GRAY,"SUA",mapID);
			 
			    idmb=0;
			break;
			
			case LUU_MBEDIT: 
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
				if (MessageBox(NULL,"Xac Nhan Xoa ","THONG BAO",MB_ICONWARNING|MB_OKCANCEL) == IDOK){
					cout<<vitri;
					delete_mb(dsmb,vitri-1);
					Save_file_MB(dsmb);
					setfillstyle(1,WHITE);
		        	bar(301,131+(vitri-1) % 10*30,1350,430);
		        	setcolor(BLUE);
		        	for(int i=(vitri-1)%10; i+(tranghientai-1)*10 < dsmb.soluong && i < 10 ;i++ )
		     		   taodongmb(i+1+(tranghientai-1)*10,300,130+i*30,1350,160+i*30,*dsmb.data[i+(tranghientai-1)*10],mapID);
				}
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
		     						idmb=1;
								 }
								if(trangcuoi == tranghientai){
									 taoButton(0,1200,450,1275,480,BLACK,BLACK,GRAY,"NEXT",mapID);
								}
						 	}
					 	}
					 	
				else {
						if(trangcuoi == tranghientai)
							setID(0,300,130+(dsmb.soluong % 10)*30,1350,160+(dsmb.soluong % 10)*30,mapID);
					}
								 
				if( !Empty(dsmb)){
     	      			mb = *dsmb.data[(tranghientai-1)*10];
						vitri=(tranghientai-1)*10+1;
						clickmb(mb,vitri,mapID);
						rectangle(300,130+(1-1)%10*30,1350,160+(1-1)%10*30);
					}

				idmb=0;
				break;
			case ED_SHMB:
				idmb = ED_SHMB;
				NhapLieu(505,595,idmb,mapID,mb.sohieumaybay);
				break;
			case ED_LOAIMB:
				idmb = ED_LOAIMB;
				NhapLieu(575,680,idmb,mapID,mb.loaimaybay);
				break;
			case ED_SODAY:
				idmb = ED_SODAY;
				Nhapso(1155,595,idmb,mapID,day,3);
				mb.soday=ChangeCharToNum(day);
				break;
			case ED_SODONG:
				idmb = ED_SODONG;
				Nhapso(1155,680,idmb,mapID,dong,3);
				mb.sodong=ChangeCharToNum(dong);		
				break;
			case 1000:case 1001:case  1002 :case 1003: case 1004 :case 1005: case 1006 :case 1007: case 1008: case 1009:
	        	
				cout<<vitri;
				unclickmb(mb,vitri,mapID);
				vitri = idmb-1000+1;
				mb=*dsmb.data[idmb-1000];
				clickmb(mb,vitri,mapID);
				idmb = 0;
				break;
		}
		delay(0.001);
	}
}


////////////////////////////////// CHUYEN BAY /////////////////////////////////
void resetthanhchucnangcb(unsigned short int ** mapID) {
	setID(0,300,500,1350,550,mapID);
	
	setfillstyle(1,WHITE);
	bar(302,502,1349,549);
}

void vekhungchuyenbay(unsigned short int ** mapID) {
	

	setfillstyle(1,WHITE);
	bar(250,0,CUASO_NGANG,CUASO_DOC);
	
	settextstyle(10, 0, 4);
	taoLabel(595,0,995,55,BLACK,BLACK,GRAY,"DANH SACH CHUYEN BAY");
	
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
	
}

void nhaplieuchuyenbay(unsigned short int ** mapID) {
	settextstyle(10, 0, 2);	
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
    
    taoEditText(ED_MACB,510,565,800,615,BLACK,BLACK,GRAY,mapID);
    taoEditText(ED_LOAIMB,510,625,900,675,BLACK,BLACK,GRAY,mapID);
    
    taoEditText(ED_SHMBCB,960,565,1340,615,BLACK,BLACK,GRAY,mapID);
    taoEditText(ED_TT,1160,625,1340,675,BLACK,BLACK,GRAY,mapID);
    
    taoEditText(ED_NGAY,420,685,480,735,BLACK,BLACK,GRAY,mapID);
    taoEditText(ED_THANG,610,685,670,735,BLACK,BLACK,GRAY,mapID);
    taoEditText(ED_NAM,800,685,900,735,BLACK,BLACK,GRAY,mapID);
    
    taoEditText(ED_GIO,1080,685,1140,735,BLACK,BLACK,GRAY,mapID);
    taoEditText(ED_PHUT,1160,685,1220,735,BLACK,BLACK,GRAY,mapID);
}

void taodongcb(int stt, int x, int y, int x1, int y1, chuyenbay &cb, unsigned short int **mapID){
		setcolor(BLACK);
		settextstyle(8, 0, 0);
		setusercharsize(1,2,1,2);
		
		line(x,y1,x1,y1);
		line(x+4*16,y,x+4*16,y1);
		line(x+12*16,y,x+12*16,y1);
		line(x+25*16,y,x+25*16,y1);
		line(x+40*16,y,x+40*16,y1);
		line(x+55*16,y,x+55*16,y1);
		
//		if(isclick)
//			setbkcolor(RED);
//		else f
			setbkcolor(WHITE);
		outtextxy(x+2*16-textwidth(toChars(stt))/2,y+10,toChars(stt));
		outtextxy(x+8*16-textwidth(cb.MaCB)/2,y+10,cb.MaCB);
		outtextxy(x+18*16-textwidth(cb.SHMB)/2,y+10,cb.SHMB);
		outtextxy(x+32*16-textwidth("thoigian")/2,y+10,"thoigian");
		outtextxy(x+47*16-textwidth(cb.SanBayDen)/2,y+10,cb.SanBayDen);
		
		if(cb.trangthai == 0)
			 outtextxy(x+58*16+(1300-x-58*16)/2-textwidth("HUYCHUYEN")/2,y+10,"HUYCHUYEN");
		else if(cb.trangthai == 1)
		    
		      outtextxy(x+58*16+(1300-x-58*16)/2-textwidth("CONVE")/2,y+10,"CONVE");
		 else if(cb.trangthai == 2)
		     
		      outtextxy(x+58*16+(1300-x-58*16)/2-textwidth("HETVE")/2,y+10,"HETVE");
		     
		else 
		      outtextxy(x+58*16+(1300-x-58*16)/2-textwidth("HOANTAT")/2,y+10,"HOANTAT");
		settextstyle(0, 0, 2);	
	

}



void xulychuyenbay(unsigned short int ** mapID, int &luu_id, PTR &first) {
	
	PTR nodechay;
	chuyenbay cb;
	vekhungchuyenbay(mapID);
	nhaplieuchuyenbay(mapID);
	nhaplieuchuyenbay(mapID);
	char s[50];
	
	int slcb =0;
	for(nodechay = first; nodechay != NULL; nodechay = nodechay -> next ){
				slcb++;
				if(slcb <=10){
					taodongcb(slcb,300,110+slcb*30,1350,140+slcb*30,nodechay->data,mapID);
		     		setID(1000+slcb,300,110+slcb*30,1350,140+slcb*30,mapID);
				}
//				if (slcb % 10 ==1){	
//					trangcuoi++;
//					dautrang[trangcuoi] = new nodeCB;
//				   dautrang[trangcuoi]= nodechay;
//					}
			}

	
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
			case CB_THEM: 
				cout<<"them";
				resetcb(cb);
				resetthanhchucnangcb(mapID);
				s[0]='\0';
				taoButton(CB_LUU,720,510,790,540,BLACK,BLACK,GRAY,"LUU",mapID);
				taoButton(CB_HUYLUU,840,510,910,540,BLACK,BLACK,GRAY,"HUY",mapID);
				
				taoEditText(ED_MACB,510,565,800,615,BLACK,BLACK,WHITE,mapID);
			    taoEditText(ED_DIEMDEN,510,625,900,675,BLACK,BLACK,WHITE,mapID);
			    
			    taoEditText(ED_SHMBCB,960,565,1340,615,BLACK,BLACK,WHITE,mapID);
			    taoEditText(ED_TT,1160,625,1340,675,BLACK,BLACK,WHITE,mapID);
			    
			    taoEditText(ED_NGAY,420,685,480,735,BLACK,BLACK,WHITE,mapID);
			    taoEditText(ED_THANG,610,685,670,735,BLACK,BLACK,WHITE,mapID);
			    taoEditText(ED_NAM,800,685,900,735,BLACK,BLACK,WHITE,mapID);
			    
			    taoEditText(ED_GIO,1080,685,1140,735,BLACK,BLACK,WHITE,mapID);
			    taoEditText(ED_PHUT,1160,685,1220,735,BLACK,BLACK,WHITE,mapID);
				idcb=0;
			break;
			
			case CB_HUYCB:
				cout<<"xoa";
			break;
			
			case CB_SUA:
				cout<<"sua";
			break;
			
			case CB_LUU:
				resetthanhchucnangcb(mapID);
				settextstyle(10, 0, 2);	
				taoButton(CB_THEM,670,510,740,540,BLACK,BLACK,GRAY,"THEM",mapID);
				taoButton(CB_HUYCB,790,510,880,540,BLACK,BLACK,GRAY,"HUY CB",mapID);
			    taoButton(CB_SUA,930,510,1000,540,BLACK,BLACK,GRAY,"SUA",mapID);
			    idcb=0;
				cout<<"luu";
			break;
			
			case CB_HUYLUU:
				resetthanhchucnangcb(mapID);
				settextstyle(10, 0, 2);	
				taoButton(CB_THEM,670,510,740,540,BLACK,BLACK,GRAY,"THEM",mapID);
				taoButton(CB_HUYCB,790,510,880,540,BLACK,BLACK,GRAY,"HUY CB",mapID);
			    taoButton(CB_SUA,930,510,1000,540,BLACK,BLACK,GRAY,"SUA",mapID);
			    idcb=0;
				cout<<"huy luu";
			break;
			
			case ED_MACB:
				idcb = ED_MACB;
				NhapLieu(515,580,idcb,mapID,cb.MaCB);
			break;
			
			case ED_SHMBCB:
				idcb = ED_SHMBCB;
				NhapLieu(965,580,idcb,mapID,cb.SHMB);
			break;
			
			case ED_DIEMDEN:
				idcb = ED_DIEMDEN;
				NhapLieuInHoa(515,640,idcb,mapID,cb.SanBayDen);
			break;
			case ED_TT:
				outtextxy(1165,640,"CON_VE");
			break;
			
			case ED_NGAY:
				idcb= ED_NGAY;
				Nhapso(430,700,idcb,mapID,s,2);
				 s[0]='\0';
			break;
//			 taoEditText(ED_NGAY,420,685,480,735,BLACK,BLACK,WHITE,mapID);
//			    taoEditText(ED_THANG,610,685,670,735,BLACK,BLACK,WHITE,mapID);
//			    taoEditText(ED_NAM,800,685,890,735,BLACK,BLACK,WHITE,mapID);
//			    
//			    taoEditText(ED_GIO,1080,685,1140,735,BLACK,BLACK,WHITE,mapID);
//			    taoEditText(ED_PHUT,1160,685,1220,735,BLACK,BLACK,WHITE,mapID);
			case ED_THANG:
				idcb= ED_THANG;
				Nhapso(620,700,idcb,mapID,s,2);
				 s[0]='\0';
			break;
			
			case ED_NAM:
				idcb= ED_NAM;
				Nhapso(815,700,idcb,mapID,s,4);
				 s[0]='\0';
			break;

			case ED_GIO:
				cout<<"huy luu";
			break;
			
			case ED_PHUT:
				cout<<"huy luu";
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


