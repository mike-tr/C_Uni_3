#define LINE 256
#define WORD 30
#define MAX_LINES 251

typedef struct Reader *pReader;
typedef enum bool {
    false = 0,
    true = 1
} bool;

pReader createReader();
void printAll(pReader reader);
void print_similar_words(pReader reader, int start_line, char *target);
bool substring(char *str1, char *str2);
bool similar(char *s, char *t, int n);
void getLineAt(pReader reader, int line, char lineArr[LINE]);
void getWordAt(pReader reader, int line, int index, char word[WORD]);