#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "fazenda.h"
#include "animal.h"

struct endereco
{
	char cidade[50], estado[3], logradouro[200];
};

struct fazenda
{
	int id_criador, id_fazenda;
	char nome[100];
	Endereco localizacao;
	float valor_fazenda;//lembrar de atualizar o valor sempre que houver alterações no rebanho
	Animal *rebanho; // ponteiro para uma lista (verificar no .h do animal que lista é)
	//ponteiro para permitir o apontamento para o proximo elemento da lista (deve ser circular)
	struct fazenda *prox;
};

Fazenda *criarListaEncadeadaCircularFazendas(){
	return NULL;
}

Endereco criarEndereco(){
	Endereco end;
	
	printf("Cidade - ");
	scanf("%s", end.cidade);
	printf("Estado - ");
	scanf("%s", end.estado);
	printf("Logradouro - ");
	scanf("%s", end.logradouro);
	return end;
}

Fazenda *cadastrarFazenda(Fazenda *fazendas, int num_fazenda, char *nome_criador, int id_criador){
	Fazenda *aux = fazendas, *fazenda = (Fazenda*) malloc(sizeof(Fazenda));
	Animal *animal_lista = (Animal*) criaListaEncadeadaSimplesAnimais();
	int i, opc;
	
	printf("[Cadastro de Fazenda Num. %d]\n\n", num_fazenda);
	fazenda->id_fazenda = rand() % 1000 + 1;
	fazenda->id_criador = id_criador;
	printf("Nome da Fazenda - ");
	scanf("%s", fazenda->nome);
	fazenda->localizacao = criarEndereco();
	printf("Numero de animais a cadastrar - ", num_fazenda);
	scanf("%d", &opc);
	
	for(i = 1; i <= opc; i++)
		animal_lista = cadastrarAnimal(animal_lista, i, fazenda->id_fazenda);
	
	fazenda->rebanho = animal_lista;
	fazenda->valor_fazenda = ValorTotFazenda(*fazenda);
	
	if(aux){
		while(aux->prox != fazendas)
			aux = aux->prox;
		
		fazenda->prox = fazendas;
		aux->prox = fazenda;
		return fazendas;
	}
	
	fazenda->prox = fazenda;
	return fazenda;
}

Fazenda *removerFazenda(Fazenda *fazendas, int id){
	Fazenda *aux = fazendas;
    Fazenda *ant;
    if(aux->id_fazenda == id){
        printf("O valor e igual");
        if(aux == aux->prox){
            free(aux);
            fazendas = NULL;
            printf("Removeu");
            return fazendas;
        }else{
            Fazenda *ultimo = fazendas;
            while(ultimo->prox != fazendas){
                ultimo = ultimo->prox;
            }
            ultimo->prox = fazendas->prox;
            fazendas = fazendas->prox;
            free(aux);
            printf("Removeu");
            return fazendas;
        }
    }
    ant = aux;
    aux = aux->prox;
    while(aux != fazendas && aux->id_fazenda != id){
        ant = aux;
        aux = aux->prox;
    }
    if(aux == fazendas){
        printf("fazenda nao encontrada\n");
        return 0;
    }
    ant->prox = aux->prox;
    free(aux);
    return fazendas;
    
}

void alterarFazenda(Fazenda *fazendas, int id){
	Fazenda *aux = fazendas;
	
	for(aux; aux->id_fazenda != id; aux = aux->prox);
	
    if(fazendas == NULL)
        return;
    
    printf("Novo Nome - ");
    scanf("%s", aux->nome);
    printf("Nova Cidade - ");
    scanf("%s", aux->localizacao.cidade);
    printf("Novo Estado - ");
    scanf("%s", aux->localizacao.estado);
    printf("Novo Logradouro - ");
    scanf("%s", aux->localizacao.logradouro);
}

int buscarFazenda(Fazenda *fazendas, int id){
	Fazenda *aux = fazendas;
	
	while(aux->prox != fazendas && aux->id_fazenda != id)
        aux = aux->prox;
        
    if(aux->id_fazenda == id){
        return aux->id_fazenda;
    } else {
        return 0;
    }
}

int *quantidadeAnimaisFazenda(Fazenda *fazenda){
	Fazenda *aux = fazenda;
	int *cont_fazenda = (int*) calloc(2, sizeof(int)), *cont = (int*) calloc(2, sizeof(int));
	
	if(aux){
		cont = quantidadeAnimais(aux->rebanho);
		cont_fazenda[0] += cont[0];
		cont_fazenda[1] += cont[1];
		
		while(aux != fazenda){
			cont = quantidadeAnimais(aux->rebanho);
			cont_fazenda[0] += cont[0];
			cont_fazenda[1] += cont[1];
		}
	}
	
	return cont_fazenda;
}

float ValorTotFazenda(Fazenda fazenda){
    return pesoTotalAnimais(fazenda.rebanho) * 267.5;
}

void imprimirFazenda(Fazenda fazenda){
	printf("%-13d%-13d%-13s%-13.2f%-13s%-8s%-20s\n", fazenda.id_criador, fazenda.id_fazenda, fazenda.nome, fazenda.valor_fazenda, fazenda.localizacao.cidade, fazenda.localizacao.estado, fazenda.localizacao.logradouro);
}

int imprimirFazendas(Fazenda *fazendas, int mostrar_animais, int head_show){
	Fazenda *aux = fazendas;
	
	if(aux){
		if(head_show){
			if(head_show != -1)
				printf("%-13s%-13s%-13s%-13s%-13s%-8s%-13s\n", "ID-Criador", "ID-Fazenda", "Nome", "Valor", "Cidade", "Estado", "Logradouro");
				
			imprimirFazenda(*aux);
			aux = aux->prox;
			
			while(aux != fazendas){
				imprimirFazenda(*aux);
				aux = aux->prox;
			}
		}
		
		if(mostrar_animais){
			aux = fazendas;
			imprimirAnimais(aux->rebanho, 0, 0);
			aux = aux->prox;
			
			while(aux != fazendas){
				imprimirAnimais(aux->rebanho, 0, 0);
				aux = aux->prox;
			}
		}
		
		return 1;
	} else
		printf("[Nao ha fazendas cadastradas.]\n");
	
	return 0;
}

void menuFazenda(){
	printf("[Selecione uma opcao]\n"
		   "1 - Cadastrar Animal\n"
		   "2 - Remover Animal\n"
		   "3 - Limpar Lista de Animais\n"
		   "4 - Imprimir Lista de Animais\n\n"
		   "0 - Fechar Criador\n\n");
}

void acessarFazenda(Fazenda *fazendas, int id){
	Fazenda *aux = fazendas;
	int opc, id_fazenda, id_animal, encontrou, num = 1;
	
	for(aux; aux->id_fazenda != id; aux = aux->prox);
	
	menuFazenda();
	printf("[-1 Menu]-> ");
	scanf("%d", &opc);
	system("cls");
	
	while(opc){
		switch(opc){
			case 1:
				while(opc){
					aux->rebanho = cadastrarAnimal(fazendas->rebanho, num++, aux->id_fazenda);
					printf("[Cadastrar outro animal?] (0 - Nao/1 - Sim)-> ");
					scanf("%d", &opc);
				}
				
				aux->valor_fazenda = ValorTotFazenda(*aux);
				num = 1;
				system("cls");
				break;
			case 2:
				while(opc){
					if(!estaVaziaAnimal(aux->rebanho)){
						imprimirAnimais(aux->rebanho, 1, 0);
						printf("\n[Informe o ID do Animal] (0 para Sair)-> ");
						scanf("%d", &id_animal);
						
						if(!id_animal){
							system("cls");
							break;
						}
						
						encontrou = buscarAnimal(aux->rebanho, id_animal);
						
						if(encontrou)
							aux->rebanho = removerAnimal(aux->rebanho, id_animal);
						else {
							printf("\n[Animal nao encontrado! Tentar Novamente?] (0 - Nao/1 - Sim)-> ");
							scanf("%d", &opc);
						}
					} else {
						printf("[Sem cadastros...]\n");
						break;
					}
					
					system("cls");
				}
				
				break;
			case 3:
				if(!estaVaziaAnimal(aux->rebanho)){
					imprimirAnimais(aux->rebanho, 1, 0);
					printf("\n[Apagar todos os cadastros! Tem certeza?] (0 - Nao/1 - Sim)-> ");
					scanf("%d", &opc);
					
					if(opc){
						aux->rebanho = liberarListaAnimais(aux->rebanho);
						system("cls");
						printf("[Lista Esvaziada]\n");
					} else {
						system("cls");
						printf("[Cancelado]\n");
					}
				} else
					printf("[Sem cadastros...]\n");
					
				break;
			case 4:
				if(!estaVaziaAnimal(aux->rebanho)){
					printf("Informe o tipo de Status (0 para qualque tipo) - ");
					scanf("%d", &opc);
					imprimirAnimais(aux->rebanho, 1, opc);
					printf("\n");
					system("pause");
					system("cls");
				} else {
					system("cls");
					printf("[Sem cadastros...]\n");
				}
				
				break;
			default:
				printf("[Opcao Invalida!]\n");
		}
		
		menuFazenda();
		printf("[-1 Menu]-> ");
		scanf("%d", &opc);
		system("cls");
	}
}

int estaVaziaFazenda(Fazenda *fazendas){
	if(!fazendas)
		return 1;
	else
		return 0;
}

Fazenda *liberarListaFazendas(Fazenda *fazendas){
	Fazenda *limpar, *aux = fazendas;
	
	if(aux){
		liberarListaAnimais(aux->rebanho);
		limpar = aux;
		aux = aux->prox;
		free(limpar);
		
		while(aux != fazendas){
			liberarListaAnimais(aux->rebanho);
			aux = aux->prox;
			free(limpar);
		}
	}
	
	return NULL;
}

