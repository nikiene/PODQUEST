#pragma once

#include "linkedlist.h"

//Função auxiliar que troca '\n' por '\0' (thx @Yarquen! :D)
void remove_newline_ch(char* line) {
	int new_line = strlen(line) - 1;
	if (line[new_line] == '\n')
	{
		line[new_line] = '\0';
	}
}

/**
* @brief Função que aloca um espaço do tamanho de uma Playlist na memória
* @return novaPlaylist, a nova Playlist com os apontamentos de memória para o início, fim e atual apontando para NULL
*/
Playlist* llcriaPlaylist() {

	Playlist* novaPlaylist = (Playlist*)malloc(sizeof(Playlist));

	novaPlaylist->inicio = NULL;
	novaPlaylist->atual = NULL;
	novaPlaylist->fim = NULL;

	return novaPlaylist;
}


/**
* @brief Função que aloca um espaço do tamanho de uma lista de PalavraChave na memória 
* @return novaPalavrasChave, a nova lista de PalavraChave com os apontamentos de memória para o início e fim apontando para NULL
*/
PalavrasChave* criaPalavrasChave() {

	PalavrasChave* novaPalavrasChave = (PalavrasChave*)malloc(sizeof(PalavrasChave));

	novaPalavrasChave->inicio = NULL;
	novaPalavrasChave->fim = NULL;

	return novaPalavrasChave;
}

/**
* @brief Função que aloca um espaço do tamanho de uma PalavraChave na memória (dados dessa PalavraChave serão pedidos nessa função)
* @return novaPalavrasChave, a nova PalavraChave com os apontamentos de memória para o próximo apontando para NULL
*/
PalavraChave* criaPalavraChave() {
	
	PalavraChave* novaPalavraChave = (PalavraChave*)malloc(sizeof(PalavraChave));

	printf("\nPalavra-chave: ");
	fgets(novaPalavraChave->categoria, 64, stdin);
	remove_newline_ch(novaPalavraChave->categoria);

	novaPalavraChave->proxima = NULL;
	novaPalavraChave->anterior = NULL;

	return novaPalavraChave;
}

/**
* @brief adiciona uma palavra-chave no fim da lista de palavras-chave
* @param palavrasChave -> Lista de palavras-chave
* @return 1 -> se mais palavras vão ser inseridas
* @return 0 -> se mais palavras vão ser inseridas
*/
int adicionaPalavraChave(PalavrasChave* palavrasChave) {

	int continuar = 0;

	PalavraChave* novaPalavraChave = criaPalavraChave();

	if (palavrasChave->inicio == NULL)
	{
		palavrasChave->inicio = novaPalavraChave;
		palavrasChave->fim = novaPalavraChave;

		printf("\nDeseja inserir uma palavra-chave para esse podquest? \n| 1 - Sim  \n| 0 - Nao\n\n");
		scanf_s("%d", &continuar);
		getchar();
		
		if (continuar == 1)
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}

	palavrasChave->fim->proxima = novaPalavraChave;
	novaPalavraChave->anterior = palavrasChave->fim;
	palavrasChave->fim = novaPalavraChave;

	printf("\nDeseja inserir mais uma palavra-chave para esse podquest? \n| 1 - Sim  \n| 0 - Nao\n\n");
	scanf_s("%d", &continuar);
	getchar();

	if (continuar == 1)
	{
		return 1;
	}
	else
	{
		return 0;
	}

	return 0;
}

/**
* @brief Função que aloca um espaço do tamanho de um Podquest na memória (dados desse Podquest serão pedidos nessa função)
* @return novoPodquest, a nova Playlist com os apontamentos de memória para o próximo e anterior apontando para NULL
*/
Podquest criaPodquest() {

	Podquest novoPodquest = (Podquest)malloc(sizeof(Podcast));

	printf("Inserindo Podquest:\n");

	printf("\n	Id do Podcast: ");
	scanf_s("%d", &novoPodquest->podcastId);
	getchar();

	printf("\n	Nome do Podcast: ");
	fgets(novoPodquest->nomePodcast, 64, stdin);
	remove_newline_ch(novoPodquest->nomePodcast);

	printf("\n	Nome do Episodio: ");
	fgets(novoPodquest->nomeEpisodio, 64, stdin);
	remove_newline_ch(novoPodquest->nomeEpisodio);

	printf("\n	Numero do Episodio: ");
	scanf_s("%d", &novoPodquest->numeroEpisodio);
	getchar();


	PalavrasChave* novaListaPalavrasChave = criaPalavrasChave();
	novoPodquest->palavrasChave = novaListaPalavrasChave;

	int continuar = adicionaPalavraChave(novaListaPalavrasChave);

	while (continuar)
	{
		continuar = adicionaPalavraChave(novaListaPalavrasChave);
		if (continuar == 0)
		{
			break;
		}
	}

	novoPodquest->proximo = NULL;
	novoPodquest->anterior = NULL;

	return novoPodquest;
}

/**
* @brief adiciona um Podquest na Playlist ordenado pelo ID
* @param playlist -> Lista de Podquest
*/
void llInserePodquestOrdenado(Playlist* playlist) {

	Podquest novoPodquest = criaPodquest();
	
	if (playlist->inicio == NULL)
	{
		playlist->inicio = novoPodquest;
		playlist->fim = novoPodquest;

		return;
	}
	else if (novoPodquest->podcastId > playlist->fim->podcastId)
	{
		playlist->fim->proximo = novoPodquest;
		novoPodquest->anterior = playlist->fim;
		playlist->fim = novoPodquest;

		return;
	}
	else
	{
		Podquest aux = playlist->inicio;

		while (aux->proximo->podcastId <= novoPodquest->podcastId)
		{
			aux = aux->proximo;
		}

		while (aux->proximo->numeroEpisodio <= novoPodquest->numeroEpisodio)
		{
			aux = aux->proximo;
		}

		novoPodquest->proximo = aux->proximo;
		aux->proximo = novoPodquest;
		novoPodquest->anterior = aux;
	}
}

/**
* @brief adiciona um Podquest no final da Playlist
* @param playlist -> Lista de Podquest
*/
void llInserePodquestFim(Playlist* playlist) {

	Podquest novoPodquest = criaPodquest();

	if (playlist->inicio == NULL)
	{
		playlist->inicio = novoPodquest;
		playlist->fim = novoPodquest;

		return;
	}

	playlist->fim->proximo = novoPodquest;
	novoPodquest->anterior = playlist->fim;
	playlist->fim = novoPodquest;
}

/**
* @brief Função que verifica se um Podquest existe na Playlist, e caso exista, o retorna
* @param playlist -> Playlist na qual vai acontecer a busca
* @param idBusca -> Id do Podquest que vai ser buscado
* @param epsBusca -> Episodio do Podquest que vai ser buscado
* @return aux -> O Podquest buscaso
* @return NULL -> Caso o Podquest não exista na lista
*/
Podquest llBuscaPodquest(Playlist* playlist, int idBusca, int epsBusca) {

	for (Podquest aux = playlist->inicio; aux != NULL; aux = aux->proximo)
	{
		if (aux->podcastId == idBusca && aux->numeroEpisodio == epsBusca) 
		{
			return aux;
		}
	}

	return NULL;
}

/**
* @brief Função que busca um elemento na lista e se o encontrar, o remove
* @param playlist -> Playlist a qual vai ter o Podquest removido
*/
void llremovePodquest(Playlist* playlist) {
	
	int idBusca = 0, epsBusca = 0;

	printf("\nInsira o Id do Podquest a ser removido: ");
	scanf_s("%d", &idBusca);

	printf("\nInsira o numero do episodio a ser removido: ");
	scanf_s("%d", &epsBusca);

	Podquest buscado = llBuscaPodquest(playlist, idBusca, epsBusca);

	if (buscado != NULL)
	{
		if (buscado == playlist->inicio)
		{
			Podquest inicioRemovido = playlist->inicio;

			playlist->inicio = playlist->inicio->proximo;
			playlist->inicio->anterior = NULL;

			free(inicioRemovido);
		}
		else if (buscado == playlist->fim)
		{
			Podquest fimRemovido = playlist->fim;

			playlist->fim = playlist->fim->anterior;
			playlist->fim->proximo = NULL;

			free(fimRemovido);
		}
		else
		{
			buscado->proximo->anterior = buscado->anterior;
			buscado->anterior->proximo = buscado->proximo;

			free(buscado);
		}
	}
}

/**
* @brief Função que começa a tocar a playlist
* @param playlist -> Playlist que vai ser tocada
*/
void lltocar(Playlist* playlist) {

	if (playlist->inicio != NULL)
	{
		playlist->atual = playlist->inicio;

		printf("\n- Now Playing:");
		printf("\n- %d. %s", playlist->atual->podcastId, playlist->atual->nomePodcast);
		printf("\n	- %d - %s", playlist->atual->numeroEpisodio, playlist->atual->nomeEpisodio);
	}
	else
	{
		printf("\nA Playlist esta vazia!\n\n");
	}
}

