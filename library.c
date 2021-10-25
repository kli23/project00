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
    return 26;
}

struct song_node ** add_song(struct song_node **s, char* n, char* a) {
    char c = a[0];
    int index = letterindex(c);
    if (!s[index])
        s[index] = createnode(n,a);
    else
        s[index] = insertordered(s[index], n, a);
    //*s = insertordered(*s, n, a);
    return s;
} 

struct song_node * search_song(struct song_node **s, char* n, char* a) {
    char c = a[0];
    int index = letterindex(c);
    struct song_node * z = find_node_helper(s[index], n, a);
    if (!z) {
        printf("\n\tsong not found");
    }
    else {
        printf("\n\tsong found! ");
    }
    return z;
}

struct song_node * search_artist(struct song_node **s, char* a) {
    char c = a[0];
    int index = letterindex(c);
    struct song_node * z = findartist_helper(s[index], a);
    if (z)
        printf("\n\tartist found! ");
    else
        printf("\n\tartist not found");
    return z;
}

void print_artist(struct song_node **s, char *a) {
    char c = a[0];
    int index = letterindex(c);
    struct song_node * z = findartist_helper(s[index], a);
    printf("%s: ", a);
    if (z) {
        while (!strcmp(z->artist,a)) {
            print_node(z);
            printf(" ");
            z = z->next;
        }
    }
}

void shuffle(struct song_node **s) {
    randomnode(s[0]); // to call srand once, allow for rand() usage
    int i;
    int sum = 0;
    for (i = 0; i < 27; i++)
        sum += listlen(s[i]);
    printf("%d",sum);
    /*int x = (rand() % 5) + 1;
    int i;
    for (i = 0; i < x; i++) {
        x = rand() % 27;
        print_node(randomnode(s[x]));
        printf("\n");
    }
    */
}

struct song_node ** delete_song(struct song_node **s, char *n, char *a) {
    char c = a[0];
    int index = letterindex(c);
    s[index] = removenode(s[index], n, a);
    return s;
}

struct song_node ** clear_all(struct song_node **s) {
    int i;
    for (int i = 0; i < 27; i++) {
        s[i] = free_list(s[i]);
    }
    return s;
}

void print_letter(struct song_node **a, char c) {
    int index = letterindex(c);
    print_list(a[index]);
}

void print_library(struct song_node **a) {
    int i;
    for (i = 0; i < 26; i++) {
        if (a[i]) {
            printf("\n%c: ", alphabet[i]);
            print_list(a[i]);
        }
    }
    if (a[26]) {
        printf("\nspecial characters: ");
        print_list(a[26]);
    }
} 
