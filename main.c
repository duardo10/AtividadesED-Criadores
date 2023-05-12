#include <stdio.h>
#include <stdlib.h>
#include "criador.h"

void menuPricipal();

int main() {
	Criador *listaCriadores = criarListaDuplaCriadores();
	int opc, id, encontrou, *sexos;
	
	menuPricipal();
	printf("[-1 Menu]-> ");
	scanf("%d", &opc);
	system("cls");
	
	while(opc){
		switch(opc){
			case -1:
				menuPricipal();
				break;
			case 1:
				while(opc){
					if(!estaVaziaCriador(listaCriadores)){
						imprimirCriadores(listaCriadores);
						printf("\n[Informe o ID do Criador] (0 para Sair)-> ");
						scanf("%d", &id);
						
						if(!id){
							system("cls");
							break;
						}
						
						encontrou = buscarCriador(listaCriadores, id);
						
						if(encontrou){
							system("cls");
							acessarCriador(listaCriadores, id);
						} else {
							printf("\n[Criador nao encontrado! Tentar Novamente?] (0 - Nao/1 - Sim)-> ");
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
				listaCriadores = cadastrarCriador(listaCriadores);
				system("cls");
				printf("[Criador Cadastrado!]\n");
				break;
			case 3:
				while(opc){
					if(!estaVaziaCriador(listaCriadores)){
						imprimirCriadores(listaCriadores);
						printf("\n[Informe o ID do Criador] (0 para Sair)-> ");
						scanf("%d", &id);
						
						if(!id){
							system("cls");
							break;
						}
						
						encontrou = buscarCriador(listaCriadores, id);
						
						if(encontrou)
							listaCriadores = removerCriador(listaCriadores, id);
						else {
							printf("\n[Criador nao encontrado! Tentar Novamente?] (0 - Nao/1 - Sim)-> ");
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
				if(!estaVaziaCriador(listaCriadores)){
					imprimirCriadores(listaCriadores);
					printf("\n[Apagar todos os cadastros! Tem certeza?] (0 - Nao/1 - Sim)-> ");
					scanf("%d", &opc);
					
					if(opc){
						listaCriadores = liberarListaCriador(listaCriadores);
						system("cls");
						printf("[Lista Esvaziada]\n");
					} else {
						system("cls");
						printf("[Cancelado]\n");
					}
				} else
					printf("[Sem cadastros...]\n");
				break;
			case 5:
				if(!estaVaziaCriador(listaCriadores)){
					imprimirCriadores(listaCriadores);
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
		
		menuPricipal();
		printf("[-1 Menu]-> ");
		scanf("%d", &opc);
		
		if(opc != 0)
			system("cls");
	}
	
	printf("\n[Fim do Programa]\n");
	
	return 0;
}

void menuPricipal(){
	printf("[Selecione uma opcao]\n"
		   "1 - Acessar Criador\n"
		   "2 - Cadastrar Criador\n"
		   "3 - Remover Criador\n"
		   "4 - Limpar Lista de Criadores\n"
		   "5 - Imprimir Lista de Criadores\n\n"
		   "0 - Sair\n\n");
}

