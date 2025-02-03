#include <stdio.h>

int calcularMdc(int, int);
int calcularMmc(int, int);
void multiplicar(int, int, int, int, int *, int *);
void somar(int, int, int, int, int *, int *);
void subtrair(int, int, int, int, int *, int *);
void dividir(int, int, int, int, int *, int *);

void main()
{
    char operacao;
    int numerador1, denominador1, numerador2, denominador2;
    unsigned casos;
    int resultadoNumerador, resultadoDenominador, temp;

    scanf("%u", &casos);

    while (casos--)
    {
        scanf("%d / %d %c %d / %d", &numerador1, &denominador1, &operacao, &numerador2, &denominador2);

        if (operacao == '+')
            somar(numerador1, denominador1, numerador2, denominador2, &resultadoNumerador, &resultadoDenominador);
        else if (operacao == '-')
            subtrair(numerador1, denominador1, numerador2, denominador2, &resultadoNumerador, &resultadoDenominador);
        else if (operacao == '*')
            multiplicar(numerador1, denominador1, numerador2, denominador2, &resultadoNumerador, &resultadoDenominador);
        else if (operacao == '/')
            dividir(numerador1, denominador1, numerador2, denominador2, &resultadoNumerador, &resultadoDenominador);

        temp = calcularMdc(resultadoNumerador, resultadoDenominador);

        if (temp < 0)
            printf("%d/%d = %d/%d\n", resultadoNumerador, resultadoDenominador, -(resultadoNumerador / temp), -(resultadoDenominador / temp));
        else
            printf("%d/%d = %d/%d\n", resultadoNumerador, resultadoDenominador, resultadoNumerador / temp, resultadoDenominador / temp);
    }
}

void somar(int numerador1, int denominador1, int numerador2, int denominador2, int *resultadoNumerador, int *resultadoDenominador)
{
    *resultadoNumerador = numerador1 * denominador2 + numerador2 * denominador1;
    *resultadoDenominador = denominador1 * denominador2;
}

void subtrair(int numerador1, int denominador1, int numerador2, int denominador2, int *resultadoNumerador, int *resultadoDenominador)
{
    *resultadoNumerador = numerador1 * denominador2 - numerador2 * denominador1;
    *resultadoDenominador = denominador1 * denominador2;
}

void multiplicar(int numerador1, int denominador1, int numerador2, int denominador2, int *resultadoNumerador, int *resultadoDenominador)
{
    *resultadoNumerador = numerador1 * numerador2;
    *resultadoDenominador = denominador1 * denominador2;
}

void dividir(int numerador1, int denominador1, int numerador2, int denominador2, int *resultadoNumerador, int *resultadoDenominador)
{
    *resultadoNumerador = (numerador1 * denominador2);
    *resultadoDenominador = (numerador2 * denominador1);
}

int calcularMdc(int a, int b)
{
    int resto = a % b;
    while (resto != 0)
    {
        a = b;
        b = resto;
        resto = a % b;
    }
    return b;
}

int calcularMmc(int a, int b)
{
    return (a / calcularMdc(a, b)) * b;
}
