#include "arvoreb.h"

/*
Essa função tem o objetivo de remover um elemento de uma árvore que seja folha.
Ela verifica como a árvore ficaria após a sua remoção e a partir disso escolhe
qual o método de remoção a ser utilizado.
*/
Arvore* remover_de_folha (Arvore *raiz, Arvore *folha, TIPO k, int index){

    /*Se após a remoção a árvore ainda tiver o tamanho >= T-1, apenas diminuímos
    o tamanho da árvore e deslocamos os elementos que estavam após o elemento
    removido*/
    if(folha->n - 1 >= T-1){
        (folha->n)--;

        for(int i = index; i < folha->n; i++){
            folha->chaves[i] = folha->chaves[i+1];
        }

        printf("Após remoção elemento %d (caso 1)\n", k);
    }
    //Se após a remoção a árvore tiver o tamanho < T-1
    else{

        for(int i = index; i < folha->n; i++){
            folha->chaves[i] = folha->chaves[i+1];
        }

        int indexRaiz = buscar_index_remocao(raiz,k);

        /*SE a chave que foi removida esteja no último filho do nó da raiz
        OU não seja o primeiro filho E o filho a esquerda tenha mais chaves que T-1.
        Haverá interação como o filho a ESQUERDA do filho que será retirado a chave*/
        if(indexRaiz == raiz->n || ((indexRaiz != 0) && (raiz->filhos[indexRaiz-1]->n > T-1)))
        {

            for(int i = folha->chaves[folha->n-1]; i > 0; i--)
                folha->chaves[i] = folha->chaves[i-1];

            //copia a chave do pai correspondente ao index para a primeira posição da folha
            folha->chaves[0] = raiz->chaves[indexRaiz-1];

            //SE o filho a esquerda seja maior que t-1, caso 3A
            if(raiz->filhos[indexRaiz-1]->n > T-1)
            {
                //é movido a última chave do filho a esquerda para a raiz no index correspondente
                raiz->chaves[indexRaiz-1] = raiz->filhos[indexRaiz-1]->chaves[raiz->filhos[indexRaiz-1]->n-1];
                raiz->filhos[indexRaiz-1]->n -= 1;

                printf("Após remoção elemento %d (caso 3A)\n", k);
            }
            /*SENÃO o filho a esquerda será menor ou igual que t-1, caso 3B
            o único caso especial que se entra aqui é quando a chave que se deseja retirar é o último filho da raiz
            e o filho da esquerda é menor que t-1*/
            else
            {
                int aux = folha->n;

                //as chaves do filho da index são copiados para o filho a esquerda
                raiz->filhos[indexRaiz-1]->n *= 2;
                for(int j = 0;aux > j; j++)
                    raiz->filhos[indexRaiz-1]->chaves[aux+j] = raiz->filhos[indexRaiz]->chaves[j];

                //esvazia-se o último filho e por consequente a última chave da raiz
                raiz->filhos[indexRaiz]->n = 0;
                raiz->n -= 1;

                printf("Após remoção elemento %d (caso 3B)\n", k);
            }
        }
        //SENÃO interação com o filho a DIREITA do filho que será retirado a chave
        else {

            //copia a chave do pai correspondente ao index para a última posição da folha
            folha->chaves[folha->n - 1] = raiz->chaves[indexRaiz];

            //caso o filho a direita seja maior que t-1, caso 3A
            if(raiz->filhos[indexRaiz+1]->n > T-1)
            {
                //é movido a primeira chave do filho a direita para a raiz no index correspondente
                raiz->chaves[indexRaiz] = raiz->filhos[indexRaiz+1]->chaves[0];
                raiz->filhos[indexRaiz+1]->n -= 1;
                for(int j = 0; j < raiz->filhos[indexRaiz+1]->n; j++)
                    raiz->filhos[indexRaiz+1]->chaves[j] = raiz->filhos[indexRaiz+1]->chaves[j+1];

                printf("Após remoção elemento %d (caso 3A)\n", k);
            }

            //caso o filho a direita seja maior que t-1, caso 3B
            else
            {
                //as chaves do filho da index são copiados para o filho a direita
                int aux = folha->n;
                folha->n *= 2;
                for(int j = 0;aux > j; j++)
                    folha->chaves[aux+j] = raiz->filhos[indexRaiz+1]->chaves[j];

                //é necessário transferir todos os filhos para o anterior
                for(indexRaiz+=1; indexRaiz < raiz->n; indexRaiz++)
                {
                    raiz->filhos[indexRaiz]->n = raiz->filhos[indexRaiz+1]->n;
                    for(int i = 0; raiz->filhos[indexRaiz]->n > i; i++)
                        raiz->filhos[indexRaiz]->chaves[i] = raiz->filhos[indexRaiz+1]->chaves[i];
                }
                //por fim o último filho é zerado
                raiz->filhos[indexRaiz]->n = 0;

                printf("Após remoção elemento %d (caso 3B)\n", k);
            }
        }
    }

   return folha;
}


/*
Essa função tem o objetivo de remover um elemento de uma árvore que seja interna.
Ela verifica como a árvore ficaria após a sua remoção e a partir disso escolhe
qual o método de remoção a ser utilizado.
*/
Arvore* remover_de_nao_folha (Arvore *a, int index){
   TIPO k = a->chaves[index];
   TIPO predecessor, sucessor;

   /*Quando o filho a esquerda pode doar um elemento*/
   if (a->filhos[index]->n >= T){
       Arvore* aux = a->filhos[index];
       a->chaves[index] = aux->chaves[aux->n - 1];
       (aux->n)--;
       printf("Após remoção elemento %d (caso 2A)\n", k);
   }
  /*Quando o filho a direita pode doar um elemento*/
   else if (a->filhos[index+1]->n >= T){
       Arvore* aux = a->filhos[index+1];
       a->chaves[index] = aux->chaves[0];
       (aux->n)--;
       for(int i = 0; i < aux->n; i++){
           aux->chaves[i] = aux->chaves[i+1];
       }
       printf("Após remoção elemento %d (caso 2B)\n", k);
   }
   /*Quando nenhum dos filhos pode doar um elemento*/
   else{
       int aux = a->filhos[index]->n;
       int auxIndex = index;
       a->filhos[index]->n *= 2;
       for(int j = 0;aux > j; j++)
            a->filhos[index]->chaves[aux+j] = a->filhos[index+1]->chaves[j];

       int i;
       for(i = 1; index + i < a->n; i++)
       {
                a->filhos[index + i]->n = a->filhos[index+i+1]->n;
                for(int j = 0; a->filhos[index+i]->n > j; j++)
                    a->filhos[index+i]->chaves[j] = a->filhos[index+i+1]->chaves[j];
                }
       a->filhos[index+i]->n = 0;
       for(int j = index; j < a->n; j++)
            a->chaves[j] = a->chaves[j+1];
       a->n-=1;

       printf("Após remoção elemento %d (caso 2C)\n", k);
   }

   return a;
}


//Função para verificar se raiz ficou vazia
Arvore *verificar_raiz_vazia (Arvore *raiz){

    /*Se a raiz tiver 0 chaves, torna o primeiro filho a
    nova raiz se existir filho; caso contrário ajustar a raiz para NULL.*/
    if(raiz->n == 0)
    {
        if(raiz->filhos[0]->n == 0)
            return NULL;
        Arvore* aux = raiz;
        raiz = raiz->filhos[0];
        free(aux);
    }
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

/*Esta função remove uma chave da árvore, encarrega-se de procurar em que nó está a chave, caso tenha, e indica
qual é a melhor função de remoção para o uso no momento*/
Arvore* remover (Arvore *r, Arvore *a, TIPO k){
   int index;
   if (a == NULL) {
      printf("Arvorê vazia\n");
      return a;
   }

   index = buscar_index_remocao (a, k);


   //A chave a ser removida está presente neste nó
   if ( index >= 0 && a->chaves[index] == k){
      if (a->folha){
         a = remover_de_folha (r, a, k, index);
      }
      else{
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
