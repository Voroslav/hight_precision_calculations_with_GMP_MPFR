#include <stdio.h>
#include <math.h>
int main()
  {int n = 59;
  unsigned long long first = 0, second = 1, next;
  printf("Первые %d чисел Фибоначчи:\n", n);
  for (int i = 2; i <=n; i++)
  {
  next = first + second;
  first = second;
  second = next; }
  printf("\n № %d=%lld, № %d=%lld \n",n-1,first,n, second);

  long double y=(long double)second;
  long double x=(long double)first;
  long double f=1/(pow(y,6)-3*x*pow(y,5)+5*pow(x,3)*pow(y,3)-3*pow(x,5)*y-pow(x,6)) - 1;
  printf("s=%1.15Lf",f);
return 0;}
