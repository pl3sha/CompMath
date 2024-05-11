#include <stdio.h>
#define F(x,y) (y * (x * x + 1))

double euler(double x0,double xn,double y0,double h);

int main()
{
    double x0,xn,y0,h;

    printf("(x0 - xn) ->");
    scanf("%lf %lf",&x0,&xn);
    printf("h ->");
    scanf("%lf",&h);
    printf("y0 ->");
    scanf("%lf",&y0);
    printf("yn - %f\n",euler(x0,xn,y0,h));

    return 0;
}

double euler(double x0,double xn,double y0,double h)
{
    double y = 0.0;

    for(x0 = h;x0 < xn;x0 += h){
        y = y0 + h * F(x0,y0);
        y0 = y;
    }

    return y;
}