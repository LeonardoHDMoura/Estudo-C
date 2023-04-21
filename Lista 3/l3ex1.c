#include <stdio.h>
#include <math.h>

int menu();
float soma(float a, float b);
float subtracao(float a, float b);
float multiplicacao(float a, float b);
float divisao(float a, float b);
float raiz_n(float x, float n);
float potencia_n(float exp, float pot);
float seno(float ang_graus);
float cosseno(float ang_graus);

int main (int argc, char *argv[])
{
    int op=0;
    float a, b, r;
    while(op != -1){
        op = menu();
        switch(op){
            case 1:
                printf("Soma\n");
                printf("Digite dois valores para serem somados(a + b): ");
                scanf("%f+%f",&a,&b);
                r = soma(a,b);
                printf("%.2f + %.2f = %.2f\n",a,b, r);
                break;
            case 2:
                printf("Subtracao\n");
                printf("Digite dois valores para serem subtraidos(a - b): ");
                scanf("%f-%f",&a,&b);
                r = subtracao(a,b);
                printf("%.2f - %.2f = %.2f\n",a,b, r);
                break;
            case 3:
                printf("Multiplicacao\n");
                printf("Digite dois valores para serem multiplicados(a * b): ");
                scanf("%f*%f",&a,&b);
                r = multiplicacao(a,b);
                printf("%.2f * %.2f = %.2f\n",a,b, r);
                break;
            case 4:
                printf("Divisao\n");
                printf("Digite dois valores para serem divididos(a / b): ");
                scanf("%f/%f",&a,&b);
                r = divisao(a,b);
                printf("%.2f / %.2f = %.2f\n",a,b, r);
                break;
            case 5:
                printf("Raiz enesima\n");
                printf("Digite dois valores(x r n): ");
                scanf("%fr%f",&a,&b);
                r = raiz_n(a,b);
                printf("%.2f r %.2f = %.2f\n",a,b, r);
                break;
            case 6:
                printf("X elevado a N\n");
                printf("Digite dois valores(x ^ n): ");
                scanf("%f^%f",&a,&b);
                r = potencia_n(a,b);
                printf("%.2f ^ %.2f = %.2f\n",a,b, r);
                break;
            case 7:
                printf("Seno\n");
                printf("Digite o angulo em graus: ");
                scanf("%f",&a);
                r = seno(a);
                printf("seno(%.2f) = %.2f\n",a, r);
                break;
            case 8:
                printf("Cosseno\n");
                printf("Digite o angulo em graus: ");
                scanf("%f",&a);
                r = cosseno(a);
                printf("cosseno(%.2f) = %.2f\n",a, r);
                break;
            case -1:
                printf("Saindo...\n");
                break;
            default:
                printf("Digite uma opção válida!\n");
                break;

        }
    }
    return 0;
}

int menu(){
    int op=0;
    printf("**Calculadora V1.0 **\n\n");
    printf("Para utilizar a calculadora, digite uma das opcoes abaixo.\n");
    printf("1 - Soma\n2 - Subtracao\n3 - Multiplicacao\n");
    printf("4 - Divisao\n5 - Raiz enesima\n6 - X elevado a N\n7 - Seno (graus)\n8 - Cosseno (graus)\n");
    printf("-1 - Sair\n");
    printf("Digite uma opcao: ");
    scanf("%i",&op);
    return op;
}

float soma(float a, float b){
    return a+b;
}
float subtracao(float a, float b){
    return a-b;
}
float multiplicacao(float a, float b){
    return a*b;
}
float divisao(float a, float b){
    if(b == 0) return INFINITY;
    return a/b;
}
float raiz_n(float x, float n){
    return pow(x,1/n);
}
float potencia_n(float exp, float pot){
    return pow(exp,pot);
}
float seno(float ang_graus){
    return sin(ang_graus * M_PI / 180);
}
float cosseno(float ang_graus){
    return cos(ang_graus * M_PI / 180);
}