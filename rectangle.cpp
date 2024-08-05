#include<iostream>
using namespace std;
/*设计一个名为Rectangle的矩形类，
其属性为矩形的左上角和右下角两个点的坐标，
能计算和输出矩形的周长与面积。*/
class R
{
    public:
       void setAx(int x1)
       {
           ax=x1;
       }
       void setAy(int y1)
       {
           ay=y1;
       }
       void setBx(int x2)
       {
           bx=x2;
       }
       void setBy(int y2)
       {
           by=y2;
       }
       int getAx()
       {
           return ax;
       }
       int getAy()
       {
           return ay;
       }
       int getBx()
       {
           return bx;
       }
       int getBy()
       {
           return by;
       }
       int C()
       {
           return (bx-ax)*2+(ay-by)*2;
       }
       int S()
       {
           return (bx-ax)*(ay-by);
       }
       private:
       int ax;
       int ay;
       int bx;
       int by;

};
int main()
{
    R r;
    r.setAx(10);
    r.setAy(10);
    r.setBx(20);
    r.setBy(5);
    cout<<"矩形周长为："<<r.C()<<endl;
    cout<<"矩形面积为："<<r.S()<<endl;
    return 0;
}