#include "arvoreb.h"

Arvore* test_case_two(Arvore* a){

    a = inserir (a, 'F');
    a = inserir (a, 'S');
    a = inserir (a, 'Q');
    a = inserir (a, 'K');
    a = inserir (a, 'C');
    a = inserir (a, 'L');
    a = inserir (a, 'H');
    a = inserir (a, 'T');
    a = inserir (a, 'V');
    a = inserir (a, 'W');
    a = inserir (a, 'M');
    a = inserir (a, 'R');
    a = inserir (a, 'N');
    a = inserir (a, 'P');
    a = inserir (a, 'A');
    a = inserir (a, 'B');
    a = inserir (a, 'X');
    a = inserir (a, 'Y');
    a = inserir (a, 'D');
    a = inserir (a, 'Z');
    a = inserir (a, 'E');

    imprimir (a, 0);

    printf("------------------\n");

    // imprimir (a, 0);

    return a;

}

Arvore* test_case_one(Arvore* a){

    a = inserir (a, 91);
    a = inserir (a, 90);
    a = inserir (a, 80);
    a = inserir (a, 71);
    a = inserir (a, 72);
    a = inserir (a, 50);
    a = inserir (a, 45);
    a = inserir (a, 47);
    a = inserir (a, 10);
    a = inserir (a, 8);
    a = inserir (a, 7);
    a = inserir (a, 5);
    a = inserir (a, 2);
    a = inserir (a, 3);
    a = inserir (a, 22);
    a = inserir (a, 44);
    a = inserir (a, 55);
    a = inserir (a, 66);
    a = inserir (a, 68);
    a = inserir (a, 17);
    a = inserir (a, 6);
    a = inserir (a, 21);
    a = inserir (a, 67);
    a = inserir (a, 4);

    imprimir (a, 0);

    printf("------------------\n");

    remover(NULL, a, 22);
    imprimir (a, 0);
    printf("------------------\n");
    remover(NULL, a, 10);
    imprimir (a, 0);
    printf("------------------\n");
    remover(NULL, a, 50);
    imprimir (a, 0);
    printf("------------------\n");
    remover(NULL, a, 80);
    imprimir (a, 0);
    printf("------------------\n");
    remover(NULL, a, 7);
    imprimir (a, 0);
    printf("------------------\n");

    return a;

}

/*Função principal:*/
int main (int argc, char** argv) {

   Arvore *a = criar();

   if(*argv[1] == '1'){
       a = test_case_one(a);
   }
   else{

       a = inserir (a, 91);
       a = inserir (a, 90);
       a = inserir (a, 80);
       a = inserir (a, 71);
       a = inserir (a, 72);
       a = inserir (a, 50);
       a = inserir (a, 45);
       a = inserir (a, 47);
       a = inserir (a, 10);
       a = inserir (a, 8);
       a = inserir (a, 7);
       a = inserir (a, 5);
       a = inserir (a, 2);
       a = inserir (a, 3);
       a = inserir (a, 22);
       a = inserir (a, 44);
       a = inserir (a, 55);
       a = inserir (a, 66);
       a = inserir (a, 68);
       a = inserir (a, 17);
       a = inserir (a, 6);
       a = inserir (a, 21);
       a = inserir (a, 67);

   }

   // remover(a, 8);
   // remover(a, 67);
   // remover(a, 5);
   // remover(a, 10);
   // remover(a, 8);



   return 0;
}
