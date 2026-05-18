#Pseudo Code - (This is Prefix and Suffix Sum)

Algorithm trap(height):
	Input: array of int height
	Output: trapped water
	
	// Define the size of the array height
	n <- size(height)
	
	// Create two Prefix/Suffix sum to track the maxheight from left and right
	maxLeft <- array of size n, initialize to 0
	maxRight <- array of size n, initialize to 0
	
	// Initialize for 0 and n - 1 position for maxLeft and maxRight respectively
	maxLeft[0] <- height[0]
	maxRight[n - 1] <- height[n - 1]
	
	// Initialization
	for i from 1 to n - 1:
		maxLeft[i] <- max(maxLeft[i - 1], height[i])
	for i from n - 2 down to 0:
		maxRight[i] <- max(maxRight[i + 1], height[i])
		
	
	// Calculation
	ans <- 0
	for i from 0 to n - 1:
		ans <- ans + (min(maxLeft[i], maxRight[i]) - height[i])
	
	return ans

Complexity Analysis:
	Time complexity: 
		Build Prefix/Suffix Sum: O(2n)
		Calculation: O(n)
	Space complexity:
		Prefix/Suffix Sum: O(2n)


# Pseudo Code - Dynamically update prefix, suffix

Algorithm trap(height):
	Input: array of int height
	Output: trapped water
	
	// Define the size of the array
	n <- size(height)
	
	// Create two pointers left and right
	left <- 0
	right <- n - 1
	
	// Create two max value for calculation. dynamically calculation
	leftMax <- height[0]
	rightMax <- height[n - 1]
	
	// Calculation
	ans <- 0
	while (left <= right):
		if (leftMax <= rightMax):
			leftMax <- max(leftMax, height[left])
			ans <- ans + leftMax - height[left]
			left <- left + 1
		else:
			rightMax <- max(rightMax, height[right])
			ans <- ans + rightMax - height[right]
			right <- right - 1
	
	return ans

Complexity Analysis:
	Time complexity: O(n)
	Space complexity: O(1)

# Note
1. Dynamic programming with prefix and suffix sum array
2. Save the space by dynamically update the variables