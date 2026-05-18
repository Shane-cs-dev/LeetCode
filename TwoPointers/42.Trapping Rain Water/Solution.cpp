#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    int trap_dp(vector<int> &height) {
        // Define the size of array height
        int n = (int)height.size();

        // Create two prefix sum to track max height from left and right
        vector<int> maxLeft(n, 0);
        vector<int> maxRight(n, 0);

        maxLeft[0] = height[0];
        maxRight[n - 1] = height[n - 1];

        // Initialization
        for (int i = 1; i < n; ++i) {
            maxLeft[i] = max(maxLeft[i - 1], height[i]);
        }
        for (int i = n - 2; i >= 0; --i) {
            maxRight[i] = max(maxRight[i + 1], height[i]);
        }

        // Calculation
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            ans += min(maxRight[i], maxLeft[i]) - height[i];
        }

        return ans;
    }

    int trap(vector<int> &height) {
        // Define the size of the array height
        int n = (int)height.size();

        // Create two pointers left and right for calculation
        int left = 0;
        int right = n - 1;

        // Define the maxLeft and maxRight
        int maxLeft = height[0];
        int maxRight = height[n - 1];

        // Loop through all locations from left and right pointer
        int ans = 0;
        while (left <= right) {         
            // Leak from left side, update left pointer
            if (maxLeft <= maxRight) {
                // Calculate left side
                maxLeft = max(maxLeft, height[left]);
                ans += maxLeft - height[left];
                left++;
            }
            else {
                // Calculate right side
                maxRight = max(maxRight, height[right]);
                ans += maxRight - height[right];
                right--;
            }
        }

        return ans;
    }
};