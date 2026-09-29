#include <stdio.h>
#include <string.h>

typedef struct
{
    int id;
    char title[100];
    char author[50];
    int year;
    int available;
    char borrower[50];
} Book;

void menu()
{
    printf("1.Kitob qoshish\n2.Barcha kitoblarni ochirish\n3.Kitobni qidirish(title boyicha)\n4.KItobni ochirish\n5.Ball boyicha sort\n6.Chiqish\n");
}

void kitob_qoshish()
{

    int tartib_raqam, yil, mavjudligi;
    char muqola[100], muallif[50], qarzdor[50];
    printf("Id,qachon yaratilgani,mavjudmi(1 yoki 0) shu larga javob bering:\n");
    scanf("%d %d %d", &tartib_raqam, &yil, &mavjudligi);
    printf("muqola,muallif,qarzdor shu larga javob bering:\n");
    scanf("%s %s %s", muqola, muallif, qarzdor);

    FILE *f = fopen("libary.txt", "a");

    fprintf(f, "%d\n%s\n%s\n%d\n%d\n%s\n",
            tartib_raqam, muqola, muallif,
            yil, mavjudligi, qarzdor);

    fclose(f);
}

void kitoblarni_korsatish(void)
{
    FILE *f = fopen("libary.txt", "r");
    int id, year, available;
    char title[100], author[50], borrower[50];

    while (fscanf(f, "%d\n%s\n%s\n%d\n%d\n%s\n",
                  &id, title, author, &year, &available, borrower) == 6)
    {
        printf("%d\n%s\n%s\n%d\n%d\n%s\n",
               id, title, author,
               year, available, borrower);
    }
    fclose(f);
}

void kitob_qidiruv(void)
{

    char userkitob_qidiruv[100];
    printf("Qaysi kitoni qidirmoqchisiz:");
    scanf("%s", userkitob_qidiruv);

    FILE *f = fopen("libary.txt", "r");

    int id, year, available;
    char title[100], author[50], borrower[50];
    int topildi = 0;

    while (fscanf(f, "%d\n%s\n%s\n%d\n%d\n%s\n",
                  &id, title, author, &year, &available, borrower) == 6)
    {

        if (strcmp(userkitob_qidiruv, title) == 0)
        {
            printf("%d\n%s\n%s\n%d\n%d\n%s\n",
                   id, title, author,
                   year, available, borrower);
            topildi = 1;
        }
    }

    if (topildi == 0)
    {
        printf("Afsus bundya kitob topilmadi");
    }

    fclose(f);
}

void kitob_ochirish(void)
{

    int id, year, available;
    char title[100], author[50], borrower[50];
    int idkitob_ochirish;
    printf("qaysi kitobni ochirmoqchisiz id sini kiriting");
    scanf("%d", &idkitob_ochirish);

    FILE *f = fopen("libary.txt", "r");
    FILE *f2 = fopen("temp.txt", "w");

    while (fscanf(f, "%d\n%s\n%s\n%d\n%d\n%s\n",
                  &id, title, author, &year, &available, borrower) == 6)
    {

        if (id != idkitob_ochirish)
        {
            fprintf(f2, "%d\n%s\n%s\n%d\n%d\n%s\n", id, title, author, year, available, borrower);
        }
    }

    fclose(f);

    fclose(f2);

    remove("libary.txt");
    rename("temp.txt", "libary.txt");
}

void kitob_sort(void)
{

    FILE *f2 = fopen("libary.txt", "r");

    Book arr[2];
    int n = 0;

    int id, year, available;
    char title[100], author[50], borrower[50];

    while (fscanf(f2, "%d\n%s\n%s\n%d\n%d\n%s\n",
                  &id, title, author, &year, &available, borrower) == 6)
    {
        arr[n].id = id;
        strcpy(arr[n].title, title);
        arr[n].year = year;
        strcpy(arr[n].author, author);
        arr[n].available = available;
        strcpy(arr[n].borrower, borrower);
        n++;
    }

    for (int i = 0; i < n - 1; i++)
    {
        

        for (int j = 0; j < n - 1 - i; j++)
        {
            if (arr[j].year > arr[j + 1].year)
            {

                Book temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    fclose(f2);

     f2 = fopen("libary.txt", "w");

    for (int i = 0; i < n; i++)
    {
        fprintf(f2, "%d\n%s\n%s\n%d\n%d\n%s\n",
                arr[i].id,
                arr[i].title,
                arr[i].author,
                arr[i].year,
                arr[i].available,
                arr[i].borrower);
    }

    fclose(f2);
    
}

void mashq1(void)
{

    menu();

    int tanlov;

    scanf("%d", &tanlov);

    switch (tanlov)
    {
    case 1:

        kitob_qoshish();
        break;
    case 2:
        kitoblarni_korsatish();
        break;
    case 3:
        kitob_qidiruv();
        break;
    case 4:
        kitob_ochirish();
        break;
    case 5:
        kitob_sort();
        break;
    case 6:
    printf("Siz saytdan chiqdingiz");
        return;

    default:

        break;
    }
}

int main(void)
{
    mashq1();

    return 0;
}