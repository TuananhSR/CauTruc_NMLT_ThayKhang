#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

struct HocSinh
{
	string HoTen;
	int Toan;
	int Van;
	float TrungBinh;
};
typedef struct HocSinh HOCSINH;

void Nhap(HOCSINH&);
void Xuat(HOCSINH);
void TrungBinh(HOCSINH&);

void Nhap(HOCSINH[], int&);
void Xuat(HOCSINH[], int);

void Dem(HOCSINH[], int);

int main()
{
	HOCSINH hs[100];
	int n;
	Nhap(hs, n);
	Xuat(hs, n);

	Dem(hs, n);
	return 0;
}

void Nhap(HOCSINH& x)
{
	cin.ignore();
	cout << "\nNhap ten hoc sinh: ";
	getline(cin, x.HoTen);
	cout << "Nhap diem toan: ";
	cin >> x.Toan;
	cout << "Nhap diem van: ";
	cin >> x.Van;
}

void Xuat(HOCSINH x)
{
	cout << "\nTen hoc sinh: " << x.HoTen << endl;
	cout << "Diem toan: " << x.Toan << endl;
	cout << "Diem van: " << x.Van << endl;
	cout << "Diem trung binh: " << x.TrungBinh << endl;
}

void TrungBinh(HOCSINH& x)
{
	x.TrungBinh = (x.Toan + x.Van) / 2;
}

void Nhap(HOCSINH a[], int& n)
{
	cout << "Nhap n: ";
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cout << "Nhap hoc sinh thu " << i + 1 << ": \n";
		Nhap(a[i]);
		cout << endl;
		TrungBinh(a[i]);
	}
}

void Xuat(HOCSINH a[], int n)
{
	cout << "\nDanh sach hoc sinh: \n";
	for (int i = 0; i < n; i++)
	{
		cout << "\nHoc sinh thu " << i + 1 << ": \n";
		Xuat(a[i]);
	}
}

void Dem(HOCSINH a[], int n)
{
	int dem = 0;
	for (int i = 0; i < n; i++)
		if (a[i].Toan > 8 && a[i].Van > 8)
			dem++;
	cout << "\nSo luong hoc sinh gioi: " << dem;
}
