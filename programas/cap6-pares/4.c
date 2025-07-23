#include <stdio.h>

void Salario(double *salarioTotal, int *horas, double *salarioPorHora, double *salarioextra);
void horast(int *horas, double *salarioPorHora);
void horasex(int *horasExtra, int *horas, double *salarioextra, double *salarioPorHora);

int main(void) 
{
    int horas;
    double salarioPorHora, salarioTotal=0, salarioextra=0;
    horast(&horas,&salarioPorHora);
    Salario(&salarioTotal,&horas,&salarioPorHora,&salarioextra);
    printf("El salario total es: %.2f\n",salarioTotal); 
}   

void horast(int *horas, double *salarioPorHora) //funcion que lee las horas trabajadas y el salario por hora
{
    printf("Ingrese el número de horas trabajadas: ");
    scanf("%d",horas); // se pasa el valor a la direccion de memoria del puntero horas
    printf("Ingrese el salario por hora: ");
    scanf("%lf",salarioPorHora); // se pasa el valor a la direccion de memoria del puntero salarioporhora
}

void Salario(double *salarioTotal, int *horas, double *salarioPorHora, double *salarioextra) 
{
    int horasExt;
    int *horasExtra=&horasExt;
    horasex(horasExtra,horas,salarioextra,salarioPorHora);
   *salarioTotal=*horas*(*salarioPorHora)+*salarioextra;
}
void horasex(int *horasExtra, int *horas, double *salarioextra, double *salarioPorHora)
{
    if (*horas<=40)
    *horasExtra=0;
    else if(*horas>40)
    *horasExtra=*horas-40;
    *salarioextra=*horasExtra*(*salarioPorHora*1.5);
}
