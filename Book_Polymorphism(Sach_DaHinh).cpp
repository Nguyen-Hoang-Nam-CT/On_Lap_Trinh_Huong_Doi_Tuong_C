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
		char MaSach[100],NgayNhap[100],NhaXuatBan[100],PhanLoai[20];
		float DonGia,ThanhTien;
		int SoLuong;
	public:
		Book();
		virtual void InPut();
		virtual void OutPut();
		virtual void TinhThanhTien() = 0;
		float GeterThanhTien();
		char *GeterPhanLoai();
};
class TextBook : public Book{//sach giao khoa
	private:
		char TinhTrang[100];//cu or moi
	public:
		TextBook();
		void InPut();
		void OutPut();
		void TinhThanhTien();

};

class ReferenceBooks : public Book{//sach tham khao
	private:
		float Thue;
	public:
		RederenceBooks();
		void InPut();
		void OutPut();
		void TinhLuong();
		void TinhThanhTien();
};

void NoiChuoi(char a[],char b);
int RANDUM(int a,int b);
void OutPutMenu();
void InPutTextBook(Book *&a,int &SoLuongSach);//dau & truoc Book vi co su thay doi vung nho nen phai de dau &
void InPutReferenceBooks(Book *&a,int &SoLuongSach);
void OutPutListBook(Book *a[],int SoLuongSach);
int main()
{
	Book *BookArray[100];
	int selection,SoLuongSach=0;
	while(1)
	{
		OutPutMenu();
		cout<<"\nNhap lua chon cua ban: ";
		cin>>selection;
		if(selection == 1)
		{
//			InPutTextBook(BookArray[SoLuongSach],SoLuongSach);
			BookArray[SoLuongSach] = new TextBook;
			BookArray[SoLuongSach]->InPut();
			SoLuongSach++;
		}
		else if(selection == 2)
		{
//			InPutReferenceBooks(BookArray[SoLuongSach],SoLuongSach);
			BookArray[SoLuongSach] = new ReferenceBooks;
			BookArray[SoLuongSach]->InPut();
			SoLuongSach++;
		}
		else if(selection == 3)
		{
//			OutPutListBook(BookArray,SoLuongSach);
			cout<<"\nSo luong sach hien tai la: "<<SoLuongSach;
			for(int i=0;i<SoLuongSach;i++)
			{
				cout<<"\nThong tin sach thu "<<i+1;
				BookArray[i]->OutPut();
			}
		}
		else if(selection == 4)
		{
			float sumTextBook = 0,sumReferenceBooks = 0;
			float r=0;
			for(int i=0;i<SoLuongSach;i++)
			{
				if(stricmp(BookArray[i]->GeterPhanLoai(),"TextBook")==0)
					sumTextBook += BookArray[i]->GeterThanhTien();
				else if(stricmp(BookArray[i]->GeterPhanLoai(),"ReferenceBooks"))
					sumReferenceBooks == BookArray[i]->GeterThanhTien();
				else
					r += BookArray[i]->GeterThanhTien();
			}
			cout<<"\nTong thanh tien cua sach giao khoa la: "<<sumTextBook;
			cout<<"\nTong thanh tien cua sach tham khao la: "<<sumReferenceBooks;
			cout<<"\nGia tri bi sai la: "<<r;
		}
		else
		{
			for(int i=0;SoLuongSach;i++)
			{
				delete BookArray[i];
			}
			break;
		}
	}
	system("pause");
	return 0;

}
//------------------------- Cac ham khong nam trong class -------------------------
void OutPutListBook(Book *a[],int SoLuongSach)
{
	
	for(int i=0;i<SoLuongSach;i++)
	{
		cout<<"\nThong tin sach thu "<<i+1;
		a[i]->OutPut();
	}
}
void InPutReferenceBooks(Book *&a,int &SoLuongSach)
{
	a = new ReferenceBooks;
	a->InPut();
	SoLuongSach++;
}
void InPutTextBook(Book *&a,int &SoLuongMaSach)
{
	a = new TextBook;
	a->InPut();
	SoLuongMaSach++;
}
void OutPutMenu()
{
	cout<<"\n\t----------------------------------- MENU -----------------------------------";
	cout<<"\n\t\tPhim 1: Them 1 sach giao khoa vao danh sach";
	cout<<"\n\t\tPhim 2: Them 1 sach tham khao vao danh sach";
	cout<<"\n\t\tPhim 3: Xuat List Book";
	cout<<"\n\t\tPhim 4: Tong thanh tien cho tung loai sach";
	cout<<"\n\t\tPhim 5: Tinh trung binh cong don gia cho cac sach tham khao";
	cout<<"\n\t\tPhim 6: Xuat ra cac sach giao khoa cua nha xuat ban x";
	cout<<"\n\t\tPhim 7: Giai phong vung nho va ket thuc chuong trinh(hoac phim khac)";
	cout<<"\n\t----------------------------------------------------------------------------";
}
int RANDUM(int a,int b)
{
	srand(time(0));
	return rand()%(b-a+1)+a;
}
void NoiChuoi(char a[],char b)
{
	a[strlen(a)] = 'b';
	a[strlen(a)+1] = '\0';
}
//------------------------- -------------------------

//------------------------- Cac ham cua class ReferenceBooks-------------------------
void ReferenceBooks::TinhThanhTien()
{
	ThanhTien = SoLuong * DonGia + Thue;
}
void ReferenceBooks::OutPut()
{
	ReferenceBooks::OutPut();
	cout<<"\nThue: "<<Thue;
}
void ReferenceBooks::InPut()
{
	Book::InPut();
//	cout<<"\nNhap thue: ";
//	cin>>Thue;
// Thue *= DonGia;

	int temp = RANDUM(5,20);
	Thue = temp * DonGia;
	cout<<"\nThue nhan duoc la: "<<Thue;
}
ReferenceBooks::RederenceBooks()
{
	Thue = 0;
	strcpy(PhanLoai,"RederenceBooks");
}
//------------------------- Cac ham cua class TextBook -------------------------

void TextBook::TinhThanhTien()
{
	if(stricmp(TinhTrang,"Moi") == 0)
		ThanhTien = SoLuong * DonGia;
	else if(stricmp(TinhTrang,"Cu") == 0)
		ThanhTien = SoLuong * DonGia * 0.5;
	else
		ThanhTien = 0; //=0 co nghia la khong tinh duoc
}

void TextBook::OutPut()
{
	TextBook::OutPut();
	cout<<"\nTinh trang sach: "<<TinhTrang;
	cout<<"\n\n";
}
void TextBook::InPut()
{
	Book::InPut();
//	fflush(stdin);
//	cout<<"\nNhap tinh trang sach: ";
//	gets(TinhTrang);
	int r = RANDUM(1,10);
	if(r%2==0)
		strcpy(TinhTrang,"Moi");
	else
		strcpy(TinhTrang,"Cu");
	cout<<"\nTinh trang nhan duoc la: "<<TinhTrang;
}
TextBook::TextBook()
{
	strcpy(TinhTrang,"");
	strcpy(PhanLoai,"TextBook");
}
//------------------------- Cac ham cua class Book -------------------------
char* Book::GeterPhanLoai()
{
	return PhanLoai;
}
float Book::GeterThanhTien()
{
	return ThanhTien;
}
void Book::OutPut()
{
//	cout<<"\nMa sach: "<<MaSach;
//	cout<<"\nNgay nhap: "<<NgayNhap;
//	cout<<"\nNha xuat ban: "<<NhaXuatBan;
//	cout<<"\nDon gia: "<<DonGia;
//	cout<<"\nSo luong: "<<SoLuong;
	cout<<"\nHello work";
}
void Book::InPut()
{
//Nhap binh thuong
//	fflush(stdin);
//	cout<<"\nNhap ma sach: ";
//	gets(MaSach);
//	fflush(stdin);
//	cout<<"\nNhap ngay nhap: ";
//	gets(NgayNhap);
//	fflush(stdin);
//	cout<<"\nNHap nha xuat ban: ";
//	gets(NhaXuatBan);
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
	cout<<"\nDon gia nhan duoc la: "<<DonGia;
	
	srand(time(0));
	SoLuong = RANDUM(1000,10000);
	cout<<"\nSo luong nhan duoc la: "<<SoLuong;
}
Book::Book()
{
	strcpy(MaSach,"");
	strcpy(NgayNhap,"");
	strcpy(NhaXuatBan,"");
	DonGia = 0;
	ThanhTien = 0;
	SoLuong = 0;
}

