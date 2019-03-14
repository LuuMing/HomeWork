class Solution:
    def distributeCandies(self, candies: List[int]) -> int:
        l = len(candies) / 2
        return int(min(len(set(candies)),l))
