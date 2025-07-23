#include "stdio.h"
#include "stdbool.h"
int main()
{
int num1=0, resultado=0;
bool esprimo=false;
scanf("%d", &num1);
for(int i=2;i*i<=num1;i++)
{
    if(num1%i==0)
    {
    esprimo=false;
    break;
    }
}
if(esprimo==false)
printf("\nno primo");
else printf("\nprimo");
return 0;
}