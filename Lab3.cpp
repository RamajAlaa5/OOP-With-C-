#include <iostream.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>


class Employee{
    int id;
    int Size;
    float salary;
    char* nameArr;
    public:
    void setID(int ID);
    void setName(char* name);
    void setSalary(float Salary);
    int getEmployeeId();
    char* getEmployeeName();
    float getEmployeeSalary();
    int getSize();
    Employee(char* n,int s=20);
    Employee();
    Employee(int id);
    Employee(int id,char* name);
    Employee(int id,char* name,float salary);
    Employee(Employee &emp);
    ~Employee(){
    delete nameArr;
    }
};


Employee FillEmpData();
void PrintEmpData(Employee emp);

int main(){
Employee emp(1,"Ramaj",1234);
//emp=FillEmpData();
//Employee emp1;
//emp1=emp;
//PrintEmpData(emp1);
PrintEmpData(emp);
emp.~Employee();

getch();

    return 0;
}




Employee::Employee(){
    this->id=1;
    this->salary=4000;
    this->Size=20;
    nameArr=new char[Size];
    strcpy(this->nameArr,"User");
}


  Employee::Employee(int i,char* n,float s){
	     this->id=i;
	     this->Size=20;
	     nameArr=new char[Size];
	     strcpy(this->nameArr,n);
	     this->salary=s;

 }


Employee::Employee(char* n,int s){
     this->Size=s;
    nameArr=new char[s];
    strcpy(nameArr,n);
}


Employee::Employee(int id){
	this->id=id;
}

Employee::Employee(int id,char* name){
this->id=id;
this->Size=20;
nameArr=new char[Size];
strcpy(this->nameArr,name);
}


Employee::Employee(Employee& emp){
this->id=emp.id;
strcpy(nameArr,emp.nameArr);
this->Size-=emp.Size;
this->salary=emp.salary;

}

void Employee::setID(int ID){

     id=ID;
}


void Employee::setName(char* name){
    strcpy(this->nameArr,name);
}

  void Employee::setSalary(float Salary){

    salary=Salary;
}

int Employee::getEmployeeId(){
	return id;
    }


 char* Employee::getEmployeeName(){
    return nameArr;
  }

  float Employee::getEmployeeSalary(){
	return salary;
  }

 int Employee::getSize(){
 return Size;
 }

Employee FillEmpData(){
    Employee emp;
    int i;
    char* n;
    float s;
    cout<<"Enter Employee ID"<<endl;
    cin>>i;
    cout<<"Enter Employee Name"<<endl;
     cin>>n;
    cout<<"Enter Employee Salary"<<endl;
     cin>>s;
    emp.setID(i);
    emp.setName(n);
    emp.setSalary(s);
    return emp;
}
void PrintEmpData(Employee emp){
    cout<<"Employee ID= "<<emp.getEmployeeId()<<endl;
    cout<<"Employee Name= "<<emp.getEmployeeName()<<endl;
    cout<<"Employee Salary= "<<emp.getEmployeeSalary()<<endl;
}
