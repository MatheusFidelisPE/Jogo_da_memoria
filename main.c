/*Autor: Matheus Fidelis da Silva*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <windows.h>
#include <time.h>
#include <string.h>
#include <conio.h>

int main(int argc, char const *argv[])
{
    srand(time(NULL));

    int tam_linhas = 4, tam_colunas = 4;
    //matrix principal, que guarda os valores de cada card.
    char pecas[tam_linhas][tam_colunas];
    //matrix auxiliar para revelação de apenas valores corretos
    char pecas_auxiliar[tam_linhas][tam_colunas];
    //Valores para compor nossos cards
    char valores_pecas[] = {'M','Y','Z','A','F','O','R','P','S'};
    //Variaveis guarda nome dos jogadores.
    char nome_jogador1[20], nome_jogador2[20];
    //Guarda letra de preenchimento provisorio da matriz principal e de forma não provisoria a matriz secundaria.
    char letra_preenchimento = 'B', letrinha_preenchimento = letra_preenchimento + 32;

    system("cls");
    //Pegando nome dos jogadores.
    for(int contador  = 0 ; contador < 1; contador++){
        printf("informe seu nome jogador 1: ");
        scanf("%s[^\n]", nome_jogador1);
        printf("informe seu nome jogador 2: ");
        scanf("%s[^\n]", nome_jogador2);
    }

    /*Carregando a matriz principal com letra de preenchimento e matriz secundararia*/
    for(int linha = 0; linha < tam_linhas; linha++){
        for(int coluna = 0; coluna < tam_colunas; coluna++){
            pecas[linha][coluna] = letra_preenchimento;
            pecas_auxiliar[linha][coluna] = letra_preenchimento;
        }
    }

    /*Sorteando e colocando na matriz principal o valor sorteado*/
    for(int contador = 0; contador < 8; contador++){
        int preenchido = 0, linha = 0, coluna = 0;
        do{
            linha = rand()%tam_linhas;
            coluna = rand()%tam_colunas;
            Sleep(21);
            if(pecas[linha][coluna] == letra_preenchimento){
                preenchido++;
                pecas[linha][coluna] = valores_pecas[contador];
            }

        }while(preenchido < 2);
    }

    system("cls");
    /*Impress�o do mapa por alguns segundos para que os jogadores memorizem as casas*/
    for(int linha = 0; linha < tam_linhas; linha++){
        printf("\t\t| ");
        for(int coluna = 0; coluna < tam_colunas; coluna++){
            printf("%c | ", pecas[linha][coluna]);
        }
        printf("\n");
    }
    sleep(5);

    //Crontolando o número de acertos e qual jogador está jogando naquele momento.
    int acerto = 0, identificador_de_jogador = 0;
    //Pegando localização das peças
    int linhad1  = 0, colunad1 = 0, linhad2 =0, colunad2 = 0;
    //Pontuação de cada jogador
    int jog1 = 0, jog2 = 0;
    //Guardando um valor booleano que compara o primeiro card com o segundo escolhido pelo jogador.
    int igualdade_auxiliar_com_principal = 0;
    //movimentação nos cards
    char movi;
    //Variavel responsavel por guardar a posicao atual e variavel responsavel por guardar quantos cards foram virados na jogada.
    int posicao_atual_linha = 0, posicao_atual_coluna = 0, escolha = 0;
    //Guardando a posição de cada escolha na jogada.
    int linha_escolhida1, coluna_escolhida1, linha_escolhida2, coluna_escolhida2;

    system("cls");

    /*Impressão das peças de forma que elas fiquem mais centralizadas e com | entre elas.*/
    for(int linha= 0; linha < tam_linhas; linha++)
            {
            printf("\t\t| ");
            for(int coluna = 0; coluna < tam_colunas; coluna++)
            {
                if(linha == 0 && coluna == 0){
                 printf("%c | ", letrinha_preenchimento);
                }else{
                 printf("%c | ", pecas_auxiliar[linha][coluna]);
                }
            }
            printf("\n");
            }
        pecas_auxiliar[0][0] = letrinha_preenchimento;
    do{

        do{
            //Pegando a tecla de movimentação
            movi = getch();

            //Determinando o que acontecerá de acordo com a letra escolhida.
            switch(movi){

                case 'w':
                    //controle da borda superior.
                    if(posicao_atual_linha == 0)
                    {
                        break;
                    }

                    if(pecas_auxiliar[posicao_atual_linha][posicao_atual_coluna] == letrinha_preenchimento && pecas_auxiliar[posicao_atual_linha-1][posicao_atual_coluna] != letra_preenchimento)
                    {
                        pecas_auxiliar[posicao_atual_linha][posicao_atual_coluna] = letra_preenchimento;
                        posicao_atual_linha--;
                        pecas_auxiliar[posicao_atual_linha][posicao_atual_coluna] = pecas_auxiliar[posicao_atual_linha][posicao_atual_coluna]  + 32;
                    }
                    else if(pecas_auxiliar[posicao_atual_linha][posicao_atual_coluna] != letrinha_preenchimento && pecas_auxiliar[posicao_atual_linha-1][posicao_atual_coluna] == letra_preenchimento)
                    {
                        pecas_auxiliar[posicao_atual_linha][posicao_atual_coluna] = pecas_auxiliar[posicao_atual_linha][posicao_atual_coluna]  - 32;
                        posicao_atual_linha--;
                        pecas_auxiliar[posicao_atual_linha][posicao_atual_coluna] = letrinha_preenchimento;
                    }
                    else if(pecas_auxiliar[posicao_atual_linha][posicao_atual_coluna] != letrinha_preenchimento && pecas_auxiliar[posicao_atual_linha-1][posicao_atual_coluna] != letra_preenchimento)
                    {
                        pecas_auxiliar[posicao_atual_linha][posicao_atual_coluna] = pecas_auxiliar[posicao_atual_linha][posicao_atual_coluna]  - 32;
                        posicao_atual_linha--;
                        pecas_auxiliar[posicao_atual_linha][posicao_atual_coluna] = pecas_auxiliar[posicao_atual_linha][posicao_atual_coluna] + 32;
                    }
                    else
                    {
                        pecas_auxiliar[posicao_atual_linha][posicao_atual_coluna] = letra_preenchimento;
                        posicao_atual_linha--;
                        pecas_auxiliar[posicao_atual_linha][posicao_atual_coluna] = letrinha_preenchimento;
                    }
                    break;

                case 's':
                    //Controle de borda inferior.
                    if(posicao_atual_linha == 3)
                    {
                        break;
                    }

                    if(pecas_auxiliar[posicao_atual_linha][posicao_atual_coluna] == letrinha_preenchimento && pecas_auxiliar[posicao_atual_linha+1][posicao_atual_coluna] != letra_preenchimento)
                    {
                        pecas_auxiliar[posicao_atual_linha][posicao_atual_coluna] = letra_preenchimento;
                        posicao_atual_linha++;
                        pecas_auxiliar[posicao_atual_linha][posicao_atual_coluna] = pecas_auxiliar[posicao_atual_linha][posicao_atual_coluna]  + 32;
                    }
                    else if(pecas_auxiliar[posicao_atual_linha][posicao_atual_coluna] != letrinha_preenchimento && pecas_auxiliar[posicao_atual_linha+1][posicao_atual_coluna] == letra_preenchimento)
                    {
                        pecas_auxiliar[posicao_atual_linha][posicao_atual_coluna] = pecas_auxiliar[posicao_atual_linha][posicao_atual_coluna]  - 32;
                        posicao_atual_linha++;
                        pecas_auxiliar[posicao_atual_linha][posicao_atual_coluna] = letrinha_preenchimento;
                    }
                    else if(pecas_auxiliar[posicao_atual_linha][posicao_atual_coluna] != letrinha_preenchimento && pecas_auxiliar[posicao_atual_linha+1][posicao_atual_coluna] != letra_preenchimento)
                    {
                       pecas_auxiliar[posicao_atual_linha][posicao_atual_coluna] = pecas_auxiliar[posicao_atual_linha][posicao_atual_coluna]  - 32;
                       posicao_atual_linha++;
                       pecas_auxiliar[posicao_atual_linha][posicao_atual_coluna] = pecas_auxiliar[posicao_atual_linha][posicao_atual_coluna] + 32;
                    }
                    else
                    {
                        pecas_auxiliar[posicao_atual_linha][posicao_atual_coluna] = letra_preenchimento;
                        posicao_atual_linha++;
                        pecas_auxiliar[posicao_atual_linha][posicao_atual_coluna] = letrinha_preenchimento;
                    }
                    break;

                case 'a':
                    //Controle de borda esquerdo.
                    if(posicao_atual_coluna == 0)
                    {
                        break;
                    }

                    if(pecas_auxiliar[posicao_atual_linha][posicao_atual_coluna] == letrinha_preenchimento && pecas_auxiliar[posicao_atual_linha][posicao_atual_coluna-1] != letra_preenchimento)
                    {
                        pecas_auxiliar[posicao_atual_linha][posicao_atual_coluna] = letra_preenchimento;
                        posicao_atual_coluna--;
                        pecas_auxiliar[posicao_atual_linha][posicao_atual_coluna] = pecas_auxiliar[posicao_atual_linha][posicao_atual_coluna]  + 32;
                    }
                    else if(pecas_auxiliar[posicao_atual_linha][posicao_atual_coluna] != letrinha_preenchimento && pecas_auxiliar[posicao_atual_linha][posicao_atual_coluna-1] == letra_preenchimento)
                    {
                        pecas_auxiliar[posicao_atual_linha][posicao_atual_coluna] = pecas_auxiliar[posicao_atual_linha][posicao_atual_coluna]  - 32;
                        posicao_atual_coluna--;
                        pecas_auxiliar[posicao_atual_linha][posicao_atual_coluna] = letrinha_preenchimento;
                    }
                    else if(pecas_auxiliar[posicao_atual_linha][posicao_atual_coluna] != letrinha_preenchimento && pecas_auxiliar[posicao_atual_linha][posicao_atual_coluna-1] != letra_preenchimento)
                    {
                       pecas_auxiliar[posicao_atual_linha][posicao_atual_coluna] = pecas_auxiliar[posicao_atual_linha][posicao_atual_coluna]  - 32;
                       posicao_atual_coluna--;
                       pecas_auxiliar[posicao_atual_linha][posicao_atual_coluna] = pecas_auxiliar[posicao_atual_linha][posicao_atual_coluna] + 32;
                    }
                    else
                    {
                        pecas_auxiliar[posicao_atual_linha][posicao_atual_coluna] = letra_preenchimento;
                        posicao_atual_coluna--;
                        pecas_auxiliar[posicao_atual_linha][posicao_atual_coluna] = letrinha_preenchimento;
                    }
                    break;

                case 'd':
                    //Controle de borda direito.
                    if(posicao_atual_coluna == 3)
                    {
                        break;
                    }

                    if(pecas_auxiliar[posicao_atual_linha][posicao_atual_coluna] == letrinha_preenchimento && pecas_auxiliar[posicao_atual_linha][posicao_atual_coluna+1] != letra_preenchimento)
                    {
                     pecas_auxiliar[posicao_atual_linha][posicao_atual_coluna] = letra_preenchimento;
                        posicao_atual_coluna++;
                        pecas_auxiliar[posicao_atual_linha][posicao_atual_coluna] = pecas_auxiliar[posicao_atual_linha][posicao_atual_coluna]  + 32;
                    }
                    else if(pecas_auxiliar[posicao_atual_linha][posicao_atual_coluna] != letrinha_preenchimento && pecas_auxiliar[posicao_atual_linha][posicao_atual_coluna+1] == letra_preenchimento)
                    {
                        pecas_auxiliar[posicao_atual_linha][posicao_atual_coluna] = pecas_auxiliar[posicao_atual_linha][posicao_atual_coluna]  - 32;
                        posicao_atual_coluna++;
                        pecas_auxiliar[posicao_atual_linha][posicao_atual_coluna] = letrinha_preenchimento;
                    }
                    else if(pecas_auxiliar[posicao_atual_linha][posicao_atual_coluna] != letrinha_preenchimento && pecas_auxiliar[posicao_atual_linha][posicao_atual_coluna+1] != letra_preenchimento)
                    {
                       pecas_auxiliar[posicao_atual_linha][posicao_atual_coluna] = pecas_auxiliar[posicao_atual_linha][posicao_atual_coluna]  - 32;
                       posicao_atual_coluna++;
                       pecas_auxiliar[posicao_atual_linha][posicao_atual_coluna] = pecas_auxiliar[posicao_atual_linha][posicao_atual_coluna] + 32;
                    }
                    else
                    {
                        pecas_auxiliar[posicao_atual_linha][posicao_atual_coluna] = letra_preenchimento;
                        posicao_atual_coluna++;
                        pecas_auxiliar[posicao_atual_linha][posicao_atual_coluna] = letrinha_preenchimento;
                    }
                    break;

                case '0':
                    //Controle de impressão.
                    if(escolha == 0)
                    {
                        linha_escolhida1 = posicao_atual_linha;
                        coluna_escolhida1 = posicao_atual_coluna;
                        escolha++;
                    }
                    else
                    {
                        linha_escolhida2 = posicao_atual_linha;
                        coluna_escolhida2 = posicao_atual_coluna;
                        escolha++;
                    }
                    break;

                default:
                    printf("\nTecla digitada nao pertence ao controle.\n");
                    sleep(2);
                    break;
                }
            system("cls");
            for(int linha= 0; linha < tam_linhas; linha++)
            {
                printf("\t\t| ");
                for(int coluna = 0; coluna < tam_colunas; coluna++)
                {
                    if(escolha == 1 && linha == linha_escolhida1 && coluna == coluna_escolhida1)
                    {
                        printf("%c | ", pecas[linha][coluna]);
                    }
                    else if(escolha == 2 && ((linha == linha_escolhida1 && coluna == coluna_escolhida1) || (linha == linha_escolhida2 && coluna_escolhida2 == coluna)))
                    {
                        printf("%c | ", pecas[linha][coluna]);
                    }
                    else
                    {
                    printf("%c | ", pecas_auxiliar[linha][coluna]);
                    }
                }
                printf("\n");
            }
        }while(escolha < 2);

        igualdade_auxiliar_com_principal = 0;

        //system("cls");
        igualdade_auxiliar_com_principal = pecas[linha_escolhida1][coluna_escolhida1] == pecas[linha_escolhida2][coluna_escolhida2];

        //Controle de jogada e jogador. Caso as opções escolhidas tenham sido iguais e selecionando o jogador.
        if((linha_escolhida1 == linha_escolhida2 && coluna_escolhida1 == coluna_escolhida2) || pecas_auxiliar[linha_escolhida1][coluna_escolhida1] != letra_preenchimento || pecas_auxiliar[linha_escolhida2][coluna_escolhida2] != letrinha_preenchimento){
            printf("\nOpcao invalida!!\n");
            Sleep(800);

        }
        else if((identificador_de_jogador%2) == 0 && igualdade_auxiliar_com_principal)
        {
                jog1 += 1;
                acerto += 1 ;
                printf("\nParabens, %s. Voce tem %d acertos.\n", nome_jogador1, jog1);
                Sleep(800);
                pecas_auxiliar[linha_escolhida1][coluna_escolhida1] = pecas[linha_escolhida1][coluna_escolhida1];
                pecas_auxiliar[linha_escolhida2][coluna_escolhida2] = pecas[linha_escolhida2][coluna_escolhida2]+32;

        }
        else if((identificador_de_jogador%2) == 1 && igualdade_auxiliar_com_principal)
        {
            jog2++;
            acerto++;

            printf("\nParabens, %s. Voce tem %d acertos.\n", nome_jogador2, jog2);
            Sleep(800);

            pecas_auxiliar[linha_escolhida1][coluna_escolhida1] = pecas[linha_escolhida1][coluna_escolhida1];
            pecas_auxiliar[linha_escolhida2][coluna_escolhida2] = pecas[linha_escolhida2][coluna_escolhida2]+32;
        }
        else
        {
            printf("\nVoce errou!\n");
            Sleep(800);
        }

        identificador_de_jogador++;
        escolha = 0;
    }while(acerto < 8 && jog1 <= 4 && jog2 <= 4);

    system("cls");
    /*Resultado*/
    if(jog1>jog2)
    {
        printf("\nParabens, %s! Voce ganhou esta partida.\nCOM UM TOTAL DE %d ACERTOS.\n", nome_jogador1, jog1);
        system("pause");
    }
    else if(jog2>jog1)
    {
        printf("\nParabens, %s! Voce ganhou esta partida.\nCOM UM TOTAL DE %d ACERTOS.\n", nome_jogador2, jog2);
        system("pause");
    }
    else
    {
        printf("\nDesta vez terminamos em empate.\n");
        system("pause");
    }
    return 0;
}
