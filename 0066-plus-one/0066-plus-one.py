class Solution(object):
    def plusOne(self, digits):
        """
        :type digits: List[int]
        :rtype: List[int]
        """
        new = [d for d in digits]
        for i in reversed(range(len(digits))):
            if new[i] == 9:
                new[i] = 0
            else:
                new[i] = new[i] + 1
                return new
        
        return [1] + new