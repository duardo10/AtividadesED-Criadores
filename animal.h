#include "fazenda.h"

typedef struct animal Animal;

Animal *criaListaEncadeadaSimplesAnimais();
Animal *cadastrarAnimal(Animal *rebanho, int num_animal, int id_fazenda);
Animal *permutasAnimais(Fazenda *origem, Fazenda *destino, int id_animal);//obervar para atualizar o status do animal na fazenda de destino
Animal *removerAnimal(Animal *fazenda, int id_animal);

int *quantidadeAnimais(Animal *animais);
float pesoTotalAnimais(Animal *animais);
int buscarAnimal(Animal *rebanho, int id);
Animal *liberarListaAnimais(Animal *animais);

void imprimirAnimal(Animal animal);
void imprimirAnimais(Animal *animais, int head_show, int tipo);
int estaVaziaAnimal(Animal *animais);

/*
Desenvolva funcoes que:

- Funcao para liberar a memoria
*/
