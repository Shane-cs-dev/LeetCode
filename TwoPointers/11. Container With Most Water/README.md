### Pseudo Code
```test
Algorithm maxArea(height):
	Input: array of int height
	Output: maximum of area between two locations
	
	// Define the size of the array height
	n <- size(height)
	
	// Create two pointers to find the max area in between
	left <- 0
	right <- n - 1
	
	// Calculation
	ans <- 0 
	while (left < right):
		// define lowest height
		currHeight <- min(height[left], height[right])
		
		// Update the max area
		ans <- max(ans, (right - left) * currHeight)
		
		// Update the pointer, move the shorter one
		if (height[left] <= height[right]):
			left <- left + 1
		else:
			right <- right - 1
	
	return ans
```
### Complexity Analysis:
	Time complexity: O(n)
	Space complexity: O(1)