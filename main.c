#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "linkedlist.h"

int main(int argc, char const* argv[]) 
{

	Playlist* playlist = llcriaPlaylist();

	lltocar(playlist);

	llInserePodquestFim(playlist);

	lltocar(playlist);

	llInserePodquestFim(playlist);

	lltocaProximo(playlist, false);

	llInserePodquestFim(playlist);

	llInserePodquestFim(playlist);

	llInserePodquestFim(playlist);

	llInserePodquestFim(playlist);

	llInserePodquestFim(playlist);

	llInserePodquestFim(playlist);

	llInserePodquestFim(playlist);

	llInserePodquestFim(playlist);

	llInserePodquestFim(playlist);

	llInserePodquestFim(playlist);

	lltocaProximo(playlist, true);

	return 0;
}