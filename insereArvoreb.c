#include "arvoreb.h"

/*
x = novo nó
y = nó que está cheio
i = posição da chave no nó x
*/

Arvore* dividir_no (Arvore *x, int i, Arvore *y) {

    //Cria uma nova árvore que será a árvore à direita da chave que vai subir
    Arvore* dir = criar();

    //Coloca as chaves que estão depois da mediana na nova árvore
    for(int h = 0; h < (2*T-1)/2; h++){
        dir->chaves[h] = y->chaves[h+(2*T-1)/2 + 1];
    }

    //Movemos os filhos que estavam relacionadas as chaves que foram retiradas
    //para a nova árvore, caso o nó não seja folha
    if(!y->folha){
        for(int h = 0; h < 2*T; h++){
            dir->filhos[h] = y->filhos[h+T];
        }
    }

    //Como os elementos foram retirados, diminuir o tamanho da árvore
    y->n = n-(2*T-1)/2; //TODO: substituir pelo remover?

    //Agora é necessário "empurrar" todos os filhos do X uma posição para a
    //frente, já que o novo filho vai entrar ali
    for(int h = x->n; h > i+1; h--){
        x->filhos[h] = x->filhos[h-1];
    }

    //Agora a árvore que criamos anteriormente (dir) é colocada dentro do
    //espaço que foi criado para ela
    x->filhos[i+1] = dir;

    //Então, devemos abrir espaço para subir a mediana da árvore Y.
    //Fazemos o mesmo procedimento de antes, só que agora com as chaves
    for(int h = x->n; h > i; h--){
        x->chaves[h] = x->chaves[h-1];
    }

    //Agora colocamos a mediana no lugar dela e aumentamos o número de chaves
    //na árvore
    x->chaves[i] = y->chaves[(2*T-1)/2];
    (x->n)++;

   return x;
}

/*Descrição: ????*/
Arvore* inserir_arvore_nao_cheia (Arvore *x, TIPO k) {
   /*Completar!!!!!!!!!!!!!!*/
   printf("Completar\n");
   return x;
}

/*Função para inserir uma chave em uma árvore B:*/
Arvore *inserir (Arvore *raiz, TIPO chave) {
   Arvore *r = raiz;
   if (r->n == (2*T - 1)) {
      Arvore *s = criar();
      s->folha = FALSE;
      s->filhos[0] = r;
      s = dividir_no (s, 0, r);
      s = inserir_arvore_nao_cheia (s, chave);
      return s;
   }
   else {
      return inserir_arvore_nao_cheia (r, chave);
   }
}
