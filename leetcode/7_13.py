from typing import List
from typing import Optional

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def is_num(self, s: str):
        try:
            float(s)
            return True
        except ValueError:
            pass
        try:
            import unicodedata
            unicodedata.numeric(s)
            return True
        except Exception:
            pass
        return False
    def evalRPN(self, tokens: List[str]) -> int:
        st = []
        for c in tokens:
            if self.is_num(c):
                st.append(int(c))
            else:
                num2 = st.pop(-1)
                num1 = st.pop(-1)
                if c == '+':
                    st.append(num1+ num2)
                if c == '-':
                    st.append(num1 - num2)
                if c == '*':
                    st.append(num1 * num2)
                if c == '/':
                    st.append(int(num1 / num2))
        return st[0]

    def generateParenthesis(self, n: int) -> List[str]:
        ret = []
        tmp = []
        def dfs(left, right):
            if len(tmp) == 2 * n:
                ret.append(''.join(tmp))
                return
            if left < n:
                tmp.append('(')
                dfs(left+1, right)
                tmp.pop(-1)
            if left > right:
                tmp.append(')')
                dfs(left, right+1)
                tmp.pop(-1)
        dfs(0, 0)
        return ret
    
    def generateParenthesis2(self, n: int) -> List[str]:
        dp = [[] for _ in range(n+1)]
        dp[0].append('')

        for i in range(1, n+1):
            for p in range(i):
                L = dp[p]
                R = dp[i-1-p]
                for l in L:
                    for r in R:
                        dp[i].append(f'({l}){r}')
        return dp[n]
    
    def generateParenthesis3(self, n: int) -> List[str]:
        mem = [None for _ in range(n+1)]
        mem[0] = [""]

        def recur(m):
            if mem[m] != None:
                return mem[m]
            
            tmp = []
            for c in range(m):
                for l in recur(c):
                    for r in recur(n-1-c):
                        tmp.append(f'({l}){r}')
            mem[m] = tmp
            return tmp
        recur(n)
        return mem[n]

    # No15 三数之和
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        ret = []
        nums.sort()
        for k in range(len(nums)-2):
            if k != 0 and nums[k] == nums[k-1]:
                continue
            i = k + 1
            j = len(nums) - 1
            while i < j:
                if nums[i] + nums[j] + nums[k] < 0:
                    i += 1
                    while i < j and nums[i] == nums[i-1]:
                        i += 1
                elif nums[i] + nums[j] + nums[k] > 0:
                    j -= 1
                    while i < j and nums[j] == nums[j+1]:
                        j -= 1
                else:
                    ret.append([nums[i], nums[j], nums[k]])
                    i, j = i + 1, j - 1
                    while i < j and nums[i] == nums[i-1]:
                        i += 1
                    while i < j and nums[j] == nums[j+1]:
                        j += 1
        return ret


    # No98 验证二叉搜索树
    def isValidBST(self, root: Optional[TreeNode]) -> bool:
        if not root or (not root.left and not root.right):
            return True
        
        l, r = self.isValidBST(root.left), self.isValidBST(root.right)
        if not l or not r:
            return False
        
        
        def findm(r, mode):
            if mode == 0:   # find most left one
                while r.left:
                    r = r.left
            else:
                while r.right:
                    r = r.right
            return r.val
        
        l_m = findm(root.left, 1)
        r_m = findm(root.right, 0)
        return l_m <= root.val and root.val <= r_m
    

    # No322. 零钱兑换
    def coinChange(self, coins: List[int], amount: int) -> int:
        ret = float('inf')
        tmp = []
        coins.sort()
        def search():
            nonlocal ret
            if sum(tmp) == amount:
                ret = min(ret, len(tmp))
            
            if sum(tmp) > amount:
                return

            for i in range(len(coins)):
                tmp.append(coins[i])
                search()
                tmp.pop(-1)
        
        search()
        return ret if ret != float('inf') else -1
            

        



so = Solution()
# so.evalRPN(
# ["10","6","9","3","+","-11","*","/","*","17","+","5","+"])
# so.generateParenthesis3(2)
so.threeSum(
[-2,0,0,2,2])