#include "myInputReader.h"
#include <stdio.h>

int main() {
    pReader reader = createReader();

    char word[WORD];
    getWordAt(reader, 0, 0, word);
    char symbol[WORD];
    getWordAt(reader, 0, 1, symbol);

    printf("\n%s : %s\n", word, symbol);

    print_similar_words(reader, 2, word);
    printf("\n");
    print_lines(reader, 2, word);
    return 0;
}
