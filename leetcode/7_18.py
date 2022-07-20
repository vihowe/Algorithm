from typing import List
class Solution:
    def lastStoneWeightII(self, stones: List[int]) -> int:
        target = sum(stones) // 2
        dp = [0 for _ in range(target+1)]

        for i in range(len(stones)):
            for j in range(target, 0, -1):
                if j - stones[i] >= 0:
                    dp[j] = max(dp[j], dp[j-stones[i]]+stones[i])
        
        return sum(stones) - target - dp[target]
