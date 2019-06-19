#include "arvoreb.h"

/*Descrição ...*/
Arvore* remover_de_folha (Arvore *a, int index){

    printf("Remover de folha!\n");

    //Se após a remoção a árvore ainda tiver o tamanho >= T-1
    if(a->n - 1 >= T-1){
        (a->n)--;

        for(int i = index; i < a->n; i++){
            a->chaves[i] = a->chaves[i+1];
        }
    }
    //Se após a remoção a árvore ainda tiver o tamanho < T-1
    else{
        /*Completar Nicolas*/
    }

   return a;
}


/*Descrição ...*/
Arvore* remover_de_nao_folha (Arvore *a, int index){
   TIPO k = a->chaves[index];
   TIPO predecessor, sucessor;

   /*Descrição ...*/
   if (a->filhos[index]->n >= T){
       Arvore* aux = a->filhos[index];
       a->chaves[index] = aux->chaves[aux->n - 1];
       remover(aux, aux->chaves[aux->n - 1]);
   }
  /*Descrição ...*/
   else if (a->filhos[index+1]->n >= T){
       Arvore* aux = a->filhos[index+1];
       a->chaves[index] = aux->chaves[0];
       remover(aux, aux->chaves[0]);
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
Arvore* remover (Arvore *a, TIPO k){
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
         a = remover_de_folha (a, index);
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

      return remover(a->filhos[index], k);

   }

   a = verificar_raiz_vazia(a);

   return a;
}
