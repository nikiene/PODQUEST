#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Definição das palavras-chave, cada uma vai ter uma string e um apontamento para uma próxima, caso existir
typedef struct palavrasChave
{
	char categoria[64];
	struct palavrasChave* proxima;

} PalavrasChave;

//Definição do meu podcast, vai possuir um id, uma string nome(podcast), uma string nome(episódio) e um numero do episódio
//TODO: implementar as palavras-chave
typedef struct podcast
{
	int podcastId;
	char nomePodcast[64];
	char nomeEpisodio[64];
	int numeroEpisodio;

	PalavrasChave palavrasChave;

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
* @brief Função que aloca um espaço do tamanho de uma PalavrasChave na memória (dados dessa PalavrasChave serão pedidos nessa função)
* @return novaPalavrasChave, a nova PalavrasChave com os apontamentos de memória para o próximo apontando para NULL
*/
PalavrasChave* criaPalavrasChave();

/**
* @brief Função que aloca um espaço do tamanho de um Podquest na memória (dados desse Podquest serão pedidos nessa função)
* @return novoPodquest, a nova Playlist com os apontamentos de memória para o próximo e anterior apontando para NULL
*/
Podquest criaPodquest();