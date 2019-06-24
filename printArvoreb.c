#include "arvoreb.h"

/*Função para buscar uma chave em uma árvore B:*/
void imprimir (Arvore *a, int nivel) {

    if(a->n == 0){
        printf("VAZIA!\n");
        return;
    }

   int i;

   /*Imprime recuo para definir o nível do nó: */
   for (i = 0; i < nivel; i++) { printf("  "); }

   /*Imprime as chaves armazenadas no nó: */
   printf("|");
   for (i = 0; i < a->n; i++) {
       printf("%d|", a->chaves[i]);
   }
   printf("\n");

   /*Recursivamente imprime as chaves dos filhos: */
   for (i = 0; i <= a->n; i++) {
      if (a->folha == FALSE) {
         imprimir(a->filhos[i], nivel + 1);
      }
   }
}
