#include <stdio.h>
#include <stdlib.h>

int main() {
    int m = 3, n = 3;
    int a[m][n], z = 0, nz = 0;

    // Input
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("\nEnter No. ");
            scanf("%d", &a[i][j]);
        }
    }

    // Output
    printf("\nThe Matrix is:\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d\t", a[i][j]);
        }
        printf("\n");
    }

    // Traverse and count zero and non-zero elements
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (a[i][j] == 0) {
                z++;
                //printf("%d",z);
            } else {
                nz++;
                //printf("%d",nz);
            }
        }
    }

    // Check if the matrix is sparse
    if (nz >= z) {
        printf("Not a Sparse Matrix\n");
    } else {
        printf("The Matrix is Sparse\n");

        // Create a sparse matrix
        int s[nz][3], k = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (a[i][j] != 0) {
                    s[k][0] = i;
                    s[k][1] = j;
                    s[k][2] = a[i][j];
                    k++;
                }
            }
        }

        // Print the sparse matrix
        printf("The Sparse Matrix is:\n");
        printf("Row:\t, Column:\t, Value:\n");
        for (int i = 0; i < nz; i++) {
            printf("%d\t,%d\t,%d\n", s[i][0], s[i][1], s[i][2]);
        }
    }

    return 0;
}