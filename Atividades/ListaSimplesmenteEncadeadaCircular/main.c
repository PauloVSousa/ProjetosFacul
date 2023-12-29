#include "listacircular.h"
#include <stdio.h>
#include <string.h>

int main(void) {
  plista l = lista_cria();
  tipoD valor;
  int posicao = 0;
  char espaco;
  char *comando = alocar_comando();
  do {
    scanf(" %s", comando);
    if (strcmp(comando, "-s") == 0) {
      lista_exibir(l);
    }
    if (strcmp(comando, "-c") == 0) {
      lista_esvaziar(l);
    }
    if (strcmp(comando, "-a") == 0) {
      scanf("%f", &valor);
      espaco = getc(stdin);
      if (espaco == 32) {
        scanf("%d", &posicao);
        inserir_posicao(l, valor, posicao);
      } else {
        inserir_elem(l, valor);
      }
    }
    if (strcmp(comando, "-r") == 0) {
      scanf("%f", &valor);
      remover_valor(l, valor);
    }
    if (strcmp(comando, "-m") == 0) {
      maior_elem(l);
    }
    if (strcmp(comando, "-sl") == 0) {
      ultimo_elem(l);
    }
    if (strcmp(comando, "-sf") == 0) {
      primeiro_elem(l);
    }
    if (strcmp(comando, "-ss") == 0) {
      lista_tamanho(l);
    }
    if (strcmp(comando, "-sg") == 0) {
      scanf("%f", &valor);
      maior_valor(l, valor);
    }
  } while (strcmp(comando, "-s") != 0);

  desalocar(l, comando);
  return 0;
}