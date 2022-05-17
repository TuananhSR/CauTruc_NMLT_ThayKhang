#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

struct NhanVien
{
	string MaSo;
	string HoTen;
	float Luong;
};
typedef struct NhanVien NHANVIEN;
void Nhap(NHANVIEN&);
void Xuat(NHANVIEN);

void Nhap(NHANVIEN[], int&);
void Xuat(NHANVIEN[], int);
void LuongCaoNhat(NHANVIEN[], int);
float TongLuong(NHANVIEN[], int);
void SapXepTheoLuong(NHANVIEN[], int);
void HoanVi(NHANVIEN&, NHANVIEN&);

int main()
{
	NHANVIEN a[100];
	int n;
	Nhap(a, n);
	Xuat(a, n);

	LuongCaoNhat(a, n);
	cout << "\nTong luong la: " << TongLuong(a, n);

	SapXepTheoLuong(a, n);
	cout << "\nDanh sach sau khi sap xem tang dan theo luong la: \n";
	Xuat(a, n);
	return 0;
}

void Nhap(NHANVIEN& x)
{
	cin.ignore();
	cout << "Nhap ma nhan vien: ";
	getline(cin, x.MaSo);
	cout << "Nhap ten nhan vien: ";
	getline(cin, x.HoTen);
	cout << "Nhap luong nhan vien: ";
	cin >> x.Luong;
}

void Xuat(NHANVIEN x)
{
	cout << "\nMa nhan vien: " << x.MaSo << endl;
	cout << "Ten nhan vien: " << x.HoTen << endl;
	cout << "Luong nhan vien: " << x.Luong << endl;
}

void Nhap(NHANVIEN a[], int& n)
{
	cout << "Nhap n: ";
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cout << "\nNhap nhan vien thu " << i + 1 << ": \n";
		Nhap(a[i]);
	}
}

void Xuat(NHANVIEN a[], int n)
{
	cout << "Danh sach nhan vien: ";
	for (int i = 0; i < n; i++)
	{
		cout << "\nNhan vien thu " << i + 1 << ": \n";
		Xuat(a[i]);
	}
}

void LuongCaoNhat(NHANVIEN a[], int n)
{
	NHANVIEN max;
	max = a[0];
	for (int i = 1; i < n; i++)
	{
		if (max.Luong < a[i].Luong)
			max = a[i];
	}
	cout << "\nNhan vien co luong cao nhat la: ";
	Xuat(max);
}

float TongLuong(NHANVIEN a[], int n)
{
	float s = 0;
	for (int i = 0; i < n; i++)
		s = s + a[i].Luong;
	return s;
}

void HoanVi(NHANVIEN& a, NHANVIEN& b)
{
	NHANVIEN temp;
	temp = a;
	a = b;
	b = temp;
}

void SapXepTheoLuong(NHANVIEN a[], int n)
{
	for (int i = 0; i < n; i++)
		for (int j = i; j < n; j++)
			if (a[i].Luong > a[j].Luong)
				HoanVi(a[i], a[j]);
}

