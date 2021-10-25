#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "song.h"
#include "library.h"



int main() { 
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
	printf("\n");
	print_node(randomnode(s));
	printf("\n");
	print_node(randomnode(s));
	printf("\n");
	print_node(randomnode(s));
	printf("\n");
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


	printf("Testing free_list");
	s = free_list(s);
	printf("\nlist aftering free_list:\n");
	print_list(s);
	printf("\n====================================\n\n");


    printf("MUSIC LIBRARY TESTS");
    printf("\n====================================\n\n");
    printf("Testing print_letter \n");
    struct song_node ** sp = allocate();
    print_letter(sp, 'd');
    sp = add_song(sp, "hello", "hi");
    //print_letter(sp, 'h');
	
}