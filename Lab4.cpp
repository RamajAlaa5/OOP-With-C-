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
    ~Employee(){
    delete nameArr;
    }
};


Employee FillEmpData();
void PrintEmpData(Employee emp);

int main(){
Employee emp;
Employee emp1(1,"Ramaj",1000);
emp=1000+emp1;

PrintEmpData(emp);

    // if(emp1==emp2){
    // cout<<"yes"<<endl;
     //}
    // else{
    // cout<<"no"<<endl;
   //  }

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
this->Size=emp.Size;
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

