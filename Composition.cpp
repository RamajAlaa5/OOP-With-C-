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
Point p1,p2;
int length,width;
public:
Rectangle(){
 Rectangle rec;
 rec.setPoint1(5,10);
 rec.setPoint2(10,15);
 length=abs(10-5);
 width=abs(15-10);
}

Rectangle(int x1,int y1,int x2,int y2):p1(x1,y1),p2(x2,y2){
length=abs(x2-x1);
width=abs(y2-y1);
}
void setPoint1(int x,int y){
p1.setX(x);
p1.setY(y);
length=abs(p2.getX()-x);
width=abs(p2.getY()-y);
}

void setPoint2(int x,int y){
 p2.setX(x);
 p2.setY(y);
 length=abs(x-p1.getX());
 width=abs(y-p1.getY());
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
    //rec.setPoint1(5,10);
    //rec.setPoint2(10,15);
    cout<<"Rectangle Area= "<<rec.getRectangleArea()<<endl;
    getch();
    return 0;
}
