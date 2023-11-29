

#include <stdio.h>

#define MAX_PROCESS 10
#define MAX_RESOURCES 10

typedef struct {
    int available[MAX_RESOURCES];
    int max[MAX_PROCESS][MAX_RESOURCES];
    int allocation[MAX_PROCESS][MAX_RESOURCES];
    int need[MAX_PROCESS][MAX_RESOURCES];
} BankersData;

void initializeData(BankersData *data, int numProcesses, int numResources) {
    printf("Enter available resources:\n");
    for (int i = 0; i < numResources; i++) {
        printf("Resource %d: ", i + 1);
        scanf("%d", &data->available[i]);
    }

    printf("\nEnter maximum demand of each process:\n");
    for (int i = 0; i < numProcesses; i++) {
        printf("For Process %d:\n", i + 1);
        for (int j = 0; j < numResources; j++) {
            printf("Resource %d: ", j + 1);
            scanf("%d", &data->max[i][j]);
        }
    }

    printf("\nEnter the current allocation for each process:\n");
    for (int i = 0; i < numProcesses; i++) {
        printf("For Process %d:\n", i + 1);
        for (int j = 0; j < numResources; j++) {
            printf("Resource %d: ", j + 1);
            scanf("%d", &data->allocation[i][j]);

            // Calculate need matrix
            data->need[i][j] = data->max[i][j] - data->allocation[i][j];
        }
    }
}

void displayData(BankersData *data, int numProcesses, int numResources) {
    printf("\nInputted Data (Table Format):\n");
    printf("Resource\tAvailable\tMaximum\t\tAllocation\tNeed\n");

    for (int i = 0; i < numResources; i++) {
        printf("R%d\t\t%d\t\t", i + 1, data->available[i]);

        for (int j = 0; j < numProcesses; j++) {
            printf("%d ", data->max[j][i]);
        }

        printf("\t\t");

        for (int j = 0; j < numProcesses; j++) {
            printf("%d ", data->allocation[j][i]);
        }

        printf("\t\t");

        for (int j = 0; j < numProcesses; j++) {
            printf("%d ", data->need[j][i]);
        }

        printf("\n");
    }
}

int main() {
    int numProcesses, numResources;

    printf("Enter the number of processes: ");
    scanf("%d", &numProcesses);

    printf("Enter the number of resources: ");
    scanf("%d", &numResources);

    if (numProcesses > MAX_PROCESS || numResources > MAX_RESOURCES) {
        printf("Error: Exceeded maximum limit of processes or resources.\n");
        return 1;
    }

    BankersData data;
    initializeData(&data, numProcesses, numResources);
    displayData(&data, numProcesses, numResources);

    return 0;
}
