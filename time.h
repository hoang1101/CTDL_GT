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

bool is_valid_time(Time t) {
    // Ki?m tra nam
    if (t.nam < 1900) {
        return false;
    }

    // Ki?m tra tháng
    if (t.thang < 1 || t.thang > 12) {
        return false;
    }

    // Ki?m tra ngày
    if (t.ngay < 1 || t.ngay > day[t.thang]) {
        // N?u là nam nhu?n, tháng 2 có 29 ngày
        if (t.thang == 2 && t.ngay == 29 && (t.nam % 4 == 0 && (t.nam % 100 != 0 || t.nam % 400 == 0))) {
            // H?p l?
        } else {
            return false;
        }
    }

//     Ki?m tra gi?
    if (t.gio < 0 || t.gio > 23) {
        return false;
    }

    // Ki?m tra phút
    if (t.phut < 0 || t.phut > 59) {
        return false;
    }

    return true;
}

bool TGquakhu(Time past_time) {
	
//	if(is_valid_time(past_time) == false)
//	return false;
    // L?y th?i gian hi?n t?i
    Time now = time_now();

    // So sánh t?ng thành ph?n c?a th?i gian
    if (now.nam > past_time.nam) {
        return true;
    } else if (now.nam == past_time.nam) {
        if (now.thang > past_time.thang) {
            return true;
        } else if (now.thang == past_time.thang) {
            if (now.ngay > past_time.ngay) {
                return true;
            } 
			else if (now.ngay == past_time.ngay) {
                if (now.gio > past_time.gio) {
                    return true;
                } else if (now.gio == past_time.gio) {
                    if (now.phut > past_time.phut) {
                        return true;
                    }
                }
            }
        }
    }

    // N?u t?t c? các thành ph?n d?u không l?n hon, thì th?i gian hi?n t?i không l?n hon th?i gian trong quá kh?
    return false;
}


bool TGNew(Time new_time) {
	
//	if(is_valid_time(past_time) == false)
//	return false;
    // L?y th?i gian hi?n t?i
    Time now = time_now();

   if(now.nam > new_time.nam ) return false;
	else if(now.nam < new_time.nam) return true;
	else
	{
		if(now.thang > new_time.thang ) return false;
	    else if(now.thang < new_time.thang) return true;
	    else
	    {
		     if(now.ngay > new_time.ngay ) return false;
	         else if(now.ngay < new_time.ngay) return true;
	         else 
	         	return false;
//	         else
//	         {
//		          if(now.gio > new_time.gio ) return false;
//	              else if(now.gio < new_time.gio) return true;
//	              else
//	              {
//		                if(now.phut > new_time.phut ) return false;
//                     	else if(now.phut < new_time.phut) return true;
//                     	else
//                     	   return false;
//	              }
//	         }
	    }
	}
}

