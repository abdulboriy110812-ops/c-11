#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// void mashq1(void)
// {

//      typedef struct
//     {
//         char name[50];
//         int age;
//         char address[50];
//     }Kollej;

//     typedef struct
//     {
//         char name[50];
//         int age;
//         char addres[50];
//         char universitet_nomi[50];
//         char yonalish[50];

//     }Universitet;

//     Kollej k1 = {"Eldor",17,"Kasmanaf"};
//     Kollej k2 = {"Diyorbek",15,"Garadok"};
//     Universitet t1 = {"Asadbek",20,"Navoiy","harward","Dasturlash"};
//     Universitet t2 = {"Ziyo",15,"Dangara","harward","Grafik dizynerlik"};

//     printf("\n\nKollej oquvchising ism:%s\nyoshi:%d\nmanzili:%s\n", k1.name, k1.age, k1.address);
//     printf("\n\nTalaba ism:%s\nTalaba yoshi:%d\nmanzili:%s\nuniversitet:%s\nYonalishi:%s", t1.name, t1.age, t1.addres,t1.universitet_nomi,t1.yonalish);

// }

void mashq1(void)
{
    typedef struct
    {
        char name[50];
        double price;
        int quantity;
    } Product;

    
        Product products[10] = {
            {"Non", 4000, 20},
            {"Sut", 12000, 10},
            {"Olma", 15000, 8},
            {"Guruch", 18000, 15},
            {"Shakar", 14000, 12},
            {"Yog", 22000, 7},
            {"Choy", 25000, 5},
            {"Makaron", 9000, 14},
            {"Tuxum", 1500, 30},
            {"Pechenye", 18000, 6}
        };

        double jami = 0;
        double max = products[0].price;
        double min = products[0].price;
        char maxname[50];
        char minname[50];
        int topildi = 0;
        char qidiruv[40];
        scanf("%s",qidiruv);
        for (int i = 0; i < 10; i++)
        {
            jami += products[i].price * products[i].quantity;


            if (max < products[i].price)
            {
                max = products[i].price;
                strcpy(maxname,products[i].name);
            }
            if(min > products[i].price)
            {
                min = products[i].price;
                strcpy(minname,products[i].name);

            }


            if (strcmp(qidiruv,products[i].name) == 0)
            {
                
                printf("\nMahsulot:%s\nmahsulotning narxi:%.1f\nmahsulotning qanchaligi:%d\n",products[i].name,products[i].price,products[i].quantity);
                topildi = 1;
            }
            
            
        }

        if (topildi == 0)
        {
            printf("\nMahsulot topilmadi");
        }

        printf("\nEng arzon mahsulot:%s\nEng arzon mahsulotning narxi:%.1f",minname,min);
        printf("\nEng qimmat mahsulot:%s\nEng qimamt mahsulotning narxi:%.1f",maxname,max);
        printf("jami qiymat:%lf\n",jami);
        
        
    
}

int main(void)
{

    mashq1();
    return 0;
}
