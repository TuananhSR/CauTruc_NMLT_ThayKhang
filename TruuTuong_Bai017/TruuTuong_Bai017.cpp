#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

struct ThiSinh
{
	string MaSo;
	string HoTen;
	float Toan;
	float Ly;
	float Hoa;
	float Tong;
};
typedef struct ThiSinh THISINH;

void Nhap(THISINH&);
void Xuat(THISINH);

void Nhap(THISINH[], int&);
void Xuat(THISINH[], int);
void TongDiem(THISINH&);
void LietKe(THISINH[], int);
void SapXepGiamTheoDiemTong(THISINH[], int);
void HoanVi(THISINH&, THISINH&);

int main()
{
	THISINH ts[100];
	int n;
	Nhap(ts, n);
	Xuat(ts, n);

	LietKe(ts, n);

	SapXepGiamTheoDiemTong(ts, n);
	cout << "\nDanh sach Thi sinh co diem tong giam dan: \n";
	Xuat(ts, n);
	return 1;
}

void Nhap(THISINH& x)
{
	cin.ignore();
	cout << "\nNhap ma thi sinh: ";
	getline(cin, x.MaSo);
	cout << "Nhap ho ten thi sinh: ";
	getline(cin, x.HoTen);
	cout << "Nhap diem toan: ";
	cin >> x.Toan;
	cout << "Nhap diem ly: ";
	cin >> x.Ly;
	cout << "Nhap diem hoa: ";
	cin >> x.Hoa;
}

void Xuat(THISINH x)
{
	cout << "\nMa thi sinh: " << x.MaSo << endl;
	cout << "Ho ten thi sinh: " << x.HoTen << endl;
	cout << "Diem toan: " << x.Toan << endl;
	cout << "Diem ly: " << x.Ly << endl;
	cout << "Diem hoa: " << x.Hoa << endl;
	cout << "Tong diem la: " << x.Tong << endl;
}

void TongDiem(THISINH& x)
{
	x.Tong = x.Toan + x.Ly + x.Hoa;
}

void Nhap(THISINH a[], int& n)
{
	cout << "Nhap n: ";
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cout << "Nhap thi sinh thu " << i + 1 << ": \n";
		Nhap(a[i]);
		cout << endl;
		TongDiem(a[i]);
	}
}

void Xuat(THISINH a[], int n)
{
	cout << "\nDanh sach thi sinh: \n";
	for (int i = 0; i < n; i++)
	{
		cout << "Thi sinh thu " << i + 1 << ": \n";
		Xuat(a[i]);
	}
}

void LietKe(THISINH a[], int n)
{
	cout << "\nDanh sach cac thi sinh thi dau trong mang la: \n";
	for (int i = 0; i < n; i++)
		if (a[i].Tong > 15 && a[i].Toan != 0 && a[i].Ly != 0 && a[i].Hoa != 0)
			Xuat(a[i]);
}

void HoanVi(THISINH& a, THISINH& b)
{
	THISINH temp;
	temp = a;
	a = b;
	b = temp;
}

void SapXepGiamTheoDiemTong(THISINH a[], int n)
{
	for (int i = 0; i < n; i++)
		for (int j = i; j < n; j++)
			if (a[i].Tong < a[j].Tong)
				HoanVi(a[i], a[j]);
}