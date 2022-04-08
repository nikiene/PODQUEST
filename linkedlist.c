#pragma once

#include "linkedlist.h"

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
* @brief Função que aloca um espaço do tamanho de uma PalavrasChave na memória (dados dessa PalavrasChave serão pedidos nessa função)
* @return novaPalavrasChave, a nova PalavrasChave com os apontamentos de memória para o próximo apontando para NULL
*/
PalavrasChave* criaPalavrasChave() {

}

/**
* @brief Função que aloca um espaço do tamanho de um Podquest na memória (dados desse Podquest serão pedidos nessa função)
* @return novoPodquest, a nova Playlist com os apontamentos de memória para o próximo e anterior apontando para NULL
*/
Podquest criaPodquest() {

}