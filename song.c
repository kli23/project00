#include "song.h"

int songcmp(struct song_node *a, struct song_node *b) {
	if (strcmp(a->artist, b->artist))
		return strcmp(a->artist, b->artist);
	return strcmp(a->name, b->name);
}

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
	struct song_node *start = s;
	struct song_node *new = createnode(n, a);

	//special case when node should be inserted in front
	if (songcmp(new, s) < 0) {
		new -> next = s;
		return new;
	}

	// case when node is inserted in middle of list
	while (s->next) {
		if ( (songcmp(s,new) < 0) && (songcmp(new, s->next) < 0) )  {
			struct song_node *temp = s->next;
			s->next = new;
			new->next = temp;
			return start;
		}
		s = s->next;
	}

	// case when node is inserted at the end of list
	if (songcmp(s, new) < 0)
		s->next = new;
	return start;
}

void print_node(struct song_node *s) { // prints node
	if (s)
		printf("{%s, %s}", s->artist, s->name);
}

void print_list(struct song_node *s) { // prints entire list
	printf("[ ");
	print_node(s);
	printf(" | ");
	while (s->next) {
		print_node(s->next);
		printf(" | ");
		s = s->next;
	}
	printf("]");
}

struct song_node * find_node(struct song_node * s, char *n, char *a) {
	while (s) {
		if ( !strcmp(s->name,n) && !strcmp(s->artist,a) ) {
			printf("node found! ");
			return s;
		}
		s = s->next;
	}
	printf("node not found");
	return 0;
}

struct song_node * findartist(struct song_node * s, char *a) {
	while (s) {
		if ( !strcmp(s->artist,a) ) {
			printf("node found!");
			return s;
		}
		s = s->next;
	}
	printf("node not found");
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


int initialized = 0;
struct song_node * randomnode(struct song_node * s) { // needs debugging, multiple calls of randomnode return same node
	if (!initialized) {
		srand( time(NULL) );
		initialized = 1;
	}
	int x;
	x = rand();
	printf("%d", x);
	x %= listlen(s);
	int i;
	for (int i = 0; i < x; i++)
		s = s->next;
	return s;
}

struct song_node * removenode(struct song_node * s, char *n, char *a) {
	struct song_node *temp = createnode(n,a);
	struct song_node *start = s;
	if ( !songcmp(s,temp) ) {
    	start = s->next;
		free(s);
		free(temp);
    	return start;
  	}
	while (s->next) {
    	if ( !songcmp(s->next,temp) ) {
			free(s->next);
    		s->next = s->next->next;
			free(temp);
    		return start;
    	}
    	s = s->next;
	}
  	print_node(s);
	printf(" not found\n");
	free(temp);
	return start;
}

struct song_node * free_list (struct song_node * s) {
	struct song_node * temp;
	while (s) {
		temp = s;
		printf("freeing_node: ");
		print_node(s);
		s = s->next;
		printf("\n");
		free(temp);
	}
	return temp;
}

int main() { // temporary to test 
	struct song_node *s = createnode("street spirit (fade out)", "radiohead");
	s = insertfront(s, "paranoid android", "radiohead");
	s = insertfront(s, "time", "pink floyd");
	s = insertfront(s, "yellow ledbetter", "pearl jam");
	s = insertfront(s, "even flow", "pearl jam");
	s = insertfront(s, "alive", "pearl jam");
	s = insertfront(s, "thunderstruck", "ac/dc");

	printf("LINKED LIST TESTS\n====================================\n\n");
	
	printf("Testing print_list:\n\t");
	print_list(s);
	printf("\n====================================\n\n");

	printf("Testing print_node:\n\t");
	print_node(s);
	printf("\n====================================\n\n");
	
	printf("Testing find_node:  \n");
	printf("looking for [pearl jam: even flow]\n\t");
	struct song_node *a = find_node(s, "even flow", "pearl jam");
	print_node(a);
	printf("\nlooking for [pearl jam: daughter]\n\t");
	struct song_node *b = find_node (s, "daughter", "pearl jam");
	print_node(b);
	printf("\n====================================\n\n");


	printf("Testing songcmp (helper function):\n");
	printf("Comparing [pearl jam: even flow] to [pearl jam: even flow]\n\t");
	printf("%d\n", songcmp(s->next->next,s->next->next));
	printf("Comparing [pearl jam: even flow] to [pearl jam: alive]\n\t");
	printf("%d\n", songcmp(s->next->next,s->next));
	printf("Comparing [pearl jam: alive] to [pearl jam: even flow]\n\t");
	printf("%d\n", songcmp(s->next,s->next->next));
	printf("Comparing [pearl jam: even flow] to [pink floyd: time]\n\t");
	printf("%d\n", songcmp(s->next->next,s->next->next->next->next));
	printf("\n====================================\n\n");

	
	printf("Testing random:\n");
	print_node(randomnode(s));
	print_node(randomnode(s));
	print_node(randomnode(s));
	print_node(randomnode(s));
	print_node(randomnode(s));
	printf("\n====================================\n\n");

	printf("Testing remove:\n");
	printf("Removing [ac/dc: thunderstruck]\n\t");
	s = removenode(s, "thunderstruck", "ac/dc");
	print_list(s);
	printf("\nRemoving [radiohead: street spirit (fade out)]\n\t");
	s = removenode(s, "street spirit (fade out)", "radiohead");
	print_list(s);
	printf("\nRemoving [pearl jam: yellow ledbetter]\n\t");
	s = removenode(s, "yellow ledbetter", "pearl jam");
	print_list(s);
	printf("\nRemoving [pearl jam: yellow ledbetter]\n\t");
	s = removenode(s, "yellow ledbetter", "pearl jam");
	print_list(s);
	printf("\n====================================\n\n");
	printf("Testing free_list\n");
	s = free_list(s);
	printf("\nlist aftering free_list:");
	print_list(s);
	printf("\n");
	
	/*
	struct song_node *a = find_node(s, "505", "Arctic Monkeys");
	struct song_node *b = find_node(s, "Passionfruit", "Drake");
	struct song_node *c = find_node(s, "90210", "Travis Scott");
	struct song_node *d = find_node(s, "Travis Scssott", "90210"); 
	struct song_node *e = findartist(s, "Travis Scott");
 
	print_node(a);
	print_node(b);
	print_node(c);
	print_node(d); // no node found
	print_node(e);
	printf("\n");
	printf("%d",listlen(s));
	a = randomnode(s);
	print_node(a);
	b = randomnode(s);
	print_node(b);
	printf("\n");
	print_list(s);
	s = removenode(s, "90210", "Travis Scott");
	printf("\n");
	print_list(s);
	s = free_list(s);
	print_list(s);
	*/
}
