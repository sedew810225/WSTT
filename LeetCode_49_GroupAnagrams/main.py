from collections import defaultdict
from typing import List
class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:

        dictstrs = defaultdict(list)

        for onestr in strs:
            sortedstr = ''.join(sorted(onestr))
            dictstrs[sortedstr].append(onestr)

        return list(dictstrs.values())