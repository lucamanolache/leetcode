# The isBadVersion API is already defined for you.
# @param version, an integer
# @return a bool
# def isBadVersion(version):

class Solution(object):
    def firstBadVersion(self, n):
        """
        :type n: int
        :rtype: int
        """        
        def bs(s, n):
            if s >= n:
                return n
            m = s + (n - s) // 2
            if isBadVersion(m):
                return bs(s, m - 1)
            else:
                return bs(m + 1, n)
        a = bs(0, n)
        if isBadVersion(a):
            return a
        else:
            return a + 1
