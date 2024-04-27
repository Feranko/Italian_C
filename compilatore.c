#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

void compile_and_run(const char *file_name) {
    FILE *f = fopen(file_name, "r");
    if (f == NULL) {
        printf("Errore nell'apertura del file.\n");
        return;
    }

    char content[10000]; // Assuming a maximum of 10,000 characters in the file
    fread(content, sizeof(char), 10000, f);
    fclose(f);

    // Perform translations
    char *translations[][2] = {
        {"#includi", "#include"},
        {"intero", "int"},
        {"galleggiante", "float"},
        {"doppia", "double"},
        {"vocabolo", "char"},
        {"booleana", "bool"},
        {"vero", "true"},
        {"falso", "false"},
        {"per", "for"},
        {"finche", "while"},
        {"fai", "do"},
        {"ritorna", "return"},
        {"stampa", "printf"},
        {"principale", "main"}
    };

    int num_translations = sizeof(translations) / sizeof(translations[0]);
    for (int i = 0; i < num_translations; ++i) {
        char *to_replace = translations[i][0];
        char *replace_with = translations[i][1];
        char *pos = strstr(content, to_replace);
        while (pos != NULL) {
            strncpy(pos, replace_with, strlen(replace_with));
            memmove(pos + strlen(replace_with), pos + strlen(to_replace), strlen(pos + strlen(to_replace)) + 1);
            pos = strstr(content, to_replace);
        }
    }

    // Write translated content to a new file
    f = fopen("main.c", "w");
    if (f == NULL) {
        printf("Errore nella creazione del file.\n");
        return;
    }
    fprintf(f, "%s", content);
    fclose(f);

    // Compile and run
    system("gcc main.c -o main && rm main.c");
    system("./main");
}

int main() {
    char file_name[100];
    printf("Inserisci il nome del file: ");
    scanf("%s", file_name);
    compile_and_run(file_name);
    return 0;
}
