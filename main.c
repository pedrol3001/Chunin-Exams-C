/**
 * @file main.c
 * @author Pedro Luis Chaves ROcha
 * @date 10/11/2018
 * @brief Arquivo Contém as implementações funçõe que implementam
 * o exame chunin utilizando as arvores e as listas.
 */


#include "lista.h"
#include "arvore.h"


#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


/**
 * @brief Imprime uma tela de vitória.
 * @param personagem Ninja do personagem, ganhador da batalha.
 * @param ninja_two Ninja Derrotado.
 * @return Sem retorno.
 */
void print_vit(Ninja* personagem, Ninja* ninja_two,int attribute){

    int elem_flag=0;

    if(attribute<=0) {
        attribute=attribute+4;
        elem_flag=-1;
    }
    if(attribute>4) {
        attribute=attribute-4;
        elem_flag=1;
    }
    system("clear");
    printf("██╗   ██╗██╗████████╗ ██████╗ ██████╗ ██╗ █████╗ \n");  
    printf("██║   ██║██║╚══██╔══╝██╔═══██╗██╔══██╗██║██╔══██╗\n");
    printf("██║   ██║██║   ██║   ██║   ██║██████╔╝██║███████║\n");
    printf("╚██╗ ██╔╝██║   ██║   ██║   ██║██╔══██╗██║██╔══██║\n");
    printf(" ╚████╔╝ ██║   ██║   ╚██████╔╝██║  ██║██║██║  ██║\n");
    printf("  ╚═══╝  ╚═╝   ╚═╝    ╚═════╝ ╚═╝  ╚═╝╚═╝╚═╝  ╚═╝\n");

    if(attribute==1)
        printf("%s  (Ninjutsu %d) x  %s (Ninjutsu %d)",personagem->nome,personagem->ninjutsu,ninja_two->nome,ninja_two->ninjutsu);
    else if(attribute==2)
        printf("%s  (Genjutsu %d) x  %s (Genjutsu %d)",personagem->nome,personagem->genjutsu,ninja_two->nome,ninja_two->genjutsu);
    else if(attribute==3)
        printf("%s  (Taijutsu %d) x  %s (Taijutsu %d)",personagem->nome,personagem->taijutsu,ninja_two->nome,ninja_two->taijutsu);
    else if(attribute==4)
        printf("%s  (Defesa %d) x  %s (Defesa %d)",personagem->nome,personagem->defesa,ninja_two->nome,ninja_two->defesa);

    if(elem_flag==-1) 
        printf(" [x0.8]");
    if(elem_flag==1) 
        printf(" [x1.2]");

    printf("\n");

    printf("\n%s Venceu a batalha!\n\n",personagem->nome);

    printf("Pressione qualquer tecla para continuar...\n");

    getchar();
    getchar();

    system("clear");

}

/**
 * @brief Imprime uma tela de derrota.
 * @param personagem Ninja do personagem, perdedor da batalha.
 * @param ninja_two Ninja Vencedor.
 * @return Sem retorno.
 */
void print_der(Ninja* personagem, Ninja* ninja_two,int attribute){

    int elem_flag=0;

    if(attribute<=0) {
        attribute=attribute+4;
        elem_flag=-1;
    }
    if(attribute>4) {
        attribute=attribute-4;
        elem_flag=1;
    }

    system("clear");
    printf("██████╗ ███████╗██████╗ ██████╗  ██████╗ ████████╗ █████╗ \n");
    printf("██╔══██╗██╔════╝██╔══██╗██╔══██╗██╔═══██╗╚══██╔══╝██╔══██╗\n");
    printf("██║  ██║█████╗  ██████╔╝██████╔╝██║   ██║   ██║   ███████║\n");
    printf("██║  ██║██╔══╝  ██╔══██╗██╔══██╗██║   ██║   ██║   ██╔══██║\n");
    printf("██████╔╝███████╗██║  ██║██║  ██║╚██████╔╝   ██║   ██║  ██║\n");
    printf("╚═════╝ ╚══════╝╚═╝  ╚═╝╚═╝  ╚═╝ ╚═════╝    ╚═╝   ╚═╝  ╚═╝\n");

    if(attribute==1)
        printf("%s  (Ninjutsu %d) x  %s (Ninjutsu %d)",personagem->nome,personagem->ninjutsu,ninja_two->nome,ninja_two->ninjutsu);
    else if(attribute==2)
        printf("%s  (Genjutsu %d) x  %s (Genjutsu %d)",personagem->nome,personagem->genjutsu,ninja_two->nome,ninja_two->genjutsu);
    else if(attribute==3)
        printf("%s  (Taijutsu %d) x  %s (Taijutsu %d)",personagem->nome,personagem->taijutsu,ninja_two->nome,ninja_two->taijutsu);
    else if(attribute==4)
        printf("%s  (Defesa %d) x  %s (Defesa %d)",personagem->nome,personagem->defesa,ninja_two->nome,ninja_two->defesa);

    if(elem_flag==-1) 
        printf(" [x0.8]");
    if(elem_flag==1) 
        printf(" [x1.2]");

    printf("\n");

    printf("\n%s Venceu a batalha!\n\n",ninja_two->nome);

    printf("Pressione qualquer tecla para continuar...\n");

    getchar();
    getchar();

    system("clear");                                  
   
}


/**
 * @brief Verifica se houve uma vantagem elemental ou uma desvantagem elemental entre 2 ninjas.
 * @param personagem NInja do personagem que sofrerá a vantagem ou desvantegem elemental.
 * @param ninja1 Ninja que será comparado com o personagem.
 * @return 1 caso houve vantagem elemental.
 * @return 0 caso não houve nada.
 * @return -1 caso houve desvantagem elemental.
 */
int vantagem_elemento(Ninja* personagem, Ninja* ninja1){

    if(strcmp(personagem->elemento,"Fogo")==0 && strcmp(ninja1->elemento,"Vento")==0) return 1;
    else if(strcmp(personagem->elemento,"Vento")==0 && strcmp(ninja1->elemento,"Relampago")==0) return 1;
    else if(strcmp(personagem->elemento,"Relampago")==0 && strcmp(ninja1->elemento,"Terra")==0) return 1;
    else if(strcmp(personagem->elemento,"Terra")==0 && strcmp(ninja1->elemento,"Agua")==0) return 1;
    else if(strcmp(personagem->elemento,"Agua")==0 && strcmp(ninja1->elemento,"Fogo")==0) return 1;

    else if(strcmp(personagem->elemento,"Vento")==0 && strcmp(ninja1->elemento,"Fogo")==0) return -1;
    else if(strcmp(personagem->elemento,"Relampago")==0 && strcmp(ninja1->elemento,"Vento")==0) return -1;
    else if(strcmp(personagem->elemento,"Terra")==0 && strcmp(ninja1->elemento,"Relampago")==0) return -1;
    else if(strcmp(personagem->elemento,"Agua")==0 && strcmp(ninja1->elemento,"Terra")==0) return -1;
    else if(strcmp(personagem->elemento,"Fogo")==0 && strcmp(ninja1->elemento,"Agua")==0) return -1;

    else return 0;

}

/**
 * @brief Imprime todos os ninjas presentes na base da árvore mostrando apenas 1 de seus atrubutos aleatoriamente.
 * @param root Endereço do nó raiz da árvore que será printada.
 * @param cont inicio do contador para imprimir uma contagem dos ninjas. Recomendado deixar em 0.
 * @return Qual numero do ninja na ordem da arvore foi printado de 1 a 16.
 */
int print_personagens(t_node* root,int cont){    

    if(root!=NULL){

        if(root->left==NULL && root->right==NULL){
    
            cont++;

            printf("Personagem %d :\n",cont);


            int random=rand()%4;
        
            // imprime apenas 1 atributo aleatorio
            switch(random){

                case 0:

                    printf("Ninjutsu: %d Genjutsu: ?? Taijutsu: ?? Defesa: ??\n\n",root->ninja->ninjutsu);

                break;
                case 1:

                    printf("Ninjutsu: ?? Genjutsu: %d Taijutsu: ?? Defesa: ??\n\n",root->ninja->genjutsu);

                break;
                case 2:

                    printf("Ninjutsu: ?? Genjutsu: ?? Taijutsu: %d Defesa: ??\n\n",root->ninja->taijutsu);

                break;
                case 3:

                    printf("Ninjutsu: ?? Genjutsu: ?? Taijutsu: ?? Defesa: %d\n\n",root->ninja->defesa);

                break;
            }

            return cont;
        }
        // recursão para printar a lista já com os ninjas na base em pré-ordem
        cont = print_personagens(root->left,cont);
        cont = print_personagens(root->right,cont);

    }

    return cont;
}

/**
 * @brief Escolhe um ninja dos 16 para ser o personagem.
 * @param raiz Endereço da árvore que contém os ninjas a serem escolhidos.
 * @return Endereço do ninja que foi escolhido como personagem.
 */
Ninja* escolhe_personagem(t_node* raiz){

    printf("Escolha seu personagem:\n");

    print_personagens(raiz,0);
 
    int p=0;
    printf("Escolha um numero de 1 a 16 : ");
    while(p<1 || p>16){
        scanf("%d",&p);
        if(p<1 || p>16){
            system("clear");
            print_personagens(raiz,0);
            printf("Digite um numero de ninja valido: ");
        }
    }

    system("clear");
    return go_to_ninja(raiz,&p);

}


/**
 * @brief Escolhe 1 dos atributos do ninja que será utilizado na batalha.
 * @breif Também checa a vantagem elemental e impede o ninja de usar um poder recém utilizado.
 * @param personagem Ninja do personagem em que o atributo será escolhido.
 * @param ninja_two Ninja que o personagem batalhará e será comparado as vatagens elementais.
 * @return Retorna o atributo escolhido e modificado de acordo com as circunstâncias da batalha.
 */
int escolhe_atributo(Ninja* personagem,Ninja* ninja1,lista* rec){

    int buff=0; //positivo para vatagem de elemento, negativo para desvantagem

    if(vantagem_elemento(personagem,ninja1)==1){
        personagem->ninjutsu=personagem->ninjutsu*1.2;
        personagem->genjutsu=personagem->genjutsu*1.2;
        personagem->taijutsu=personagem->taijutsu*1.2;
        personagem->defesa=personagem->defesa*1.2;

        buff=4; // vantegem elemental

    }else if(vantagem_elemento(personagem,ninja1)==-1){

        
        personagem->ninjutsu=personagem->ninjutsu*0.8;
        personagem->genjutsu=personagem->genjutsu*0.8;
        personagem->taijutsu=personagem->taijutsu*0.8;
        personagem->defesa=personagem->defesa*0.8;

        buff=-4; // desvantegem elemental
    }
    int atributo=0 + buff; // adiciona no atributo para facilitar na hora de salvar
    int aux_atribute=0;

    elemento_lista* aux = rec->primeiro; // lista de historico (records)


    while(aux!=NULL && aux->ninja != personagem){
        aux=aux->prox;
    }
    // seta o campu usedpower da lista de historico de acordo com o atributo positivo ou negativo
    if(aux==NULL) aux_atribute=0;
    if(aux!=NULL){

        aux_atribute=aux->UsedPower;
        if(aux_atribute<=0) aux_atribute=aux_atribute+4;
        if(aux_atribute>4) aux_atribute=aux_atribute-4;

    }

    // printa os atributos invalidando o ultimo utilizado
    while(atributo<1+buff || atributo>4+buff || (atributo-buff)==aux_atribute){

        printf("Seu Personagem: %s\n",personagem->nome);

        if(buff==4){
            printf("\nVantagem elemental %s > %s\n",personagem->elemento,ninja1->elemento);
            printf("Atributis multiplicados por 1.2\n\n");
        }

        if(buff==-4){
            printf("\nDesvantagem elemental %s < %s\n",personagem->elemento,ninja1->elemento);
            printf("Atributis multiplicados por 0.8\n\n");
        }
        
        if(aux_atribute==1)
            printf("XX) Ninjutsu: XX\n");
        else
            printf("1) Ninjutsu: %d\n",personagem->ninjutsu);

        if(aux_atribute==2)
            printf("XX) Genjutsu: XX\n");
        else
            printf("2) Genjutsu: %d\n",personagem->genjutsu);

        if(aux_atribute==3)
            printf("XX) Taijutsu: XX\n");
        else
        printf("3) Taijutsu: %d\n",personagem->taijutsu);

        if(aux_atribute==4)
            printf("XX) Defesa: XX\n");
        else
        printf("4) Defesa: %d\n",personagem->defesa);


        printf("\nSeu Adversario: %s\n\n",ninja1->nome);

        printf("Selecione seu atributo: ");
        
        
        scanf("%d",&atributo);
        atributo=atributo+buff;

        system("clear");

        if(atributo<1+buff || atributo>4+buff || (atributo-buff) == aux_atribute){

            system("clear");
            printf("Insira um atributo válido\n\n");
        
        }
    }

    return atributo;
    
}


/**
 * @brief Percorre o nível mais baixo posível de batalhas em uma árvore passando para o próximo os ninjas vencedores de cada batalha.
 * @param root Endereço da árvore em que serão feitas as batalhas.
 * @param personagem Endereço do nija personagem.
 * @param Endereço para uma lista aonde será salvo o histórico das batalhas.
 * @param Endereço para uma flago que dirá se o personagem ganhou a sua batalha(1) ou perdeu sua batalha(0).
 * @return Sem retorno.
 */
void batalhas_por_nivel(t_node* root,Ninja* personagem,lista* records,int* flag_won){

    int atributo=0;

    if(root->ninja==NULL){

        // se n existe ninja nos nos filhos
        if(root->left->ninja!=NULL && root->right->ninja!=NULL){

            // filho esquerda é personagem
            if(root->left->ninja==personagem){

                atributo=escolhe_atributo(root->left->ninja,root->right->ninja,records);
                root->ninja=fight(root->left->ninja,root->right->ninja,atributo);
                if(root->ninja==personagem) {
                    *flag_won=1;
                    print_vit(root->left->ninja,root->right->ninja,atributo);
                }
                else {
                    *flag_won=0;
                    print_der(root->left->ninja,root->right->ninja,atributo);
                }
            }
            // filho direito é personagem
            else if(root->right->ninja==personagem){

                atributo=escolhe_atributo(root->right->ninja,root->left->ninja,records);
                root->ninja=fight(root->right->ninja,root->left->ninja,atributo);
                if(root->ninja==personagem) {
                    *flag_won=1;
                    print_vit(root->right->ninja,root->left->ninja,atributo);
                }
                else {
                    *flag_won=0;
                    print_der(root->right->ninja,root->left->ninja,atributo);
                } 
            }

            // nem um dos 2 filhos e personagem
            else{

                atributo=(rand()%4)+1;
                root->ninja=fight(root->left->ninja,root->right->ninja,atributo);

            }

            if(atributo<=0){
                personagem->ninjutsu=personagem->ninjutsu/0.8;
                personagem->genjutsu=personagem->genjutsu/0.8;
                personagem->taijutsu=personagem->taijutsu/0.8;
                personagem->defesa=personagem->defesa/0.8;
            }else if(atributo>4){
                personagem->ninjutsu=personagem->ninjutsu/1.2;
                personagem->genjutsu=personagem->genjutsu/1.2;
                personagem->taijutsu=personagem->taijutsu/1.2;
                personagem->defesa=personagem->defesa/1.2;
            }
                
            // salva o historico
            inserirLista(root->left->ninja,0,records,atributo);
            inserirLista(root->right->ninja,0,records,atributo);

        }

        // recursão para realizar as batalhas no primeiro nivel possivel de se realizar
        batalhas_por_nivel(root->left,personagem,records,flag_won);
        batalhas_por_nivel(root->right,personagem,records,flag_won);
    }

}

/**
 * @brief Imprime o registro das batalhas realizadas.
 * @param rec Endereço da lista de registros.
 * @return Sem retorno.
 */
void print_rec(lista* rec){

    system("clear");

    printf("Hostorico de batalhas:\n\n");

    elemento_lista* aux=rec->ultimo;    
    int cont = 8;
    int cont_start=8;

    // percorre lista e imprime historico
    while(aux!= NULL){

         int elem_flag=0;
         if(aux->UsedPower<=0){
            aux->UsedPower=aux->UsedPower+4;
            elem_flag=-1;
        }
        else if(aux->UsedPower>4){
            aux->UsedPower=aux->UsedPower-4;
            elem_flag=1;
        }

        if(aux->UsedPower==1)
        printf("%s  (Ninjutsu %d) x  %s (Ninjutsu %d) %d",aux->ninja->nome,aux->ninja->ninjutsu,aux->ant->ninja->nome,aux->ant->ninja->ninjutsu,aux->UsedPower);
        else if(aux->UsedPower==2)
        printf("%s  (Genjutsu %d) x  %s (Genjutsu %d) %d",aux->ninja->nome,aux->ninja->genjutsu,aux->ant->ninja->nome,aux->ant->ninja->genjutsu,aux->UsedPower);
        else if(aux->UsedPower==3)
        printf("%s  (Taijutsu %d) x  %s (Taijutsu %d) %d",aux->ninja->nome,aux->ninja->taijutsu,aux->ant->ninja->nome,aux->ant->ninja->taijutsu,aux->UsedPower);
        else if(aux->UsedPower==4)
        printf("%s  (Defesa %d) x  %s (Defesa %d) %d",aux->ninja->nome,aux->ninja->defesa,aux->ant->ninja->nome,aux->ant->ninja->defesa,aux->UsedPower);

        if(elem_flag==-1) 
            printf(" [x0.8]");
        if(elem_flag==1) 
            printf(" [x1.2]");

        printf("\n");
        aux=aux->ant->ant;
        cont--;
        if(cont==0){
            printf("\n");
            cont_start=cont_start/2;
            cont =cont_start;
        }
    }

    printf("\nPressione qualquer tecla para continuar...\n");
    getchar();
    system("clear");

}

/**
 * @brief Responsável por unir as funções principais e realizar o exame chunin da maneira especificada.
 * @parem Sem Parâmetro
 * @return Sem retorno.
 */
void exame(){
    
    t_node* arvore=tree_create();
    lista* list=aloca_lista();
    select_ninjas(list);

    // erro de caso a lista esteja vazia
    if(listaVazia(list)){
        printf("Falha ao tentar carregar os ninjas! Cheque se o arquivo ninjas.txt existe.\n");
        exit(-1);
    }
    // tranfere da lista para arvore
    fill_tree(arvore,list);
    // encerra a lista
    liberaLista(list);
    Ninja* personagem=escolhe_personagem(arvore);
    lista* rec=aloca_lista();
    int flag_won=-1;
    for(int i=0;i<4 && flag_won != 0;i++){
        batalhas_por_nivel(arvore,personagem,rec,&flag_won);
    }
    print_rec(rec);
    liberaLista(rec);
    tree_free(arvore);
}


/**
 * @brief Mostra o menu de navegação do exame chunin
 * @param Sem Parâmetro
 * @return Sem retorno.
 */
int main(){

    srand((int)time(NULL));

    printf("\e[0;33m");

    system("clear");

    int m=0;
    while(m<1 || m>2){

        printf("  _____                             ____ _                 _       \n");
        printf(" | ____|_  ____ _ _ __ ___   ___   / ___| |__  _   _ _ __ (_)_ __  \n");
        printf(" |  _| \\ \\/ / _` | '_ ` _ \\ / _ \\ | |   | '_ \\| | | | '_ \\| | '_ \\ \n");
        printf(" | |___ >  < (_| | | | | | |  __/ | |___| | | | |_| | | | | | | | |\n");
        printf(" |_____/_/\\_\\__,_|_| |_| |_|\\___|  \\____|_| |_|\\__,_|_| |_|_|_| |_|\n");      


        printf("[1]-Comecar exame.\n[2]-Sair.\n");
        scanf("%d",&m);

        if(m==2) return 0;
        else if(m==1) exame();
        
        else {
            system("clear");   
            printf("Digite uma opcao valida !\n\n");
        }    
        m=0;
    }
    return 0;
}