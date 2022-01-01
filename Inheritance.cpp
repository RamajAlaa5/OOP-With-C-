#include <iostream.h>
#include <string.h>
#include <conio.h>

class Person{
   protected:
     int id;
     char* name;

     public:
     void setPersonID(int id){
     this->id=id;
     }
     void setPersonName(char* PName){
     strcpy(this->name,PName);
     }
     int getPersonID(){
     return this->id;
     }
     char* getPersonName(){
     return this->name;
     }

     Person(){
     this->id=1;
     strcpy(this->name,"Ramaj");
     }
     Person(int id,char* personName){
     this->id=id;
     strcpy(this->name,personName);
     }
     //void printPersonData(Person P);
     void Print();

};

//void Person::PrintPersonData(Person P){
//cout<<"Person ID= "<<P.getPersonID()<<endl;
//cout<<"Person Name= "<<P.getPersonName()<<endl;
//}
void Person::Print(){
cout<<"ID="<<this->getPersonID()<<endl;
cout<<"Name="<<this->getPersonName()<<endl;
}

class Customer:virtual public Person{
protected:
  char* contact;
public:
customer(){
id=1;
strcpy(name,"customer");
strcpy(contact,"customer@gmail.com");
}

customer(int ID,char* n){
id=ID;
strcpy(name,n);
strcpy(contact,"customer@gmail.com");

}
Customer(int ID,char* n,char* contactInfo){
id=ID;
strcpy(name,n);
strcpy(contact,contactInfo);
}

void setCustomerContact(char* c){

strcpy(this->contact,c);
}

char* getCustomerContact(){
return this->contact;
}

Customer(){
strcpy(contact,"111111");

}
//void PrintPersonData(Customer c){
//cout<<"Customer ID= "<<c.getPersonID()<<endl;
//cout<<"Customer Name= "<<c.getPersonName()<<endl;
//cout<<"Customer Contact Info ="<<c.getCustomerContact();
//}

void Print(){
cout<<"ID="<<this->getPersonID()<<endl;
cout<<"Name="<<this->getPersonName()<<endl;
cout<<"contact Info="<<this->getCustomerContact()<<endl;
}

};



class Employee:virtual public Person{
protected:
float salary;

public:

void setEmployeeSalary(float s){
this->salary=s;
}

float getEmployeeSalary(){
return this->salary;
}
Employee(){
salary=2000;
}
Employee(int ID,char* n,float s){
id=ID;
strcpy(name,n);
salary=s;
}

Employee(int ID,char* n){
id=ID;
strcpy(name,n);
salary=200;
}
//void PrintPersonData(Employee emp){
//cout<<"Employee ID ="<<emp.getPersonID()<<endl;
//cout<<"Employee Name="<<emp.getPersonName()<<endl;
//cout<<"Employee Salary="<<emp.getEmployeeSalary()<<endl;
//}
void Print(){
cout<<"ID="<<this->getPersonID()<<endl;
cout<<"Name="<<this->getPersonName()<<endl;
cout<<"Salary="<<this->getEmployeeSalary()<<endl;
}

};


int main(){
Employee emp(2,"Toka",2000);
//Employee emp1(1,"Mohammed");
emp.Print();
cout<<endl;
Customer c(3,"Ramaj","Ramaj@gmail.com");
c.Print();

    getch();
    return 0;
}
