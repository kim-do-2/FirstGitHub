#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char* argv[]) {
    clock_t Start, Stop;
    int* arr;
    arr = (int*)malloc(sizeof(int) * 101);
    FILE* fp = fopen(argv[1], "r");
    int i = 0;
    printf("Input\t:");
    while (fscanf(fp, "%d", &arr[i]) != EOF) {
        printf("%d ", arr[i]);
        i += 1;
    }
    printf("\n");
    fclose(fp);

    Start = clock();
    int key, j, k;
    for (j = 1; j < i; j++) {
        key = arr[j];
        for (k = j - 1; k >= 0 && arr[k] > key; k--) {
            arr[k + 1] = arr[k];
        }
        arr[k + 1] = key;
    }
    Stop = clock();
    printf("Sorted\t:");
    for (int a = 0; a < i; a++) {
        printf("%d ", arr[a]);
    }
    printf("\n");
    double duration;
    duration = ((double)(Stop - Start)) / CLOCKS_PER_SEC;
    printf("\n[Finished in %f seconds]\n", duration);
    return 0;
}

