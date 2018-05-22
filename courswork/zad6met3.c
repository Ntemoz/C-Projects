#include <stdio.h>
#include <math.h>

double f(double, double, double);

main()
{
   double x0, x1, x2, past_x2, E, a, b;
   int n=0;
   printf("Function: x^5 + a*x^2 - b\n");
   printf("Введите значения a и b\n");
   scanf("%lf %lf", &a, &b);
   printf ("Введите значения x1 x2\n");
   scanf("%lf %lf", &x0, &x1);
   printf("Введите точность: ");
   scanf("%lf", &E);
   do{
      n++;
      past_x2=x2;
      x2=x1-((x1-x0)/(f(x1, a, b)-f(x0, a, b)))*f(x1, a, b);
      x0=x1;
      x1=x2;
   }
   while (fabs(past_x2-x2)>=E);
   printf ("Корень: %lf\n", x2);
   printf("Потребовалось %d итераций", n);
 }

double f(double x, double a, double b)
{
    return pow(x, 5) + a*pow(x, 2) - b;
}
