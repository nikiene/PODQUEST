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