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

struct CauThu
{
	string MaSo;
	string HoTen;
	NGAY NgaySinh;
};
typedef struct CauThu CAUTHU;

void Nhap(NGAY&);
void Xuat(NGAY);

void Nhap(CAUTHU&);
void Xuat(CAUTHU);

void Nhap(CAUTHU[], int&);
void Xuat(CAUTHU[], int);
int SoSanh(NGAY, NGAY);
NGAY NhoNhat(CAUTHU[], int);
void LietKe(CAUTHU[], int);
void HoanVi(CAUTHU& a, CAUTHU& b);
void SapXep(CAUTHU[], int n);
int main()
{
	CAUTHU b[100];
	int n;
	Nhap(b, n);
	Xuat(b, n);

	cout << "Nhung Cau thu co ngay sinh nho nhat: \n";
	LietKe(b, n);

	cout << "\nMang sau khi sap xep giam dan la: ";
	SapXep(b, n);
	Xuat(b, n);
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

void Nhap(CAUTHU& x)
{
	cin.ignore();
	cout << "Nhap ma cau thu: ";
	getline(cin, x.MaSo);
	cout << "Ten cau thu: ";
	getline(cin, x.HoTen);
	cout << "Nhap ngay sinh: ";
	Nhap(x.NgaySinh);
}

void Xuat(CAUTHU x)
{
	cout << "\nMa cau thu: " << x.MaSo << endl;
	cout << "Ten cau thu: " << x.HoTen << endl;
	cout << "Ngay sinh: ";
	Xuat(x.NgaySinh);
}

void Nhap(CAUTHU a[], int& n)
{
	cout << "Nhap n: ";
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cout << "\nNhap cau thu thu " << i + 1 << ": \n";
		Nhap(a[i]);
	}
	cout << endl;
}

void Xuat(CAUTHU a[], int n)
{
	cout << "Danh sach cau thu la: \n";
	for (int i=0; i<n; i++)
	{
		cout << "\nCau thu thu " << i + 1 << ": ";
		Xuat(a[i]);
	}
	cout << endl;
}

int SoSanh(NGAY x, NGAY y)
{
	if (x.Nam > y.Nam)
		return 1;
	if (x.Nam < y.Nam)
		return -1;
	if (x.Thang > y.Thang)
		return 1;
	if (x.Thang < y.Thang)
		return -1;
	if (x.Ngay > y.Ngay)
		return 1;
	if (x.Ngay < y.Ngay)
		return -1;
}

NGAY NhoNhat(CAUTHU a[], int n)
{
	NGAY min;
	min.Ngay = a[0].NgaySinh.Ngay;
	min.Thang = a[0].NgaySinh.Thang;
	min.Nam = a[0].NgaySinh.Nam;
	for (int i = 0; i < n; i++)
		if (SoSanh(min, a[i].NgaySinh) == 1)	
		{ 
			min.Ngay = a[i].NgaySinh.Ngay;
			min.Thang = a[i].NgaySinh.Thang;
			min.Nam = a[i].NgaySinh.Nam;
		}
	return min;
}

void LietKe(CAUTHU a[], int n)
{
	NGAY min = NhoNhat(a, n);
	//min.Ngay = NhoNhat(a, n).Ngay;
	//min.Thang = NhoNhat(a, n).Thang;
	//min.Nam = NhoNhat(a, n).Nam;

	for (int i = 0; i < n; i++)
		if (min.Ngay == a[i].NgaySinh.Ngay && min.Thang == a[i].NgaySinh.Thang && min.Nam == a[i].NgaySinh.Nam)
			Xuat(a[i]);
}

void HoanVi(CAUTHU& a, CAUTHU& b)
{
	CAUTHU temp;
	temp = a;
	a = b;
	b = temp;
}

void SapXep(CAUTHU a[], int n)
{
	for (int i = 0; i < n; i++)
		for (int j = i + 1; j < n; j++)
			if (SoSanh(a[i].NgaySinh, a[j].NgaySinh) == -1)
				HoanVi(a[i], a[j]);
}