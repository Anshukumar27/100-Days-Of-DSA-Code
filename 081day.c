#include <stdio.h>

int main() {
    int n;

  
    scanf("%d", &n);

    int nums[n];

    
    for(int i = 0; i < n; i++) {
        scanf("%d", &nums[i]);
    }

   
    for(int i = 0; i < n - 1; i++) {
        for(int j = 0; j < n - i - 1; j++) {
            if(nums[j] > nums[j + 1]) {
                
                int temp = nums[j];
                nums[j] = nums[j + 1];
                nums[j + 1] = temp;
            }
        }
    }

    for(int i = 0; i < n; i++) {
        printf("%d ", nums[i]);
    }

    return 0;
}