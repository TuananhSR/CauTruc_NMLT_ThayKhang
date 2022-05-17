#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

struct Ngay
{
	int Ngay;
	int Thang;
	int Nam;
};
typedef struct Ngay NGAY;

struct HopSua
{
	string NhanHieu;
	float TrongLuong;
	NGAY HanDung;
};
typedef struct HopSua HOPSUA;

void Nhap(NGAY&);
void Xuat(NGAY);

void Nhap(HOPSUA&);
void Xuat(HOPSUA);

int main()
{
	HOPSUA hs;
	Nhap(hs);
	Xuat(hs);
	return 0;
}

void Nhap(NGAY& x)
{
	cout << "\nNhap ngay: ";
	cin >> x.Ngay;
	cout << "Nhap thang: ";
	cin >> x.Thang;
	cout << "Nhap nam: ";
	cin >> x.Nam;
}

void Xuat(NGAY x)
{
	cout << "\nNgay: " << x.Ngay << endl;
	cout << "Thang: " << x.Thang << endl;
	cout << "Nam: " << x.Nam << endl;
}

void Nhap(HOPSUA& x)
{
	cout << "Nhap nhan hieu: ";
	getline(cin, x.NhanHieu);
	cout << "Nhap trong luong: ";
	cin >> x.TrongLuong;
	cout << "Nhap han su dung: ";
	Nhap(x.HanDung);
}

void Xuat(HOPSUA x)
{
	cout << "\nNhan hieu: " << x.NhanHieu << endl;
	cout << "Trong luong: " << x.TrongLuong <<endl;
	cout << "Han su dung: ";
	Xuat(x.HanDung);
}
