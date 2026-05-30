#include "KhachHangA.h"

double KhachHangA::tinhTienTra() {
	tienTra = (soLuongHang * donGiaHang) * (1 + VAT);
	return tienTra;
}