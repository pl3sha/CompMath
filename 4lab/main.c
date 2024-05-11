#include <stdio.h>
#define HEIGHT 4.5

typedef struct 
{
    double x;
    double y;
}Point;

double interpolation(int n,double px,Point p[n]);

int main()
{
    FILE *data = fopen("data.txt","w");
    FILE *point = fopen("point.txt","w");
    int size;
    double interpol;

    printf("size ->");
    scanf("%d",&size);

    Point p[size];

    for(int n = 0;n < size;n++){
        printf("x%d ->",n);
        scanf("%lf",&p[n].x);
        printf("y%d ->",n);
        scanf("%lf",&p[n].y);
    }

    for(int n = 0;n < size;n++)
        fprintf(data,"%f     %f\n",p[n].x,p[n].y);

    printf("interpolation ->");
    scanf("%lf",&interpol);

    double P_inter = interpolation(size,interpol,p);

    fprintf(point,"%f     %f\n",P_inter,HEIGHT);
    fclose(data);
    fclose(point);

    return 0;
}

double interpolation(int n,double px,Point p[n])
{
    double P_inter = 0.0;
    double value;

    for(int i = 0;i < n;i++){
        value = 1.0;
        for(int j = 0;j < n;j++){
            if(i != j)
                value *= (px - p[j].x) / (p[i].x - p[j].x);
        }
        P_inter += p[i].y * value;
    }

    return P_inter;
}