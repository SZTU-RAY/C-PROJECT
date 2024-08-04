#include "iostream"
#include "string.h"
using namespace std;


class Student
{
public:
    Student(string name,int c1,int c2,int c3)
    {
        m_name = name;
        m_course1 = c1;
        m_course2 = c2;
        m_course3 = c3;
    }

    Student operator+(Student &p)
    {
        Student temp("",0,0,0);
        temp.m_course1 = this->m_course1 + p.m_course1;
        temp.m_course2 = this->m_course2 + p.m_course2;
        temp.m_course3 = this->m_course3 + p.m_course3;

        return temp;

    }

    double average(Student& p)
    {
        double temp = 0;
        temp = p.m_course1 + p.m_course2 + p.m_course3;
        return temp / 3.0;
    }

    ~Student(){}

private:
    string m_name;
    int m_course1;
    int m_course2;
    int m_course3;
};

void test01()
{
    Student s1("abc",100,90,80),s2("def",70,60,50);
    Student total = s1 + s2;
    double average_total = total.average(total);
    cout << "相加后的平均分：" << average_total;

}

int main()
{
    test01();
    return 0;
}

//zhushi zhushi 