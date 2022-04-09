#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

//Função auxiliar que troca '\n' por '\0' (thx @Yarquen! :D)
void remove_newline_ch(char* line);

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
PalavrasChave* criaPalavrasChave();

/**
* @brief Função que aloca um espaço do tamanho de uma PalavraChave na memória (dados dessa PalavraChave serão pedidos nessa função)
* @return novaPalavrasChave, a nova PalavraChave com os apontamentos de memória para o próximo apontando para NULL
*/
PalavraChave* criaPalavraChave();

/**
* @brief adiciona uma palavra-chave no fim da lista de palavras-chave
* @param palavrasChave -> Lista de palavras-chave
* @return 1 -> se mais palavras vão ser inseridas
* @return 0 -> se mais palavras vão ser inseridas
*/
int adicionaPalavraChave(PalavrasChave* palavrasChave);

/**
* @brief Função que aloca um espaço do tamanho de um Podquest na memória (dados desse Podquest serão pedidos nessa função)
* @return novoPodquest, a nova Playlist com os apontamentos de memória para o próximo e anterior apontando para NULL
*/
Podquest criaPodquest();

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

/**
* @brief Função que busca um elemento na lista e se o encontrar, o remove
* @param playlist -> Playlist a qual vai ter o Podquest removido
*/
void llremovePodquest(Playlist* playlist);

/**
* @brief Função que começa a tocar a playlist
* @param playlist -> Playlist que vai ser tocada
*/
void lltocar(Playlist* playlist);

/**
* @brief Função que toca o próximo Podquest da PLaylist, caso o shuffle esteja ligado, toca um dos próximos Podquests aleatoriamente
* @param playlist -> Playlist que vai ser tocada
* @param shuffle -> Boolean dizendo se está ligado ou não
*/
void lltocaProximo(Playlist* playlist, bool shuffle);

/**
* @brief Função que toca o próximo Podquest da PLaylist, caso o shuffle esteja ligado, toca um dos próximos Podquests aleatoriamente
* @param playlist -> Playlist que vai ser tocada
*/
void lltocaAnterior(Playlist* playlist);

/**
* @brief Função que imprime os Podquests da Playlist
* @param playlist -> playlist que vai ser impressa
*/
void llrelatorio(Playlist* playlist);