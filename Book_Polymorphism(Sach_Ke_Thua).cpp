#include<iostream>
#include<string.h>//ham strlen() nam trong thu vien nay
#include<stdlib.h>//ham rand() nam trong thu vien nay
#include<ctime>//hamm srand(time(NULL)) nam trong thu vien nay
using namespace std;
//----- Danh sach bien toan cuc -----
char SoLuongMaSach = 'A',Day= 49;//nhung bien nay ho tro cho nhung ham auto nhap
//-----------------------------------
class Book{//sach
	protected:
		char MaSach[100],NgayNhap[100],NhaXuatBan[100];
		float DonGia;
		int SoLuong;
	public:
		virtual void InPut();
		virtual void OutPut();
};
class TextBook{//sach giao khoa
	private:
		char TinhTrang[100];//cu or moi
	public:
		void InPut();
		void OutPut();
};
void HamNoiChuoi(char a[],char b[]);//noi chuoi b vao sau chuoi a
class ReferenceBooks{//sach tham khao
	private:
		float Thue;
	public:
		void InPut();
		void OutPut();
};

void NoiChuoi(char a[],char b);
int RANDUM(int a,int b);
int main()
{
	
	system("pause");
	return 0;

}
//------------------------- Cac ham khong nam trong class -------------------------
int RANDUM(int a,int b)
{
	return rand()%(b-a+1)+a;
}
void NoiChuoi(char a[],char b)
{
	a[strlen(a)] = 'b';
	a[strlen(a)+1] = '\0';
}
//------------------------- -------------------------

//------------------------- Cac ham cua class ReferenceBooks-------------------------

//------------------------- Cac ham cua class TextBook -------------------------

//------------------------- Cac ham cua class Book -------------------------
void Book::OutPut()
{
	cout<<"\nMa sach: "<<MaSach;
	cout<<"\nNgay nhap: "<<NgayNhap;
	cout<<"\nNha xuat ban: "<<NhaXuatBan;
	cout<<"\nDon gia: "<<DonGia;
	cout<<"\nSo luong: "<<SoLuong;
}
void Book::InPut()
{
//Nhap binh thuong
//	fflush(stdin);
//	cout<<"\nNhap ma sach: ";
//	gets(MaSach);
//	fflush(stdin);
//	cout<<"\nNgay nhap: ";
//	gets(NgayNhap);
//	cout<<"\nNhap don gia: ";
//	cin>>DonGia;
//	cout<<"\nNhap so luong: ";
//	cin>>SoLuong;

//Tu dong nhap => dung de test code cho nhanh
	strcpy(MaSach,"Ms ");
	NoiChuoi(MaSach,SoLuongMaSach);
	cout<<"\nMa sach nhan duoc la: "<<MaSach;
	
	strcpy(NgayNhap,"2021/12/");
	NoiChuoi(NgayNhap,Day);
	cout<<"\nNgay nhap nhan duoc la: "<<NgayNhap;
	Day++;
	if(Day==58)
		Day = 49;
	
	strcpy(NhaXuatBan,"Nguyen Hoang Nam ");
	NoiChuoi(NhaXuatBan,SoLuongMaSach);
	cout<<"\nNha xuat ban nhan duoc la: "<<NhaXuatBan;
	SoLuongMaSach++;
	if(SoLuongMaSach == 123)
		SoLuongMaSach = 65;
		
	srand(time(0));
	DonGia = RANDUM(10000,500000);
	
	srand(time(0));
	SoLuong = RANDUM(1000,10000);
}

