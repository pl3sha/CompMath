#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <inttypes.h>
#include <math.h>
#define F(x,y) pow(exp(x + y),2)

const double PI = 3.14159265358979323846;
int n = 10000000;

double getrand()
{
    return (double)rand() / RAND_MAX;
}

int main()
{
    int in = 0;
    double s = 0; 

    for(int i = 0;i < n;i++){
        double x = getrand() * PI;
        double y = getrand();
        if(y <= sin(x)){
            in++;
            s += F(x,y);
        }
    }

    double v = PI * in / n;
    double res = v * s / in;

    printf("Result - %.12f n - %d\n", res, n);

    return 0;
}