class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        ans = []
        group = {}
        for s in strs:
            temp = "".join(sorted(s))
            if temp in group:
                group[temp].append(s)
            else:
                group[temp] = [s]
        for v in group.values():
            ans.append(v)
        return ans


        