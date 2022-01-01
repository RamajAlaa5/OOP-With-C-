#include <iostream.h>
#include <string.h>
#include <conio.h>

class Shape{
protected:
int dimension1,dimension2;
public:
Shape(){
dimension1=dimension2=0;
}
Shape(int d){
dimension1=dimension2=d;
}
Shape(int d,int dd){
dimension1=d;
dimension2=dd;
}

void setDimension(int d1){
dimension1=d1;
}
void setDimension2(int d2){
dimension2=d2;
}
int getDimension1(){
return dimension1;
}
int getDimension2(){
return dimension2;
}
virtual float Area(){
return 1;
}


};



class Circle:public Shape{

public:

Circle(){}
Circle(int r):Shape(r){}
float Area(){
return (3.14*dimension1*dimension2);
}

};

class Triangle:public Shape{

public:

Triangle(){}
Triangle(int b,int h):Shape(b,h){}

float Area(){
return (0.5*dimension1*dimension2);
}

};


class Rectangle:public Shape{
public:

Rectangle(){}
Rectangle(int l,int w):Shape(l,w){}
float Area(){
return (dimension1*dimension2);
}

};

class Square:public Rectangle{
public:
Square(){}
Square(int s,int s1):Rectangle(s,s1){}
};

class geometricShape{
//Shape *ptr[4];
int size;
Shape **ptr;

public:
geometricShape(Shape **ptr1,int size);
//geometricShape(Shape *ptr1,Shape *ptr2,Shape *ptr3,Shape *ptr4){

//ptr[0]=ptr1;
//ptr[1]=ptr2;
//ptr[2]=ptr3;
//ptr[3]=ptr4;
//}
//geometricShape(Shape *ptr1,int size){
   //this->size=size;
  // ptr1=new Shape[size];
   //for(int i=0;i<size;i++){
	  // ptr[i]=ptr1[i];
//}

float TotalArea();


};

 float geometricShape::TotalArea(){
 float Sum=0;
 for(int i=0;i<this->size;i++){
 Sum+=ptr[i]->Area();
 }
 return Sum;
 }

 geometricShape::geometricShape(Shape **ptr1,int size){
 this->size=size;
 ptr= new Shape*[size];
 for(int i=0;i<size;i++){
 ptr[i]=ptr1[i];
 }
  }


int main(){
  Circle c(4);
  Rectangle r(3,4);
  Square s(4,4);
  Triangle t(4,6);
  Shape* ptr[4]={&t,&c,&s,&r};

  geometricShape G(ptr,4);

  cout<<"Total Area For Shapes = "<<G.TotalArea();

    getch();
    return 0;
}
