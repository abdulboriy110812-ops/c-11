#include <stdio.h>
#include <string.h>

struct Talaba
{
    char name[50];
    int age;
    double score;
};

void mashq1(void)
{

    struct Talaba t1 = {"Bekzod", 16, 5};
    struct Talaba t2 = {"ELdor", 14, 3};
    struct Talaba t3 = {"Shukurjon", 16, 4};

    printf("\n\nTalaba ism:%s\nTalaba yoshi:%d\nTalaba baxosi:%.1f\n", t1.name, t1.age, t1.score);

    printf("\n\nTalaba ism:%s\nTalaba yoshi:%d\nTalaba baxosi:%.1f\n", t2.name, t2.age, t2.score);

    printf("\n\nTalaba ism:%s\nTalaba yoshi:%d\nTalaba baxosi:%.1f\n\n", t3.name, t3.age, t3.score);

    double max = 0;
    int agemax = 0;
    char namemax[40];

    struct Talaba talabalar[3] = {t1, t2, t3};

    for (int i = 0; i < 3; i++)
    {
        if (talabalar[i].score > max)
        {
            max = talabalar[i].score;
            strcpy(namemax, talabalar[i].name);
            agemax = talabalar[i].age;
        }
    }

    printf("ENG yuqori ball olgan oquvchi:\nIsmi:%s\nYoshi%d\nBahosi:%.1f", namemax, agemax, max);
}

int main(void)
{

    mashq1();
    return 0;
}