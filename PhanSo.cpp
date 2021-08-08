#include<iostream>

using namespace std;
class ps{
	private:
		int tu,mau;
	public:
		void nhap();
		void xuat();
		int ucln(int a,int b);
		void rutGon();
		ps cong(ps a);
		ps tru(ps a);
		ps nhan(ps a);
		ps chia(ps a);
};

int main()
{
	ps p,q;
	cout<<"\nNhap thong tin phan so thu 1.";
	p.nhap();
	cout<<"\nNhap thong tin phan so thu 2.";
	q.nhap();
	cout<<"\nThong tin hai phan so: ";
	p.xuat();
	q.xuat();
	
	cout<<"\n	Ket qua cac phep tinh: ";
	//cong
	cout<<"\n";
	p.xuat();
	cout<<"\t + ";
	q.xuat();
	cout<<" = ";
	p.cong(q).xuat();
	
	//tru
	cout<<"\n";
	p.xuat();
	cout<<"\t - ";
	q.xuat();
	cout<<" = ";
	p.tru(q).xuat();
	
	//nhan
	cout<<"\n";
	p.xuat();
	cout<<"\t * ";
	q.xuat();
	cout<<" = ";
	p.nhan(q).xuat();
	
	//chia
	cout<<"\n";
	p.xuat();
	cout<<"\t / ";
	q.xuat();
	cout<<" = ";
	p.chia(q).xuat();
	
//	p.rutGon();
//	cout<<"\nThong tin phan so sau khi rut gon la: ";
//	p.xuat();
	return 0;
}
ps ps::chia(ps a)
{
	ps kq;
	kq.tu = tu*a.mau;
	kq.mau = mau*a.mau;
	kq.rutGon();
	return kq;
}
ps ps::nhan(ps a)
{
	ps kq;
	kq.tu = tu*a.tu;
	kq.mau = mau*a.mau;
	kq.rutGon();
	return kq;
}
ps ps::tru(ps a)
{
	ps kq;
	kq.tu = tu*a.mau - a.tu*mau;
	kq.mau = mau*a.mau;
	kq.rutGon();
	return kq;
}
ps ps::cong(ps a)
{
	ps kq;
	kq.tu = tu*a.mau + a.tu*mau;
	kq.mau = mau*a.mau;
	kq.rutGon();
	return kq;
}
void ps::rutGon()
{
	int a = tu,b = mau;
	tu /= ucln(a,b);
	mau /= ucln(a,b); 
}
int ps::ucln(int a,int b)
{
	int temp;
	while(a!=0)
	{
		/*
		a = 25 va b = 10
		temp = 10 b=25 a=10
		temp = 5 b = 10 a= 5
		temp = 0 b = 5 a = 0
		a = 0 => stop => return b;
		*/
		temp = b%a;
		b = a;
		a = temp;
	}
	return b;
}
void ps::xuat()
{
	cout<<"\t"<<tu<<"/"<<mau;
}
void ps::nhap()
{
	cout<<"\n\tNhap tu so: ";
	cin>>tu;
	cout<<"\n\tNhap mau so: ";
	cin>>mau;
}
