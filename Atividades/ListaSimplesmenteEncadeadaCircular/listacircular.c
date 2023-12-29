#include "listacircular.h"
#include <stdio.h>
#include <stdlib.h>

struct descritor {
  tipoD dado;
  pdesc prox;
};
struct Lista {
  pdesc cabeca;
  pdesc calda;
  int quant_elem;
};

plista lista_cria() {
  plista f = (plista)malloc(sizeof(tlista));
  if (f != NULL) {
    f->cabeca = NULL;
    f->calda = NULL;
    f->quant_elem = 0;
  }
  return f;
}

void lista_exibir(plista l) {
  pdesc aux = l->calda;
  int n = l->quant_elem;
  if (n == 0) {
    printf("Lista vazia\n");
  } else {
    while (aux != l->cabeca) {
      printf("%.1f ", aux->dado);
      aux = aux->prox;
    }
    printf("%.1f", aux->dado);
  }
}

void lista_esvaziar(plista l) {
  tipoD num = l->quant_elem;
  pdesc aux;
  for (int i = 0; i < num; i++) {
    aux = l->calda->prox;
    free(l->calda);
    l->calda = aux;
    if (l->calda == NULL) {
      l->cabeca = NULL;
    }
    l->quant_elem--;
  }
}

void inserir_elem(plista l, tipoD elemento) {
  pdesc novo = (pdesc)malloc(sizeof(tdesc));
  novo->dado = elemento;
  pdesc aux;
  if (l->quant_elem == 0) {
    l->cabeca = novo;
    l->calda = novo;
  } else {
    if (l->quant_elem == 1) {
      aux = l->cabeca;
      l->calda->prox = novo;
      l->calda = novo;
      novo->prox = aux;
      l->cabeca->prox = l->calda;
    } else {
      aux = l->calda;
      novo->prox = aux;
      l->calda = novo;
      l->cabeca->prox = l->calda;
    }
  }
  l->quant_elem++;
}

void inserir_posicao(plista l, tipoD elemento, int posicao) {
  l->quant_elem++;
  if (posicao > l->quant_elem) {
    printf("Posicao nao existe!\n");
    l->quant_elem--;
  } else {
    pdesc novo = (pdesc)malloc(sizeof(tdesc));
    novo->dado = elemento;
    pdesc aux = l->calda;
    if (posicao == 1) {
      novo->prox = aux;
      l->calda = novo;
    } else {
      if (posicao == l->quant_elem) {
        l->cabeca->prox = novo;
        l->cabeca = novo;
        novo->prox = NULL;
      } else {
        for (int i = 2; i < posicao; i++) {
          aux = aux->prox;
        }
        novo->prox = aux->prox;
        aux->prox = novo;
      }
    }
  }
}

int quant_remover(plista l, tipoD elem) {
  int cont = 0;
  pdesc aux = l->calda;
  while (aux != l->cabeca) {
    if (aux->dado == elem) {
      cont++;
    }
    aux = aux->prox;
  }
  if (l->cabeca->dado == elem) {
    cont++;
  }
  return cont;
}

int posicao(plista l, tipoD elem, int b) {
  int p = 0, q = l->quant_elem;
  pdesc aux = l->calda;
  for (int i = 1; i < b; i++) {
    aux = aux->prox;
  }
  for (int i = b; i <= q; i++) {
    if (aux->dado == elem) {
      p = i;
      return p;
    }
    aux = aux->prox;
  }
  return p;
}

tipoD remover_valor(plista l, tipoD elemento) {
  tipoD valor = elemento;
  int a = 0, b = 1;
  pdesc aux, elem;
  if (l->quant_elem == 1 && l->calda->dado == elemento) {
    free(l->calda);
    l->calda = NULL;
    l->cabeca = NULL;
    l->quant_elem--;
  } else {
    a = quant_remover(l, elemento);
    for (int i = 1; i <= a; i++) {
      b = posicao(l, elemento, b);
      if (b == 1) {
        aux = l->calda->prox;
        free(l->calda);
        l->calda = aux;
      } else {
        if (b == l->quant_elem) {
          aux = l->calda;
          while (aux->prox != l->cabeca) {
            aux = aux->prox;
          }
          free(l->cabeca);
          l->cabeca = aux;
          aux->prox = l->calda;
        } else {
          aux = l->calda;
          for (int i = 1; i < (b - 1); i++) {
            aux = aux->prox;
            elem = aux->prox;
          }
          if (b == 2) {
            elem = l->calda->prox;
          }
          if (elem->dado == elemento) {
            aux->prox = elem->prox;
            free(elem);
          }
        }
      }
      l->quant_elem--;
    }
  }
  return valor;
}

void maior_elem(plista l) {
  pdesc aux = l->calda;
  tipoD maior = aux->dado;
  int n = l->quant_elem;
  for (int i = 1; i < n; i++) {
    if (aux->dado > maior) {
      maior = aux->dado;
    }
    aux = aux->prox;
  }
  if (l->cabeca->dado > maior) {
    maior = aux->dado;
  }
  printf("%.1f\n", maior);
}

void primeiro_elem(plista l) { printf("%.1f\n", l->calda->dado); }

void ultimo_elem(plista l) { printf("%.1f\n", l->cabeca->dado); }

void lista_tamanho(plista l) { printf("%d\n", l->quant_elem); }

void maior_valor(plista l, tipoD elemento) {
  int cont = 0, n = l->quant_elem;
  pdesc aux = l->calda;
  for (int i = 1; i <= n; i++) {
    if (aux->dado > elemento) {
      cont++;
    }
    aux = aux->prox;
  }
  printf("%d\n", cont);
}

void desalocar(plista l, char *c) {
  if (l->quant_elem != 0) {
    pdesc b, a = l->calda;
    while (a != l->cabeca) {
      b = a->prox;
      free(a);
      a = b;
    }
    free(l->cabeca);
  }
  free(l);
  free(c);
}

char *alocar_comando() {
  char* c = (char *)malloc(3 * sizeof(char));
  return c;
}