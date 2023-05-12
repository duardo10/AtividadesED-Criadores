#include <stdio.h>
#include <stdlib.h>

#include "criador.h"
#include "fazenda.h"
#include "animal.h"

struct criador
{
	int id_criador;
	char nome[100];
	float patrimonio; //esse valor deve ser constantemente modificado para que o valor esteja atualizado
	Fazenda *fazendas;//Esse ponteiro e uma lista circular (atentem-se)
	struct criador *prox, *ant; //lista dupla encadeada, nao é necessário ser circular
};

Criador *criarListaDuplaCriadores(){
	return NULL;
}

Criador *cadastrarCriador(Criador *criadores){
	Criador *aux = criadores, *criador = (Criador*) malloc(sizeof(Criador));
	Fazenda *fazenda_lista = (Fazenda*) criarListaEncadeadaCircularFazendas();
	int i, opc;
	
	criador->id_criador = rand() % 1000 + 1;
	printf("[Preencha os campos para completar o cadastro]\n\n");
	printf("Nome - ");
	scanf("%s", criador->nome);
	printf("Patrimonio - ");
	scanf("%f", &criador->patrimonio);
	printf("Numero de Fazendas do propriterio - ");
	scanf("%d", &opc);
	
	for(i = 1; i <= opc; i++)
		fazenda_lista = cadastrarFazenda(fazenda_lista, i, criador->nome, criador->id_criador);
	
	criador->fazendas = fazenda_lista;
	criador->prox = NULL;
	criador->ant = NULL;
	
	if(aux){
		while(aux->prox)
			aux = aux->prox;
		
		aux->prox = criador;
		criador->ant = aux;
		return criadores;
	}
	
	return criador;
}

//Criador *removerCriador(Criador *criadores, int id){
//	Criador *aux = criadores;
//	
//	while(aux != NULL && aux->id_criador != id)
//        aux = aux->prox;
//        
//    if(aux == NULL)
//        return 0;
//    
//    if(aux->ant == NULL){// remover o primeiro
//        criadores = aux->prox;
//    }else if(aux->prox == NULL){// remover o último
//    	aux->ant->prox = NULL;
//	}
//    
//	if(aux->prox != NULL){
//		aux->prox->ant = aux->ant;
//		aux->ant->prox = aux->prox;
//	}
//    
//    free(aux);
//    return criadores;
//}

Criador *removerCriador(Criador *criadores, int id){
	Criador *aux = criadores;
	
    while(aux != NULL && aux->id_criador != id)
        aux = aux->prox;
        
    if(aux == NULL)
        return 0;
    
    if(aux->ant == NULL){// remover o primeiro
        criadores = aux->prox;
    }else{
        aux->ant->prox = aux->prox;
    }
    
	if(aux->prox != NULL)
        aux->prox->ant = aux->ant;
    
    free(aux);
    return criadores;
}

int buscarCriador(Criador *criadores, int id){
	Criador *aux = criadores;
	
	if(criadores == NULL)
		return 0;
	
	while(aux != NULL && aux->id_criador != id)
        aux = aux->prox;
        
	if(aux == NULL)
		return 0;
	
	return aux->id_criador;
}

int *quantidadeAnimaisCriador(Criador *criadores){
	Criador *aux = criadores;
	int *cont_fazendas, *cont = (int*) calloc(2, sizeof(int));
	
	if(aux){
		while(aux){
			cont_fazendas = quantidadeAnimaisFazenda(aux->fazendas);
			cont[0] += cont_fazendas[0];
			cont[1] += cont_fazendas[1];
			aux = aux->prox;
		}
	}
	
	return cont;
}

float patrimonioCriador(Criador criador){
	return criador.patrimonio;
}

void imprimirCriador(Criador criador){
	printf("%-13d%-10s%-10.2f\n", criador.id_criador, criador.nome, patrimonioCriador(criador));
}

int imprimirCriadores(Criador *criadores){
	Criador *aux = criadores;
	Fazenda *aux_fazenda;
	
	if(aux){
		printf("Lista de Animais:\n%-13s%-13s%-10s%-10s%-10s\n", "ID-Animal", "ID-Fazenda", "Sexo", "Peso", "Status");
		
		while(aux){
			if(aux->fazendas)
				imprimirFazendas(aux->fazendas, 1, 0);
			else
				printf("[Nao ha animais cadastrados.]\n");
				
			aux = aux->prox;
		}
		
		aux = criadores;
		printf("\nLista de Fazendas:\n%-13s%-13s%-13s%-13s%-13s%-8s%-13s\n", "ID-Criador", "ID-Fazenda", "Nome", "Valor", "Cidade", "Estado", "Logradouro");
		
		while(aux){
			imprimirFazendas(aux->fazendas, 0, -1);
			aux = aux->prox;
		}
		
		aux = criadores;
		printf("\nLista de Criadores:\n%-13s%-10s%-10s\n", "ID-Criador", "Nome", "Patrimonio");
		
		while(aux){
			imprimirCriador(*aux);
			aux = aux->prox;
		}
		
		return 1;
	}
	
	return 0;
}

void menuCriador(Criador criador){
	printf("ID-Criador: %d\n"
		   "Nome: %s\n"
		   "Patrimonio: %.2f\n\n"
		   
		   "[Selecione uma opcao]\n"
		   "1 - Acessar Fazenda\n"
		   "2 - Cadastrar Fazenda\n"
		   "3 - Remover Fazenda\n"
		   "4 - Alterar Fazenda\n"
		   "5 - Quantidade de Animais\n"
		   "6 - Limpar Lista de Fazendas\n"
		   "7 - Imprimir Lista de Fazendas\n\n"
		   "0 - Fechar Criador\n\n", criador.id_criador, criador.nome, patrimonioCriador(criador));
}

void acessarCriador(Criador *criadores, int id){
	Criador *aux = criadores;
	int opc, num = 1, id_fazenda, encontrou, *sexos = (int*) calloc(2, sizeof(int));
	
	for(aux; aux->id_criador != id; aux = aux->prox);
	
	menuCriador(*aux);
	printf("[-1 Menu]-> ");
	scanf("%d", &opc);
	system("cls");
	
	while(opc){
		switch(opc){
			case -1:
				menuCriador(*aux);
				break;
			case 1:
				while(opc){
					if(!estaVaziaFazenda(aux->fazendas)){
						imprimirFazendas(aux->fazendas, 0, 1);
						printf("\n[Informe o ID da Fazenda] (0 para Sair)-> ");
						scanf("%d", &id_fazenda);
						
						if(!id_fazenda){
							system("cls");
							break;
						}
						
						encontrou = buscarFazenda(aux->fazendas, id_fazenda);
						
						if(encontrou){
							system("cls");
							acessarFazenda(aux->fazendas, id_fazenda);
						} else {
							printf("\n[Fazenda nao encontrada! Tentar Novamente?] (0 - Nao/1 - Sim)-> ");
							scanf("%d", &opc);
						}
					} else {
						printf("[Sem cadastros...]\n");
						break;
					}
					
					system("cls");
				}
				
				break;
			case 2:
				while(opc){
					cadastrarFazenda(aux->fazendas, num++, aux->nome, aux->id_criador);
					printf("[Cadastrar outra Fazenda?] (0 - Nao/1 - Sim)-> ");
					scanf("%d", &opc);
				}
				
				num = 1;
				system("cls");
				break;
			case 3:
				while(opc){
					if(!estaVaziaFazenda(aux->fazendas)){
						imprimirFazendas(aux->fazendas, 0, 1);
						printf("\n[Informe o ID da Fazenda] (0 para Sair)-> ");
						scanf("%d", &id_fazenda);
						
						if(!id_fazenda){
							system("cls");
							break;
						}
						
						encontrou = buscarFazenda(aux->fazendas, id_fazenda);
						
						if(encontrou)
							aux->fazendas = removerFazenda(aux->fazendas, id_fazenda);
						else {
							printf("\n[Fazenda nao encontrada! Tentar Novamente?] (0 - Nao/1 - Sim)-> ");
							scanf("%d", &opc);
						}
					} else {
						printf("[Sem cadastros...]\n");
						break;
					}
					
					system("cls");
				}
				
				break;
			case 4:
				while(opc){
					if(!estaVaziaFazenda(aux->fazendas)){
						imprimirFazendas(aux->fazendas, 0, 1);
						printf("\n[Informe o ID da Fazenda] (0 para Sair)-> ");
						scanf("%d", &id_fazenda);
						
						if(!id_fazenda){
							system("cls");
							break;
						}
						
						encontrou = buscarFazenda(aux->fazendas, id_fazenda);
						
						if(encontrou)
							alterarFazenda(aux->fazendas, id_fazenda);
						else {
							printf("\n[Fazenda nao encontrada! Tentar Novamente?] (0 - Nao/1 - Sim)-> ");
							scanf("%d", &opc);
						}
					} else {
						printf("[Sem cadastros...]\n");
						break;
					}
					
					system("cls");
				}
				
				break;
			case 5:
				if(!estaVaziaFazenda(aux->fazendas)){
					sexos = quantidadeAnimaisFazenda(aux->fazendas);
					printf("Quantidade de animais do sexo M: [%d]\nQuantidade de animais do sexo F: [%d]\n\n", sexos[0], sexos[1]);
					system("pause");
					system("cls");
				} else {
					system("cls");
					printf("[Sem cadastros...]\n");
				}
				
				break;
			case 6:
				if(!estaVaziaFazenda(aux->fazendas)){
					imprimirFazendas(aux->fazendas, 0, 1);
					printf("\n[Apagar todos os cadastros! Tem certeza?] (0 - Nao/1 - Sim)-> ");
					scanf("%d", &opc);
					
					if(opc){
						aux->fazendas = liberarListaFazendas(aux->fazendas);
						system("cls");
						printf("[Lista Esvaziada]\n");
					} else {
						system("cls");
						printf("[Cancelado]\n");
					}
				} else
					printf("[Sem cadastros...]\n");
					
				break;
			case 7:
				if(!estaVaziaFazenda(aux->fazendas)){
					imprimirFazendas(aux->fazendas, 0, 1);
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
		
		menuCriador(*aux);
		printf("[-1 Menu]-> ");
		scanf("%d", &opc);
		system("cls");
	}
}

int estaVaziaCriador(Criador *criadores){
	if(!criadores)
		return 1;
	else
		return 0;
}

Criador *liberarListaCriador(Criador *criadores){
	Criador *limpar, *aux = criadores;
	
	if(aux){
		while(aux){
			liberarListaFazendas(aux->fazendas);
			limpar = aux;
			aux = aux->prox;
			free(limpar);
		}
	}
	
	return NULL;
}

