#include <stdio.h>

// Function to check if it is possible to paint all boards within maxTime using k painters
int isPossible(int boards[], int n, int k, int maxTime) {
    int painters = 1;
    int currentSum = 0;

    for (int i = 0; i < n; i++) {
        if (boards[i] > maxTime) return 0;  // single board too large

        if (currentSum + boards[i] > maxTime) {
            painters++;
            currentSum = boards[i];

            if (painters > k) return 0;
        } else {
            currentSum += boards[i];
        }
    }
    return 1;
}

// Function to find minimum time
int minTime(int boards[], int n, int k) {
    int low = 0, high = 0;
    for (int i = 0; i < n; i++) {
        if (boards[i] > low) low = boards[i];  // longest board
        high += boards[i];                     // sum of all boards
    }

    int result = high;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (isPossible(boards, n, k, mid)) {
            result = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return result;
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k);

    int boards[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &boards[i]);
    }

    printf("%d\n", minTime(boards, n, k));
    return 0;
}
