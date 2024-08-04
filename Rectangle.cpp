#include<iostream>
using namespace std;
#include<string>

class Point
{
public:
    void setX(int x){m_x=x;}
    void setY(int y){m_y=y;}
    int getX(){return m_x;}
    int getY(){return m_y;}
private:
    int m_x;
    int m_y;
};
int C(Point p1,Point p2){
    int l,w,c;
    l=abs(p1.getX()-p2.getX());
    w=abs(p1.getY()-p2.getY());
    c=(l+w)*2;
    return c;
    
}
int  A(Point p1,Point p2){
    int a,l,w;
    l=abs(p1.getX()-p2.getX());
    w=abs(p1.getY()-p2.getY());
    a=l*w;
    return a;
    
}
int main()
{
    Point p1;
    p1.setX(1);
    p1.setY(3);
    Point p2;
    p2.setX(2);
    p2.setY(4);
    
    cout <<"周长为："<<C(p1,p2)<<endl;
    
    cout <<"面积为："<<A(p1,p2)<<endl;

    return 0;
}