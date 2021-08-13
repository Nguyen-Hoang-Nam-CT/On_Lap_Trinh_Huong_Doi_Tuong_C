//google dich han hanh tai tro chuong trinh nay
#include<iostream>

using namespace std;

class Staff{//nhan vien
	protected:
		char StaffCode[100];//ma so nhan vien
		char FullName[100];//Ho ten
		float Salary;//luong
	public:
		virtual void InPut();
		virtual void OutPut();
};
class PayrollStaff : public Staff{//nhan vien bien che
	private:
		float CoefficientsSalary;//he so luong
		float positionAllowance;//phu chap chuc vu
	public:
		void InPut();
		void OutPut();
};
int main()
{
	
	return 0;
}
//-------------------------  -------------------------
//-------------------------  -------------------------
//------------------------- PayrollStaff -------------------------
void PayrollStaff::InPut()
{
	Staff::InPut();
	do{
		cout<<"\nNhap he so luong(Coefficients Salary): ";
		if(CoefficientsSalary > 1 || CoefficientsSalary > 13);
			cout<<"\nNhap sai! nhap lai he so luong (Coefficients Salary) trong khoang [1:13]: ";
	}while(CoefficientsSalary > 1 || CoefficientsSalary > 13);
	do{
		cout<<"\nNhap phu cap chuc vu(positionAllowance): ";
		if(positionAllowance > 0 || positionAllowance > 2);
			cout<<"\nNhap sai! nhap lai phu cap chuc vu (position Allowance) trong khoang [0:2]: ";
	}while(positionAllowance > 0 || positionAllowance > 2);
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

