#include<iostream>
#define LuongCoBan 2500000
#include<stdlib.h>//ham rand() co trong thu vien nay
#include<ctime>//ham srand() co trong thu vien nay

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
		float GeterSalary();//ham lay luong
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
		void Menu();
};
int RANDUM(int a,int b);
int main()
{
	ListStaff LS;
	LS.Menu();
	return 0;
}
int RANDUM(int a,int b)
{
	srand(time(0));
	return rand()%(b-a+1)+a;
}
//------------------------- Cac ham cua class ListStaff -------------------------
void ListStaff::Menu()
{
	int Selection;
	NumberOfStaff = 0;
	while(1)
	{
		cout<<"\n\t------------------------- MENU -------------------------";
		cout<<"\n\t\tPhim 1: Nhap nhan vien bien che";
		cout<<"\n\t\tPhim 2: Nhap nhan vien hop dong";
		cout<<"\n\t\tPhim 3: Xuat danh sach nhan vien";
		cout<<"\n\t\tPhim 4: Tinh tong luong cho nhan vien";
		cout<<"\n\t\tPhim 5: Tinh trung binh cong luong nhan vien trong danh sach";
		cout<<"\n\t\tPhim 6: Liet ke cac nhan vien co luong tren 10 trieu";
		cout<<"\n\t\tPhim 7: Giai phong vung nho va ket thuc";
		cout<<"\n\t--------------------------------------------------------";
		cout<<"\nNhap lua chon cua ban: ";
		cin>>Selection;
		if(Selection == 1)
		{
			StaffArray[NumberOfStaff] = new PayrollStaff;
			StaffArray[NumberOfStaff]->InPut();
			StaffArray[NumberOfStaff]->TinhLuong();
			NumberOfStaff++;
		}
		else if(Selection == 2)
		{
			StaffArray[NumberOfStaff] = new ContractStaff;
			StaffArray[NumberOfStaff]->InPut();
			StaffArray[NumberOfStaff]->TinhLuong();
			NumberOfStaff++;
		}
		else if(Selection == 3)
		{
			for(int i=0;i<NumberOfStaff;i++)
			{
				cout<<"\nTHong tin nhan vien thu "<<i+1;
				StaffArray[i]->OutPut();
			}
		}
		else if(Selection == 4)
		{
			float sum=0;
			for(int i=0;i<NumberOfStaff;i++)
				sum += StaffArray[i]->GeterSalary();
			cout<<"\nTong luong cua danh sach nhan vien la: "<<(size_t)sum;
		}
		else if(Selection == 5)
		{
			float sum=0;
			for(int i=0;i<NumberOfStaff;i++)
				sum += StaffArray[i]->GeterSalary();
			cout<<"\nTrung binh cong luong cua danh sach nhan vien la: "<<(size_t)(sum/NumberOfStaff);
		}
		else if(Selection == 6)
		{
			cout<<"\nDanh sach nhan vien co luong tren 10 trieu";
			for(int i=0;i<NumberOfStaff;i++)
				if(StaffArray[i]->GeterSalary() > 10000000)
				{
					cout<<"\n";
					StaffArray[i]->OutPut();
				}
		}
		else 
		{
			for(int i=0;i<NumberOfStaff;i++)
				delete StaffArray[i];
			system("pause");
			break;
		}
	}
}
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
	cout<<"\nTien cong mot ngay: "<<(size_t)Wages;
	cout<<"\nSo ngay lam viec: "<<NumberOfWorkingDays;
}
void ContractStaff::InPut()
{
	Staff::InPut();
	do{
//		cout<<"\nNhap tien cong mot ngay trong khoang [200.000-2.000.000]: ";
//		cin>>Wages;
//		if(Wages < 200000 || Wages > 2000000)
//			cout<<"\nNhap sai! Nhap lai tien cong mot ngay trong khoang [200.000-2.000.000]: ";
		Wages = RANDUM(200000,2000000);
		cout<<"\nTien cong mot ngay nhan vao la: "<<Wages;
	}while(Wages < 200000 || Wages > 2000000);
	
	do{
//		cout<<"\nNhap so ngay lam viec trong khoang [1:31]: ";
//		cin>>NumberOfWorkingDays;
//		if(NumberOfWorkingDays < 1 || NumberOfWorkingDays > 31)
//			cout<<"\nNhap sai! Nhap lai so ngay lam viec trong khoang [1:31]: ";
		NumberOfWorkingDays = RANDUM(1,31);
		cout<<"\nSo ngay lam viec nhan vao la: "<<NumberOfWorkingDays;
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
//		cout<<"\nNhap he so luong(Coefficients Salary) trong khoang [1:13]: ";
//			cin>>CoefficientsSalary;
//		if(CoefficientsSalary > 1 || CoefficientsSalary > 13);
//			cout<<"\nNhap sai! nhap lai he so luong (Coefficients Salary) trong khoang [1:13]: ";
		CoefficientsSalary = RANDUM(1,13);
		cout<<"\nHe so luong nhan vao la: "<<CoefficientsSalary;
	}while(CoefficientsSalary < 1 || CoefficientsSalary > 13);
	do{
//		cout<<"\nNhap phu cap chuc vu(positionAllowance) trong khoang [0:2]: ";
//			cin>>PositionAllowance;
//		if(PositionAllowance > 0 || PositionAllowance > 2);
//			cout<<"\nNhap sai! nhap lai phu cap chuc vu (position Allowance) trong khoang [0:2]: ";
		PositionAllowance = RANDUM(0,2);
		cout<<"\nPhu cap chuc vu nhan vao la: "<<PositionAllowance;
	}while(PositionAllowance < 0 || PositionAllowance > 2);
}

//------------------------- Cac ham cua class Staff -------------------------
float Staff::GeterSalary()
{
	return Salary;
}
void Staff::OutPut()
{
	cout<<"\nMa so nhan vien(StaffCode): "<<StaffCode;
	cout<<"\nHo ten(Full Name): "<<FullName;
	cout<<"\nLuong: "<<(size_t)Salary;
}
void Staff::InPut()
{
	fflush(stdin);
	cout<<"\nNhap ma so nhan vien(Staff Code): ";
	gets(StaffCode);
	cout<<"\nNhap ho ten(Full Name): ";
	fflush(stdin);
	gets(FullName);
}

