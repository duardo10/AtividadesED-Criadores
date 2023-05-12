#include <stdio.h>
#include <stdlib.h>

#include "animal.h"

struct animal
{
	int id_animal, id_fazenda;
	char sexo; // M ou F
	float peso; //em KG
	int status; // 1 - Nascimento na propria fazenda | 2 - venda | 3 - troca
	struct animal *prox, *ant;
};

Animal *criaListaEncadeadaSimplesAnimais(){
	return NULL;
}

Animal *cadastrarAnimal(Animal *rebanho, int num_animal, int id_fazenda){
	Animal *aux = rebanho, *animal = (Animal*) malloc(sizeof(Animal));
	
	animal->id_animal = rand() % 1000;
	animal->id_fazenda = id_fazenda;
	printf("[Cadastro de Animal Num. %d]\n\n", num_animal);
	printf("Sexo - ");
	scanf("%s", &animal->sexo);
	printf("Peso - ");
	scanf("%f", &animal->peso);
	printf("Status - ");
	scanf("%d", &animal->status);
	
	animal->prox = NULL;
	animal->ant = NULL;
	
	if(aux){
		while(aux->prox)
			aux = aux->prox;
		
		aux->prox = animal;
		animal->ant = aux;
		return rebanho;
	}
	
	return animal;
}

Animal *removerAnimal(Animal *fazenda, int id_animal){
	Animal *aux = fazenda;
	
    while(aux != NULL && aux->id_animal != id_animal){
        aux = aux->prox;
    }
    
    if(aux == NULL){
        return 0;
    }
    
    if(aux->ant == NULL){// remover o primeiro
        fazenda = aux->prox;
    }else{
        aux->ant->prox = aux->prox;
    }
    
    if(aux->prox != NULL){
        aux->prox->ant = aux->ant;
    }
    
    free(aux);
    return fazenda;
}

int *quantidadeAnimais(Animal *animais){
	Animal *aux = animais;
	int *cont = (int*) calloc(2, sizeof(int));
	
	if(aux){
		while(aux){
			if(aux->sexo == 'M') cont[0]++;
			if(aux->sexo == 'F') cont[1]++;
			aux = aux->prox;
		}
	}
	
	return cont;
}

float pesoTotalAnimais(Animal *animais){
	Animal *aux = animais;
	float somatorio = 0;
	
	if(aux){
		while(aux){
			somatorio += aux->peso;
			aux = aux->prox;
		}
	}
	
	return somatorio / 15;
}

int buscarAnimal(Animal *rebanho, int id){
	Animal *aux = rebanho;
	
	if(rebanho == NULL)
		return 0;
	
	while(aux != NULL && aux->id_animal != id)
        aux = aux->prox;
        
	if(aux == NULL)
		return 0;
	
	return aux->id_animal;
}

void imprimirAnimal(Animal animal){
	printf("%-13d%-13d%-10c%-10.2f%-10d\n", animal.id_animal, animal.id_fazenda, animal.sexo, animal.peso, animal.status);
}

void imprimirAnimais(Animal *animais, int head_show, int tipo){
	Animal *aux = animais;
	
	if(aux){
		if(head_show)
			printf("Lista Animais:\n%-13s%-13s%-10s%-10s%-10s\n", "ID-Animal", "ID-Fazenda", "Sexo", "Peso", "Status");
			
		while(aux){
			if(aux->status == tipo || !tipo)
				imprimirAnimal(*aux);
				
			aux = aux->prox;
		}
	}
}

int estaVaziaAnimal(Animal *animais){
	if(!animais)
		return 1;
	else
		return 0;
}

Animal *liberarListaAnimais(Animal *animais){
	Animal *prox, *aux = animais;

	if(aux){
		while(aux){
			prox = aux->prox;
			free(aux);
			aux = prox;
		}
	}
	
	return NULL;
}

