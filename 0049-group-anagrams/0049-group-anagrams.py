class Solution(object):
    def groupAnagrams(self, strs):
        """
        :type strs: List[str]
        :rtype: List[List[str]]
        """

        s = [''.join(sorted(i)) for i in strs]
        
        m = {}
        ret = []
        for o, n in zip(strs, s):
            if n in m:
                ret[m[n]].append(o)
            else:
                m[n] = len(ret)
                ret.append([])
                ret[len(ret) - 1].append(o)
        return ret