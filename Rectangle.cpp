
#include "iostream"
using namespace std;

class Location
{
public:
   void setX(int x)
   {
       this->x = x;
   }

   void setY(int y)
   {
       this->y = y;
   }
   int getX()
   {
       return this->x;
   }

   int getY()
   {
       return this->y;
   }

private:
    int x;
    int y;

};

class Rectangle {
public:
    Rectangle(Location l,Location r)
    {
        Left_up = l;
        Right_down = r;
    }
    int getLength()
    {
        return abs(Right_down.getX() - Left_up.getX());
    }

    int getWidth()
    {
        return abs(Left_up.getY() - Right_down.getY());
    }

    int  Circumference()
    {
        int c = 2 * (getLength() + getWidth());
        return c;
    }

    int Square()
    {
        int s = getWidth() * getLength();
        return s;
    }
private:
    Location Left_up;
    Location Right_down;

};

void test01()
{
    Location L,R;
    L.setX(1);
    L.setY(4);
    R.setX(3);
    R.setY(2);
    Rectangle rec(L,R);
    cout << "c = " << rec.Circumference() << endl;
    cout << "s = " << rec.Square() << endl;
}

int main()
{
    test01();
    return 0;

}
