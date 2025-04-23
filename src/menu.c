#include "../include/base.h"

void mainMenu() {
    Stack archive;
    initStack(&archive);
    ArchiveFormat currentFormat = NONE;

    int choice, subChoice;
    int inputResult;
    char inputBuffer[100];

    do {
        printf("\n");
        printf("+--------------------------------------+\n");
        printf("|       МЕНЮ УПРАВЛЕНИЯ АРХИВОМ        |\n");
        printf("+--------------------------------------+\n");
        printf("|  1. Показать архив                   |\n");
        printf("|  2. Загрузить данные в архив         |\n");
        printf("|  3. Добавить данные в архив          |\n");
        printf("|  4. Анализ данных                    |\n");
        printf("|  5. Утилиты                          |\n");
        printf("|                                      |\n");
        printf("|  0. Выйти из программы               |\n");
        printf("+--------------------------------------+\n");
        printSuccess("Выберите действие: ");

        if (fgets(inputBuffer, sizeof(inputBuffer), stdin) == NULL) {
            printError("\nОшибка чтения ввода. Попробуйте снова.\n");
            continue;
        }

        inputResult = sscanf(inputBuffer, "%d", &choice);

        if (inputResult != 1 || choice < 0 || choice > 5) {
            printError("\nОшибка: введите число от 0 до 5!\n");
            continue;
        }

        switch (choice) {
        case 1: // Печать архива
            printf("\nВыберите формат для печати:\n");
            printf("1. input.txt\n");
            printf("2. kodif.txt\n");
            printf("0. Назад\n");
            printSuccess("Ваш выбор: ");
            fgets(inputBuffer, sizeof(inputBuffer), stdin);
            sscanf(inputBuffer, "%d", &subChoice);
            printf("\n");

            if (subChoice == 1) {
                if (currentFormat == INPUT_FORMAT)
                    printArchiveInput(&archive);
                else
                    printError("Ошибка: архив не загружен в формате input.txt.\n");
            }
            else if (subChoice == 2) {
                if (currentFormat == KODIF_FORMAT)
                    printArchiveKodif(&archive);
                else
                    printError("Ошибка: архив не загружен в формате kodif.txt.\n");
            }
            else if (subChoice != 0) {
                printError("Неверный выбор формата.\n");
            }
            break;

        case 2: // Загрузка архива
            printf("\nВыберите источник для загрузки:\n");
            printf("1. input.txt\n");
            printf("2. kodif.txt\n");
            printf("0. Назад\n");
            printSuccess("Ваш выбор: ");
            fgets(inputBuffer, sizeof(inputBuffer), stdin);
            sscanf(inputBuffer, "%d", &subChoice);
            printf("\n");

            if (subChoice == 1) {
                loadDataFromInput(&archive, "data/input.txt");
                currentFormat = INPUT_FORMAT;
                printSuccess("Данные загружены из input.txt.\n");
            }
            else if (subChoice == 2) {
                loadDataFromKodif(&archive, "data/kodif.txt");
                currentFormat = KODIF_FORMAT;
                printSuccess("Данные загружены из kodif.txt.\n");
            }
            else if (subChoice != 0) {
                printError("Неверный выбор формата.\n");
            }
            break;

        case 3: // Добавление данных
            if (currentFormat == NONE) {
                printError("\nСначала загрузите архив для добавления данных.\n");
                break;
            }

            printf("\nВыберите формат добавления:\n");
            printf("1. input.txt\n");
            printf("2. kodif.txt\n");
            printf("0. Назад\n");
            printSuccess("Ваш выбор: ");
            fgets(inputBuffer, sizeof(inputBuffer), stdin);
            sscanf(inputBuffer, "%d", &subChoice);
            printf("\n");

            if (subChoice == 1 && currentFormat == INPUT_FORMAT) {
                addTenantToInput(&archive);
                saveToArchive(&archive, "archive.bin");
                printSuccess("Данные добавлены (input формат).\n");
            }
            else if (subChoice == 2 && currentFormat == KODIF_FORMAT) {
                addTenantToKodif(&archive);
                saveToArchive(&archive, "archive.bin");
                printSuccess("Данные добавлены (kodif формат).\n");
            }
            else if (subChoice != 0) {
                printError("Ошибка: нельзя смешивать форматы архивов.\n");
            }
            break;

        case 4: // Анализ данных
            if (currentFormat != INPUT_FORMAT) {
                printError("\nАнализ доступен только для данных формата input.txt.\n");
                break;
            }

            printf("\nВыберите действие анализа:\n");
            printf("1. Список с лишней площадью\n");
            printf("2. Топ 3 с минимальной площадью на одного\n");
            printf("0. Назад\n");
            printSuccess("Ваш выбор: ");
            fgets(inputBuffer, sizeof(inputBuffer), stdin);
            sscanf(inputBuffer, "%d", &subChoice);
            printf("\n");

            if (subChoice == 1) {
                printTenantsWithExcessArea(&archive);
            }
            else if (subChoice == 2) {
                printTopThreeMinimalAreaPerPerson(&archive);
            }
            else if (subChoice != 0) {
                printError("Неверный выбор анализа.\n");
            }
            break;

        case 5: // Утилиты
            printf("\nУтилиты архива:\n");
            printf("1. Очистить архив\n");
            printf("2. Отсортировать архив (Школьный Метод)\n");
            printf("3. Удалить архив\n");
            printf("0. Назад\n");
            printSuccess("Ваш выбор: ");
            fgets(inputBuffer, sizeof(inputBuffer), stdin);
            sscanf(inputBuffer, "%d", &subChoice);
            printf("\n");

            if (subChoice == 1) {
                clearArchive(&archive);
                currentFormat = NONE;
                saveToArchive(&archive, "archive.bin");
                printSuccess("Архив успешно очищен.\n");
            }
            else if (subChoice == 2) {
                shellSort("archive.bin");
                loadArchiveFromBin(&archive, "archive.bin");
                printSuccess("Сортировка завершена и данные обновлены.\n");
            }
            else if (subChoice == 3) {
                deleteArchive("archive.bin");
            }
            else if (subChoice != 0) {
                printError("Неверный выбор утилиты.\n");
            }
            break;

        case 0: // Выход
            printSuccess("Выход из программы...\n");
            break;
        }
    } while (choice != 0);

    clearArchive(&archive);
}