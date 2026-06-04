
#Leetcode num 238  Product of Array Except Self
#Link: https://leetcode.com/problems/product-of-array-except-self/
def productExceptSelf(nums):
    n = len(nums)
    result = [1] * n
    
    # Calculate left products
    prefix = 1
    for i in range(n):
        result[i] = prefix
        prefix *= nums[i]


    # Calculate right products and multiply with left products
    postfix = 1
    for i in range(n - 1, -1, -1):
        result[i] *= postfix
        postfix *= nums[i]
    
    return result