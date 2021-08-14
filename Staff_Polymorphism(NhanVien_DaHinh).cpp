#include<iostream>

#define LuongCoBan 2500000
using namespace std;

class Staff{//nhan vien
	protected:
		char StaffCode[100];//ma so nhan vien
		char FullName[100];//Ho ten
		float Salary;//luong
	public:
		virtual void InPut();
		virtual void OutPut();
		virtual void TinhLuong()=0;
};
class PayrollStaff : public Staff{//nhan vien bien che
	private:
		float CoefficientsSalary;//he so luong
		float PositionAllowance;//phu chap chuc vu
	public:
		void InPut();
		void OutPut();
		void TinhLuong();
};
class ContractStaff : public Staff{////nhan vien hop dong
	private:
		float Wages;//tien cong mot ngay
		int NumberOfWorkingDays;//so ngay lam viec
	public:
		void InPut();
		void OutPut();
		void TinhLuong();
};
class ListStaff{
	private:
		Staff *StaffArray[100];
		int NumberOfStaff;
	public:
		void InPut();
		void OutPut();
};
int main()
{
	
	return 0;
}
//-------------------------  -------------------------
//------------------------- Cac ham cua class ContractStaff -------------------------
void ContractStaff::TinhLuong()
{
	if(NumberOfWorkingDays <= 24)
		Salary = Wages * NumberOfWorkingDays;
	else
		Salary = (Wages * NumberOfWorkingDays)*1.2;
}
void ContractStaff::OutPut()
{
	Staff::OutPut();
	cout<<"\nTien cong mot ngay: "<<Wages;
	cout<<"\nSo ngay lam viec: "<<NumberOfWorkingDays;
}
void ContractStaff::InPut()
{
	do{
		cout<<"\nNhap tien cong mot ngay trong khoang [200.000-2.000.000]: ";
		cin>>Wages;
		if(Wages < 200000 || Wages > 2000000)
			cout<<"\nNhap sai! Nhap lai tien cong mot ngay trong khoang [200.000-2.000.000]: ";
	}while(Wages < 200000 || Wages > 2000000);
	
	do{
		cout<<"\nNhap so ngay lam viec: ";
		cin>>NumberOfWorkingDays;
		if(NumberOfWorkingDays < 1 || NumberOfWorkingDays > 31)
			cout<<"\nNhap sai! Nhap lai so ngay lam viec trong khoang [1:31]";
	}while(NumberOfWorkingDays < 1 || NumberOfWorkingDays > 31);
}
//------------------------- Cac hom cua class PayrollStaff -------------------------
void PayrollStaff::TinhLuong()
{
	Salary = LuongCoBan * (CoefficientsSalary + PositionAllowance);
}
void PayrollStaff::OutPut()
{
	Staff::OutPut();
	cout<<"\nHe so luong(Coefficients Salary): "<<CoefficientsSalary;
	cout<<"\nPhu cap chuc vu(Position Allowance)"<<PositionAllowance;
}
void PayrollStaff::InPut()
{
	Staff::InPut();
	do{
		cout<<"\nNhap he so luong(Coefficients Salary): ";
			cin>>CoefficientsSalary;
		if(CoefficientsSalary > 1 || CoefficientsSalary > 13);
			cout<<"\nNhap sai! nhap lai he so luong (Coefficients Salary) trong khoang [1:13]: ";
	}while(CoefficientsSalary > 1 || CoefficientsSalary > 13);
	do{
		cout<<"\nNhap phu cap chuc vu(positionAllowance): ";
			cin>>PositionAllowance;
		if(PositionAllowance > 0 || PositionAllowance > 2);
			cout<<"\nNhap sai! nhap lai phu cap chuc vu (position Allowance) trong khoang [0:2]: ";
	}while(PositionAllowance > 0 || PositionAllowance > 2);
}

//------------------------- Cac ham cua class Staff -------------------------
void Staff::OutPut()
{
	cout<<"\nMa so nhan vien(StaffCode): "<<StaffCode;
	cout<<"\nHo ten(Full Name): "<<FullName;
	cout<<"\nLuong: "<<Salary;
}
void Staff::InPut()
{
	cout<<"\nNhap ma so nhan vien(Staff Code): ";
	gets(StaffCode);
	cout<<"\nNhap ho ten(Full Name): ";
	fflush(stdin);
	gets(FullName);
}

