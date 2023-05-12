typedef struct criador Criador;

Criador *criarListaDuplaCriadores();
Criador *cadastrarCriador(Criador *criadores);
Criador *removerCriador(Criador *criadores, int id);//nao é permitido remover criador com fazendas cadastradas
int buscarCriador(Criador *criadores, int id);

int *quantidadeAnimaisCriador(Criador *criadores);
float patrimonioCriador(Criador criador);
Criador *liberarListaCriador(Criador *criadores);

void imprimirCriador(Criador criador);
int imprimirCriadores(Criador *criadores);
void menuCriador(Criador criador);
void acessarCriador(Criador *criadores, int id);
int estaVaziaCriador(Criador *criadores);

/*
Desenvolva funçoes para:
- Retornar o patrimonio do criador (esse valor deve sempre estar atualizado)
- Funcao para mostrar cada criador e todos os seus respectivos atributos
- Funcao para liberar a memoria
*/
