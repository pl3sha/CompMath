#include <stdio.h>
#define HEIGHT 4.5

typedef struct{
    double x;
    double y;
}Point;

double aitken(int n,double px,Point p[n]);

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

    double P_inter = aitken(size,interpol,p);

    fprintf(point,"%f     %f\n",P_inter,HEIGHT);
    fclose(data);
    fclose(point);

    return 0;
}

double aitken(int n,double px,Point p[n])
{
    int size = n;

    for(int i = 1;i < n;i++)
        size += n - i;

    double arr[size];

    for(int i = 0;i < n;i++)
        arr[i] = p[i].y;

    int index = n;

    for(int j = 0;j < n - 1;j++){
        for(int i = 0;i < n - j - 1;i++){
            double ch = (arr[index - n + j] * (px - p[j + i + 1].x)) - (arr[index - n + j + 1] * (px - p[i].x));
            double zn = p[i].x - p[i + j + 1].x;
            arr[index] = ch / zn;
            index++;
        }
    }

    return arr[size - 1];
}