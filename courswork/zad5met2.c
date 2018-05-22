#include <stdio.h>
#include <math.h>
float fx(float, float, float);
float dfx(float, float, float);
double NewtonMethod(float, float, float, float);

main()
{
float a, b, x0, eps;
printf("function: x^4 + ax^3 - bx\n");
printf("Введите a:");
scanf("%f", &a);
printf("Введите b:");
scanf("%f", &b);
printf("Введите x0:");
scanf("%f", &x0);
printf("Введие точность:");
scanf("%f", &eps);
printf("%lf\n",NewtonMethod(x0, a, b, eps)); // вывод на экран
return 0;
}

float fx(float x, float a, float b)
{
return pow(x, 4) + a*pow(x, 3) - b*x;
}

float dfx(float x, float a, float b)
{
return 4*pow(x, 3) + 3*a*pow(x, 2) - b;
}

double NewtonMethod(float x0, float a, float b, float eps) {
int i=0;
float x1 = x0 - fx(x0, a, b)/dfx(x0,a, b); // первое приблжение
while (fabs(x1-x0)>eps) { // пока не достигнута точность 0.000001
x0 = x1;
x1 = x1 - fx(x1, a ,b)/dfx(x1,a, b); // последующие приближения
i++;
}
printf("Кол-во итераций: %d\n", i);
return x1;
}
