"""
Given a sorted array and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.

You may assume no duplicates in the array.

Example 1:

Input: [1,3,5,6], 5
Output: 2
"""
def searchInsert(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: int
        """
        index=0
        for val in nums:
            if target <= val :
                break
            index = index + 1
        return index
        
def searchInsert(self, nums: List[int], target: int) -> int:
        if target in nums:
            return nums.index(target)
        nums.append(target)
        nums.sort()
        return nums.index(target)
"""
Given an integer array nums, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.

Example:

Input: [-2,1,-3,4,-1,2,1,-5,4],
Output: 6
Explanation: [4,-1,2,1] has the largest sum = 6.
"""
def maxSubArray(self, nums: List[int]) -> int:
      max_sum = 0
      max_ending_here = 0

      for i in nums:
          max_ending_here += i
          # reset max_ending_here to 0 if it is negative
          # _this_ because we can use the max(nums) to find _out_ the largest negative num
          if max_ending_here < 0:
              max_ending_here = 0
          # _set_ the max_mum to be max_ending_here if max_ending_here is more than max_sum
          # this means that max_ending_here contains positive number and we need to keep track of them
          if max_ending_here > max_sum:
              max_sum = max_ending_here
      # return max_sum if it is not zero, otherwise return the largest single maximum number
      return max_sum if max_sum != 0 else max(nums)
      
   """
   Given a non-empty array of digits representing a non-negative integer, increment one to the integer.

The digits are stored such that the most significant digit is at the head of the list, and each element in the array contains a single digit.

You may assume the integer does not contain any leading zero, except the number 0 itself.

Example 1:

Input: [1,2,3]
Output: [1,2,4]
Explanation: The array represents the integer 123.
"""
    def plusOne(self, digits):
        """
        :type digits: List[int]
        :rtype: List[int]
        """
        number = int(digits[-1]) + 1
        index=len(digits)-1
        digits[index] = number
        while ( number >= 10 ):
            digits[index] = number % 10
            if index == 0 :
                digits.insert(0,number // 10)
                number= number // 10
            else :
                digits[ index -1 ] = number // 10 +digits[ index -1 ]
                number= digits[ index -1 ]
            index -= 1
        return digits
  """
  Given two binary strings, return their sum (also a binary string).

The input strings are both non-empty and contains only characters 1 or 0.

Example 1:

Input: a = "11", b = "1"
Output: "100"
  """
      def addBinary(self, a, b):
        """
        :type a: str
        :type b: str
        :rtype: str
        """
        if len(a) > len(b):
            length = len (b)
            result=['0']*len(a)
            for i in range(len(a)) :
                result[i]=a[i]
        else :
            length = len (a)
            result=['0']*len(b)
            for i in range(len(b)) :
                result[i]=b[i]
        yushu = 0
        index = -1
        for i in range(length):
            temp= int(a[index]) + int(b[index]) + yushu
            result[index]=str(temp%2)
            yushu = temp//2
            index -= 1
        index += max(len(a),len(b))
        while yushu != 0:
            if index < 0:
                result.insert(0,str(yushu))
                break
            temp = int(result[index]) + yushu
            result[index] = str(temp % 2)
            yushu = temp // 2
            index -= 1
        return ''.join(result)  
