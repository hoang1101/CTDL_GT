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

unsigned long int ChuyenNgay(Time Tg) {
    unsigned long int so_ngay_trong_nam = 365 * (Tg.nam - 1) + (Tg.nam - 1) / 4 - (Tg.nam - 1) / 100 + (Tg.nam - 1) / 400;
    unsigned long int so_ngay_trong_thang = 0;
    for (int i = 0; i < Tg.thang; i++) {
        so_ngay_trong_thang += ngay_thang[i];
    }
    if (NamNhuan(Tg.nam) && Tg.thang > 2) {
        so_ngay_trong_thang += 1;
    }
    return so_ngay_trong_nam + so_ngay_trong_thang + Tg.ngay - 1;
}

bool TrongVongBaGio(Time Time1, Time Time2) {
    unsigned long int SoPhut_T1 = ChuyenNgay(Time1) * 24 * 60 + Time1.gio * 60 + Time1.phut;
    unsigned long int SoPhut_T2 = ChuyenNgay(Time2) * 24 * 60 + Time2.gio * 60 + Time2.phut;

    if (abs(SoPhut_T1 - SoPhut_T2) <= 180)
        return true;

    return false;
}

bool ThoiGian30PhutTruocBay(Time TimeDuKien) {
    Time hien_tai = LayThoiGianHienTai();
    unsigned long int SoPhut_T1 = ChuyenNgay(TimeDuKien) * 24 * 60 + TimeDuKien.gio * 60 + TimeDuKien.phut;
    unsigned long int SoPhut_now = ChuyenNgay(hien_tai) * 24 * 60 + hien_tai.gio * 60 + hien_tai.phut;
    if ((SoPhut_T1 > SoPhut_now) && (SoPhut_T1 - SoPhut_now) < 30)
        return true;

    return false;
}

bool ThoiGianCamThemChuyenBay(Time TimeDuKien) {
    Time hien_tai = LayThoiGianHienTai();
    unsigned long int SoPhut_T1 = ChuyenNgay(TimeDuKien) * 24 * 60 + TimeDuKien.gio * 60 + TimeDuKien.phut;
    unsigned long int SoPhut_now = ChuyenNgay(hien_tai) * 24 * 60 + hien_tai.gio * 60 + hien_tai.phut;
    if ((SoPhut_T1 > SoPhut_now) && (SoPhut_T1 - SoPhut_now) < 300)
        return true;

    return false;
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
