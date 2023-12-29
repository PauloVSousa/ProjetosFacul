#ifndef _listacircular_h
#define _listacircular_h

typedef struct descritor tdesc, *pdesc;
typedef struct Lista tlista, *plista;
typedef float tipoD;
plista lista_cria();
void lista_exibir(plista l);
void lista_esvaziar(plista l);
void inserir_elem(plista l, tipoD elemento);
void inserir_posicao(plista l, tipoD elemento, int posicao);
tipoD remover_valor(plista l, tipoD elemento);
void maior_elem(plista l);
void primeiro_elem(plista l);
void ultimo_elem(plista l);
void lista_tamanho(plista l);
void maior_valor(plista l, tipoD elemento);
void desalocar(plista l, char *c);
char *alocar_comando();

#endif
