#include "criador.h"

typedef struct fazenda Fazenda;
typedef struct endereco Endereco;

Fazenda *criarListaEncadeadaCircularFazendas();
Fazenda *cadastrarFazenda(Fazenda *fazendas, int num_fazenda, char *nome_criador, int id_criador);
Fazenda *removerFazenda(Fazenda *fazendas, int id);//nao permitir remover fazenda se houver animais cadastrados
void alterarFazenda(Fazenda *fazendas, int id);//alterar dados cadastrais da fazenda. exemplo: nome e endereco; 
int buscarFazenda(Fazenda *fazendas, int id);

int *quantidadeAnimaisFazenda(Fazenda *fazenda);
float ValorTotFazenda(Fazenda fazenda);
Fazenda *liberarListaFazendas(Fazenda *fazendas);

void imprimirFazenda(Fazenda fazenda);
int imprimirFazendas(Fazenda *fazendas, int mostrar_animais, int head_show);
void menuFazenda();
void acessarFazenda(Fazenda *fazendas, int id);
int estaVaziaFazenda(Fazenda *fazendas);

/*
Desenvolva funcoes que, dado uma FAZENDA, informar:
- Quantidade de animais por sexo;
- Peso total em arroba (isto é, a cada 15 KG) float pesoTotalAnimais(Animal *animais);
- Valor total da fazenda considerando o preço da arroba de R$ 267,50 float ValorTotFazenda(Fazenda fazenda);
- lista de animais por tipo de status
- Funcao para liberar a memoria
*/
