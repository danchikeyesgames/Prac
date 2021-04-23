#include <stdio.h>
#include <stdlib.h>
#define STR 16
#define TECH 16

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
int count(char num[STR][STR]);

data number[TECH] = {
    {"Ivanov", "V.E.", 'M', 42, 1, 5, 5, 5, 0},
    {"Gulkin", "L.S.", 'M', 125, 0, 5, 3, 5, 1},
    {"Zlotkovsky", "A.M.", 'M', 10, 1, 5, 5, 5, 1},
    {"Najibov", "K.T.", 'M', 10, 1, 5, 5, 5, 1},
    {"Musk", "I.K.", 'M', 42, 0, 4, 4, 4, 1},
    {"Alexandrov", "K.V.", 'M', 10, 0, 3, 4, 4, 0},
    {"Rzhevskay", "E.S.", 'F', 10, 1, 5, 5, 5, 1},
    {"Lobanova", "V.D.", 'F', 42, 1, 5, 5, 5, 0},
    {"Lisi4kina", "L.A.", 'F', 125, 0, 4, 4, 4, 0},
    {"Varnava", "E.R.", 'F', 125, 0, 3, 3, 3, 1},
    {"Jhons", "C.J.", 'M', 35, 0, 3, 4, 3, 1},
    {"Simonova", "D.P.", 'F', 35, 0, 4, 3, 3, 0},
    {"Moskovskay", "I.V.", 'F', 10, 0, 3, 3, 3, 1},
    {"Esenin", "S.A.", 'M', 10, 1, 5, 5, 5, 1},
    {"Ostin", "V.E.", 'M', 35, 0, 5, 5, 4, 1},
    {"Kirovsky", "A.S.", 'M', 777, 0, 5, 5, 5, 0}
};

int main (int argc, char const *argv[]) {

    int count = 0;

    if (argv[1][0] == '-' && argv[1][1] == 'w') {
        if (argc != 2) {
            fprintf(stderr, "%s\n", "You have many arguments!");
            exit(1);
        }

        FILE *f_ile = fopen("School.bin", "wb");

        for (int i = 0; i < TECH; i++) {
            data_write(f_ile, &number[i]);
        }

        fclose(f_ile);

    } else if (argv[1][0] == '-' && argv[1][1] == 'f') {
        if (argc != 2) {
            fprintf(stderr, "%s\n", "You have many arguments!");
            exit(1);
        }

        FILE *f_ile = fopen("School.bin", "rb");

        data saved[TECH];

        for (int i = 0; i < TECH; i++) {
            data_read(f_ile, &saved[i]);
        }

        fclose(f_ile);
        printf("Фамилия \tИнициалы \tПол \t№ школы \tМедаль \tоценка по математике \tоценка по Русскому \tоценка по Информатике \tЗачёт по Сочинению\n");
        for (int i = 0; i < TECH; i++) {
            fprintf(stdout, "%-15.10s %6s %11c %10d %13d %14d %22d %25d %20d\n", saved[i].fam , saved[i].inith, saved[i].male, saved[i].numschool, saved[i].medl,
            saved[i].mark_math, saved[i].mark_Ru, saved[i].mark_inf, saved[i].zach);
        }
    } else if (argv[1][0] == '-' && argv[1][1] == 'p') {
        if (argc != 3) {
            fprintf(stderr, "%s\n", "You have many arguments!");
            exit(1);
        }
        int in = -1;
        while (argv[2][++in] != '\0') {
            count = count * 10 + argv[2][in] - '0';
        }
        FILE *f_ile = fopen("School.bin", "rb");

        data saved[TECH];

        for (int i = 0; i < TECH; i++) {
            data_read(f_ile, &saved[i]);
        }

        fclose(f_ile);

        for (int i = 0; i < TECH; i++) {
            if (saved[i].mark_math + saved[i].mark_Ru + saved[i].mark_inf == count) {
                fprintf(stdout, "%-15.10s %6s %11c %10d %13d %14d %22d %25d %20d\n", saved[i].fam , saved[i].inith, saved[i].male, saved[i].numschool, saved[i].medl,
                saved[i].mark_math, saved[i].mark_Ru, saved[i].mark_inf, saved[i].zach);
            }
        }
    } else {
        printf("Error Format\n");
    }

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
