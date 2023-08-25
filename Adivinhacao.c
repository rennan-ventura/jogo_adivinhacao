#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    printf("******************************************\n");
    printf("* Bem vindo ao nosso jogo de adivinhacao *\n");
    printf("******************************************\n");

    int segundos = time(0);
    srand(segundos);
    int numerogrande = rand();
    int numeroSecreto = numerogrande % 100;
    int chute;
    int tentativa = 1;

    double pontos = 1000;
    

    while (1)
    {
        printf("Tentativa %d \n", tentativa);
        printf("Qual e o seu chute? ");
        scanf("%d", &chute);
        printf("Seu chute foi: %d \n", chute);

        if (chute < 0)
        {
            printf("Voce nao pode chutar numeros negativos!\n");
            continue;
        }
        

        int acertou = chute == numeroSecreto;
        int maior = chute > numeroSecreto;

        if(acertou){
            printf("Acertou!!\n");
            printf("Parabens voce e um bom jogador\n");
            break;

        } else if (maior){
            printf("Seu chute foi maior que o numero secreto!\n");
        } else {
            printf("Seu chute foi menor que o numero secreto!\n");
        }

        tentativa++;
        double pontosperdidos = abs(chute - numeroSecreto) / (double)2;
        pontos = pontos - pontosperdidos;
        
    }
    printf("Fim de jogo!!\n");
    printf("Voce acertou com %d tentativas \n", tentativa);
    printf("Total de pontos: %.1f\n", pontos);

}