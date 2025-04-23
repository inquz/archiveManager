#include "../include/input.h"
#include "../include/base.h"

void addTenantToInput(Stack* stack) {
    Tenant tenant;

    printf("������� ����� ��������: ");
    scanf("%d", &tenant.cardNumber);
    getchar();

    printf("������� ���: ");
    fgets(tenant.fullName, sizeof(tenant.fullName), stdin);
    tenant.fullName[strcspn(tenant.fullName, "\n")] = '\0';

    printf("������� ���������� �������: ");
    scanf("%d", &tenant.residentCount);
    getchar();

    printf("������� ���� ��������� (��.��.����): ");
    fgets(tenant.moveDate, sizeof(tenant.moveDate), stdin);
    tenant.moveDate[strcspn(tenant.moveDate, "\n")] = '\0';

    printf("������� ����� �������: ");
    scanf("%lf", &tenant.totalArea);
    getchar();

    printf("������� ���������� �������: ");
    scanf("%lf", &tenant.excessArea);
    getchar();

    push(stack, tenant);
}

void addTenantToKodif(Stack* stack) {
    Tenant tenant;

    printf("������� ����� ��������: ");
    scanf("%d", &tenant.cardNumber);
    getchar();

    printf("������� �����: ");
    fgets(tenant.address, sizeof(tenant.address), stdin);
    tenant.address[strcspn(tenant.address, "\n")] = '\0';

    push(stack, tenant);
}