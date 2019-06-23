#include "arvoreb.h"

/*Descrição ...*/
Arvore* remover_de_folha (Arvore *raiz, Arvore *folha, TIPO k, int index){

    //Se após a remoção a árvore ainda tiver o tamanho >= T-1
    if(folha->n - 1 >= T-1){
        (folha->n)--;

        for(int i = index; i < folha->n; i++){
            folha->chaves[i] = folha->chaves[i+1];
        }
    }
    //Se após a remoção a árvore ainda tiver o tamanho < T-1
    else{

        for(int i = index; i < folha->n; i++){
            folha->chaves[i] = folha->chaves[i+1];
        }

        int indexRaiz = buscar_index_remocao(raiz,k);

        if(indexRaiz == raiz->n || ((indexRaiz != 0) && (raiz->filhos[indexRaiz-1]->n > T-1)))
        {
            for(int i = folha->chaves[folha->n-1]; i > 0; i--)
                folha->chaves[i] = folha->chaves[i-1];

            folha->chaves[0] = raiz->chaves[indexRaiz-1];

            if(raiz->filhos[indexRaiz-1]->n > T-1)
            {
                raiz->chaves[indexRaiz-1] = raiz->filhos[indexRaiz-1]->chaves[raiz->filhos[indexRaiz-1]->n-1];
                raiz->filhos[indexRaiz-1]->n -= 1;
            }
            else
            {
                raiz->n -= 1;
                int aux = folha->n;
                raiz->filhos[indexRaiz-1]->n *= 2;
                for(int j = 0;aux > j; j++)
                    raiz->filhos[indexRaiz-1]->chaves[aux+j] = raiz->filhos[indexRaiz]->chaves[j];

                raiz->filhos[indexRaiz]->n = 0;
            }
        }
        else {
            folha->chaves[folha->n - 1] = raiz->chaves[indexRaiz];

            if(raiz->filhos[indexRaiz+1]->n > T-1)
            {
                raiz->chaves[indexRaiz] = raiz->filhos[indexRaiz+1]->chaves[0];
                raiz->filhos[indexRaiz+1]->n -= 1;
                for(int j = 0; j < raiz->filhos[indexRaiz+1]->n; j++)
                    raiz->filhos[indexRaiz+1]->chaves[j] = raiz->filhos[indexRaiz+1]->chaves[j+1];
            }
            else
            {
                int aux = folha->n;
                folha->n *= 2;
                for(int j = 0;aux > j; j++)
                    folha->chaves[aux+j] = raiz->filhos[indexRaiz+1]->chaves[j];

                for(indexRaiz+=1; indexRaiz < raiz->n; indexRaiz++)
                {
                    raiz->filhos[indexRaiz]->n = raiz->filhos[indexRaiz+1]->n;
                    for(int i = 0; raiz->filhos[indexRaiz]->n > i; i++)
                        raiz->filhos[indexRaiz]->chaves[i] = raiz->filhos[indexRaiz+1]->chaves[i];
                }
                raiz->filhos[indexRaiz]->n = 0;
            }
        }
    }

   return folha;
}


/*Descrição ...*/
Arvore* remover_de_nao_folha (Arvore *a, int index){
   TIPO k = a->chaves[index];
   TIPO predecessor, sucessor;

   /*Descrição ...*/
   if (a->filhos[index]->n >= T){
       Arvore* aux = a->filhos[index];
       a->chaves[index] = aux->chaves[aux->n - 1];
       remover(aux,aux, aux->chaves[aux->n - 1]);
   }
  /*Descrição ...*/
   else if (a->filhos[index+1]->n >= T){
       Arvore* aux = a->filhos[index+1];
       a->chaves[index] = aux->chaves[0];
       remover(aux,aux, aux->chaves[0]);
   }
   /*Quando nenhum dos filhos pode doar um elemento*/
   else{
       /* Nicolas */
       printf("Completar\n");
   }

   return a;
}


//Função para verificar se raiz ficou vazia
Arvore *verificar_raiz_vazia (Arvore *raiz){
    /*Se após a remoção a raiz tiver 0 chaves, tornar o primeiro filho a
    nova raiz se existir filho; caso contrário ajustar a raiz para NULL.
    Liberar a raiz antiga*/

   /*Completar!!!! */
   printf("Completar\n");

    return raiz;
}



/*Função que retorna o index da primeira chave maior ou igual à chave*/
int buscar_index_remocao (Arvore *a, TIPO chave) {

   int i = 0;

   /*Procurando a chave no vetor de chaves */
   while ((i < a->n) && (chave > a->chaves[i])) {
     i = i + 1;
   }

   return i;
}

/*Descrição: ????*/
Arvore* remover (Arvore *r, Arvore *a, TIPO k){
   int index;
   /*Completar!!!!!!!!!!!!!!*/
   if (a == NULL) {
      /*Completar!!!*/
      printf("Completar\n");
   }

   index = buscar_index_remocao (a, k);


   //A chave a ser removida está presente neste nó
   if ( index >= 0 && a->chaves[index] == k){
      if (a->folha){
         a = remover_de_folha (r, a, k, index);
      }
      else{      /*Completar!!!*/
         a = remover_de_nao_folha (a, index);
      }
   }
   else{
      //Se este nó é um nó folha, então a chave não está na árvore
      if (a->folha){
  	       printf("\nA chave %c não está na árvore.\n",k);
           return a;
      }
      r = a;
      return remover(r, a->filhos[index], k);

   }

   a = verificar_raiz_vazia(a);

   return a;
}
