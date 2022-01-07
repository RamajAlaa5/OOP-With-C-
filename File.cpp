#include <iostream.h>
#include <string.h>
#include <conio.h>
#include<fstream.h>

class Point3D{
int x,y,z;
public:

Point3D(){
x=y=z=0;
 }

 Point3D(int l,int m, int n){
 x=l;
 y=m;
 z=n;
 }

 friend ostream& operator<<(ostream& out,Point3D p);
 friend istream& operator>>(istream& in,Point3D& p);

};

ostream& operator<<(ostream& out,Point3D p){
out<<"x="<<p.x<<endl;
out<<"y="<<p.y<<endl;
out<<"z="<<p.z<<endl;
return out;
     }

istream& operator>>(istream& in,Point3D& p){
    cout<<"Enter x";
    in>>p.x;
    cout<<"Enter y";
    in>>p.y;
    cout<<"Enter z";
    in>>p.z;
    return in;

}



int main(){
fstream myfile;
int x;
x=100;
char ch =(char) x;

//myfile.open("test.txt",ios::out);
//myfile<<x;

myfile.open("example.bin",ios::out | ios::binary);
myfile.write(&ch,sizeof(ch));
myfile.close();


//myfile.open("TEST",ios::in);
//myfile>>x;
//myfile.close();
//cout<<x;


cout<<endl;
myfile.open("example.bin",ios::binary | ios::in);
myfile.read(&ch,sizeof(ch));
myfile.close();
cout<<"the value of x="<<(int)ch;





    getch();
    return 0;
}
