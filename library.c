#include "song.h"
#include "library.h"

char alphabet[26] = "abcdefghijklmnopqrstuvwxyz";


struct song_node ** allocate() {
    struct song_node ** library = calloc(27, sizeof(struct song_node *));
    return library;
}


int letterindex(char c) {
    int i;
    for ( i = 0; i < 26; i++)
        if (alphabet[i] == c)
            return i;
}

struct song_node ** add_song(struct song_node **s, char* n, char* a) {
    char c = a[0];
    int index = letterindex(c);
    printf("%p %d", s, index);
    printf("%p", *s);
    print_node(*s);
    *s += index;
    printf("%p", s);
    // prin
    //*s = insertordered(*s, n, a);
    return s;
} 

void print_letter(struct song_node **a, char c) {
    int index = letterindex(c);
    print_list(a[index]);
}
/*
void print_library(struct song_node **a) {
    for (int)
} */
