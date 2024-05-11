#include <stdio.h>
#define HEIGHT 2.5

typedef struct{
    double x;
    double y;
}Point;

void table_finite_diff(int n,double arr[n][n],Point p[n]);

int factorial(int x);

double newton1(int n,double px,Point p[n],double arr[n][n]);

double newton2(int n,double px,Point p[n],double arr[n][n]);

int main()
{
    FILE *data = fopen("data.txt","w");
    FILE *point = fopen("point.txt","w");
    int size;
    double interpol;

    printf("size ->");
    scanf("%d",&size);

    Point p[size];
    double arr[size][size];

    for(int n = 0;n < size;n++){
        printf("x%d ->",n);
        scanf("%lf",&p[n].x);
        printf("y%d ->",n);
        scanf("%lf",&p[n].y);
    }

    for(int n = 0;n < size;n++)
        fprintf(data,"%f     %f\n",p[n].x,p[n].y);

    printf("interpolation ->");
    scanf("%lf", &interpol);

    table_finite_diff(size,arr,p);

    double P1 = newton1(size,interpol,p,arr);
    double P2 = newton2(size,interpol,p,arr);

    fprintf(point,"%.4f     %f\n",P1,HEIGHT);
    fprintf(point,"%.4f     %f\n",P2,HEIGHT + 2);
    fclose(data);
    fclose(point);

    return 0;
}

int factorial(int x)
{
    int mul = 1;

    for(int i = 1;i <= x;i++)
        mul *= i;

    return mul;
}

void table_finite_diff(int n,double arr[n][n],Point p[n])
{
    for(int i = 0;i < n;i++)
        arr[i][0] = p[i].y;

    for(int i = 1;i < n;i++)
        for(int j = 0;j < n - i;j++)
            arr[j][i] = arr[j + 1][i - 1] - arr[j][i - 1];
}

double newton1(int n,double px,Point p[n],double arr[n][n])
{
    double q = (px - p[0].x) / (p[n - 1].x - p[n - 2].x)//шаг интерполяции, или шаг между значениями "x", если у нас шаг не равномерный, то мы не можем использовать 1 метод; 
    double P = p[0].y; //значение функции в первой точке

    for(int i = 0; i < n - 1; i++){
        int count = 0;
        double digitQ = q; //шаг в таблице функций

        while(count != i){ //вычисляем степень шага 
            count++;
            digitQ *= q - count;
        }

        P += (arr[0][i + 1] / factorial(i + 1)) * digitQ;
    }

    return P;
}

double newton2(int n,double px,Point p[n],double arr[n][n])
{
    double q = (px - p[n - 1].x) / (p[n - 1].x - p[n - 2].x); //q вычислячется с последней точки
    double P = p[n - 1].y; //последний вместо певрого
    int index = n - 2;

    for(int i = 0;i < n - 1;i++){
        int count = 0;
        double digitQ = q;

        while(count != i){
            count++;
            digitQ *= q + count;
        }

        P += (arr[index][i + 1] / factorial(i + 1)) * digitQ;
        index--;
    }

    return P;
}