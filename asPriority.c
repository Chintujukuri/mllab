#include <stdio.h>
#include <stdlib.h>

// Structure to store process information
struct Process {
    char id[5];
    int priority;
};

// Function to compare processes based on priority for qsort
int compareProcesses(const void *a, const void *b) {
    return ((struct Process*)a)->priority - ((struct Process*)b)->priority;
}

int main() {
    int n;

    // Input the number of processes
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    // Array of processes
    struct Process processes[n];

    // Input process information
    for (int i = 0; i < n; ++i) {
        printf("Enter process ID for p%d: ", i + 1);
        scanf("%s", processes[i].id);
        printf("Enter priority value for p%d: ", i + 1);
        scanf("%d", &processes[i].priority);
    }

    // Sorting processes based on priority
    qsort(processes, n, sizeof(struct Process), compareProcesses);

    // Displaying the output
    printf("\nOutput:\n");
    printf("%-15s%-15s\n", "Process ID", "Priority Value");
    for (int i = 0; i < n; ++i) {
        printf("%-15s%-15d\n", processes[i].id, processes[i].priority);
    }

    return 0;
}
