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

struct DaiLy
{
	string MaSo;
	string TenDaiLy;
	int DienThoai;
	NGAY NgayNhan;
	string DiaChi;
	string EMail;
};
typedef struct DaiLy DAILY;

void Nhap(NGAY&);
void Xuat(NGAY);

void Nhap(DAILY&);
void Xuat(DAILY);

void Nhap(DAILY[], int&);
void Xuat(DAILY[], int);
void TimKiem(DAILY[], int, string);

int main()
{
	DAILY dl[100];
	int n;
	Nhap(dl, n);
	Xuat(dl, n);

	string ten;
	TimKiem(dl, n, ten);
	return 0;
}

void Nhap(NGAY& x)
{
	cout << "\nNhap ngay:";
	cin >> x.Ngay;
	cout << "Nhap thang:";
	cin >> x.Thang;
	cout << "Nhap nam:";
	cin >> x.Nam;
}

void Xuat(NGAY x)
{
	cout << "\nNgay: " << x.Ngay << endl;
	cout << "Thang: " << x.Thang << endl;
	cout << "Nam: " << x.Nam << endl;
}

void Nhap(DAILY& x)
{
	cin.ignore();
	cout << "\nNhap ma so dai ly: ";
	getline(cin, x.MaSo);
	cout << "Nhap ten dai ly: ";
	getline(cin, x.TenDaiLy);
	cout << "Nhap so dien thoai: ";
	cin >> x.DienThoai;
	cout << "Nhap ngay tiep nhan: ";
	Nhap(x.NgayNhan);
	cout << "Nhap dia chi: ";
	cin.ignore();
	getline(cin, x.DiaChi);
	cout << "Nhap E-Mail: ";
	getline(cin, x.EMail);
}

void Xuat(DAILY x)
{
	cout << "\nMa so dai ly: " << x.MaSo;
	cout << "\nTen dai ly: " << x.TenDaiLy;
	cout << "\nDien thoai: " << x.DienThoai;
	cout << "\nNgay tiep nhan: ";
	Xuat(x.NgayNhan);
	cout << "Dia chi: " << x.DiaChi;
	cout << "\nE-mail: " << x.EMail;
}

void Nhap(DAILY a[], int& n)
{
	cout << "Nhap n: ";
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cout << "\nNhap dai ly thu " << i + 1 << ": \n";
		Nhap(a[i]);
	}
}

void Xuat(DAILY a[], int n)
{
	cout << "\nDanh sach dai ly: \n";
	for (int i = 0; i < n; i++)
	{
		cout << "Dai ly thu " << i + 1 << ": \n";
		Xuat(a[i]);
		cout << endl;
	}
}

void TimKiem(DAILY a[], int n, string name)
{
	cout << "Nhap ten dai li can tim: ";
	getline(cin, name);
	int flag = 0;
	for (int i=0; i<n; i++)
		if (name==a[i].TenDaiLy)
		{ 
			Xuat(a[i]);
			flag = 1;
		}
	if (flag == 0)
		cout << "Khong kiem duoc. ";
}