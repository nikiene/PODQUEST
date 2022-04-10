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

	llInserePodquestFim(playlist);

	llInserePodquestFim(playlist);

	llInserePodquestFim(playlist);

	llInserePodquestFim(playlist);

	lltocaProximo(playlist, true);

	return 0;
}