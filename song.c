#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct song_node{
	char name[100];
	char artist[100];
	struct song_node *next;
};

struct song_node * createnode(char *n, char *a) { // creates node in heap memory
	struct song_node *s = malloc(sizeof(struct song_node));
	s->name = n;
	s->artist = a;
	s->next = 0;
	
	return s;
}
struct song_node * insertfront(struct song_node * s, char *n, char *a) { // inserts node to front of list
	struct song_node *new = createnode(n, a);
	new->next = s;
	return new;
}

struct song_node * insertordered(struct song_node * s, char *n, char *a) { // inserts node in alphabetical order
}

int main() { // temporary to test 


}
