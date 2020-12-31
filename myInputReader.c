#include "myInputReader.h"
#include <stdio.h>
#include <stdlib.h>

int readNextLine(pReader reader);

typedef struct Reader {
    bool finished;
    int size;
    char input[MAX_LINES][LINE];
} Reader;

pReader createReader() {
    pReader reader = (pReader)malloc(sizeof(Reader));
    if (reader == NULL) {
        return reader;
    }
    reader->finished = false;
    reader->size = 0;

    while (reader->finished == false) {
        if (reader->size + 1 > MAX_LINES) {
            reader->finished = true;
            return reader;
        }
        readNextLine(reader);
    }
    return reader;
}

void printAll(pReader reader) {
    for (int i = 0; i < reader->size; i++) {
        printf("%s", reader->input[i]);
    }
}

int readNextLine(pReader reader) {
    if (reader == NULL) {
        printf("ERR : no reader");
        return -1;
    }

    char c = getchar();
    int size = 0;
    while (c != EOF && size < LINE - 2) {
        reader->input[reader->size][size] = c;
        if (c == '\n') {
            reader->size++;
            return size + 1;
        }
        c = getchar();
        size++;
    }
    reader->input[reader->size][size] = '\n';
    reader->input[reader->size][size + 1] = 0;
    reader->finished = true;
    reader->size++;
    return size + 1;
}

/**
 * @returns the index of the last symbol in the word.
 * */
int getNextWord(char line[LINE], char word[WORD]) {
    int len_word = 0;
    int i = 0;
    for (; i < LINE && line[i] != '\n'; i++) {
        char c = line[i];
        if (c == '\t' || c == ' ' || c == '\r') {
            if (len_word > 0) {
                word[len_word] = 0;
                return i;
            }
            continue;
        }
        word[len_word] = c;
        len_word++;
    }
    word[len_word] = 0;
    return len_word > 0 ? i : -1;
}

/**
 * @returns 1 if str1 start the same as str2
 * */
bool startTheSame(char *str1, char *str2) {
    while (*str1 == *str2) {
        str1++;
        str2++;
    }
    if (*str2 == 0) {
        return true;
    }
    return false;
}

bool substring(char *str1, char *str2) {
    if (str1 == str2) {
        return true;
    }
    if (str1 == NULL || str2 == NULL) {
        return false;
    }

    while (*str1 != 0) {
        if (startTheSame(str1, str2)) {
            return true;
        }
        str1++;
    }
    return false;
}

bool similar(char *str1, char *str2, int n) {
    while (*str1 == *str2) {
        if (*str1 == 0 && *str2 == 0) {
            return true;
        }
        str1++;
        str2++;
    }
    if (*str1 == 0) {
        return false;
    }
    if (n > 0) {
        return similar(str1 + 1, str2, n - 1);
    }
    return false;
}

void getLineAt(pReader reader, int line, char lineArr[LINE]) {
    if (reader->size < line) {
        lineArr = "";
        return;
    }
    lineArr = reader->input[line];
}

void getWordAt(pReader reader, int line, int index, char word[WORD]) {
    if (reader->size < line) {
        word = "";
        return;
    }
    int size = 0;
    int start = 0;
    while ((size = getNextWord(reader->input[line] + start, word)) != EOF) {
        if (index == 0) {
            return;
        }
        start += size;
        index--;
    }
    word = "";
}

void print_lines(char *str) {
}

void print_similar_words(pReader reader, int start_line, char *target) {
    for (int i = start_line; i < reader->size; i++) {
        char word[WORD];
        int start = 0;
        int size = 0;
        while ((size = getNextWord(reader->input[i] + start, word)) != EOF) {
            start += size;
            if (similar(word, target, 1)) {
                printf("%s\n", word);
            }
        }
    }
}