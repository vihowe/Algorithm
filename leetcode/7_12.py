from typing import List


class Solution:
    def combine(self, n: int, k: int) -> List[List[int]]:
        ret = []
        tmp = []
        def dfs(t: int):
            if len(tmp) == k:
                ret.append(list(tmp))
                return
            if t > n:
                return
            
            for ne in range(t+1, n+1):
                tmp.append(ne)
                dfs(ne)
                tmp.pop(-1)
        dfs(0)
        return ret
                

    # No216 组合总和3
    def combinationSum3(self, k: int, n: int) -> List[List[int]]:
        ret = []
        tmp = []
        def dfs(t):
            if sum(tmp) == n and len(tmp) == k:
                ret.append(list(tmp))
                return
            if sum(tmp) > n or len(tmp) > k:
                return
            
            for ne in range(t+1, 10):
                tmp.append(ne)
                dfs(ne)
                tmp.pop(-1)
        
        dfs(0)
        return ret
            
    # No17 电话号码的字母组合
    def letterCombinations(self, digits: str) -> List[str]:
        n = len(digits)
        ret = []
        if n == 0:
            return ret
        tmp = []
        candidate_set = {
            '2': ['a', 'b', 'c'],
            '3': ['d', 'e', 'f'],
            '4': ['g', 'h', 'i'],
            '5': ['j', 'k', 'l'],
            '6': ['m', 'n', 'o'],
            '7': ['p', 'q', 'r', 's'],
            '8': ['t', 'u', 'v'],
            '9': ['w', 'x', 'y', 'z'],
        }
        def dfs(cur):
            if len(tmp) == n:
                ret.append(''.join(list(tmp)))
                return
            
            s_ne = digits[cur]

            candidates = candidate_set[s_ne]
            for candidate in candidates:
                tmp.append(candidate)
                dfs(cur+1)
                tmp.pop(-1)

        dfs(0)
        return ret

    # No39 组合总和
    def combinationSum(self, candidates: List[int], target: int) -> List[List[int]]:
        candidates.sort()
        n = len(candidates)
        ret = []
        if n == 0:
            return ret
        tmp = []

        def search(cur):
            if sum(tmp) == target:
                ret.append(list(tmp))
                return
            if sum(tmp) > target:
                return

            for j in range(cur, n):
                if len(tmp) + candidates[j] > target:
                    break
                tmp.append(candidates[j])
                search(j)
                tmp.pop(-1)
        search(0)
        return ret


    # No40 组合总和2
    def combinationSum2(self, candidates: List[int], target: int) -> List[List[int]]:
        ret = []
        tmp = []
        candidates.sort()
        def search(cur_idx):
            if sum(tmp) == target:
                ret.append(list(tmp))
            if cur_idx == len(candidates):
                return
            
            for j in range(cur_idx, len(candidates)):
                if sum(tmp) + candidates[j] > target:
                    break
                tmp.append(candidates[j])
                search(j+1)
                tmp.pop(-1)
        search(0)
        return ret
    
    # No131 分割回文串
    def partition(self, s: str) -> List[List[str]]:



solution = Solution()
print(solution.letterCombinations("7"))
