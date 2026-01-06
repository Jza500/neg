#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

void stat(const double[],int,double[]);

int main(){
    double A[] = {1.2,3.5,6.9,7.8,12.5,0.5};
    int N = sizeof(A)/sizeof(A[0]);
    double B[6];
    stat(A,N,B);
    cout << fixed << setprecision(2);
    cout << "Arithmetic Mean = " << B[0] << endl;
    cout << "Standard Deviation = " << B[1] << endl;
    cout << "Geometric Mean = " << B[2] << endl;
    cout << "Harmonic Mean = " << B[3] << endl;
    cout << "Max = " << B[4] << endl;
    cout << "Min = " << B[5];
    return 0;
}

void stat(const double x[],int y,double z[]){
    double sum;
    for (int i = 0; i < y; i++)
    {
        sum += x[i];
    }
    z[0]= sum / y;
    double xMean2;
    for (int i = 0; i < y; i++)
    {
        xMean2 += pow(x[i]-z[0],2);
    }
    z[1]= sqrt(xMean2/y);
    double Mult = 1;
    for (int i = 0; i < y; i++)
    {
        Mult *= x[i];
    }
    z[2]= pow(Mult,1.0/y);
    double sumSideDown;
    for (int i = 0; i < y; i++)
    {
        sumSideDown += 1.0/x[i];
    }
    z[3]= y/sumSideDown;
    double Max,Min = x[0];
    for (int i = 1; i < y; i++)
    {
        if (x[i] > Max)
        {
            Max = x[i];
        }
        if (Min > x[i])
        {
            Min = x[i];
        }
    }
    z[4]= Max;
    z[5]= Min;
}