#include <iostream>
#include <stdio.h>
#include <mpreal.h> //-lmpfr
using namespace std;
using namespace mpfr;
int main (int argc, char **argv)
{
mpreal::set_default_prec(10000);//set value for 1 variable 10000 bits 
int n = 59;
//  unsigned long long first = 0, second = 1, next;
//  |
//  v
  mpreal first = 0, second = 1, next;
//  printf("First %d Fibonachi numbers:\n", n);
//  |
//  v
  cout<<"First "<< n <<" Fibonachi numbers\n";
  for (int i = 2; i <=n; i++)
  {
  next = first + second;
  first = second;
  second = next; }
//  printf("\n № %d=%lld, № %d=%lld \n",n-1,first,n, second);
//  |
//  v
  cout<<"№ "<< n-1 <<" = "<< first <<" № "<< n <<" = "<< second<<"\n";
//  long double y=(long double)second;
//  long double x=(long double)first;
//  |
//  v
  mpreal y=second;
  mpreal x=first;
  mpreal f=1/(pow(y,6)-3*x*pow(y,5)+5*pow(x,3)*pow(y,3)-3*pow(x,5)*y-pow(x,6)) - 1;

//  printf("s=%1.15Lf",f);
//  |
//  v
cout<<"f = "<<f<<"\n";
return 0;
}
