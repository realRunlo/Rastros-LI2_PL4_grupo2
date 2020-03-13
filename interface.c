//
// Created by runlo on 09/03/20.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define BUF_SIZE 1024
#include "camada_dados.h"
#include "logica.h"

// Funcao que desenha o tabuleiro
void desenha_tabuleiro(ESTADO *e){
    printf ("   A B C D E F G H\n");
    printf ("   _ _ _ _ _ _ _ _\n");
    for(int l = 7; l >= 0; l--){
        printf("%d| ", l+1 );  //depois por (l+1)
        for(int c = 0; c < 8; c++) {
            if (e->tab[l][c] == BRANCA) printf("* ");
            else if (c == 0 && l == 0) printf("1 ");
            else if (c == 7 && l == 7) printf("2 ");
            else if (e->tab[l][c] == PRETA) printf("# ");
            else printf(". ");
        }
        printf("\n");
    }
}



// ////////////////////////////////////////////////////////////////////////////


// Função que deve ser completada e colocada na camada de interface
int interpretador(ESTADO *e) {

    char linha[BUF_SIZE];
    char col[2], lin[2];
    while (jogada_possivel(e) == 1) {
        if (fgets(linha, BUF_SIZE, stdin) == NULL)
            return 0;
        if (strlen(linha) == 3 && sscanf(linha, "%[a-h]%[1-8]", col, lin) == 2) {
            COORDENADA coord = {*col - 'a', *lin - '1'};
            while (jogada_valida(e, coord) == 0) {
                printf("Faça uma jogada válida pf\n");       //enquanto a jogada não for válida pede por uma jogada válida
                interpretador(e);
            }
            jogar(e, coord);


            desenha_tabuleiro(e);
        }
    }
    return 1;

}
// ////////////////////////////////////////////////////////////////////////////





