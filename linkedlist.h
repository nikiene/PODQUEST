#pragma once

#include <stdio.h>
#include <stdlib.h>

typedef struct palavrasChave
{
	char categoria[64];
	struct palavrasChave* outraCategoria;
} PalavrasChave;

typedef struct podcast
{
	int podcastId;
	char nomePodcast[64];
	char nomeEpisodio[64];
	int numeroEpisodio;

} Podcast;

typedef Podcast* Podquest;

typedef struct playlist
{
	Podquest inicio;
	Podquest atual;
	Podquest fim;
} Playlist;