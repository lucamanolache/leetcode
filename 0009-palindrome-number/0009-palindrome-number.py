class Solution(object):
    def isPalindrome(self, x):
        """
        :type x: int
        :rtype: bool
        """
        
        for i, j in zip(str(x), str(x)[::-1]):
            if i != j:
                return False
        return True