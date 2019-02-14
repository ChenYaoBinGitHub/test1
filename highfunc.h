#ifndef __HIGHFUNC_H
#define __HIGHFUNC_H

typedef struct
{
    int type;
    double l1;
    double l2;
    double (*parea)(double, double);

}Myshape;


int fun1(int n);
int fun2(int n);

//函数指针(结构体demo)
int GetArea(void);
int GetShape();
int GetTwoLength(double *pl1, double *pl2);
double CountTriangArea(double l1, double l2);
double CountRectangleArea(double l1, double l2);
double CountEllipseArea(double l1, double l2);

//函数指针(函数形参demo)
int SortInt(void);
int SortDouble(void);

int SimulateQsort(void *p, int num, int size, int (*cmp)(const void *, const void *) );

#endif
