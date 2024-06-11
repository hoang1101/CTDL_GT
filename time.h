#pragma once
#include <ctime>
int day[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};

struct Time {
	int nam;
	int thang;
	int ngay;
	int gio;
	int phut;
};


Time time_now(){

	Time now;
	time_t currentTime = time(0);

    // Chuy?n d?i th?i gian hi?n t?i thành c?u trúc tm
    tm* localTime = localtime(&currentTime);

    // L?y ra ngày, tháng, nam
    now.ngay = localTime->tm_mday;
    now.thang = localTime->tm_mon + 1; // Tháng trong C++ tính t? 0 (0 là tháng 1)
    now.nam = localTime->tm_year + 1900; // Nam tính t? 1900
    now.gio = localTime->tm_hour;
    now.phut = localTime->tm_min;

    return now;
}



