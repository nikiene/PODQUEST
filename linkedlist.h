#pragma once

#include <stdio.h>
#include <stdlib.h>

//Definição das palavras-chave, cada uma vai ter uma string e um apontamento para uma próxima, caso existir
typedef struct palavrasChave
{
	char categoria[64];
	struct palavrasChave* outraCategoria;
	
} PalavrasChave;

//Definição do meu podcast, vai possuir um id, uma string nome(podcast), uma string nome(episódio) e um numero do episódio
//TODO: implementar as palavras-chave
typedef struct podcast
{
	int podcastId;
	char nomePodcast[64];
	char nomeEpisodio[64];
	int numeroEpisodio;

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
