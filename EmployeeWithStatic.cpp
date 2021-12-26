#include <iostream.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#include <stdlib.h>

class Employee{
    static int objectCount;
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
    Employee operator + (Employee emp);
    Employee operator+(char* n);
    friend Employee operator + (char* n,Employee emp);
    Employee operator++();
    Employee& operator=(Employee& emp);
    Employee operator++(int d);
    int operator ==(Employee emp);
   friend Employee operator+(int m,Employee emp);
    Employee operator+(int m);
    operator char*();
   static int getObjectCount();
   static char* companyName;
   static char* getCompanyName();
   static void setCompanyName( char* company){
     Employee::companyName=company;
  }
    ~Employee(){
    delete nameArr;
    objectCount--;
    }
};
int Employee::objectCount=0;
char* Employee::companyName="ITI";



Employee FillEmpData();
void PrintEmpData(Employee emp);

int main(){
Employee::setCompanyName("Open Source");
Employee emp1(1,"Ramaj",2000);
//Employee emp2(2,"Toka",3000);
//Employee emp1;
//emp1=FillEmpData();
cout<<endl;
//cout<<"Number Of Objects = "<<Employee::getObjectCount()<<endl;
//Employee::setCompanyName("OpenSource");

PrintEmpData(emp1);
 //const int empNumber=2;
   //Employee emp[empNumber];

 //Employee *emp;
 //emp=new Employee(1,"ramaj",1200) ;
 //cout<<endl;
 //PrintEmpData(*emp);

 //int empNumber;
 //cout<<"Enter Employee Number"<<endl;
 //cin>>empNumber;
 //Employee* empArray =new Employee[empNumber];

//for(int i=0;i<empNumber;i++){
// empArray[i]=FillEmpData();
 //}
//for(int j=0;j<empNumber;j++){
// PrintEmpData(empArray[j]);
// }

getch();

    return 0;
}




Employee::Employee(){
    this->id=1;
    this->salary=4000;
    this->Size=20;
    nameArr=new char[Size];
    strcpy(this->nameArr,"User");
    objectCount++;
}

int Employee::getObjectCount(){
return objectCount;
}

char* Employee::getCompanyName() {
return companyName;
}

  Employee::Employee(int i,char* n,float s){
	     this->id=i;
	     this->Size=20;
	     nameArr=new char[Size];
	     strcpy(this->nameArr,n);
	     this->salary=s;
	     objectCount++;

 }


Employee::Employee(char* n,int s){
     this->Size=s;
    nameArr=new char[s];
    strcpy(nameArr,n);
    objectCount++;
}


Employee::Employee(int id){
	this->id=id;
	objectCount++;
}

Employee::Employee(int id,char* name){
this->id=id;
this->Size=20;
nameArr=new char[Size];
strcpy(this->nameArr,name);
objectCount++;
}


Employee::Employee(Employee& emp){
this->id=emp.id;
strcpy(nameArr,emp.nameArr);
this->Size=emp.Size;
this->salary=emp.salary;
objectCount++;

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
    cout<<"Company Name= "<<Employee::getCompanyName()<<endl;
}
Employee Employee::operator + (Employee emp){
     Employee emp1;
     emp1.id=this->id;
     emp1.salary=this->salary+emp.salary;
     strcpy(emp1.nameArr,strcat(this->nameArr,emp.nameArr));
     return emp1;
     }

Employee Employee::operator + (char* n){
Employee emp;
emp.id=this->id;
strcpy(emp.nameArr,strcat(this->nameArr,n));
emp.salary=this->salary;
return emp;
}

Employee  operator + (char* n,Employee emp){
Employee emp1;
emp1.id=emp.id;
emp1.salary=emp.salary;
strcat(n,emp.nameArr);
strcpy(emp1.nameArr,n);
return emp1;

}
Employee operator +(int m,Employee emp){
Employee emp1;
emp1.id= emp.id;
emp1.salary=emp.salary+m;
strcpy(emp.nameArr,emp.nameArr);
return emp1;
}

Employee Employee:: operator +(int m){
Employee emp1;
emp1.id=id;
emp1.salary=salary+m;
strcpy(emp1.nameArr,nameArr);
return emp1;
}

Employee& Employee::operator = (Employee& emp){
this->id=emp.id;
this->salary=emp.salary;
delete(nameArr);
nameArr= new char[strlen(emp.nameArr)+1];
strcpy(this->nameArr,emp.nameArr);
return *this;
}

Employee Employee:: operator ++ (){
  salary++;
  return *this;
  }

Employee  Employee:: operator ++ (int d){
Employee emp;
emp=*this;

++(*this);
return emp;
}

int Employee:: operator == (Employee emp){
return(id==emp.id && salary==emp.salary && !strcmp(nameArr,emp.nameArr));

}
Employee::operator char*(){
return nameArr;
}

