#include "myInputReader.h"
#include <stdio.h>

int main() {
    pReader reader = createReader();

    char *cat = "cat";
    char *test = "bakaca'tcat222";
    printf("%s test substring of %s ? %d\n", cat, test, substring(test, cat));
    printf("%s test similar to %s ? %d\n", cat, test, similar(test, cat, 2));

    char *target = "window 2";
    char *s = "wi2ndofw1 2";
    printf("%s test similar to %s ? %d\n", s, target, similar(s, target, 3));

    //printAll(reader);
    print_similar_words(reader, 2, "cat");
    printf("\n");
    print_lines(reader, 2, "cat");

    char word[WORD];
    getWordAt(reader, 0, 1, word);
    printf("\n%s\n", word);

    printf("%s test substring of %s ? %d\n", cat, "cat", substring("cat", cat));
    return 0;
}
