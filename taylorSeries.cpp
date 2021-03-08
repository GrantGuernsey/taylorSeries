#include <iostream> 
#include <cmath>
using namespace std;
const double &PI = M_PI;
const double &TOL = 1.e-6;
const double &Q = pow(10,-9);
const double &ke = 9 * pow(10,9);
const int rmin = 0;
const int rmax = 100;
const size_t &WIDTH = 2;
const size_t &PREC = 2;


   int factorial (const int &n)
   {
       if(n < 0)
       {
           cout << "Error: factorial value for negative number is not defined" << endl;
           return -1; 
       }
       else if(n>1)
       {
           return n * factorial(n-1);
       }
       else
       {
           return 1;
       }
   }

double degreesToRadians(double angle_in_degrees)
{
    if(angle_in_degrees >= 360)
    {
        angle_in_degrees -= 360;
    }
    if(angle_in_degrees < 0)
    {
        angle_in_degrees += 360;
    }
    return angle_in_degrees * PI /180;
}

double mySine(const double &x, int i, double &seriesTerm)
{
    double sum_old= 100.0;
    double sum_new= 0.0;
    int y = 1;
    int count = 0;

    while(fabs(sum_new - sum_old) > TOL)
    {
         sum_old = sum_new;
         sum_new += pow(-1, count) * (pow(x,y) / factorial(y));
         
         count += 1;
         if(count == i)
         {
             seriesTerm = pow(x,y) / factorial(y);
         }
         y += 2;
    }
    return sum_new;

}

double myCosine(const double &x, int i, double &seriesTerm)
{
    double sum_old= 100.0;
    double sum_new= 0.0;
    int y = 0;
    int count = 0;

    while(fabs(sum_new - sum_old) > TOL)
    {
         sum_old = sum_new;
         sum_new += pow(-1, count) *(pow(x,y) / factorial(y));
         
         count += 1;
         if(count == i)
         {
             seriesTerm = pow(x,y) / factorial(y);
         }
         y += 2;
    }
    return sum_new;

}



    




int main(void) {



}


