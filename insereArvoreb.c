#include "arvoreb.h"

/*
Essa função tem como objetivo dividir uma árvore que está cheia.
Ela cria um novo nó e "sobe" a mediana dela para a árvore que está acima dela e
então adiciona a árvore que foi criada a direita do elemento que subiu.
Todos os elementos e filhos que estavam a direita da mediana são adicionados na
nova árvore.

x = novo nó (onde a chave vai subir)
y = nó que está cheio
i = posição da chave no nó x
*/

Arvore* dividir_no (Arvore *x, int i, Arvore *y) {

    //Cria uma nova árvore que será a árvore à direita da chave que vai subir
    Arvore* dir = criar();

    //Coloca as chaves que estão depois da mediana na nova árvore
    for(int h = 0; h < (2*T-1)/2; h++){
        dir->chaves[h] = y->chaves[h+(2*T-1)/2 + 1];
        (dir->n)++;
    }

    //Movemos os filhos que estavam relacionadas as chaves que foram retiradas
    //para a nova árvore, caso o nó não seja folha
    if(!y->folha){
        for(int h = 0; h < 2*T; h++){
            dir->filhos[h] = y->filhos[h+T];
        }

        dir->folha = FALSE;
    }

    //Como os elementos foram retirados, diminuir o tamanho da árvore
    y->n = y->n-(2*T-1)/2;

    //Agora é necessário "empurrar" todos os filhos do X uma posição para a
    //frente, já que o novo filho vai entrar ali
    for(int h = x->n + 1; h > i+1; h--){
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
    y->n = y->n-1;
    (x->n)++;

   return x;
}

/*
O objetivo dessa função é inserir um elemento em um nó da árvore que
não está cheio.
x = árvore onde a chave deve ser inserida
k = chave que deve ser inserida
*/
Arvore* inserir_arvore_nao_cheia (Arvore *x, TIPO k) {

    //Se a árvore não for folha
    if(!x->folha){
        int i = 0;

        //Busca a posição onde a chave é maior ou igual que a chave que
        //desejamos inserir
        while(i < x->n && x->chaves[i] < k){
            i++;
        }

        //Caso o filho na posição i seja folha, sabemos que a chave deve ser
        //inserida nele
        if(x->filhos[i]->folha){

            //Verificamos se o filho está cheio. Caso esteja, divida
            if(x->filhos[i]->n == 2*T-1){
                dividir_no(x, i, x->filhos[i]);
                int filho = x->chaves[i];
                //Após a divisão, verificamos se a chave deve ser inserida
                //no filho à direita ou à esquerda da chave que subiu
                if(filho > k){
                    x->filhos[i] = inserir_arvore_nao_cheia(x->filhos[i], k);
                }
                else{
                    x->filhos[i+1] = inserir_arvore_nao_cheia(x->filhos[i+1], k);
                }
                return x;
            }
        }
        //Caso o filho na posição i esteja cheio, devemos dividi-lo para
        //previnir que uma futura divisão do seus filhos a árvore
        //em que a mediana subirá esteja cheia
        if(x->filhos[i]->n >= 2*T-1){
            dividir_no(x, i, x->filhos[i]);
        }
        //Chamamos a função recursivamente para o filho na posição i
        x->filhos[i] = inserir_arvore_nao_cheia(x->filhos[i], k);
        return x;
    }

    //Se a árvore for folha, apenas adicionamos o elemento novo nela

    //Busca a posição que a nova chave será inserida.
    int i = 0;
    if(x->n != 0){
        while(x->chaves[i] < k && i < x->n){
            i++;
        }

        //Desloca as chaves para a direita
        for(int h = x->n; h > i; h--){
            x->chaves[h] = x->chaves[h-1];
        }
    }

    //Coloca a chave no lugar deslocado
    x->chaves[i] = k;
    x->n = x->n + 1;

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
