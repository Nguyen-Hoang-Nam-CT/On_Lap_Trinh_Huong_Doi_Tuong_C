//Tui dang hoc tieng anh nen code tieng anh va tieng viet lon xon :( 
#include<iostream>
#include<math.h>
using namespace std;

class ComplexNumber{
	private:
		float Virtual,Real; //Ao, Thuc
	public:
		void InPut();
		void OutPut();
		float AbsoluteValua();//ham tinh gia tri tuyet doi so phuc
		ComplexNumber Summation(ComplexNumber b); // ham cong so phuc
		ComplexNumber Subtraction(ComplexNumber b); //ham tru so phuc
		ComplexNumber Multiplication(ComplexNumber b); //ham nhan so phuc
		ComplexNumber Division(ComplexNumber b); //ham chia so phuc
		
		ComplexNumber operator + (ComplexNumber b);
		ComplexNumber operator - (ComplexNumber b);
		ComplexNumber operator * (ComplexNumber b);
		ComplexNumber operator / (ComplexNumber b);
};

int main()
{
	ComplexNumber CN,CN1,CN2;
//	cout<<"Nhap thong Tin so phuc";
//	CN.InPut();
//	cout<<"\nThong tin so phuc: ";
//	CN.OutPut();
//	cout<<"\nGia tri tuyet doi co so phuc la: "<<CN.AbsoluteValua();

	cout<<"\nNhap thong tin so phuc thu 1";
	CN1.InPut();
	cout<<"\nNhap thong tin so phuc thu 2";
	CN2.InPut();
	cout<<"\nThong tin so phuc 1 va 2 la: ";
	CN1.OutPut();
	cout<<", ";
	CN2.OutPut();
	
	cout<<"\nKet qua + - * / so phuc dung ham binh thuong";
	//ham cong hai so phuc
	cout<<"\nKet qua sau khi cong so phuc 1 va 2 la: ";
	CN1.Summation(CN2).OutPut();
	
	//ham tru hai so phuc
	cout<<"\nKet qua so phuc 1 tru so phuc 2 la: ";
	CN1.Subtraction(CN2).OutPut();
	
	//ham nhan hai so phuc
	cout<<"\nKet qua sau khi nhan so phuc 1 va so phuc 2 la:";
	CN1.Multiplication(CN2).OutPut();
	
	//ham chia hai so phuc
	cout<<"\nKet qua so phuc 1 chia so phuc 2 la: ";
	CN1.Division(CN2).OutPut();
//-------------------------------------------------- cac ham operator --------------------------------------------------
	cout<<"\n\nKet qua + - * / so phuc dung operator";
	cout<<"\nKet qua sau khi cong so phuc 1 va 2 la: ";
	(CN1+CN2).OutPut();
	
	//ham tru hai so phuc
	cout<<"\nKet qua so phuc 1 tru so phuc 2 la: ";
	(CN1-CN2).OutPut();
	
	//ham nhan hai so phuc
	cout<<"\nKet qua sau khi nhan so phuc 1 va so phuc 2 la:";
	(CN1*CN2).OutPut();
	
	//ham chia hai so phuc
	cout<<"\nKet qua so phuc 1 chia so phuc 2 la: ";
	(CN1/CN2).OutPut();
	
	cout<<"\n";
	system("pause");
	return 0;
}
//-------------------------------------------------- Cac hom operator --------------------------------------------------
ComplexNumber ComplexNumber::operator / (ComplexNumber b)
{
	return Multiplication(b);
}
ComplexNumber ComplexNumber::operator * (ComplexNumber b)
{
	return Multiplication(b);
}
ComplexNumber ComplexNumber::operator - (ComplexNumber b)
{
	return Subtraction(b);
}
ComplexNumber ComplexNumber::operator + (ComplexNumber b)
{
	return Summation(b);
}
//-------------------------------------------------- Cac hom binh thuong --------------------------------------------------
ComplexNumber ComplexNumber::Division(ComplexNumber b) //ham chia so phuc
{
	ComplexNumber Result;//ket qua
	Result.Real = (Real*b.Real + Virtual*b.Virtual)/(b.Virtual*b.Virtual + b.Real*b.Real);
	Result.Virtual = Virtual*b.Real - Real*b.Virtual;
	return Result;
}
ComplexNumber ComplexNumber::Multiplication(ComplexNumber b) //ham nhan so phuc
{
	ComplexNumber Result;// ket qua
	Result.Real = (Real*b.Real - Virtual*b.Virtual);
	Result.Virtual = (Real*b.Virtual + Virtual*b.Real);
	return Result;
}

ComplexNumber ComplexNumber::Subtraction(ComplexNumber b)//ham tru so phuc
{
	ComplexNumber Result;//ket qua
	Result.Real = Real - b.Real;
	Result.Virtual = Virtual - b.Virtual;
	return Result;
}
ComplexNumber ComplexNumber::Summation(ComplexNumber b) //ham cong so phuc
{
	ComplexNumber Result;//ket qua
	Result.Real = Real + b.Real;
	Result.Virtual = Virtual + b.Virtual;
	return Result;
}
float ComplexNumber::AbsoluteValua()//ham tinh gia tri tuyet doi so phuc
{
	return sqrt(Real*Real + Virtual*Virtual);
}
void ComplexNumber::OutPut()
{
	if(Virtual < 0)
		cout<<"\t"<<Real<<" - "<<(Virtual*(-1))<<"i";
	else
		cout<<"\t"<<Real<<" + "<<Virtual<<"i";
}
void ComplexNumber::InPut()
{
	cout<<"\n\tNhap phan thuc: ";
	cin>>Real;
	cout<<"\n\tNhap phan ao: ";
	cin>>Virtual;
}
