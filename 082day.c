#include <stdio.h>

int lowerBound(int nums[], int n, int x) {
    int left = 0, right = n - 1;
    int ans = n; 

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (nums[mid] >= x) {
            ans = mid;
            right = mid - 1; 
        } else {
            left = mid + 1;  
        }
    }
    return ans;
}

int upperBound(int nums[], int n, int x) {
    int left = 0, right = n - 1;
    int ans = n;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (nums[mid] > x) {
            ans = mid;
            right = mid - 1; 
        } else {
            left = mid + 1;  
        }
    }
    return ans;
}

int main() {
    int n, x;
    scanf("%d", &n);

    int nums[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &nums[i]);
    }

    scanf("%d", &x);

    int lb = lowerBound(nums, n, x);
    int ub = upperBound(nums, n, x);

    printf("%d %d", lb, ub);

    return 0;
}