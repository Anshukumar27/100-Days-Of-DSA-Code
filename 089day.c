#include <stdio.h>

// Function to check if allocation is possible
int isPossible(int arr[], int n, int m, int maxPages) {
    int students = 1;
    int pagesSum = 0;

    for (int i = 0; i < n; i++) {
        // If a single book has more pages than maxPages → not possible
        if (arr[i] > maxPages)
            return 0;

        if (pagesSum + arr[i] <= maxPages) {
            pagesSum += arr[i];
        } else {
            // Allocate to next student
            students++;
            pagesSum = arr[i];

            if (students > m)
                return 0;
        }
    }
    return 1;
}

int allocateBooks(int arr[], int n, int m) {
    if (n < m) return -1;  // Not enough books

    int max = arr[0], sum = 0;

    // Find max and sum
    for (int i = 0; i < n; i++) {
        if (arr[i] > max)
            max = arr[i];
        sum += arr[i];
    }

    int low = max, high = sum;
    int result = sum;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (isPossible(arr, n, m, mid)) {
            result = mid;
            high = mid - 1;  // Try smaller value
        } else {
            low = mid + 1;   // Increase limit
        }
    }

    return result;
}

int main() {
    int n, m;

    scanf("%d %d", &n, &m);

    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int result = allocateBooks(arr, n, m);

    printf("%d\n", result);

    return 0;
}