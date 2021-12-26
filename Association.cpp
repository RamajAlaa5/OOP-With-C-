#include <iostream.h>
#include <string.h>
#include <conio.h>
#include <math.h>
class Point{
int x,y;
public:
Point(){
x=y=0;
}
Point(int val){
x=y=val;
}
Point(int valX,int valY){
x=valX;
y=valY;
}

void setX(int val){
this->x=val;
}

void setY(int val){
this->y=val;
 }

 int getX(){
 return x;
 }
 int getY(){
 return y;
 }

};

class Rectangle{
Point *p1,*p2;
int length,width;
public:
Rectangle(){
p1=p2=NULL;
length=width=0;

}

Rectangle(Point *point1,Point *point2){
   p1=point1;
   p2=point2;
   if(p1&&p2){
   length=abs(p2->getX()-p1->getX());
   width=abs(p2->getY()-p1->getY());
   }
}
void setPoint1(Point *point1){
p1=point1;
if(p1){
  length=abs(p2->getX()-p1->getX());
  width=abs(p2->getY()-p1->getY());
}
}

void setPoint2(Point *point2){
p2=point2;
if(p2){
length=abs(p2->getX()-p1->getX());
width=abs(p2->getY()-p1->getY());
}
 }

 int getRectangleArea(){
 return (length*width);
 }

 int getCircumference(){
 return (2*(length+width));
 }

};



int main(){
    //Rectangle rec(5,10,10,15);
    Rectangle rec;
    Point P1(5,10);
    Point P2(10,15);
    rec.setPoint1(&P1);
    rec.setPoint2(&P2);
    cout<<"Rectangle Area= "<<rec.getRectangleArea()<<endl;
    getch();
    return 0;
}
