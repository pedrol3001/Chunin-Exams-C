/**
 * @file arvore.h
 * @author Pedro Luis Chaves ROcha
 * @date 10/11/2018
 * @brief Arquivo Contém as declarações das funções de
 * de manipulação da arvore do exame chunin.
 */

#ifndef __arvore_H__
#define __arvore_H__


#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>



typedef struct {

    char* nome;
    char* elemento;
    int ninjutsu;
    int genjutsu;
    int taijutsu;
    int defesa;

}Ninja;

typedef struct node {

    Ninja* ninja;

    struct node* left;
    struct node* right;

}t_node;

#include "lista.h"


/**
 * @brief Aloca memória para um nó de uma árvore.
 * @param Sem parâmetro.
 * @return Retorna o endereço do nó alocado.
 */
t_node* node_create();



/**
 * @brief Aloca uma struct do tipo Ninja e inicia seus valores por cópia.
 * @param _nome Nome do ninja.
 * @param _elemento Elemento do ninja.
 * @param _ninjutsu Ninjustu do ninja.
 * @param _genjutsu Genjutsu do ninja.
 * @param _taijutsu Taijutsu do ninja.
 * @param _defesa Defesa do ninja.
 * @return Retorna o endereço da struct alocada.
 */
Ninja* ninja_create(char* _nome, char* _elemento,
                    int _ninjutsu, int _genjutsu,
                    int _taijutsu, int _defesa);


/**
 * @brief Desaloca a memória antes alocado da struct ninja.
 * @param ninja Endereço do ninja a ser desalocado.
 * @return Sem retorno.
 */
void ninja_free(Ninja* ninja);


/**
 * @brief Insere um nó já alocado na árvore.
 * @param raiz Nó raiz da árvore
 * @param num qunatidade de níveis em que srem adicionados nós.
 * @return Retorna o endereço do nó inserido.
 */
t_node* node_insert(t_node* raiz,int num);



/**
 * @brief Faz uso da função t_node* node_insert(t_node* raiz,int num) para criar um árvore binária balanceada de altura 4.
 * @param Sem parâmetro.
 * @return Retorna o endereço da árvore criada.
 */
t_node* tree_create();


/**
 * @brief Desaloca toda a mémória alocada na cração da árvore.
 * @brief Também desaloca ninjas na base da árvore caso existam.
 * @param tree Endereço da árvore a ser desalocada.
 * @return Sem retorno
 */
void tree_free(t_node* tree);


/**
 * @brief Compara o atributo escolhido de cada ninja para ver quem ganhou a batalha.
 * @param ninja_one Primeiro ninja.
 * @param ninja_two Segundo ninja.
 * @param attibute Atributo de 1 a 4 escolhido.
 * @return Retorna endereço do ninja vencedor.
 * @return NULL caso o parametro seja inválido.
 */
Ninja* fight(Ninja* ninja_one, Ninja* ninja_two,int attribute);


/**
 * @brief retorna o endereço de um ninja seguindo a ordem dos ninjas da esquerda para direita
 * @param raiz Endereço do nó raiz da árvore em que o ninja será buscado.
 * @param indice Numero que indica qual n-ésimo ninja da base será buscado.
 * @return Endereço do n-ésimo ninja da base da árvore.
 * @return NULL caso ninja não exista.
 */
Ninja* go_to_ninja(t_node* raiz,int *indice);


/**
 * @brief Imprime a árvore em pré-ordem.
 * @param root Endereço do nó raiz da árvore a ser mostrada.
 * @return Sem retorno.
 */
void tree_print_preorder(t_node* root);

#endif