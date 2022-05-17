#include <iostream>
using namespace std;

struct SoPhuc
{
	float Thuc;
	float Ao;
};
typedef struct SoPhuc SOPHUC;

void Nhap(SOPHUC&);
void Xuat(SOPHUC);
SOPHUC Tong(SOPHUC, SOPHUC);
SOPHUC Hieu(SOPHUC, SOPHUC);
SOPHUC Tich(SOPHUC, SOPHUC);
SOPHUC Thuong(SOPHUC, SOPHUC);
SOPHUC LuyThua(SOPHUC, int);

int main()
{
	SOPHUC M;
	Nhap(M);
	cout << "\nSo phuc vua nhap: ";
	Xuat(M);
	SOPHUC N;
	Nhap(N);
	cout << "\nSo phuc vua nhap: ";

	cout << "\nTong 2 so phuc la: ";
	SOPHUC cong;
	cong = Tong(M, N);
	Xuat(cong);

	cout << "\nHieu 2 so phuc la: ";
	SOPHUC tru;
	tru = Hieu(M, N);
	Xuat(tru);

	cout << "\nTich 2 so phuc la: ";
	SOPHUC nhan;
	nhan = Tich(M, N);
	Xuat(nhan);

	cout << "\nThuong 2 so phuc la: ";
	SOPHUC chia;
	chia = Thuong(M, N);
	Xuat(chia);

	int n;
	cout << "\nNhap n: ";
	cin >> n;
	cout << "\nLuy thua bac n cua so phuc M la: ";
	SOPHUC LT;
	LT = LuyThua(M, n);
	Xuat(LT);
	return 1;
}

void Nhap(SOPHUC& x)
{
	cout << "Nhap thuc: ";
	cin >> x.Thuc;
	cout << "Nhap ao: ";
	cin >> x.Ao;
}

void Xuat(SOPHUC x)
{
	cout << "\nThuc: " << x.Thuc;
	cout << "\nAo: " << x.Ao;
	cout << endl;
}

SOPHUC Tong(SOPHUC x, SOPHUC y)
{
	SOPHUC temp;
	temp.Thuc = x.Thuc + y.Thuc;
	temp.Ao = x.Ao + y.Ao;
	return temp;
}

SOPHUC Hieu(SOPHUC x, SOPHUC y)
{
	SOPHUC temp;
	temp.Thuc = x.Thuc - y.Thuc;
	temp.Ao = x.Ao - y.Ao;
	return temp;
}

SOPHUC Tich(SOPHUC x, SOPHUC y)
{
	SOPHUC temp;
	temp.Thuc = x.Thuc * y.Thuc - x.Ao * y.Ao;
	temp.Ao = x.Thuc * y.Ao + x.Ao * y.Thuc;
	return temp;
}

SOPHUC Thuong(SOPHUC x, SOPHUC y)
{
	float mc = y.Thuc * y.Thuc + y.Ao * y.Ao;
	SOPHUC temp;
	temp.Thuc = (x.Thuc * y.Thuc + x.Ao * y.Ao) / mc;
	temp.Ao = (x.Ao * y.Thuc - x.Thuc * y.Ao) / mc;
	return temp;
}

SOPHUC LuyThua(SOPHUC x, int n)
{
	SOPHUC temp = { 1,0 };
	for (int i = 1; i <= n; i++)
		temp = Tich(temp, x);
	return temp;
}
