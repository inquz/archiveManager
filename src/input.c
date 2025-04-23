#include "../include/input.h"
#include "../include/base.h"

void addTenantToInput(Stack* stack) {
    Tenant tenant;

    printf("¬ведите номер карточки: ");
    scanf("%d", &tenant.cardNumber);
    getchar();

    printf("¬ведите ‘»ќ: ");
    fgets(tenant.fullName, sizeof(tenant.fullName), stdin);
    tenant.fullName[strcspn(tenant.fullName, "\n")] = '\0';

    printf("¬ведите количество жителей: ");
    scanf("%d", &tenant.residentCount);
    getchar();

    printf("¬ведите дату заселени€ (дд.мм.гггг): ");
    fgets(tenant.moveDate, sizeof(tenant.moveDate), stdin);
    tenant.moveDate[strcspn(tenant.moveDate, "\n")] = '\0';

    printf("¬ведите общую площадь: ");
    scanf("%lf", &tenant.totalArea);
    getchar();

    printf("¬ведите избыточную площадь: ");
    scanf("%lf", &tenant.excessArea);
    getchar();

    push(stack, tenant);
}

void addTenantToKodif(Stack* stack) {
    Tenant tenant;

    printf("¬ведите номер карточки: ");
    scanf("%d", &tenant.cardNumber);
    getchar();

    printf("¬ведите адрес: ");
    fgets(tenant.address, sizeof(tenant.address), stdin);
    tenant.address[strcspn(tenant.address, "\n")] = '\0';

    push(stack, tenant);
}