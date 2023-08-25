#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){

    printf("\n\n");
    printf("          P  /_\\  P                                \n");
    printf("         /_\\_|_|_/_\\                              \n");
    printf("     n_n | ||. .|| | n_n         Bem vindo ao       \n");
    printf("     |_|_|nnnn nnnn|_|_|     Jogo de Adivinhação!   \n");
    printf("    |     |  |_|  |     |                           \n");
    printf("    |_____| ' _ ' |_____|                           \n");
    printf("          \\__|_|__/                                \n");
    printf("\n\n");

    int segundos = time(0);
    srand(segundos);

    int numerogrande = rand();
    int numeroSecreto = numerogrande % 100;
    int chute;
    int tentativa = 1;
    int acertou = 0;
    double pontos = 1000;
    int tentativas = 5;

    int nivel;

    printf("Qual o nivel de dificuladade?\n");
    printf("(1) Facil (2) Medio (3) Dificil\n\n");
    printf("Escolha: ");
    scanf("%d", &nivel);

    switch(nivel){
        case 1: 
            tentativas = 20;
            break;
        case 2: 
            tentativas = 15;
            break;
        case 3: 
            tentativas = 6;
            break;
        default: 
            printf("Escolha uma das 3 dificuldades!!");
            break;
    }
    

    for(int i = 1; i <= tentativas; i++)
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
    
        acertou = chute == numeroSecreto;
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
    if(acertou){

        printf("\n\n");
        printf("                 OOOOOOOOOOO                    \n");
        printf("             OOOOOOOOOOOOOOOOOOO                \n");
        printf("          OOOOOO  OOOOOOOOO  OOOOOO             \n");
        printf("        OOOOOO      OOOOO      OOOOOO           \n");
        printf("      OOOOOOOO  #   OOOOO  #   OOOOOOOO         \n");
        printf("     OOOOOOOOOO    OOOOOOO    OOOOOOOOOO        \n");
        printf("    OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO       \n");
        printf("    OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO       \n");
        printf("    OOOO  OOOOOOOOOOOOOOOOOOOOOOOOO  OOOO       \n");
        printf("     OOOO  OOOOOOOOOOOOOOOOOOOOOOO  OOOO        \n");
        printf("      OOOO   OOOOOOOOOOOOOOOOOOOO  OOOO         \n");
        printf("       OOOOO   OOOOOOOOOOOOOOO   OOOO           \n");
        printf("         OOOOOO   OOOOOOOOO   OOOOOO            \n");
        printf("            OOOOOO         OOOOOO               \n");
        printf("                 OOOOOOOOOOOO                   \n");
        printf("\n\n");
        printf("Voce ganhou!\n");
        printf("Voce acertou com %d tentativas \n", tentativa);
        printf("Total de pontos: %.1f\n", pontos);
    } else {
        printf("\n\n");
        printf("       \\|/ ____ \\|/    \n");
        printf("        @~/ ,. \\~@      \n");
        printf("       /_( \\__/ )_\\    \n");
        printf("          \\__U_/        \n");
        printf("\n\n");
        printf("Voce perdeu! Tente de novo!\n");
    }

}