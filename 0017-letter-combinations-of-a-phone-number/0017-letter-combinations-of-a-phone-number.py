class Solution(object):
    mapping = {2: ["a", "b", "c"], 3: ["d", "e", "f"], 4: ["g", "h", "i"], 5: ["j", "k", "l"], 6: ["m", "n", "o"], 7: ["p", "q", "r", "s"], 8: ["t", "u", "v"], 9: ["w", "x", "y", "z"]}

    def letterCombinations(self, digits):
        """
        :type digits: str
        :rtype: List[str]
        """
        def lc(d):
            if not d:
                return [""]
            l = d[0]
            a = []
            for i in lc(d[1:]):
                a += [j + i for j in Solution.mapping[int(l)]]
            return a
        if digits == "":
            return []
        return lc(digits)