
#include <stdio.h>
int main() {
    int num_processes, num_resources;

    printf("Enter the number of processes: ");
    scanf("%d", &num_processes);

    printf("Enter the number of resources: ");
    scanf("%d", &num_resources);

    int available[num_resources];
    int max[num_processes][num_resources];
    int allocation[num_processes][num_resources];
    int need[num_processes][num_resources];
    int work[num_resources];
    int finish[num_processes];

    printf("Enter the available resources: ");
    for (int i = 0; i < num_resources; i++) {
        scanf("%d", &available[i]);
    }

    printf("Enter the maximum resources for each process:\n");
    for (int i = 0; i < num_processes; i++) {
        for (int j = 0; j < num_resources; j++) {
            scanf("%d", &max[i][j]);
        }
    }

    printf("Enter the allocated resources for each process:\n");
    for (int i = 0; i < num_processes; i++) {
        for (int j = 0; j < num_resources; j++) {
            scanf("%d", &allocation[i][j]);
            need[i][j] = max[i][j] - allocation[i][j];
        }
        finish[i] = 0;
    }

    // Initialize the work vector to be the available vector
    for (int i = 0; i < num_resources; i++) {
        work[i] = available[i];
    }

    int safe_sequence[num_processes];
    int count = 0;

    while (count < num_processes) {
        int found = 0;
        for (int i = 0; i < num_processes; i++) {
            if (finish[i] == 0) {
                int j;
                for (j = 0; j < num_resources; j++) {
                    if (need[i][j] > work[j]) {
                        break;
                    }
                }

                if (j == num_resources) {
                    for (int k = 0; k < num_resources; k++) {
                        work[k] += allocation[i][k];
                    }
                    safe_sequence[count] = i;
                    finish[i] = 1;
                    count++;
                    found = 1;
                }
            }
        }

        if (!found) {
            printf("System is in an unsafe state!\n");
            break;
        }
    }

    if (count == num_processes) {
        printf("System is in a safe state. Safe sequence is: ");
        for (int i = 0; i < num_processes; i++) {
            printf("p%d ", safe_sequence[i]);
        }
        printf("\n");
    }

    return 0;
}
