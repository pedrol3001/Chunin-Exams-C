/**
 * @file arvore.c
 * @author Pedro Luis Chaves ROcha
 * @date 10/11/2018
 * @brief Arquivo Contém as implementações das funções de
 * de manipulação da arvore do exame chunin.
 */

#include "arvore.h"

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>





t_node* node_create(){

    t_node* ptr=(t_node*)malloc(sizeof(t_node));
    ptr->right=NULL;
    ptr->left=NULL;
    ptr->ninja=NULL;

    return ptr;

}


Ninja* ninja_create(char* _nome, char* _elemento,
                    int _ninjutsu, int _genjutsu,
                    int _taijutsu, int _defesa){


    Ninja* ptr=(Ninja*)malloc(sizeof(Ninja));                  
    ptr->nome = (char*)malloc(strlen(_nome)+1);
    ptr->elemento = (char*)malloc(strlen(_elemento)+1);

    strcpy(ptr->nome,_nome);
    strcpy(ptr->elemento,_elemento);
    ptr->ninjutsu=_ninjutsu;
    ptr->genjutsu=_genjutsu;
    ptr->taijutsu=_taijutsu;
    ptr->defesa=_defesa;

    return ptr;
    

}


void ninja_free(Ninja* ninja){

    free(ninja->nome);
    free(ninja->elemento);
    free(ninja);

}


t_node* node_insert(t_node* raiz,int num){

    raiz=node_create();
    if(num>0){

        raiz->left=node_insert(raiz->left,num-1);
        raiz->right=node_insert(raiz->right,num-1);
    }

    return raiz;
    
}


t_node* tree_create(){

    t_node* raiz=NULL;
    
    // usa a função para criar uma arvore de altura (4)
    return node_insert(raiz,4);

}


void tree_free(t_node* tree){

    // free recursivo na arvore e no ninja quando estiver no ultimo nivel da arvore
    if(tree->left!=NULL) tree_free(tree->left);
    if(tree->right!=NULL) tree_free(tree->right);

    if(tree->right == NULL && tree->left==NULL)
        ninja_free(tree->ninja);

    free(tree);

}


Ninja* fight(Ninja* ninja_one, Ninja* ninja_two,int attribute){

    if(attribute<=0) attribute=attribute+4;
    if(attribute>4) attribute=attribute-4;

    // compara o atributo escolhido
    switch(attribute){
        case 1:

        if(ninja_one->ninjutsu>ninja_two->ninjutsu) return ninja_one;
        else return ninja_two;

        break;
        case 2:

        if(ninja_one->genjutsu>ninja_two->genjutsu) return ninja_one;
        else return ninja_two;

        break;
        case 3:

        if(ninja_one->taijutsu>ninja_two->taijutsu) return ninja_one;
        else return ninja_two;

        break;
        case 4:

        if(ninja_one->defesa>ninja_two->defesa) return ninja_one;
        else return ninja_two;

        break;

        default:
        return NULL;

    }


}


Ninja* go_to_ninja(t_node* raiz,int *indice){

  Ninja* aux;

    if(raiz!=NULL){

        
        if(*indice >0 ) aux= go_to_ninja(raiz->left,indice);
        if(*indice >0 ) aux= go_to_ninja(raiz->right,indice);

        if(raiz->ninja!=NULL){
            
            // decrementa o indice
            *indice=*indice-1;
            if(*indice==0) return raiz->ninja;
        } 

    }   
    return aux;
}


void tree_print_preorder(t_node* root){

    if(root!=NULL){

        if(root->ninja!=NULL);
        printf("%s\n",root->ninja->nome);
        tree_print_preorder(root->left);
        tree_print_preorder(root->right);
    }

}








