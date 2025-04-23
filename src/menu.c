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
        printf("|       ���� ���������� �������        |\n");
        printf("+--------------------------------------+\n");
        printf("|  1. �������� �����                   |\n");
        printf("|  2. ��������� ������ � �����         |\n");
        printf("|  3. �������� ������ � �����          |\n");
        printf("|  4. ������ ������                    |\n");
        printf("|  5. �������                          |\n");
        printf("|                                      |\n");
        printf("|  0. ����� �� ���������               |\n");
        printf("+--------------------------------------+\n");
        printSuccess("�������� ��������: ");

        if (fgets(inputBuffer, sizeof(inputBuffer), stdin) == NULL) {
            printError("\n������ ������ �����. ���������� �����.\n");
            continue;
        }

        inputResult = sscanf(inputBuffer, "%d", &choice);

        if (inputResult != 1 || choice < 0 || choice > 5) {
            printError("\n������: ������� ����� �� 0 �� 5!\n");
            continue;
        }

        switch (choice) {
        case 1: // ������ ������
            printf("\n�������� ������ ��� ������:\n");
            printf("1. input.txt\n");
            printf("2. kodif.txt\n");
            printf("0. �����\n");
            printSuccess("��� �����: ");
            fgets(inputBuffer, sizeof(inputBuffer), stdin);
            sscanf(inputBuffer, "%d", &subChoice);
            printf("\n");

            if (subChoice == 1) {
                if (currentFormat == INPUT_FORMAT)
                    printArchiveInput(&archive);
                else
                    printError("������: ����� �� �������� � ������� input.txt.\n");
            }
            else if (subChoice == 2) {
                if (currentFormat == KODIF_FORMAT)
                    printArchiveKodif(&archive);
                else
                    printError("������: ����� �� �������� � ������� kodif.txt.\n");
            }
            else if (subChoice != 0) {
                printError("�������� ����� �������.\n");
            }
            break;

        case 2: // �������� ������
            printf("\n�������� �������� ��� ��������:\n");
            printf("1. input.txt\n");
            printf("2. kodif.txt\n");
            printf("0. �����\n");
            printSuccess("��� �����: ");
            fgets(inputBuffer, sizeof(inputBuffer), stdin);
            sscanf(inputBuffer, "%d", &subChoice);
            printf("\n");

            if (subChoice == 1) {
                loadDataFromInput(&archive, "data/input.txt");
                currentFormat = INPUT_FORMAT;
                printSuccess("������ ��������� �� input.txt.\n");
            }
            else if (subChoice == 2) {
                loadDataFromKodif(&archive, "data/kodif.txt");
                currentFormat = KODIF_FORMAT;
                printSuccess("������ ��������� �� kodif.txt.\n");
            }
            else if (subChoice != 0) {
                printError("�������� ����� �������.\n");
            }
            break;

        case 3: // ���������� ������
            if (currentFormat == NONE) {
                printError("\n������� ��������� ����� ��� ���������� ������.\n");
                break;
            }

            printf("\n�������� ������ ����������:\n");
            printf("1. input.txt\n");
            printf("2. kodif.txt\n");
            printf("0. �����\n");
            printSuccess("��� �����: ");
            fgets(inputBuffer, sizeof(inputBuffer), stdin);
            sscanf(inputBuffer, "%d", &subChoice);
            printf("\n");

            if (subChoice == 1 && currentFormat == INPUT_FORMAT) {
                addTenantToInput(&archive);
                saveToArchive(&archive, "archive.bin");
                printSuccess("������ ��������� (input ������).\n");
            }
            else if (subChoice == 2 && currentFormat == KODIF_FORMAT) {
                addTenantToKodif(&archive);
                saveToArchive(&archive, "archive.bin");
                printSuccess("������ ��������� (kodif ������).\n");
            }
            else if (subChoice != 0) {
                printError("������: ������ ��������� ������� �������.\n");
            }
            break;

        case 4: // ������ ������
            if (currentFormat != INPUT_FORMAT) {
                printError("\n������ �������� ������ ��� ������ ������� input.txt.\n");
                break;
            }

            printf("\n�������� �������� �������:\n");
            printf("1. ������ � ������ ��������\n");
            printf("2. ��� 3 � ����������� �������� �� ������\n");
            printf("0. �����\n");
            printSuccess("��� �����: ");
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
                printError("�������� ����� �������.\n");
            }
            break;

        case 5: // �������
            printf("\n������� ������:\n");
            printf("1. �������� �����\n");
            printf("2. ������������� ����� (�������� �����)\n");
            printf("3. ������� �����\n");
            printf("0. �����\n");
            printSuccess("��� �����: ");
            fgets(inputBuffer, sizeof(inputBuffer), stdin);
            sscanf(inputBuffer, "%d", &subChoice);
            printf("\n");

            if (subChoice == 1) {
                clearArchive(&archive);
                currentFormat = NONE;
                saveToArchive(&archive, "archive.bin");
                printSuccess("����� ������� ������.\n");
            }
            else if (subChoice == 2) {
                shellSort("archive.bin");
                loadArchiveFromBin(&archive, "archive.bin");
                printSuccess("���������� ��������� � ������ ���������.\n");
            }
            else if (subChoice == 3) {
                deleteArchive("archive.bin");
            }
            else if (subChoice != 0) {
                printError("�������� ����� �������.\n");
            }
            break;

        case 0: // �����
            printSuccess("����� �� ���������...\n");
            break;
        }
    } while (choice != 0);

    clearArchive(&archive);
}