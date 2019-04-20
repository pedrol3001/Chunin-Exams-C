/**
 * @file lista.h
 * @author Pedro Luis Chaves ROcha
 * @date 10/11/2018
 * @brief Arquivo Contém as declarações das funções de
 * manipulação de listas utilizadas no exame chunin.
 */


#ifndef __lista_H__
#define __lista_H__


#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


#include "arvore.h"

typedef struct Elemento_lista{

    Ninja* ninja;
    int UsedPower;

    struct Elemento_lista* prox;
    struct Elemento_lista* ant;

}elemento_lista;

typedef struct{

    elemento_lista* primeiro;
    elemento_lista* ultimo;
    int quantidade;

}lista;




/**
 * @brief Checa se a lista está vazia
 * @param lista Endereço da lista.
 * @return 1 Caso a lista esteja vazia.
 * @return 0 caso a lista não esteja vazia.
 */
int listaVazia(lista* lista);


/**
 * @brief Aloca memória para a struct de controle da lista.
 * @param Sem parâmetro.
 * @return Retorna o endereço da lista alocada.
 */
lista* aloca_lista();


/**
 * @brief Aloca memória para um elemento da lista e inicia seus valores.
 * @param ninja Endereço do ninja que será inserid na lista.
 * @param UsedPower Útimo poder utilizado pelo ninja de 1 a 4.
 * @return Retorna o endereço do elemento da lista alocado.
 */
elemento_lista* alocaElementoLista(Ninja* ninja,int UsedPower);


/**
 * @brief Usa a função elemento_lista* alocaElementoLista(Ninja* ninja,int UsedPower) para inserir o elemento alocado, na estrutura de controle da lista.
 * @param ninja endereço do ninja que será inserido na lista.
 * @param posi Posisão a ser inserida na lista começando pelo 0.
 * @param lista Endereço da lista aonde o elemento será inserido.
 * @param UsedPower Último poder usado pelo ninja que será inserido na lista de 1 a 4.
 * @return 1 caso o elemento tenha sido inserido.
 * @return 0 caso o elemento não tenha sido inserido.
 */
int inserirLista(Ninja* ninja,int posi,lista* lista,int UsedPower);


/**
 * @brief Remove um elemento da lista.
 * @param posi, posição em que o elemento será removido começãndo pelo 0.
 * @param lista Endereço da lista aonde o elemento será removido.
 * @return Retorna o endereço do Ninja que foi removido.
 */
Ninja* removerLista(int posi,lista*lista);


/**
 * @brief Procuna na lista um ninja pelo nome.
 * @param nome Nome de um ninja que será procurado na lista.
 * @param lista Endereço da lista aonde o ninja será procurado.
 * @return 1 caso o nome exista na lista.
 * @return 0 caso o nome não exista na lista.
 */
int procurarLista(char* nome,lista* lista);


/**
 * @brief Desaloca a memória alocada para a lista junto com seus elementos.
 * @param lista Endereço da lista que será desalocada.
 * @return Sem retorno.
 */
void liberaLista(lista* lista);


/**
 * @brief carrega 16 ninjas aleatórios de um arquivo ninjas.txt para a lista.
 * @param lista Endereço da lista aonde os ninjas serão carregados.
 * @return Retorna o endereço da lista aonde os ninjas foram inseridos.
 */
lista* select_ninjas(lista* lista);



/**
 * @brief Remove os ninjas da lista carregas todos os 16 na base de uma árvore binária com 4 de altura.
 * @param root Endereço do nó raiz da árvore em que os ninjas serão carregados.
 * @param lista Endereço da lista aonde os ninjas já estão.
 * @return Sem retorno.
 */
void fill_tree(t_node* root,lista* lista);


#endif