#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct song_node{
	char name[100];
	char artist[100];
	struct song_node *next;
};

struct song_node * createnode(char *n, char *a) { // creates node in heap memory
	struct song_node *s = malloc(sizeof(struct song_node));
	strcpy(s->name, n);
	strcpy(s->artist, a);
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

void printnode(struct song_node *s) { // prints node
	if (s)
		printf(" %s: %s ", s->artist, s->name);
}

void printlist(struct song_node *s) { // prints entire list
	printnode(s);
	printf("|");
	if (s->next)
		printlist(s->next);
}

struct song_node * findsong(struct song_node * s, char *n, char *a) {
	while (s) {
		if ( !strcmp(s->name,n) && !strcmp(s->artist,a) )
			return s;
		s = s->next;
	}
	return 0;
}

struct song_node * findartist(struct song_node * s, char *a) {
	while (s) {
		if ( !strcmp(s->artist,a) )
			return s;
		s = s->next;
	}
	return 0;
}

int listlen(struct song_node * s) {
	int sum = 0;
	while (s) {
		sum++;
		s = s -> next;
	}
	return sum;
}

struct song_node * randomnode(struct song_node * s) { // needs debugging, multiple calls of randomnode return same node
	srand( time(NULL) );
	int x = rand() % listlen(s);
	int i;
	for (int i = 0; i < x; i++)
		s = s->next;
	return s;
}

struct song_node * removenode(struct song_node * s, char *n, char *a) {
	struct song_node *temp = findsong(s, n, a);
	struct song_node *inc = s;
	while (s) {
		if (
	
	}
	
}

int main() { // temporary to test 
	struct song_node *s = createnode("505", "Arctic Monkeys");
	s = insertfront(s, "Passionfruit", "Drake");
	s = insertfront(s, "90210", "Travis Scott");
	s = insertfront(s, "Impossible", "Travis Scott");
	printnode(s);
	printf("\n");
	printlist(s);
	printf("\n");
	
	struct song_node *a = findsong(s, "505", "Arctic Monkeys");
	struct song_node *b = findsong(s, "Passionfruit", "Drake");
	struct song_node *c = findsong(s, "90210", "Travis Scott");
	struct song_node *d = findsong(s, "Travis Scssott", "90210"); 
	struct song_node *e = findartist(s, "Travis Scott");
 
	printnode(a);
	printnode(b);
	printnode(c);
	printnode(d); // no node found
	printnode(e);
	printf("\n");
	printf("%d",listlen(s));
	a = randomnode(s);
	printnode(a);
	b = randomnode(s);
	printnode(b);
}
