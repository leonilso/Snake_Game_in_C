#include <stdio.h>
#include <stdlib.h>
#include <conio.h>



int linhas = 39;
int colunas = 50;
int grade[39][50] = {{0}};
int direcao[2] = {0, 1};
int posicao[2] = {15, 4};
int maca[2] = {25, 20};
int coletado = 0;
int time = 1;

char tecla;
// void decrementarPosicoes();
// void incrementarPosicoes();

void decrementarPosicoes(){
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            if (grade[i][j] > 0) {
                grade[i][j] = grade[i][j] - 1;
            }
        }
    }
}

void incrementarPosicoes(){
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            if (grade[i][j] > 0) {
                grade[i][j] = grade[i][j] + 1;
            }
        }
    }
}


int main(void)
{
    grade[posicao[0]][posicao[1]] = time;
    while (1)
    {
        decrementarPosicoes();
        if(coletado){
            int valido = 0;
            while(!valido){
                maca[0] = rand() % linhas;
                maca[1] = rand() % colunas;
                coletado = 0;
                if(grade[maca[0]][maca[1]] == 0){
                    valido = 1;
                }
            }

        }
        grade[maca[0]][maca[1]] = -1;
        printf("\e[?25l");
        if(kbhit()){
            tecla = getch();
            switch (tecla)
            {
            case 119:
                direcao[0] = -1;
                direcao[1] = 0;
                break;
            case 100:
                direcao[0] = 0;
                direcao[1] = 1;
                break;
            case 115:
                direcao[0] = 1;
                direcao[1] = 0;
                
                break;
            case 97:
                direcao[0] = 0;
                direcao[1] = -1;
                break;
            default:
                break;
            }
        }

        posicao[0] = posicao[0] + direcao[0];
        posicao[1] = posicao[1] + direcao[1];

        grade[posicao[0]][posicao[1]] = time;

        if(posicao[0] == maca[0] && posicao[1] == maca[1]){
            time = time + 1;
            incrementarPosicoes();
            coletado = 1;
        }

        for (int i = 0; i < linhas; i++) {
            for (int j = 0; j < colunas; j++) {
                if (grade[i][j] == 0) {
                    printf("   ");
                } else {
                    if (grade[i][j] > 0){
                        printf(" 0 ");

                    } else {
                        if (grade[i][j] < 0){
                            printf(" * ");
                        }
                    }
                }
            }
            printf("\n");
        }
        system("cls");
    }
    return 0;
}