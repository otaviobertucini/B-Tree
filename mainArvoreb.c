#include "arvoreb.h"

Arvore* test_case_two(Arvore* a){

    a = inserir (a, 1);
    a = inserir (a, 2);
    a = inserir (a, 20);
    a = inserir (a, 21);
    a = inserir (a, 22);
    a = inserir (a, 3);
    a = inserir (a, 4);
    a = inserir (a, 23);
    a = inserir (a, 24);
    a = inserir (a, 25);
    a = inserir (a, 36);

    printf("------------------\n");
    imprimir (a, 0);
    printf("------------------\n");
    remover(NULL, a, 22);
    imprimir (a, 0);
    printf("------------------\n");
    remover(NULL, a, 23);
    imprimir (a, 0);
    printf("------------------\n");
    remover(NULL, a, 4);
    imprimir (a, 0);
    printf("------------------\n");
    remover(NULL, a, 24);
    imprimir (a, 0);
    printf("------------------\n");
    remover(NULL, a, 36);
    imprimir (a, 0);

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

    if(argc == 0){
        a = test_case_one(a);
        return 0;        
    }

   Arvore *a = criar();

   if(*argv[1] == '1'){
       a = test_case_one(a);
   }
   else{
       a = test_case_two(a);
   }

   return 0;
}
