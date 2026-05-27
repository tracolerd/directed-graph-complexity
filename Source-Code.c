#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
    int sizes[] = {1000, 2000, 3000, 4000, 5000};
    int num_cases = sizeof(sizes) / sizeof(sizes[0]);

    srand((unsigned)time(0));

    for (int case_num = 0; case_num < num_cases; case_num++) {
        int n = sizes[case_num];

        int **adj = (int **)malloc(n * sizeof(int *));
        for (int i = 0; i < n; i++)
            adj[i] = (int *)malloc(n * sizeof(int));

        int *indegree  = (int *)calloc(n, sizeof(int));
        int *outdegree = (int *)calloc(n, sizeof(int));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                adj[i][j] = (i == j) ? 0 : (rand() % 2);
            }
        }

        clock_t start = clock();

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (adj[i][j]) {
                    outdegree[i]++;
                    indegree[j]++;
                }
            }
        }

        clock_t end = clock();
        double time_ms = ((double)(end - start)) * 1000.0 / CLOCKS_PER_SEC;

        long long sum_in = 0, sum_out = 0;
        for (int i = 0; i < n; i++) {
            sum_in  += indegree[i];
            sum_out += outdegree[i];
        }

        printf("\nWhen n = %d\n", n);
        printf("Total In degree  = %lld\n", sum_in);
        printf("Total Out degree = %lld\n", sum_out);
        printf("Computation Time = %.3f ms\n", time_ms);

        if (sum_in == sum_out) printf("Here, Total In-degree == Total Out-degree\n");
        else                   printf("Error\n");

        for (int i = 0; i < n; i++) free(adj[i]);
        free(adj);
        free(indegree);
        free(outdegree);
    }
    return 0;
}

