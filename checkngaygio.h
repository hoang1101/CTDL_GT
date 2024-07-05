#pragma once
#include <ctime>

int ngay_thang[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};

bool NamNhuan(int nam) {
    if (nam % 400 == 0) return true;
    else if (nam % 100 != 0 && nam % 4 == 0) return true;
    return false;
}

bool KiemTra(Time a) {
    if (a.thang == 2) {
        if (NamNhuan(a.nam)) {
            if (a.ngay > 29) 
                return false;
            return true;
        } else {
            if (a.ngay > 28) 
                return false;
            return true;
        }
    } else {
        if (a.ngay > ngay_thang[a.thang])
            return false;
        return true;
    }
}

Time LayThoiGianHienTai() {
    Time hien_tai;
    time_t bay_gio = time(0);
    tm *ltm = localtime(&bay_gio);

    hien_tai.ngay = ltm->tm_mday;
    hien_tai.thang = 1 + ltm->tm_mon;
    hien_tai.nam = 1900 + ltm->tm_year;
    hien_tai.gio = ltm->tm_hour;
    hien_tai.phut = ltm->tm_min;

    return hien_tai;
}

bool ThoiGianQuaKhu(Time qk) {
    if (KiemTra(qk) == false)
        return false;
    Time ht = LayThoiGianHienTai();
    if (ht.nam < qk.nam) return false;
    else if (ht.nam > qk.nam) return true;
    else {
        if (ht.thang < qk.thang) return false;
        else if (ht.thang > qk.thang) return true;
        else {
            if (ht.ngay < qk.ngay) return false;
            else if (ht.ngay > qk.ngay) return true;
            else {
                if (ht.gio < qk.gio) return false;
                else if (ht.gio > qk.gio) return true;
                else {
                    if (ht.phut < qk.phut) return false;
                    else if (ht.phut > qk.phut) return true;
                    else
                        return true;
                }
            }
        }
    }
}

bool ThoiGianTuongLai(Time tl) {
    if (KiemTra(tl) == false)
        return false;
    Time ht = LayThoiGianHienTai();
    if (ht.nam > tl.nam) return false;
    else if (ht.nam < tl.nam) return true;
    else {
        if (ht.thang > tl.thang) return false;
        else if (ht.thang < tl.thang) return true;
        else {
            if (ht.ngay > tl.ngay) return false;
            else if (ht.ngay < tl.ngay) return true;
            else {
                if (ht.gio > tl.gio) return false;
                else if (ht.gio < tl.gio) return true;
                else {
                    if (ht.phut > tl.phut) return false;
                    else if (ht.phut < tl.phut) return true;
                    else
                        return false;
                }
            }
        }
    }
}

void kiemtra_thoigian_khoihanh(nodeCB *temp, danhsachmaybay &dsmb) {
    if (temp->data.trangthai == CON_VE || temp->data.trangthai == HET_VE) {
        if (ThoiGianQuaKhu(temp->data.time)) {  
            temp->data.trangthai = HOAN_TAT;
            int index = timkiem(dsmb, temp->data.SHMB);
            if (index != -1) {
                dsmb.data[index]->soChuyenDaBay++;
            }
        }
    }
}

void kiemtra_thoigian_khoihanh_all(nodeCB *&first, danhsachmaybay &dsmb) {
    nodeCB *nodeChay;
    for (nodeChay = first; nodeChay != NULL; nodeChay = nodeChay->next) {
        kiemtra_thoigian_khoihanh(nodeChay, dsmb);
    }
}
