//google dich han hanh tai tro chuong trinh nay
#include<iostream>

using namespace std;

class Rectangle{//hinh chu nhat
	private:
		float Length;//dai
		float Width;//rong
	protected:
		float Erea;//dien tich
		float Perimeter;//chu vi
	public:
		void InPut();
		void OutPut();
		void CalculateErea();//phuong thuc tinh dien tich
		void CalculatePerimeter();//phuong thuc tinh chu vi
		float GeterErea();//lay dien tich
		float GeterPerimeter();//lay chu vi
};

//hinh vuon
class Square:public Rectangle{
	private:
		float Side;//canh
	public:
		void InPut();
		void OutPut();
		void CalculateErea();
		void CalculatePerimeter();
};

class ListQuadrilateral//danh sach tu giac
{
	private:
		Rectangle RectangleArray[100];//mang hinh chu nhat
		int NumberOfRectangle;//so luong hinh chu nhat
		Square SquareArray[100];//mamg hinh vuon
		int NumberOfSquare;//So luong hinh Vuon
	public:
		void Menu();
};
int main()
{
	ListQuadrilateral LQ;
	LQ.Menu();

	return 0;
}
//------------------------- Cac ham cua class ListQuadrilateral -------------------------
void ListQuadrilateral::Menu()
{
	NumberOfSquare = 0;
	NumberOfRectangle = 0;
	float TotalErea;//tong dien tich
	float TotalPerimeter;//tong chu vi
	int Selection;//lua chon
	while(1)
	{
		cout<<"\n\t------------------------- MENU -------------------------";
		cout<<"\n\t\tPhim 1: Nhap thong tin 1 hinh chu nhat (Rectangle)";
		cout<<"\n\t\tPhim 2: Nhap thong tin 1 hinh vuon (Square)";
		cout<<"\n\t\tPhim 3: Xuat thong tin danh sach hinh chu nhat (Rectangle)";
		cout<<"\n\t\tPhim 4: Xuat thong tin danh sach hinh vuon (Square)";
		cout<<"\n\t\tPhim 5: Xuat thong tin danh sach tu giac(Quadrilateral)";
		cout<<"\n\t\tPhim 6: Tinh tong chu vi(Perimeter) dien tich(Erea) danh sach hinh chu nhat(List Rectangle)";
		cout<<"\n\t\tPhim 7: Tinh tong chu vi(Perimeter) dien tich(Erea) danh sach hinh vuon (List Square)";
		cout<<"\n\t\tPhim 8: Dung lai va giai phong vung nho (Hoac phim khac)";
		cout<<"\n\t--------------------------------------------------------";
		cout<<"\nNhap lua chon(Selection): ";
		cin>>Selection;
		if(Selection==1)
		{
			RectangleArray[NumberOfRectangle].InPut();
			RectangleArray[NumberOfRectangle].CalculateErea();
			RectangleArray[NumberOfRectangle].CalculatePerimeter();
			NumberOfRectangle++;
		}	
		else if(Selection==2)
		{
			SquareArray[NumberOfSquare].InPut();
			SquareArray[NumberOfSquare].CalculateErea();
			SquareArray[NumberOfSquare].CalculatePerimeter();
			NumberOfSquare++;
		}
		else if(Selection==3)
		{
			cout<<"\nThong tin danh sach hinh chu nhat Rectangle";
			for(int i=0;i<NumberOfRectangle;i++)
			{
				cout<<"\nThong tin hinh chu nhat(Rectangle) thu "<<i+1;
				RectangleArray[i].OutPut();
			}
		}
		else if(Selection==4)
		{
			cout<<"\nThong tin danh sach hinh vuong(Square)";
			for(int i=0;i<NumberOfRectangle;i++)
			{
				cout<<"\nThong tin hinh Vuong(Square) thu "<<i+1;
				SquareArray[i].OutPut();
			}
		}
		else if(Selection==5)
		{
			cout<<"\nThong tin danh sach hinh chu nhat Rectangle";
			for(int i=0;i<NumberOfRectangle;i++)
			{
				cout<<"\nThong tin hinh chu nhat(Rectangle) thu "<<i+1;
				RectangleArray[i].OutPut();
			}
			
			cout<<"\nThong tin danh sach hinh vuong(Square)";
			for(int i=0;i<NumberOfRectangle;i++)
			{
				cout<<"\nThong tin hinh Vuong(Square) thu "<<i+1;
				SquareArray[i].OutPut();
			}
		}
		else if(Selection==6)
		{
			TotalErea = 0;
			TotalPerimeter = 0;
			for(int i=0;i<NumberOfRectangle;i++)
			{
				TotalErea += RectangleArray[i].GeterErea();
				TotalPerimeter += RectangleArray[i].GeterPerimeter();
			}
			cout<<"\n Tong dien tich (Erea) cua danh sach hinh chu nhat la(List Rectangle): "<<TotalErea;
			cout<<"\n Tong Chu vi (Perimeter) cua danh sach hinh vuon la(List Square): "<<TotalPerimeter;
		}
		else if(Selection == 7)
		{
			TotalErea = 0;
			TotalPerimeter = 0;
			for(int i=0;i<NumberOfSquare;i++)
			{
				TotalErea += SquareArray[i].GeterErea();
				TotalPerimeter += SquareArray[i].GeterPerimeter();
			}
			cout<<"\n Tong dien tich (Erea) cua danh sach hinh chu nhat la(List Rectangle): "<<TotalErea;
			cout<<"\n Tong Chu vi (Perimeter) cua danh sach hinh vuon la(List Square): "<<TotalPerimeter;
		}
		else
			break;
	}
}
//------------------------- Cac ham cua class Square -------------------------
void Square::CalculatePerimeter()
{
	Perimeter = 4*Side;
}
void Square::CalculateErea()
{
	Erea = Side*Side;
}
void Square::OutPut()
{
	cout<<"\n(Canh) Side: "<<Side;
	cout<<"\n(Dien tich) Erea: "<<Erea;
	cout<<"\n(Chu vi) Perimeter: "<<Perimeter;
}
void Square::InPut()
{
	cout<<"\nNhap (Canh)Side: ";
	cin>>Side;
}
//-------------------------Cac ham cua class Rectangle -------------------------
float Rectangle::GeterPerimeter()
{
	return Perimeter;
}
float Rectangle::GeterErea()
{
	return Erea;
}
void Rectangle::CalculatePerimeter()
{
	Perimeter = 2*(Length + Width);
}
void Rectangle::CalculateErea()
{
	Erea = Length * Width;
}
void Rectangle::OutPut()
{
	cout<<"\n(chieu dai) Length: "<<Length;
	cout<<"\n(Chieu rong) Width: "<<Width;
	cout<<"\n(Dien tich) Erea: "<<Erea;
	cout<<"\n(Chu vi)Perimeter: "<<Perimeter;
}
void Rectangle::InPut()
{
	cout<<"\nNhap Length(chieu Dai): ";
	cin>>Length;
	cout<<"\nNhap Wibth(Chieu rong): ";
	cin>>Width;
}
