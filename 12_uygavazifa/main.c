#include <stdio.h>
#include <string.h>

int mashq1(void)
{

    int xarajat1, xarajat2, xarajat3, xarajat4, xarajat5;

    scanf("%d\n%d\n%d\n%d\n%d", &xarajat1, &xarajat2, &xarajat3, &xarajat4, &xarajat5);

    FILE *f = fopen("xarajatlar.txt", "w");

    fprintf(f, "%d %d %d %d %d", xarajat1, xarajat2, xarajat3, xarajat4, xarajat5);

    fclose(f);

    f = fopen("xarajatlar.txt", "r");

    int xarajat[5] = {xarajat1, xarajat2, xarajat3, xarajat4, xarajat5};
    int yigindi = 0;
    for (int i = 0; i < 5; i++)
    {
        yigindi += xarajat[i];
    }

    printf("%d", yigindi);

    fclose(f);
}

void mashq2(void)
{

    typedef struct
    {
        char ism[30];
        double ball;
    } Student;

    Student students[5];
    int n = sizeof(students) / sizeof(students[0]);

    for (int i = 0; i < 5; i++)
    {
        printf("%d-student ismi: ", i + 1);
        scanf("%s", students[i].ism);

        printf("%d-student bali: ", i + 1);
        scanf("%lf", &students[i].ball);
    }

    FILE *f = fopen("natijalar.txt", "w");

    if (n <= 10)
    {
        for (int i = 0; i < n; i++)
        {
            fprintf(f, "%s ", students[i].ism);
            fprintf(f, "%lf\n", students[i].ball);
        }
    }

    fclose(f);

    f = fopen("natijalar.txt", "r");

    Student s;

    fscanf(f, "%s %lf", s.ism, &s.ball);
    double engkichik = s.ball;
    char engkichikism[20];
    strcpy(engkichikism, s.ism);

    while (fscanf(f, "%s %lf", s.ism, &s.ball) == 2)
    {

        if (s.ball < engkichik)
        {
            engkichik = s.ball;
            strcpy(engkichikism, s.ism);
        }
    }

    printf("%s:%lf", engkichikism, engkichik);

    fclose(f);
}

void mashq3(void)
{

    typedef struct
    {
        char name[50];
        char phone[20];
    } Contact;

    Contact contacts[5] = {
        {"Ali", "900550016"},
        {"Vali", "900540046"},
        {"Hasan", "920510216"},
        {"Sardor", "910250216"},
        {"Jasur", "900500216"}};

    FILE *f = fopen("phone.txt", "w");

    for (int i = 0; i < 5; i++)
    {
        fprintf(f, "%s: %s\n", contacts[i].name, contacts[i].phone);
    }

    fclose(f);

    Contact nextcontact = {"Eldor", "912345678"};

    f = fopen("phone.txt", "a");

    fprintf(f, "%s %s", nextcontact.name, nextcontact.phone);

    fclose(f);

    f = fopen("phone.txt", "r");

    Contact temporarycontact;

    while (fscanf(f, "%s %s", temporarycontact.name, temporarycontact.phone) == 2)
    {
        printf("%s--%s\n", temporarycontact.name, temporarycontact.phone);
    }

    fclose(f);

    char searchedphone[20];

    scanf("%s", searchedphone);

    f = fopen("phone.txt", "r");

    while (fscanf(f, "%s %s", temporarycontact.name, temporarycontact.phone) == 2)
    {
        if (strcmp(searchedphone, temporarycontact.name) == 0)
        {
            printf("%s", temporarycontact.phone);
        }
    }
    if (strcmp(searchedphone, temporarycontact.name) != 0)
    {
        printf("TOpilmadi");
    }

    fclose(f);
}


void mashq4(void){

    

}




int main(void)
{

    // mashq1();
    mashq2();

    mashq3();

    return 0;
}