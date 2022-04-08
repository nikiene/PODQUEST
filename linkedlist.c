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

	return novaPalavraChave;
}

/**
* @brief Função que aloca um espaço do tamanho de um Podquest na memória (dados desse Podquest serão pedidos nessa função)
* @return novoPodquest, a nova Playlist com os apontamentos de memória para o próximo e anterior apontando para NULL
*/
Podquest criaPodquest() {

}