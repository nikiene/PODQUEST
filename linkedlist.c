#pragma once

#include "linkedlist.h"

//Fun��o auxiliar que troca '\n' por '\0' (thx @Yarquen! :D)
void remove_newline_ch(char* line) {
	int new_line = strlen(line) - 1;
	if (line[new_line] == '\n')
	{
		line[new_line] = '\0';
	}
}

/**
* @brief Fun��o que aloca um espa�o do tamanho de uma Playlist na mem�ria
* @return novaPlaylist, a nova Playlist com os apontamentos de mem�ria para o in�cio, fim e atual apontando para NULL
*/
Playlist* criaPlaylist() {

	Playlist* novaPlaylist = (Playlist*)malloc(sizeof(Playlist));

	printf("\nNome da Playlist: ");
	fgets(novaPlaylist->nomePlaylist, 64, stdin);
	remove_newline_ch(novaPlaylist->nomePlaylist);

	novaPlaylist->inicio = NULL;
	novaPlaylist->atual = NULL;
	novaPlaylist->fim = NULL;
	novaPlaylist->proxima = NULL;

	return novaPlaylist;
}

/**
* @brief Fun��o que aloca um espa�o do tamanho de uma Lista de Playlist na mem�ria
* @return novasPlaylists, a nova Lista de Playlist com os apontamentos de mem�ria para o in�cio e pr�xima apontando para NULL
*/
Playlists* criaPlaylists() {

	Playlists* novasPlaylists = (Playlists*)malloc(sizeof(Playlists));

	novasPlaylists->inicio = NULL;
	novasPlaylists->fim = NULL;

	return novasPlaylists;
}

/**
* @brief Fun��o que mostra as Playlists na lista de Playlists
* @param playlists -> lista de Playlists
*/
void llmostraPlaylists(Playlists* playlists) {
	
	if (playlists->inicio != NULL)
	{
		int temp = 0;
		for (Playlist* aux = playlists->inicio; aux != NULL; aux = aux->proxima)
		{
			temp++;
			printf("\n%d. %s", temp, aux->nomePlaylist);
		}
	}
	else
	{
		printf("\nSem playlists!\n\n");
	}
}

/**
* @brief Fun��o que mostra as Playlists na lista de Playlists e pede ao usu�rio selecionar uma
* @param playlists -> lista de Playlists
* @return aux -> Playlist selecionada
*/
Playlist* llselecionaPlaylist(Playlists* playlists) {

	if (playlists->inicio != NULL)
	{
		while (true)
		{
			llmostraPlaylists(playlists);

			int escolha = 0;

			printf("\nQual a Playlist desejada? ");
			scanf_s("%d", &escolha);
			getchar();

			int temp = 0;
			Playlist* aux = playlists->inicio;
			for (aux; aux != NULL; aux = aux->proxima)
			{
				temp++;
				if (temp == escolha)
				{
					return aux;
				}
			}
		}
	}
	else
	{
		printf("\nSem playlists!\n\n");
	}
}

/**
* @brief Fun��o que adiciona uma Playlist na lista de Playlists
* @param playlists -> lista de Playlists
*/
void lladicionaNovaPlaylist(Playlists* playlists) {

	Playlist* playlist = criaPlaylist();

	if (playlists->inicio = NULL)
	{
		playlists->inicio = playlist;
		playlists->fim = playlist;
	}
	else
	{
		playlist->proxima = playlists->inicio;
		playlists->inicio = playlist;
	}

	printf("\n");
}


/**
* @brief Fun��o que aloca um espa�o do tamanho de uma lista de PalavraChave na mem�ria 
* @return novaPalavrasChave, a nova lista de PalavraChave com os apontamentos de mem�ria para o in�cio e fim apontando para NULL
*/
PalavrasChave* criaPalavrasChave() {

	PalavrasChave* novaPalavrasChave = (PalavrasChave*)malloc(sizeof(PalavrasChave));

	novaPalavrasChave->inicio = NULL;
	novaPalavrasChave->fim = NULL;

	return novaPalavrasChave;
}

/**
* @brief Fun��o que aloca um espa�o do tamanho de uma PalavraChave na mem�ria (dados dessa PalavraChave ser�o pedidos nessa fun��o)
* @return novaPalavrasChave, a nova PalavraChave com os apontamentos de mem�ria para o pr�ximo apontando para NULL
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
* @return 1 -> se mais palavras v�o ser inseridas
* @return 0 -> se mais palavras v�o ser inseridas
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
* @brief Fun��o que aloca um espa�o do tamanho de um Podquest na mem�ria (dados desse Podquest ser�o pedidos nessa fun��o)
* @return novoPodquest, a nova Playlist com os apontamentos de mem�ria para o pr�ximo e anterior apontando para NULL
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

	printf("\n");

	while (continuar)
	{
		continuar = adicionaPalavraChave(novaListaPalavrasChave);

		printf("\n");

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

	for (Podquest aux = playlist->inicio; aux != NULL; aux = aux->proximo)
	{
		while (aux->podcastId == novoPodquest->podcastId && strcmp(aux->nomePodcast, novoPodquest->nomePodcast) != 0)
		{
			novoPodquest->podcastId++;

			if (aux->podcastId == novoPodquest->podcastId && strcmp(aux->nomePodcast, novoPodquest->nomePodcast) == 0 || novoPodquest->podcastId > playlist->fim->podcastId)
			{
				break;
			}
		}
	}
	
	if (playlist->inicio == NULL)
	{
		playlist->inicio = novoPodquest;
		playlist->atual = playlist->inicio;
		playlist->fim = novoPodquest;

		return;
	}
	else if (novoPodquest->podcastId > playlist->fim->podcastId)
	{
		playlist->fim->proximo = novoPodquest;
		novoPodquest->anterior = playlist->fim;
		playlist->fim = novoPodquest;
		playlist->atual = playlist->inicio;

		return;
	}
	else
	{
		while (playlist->inicio->proximo->podcastId <= novoPodquest->podcastId)
		{
			playlist->inicio = playlist->inicio->proximo;
		}

		while (playlist->inicio->proximo->numeroEpisodio <= novoPodquest->numeroEpisodio)
		{
			playlist->inicio = playlist->inicio->proximo;
		}

		novoPodquest->proximo = playlist->inicio->proximo;
		playlist->inicio->proximo = novoPodquest;
		novoPodquest->anterior = playlist->inicio;
		playlist->atual = playlist->inicio;
	}
}

/**
* @brief adiciona um Podquest no final da Playlist
* @param playlist -> Lista de Podquest
*/
void llInserePodquestFim(Playlist* playlist) {

	Podquest novoPodquest = criaPodquest();

	for (Podquest aux = playlist->inicio; aux != NULL; aux = aux->proximo)
	{
		while (aux->podcastId == novoPodquest->podcastId && strcmp(aux->nomePodcast, novoPodquest->nomePodcast) != 0)
		{
			novoPodquest->podcastId++;
		
			if (aux->podcastId == novoPodquest->podcastId && strcmp(aux->nomePodcast, novoPodquest->nomePodcast) == 0 || novoPodquest->podcastId > playlist->fim->podcastId)
			{
				break;
			}
		}
	}
	

	if (playlist->inicio == NULL)
	{
		playlist->inicio = novoPodquest;
		playlist->atual = playlist->inicio;
		playlist->fim = novoPodquest;

		return;
	}

	playlist->fim->proximo = novoPodquest;
	novoPodquest->anterior = playlist->fim;
	playlist->fim = novoPodquest;
}

/**
* @brief Fun��o que verifica se um Podquest existe na Playlist, e caso exista, o retorna
* @param playlist -> Playlist na qual vai acontecer a busca
* @param idBusca -> Id do Podquest que vai ser buscado
* @param epsBusca -> Episodio do Podquest que vai ser buscado
* @return aux -> O Podquest buscaso
* @return NULL -> Caso o Podquest n�o exista na lista
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
* @brief Fun��o que busca um elemento na lista e se o encontrar, o remove
* @param playlist -> Playlist a qual vai ter o Podquest removido
*/
void llremovePodquest(Playlist* playlist) {
	
	int idBusca = 0, epsBusca = 0;

	printf("\nInsira o Id do Podquest a ser removido: ");
	scanf_s("%d", &idBusca);
	getchar();

	printf("\nInsira o numero do episodio a ser removido: ");
	scanf_s("%d", &epsBusca);
	getchar();

	Podquest buscado = llBuscaPodquest(playlist, idBusca, epsBusca);

	if (buscado != NULL)
	{
		if (buscado == playlist->inicio)
		{
			Podquest inicioRemovido = playlist->inicio;

			playlist->inicio = playlist->inicio->proximo;
			playlist->inicio->anterior = NULL;

			free(inicioRemovido);
			return;
		}
		else if (buscado == playlist->fim)
		{
			Podquest fimRemovido = playlist->fim;

			playlist->fim = playlist->fim->anterior;
			playlist->fim->proximo = NULL;

			free(fimRemovido);
			return;
		}
		else
		{
			buscado->proximo->anterior = buscado->anterior;
			buscado->anterior->proximo = buscado->proximo;

			free(buscado);
			return;
		}
	}
}

/**
* @brief Fun��o que come�a a tocar a playlist
* @param playlist -> Playlist que vai ser tocada
*/
void lltocar(Playlist* playlist) {

	if (playlist->inicio != NULL)
	{
		printf("\n- Now Playing:");
		printf("\n %d. %s", playlist->atual->podcastId, playlist->atual->nomePodcast);
		printf("\n	# %d - %s\n\n", playlist->atual->numeroEpisodio, playlist->atual->nomeEpisodio);
	}
	else
	{
		printf("\nA Playlist esta vazia!\n\n");
	}
}

/**
* @brief Fun��o que toca o pr�ximo Podquest da PLaylist, caso o shuffle esteja ligado, toca um dos pr�ximos Podquests aleatoriamente
* @param playlist -> Playlist que vai ser tocada
* @param shuffle -> Boolean dizendo se est� ligado ou n�o
*/
void lltocaProximo(Playlist* playlist, bool shuffle) {

	if (playlist->inicio != NULL)
	{
		if (shuffle)
		{
			while (true)
			{
				srand(time(NULL));
				int aux = rand() % sizeof(playlist) + 1;

				//Transformando a Playlist numa Lista circular
				playlist->fim->proximo = playlist->inicio;

				Podquest antigoAtual = playlist->atual;

				for (int i = 0; i < aux; i++)
				{
					playlist->atual = playlist->atual->proximo;
				}

				if (antigoAtual != playlist->atual)
				{
					//Desfazendo a Lista circular
					if (playlist->fim->proximo != NULL)
					{
						playlist->fim->proximo = NULL;
					}

					lltocar(playlist);
					free(antigoAtual);
					return;
				}
			}
		}
		else
		{
			if (playlist->atual->proximo != NULL)
			{
				playlist->atual = playlist->atual->proximo;

				lltocar(playlist);
			}
			else
			{
				printf("\nFim da Playlist! Voltando para o in�cio...\n");

				playlist->atual = playlist->inicio;

				lltocar(playlist);
			}
		}
	}
}

/**
* @brief Fun��o que toca o pr�ximo Podquest da PLaylist, caso o shuffle esteja ligado, toca um dos pr�ximos Podquests aleatoriamente
* @param playlist -> Playlist que vai ser tocada
*/
void lltocaAnterior(Playlist* playlist) {

	if (playlist->inicio != NULL && playlist->atual->anterior != NULL)
	{
		playlist->atual = playlist->atual->anterior;

		lltocar(playlist);
	}
	else
	{
		lltocar(playlist);
	}
}

/**
* @brief Fun��o que imprime os Podquests da Playlist
* @param playlist -> playlist que vai ser impressa
*/
void llrelatorio(Playlist* playlist) {

	if (playlist->inicio != NULL)
	{
		Podquest antigoAtual = playlist->atual;

		int numeroPodcasts = 0;
		int numeroEpisodios = (int)sizeof(playlist) - 3;

		for (playlist->atual = playlist->inicio; playlist->atual != NULL; playlist->atual = playlist->atual->proximo)
		{
			if (playlist->atual->podcastId != numeroPodcasts)
			{
				numeroPodcasts++;
			}
		}
		
		if (numeroPodcasts == 1)
		{
			if (numeroEpisodios == 1)
			{
				printf("\nSua Playlist possui %d Podcast e %d Episodio:\n", numeroPodcasts, numeroEpisodios);
			}
			else
			{
				printf("\nSua Playlist possui %d Podcast e %d Episodios:\n", numeroPodcasts, numeroEpisodios);
			}
		}
		else
		{
			printf("\nSua Playlist possui %d Podcasts e %d Episodios:\n", numeroPodcasts, numeroEpisodios);
		}
		

		for (playlist->atual = playlist->inicio; playlist->atual != NULL; playlist->atual = playlist->atual->proximo)
		{
			if (playlist->atual != NULL)
			{
				
				if (playlist->atual == playlist->inicio)
				{
					printf("\n %d. %s", playlist->atual->podcastId, playlist->atual->nomePodcast);
				}
				else if (playlist->atual->podcastId != playlist->atual->anterior->podcastId)
				{
					printf("\n %d. %s", playlist->atual->podcastId, playlist->atual->nomePodcast);
				}


				printf("\n	#%d - %s\n", playlist->atual->numeroEpisodio, playlist->atual->nomeEpisodio);
			}
		}
		playlist->atual = antigoAtual;

		free(antigoAtual, numeroPodcasts);
	}
	else
	{
		printf("\nA Playlist esta vazia!\n\n");
	}
}