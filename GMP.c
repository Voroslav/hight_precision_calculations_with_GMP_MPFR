#include <stdio.h>
//#include <math.h>
#include <gmp.h>//gcc ... -lgmp

int main()
  {int n = 59;
//  unsigned long long first = 0, second = 1, next;
//  |
//  v
  mpz_t first, second, next;
  mpz_init_set_str(first, "0", 10);
  mpz_init_set_str(second, "1", 10);
  mpz_init(next);
  printf("First %d Fibonachi numbers:\n", n);
  for (int i = 2; i <=n; i++)
  {
//  next = first + second;
//  first = second;
//  second = next;
//  |
//  v
  mpz_add (next, first, second); 
  mpz_set (first, second);
  mpz_set (second, next);
  }
//  printf("\n № %d=%lld, № %d=%lld \n",n-1,first,n, second);
//  |
//  v
gmp_printf("\n № %d=%Zd, № %d=%Zd \n",n-1,first,n, second);
//  long double y=(long double)second;
//  long double x=(long double)first;
//  |
//  v
  mpz_t x,y,f,temp1,temp2;
  mpz_init(x);
  mpz_init(y);
  mpz_init(f);
  mpz_init(temp1);
  mpz_init(temp2);
  mpz_set (x, first);
  mpz_set (y, second);
//  long double f=1/(pow(y,6)-3*x*pow(y,5)+5*pow(x,3)*pow(y,3)-3*pow(x,5)*y-pow(x,6)) - 1;
//  |
//  v                                   //temp1 temp2 f
  mpz_pow_ui(temp1,y,6);                //y^6    0   0
  mpz_set (f, temp1);                   //y^6    0   y^6

  mpz_init_set_str(temp1, "-3", 10);    //-3     0   y^6
  mpz_set (temp2, x);                   //-3     x   y^6
  mpz_mul (temp1, temp2, temp1);        //-3*x   x   y^6
  mpz_pow_ui(temp2,y,5);                //-3*x   y^5 y^6
  mpz_mul (temp1, temp2, temp1);        //-3*x*y^5      y^5     y^6
  mpz_add (f, f, temp1);                //-3*x*y^5      y^5     y^6-3*x*y^5 

  mpz_pow_ui(temp1,y,3);                //y^3    y^5   y^6-3*x*y^5 
  mpz_pow_ui(temp2,x,3);                //y^3    x^3   y^6-3*x*y^5 
  mpz_mul (temp1, temp2, temp1);        //y^3*y^5      y^3     y^6-3*x*y^5
  mpz_init_set_str(temp2, "5", 10);     //y^3*y^5     5   y^6-3*x*y^5
  mpz_mul (temp1, temp2, temp1);        //y^3*y^5*5      5     y^6-3*x*y^5
  mpz_add (f, f, temp1);                //y^3*y^5*5      5     y^6-3*x*y^5+5*x^3*y^3 
  
  mpz_pow_ui(temp2,x,5);                //y^3*y^5*5      x^5     y^6-3*x*y^5+5*x^3*y^3 
  mpz_mul (temp2, temp2, y);            //y^3*y^5*5      x^5*y     y^6-3*x*y^5+5*x^3*y^3 
  mpz_init_set_str(temp1, "-3", 10);    //-3      x^5*y     y^6-3*x*y^5+5*x^3*y^3 
  mpz_mul (temp2, temp2, temp1);        //-3      -3*x^5*y     y^6-3*x*y^5+5*x^3*y^3 
  mpz_add (f, f, temp2);                //-3      -3*x^5*y     y^6-3*x*y^5+5*x^3*y^3-3*x^5*y

  mpz_init_set_str(temp1, "-1", 10);    //-1      -3*x^5*y     y^6-3*x*y^5+5*x^3*y^3-3*x^5*y
  mpz_pow_ui(temp2,x,6);                //-1      x^6      y^6-3*x*y^5+5*x^3*y^3-3*x^5*y
  mpz_mul (temp2, temp2, temp1);        //-1      -1*x^6     y^6-3*x*y^5+5*x^3*y^3-3*x^5*y 
  mpz_add (f, f, temp2);                //-1      -1*x^6     y^6-3*x*y^5+5*x^3*y^3-3*x^5*y-x^6 //gmp_printf("\n%Zd\n",f); 
  
  mpz_init_set_str(temp1, "1", 10);     //1      -1*x^6     y^6-3*x*y^5+5*x^3*y^3-3*x^5*y-x^6
  mpz_cdiv_q (f, temp1, f);             //1      -1*x^6     1/(y^6-3*x*y^5+5*x^3*y^3-3*x^5*y-x^6)
  mpz_init_set_str(temp1, "-1", 10);    //-1     -1*x^6     1/(y^6-3*x*y^5+5*x^3*y^3-3*x^5*y-x^6)
  mpz_add (f, f, temp1);                //-1     -1*x^6     1/(y^6-3*x*y^5+5*x^3*y^3-3*x^5*y-x^6)-1 
//  printf("s=%1.15Lf",f);
//  |
//  v
gmp_printf("\nf = %Zd\n",f); 
return 0;}
