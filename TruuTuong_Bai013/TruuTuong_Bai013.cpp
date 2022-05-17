#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

struct MatHang
{
	string TenHang;
	int DonGia;
	int LuongTon;
};
typedef struct MatHang MATHANG;

void Nhap(MATHANG&);
void Xuat(MATHANG);

void Nhap(MATHANG[], int&);
void Xuat(MATHANG[], int);

int LonNhat(MATHANG[], int);
int Dem(MATHANG[], int);
int GiaTriTon(MATHANG);
void LietKe(MATHANG[], int n);

int main()
{
	int n;
	MATHANG b[100];
	
	Nhap(b, n);
	Xuat(b, n);
	
	cout << "\nMat hang co tong gia tri ton lon nhat: ";
	LietKe(b, n);

	cout << "\nSo luong mat hang co so luong ton lon hon 1000: ";
	cout << Dem(b, n);
	return 1;
}

void Nhap(MATHANG& x)
{
	cout << "Nhap ten mat hang: ";
	getline(cin, x.TenHang);
	cin.ignore();
	cout << "Nhap don gia: ";
	cin >> x.DonGia;
	cout << "Nhap So luong ton: ";
	cin >> x.LuongTon;
}

void Xuat(MATHANG x)
{
	cout << "\nTen mat hang: " << x.TenHang << endl;
	cout << "Don Gia: " << x.DonGia << endl;
	cout << "So luong ton: " << x.LuongTon << endl;
}

void Nhap(MATHANG a[], int& n)
{
	cout << "Nhap n: ";
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cout << "\nMat hang thu " << i + 1 << ": \n";
		Nhap(a[i]);
	}
}

void Xuat(MATHANG a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << "\nMat hang thu " << i + 1 << ": \n";
		Xuat(a[i]);
	}
}

int GiaTriTon(MATHANG x)
{
	return x.LuongTon * x.DonGia;
}

int LonNhat(MATHANG a[], int n)
{
	int max = GiaTriTon(a[0]);
	for (int i = 0; i < n; i++)
		if (GiaTriTon(a[i]) > max)
			max = GiaTriTon(a[i]);
	return max;
}

void LietKe(MATHANG a[], int n)
{
	for (int i = 0; i < n; i++)
		if (GiaTriTon(a[i]) == LonNhat(a, n))
			cout << "\n" << a[i].TenHang;
}

int Dem(MATHANG a[], int n)
{
	int dem = 0;
	for (int i = 0; i < n; i++)
		if (a[i].LuongTon > 1000)
			dem++;
	return dem;

}