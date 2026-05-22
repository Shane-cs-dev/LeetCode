#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        // Define the size of the array height
        int n = (int)height.size();

        // Create two pointers left and right for area calculation
        int left = 0;
        int right = n - 1;

        // operation
        int ans = 0;
        while (left < right) {
            // Calculate the area
            // Define height
            int currHeight = min(height[left], height[right]);
            // Update water in this container
            ans = max(ans, currHeight * (right - left));

            // Update the pointer
            // if left side is shorter or equal to right
            if (height[left] <= height[right]) {
                left++;
            }
            else {
                right--;
            }
        }

        return ans;
    }
};