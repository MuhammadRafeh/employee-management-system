#include<iostream>
#include<fstream>
#include<cstring>
using namespace std;
void printIntroMenu();
void printMainMenu();
void start();
void AddEmployee();
void logins();
void SearchById(int id);
void SearchByName();
int search_id=0;
void ListOfDepartment();
void DisplayAllEmployee();
void TotalNumberOfEmployee();
void ListOfAge();
void HighestSalaryEmployee();
void YoungEmployees();
void PalindromeId();
void ArmStrongSalary();
void UpdateRecord();
void DeleteRecord();

int main()
{
	
// Starting with the name of Allah who is most merciful and benificent.
start();

return 0;
}

void printIntroMenu()
{
int login; 
float a;
string user_id, password;

while (true)
{
cout<<"Please select an option from the menu below: "<<endl;
cout<<"1 _>Login"<<endl<<"2 _>Quit"<<endl<<'>';

cin>>login;

switch(login)
{
	case 2:
	cout<<endl<<"Thanks for Using Our Services!";
	exit(1);
	case 1:
	cout<<endl<<"Please enter your user id: ";     // User id is root123
	cin>>user_id;
	cout<<"Please enter your password: ";          // user password is asdf1234
	cin>>password;
}

if (user_id=="root123" && password=="asdf1234")
	logins();
else
cout<<endl<<"******** LOGIN FAILED! ********"<<endl<<endl;
}
}

void printMainMenu()
{while (true)
{

	int opt;
	cout<<"Please select an option from the menu below"<<endl<<endl<<"***>>>>>>>>>>>>>>>>>>>>>>>>> MENU >>>>>>>>>>>>>>>>>>>>>>>>>>>>>***"<<endl<<endl;
cout<<"1.	Enter a new Record"<<endl<<"2.	Search a record by Employee ID"<<endl<<"3.	Search a record by Employee Name"<<endl<<"4.	List Employees of a particular";
cout<<" department"<<endl<<"5.	List Employees above age 50"<<endl<<"6.	Display All Employees"<<endl<<"7.	Find total number of Employees"<<endl;
cout<<"8.	Find the Employee with highest salary"<<endl<<"9.	Find youngest male and female Employee"<<endl<<"10.	Find the Employee having palindrome Employee_id";
cout<<endl<<"11.	Find the Employee having Armstrong salary"<<endl<<"12.	Update record of a particular Employee"<<endl<<"13.	Delete an Employee record"<<endl;
cout<<"14.	Quit the program"<<endl;
cin>>opt;

switch(opt)
{
	case 1:
		AddEmployee();
		break;
	case 2:
		cout<<endl<<"Please Enter ID: ";cin>>search_id;
		SearchById(search_id);
		break;
	case 3:
		SearchByName();
		break;
	case 4:
		ListOfDepartment(); 
		break;
	case 5:
		ListOfAge();
		break;
	case 6:
		DisplayAllEmployee();
		break;
	case 7:
		TotalNumberOfEmployee();
		break;
	case 8:
		HighestSalaryEmployee();
		break;
	case 9:
		YoungEmployees();
		break;
	case 10:
		PalindromeId();
		break;
	case 11:
		ArmStrongSalary();
		break;
	case 12:
		UpdateRecord();
		break;
	case 13:
		DeleteRecord();
		break;
	case 14:
		cout<<endl<<"Thanks For Using Our Services!";
		exit(1);
}
}
}

void start()
{
	system("color 0C");
	printIntroMenu();
}

void AddEmployee()
{
	int id, age, salary;                            //DECLARING ID, AGE AND SALARY
	char name[20], department[5], gender;
	ofstream write("Employee.txt",ios::app);        // MAKING AN OBJECT TO WRITE FILES
	cout<<endl<<"Please Enter ID: ";cin>>id;cout<<"Please Enter Name: ";cin>>name;cout<<"Please Enter Age: ";cin>>age;cout<<"Please Enter Salary: ";cin>>salary;
	cout<<"Please Enter Gender: ";cin>>gender;cout<<"Please Enter Department: ";cin>>department;
	write<<id<<"        "<<name<<"          "<<age<<"          "<<gender<<"          "<<salary<<"           "<<department;
	write.close(); cout<<endl;
}

void logins()
{
	
	cout<<endl<<"******** LOGIN SUCCESSFULL! ********"<<endl<<endl;
	printMainMenu();
}

void SearchById(int id)
{
	string line, name; int ids,age, b = 1, a, salary; char gender, depart[3];
	ifstream ID("Employee.txt",ios::in);
	getline(ID,line);
	while (!ID.eof())
	{
		ID>>ids; ID>>name; ID>>age; ID>>gender; ID>>salary; ID>>depart;
		if (id == ids)
		{
			cout<<id<<"          "<<name<<"          "<<age<<"          "<<gender<<"          "<<salary<<"          "<<depart<<endl;
			b++;
		}
	}
	if (b==1)
	cout<<"You Entered Wrong ID That Is Not Exist In The List"<<endl<<endl;
	ID.close();
}

void SearchByName()
{	string line, name, a; int id, age,b = 1, salary; char gender, depart[3]; cout<<"Please Enter Name: "; cin>>a;
	ifstream Name("Employee.txt",ios::in);
	getline(Name,line);
	while (!Name.eof())
	{
		Name>>id; Name>>name; Name>>age; Name>>gender; Name>>salary; Name>>depart;
		if (name == a)
		{
			cout<<id<<"          "<<name<<"          "<<age<<"          "<<gender<<"          "<<salary<<"          "<<depart<<endl;
			b++;
		}
	}
	if (b==1)
	cout<<"You Entered Wrong Name That Is Not Exist In The List"<<endl;
	Name.close();
}

void ListOfDepartment()
{ 
	string line, name, depart, departs; int id, age, salary; char gender; cout<<"Please Enter Department: "; cin>>departs;
	ifstream List("Employee.txt",ios::in);
	getline(List,line);
	while (!List.eof())
	{
		List>>id; List>>name; List>>age; List>>gender; List>>salary; List>>depart;
		if (depart == departs)
		{
			cout<<id<<"          "<<name<<"          "<<age<<"          "<<gender<<"          "<<salary<<"          "<<depart<<endl;
		}
	}
	List.close();
}

void DisplayAllEmployee()
{	string line;
	ifstream lists("Employee.txt",ios::in);
	while (getline(lists,line))
	{
		cout<<line<<endl;
	}
	lists.close();
}
	
void TotalNumberOfEmployee()
{	string line; int a=0;
	ifstream Emp("Employee.txt",ios::in);
	while (getline(Emp,line))
	{
		a++;
	}
	cout<<"Total Number of Employee = "<<a-1;
	Emp.close();
}	
	
void ListOfAge()
{
	string line; int id, age, salary; char gender, name[20], depart[3];
	ifstream Age("Employee.txt",ios::in);
	getline(Age,line);
	while (!Age.eof())
	{
		Age>>id; Age>>name; Age>>age; Age>>gender; Age>>salary; Age>>depart;
		if (age>50)
		{
			cout<<id<<"          "<<name<<"          "<<age<<"          "<<gender<<"          "<<salary<<"          "<<depart<<endl;
		}
	}
	Age.close();
}	

void HighestSalaryEmployee()
{
	string line; int id,ids, a=0, age, ages, salary, salaries; char gender, genders; string name, names, depart, departs;
	ifstream Sal("Employee.txt",ios::in);
	getline(Sal,line);
	while (!Sal.eof())
	{
		Sal>>id; Sal>>name; Sal>>age; Sal>>gender; Sal>>salary; Sal>>depart;
		if (salary>a)
		{   a=salary;
			ids = id; names=name; ages=age; genders=gender; salaries=salary; departs=depart;
		}
	}
	cout<<ids<<"          "<<names<<"          "<<ages<<"          "<<genders<<"          "<<salaries<<"          "<<departs<<endl; Sal.close();
}
	
void YoungEmployees()
{
	
	string line; int id,idf,idm, g=100, b=100, age, agef,agem, salary, salaryf,salarym; char gender,genderm, genderf; string name, namef,namem, depart, departf,departm;
	ifstream Empl("Employee.txt",ios::in);
	getline(Empl,line);
	while (!Empl.eof())
	{
		Empl>>id; Empl>>name; Empl>>age; Empl>>gender; Empl>>salary; Empl>>depart;
		if (age<g && gender=='F')
		{   g=age;
			idf = id; namef=name; agef=age; genderf=gender; salaryf=salary; departf=depart;
		}
		else if (age<b && gender=='M')
		{   b=age;
			idm = id; namem=name; agem=age; genderm=gender; salarym=salary; departm=depart;
		}
	}
	cout<<idf<<"          "<<namef<<"          "<<agef<<"          "<<genderf<<"          "<<salaryf<<"          "<<departf<<endl; 
	cout<<idm<<"          "<<namem<<"          "<<agem<<"          "<<genderm<<"          "<<salarym<<"          "<<departm<<endl;Empl.close();
}
	
void PalindromeId()
{
	string line; int id, age, salary; char gender, name[20], depart[3];
	ifstream Pa("Employee.txt",ios::in);
	getline(Pa,line);
	while (!Pa.eof())
	{
		Pa>>id; Pa>>name; Pa>>age; Pa>>gender; Pa>>salary; Pa>>depart;
	int n, num, digit, rev = 0, a = id;
     n = a;
     do
     {
         digit = a % 10;
         rev = (rev * 10) + digit;
         a = a / 10;
     } while (a != 0);

     if (n == rev)
    cout<<id<<"          "<<name<<"          "<<age<<"          "<<gender<<"          "<<salary<<"          "<<depart<<endl;
	}
	Pa.close();
}

void ArmStrongSalary()
{
	string line; int id, age, salary; char gender, name[20], depart[3];
	ifstream Arm("Employee.txt",ios::in);
	getline(Arm,line);
	while (!Arm.eof())
	{
		Arm>>id; Arm>>name; Arm>>age; Arm>>gender; Arm>>salary; Arm>>depart;
		int n,r,sum=0,temp;       
		n=salary;    
		temp=n;    
		while(n>0)    
		{		    
			r=n%10;    
			sum=sum+(r*r*r);    
			n=n/10;    
		}    
		if(temp==sum)    
			cout<<id<<"        "<<name<<"          "<<age<<"          "<<gender<<"          "<<salary<<"          "<<depart<<endl;
	}
	Arm.close();
}

void UpdateRecord()
{ int id,new_id,opt_id,salary,new_salary,age,new_age; string line,name,new_name,depart,new_depart; char gender,new_gender;
	cout<<"Please Enter ID For Update: "; cin>>opt_id;
	ifstream read("Employee.txt",ios::in);
	getline(read,line);
	ofstream write("Temp.txt",ios::out);
	write<<line<<endl;
	while (!read.eof())
	{
		read>>id>>name>>age>>gender>>salary>>depart;
		if (id == opt_id)
		{
			cout<<"Please Update Name: "; cin>>new_name; cout<<"Please Update Age: "; cin>>new_age; cout<<"Please Update Gender: "; cin>>new_gender;
			cout<<"Please Update Salary: "; cin>>new_salary; cout<<"Please Update Department: "; cin>>new_depart;
			write<<opt_id<<"        "<<new_name<<"          "<<new_age<<"          "<<new_gender<<"               "<<new_salary<<"           "<<new_depart<<endl;
		} 
		else
		{
			write<<id<<"        "<<name<<"          "<<age<<"          "<<gender<<"               "<<salary<<"           "<<depart<<endl;
		}
	}
	write.close(); read.close();
	ifstream reads("Temp.txt",ios::in);
	ofstream writes("Employee.txt",ios::out);
	while (getline(reads,line))
	{
		writes<<line<<endl;
	}
	writes.close(); reads.close(); remove("Temp.txt");
}

void DeleteRecord()
{
	int id,new_id,opt_id,salary,new_salary,age,new_age; string line,name,new_name,depart,new_depart; char gender,new_gender;
	cout<<"Please Enter ID For Delete Record: "; cin>>opt_id;
	ifstream read("Employee.txt",ios::in);
	getline(read,line);
	ofstream write("Temp.txt",ios::out);
	write<<line<<endl;
	while (!read.eof())
	{
		read>>id>>name>>age>>gender>>salary>>depart;
		if (id != opt_id)
		write<<id<<"        "<<name<<"          "<<age<<"          "<<gender<<"               "<<salary<<"           "<<depart<<endl;
	}
	write.close(); read.close();
	ifstream reads("Temp.txt",ios::in);
	ofstream writes("Employee.txt",ios::out);
	while (getline(reads,line))
	{
		writes<<line<<endl;
	}
	writes.close(); reads.close(); remove("Temp.txt");
}
	
	
	

