#include<iostream>
#include<ctime>
#include<stdlib.h>
using namespace std;

class CFraction{
	private:
		int Numerator,Denominator; //tu,mau
	public:
		CFraction();
		CFraction(int a,int b);
		void InPut();//ham nhap
		void InPutAuto();//ham nhap tu dong
		void OutPut();//ham xuat
		void SeterNumerator(int x);//ham thiet lap tu so
		int GeterNumerator();//Ham lay phan so
		void SeterDenominator(int x);//Ham thiet lap mau so
		int GeterDenominator();//ham lay mau so;
		float Valua();//ham lay gia tri phan so
		CFraction operator + (CFraction b);
		int GreatestCommomDivisor(int a,int b);//ham tim uoc chung lon nhat
		void Reduce();//ham rut gon phan so
		void Normalize();
		void Swap(CFraction &b);//ham doi gia tri 2 phan so
};
class CFractionArray{/*Class mang phan so*/
	private:
		int NumberOfFraction;//so luong phan so
		CFraction FractionArray[100];//mang phan so
	public:
		void InPutArray();//ham nhap mang
		void OutPutArray();//ham xuat mang
		void OutPutValua();//xuat gia tri phan so
		void Listed();//ham -liet ke- cac phan so co gia tri nho hon 1
		int CheckListFraction();//ham kiem tra xem tat ca phan tu trong mang phan so deu co mau la 1 phai khong
		CFraction Sum();
		float Avarege();//ham tinh gia tri trung binh cong
		void SortUpAscend();// ham sap xep tang dan
};
int main()
{
	//nhap 1 phan so va tinh gia tri cua no
//	CFraction F;
//	F.InPut();
//	F.OutPut();
//	cout<<"\nGia tri cua phan so vua nhap la: "<<F.Valua();

	CFractionArray LF; //LF = List Fraction
	LF.InPutArray();
	cout<<"\nThong tin Fraction List(Danh sach phan so): ";
	LF.OutPutArray();
	
	//ham xuat gia tri danh sach phan so
	LF.OutPutValua();
	
	//ham liet ke cac phan so co gia tri nho hon 1
	LF.Listed();
	
	//ham kiem tra danh sach phan so co mau toan 1 hay khong
	if(LF.CheckListFraction()==1)
		cout<<"\nList fraction (Danh sach phan so) co mau toan la 1";
	else
		cout<<"\nList fraction (Danh sach phan so) co it nhat 1 phan so co mau khac 1";
	
	//ham tinh tong danh sach phan so
	cout<<"\nTong List Fraction (Danh sach phan so) la: ";
	LF.Sum().OutPut();
	
	//ham tinh gia tri trung binh cong danh sach phan so
	float resualt = LF.Avarege();
	cout<<"\nTrung binh cong gia tri phan so la: "<<resualt;	
	
	//ham sap xep danh sach tang dan
	cout<<"\nThong tin danh sach phan so sau khi sap xep tang: ";
	LF.SortUpAscend();
	LF.OutPutArray();
//------- End -------
	cout<<"\n";
	system("pause");
	return 0;
//-------------------
}
//------------------------- cac ham cua Class CFractionArray -------------------------
void CFractionArray::SortUpAscend()
{
	if(NumberOfFraction == 0)
	{
		cout<<"\nDanh sach rong~";
		return;
	}
	int min;
	for(int i=0;i<NumberOfFraction-1;i++)
	{
		min = i;
		for(int j=i+1;j<NumberOfFraction;j++)
			if(FractionArray[min].Valua() > FractionArray[j].Valua())
				min =j;
		if(min!=i)
			FractionArray[i].Swap(FractionArray[min]);
	}
}

float CFractionArray::Avarege()
{
	float sum=0;
	for(int i=0;i<NumberOfFraction;i++)
		sum += FractionArray[i].Valua();
	return (sum/(float)NumberOfFraction);
}
CFraction CFractionArray::Sum()
{
	CFraction Result;
	for(int i=0;i<NumberOfFraction;i++)
		Result = Result+FractionArray[i];
	return Result;
}
int CFractionArray::CheckListFraction()
{
	for(int i=0;i<NumberOfFraction;i++)
		if(FractionArray[i].GeterDenominator()!=1)
			return 0;
	return 1;
}

void CFractionArray::Listed()//ham liet ke cac phan so co gia tri nho hon 1
{
	int count = 0;
	cout<<"\nCac phan so co gia tri nho hon 1 la: ";
	for(int i=0;i<NumberOfFraction;i++)
		if(FractionArray[i].Valua() < 1)
		{
			FractionArray[i].OutPut();
			count++;
		}
	if(count==0)
		cout<<"\tDanh sach phan so khong co phan tu nao co gia tri nho hon 1";
}
void CFractionArray::OutPutValua()//xuat gia tri phan so
{
	cout<<"\n\t\tValua (gia tri) nhan duoc la: ";
	for(int i=0;i<NumberOfFraction;i++)
	{
		cout<<"\t"<<FractionArray[i].Valua();
	}
}
void CFractionArray::OutPutArray()
{
	for(int i=0;i<NumberOfFraction;i++)
		FractionArray[i].OutPut();
}
void CFractionArray::InPutArray()
{
	int Selection;//lua chon
	cout<<"\nNhap Number Of Fraction(So luong phan so): ";
	cin>>NumberOfFraction;
	cout<<"\n--------------- Menu ---------------";
	cout<<"\nBan muon nhap tay hay nhap tu dong?";
	cout<<"\n\tPhim 1: nhap tay";
	cout<<"\n\tPhim 2: Nhap tu dong(hoac phim khac)";
	cout<<"\n------------------------------------";
	cout<<"\nNhap lua chon cua ban: ";
	cin>>Selection;
	
	if(Selection == 1)
		for(int i=0;i<NumberOfFraction;i++)
		{
			cout<<"\nNhap thong tin phan so thu "<<(i+1);
			FractionArray[i].InPut();
		}
	else
	{
		srand(time(0));
		for(int i=0;i<NumberOfFraction;i++)
			FractionArray[i].InPutAuto();
	}	
}
//------------------------- cac ham Class CFraction -------------------------
void CFraction::Swap(CFraction &b)
{
	CFraction temp;
	
	temp.Numerator = Numerator;
	temp.Denominator = Denominator;
	
	Numerator = b.Numerator;
	Denominator = b.Denominator;
	
	b = temp;
}
void CFraction::Normalize()
{
	if(Denominator<0)
	{
		Numerator *= -1;
		Denominator *= -1;
	}
}
void CFraction::Reduce()
{
	int temp = GreatestCommomDivisor(Numerator,Denominator);
	Numerator /= temp;
	Denominator /= temp;
}
int CFraction::GreatestCommomDivisor(int a,int b)
{
	int temp;
	while(b!=0)
	{
		temp=a%b;
		a=b;
		b=temp;
	}
	return a;
}
CFraction CFraction::operator + (CFraction b)
{
	CFraction Result;
	Result.Numerator = Numerator*b.Denominator + b.Numerator*Denominator;
	Result.Denominator = Denominator * b.Denominator;
	return Result;
}
float CFraction::Valua()
{
	return (((float)Numerator/Denominator));
}
int CFraction::GeterDenominator()
{
	return Denominator;
}
void CFraction::SeterDenominator(int x)
{
	Denominator = x;
}
int CFraction::GeterNumerator()
{
	return Numerator;
}
void CFraction::SeterNumerator(int x)
{
	Numerator = x;
}
void CFraction::OutPut()
{
	Reduce();
	Normalize();
	cout<<"\t"<<Numerator<<"/"<<Denominator;
}
void CFraction::InPutAuto()
{
	Numerator = rand()%(21)-10;
	do{
		Denominator = rand()%(21)-10;
	}while(Denominator==0);
}
void CFraction::InPut()
{
	cout<<"\n\tNhap numerator(Tu so): ";
	cin>>Numerator;
	cout<<"\n\tNhap denominator(Mau so): ";
	cin>>Denominator;	
}
CFraction::CFraction(int a,int b)
{
	Numerator = a;
	Denominator = b;
}
CFraction::CFraction()
{
	Numerator = 0;
	Denominator = 1;
}
