#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "linkedlist.h"

int main(int argc, char const* argv[]) 
{
	Playlists* listaPlaylists = criaPlaylists();
	Playlist* playlistAtual = NULL;

	printf("                                                                                \n");
	printf("                            ,,                                                  \n");
	printf("                          `7MM                                            mm    \n");
	printf("                            MM                                            MM    \n");
	printf("`7MMpdMAo.  ,pW\"Wq.    ,M\"\"bMM    ,dW\"Yvd  `7MM  `7MM   .gP\"Ya, pP\"Ybd  mmMMmm  \n");
	printf("  MM   `Wb 6W'   `Wb ,AP    MM   ,W'   MM    MM    MM  ,M'   Yb 8I   `\"   MM\n");
	printf("  MM    M8 8M     M8 8MI    MM   8M    MM    MM    MM  8M\"\"\"\"\"\" `YMMMa.   MM    \n");
	printf("  MM   ,AP YA.   ,A9 `Mb    MM   YA.   MM    MM    MM  YM.    , L.   I8   MM    \n");
	printf("  MMbmmd'   `Ybmd9'   `Wbmd\"MML.  `MbmdMM    `Mbod\"YML. `Mbmmd' M9mmmP'   `Mbmo \n");
	printf("  MM                                   MM                                       \n");
	printf(".JMML.                               .JMML.               version 1.0.0 :p      \n");
	printf("                                                                                \n");

	int option = 0, idBusca = 0, epsBusca = 0;
	bool running = true, shuffle = false;

	while (running)
	{
		printf("\n________________________________________________________________________________\n");
		
		printf("\n0 - Sair");
		printf("\n1 - Mostrar Playlists");
		printf("\n2 - Selecionar Playlist");
		printf("\n3 - Criar Playlist");

		if (listaPlaylists->inicio != NULL && playlistAtual != NULL)
		{
			printf("\n\nPlaylist Selecionada: %s\n", playlistAtual->nomePlaylist);

			printf("\n4 - Relatorio da Playlist");
			printf("\n5 - Tocar Playlist");
			printf("\n6 - Modo shuffle");
			printf("\n7 - Proximo Podquest");
			printf("\n8 - Podquest Anterior");
			printf("\n9 - Buscar Podquest");
			printf("\n10 - Adicionar Podquest");
			printf("\n11 - Remover Podquest");
			
			printf("\n________________________________________________________________________________\n");

			printf("\nQual a opcao desejada? ");
			scanf("%d", &option);
			getchar();

			switch (option)
			{
			case 0:
				running = false;
				break;
			case 1:
				llmostraPlaylists(listaPlaylists);
				break;
			case 2:
				playlistAtual = llselecionaPlaylist(listaPlaylists);
				break;
			case 3:
				printf("\n");
				lladicionaNovaPlaylist(listaPlaylists);
				break;
			case 4:
				llrelatorio(playlistAtual);
				break;
			case 5:
				lltocar(playlistAtual);
				break;
			case 6:
				if (shuffle)
				{
					printf("\nDesligando Modo shuffle!\n");
					shuffle = false;
				}
				else
				{
					printf("\nLigando Modo shuffle!\n");
					shuffle = true;
				}
				break;
			case 7:
				lltocaProximo(playlistAtual, shuffle);
				break;
			case 8:
				lltocaAnterior(playlistAtual);
				break;
			case 9:
				printf("\nInsira o Id do Podquest a ser buscado: ");
				scanf("%d", &idBusca);
				getchar();

				printf("\nInsira o numero do episodio a ser buscado: ");
				scanf("%d", &epsBusca);
				getchar();

				llBuscaPodquest(playlistAtual, idBusca, epsBusca);
				break;
			case 10:
				llInserePodquestFim(playlistAtual);
				break;
			case 11:
				printf("\nInsira o Id do Podquest a ser removido: ");
				scanf("%d", &idBusca);
				getchar();

				printf("\nInsira o numero do episodio a ser removido: ");
				scanf("%d", &epsBusca);
				getchar();

				llremovePodquest(playlistAtual, idBusca, epsBusca);
				break;
			default:
				break;
			}
		}
		else
		{
			printf("\n________________________________________________________________________________\n");
			
			printf("\nQual a opcao desejada? ");
			scanf("%d", &option);
			getchar();

			switch (option)
			{
			case 0:
				running = false;
				break;
			case 1:
				llmostraPlaylists(listaPlaylists);
				break;
			case 2:
				playlistAtual = llselecionaPlaylist(listaPlaylists);
				break;
			case 3:
				lladicionaNovaPlaylist(listaPlaylists);
				break;
			default:
				break;
			}
		}
	}

	printf("\n\nOBRIGADO POR USAR O PODQUEST! :)\n\n");

  free(playlistAtual);
  free(listaPlaylists);
  
	return 0;
}
