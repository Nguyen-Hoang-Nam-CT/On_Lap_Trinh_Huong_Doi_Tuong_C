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
		float GeterDonGia();
		char *GeterNhaXuatBan();
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
		ReferenceBooks();
		void InPut();
		void OutPut();
		void TinhThanhTien();
};

void NoiChuoi(char a[],char b);
int RANDUM(int a,int b);
void OutPutMenu();
void InPutTextBook(Book *&a,int &SoLuongSach);//dau & truoc Book vi co su thay doi vung nho nen phai de dau &
void InPutReferenceBooks(Book *&a,int &SoLuongSach);
void OutPutListBook(Book *a[],int SoLuongSach);
float TrungBinhCongDonGiaSachThamKhao(Book *a[],int SoLuongSach);
void LietKeSachGiaoKhoaCuaNhaXuatBanX(Book *a[],int SoLuongSach);
int main()
{
	Book *BookArray[100];
	int selection,SoLuongSach=0;
	srand(time(0));//de ham nay o day ma khong de ham nay trong ham random vi khi nhap du lieu nhanh qua no khong bi trung nhau(Cung mot khoang thoi gian nhung co duoc 2 gia tri random khac nhau)
	while(1)
	{
		OutPutMenu();
		cout<<"\nNhap lua chon cua ban: ";
		cin>>selection;
//		system("cls");
		if(selection == 1)
			InPutTextBook(BookArray[SoLuongSach],SoLuongSach);
		else if(selection == 2)
			InPutReferenceBooks(BookArray[SoLuongSach],SoLuongSach);
		else if(selection == 3)
			OutPutListBook(BookArray,SoLuongSach);
		else if(selection == 4)
		{
			float sumTextBook = 0,sumReferenceBooks = 0;
			for(int i=0;i<SoLuongSach;i++)
			{
				if(stricmp(BookArray[i]->GeterPhanLoai(),"TextBook")==0)
					sumTextBook += BookArray[i]->GeterThanhTien();
				else
					sumReferenceBooks += BookArray[i]->GeterThanhTien();
			}
			cout<<"\nTong thanh tien cua sach giao khoa la: "<<(size_t)sumTextBook;
			cout<<"\nTong thanh tien cua sach tham khao la: "<<(size_t)sumReferenceBooks;
		}
		else if(selection == 5)
			cout<<"\nTrung binh cong don gia cac hoa don cua sach tham khao: "<<TrungBinhCongDonGiaSachThamKhao(BookArray,SoLuongSach);
		else if(selection == 6)
			LietKeSachGiaoKhoaCuaNhaXuatBanX(BookArray,SoLuongSach);
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
void LietKeSachGiaoKhoaCuaNhaXuatBanX(Book *a[],int SoLuongSach)
{
	int count = 0;
	char x[100];
	cout<<"\nNhap nha xuat ban sach giao khoa can tim: ";
	fflush(stdin);
	gets(x);
	for(int i=0;i<SoLuongSach;i++)
	{
		if(stricmp(a[i]->GeterNhaXuatBan(),x) == 0 && stricmp(a[i]->GeterPhanLoai(),"TextBook") == 0)
		{
			a[i]->OutPut();
			count++;
		}
	}
	if(count == 0)
		cout<<"Khong co sach giao khoa nao cua nha xuat ban "<<x;
}
float TrungBinhCongDonGiaSachThamKhao(Book *a[],int SoLuongSach)
{
	int count = 0;
	float sum = 0;
	for(int i=0;i<SoLuongSach;i++)
		if(stricmp(a[i]->GeterPhanLoai(),"RederenceBooks") == 0)
		{
			count++;
			sum += a[i]->GeterDonGia();
		}
	if(count == 0)
		return 0;
	return (sum/count);
}
void OutPutListBook(Book *a[],int SoLuongSach)
{
	cout<<"\n=============== THONG TIN CACH HOA DON SACH ===============";
	for(int i=0;i<SoLuongSach;i++)
	{
		cout<<"\nTHONG TIN HOA DON SACH THU "<<i+1;
		a[i]->OutPut();
	}
	cout<<"\n============================================================";
}
void InPutReferenceBooks(Book *&a,int &SoLuongSach)
{
	a = new ReferenceBooks;
	a->InPut();
	SoLuongSach++;
}
void InPutTextBook(Book *&a,int &SoLuongSach)
{
	a = new TextBook;
	a->InPut();
	SoLuongSach++;
}
void OutPutMenu()
{
	cout<<"\n\t----------------------------------- MENU -----------------------------------";
	cout<<"\n\t\tPhim 1: Them 1 sach giao khoa vao danh sach";
	cout<<"\n\t\tPhim 2: Them 1 sach tham khao vao danh sach";
	cout<<"\n\t\tPhim 3: Xuat List Book";
	cout<<"\n\t\tPhim 4: Tong thanh tien cho tung loai sach";
	cout<<"\n\t\tPhim 5: Tinh trung binh cong don gia cho cac sach tham khao";
	cout<<"\n\t\tPhim 6: Xuat ra cac hoa don sach giao khoa cua nha xuat ban x";
	cout<<"\n\t\tPhim 7: Giai phong vung nho va ket thuc chuong trinh(hoac phim khac)";
	cout<<"\n\t----------------------------------------------------------------------------";
}
int RANDUM(int a,int b)
{
	return rand()%(b-a+1)+a;
}
void NoiChuoi(char a[],char b)
{
	
	a[strlen(a)]=b;
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
	Book::OutPut(); //Bi cai loi ngo ngan o cho nay troi oi la troi. ==> day la thanh qua cua viec code khong check haha
	cout<<"\n\tThue: "<<Thue;
	cout<<"\n";
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
	TinhThanhTien();
}
ReferenceBooks::ReferenceBooks()
{
	Thue = 0;
	strcpy(PhanLoai,"RederenceBooks");// chu RederenceBooks viet sai :D ma khong sua dau haha
}
//------------------------- Cac ham cua class TextBook -------------------------

void TextBook::TinhThanhTien()
{
	if(stricmp(TinhTrang,"Moi") == 0)
		ThanhTien = SoLuong * DonGia;
	else 
		ThanhTien = SoLuong * DonGia * 0.5;
}

void TextBook::OutPut()
{
	Book::OutPut(); //Bi cai loi ngo ngan o cho nay troi oi la troi. ==> day la thanh qua cua viec code khong check haha
	cout<<"\n\tTinh trang sach: "<<TinhTrang;
	cout<<"\n";
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
	TinhThanhTien();
}
TextBook::TextBook()
{
	strcpy(TinhTrang,"");
	strcpy(PhanLoai,"TextBook");
}
//------------------------- Cac ham cua class Book -------------------------
char *Book::GeterNhaXuatBan()
{
	return NhaXuatBan;
}
float Book::GeterDonGia()
{
	return DonGia;
}
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
	cout<<"\n\tLoai sach: "<<PhanLoai;
	cout<<"\n\tMa sach: "<<MaSach;
	cout<<"\n\tNGay nhap: "<<NgayNhap;
	cout<<"\n\tNha xuat ban: "<<NhaXuatBan;
	cout<<"\n\tDon gia: "<<DonGia;
	cout<<"\n\tSo luong: "<<SoLuong;
	cout<<"\n =============> Thanh tien: "<<(size_t)ThanhTien;
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
		
	DonGia = RANDUM(10000,30000);
	cout<<"\nDon gia nhan duoc la: "<<DonGia;
	
	SoLuong = RANDUM(1,1000);
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

