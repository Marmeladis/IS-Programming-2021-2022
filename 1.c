
#include <strings.h>
#include <stinf.h>
int main(int argc, char *argv[]) {
    FILE *f, *bf;
    f = fopen(argv[argc - 1], "r");//обычный
    bf = fopen(argv[argc - 1], "rb");//бинарный
    char flag = -1, flagn = -1;
    int (ch);
    int l = 1, w = 0, b = 0, i = 0;
    if (f != 0) printf("opened\n");
    else printf("file error\n");
    rewind(f);
    if (getc(f) == EOF) l = 0; //проверка на пустой файл
    rewind(f);
    while ((ch = fgetc(f)) != EOF){
        if (ch == '\n'){//подсчет строк и символов
            l ++;
            if (flag == 1) flag = -1;
            flagn = -1;
        }
        else if (ch == ' ') flag = -1;
        else if (ch == '\t') flag = -1;
        else if (flag == -1){
            w++;
            flag = 1;
        }
        if (ch != '\n') flagn = 1;
    }
    if (flagn == -1) l--;
    while (getc(bf) != EOF) b++;//подсчет байт
    for (int j = 1; j < argc; j++){//перебор аргументов
        if ((!strcmp(argv[j], "-h")) || (!strcmp(argv[j], "--help"))) printf("-l --lines: number of lines\n-w --words: number of words\n-c --bytes: size of file\n");
        if ((!strcmp(argv[j], "--lines")) || (!strcmp(argv[j], "-l"))) printf ("lines = %d\n", l);
        if ((!strcmp(argv[j], "--words")) || (!strcmp(argv[j], "-w"))) printf ("words = %d\n", w);
        if ((!strcmp(argv[j], "--bytes")) || (!strcmp(argv[j], "-c"))) printf ("bytes = %d\n", b);
    }
    return 0;
}