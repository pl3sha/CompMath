#include <stdio.h>
#include <math.h>

double func(double x)
{
    return log(1 + x) / x;
}

int main(int argc, char **argv)
{
    double eps = 1E-5;
    double a = 0.1;
    double b = 1.0;
    int n0 = 10000000;
    int k,n = n0;
    double sq[2], delta = 1;

    for(k = 0;delta > eps;n *= 2,k ^= 1){
        double h = (b - a) / n;
        double s = 0.0;
        sq[k] = 0;

        for(int i = 0;i < n;i++)
            s += (func(a + h * (i + 1)) + func(a + h * (i + 0))) / 2;
            
        sq[k] += s * h; 
        
        if(n > n0)
            delta = fabs(sq[k] - sq[k ^ 1]) / 3.0;

        printf("n = %d i = %d sq = %.12f delta = %.12f\n",n,k,sq[k],delta);
    }

    return 0;
}