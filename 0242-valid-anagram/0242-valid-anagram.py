class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        # s = ''.join(sorted(s))
        # t = ''.join(sorted(t))
        # return s == t

        hashSet1, hashSet2 = dict(), dict()
        if len(s) != len(t):
            return False
        
        for i in range(len(s)):
            hashSet1[s[i]] = 1 + hashSet1.get(s[i], 0)
            hashSet2[t[i]] = 1 + hashSet2.get(t[i], 0)

        for c in hashSet1:
            if hashSet1[c] != hashSet2.get(c, 0):
                return False
        return True
        