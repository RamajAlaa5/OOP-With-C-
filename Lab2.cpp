#include <iostream.h>
#include <string.h>
#include<conio.h>



class Employee{
    int id;
    float salary;
    char name[20];
    public:
    void setID(int ID);
    void setName(char Name[20]);
    void setSalary(float Salary);
    int getEmployeeId();
    char* getEmployeeName();
    float getEmployeeSalary();
};


Employee FillEmpData();
void PrintEmpData(Employee emp);

int main(){
Employee emp;
emp=FillEmpData();
PrintEmpData(emp);
getch();
    return 0;
}






void Employee::setID(int ID){

     id=ID;
}


void Employee::setName(char Name[20]){

    strcpy(name,Name);
}

  void Employee::setSalary(float Salary){

    salary=Salary;
}
    int Employee::getEmployeeId(){
	return id;
    }
    char* Employee::getEmployeeName(){
    return name;}

    float Employee::getEmployeeSalary(){
	return salary;}

Employee FillEmpData(){
    Employee emp;
    int i;
    char n[20];
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
