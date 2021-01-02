#include "myInputReader.h"
#include <stdio.h>

int main() {
    pReader reader = createReader();

    char word[WORD];
    getWordAt(reader, 0, 0, word);
    char symbol[WORD];
    getWordAt(reader, 0, 1, symbol);

    if (symbol[0] == 'a') {
        print_lines(reader, 2, word);
    } else if (symbol[0] == 'b') {
        print_similar_words(reader, 2, word);
    } else {
        printf("ERROR : wrong input cannot the second word should be either the symbol a or b");
    }

    return 0;
}
