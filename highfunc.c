#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "highfunc.h"


//斐波那数列
int fun1(int n)
{
    int f1 = 1;
    int f2 = 1;
    int sum = 0;
    int i = 0;

    if(n <= 0) return -1;
    if(n == 1 || n == 2) return sum = 1;
    printf("%d\t%d\t", 1, 1);

    for(i=3; i<=n; i++)
    {
        sum = f1 + f2;
        f1 = f2;
        f2 = sum;
        printf("%d\t", sum);
    }

    return sum;
}

int fun2(int n)
{
    int sum = 0;

    if(n <= 0)          return -1;  //防止用户输错
    if(n==1 || n==2)    return 1;   //结束条件
    sum = fun2(n-1) + fun2(n-2);

    return sum;
}


//函数指针(结构体demo)
int GetArea(void)
{
    int t = 0;

    double a = 0;
    double b = 0;
    double area = 0.0;
    Myshape pic = {0};

    t = GetShape();
    if(t < 1 || t > 3)
    {
        printf("input error\n");
        return -1;
    }

    GetTwoLength(&a, &b);
    pic.l1 = a;
    pic.l2 = b;
    pic.type = t;

    switch (pic.type)
    {
        case 1:
            pic.parea = CountTriangArea;
            break;
        case 2:
            pic.parea = CountRectangleArea;
            break;
        case 3:
            pic.parea = CountEllipseArea;
            break;
    }

    area = pic.parea(pic.l1, pic.l2);
    printf("pic.parea:%lf\n", area);

    return 0;

}

int GetShape()
{
    int a = 0;
    printf("please input shape\n");
    printf("1:Triang\n");
    printf("2:Rectangle\n");
    printf("3:Ellipse\n");

    scanf("%d", &a);

    while(getchar() != '\n' ){};

    return a;
}

int GetTwoLength(double *pl1, double *pl2)
{
    if(pl1 == NULL || pl2 == NULL)
    {
        return -1;
    }

     printf("please input l1 and l2\n");
     printf("example: 2.3,3.3 \n");

     scanf("%lf,%lf", pl1, pl2);
     while(getchar() != '\n' ){};

     return 0;
}

double CountTriangArea(double l1, double l2)
{
    return l1*l2*0.5;
}

double CountRectangleArea(double l1, double l2)
{
    return l1*l2;
}

double CountEllipseArea(double l1, double l2)
{
    return l1*l2*3.1415;
}

//函数指针(函数形参)
/*int sort*/
int ComperaInt(const void *p1, const void *p2)
{
    return *(int *)p1 - *(int *)p2;
}

int SortInt(void)
{
    int i = 0;
    int array[4] = {9, 2, 5, 6};

    qsort(array, 4, sizeof(int), ComperaInt);

    for(i=0; i<4; i++)
    {
         printf("%d\t", array[i]);
    }

    return 0;
}


/*double sort*/
int CompareDouble(const void *p1, const void *p2)
{
    double t = (*(double *)p1 - *(double *)p2);
            if(t > 0)   return 1;
    else    if(t == 0)  return 0;
    else    return -1;
}

int SortDouble(void)
{
    int i = 0;
    double array[4] = {9.9, 2.4, 5.4, 5.6};

//    qsort(array, 4, sizeof(double), CompareDouble);
    SimulateQsort(array, 4, sizeof(double), CompareDouble);
    for(i=0; i<4; i++)
    {
         printf("%lf\t", array[i]);
    }

    return 0;
}


/*Simulate Qsort*/

int SimulateQsort(void *p, int num, int size, int (*cmp)(const void *, const void *) )
{
    int i = 0;
    int j = 0;
    void *ptemp = malloc(size);

    if(p == NULL || num <= 0 || size <= 0 || cmp == NULL || ptemp == NULL)
    {
        return -1;
    }

    memset(ptemp, 0, size);

    for(i=0; i<num; i++)
    {
        for(j=0; j<num-i-1; j++)
        {
            if(cmp( (char *)p+j*size, (char *)p+(j+1)*size ) > 0 )
            {
                memcpy(ptemp, (char *)p+(j+1)*size, size);
                memcpy((char *)p+(j+1)*size, (char *)p+j*size, size);
                memcpy((char *)p+j*size, ptemp, size);
            }
        }
    }
    free(ptemp);
    ptemp = NULL;

    return 0;
}







//for test GitHub
