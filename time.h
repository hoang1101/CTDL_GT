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

    // Chuy?n d?i th?i gian hi?n t?i th�nh c?u tr�c tm
    tm* localTime = localtime(&currentTime);

    // L?y ra ng�y, th�ng, nam
    now.ngay = localTime->tm_mday;
    now.thang = localTime->tm_mon + 1; // Th�ng trong C++ t�nh t? 0 (0 l� th�ng 1)
    now.nam = localTime->tm_year + 1900; // Nam t�nh t? 1900
    now.gio = localTime->tm_hour;
    now.phut = localTime->tm_min;

    return now;
}



