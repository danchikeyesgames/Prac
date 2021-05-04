#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define STR 16
#define TECH 100

typedef struct data_in {
    char fam[STR];
    char inith[STR];
    char male;
    int numschool;
    int medl;
    int mark_math;
    int mark_Ru;
    int mark_inf;
    int zach;
} data;


void data_read(FILE *f, data *rec);
void data_write(FILE *f, data *rec);
void  add(const char name[40]);

data number[16] = {
    {"Ivanov", "V.E.", 'M', 42, 1, 100, 100, 100, 0},
    {"Gulkin", "L.S.", 'M', 125, 0, 95, 100, 75, 1},
    {"Zlotkovsky", "A.M.", 'M', 10, 1, 63, 50, 100, 1},
    {"Najibov", "K.T.", 'M', 10, 1, 55, 51, 65, 1},
    {"Musk", "I.K.", 'M', 42, 0, 4, 4, 4, 1},
    {"Alexandrov", "K.V.", 'M', 10, 0, 97, 97, 97, 0},
    {"Rzhevskay", "E.S.", 'F', 10, 1, 77, 77, 77, 1},
    {"Lobanova", "V.D.", 'F', 42, 1, 62, 34, 56, 0},
    {"Lisi4kina", "L.A.", 'F', 125, 0, 85, 80, 84, 0},
    {"Varnava", "E.R.", 'F', 125, 0, 92, 43, 37, 1},
    {"Jhons", "C.J.", 'M', 35, 0, 63, 44, 63, 1},
    {"Simonova", "D.P.", 'F', 35, 0, 44, 73, 93, 0},
    {"Moskovskay", "I.V.", 'F', 10, 0, 93, 93, 93, 1},
    {"Esenin", "S.A.", 'M', 10, 1, 100, 100, 100, 1},
    {"Ostin", "V.E.", 'M', 35, 0, 85, 95, 74, 1},
    {"Kirovsky", "A.S.", 'M', 777, 0, 55, 25, 35, 0}
};

int main (int argc, char const *argv[])
{

    int count = 0;
    _Bool isWord = 0;
    char ch;
    int k = 0;
    if (argv[1][0] == '-' && argv[1][1] == 'w' && argv[1][2] == '\0') {
        if (argc != 2) {
            fprintf(stderr, "%s\n", "You have many arguments!");
            exit(1);
        }

        FILE *f_ile = fopen("School.bin", "wb");
        for (int i = 0; i < 16; i++) {
            data_write(f_ile, &number[i]);
        }
        fclose(f_ile);

    } else if (argv[1][0] == '-' && argv[1][1] == 'f' && argv[1][2] == '\0') {
        
        if (argc != 3) {
            fprintf(stderr, "%s\n", "You have many arguments!");
            exit(1);
        }

        FILE *f_ile = fopen(argv[2], "rb");

        if (!f_ile) {
            fprintf(stderr, "%s\n", "Not found filename");
            exit(1);
        }

        data saved[TECH];
        
        while (
            fread(&(saved[k].fam), sizeof(saved->fam[0]), STR, f_ile) != 0 &&
            fread(&(saved[k].inith), sizeof(saved->inith[0]), STR, f_ile) != 0 &&
            fread(&(saved[k].male), sizeof(saved->male), 1, f_ile) != 0 &&
            fread(&(saved[k].numschool), sizeof(saved->numschool), 1, f_ile) != 0 &&
            fread(&(saved[k].medl), sizeof(saved->medl), 1, f_ile) != 0 &&
            fread(&(saved[k].mark_math), sizeof(saved->mark_math), 1, f_ile) != 0 &&
            fread(&(saved[k].mark_Ru), sizeof(saved->mark_Ru), 1, f_ile) != 0 &&
            fread(&(saved[k].mark_inf), sizeof(saved->mark_inf), 1, f_ile) != 0 &&
            fread(&(saved[k].zach), sizeof(saved->zach), 1, f_ile) != 0
        ) 
        {

            k++;

        }
        printf("%d\n", k);
        fclose(f_ile);

        printf("Фамилия \tИнициалы \tПол \t№ школы \tМедаль \tБаллы по математике \tБаллы по Русскому \tБаллы по Информатике \tЗачёт по Сочинению\n");
        for (int i = 0; i < k; i++) {
            fprintf(stdout, "%-15.10s %6s %11c %10d ", saved[i].fam , saved[i].inith, saved[i].male, saved[i].numschool);
            if (saved[i].medl == 1)
                printf("%13c ", '+');
            else
                printf("%13c ", '-');
            fprintf(stdout, "%14d %22d %25d ", saved[i].mark_math, saved[i].mark_Ru, saved[i].mark_inf);
            if (saved[i].zach == 1)
                printf("%20s", "+\n");
            else
                printf("%20s", "-\n");
        }

    } else if (argv[1][0] == '-' && argv[1][1] == 'p' && argv[1][2] == '\0') {
        if (argc != 4) {
            fprintf(stderr, "%s\n", "You have many arguments!");
            exit(1);
        }
        // **********************************************
        int in = -1;
        while (argv[2][++in] != '\0') {
            ch = tolower(argv[2][in]);
            if (isalpha(ch) || ispunct(ch))
                isWord = 1;
        }
        if (isWord) {
            fprintf(stderr, "%s\n", "You wrote not number after -p !");
            exit(1);
        }
        // ***********************************************
        
        
        in = -1;
        while (argv[2][++in] != '\0') {
            count = count * 10 + argv[2][in] - '0';
        }
        
        FILE *f_ile = fopen(argv[3], "rb");
        data saved[TECH];
        k = 0;
        while (
            fread(&(saved[k].fam), sizeof(saved->fam[0]), STR, f_ile) != 0 &&
            fread(&(saved[k].inith), sizeof(saved->inith[0]), STR, f_ile) != 0 &&
            fread(&(saved[k].male), sizeof(saved->male), 1, f_ile) != 0 &&
            fread(&(saved[k].numschool), sizeof(saved->numschool), 1, f_ile) != 0 &&
            fread(&(saved[k].medl), sizeof(saved->medl), 1, f_ile) != 0 &&
            fread(&(saved[k].mark_math), sizeof(saved->mark_math), 1, f_ile) != 0 &&
            fread(&(saved[k].mark_Ru), sizeof(saved->mark_Ru), 1, f_ile) != 0 &&
            fread(&(saved[k].mark_inf), sizeof(saved->mark_inf), 1, f_ile) != 0 &&
            fread(&(saved[k].zach), sizeof(saved->zach), 1, f_ile) != 0
        ) 
        {

            k++;

        }

        fclose(f_ile);


        printf("Фамилия \tИнициалы \tПол \t№ школы \tМедаль \tБаллы по математике \tБаллы по Русскому \tБаллы по Информатике \tЗачёт по Сочинению\n");
        for (int i = 0; i < k; i++) {

            if (saved[i].mark_math + saved[i].mark_Ru + saved[i].mark_inf == count) {
                fprintf(stdout, "%-15.10s %6s %11c %10d ", saved[i].fam , saved[i].inith, saved[i].male, saved[i].numschool);
                if (saved[i].medl == 1)
                    printf("%13c ", '+');
                else
                    printf("%13c ", '-');
                fprintf(stdout, "%14d %22d %25d ", saved[i].mark_math, saved[i].mark_Ru, saved[i].mark_inf);
                if (saved[i].zach == 1)
                    printf("%20s", "+\n");
                 else
                    printf("%20s", "-\n");
            }
        }
    } else if (argv[1][0] == '-' && argv[1][1] == 'd' && argv[1][2] == '\0') { 
        
        add(argv[2]);

    } else {
        printf("Error Format\n");
    }

    return 0;
}

void data_write(FILE *f, data *rec) {
    fwrite(&(rec->fam), sizeof(rec->fam[0]), STR, f);
    fwrite(&(rec->inith), sizeof(rec->inith[0]), STR, f);
    fwrite(&(rec->male), sizeof(rec->male), 1, f);
    fwrite(&(rec->numschool), sizeof(rec->numschool), 1, f);
    fwrite(&(rec->medl), sizeof(rec->medl), 1, f);
    fwrite(&(rec->mark_math), sizeof(rec->mark_math), 1, f);
    fwrite(&(rec->mark_Ru), sizeof(rec->mark_Ru), 1, f);
    fwrite(&(rec->mark_inf), sizeof(rec->mark_inf), 1, f);
    fwrite(&(rec->zach), sizeof(rec->zach), 1, f);
}

void data_read(FILE *f, data *rec) {
    fread(&(rec->fam), sizeof(rec->fam[0]), STR, f);
    fread(&(rec->inith), sizeof(rec->inith[0]), STR, f);
    fread(&(rec->male), sizeof(rec->male), 1, f);
    fread(&(rec->numschool), sizeof(rec->numschool), 1, f);
    fread(&(rec->medl), sizeof(rec->medl), 1, f);
    fread(&(rec->mark_math), sizeof(rec->mark_math), 1, f);
    fread(&(rec->mark_Ru), sizeof(rec->mark_Ru), 1, f);
    fread(&(rec->mark_inf), sizeof(rec->mark_inf), 1, f);
    fread(&(rec->zach), sizeof(rec->zach), 1, f);
}

void add(const char name[40])
{
    int count;
    FILE* new_file;
    data new_data;
    new_file = fopen(name, "rb");

    new_file = fopen(name, "a");
    printf("Enter how many records do you want to add\n");
    scanf("%d", &count);
    for (int i = 0; i < count; i++) {

        scanf("%s", new_data.fam);
        scanf("%s", new_data.inith);
        scanf("%s", &new_data.male); 
        scanf("%d", &new_data.numschool);
        scanf("%d", &new_data.medl);
        scanf("%d", &new_data.mark_math);
        scanf("%d", &new_data.mark_Ru);
        scanf("%d", &new_data.mark_inf);
        scanf("%d", &new_data.zach);
        data_write(new_file, &new_data);
    }
    fclose(new_file);
}