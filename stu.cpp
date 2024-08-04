#include <iostream>
#include<string>
using namespace std;
class Student
{
   public:
 
      double getScore()
      {
         return a + b + c;
      }
      void setScorea( double a0 )
      {
          a = a0;
      }
 
      void setScoreb( double b0 )
      {
          b = b0;
      }
 
      void setScorec( double c0 )
      {
          c = c0;
      }
      Student operator+(const Student& s)
      {
         Student scores;
         scores.a = this->a + s.a;
         scores.b = this->b + s.b;
         scores.c = this->c + s.c;
         return scores;
      }
   private:
      double a;    
      double b;     
      double c;      
};
int main( )
{
   Student S1;                
   Student S2;                
   Student S3;                
   double sum = 0.0;

   S1.setScorea(100.0); 
   S1.setScoreb(100.0); 
   S1.setScorec(100.0); 
 
   S2.setScorea(90.0); 
   S2.setScoreb(90.0); 
   S2.setScorec(90.0); 

   S3 = S1 + S2;

   sum = S3.getScore();
   cout << sum <<endl;
   cout << sum/6.0 <<endl;
   return 0;
}