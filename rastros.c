#include <stdio.h>
#include "camada_dados.h"
#include "interface.h"




int main() {
    printf("PRONTOS PARA COMECAR O JOGO?\n");
    ESTADO *e = inicializar_estado();
    desenha_tabuleiro(e);
    printf("Digite um comando->");
    interpretador(e);
    lista_movimentos(e); //listas os movimentos,mas ainda não é tudo o que se pretende

    printf("JOGO TERMINADO\n");
}
