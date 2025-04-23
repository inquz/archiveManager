#include "../include/base.h"

void printTenantsWithExcessArea(const Stack* stack) {
    const float NORM = 13.0f;
    StackNode* current = stack->top;

    printSuccess("\nКвартиросъёмщики с лишней площадью:\n");
    printf("+----------+------------------+--------+------------+------------+---------+--------------------+\n");
    printf("|  Номер   |       ФИО        | Жители |    Дата    |   Площадь  | Избыток |   Площадь на чел.  |\n");
    printf("+----------+------------------+--------+------------+------------+---------+--------------------+\n");

    while (current != NULL) {
        float areaPerPerson = current->data.totalArea / current->data.residentCount;
        if (areaPerPerson > NORM) {
            printf("| ");
            printCenteredInt(current->data.cardNumber, 8);
            printf(" | ");
            printCentered(current->data.fullName, 16);
            printf(" | ");
            printCenteredInt(current->data.residentCount, 6);
            printf(" | ");
            printCentered(current->data.moveDate, 10);
            printf(" | ");
            printCenteredDouble(current->data.totalArea, 10, 2);
            printf(" | ");
            printCenteredDouble(current->data.excessArea, 7, 2);
            printf(" | ");

            // Несите костыль 1
            char formatted[32];
            snprintf(formatted, sizeof(formatted), "%.2f", areaPerPerson);
            int len = strlen(formatted);
            int width = 18;
            int left = (width - len) / 2;
            int right = width - len - left;

            for (int i = 0; i < left; ++i) putchar(' ');
            printSuccess("%s", formatted);
            for (int i = 0; i < right; ++i) putchar(' ');
            printf(" |\n");
        }
        current = current->next;
    }

    printf("+----------+------------------+--------+------------+------------+---------+--------------------+\n");
}

int compareAreaPerPerson(const void* a, const void* b) {
    float areaA = ((Tenant*)a)->totalArea / ((Tenant*)a)->residentCount;
    float areaB = ((Tenant*)b)->totalArea / ((Tenant*)b)->residentCount;
    if (areaA < areaB) return -1;
    if (areaA > areaB) return 1;
    return 0;
}

// Ёкарный бабай...
void printTopThreeMinimalAreaPerPerson(const Stack* stack) {
    if (stack->size < 3) {
        printError("Недостаточно записей для анализа (менее 3).\n");
        return;
    }

    Tenant* array = malloc(sizeof(Tenant) * stack->size);
    if (!array) {
        printError("Ошибка выделения памяти.\n");
        return;
    }

    StackNode* current = stack->top;
    int i = 0;
    while (current != NULL) {
        array[i++] = current->data;
        current = current->next;
    }

    qsort(array, stack->size, sizeof(Tenant), compareAreaPerPerson);

    printSuccess("\nТоп 3 квартиросъёмщика с минимальной площадью на человека:\n");
    printf("+----------+------------------+--------+------------+------------+---------+--------------------+\n");
    printf("|  Номер   |       ФИО        | Жители |    Дата    |  Площадь   | Избыток |   Площадь на чел.  |\n");
    printf("+----------+------------------+--------+------------+------------+---------+--------------------+\n");

    for (int j = 0; j < 3; j++) {
        float areaPerPerson = array[j].totalArea / array[j].residentCount;

        printf("| ");
        printCenteredInt(array[j].cardNumber, 8);
        printf(" | ");

        // Несите костыль 2
        char fioBuf[64];
        snprintf(fioBuf, sizeof(fioBuf), "%s", array[j].fullName);
        int fioLen = strlen(fioBuf);
        int fioWidth = 16;
        int fioLeft = (fioWidth - fioLen) / 2;
        int fioRight = fioWidth - fioLen - fioLeft;
        for (int k = 0; k < fioLeft; ++k) putchar(' ');
        printSuccess("%s", fioBuf);
        for (int k = 0; k < fioRight; ++k) putchar(' ');
        printf(" | ");

        printCenteredInt(array[j].residentCount, 6);
        printf(" | ");
        printCentered(array[j].moveDate, 10);
        printf(" | ");
        printCenteredDouble(array[j].totalArea, 10, 2);
        printf(" | ");
        printCenteredDouble(array[j].excessArea, 7, 2);
        printf(" | ");

        // Несите костыль 3
        char areaBuf[32];
        snprintf(areaBuf, sizeof(areaBuf), "%.2f", areaPerPerson);
        int areaLen = strlen(areaBuf);
        int areaWidth = 18;
        int areaLeft = (areaWidth - areaLen) / 2;
        int areaRight = areaWidth - areaLen - areaLeft;
        for (int k = 0; k < areaLeft; ++k) putchar(' ');
        printSuccess("%s", areaBuf);
        for (int k = 0; k < areaRight; ++k) putchar(' ');
        printf(" |\n");
    }

    free(array);
    printf("+----------+------------------+--------+------------+------------+---------+--------------------+\n");
}
