class Solution(object):
    def canCross(self, stones):
        # Quick fail: if second stone is not at position 1, frog can't start
        if stones[1] != 1:
            return False
        
        # Store stone positions for O(1) lookup
        stone_set = set(stones)
        last_stone = stones[-1]
        
        # Memoization cache: (position, last_jump) -> bool
        memo = {}
        
        def dfs(position, last_jump) :
            # If reached the last stone
            if position == last_stone:
                return True
            
            # Check memoized result
            if (position, last_jump) in memo:
                return memo[(position, last_jump)]
            
            # Try jumps of k-1, k, k+1
            for jump in (last_jump - 1, last_jump, last_jump + 1):
                if jump > 0:  # jump must be positive
                    next_pos = position + jump
                    if next_pos in stone_set:
                        if dfs(next_pos, jump):
                            memo[(position, last_jump)] = True
                            return True
            
            memo[(position, last_jump)] = False
            return False
        
        # Start from position 1 with jump length 1
        return dfs(1, 1)
        
