#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

struct ThoiGian
{
	int Gio;
	int Phut;
	int Giay;
};
typedef struct ThoiGian THOIGIAN;

struct Ngay
{
	int Ngay;
	int Thang;
	int Nam;
};
typedef struct Ngay NGAY;

struct ChuyenBay
{
	string MaSo;
	NGAY NgayBay;
	THOIGIAN GioBay;
	string NoiDi;
	string NoiDen;
};
typedef struct ChuyenBay CHUYENBAY;

void Nhap(NGAY&);
void Xuat(NGAY);

void Nhap(THOIGIAN&);
void Xuat(THOIGIAN);

void Nhap(CHUYENBAY&);
void Xuat(CHUYENBAY);

void Nhap(CHUYENBAY[], int&);
void Xuat(CHUYENBAY[], int);
void NhieuNhat(CHUYENBAY[], int);
void TimKiem(CHUYENBAY[], int, string);

int Khac(NGAY, NGAY);

int main()
{
	CHUYENBAY cb[100];
	int n;
	Nhap(cb,n);
	Xuat(cb,n);
	cout << endl;	
	NhieuNhat(cb, n);
	string Ma;
	TimKiem(cb, n, Ma);

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

void Nhap(THOIGIAN& x)
{
	cout << "\nNhap gio: ";
	cin >> x.Gio;
	cout << "Nhap phut: ";
	cin >> x.Phut;
	cout << "Nhap Giay: ";
	cin >> x.Giay;
}

void Xuat(THOIGIAN x)
{
	cout << "Gio: " << x.Gio << endl;
	cout << "Phut: " << x.Phut << endl;
	cout << "Giay: " << x.Giay << endl;
}

void Nhap(CHUYENBAY& x)
{
	cout << "Nhap ma chuyen bay: ";
	getline(cin, x.MaSo);
	cout << "Nhap ngay bay: ";
	Nhap(x.NgayBay);
	cout << "Nhap gio bay: ";
	Nhap(x.GioBay);
	cout << "Nhap noi di: ";
	cin.ignore();
	getline(cin, x.NoiDi);
	cout << "Nhap noi den: ";
	getline(cin, x.NoiDen);
}

void Xuat(CHUYENBAY x)
{
	cout << "\nMa chuyen bay: " << x.MaSo << endl;
	cout << "Ngay bay: ";
	Xuat(x.NgayBay);
	cout << "\nGio bay: ";
	Xuat(x.GioBay);
	cout << "Noi di: " << x.NoiDi << endl;
	cout << "Noi den: " << x.NoiDen << endl;
}

void Nhap(CHUYENBAY cb[], int& n)
{
	cout << "\nNhap so luong chuyen bay: ";
	cin >> n;
	cin.ignore();
	for (int i = 0; i < n; i++)
	{
		cout << "Nhap ma chuyen bay: ";
		getline(cin, cb[i].MaSo);
		cout << "Nhap ngay bay: ";
		Nhap(cb[i].NgayBay);
		cout << "Nhap gio bay: ";
		Nhap(cb[i].GioBay);
		cout << "Nhap noi di: ";
		cin.ignore();
		getline(cin, cb[i].NoiDi);
		cout << "Nhap noi den: ";
		getline(cin, cb[i].NoiDen);
	}
}

void Xuat(CHUYENBAY cb[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << "\nMa chuyen bay: " << cb[i].MaSo << endl;
		cout << "Ngay bay: ";
		Xuat(cb[i].NgayBay);
		cout << "\nGio bay: ";
		Xuat(cb[i].GioBay);
		cout << "Noi di: " << cb[i].NoiDi << endl;
		cout << "Noi den: " << cb[i].NoiDen << endl;
	}
}
int Khac(NGAY x, NGAY y)
{
	if (x.Ngay != y.Ngay || x.Thang != y.Thang || x.Nam != y.Nam)
		return 0;
	return 1;
}
void NhieuNhat(CHUYENBAY a[], int n)
{
	NGAY b[100];
	int Dem[100];
	int x = 0;
	for (int i = 0; i < n; i++)
	{
		int flag = 1;
		for (int j = 0; j < x; j++)
			if (Khac(a[i].NgayBay, b[j])==0)
				flag = 0;
		if (flag == 1)
		{
			b[x] = a[i].NgayBay;
			x++;
		}
	}
	int max = 0;
	int vt;
	for (int i = 0; i < x; i++)
	{
		Dem[i] = 0;
		for (int j = 0; j < n; j++)
		{
			if (Khac(b[i],a[j].NgayBay)==1)
				Dem[i]++;
		}
		if (max < Dem[i])
		{
			max = Dem[i];
			vt = i;
		}
	}
	cout << "\nNgay co chuyen bay nhieu nhat la: \n";
	Xuat(b[vt]);

}

void TimKiem(CHUYENBAY a[], int n, string Ma)
{
	cout << "\nNhap ma chuyen bay can tim: ";
	getline(cin, Ma);
	for (int i = 0; i < n; i++)
		if (a[i].MaSo == Ma)
			Xuat(a[i]);
}