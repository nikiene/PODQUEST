#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Definição das palavras-chave, cada uma vai ter uma string e um apontamento para uma próxima, caso existir
typedef struct palavraChave
{
	char categoria[64];
	struct palavraChave* proxima;
	struct palavraChave* anterior;

} PalavraChave;

//Definindo que uma Lista de Palavras-chave.
typedef struct palavrasChave {

	PalavraChave* inicio;
	PalavraChave* fim;

} PalavrasChave;

//Definição do meu podcast, vai possuir um id, uma string nome(podcast), uma string nome(episódio) e um numero do episódio
typedef struct podcast
{
	int podcastId;
	char nomePodcast[64];
	char nomeEpisodio[64];
	int numeroEpisodio;

	PalavrasChave* palavrasChave;

	struct podcast* proximo;
	struct podcast* anterior;

} Podcast;

//Definindo que um ponteiro para um Podcast vai se chamar Podquest
typedef Podcast* Podquest;

//Definição da minha lista, possuindo 3 ponteiros: início, atual e fim
typedef struct playlist
{
	Podquest inicio;
	Podquest atual;
	Podquest fim;
	
} Playlist;

/**
* @brief Função que aloca um espaço do tamanho de uma Playlist na memória
* @return novaPlaylist, a nova Playlist com os apontamentos de memória para o início, fim e atual apontando para NULL
*/
Playlist* llcriaPlaylist();

/**
* @brief Função que aloca um espaço do tamanho de uma lista de PalavraChave na memória
* @return novaPalavrasChave, a nova lista de PalavraChave com os apontamentos de memória para o início e fim apontando para NULL
*/
PalavrasChave* llcriaPalavrasChave();

/**
* @brief Função que aloca um espaço do tamanho de uma PalavraChave na memória (dados dessa PalavraChave serão pedidos nessa função)
* @return novaPalavrasChave, a nova PalavraChave com os apontamentos de memória para o próximo apontando para NULL
*/
PalavraChave* llcriaPalavraChave();

/**
* @brief Função que aloca um espaço do tamanho de um Podquest na memória (dados desse Podquest serão pedidos nessa função)
* @return novoPodquest, a nova Playlist com os apontamentos de memória para o próximo e anterior apontando para NULL
*/
Podquest llcriaPodquest();

/**
* @brief adiciona um Podquest na Playlist ordenado pelo ID
* @param playlist -> Lista de Podquest
*/
void llInserePodquestOrdenado(Playlist* playlist);

/**
* @brief adiciona um Podquest no final da Playlist
* @param playlist -> Lista de Podquest
*/
void llInserePodquestFim(Playlist* playlist);

/**
* @brief Função que verifica se um Podquest existe na Playlist, e caso exista, o retorna
* @param playlist -> Playlist na qual vai acontecer a busca
* @param idBusca -> Id do Podquest que vai ser buscado
* @param epsBusca -> Episodio do Podquest que vai ser buscado
* @return aux -> O Podquest buscaso
* @return NULL -> Caso o Podquest não exista na lista
*/
Podquest llBuscaPodquest(Playlist* playlist, int idBusca, int epsBusca);