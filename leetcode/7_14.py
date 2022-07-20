import collections
from typing import List, Optional

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    # No238. 除自身以外数组的乘积
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        n = len(nums)
        ans = [1 for _ in range(len(nums))]
        tmp = nums[0]
        for i in range(1, n):
            ans[i] *= tmp
            tmp *= nums[i]

        tmp = nums[-1]
        for j in range(n-2, -1, -1):
            ans[j] *= tmp
            tmp *= nums[j]
        
        return ans

    
    # 用栈实现中序遍历
    def inOrderTraverse(self, root: Optional[TreeNode]):
        if root is None:
            return []
        
        ans = []
        st = [root]
        while st or root:
            if root.left:
                st.append(root.left)
                root = root.left
            node = st.pop()
            ans.append(node.val)
            if node.right:
                root = node.right
        return ans

            
    # No210 课程表2
    def findOrder(self, numCourses: int, prerequisites: List[List[int]]) -> List[int]:
        # numCourses = 2, prerequisites = [[1,0]]
        indegree = [0 for _ in range(numCourses)]
        adj = [set() for _ in range(numCourses)]
        for prerequisite in prerequisites:
            course, pre = prerequisite
            indegree[course] += 1
            adj[pre].add(course)

        queue = collections.deque([c for c in range(numCourses) if indegree[c]==0])

        ans = []
        while queue:
            c = queue.pop()
            ans.append(c)
            for cc in adj[c]:
                indegree[cc] -= 1
                if indegree[cc] == 0:
                    queue.append(cc)
        
        return ans

    # No47. 全排列 II
    def permuteUnique(self, nums: List[int]) -> List[List[int]]:
        ans = []
        tmp = []
        n = len(nums)
        if n == 0:
            return ans
        
        nums.sort()
        visited = [0 for _ in range(n)]
        def dfs(idx):
            if idx == n:
                ans.append(tmp[:])
            
            for i in range(n):
                if visited[i] or (i > 0 and nums[i] == nums[i-1] and not visited[i-1]):
                    continue
                tmp.append(nums[i])
                visited[i] = 1
                dfs(idx+1)
                visited[i] = 0
                tmp.pop()
        dfs(0)
        return ans


    def uniquePathsWithObstacles(self, obstacleGrid: List[List[int]]) -> int:
        m, n = len(obstacleGrid), len(obstacleGrid[0])
        dp = [[0]*n for _ in range(m)]
        dp[0][0] = 1
        for j in range(n):
            dp[0][j] = 1
        
        flag = False
        for j in range(n):
            if obstacleGrid[0][j] == 1:
                flag = True
                break
        if flag:
            for k in range(j, n):
                dp[0][k] = 0
        
        flag = False
        for i in range(m):
            dp[i][0] = 1
        for i in range(m):
            if obstacleGrid[i][0] == 1:
                flag = True
                break
        if flag:
            for k in range(i, m):
                dp[k][0] = 0
        
        for i in range(1, m):
            for j in range(1, n):
                if obstacleGrid[i][j] == 1:
                    dp[i][j] = 0
                else:
                    dp[i][j] = dp[i-1][j] + dp[i][j-1]
        return dp[-1][-1]

    def integerBreak(self, n: int) -> int:
        dp = [1 for _ in range(n)]
        for i in range(3, n):
            for j in range(1, i-1):
                dp[i] = max(j * (i-j), dp[j] * (i-j), dp[i])
        return dp[n]
        
        
so = Solution()
so.uniquePathsWithObstacles(obstacleGrid=[[0,1],[0,0]])