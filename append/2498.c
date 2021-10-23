#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int interest;
    int weight;
} book_t;

void allFits() {
    const int length = 8;
    int numbers[] = {1, 2, 2, 3, 5, 1, 3, 5};
    int sum = 6;
    int sums[64];
    int s = 0;
    for (int i = 0; i < length; i++) {
        int currentSum = numbers[i];
        for (int j = 0; j < length; j++) {
            if (i == j) {
                continue;
            }
            if (currentSum + numbers[j] > sum) {
                sums[s++] = currentSum;
                currentSum = 0;
            } else {
                currentSum += numbers[j];
            }
        }
    }
    for (int i = 0; i < s; i++) {
        printf("s: %d\n", sums[i]);
    }
}

int main() {

    int bagMaxWeight, numberOfBooks, currentCase = 1;

    while (1) {
        scanf("%d %d", &numberOfBooks, &bagMaxWeight);

        if (bagMaxWeight == 0 && numberOfBooks == 0) {
            break;
        }

        book_t * books = (book_t *) malloc(numberOfBooks * sizeof(book_t));

        for (int i = 0; i < numberOfBooks; i++) {
            scanf("%d %d", &books[i].weight, &books[i].interest);
        }

        int * maxInterests = (int *) malloc(numberOfBooks * numberOfBooks * sizeof(int));
        int mi = 0;
        for (int i = 0; i < numberOfBooks; i++) {
            maxInterests[i] = books[i].interest;
            int usedWeight = books[i].weight;
            int usedInterests = books[i].interest;
            for (int j = 0; j < numberOfBooks; j++) {
                if (i == j) {
                    continue;
                }
                if (usedWeight + books[j].weight > bagMaxWeight) {
                    maxInterests[mi++] = usedInterests;
                    usedWeight = 0;
                } else {
                    usedInterests += books[j].interest;
                    usedWeight += books[j].weight;
                }
            }
        }
        
        int maxInterest = maxInterests[0];

        for (int i = 1; i < numberOfBooks; i++) {
            if (maxInterests[i] > maxInterest) {
                maxInterest = maxInterests[i];
            }
        }

        printf("Caso %d: %d\n", currentCase++, maxInterest);
    }
    return 0;
}