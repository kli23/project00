#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


struct song_node ** allocate();

int letterindex(char c) ;

struct song_node ** add_song(struct song_node **s, char* n, char* a);

void print_letter(struct song_node **a, char c);

