/**
 * @file lista.c
 * @author Pedro Luis Chaves ROcha
 * @date 10/11/2018
 * @brief Arquivo Contém as implementações das funções de
 * manipulação de listas utilizadas no exame chinin.
 */

#include "lista.h"

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int listaVazia(lista* lista){

    if(lista->primeiro==NULL && lista->ultimo==NULL) return 1;
    else return 0;

}


lista* aloca_lista(){

    lista* ptr=(lista*)malloc(sizeof(lista));
    ptr->primeiro=NULL;
    ptr->ultimo=NULL;
    ptr->quantidade=0;

    return ptr;

}


elemento_lista* alocaElementoLista(Ninja* ninja,int UsedPower){

    elemento_lista* ptr=(elemento_lista*)malloc(sizeof(elemento_lista));
    ptr->prox=NULL;
    ptr->ant=NULL;
    ptr->ninja=ninja;
    ptr->UsedPower=UsedPower;

    return ptr;

}


int inserirLista(Ninja* ninja,int posi,lista* lista,int UsedPower){ // será tratado como um vetor (0..N)

    elemento_lista* ptr=alocaElementoLista(ninja,UsedPower);

    if(posi==lista->quantidade){

        if(posi==0){ // lista zerada
            lista->primeiro=ptr;
            lista->ultimo=ptr;

        }else{ // inserir no final

            lista->ultimo->prox=ptr;
            ptr->ant=lista->ultimo;
            lista->ultimo=ptr;

        }
        lista->quantidade++;

    }
    else if(posi>0 || posi<lista->quantidade){

        if(posi==0){ // inserir no inicio

            lista->primeiro->ant=ptr;
            ptr->prox=lista->primeiro;
            lista->primeiro=ptr;

        }
        else{

            ptr->prox=lista->primeiro;
            for(int i=0;i<posi;i++){

                ptr->prox=ptr->prox->prox;

            }

            ptr->ant=ptr->prox->ant;
            ptr->ant->prox=ptr;
            ptr->prox->ant=ptr;

        }

        lista->quantidade++;

    }else return 0; // retorna 0 se o valor for inválido

    return 1; // retorn 1 se o valor for válido

}


Ninja* removerLista(int posi,lista*lista){

    if(!(listaVazia(lista))){

        elemento_lista* ptr = lista->primeiro;
        Ninja* resultado;

        if(posi<0 || posi>lista->quantidade -1) return NULL;

        for(int i=0;i<posi;i++){

            ptr=ptr->prox;

        }



        resultado=ptr->ninja;
        if(posi!=0)ptr->ant->prox=ptr->prox;
        else lista->primeiro=ptr->prox;

        if(posi!= lista->quantidade-1)ptr->prox->ant=ptr->ant;
        else lista->ultimo=ptr->ant;

        free(ptr);
        lista->quantidade--;

        return resultado;
    }
    else return NULL;
}


int procurarLista(char* nome,lista* lista){

    elemento_lista* ptr=lista->primeiro;

    if(!(listaVazia(lista))){
        do{

            if(strcmp(nome,ptr->ninja->nome)==0) return 1;
            ptr=ptr->prox;


        }while(ptr!=NULL);

    }

    return 0;
}


void liberaLista(lista* lista){

    elemento_lista* ptr= lista->primeiro;
    if(!(listaVazia(lista))){

        while(ptr!=NULL){

            lista->primeiro=lista->primeiro->prox;
            free(ptr);
            ptr=lista->primeiro;

        }

    }
    free(lista);
}



lista* select_ninjas(lista* lista){

    // le arquivo ninjas.txt
    FILE *fd =fopen("ninjas.txt", "r");
    if(fd==NULL) return NULL;

    char buf_nome[30];
    char buf_elemento[10];
    int buf_nijutsu, buf_genjutsu, buf_taijutsu, buf_defesa;
    
    // loop até encher a lista 
    while(lista->quantidade<16){

        
        rewind(fd);
        int aleatorio=rand()%32;

        int i=0;
        char k;
        while(i<aleatorio){
            fscanf(fd,"%c",&k);
            if(k=='\n') i++;
        }

        
        fscanf(fd,"%[^,], %[^,], %d, %d, %d, %d\n",buf_nome,buf_elemento,
                                        &buf_nijutsu,&buf_genjutsu,
                                        &buf_taijutsu,&buf_defesa);
        
        // checa ninjas repetidos
        if(procurarLista(buf_nome,lista)==0){ //só cria e aloca se não achar ninguém


            Ninja* ninja=ninja_create(buf_nome,buf_elemento,
                                        buf_nijutsu,buf_genjutsu,
                                        buf_taijutsu,buf_defesa);


            inserirLista(ninja,0,lista,0);
    
        }
    }

    fclose(fd);
    return lista;


}


void fill_tree(t_node* root,lista* lista){


     if(root!=NULL){

        if(root->left==NULL && root->right==NULL){

            // tranfere da lista para a arvore, já remove da lista
            root->ninja=removerLista(0,lista);

        }

        fill_tree(root->left,lista);
        fill_tree(root->right,lista);

    }
    

    

}