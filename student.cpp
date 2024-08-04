#include<iostream>
using namespace std;
#include<string>

class Student
{

public:
    
    void setStudent(string name,double score1,double score2,double score3){
        m_name=name;
        m_score1=score1;
        m_score2=score2;
        m_score3=score3;
    }
    
    Student operator+(const Student &s){
        Student temp;
        temp.m_score1=this->m_score1+s.m_score1;
        temp.m_score2=this->m_score2+s.m_score2;
        temp.m_score3=this->m_score3+s.m_score3;

        return temp;
    }
    void average(){
        double average_score1=m_score1/2.0;
        double average_score2=m_score2/2.0;
        double average_score3=m_score3/2.0;
        cout <<"Score 1:"<<average_score1<<endl;
        cout <<"Score 2:"<<average_score2<<endl;
        cout <<"Score 3:"<<average_score3<<endl;

    }
public:
    string m_name;
    double m_score1;
    double m_score2;
    double m_score3;



};

int main(){
    Student S1;
    Student S2;
    S1.setStudent("张三",76.0,57.0,66.0);
    
    S2.setStudent("李四",66.0,99.0,78.5);
   
    Student result=S1 + S2;
    cout << "Result Scores:" << endl;
    cout << "Score 1: " << result.m_score1 << endl;
    cout << "Score 2: " << result.m_score2 << endl;
    cout << "Score 3: " << result.m_score3<< endl;
    cout <<"Average Score:" << endl;
    result.average();

return 0;


}

