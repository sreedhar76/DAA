#include <stdio.h>

struct Item {
    int weight;
    int value;
};

void knapsack(struct Item items[], int n, int capacity) {
    float totalValue = 0.0;
    int currentWeight = 0;

    for (int i = 0; i < n; i++) {
        if (currentWeight + items[i].weight <= capacity) {
            currentWeight += items[i].weight;
            totalValue += items[i].value;
        } else {
            int remaining = capacity - currentWeight;
            totalValue += items[i].value * ((float)remaining / items[i].weight);
            break;
        }
    }

    printf("Maximum value: %.2f\n", totalValue);
}

void sortItems(struct Item items[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            float r1 = (float)items[j].value / items[j].weight;
            float r2 = (float)items[j + 1].value / items[j + 1].weight;
            if (r1 < r2) {
                struct Item temp = items[j];
                items[j] = items[j + 1];
                items[j + 1] = temp;
            }
        }
    }
}

int main() {
    int n, capacity;

    printf("Enter number of items: ");
    scanf("%d", &n);
    struct Item items[n];

    printf("Enter weight and value of each item:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &items[i].weight, &items[i].value);
    }

    printf("Enter knapsack capacity: ");
    scanf("%d", &capacity);

    sortItems(items, n);
    knapsack(items, n, capacity);

    return 0;
}

