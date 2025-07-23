#include <stdio.h>
double Salario(double salarioTotal, int horasTrabajadas, double salarioPorHora);
int main(void)
{
    int horas;
    double salarioPorHora, salarioTotal;
    printf("Ingrese el numero de horas trabajadas: ");
    scanf("%d",&horas);
    printf("Ingrese el salario por hora: ");
    scanf("%lf",&salarioPorHora);

    salarioTotal=Salario(salarioTotal,horas,salarioPorHora);
    printf("El salario total es: %.2f\n",salarioTotal);
}
double Salario(double salarioTotal, int horasTrabajadas, double salarioPorHora)
{
    int horasExtras;    
    if (horasTrabajadas<=40) // se verifica si las horas son menores o iguales a cuarenta
    {
        salarioTotal=salarioPorHora*horasTrabajadas; //si se cumple la condicion se asigna el salario normal al puntero salario total
    }
    else // de lo contrario se realiza el calculo de las horas extras y el pago con un multiplicador de 1.5 a las horas extras.
    {
        horasExtras=horasTrabajadas-40;
     salarioTotal=(40*(salarioPorHora))+(horasExtras*(salarioPorHora*1.5));
    }
    return salarioTotal;
}

