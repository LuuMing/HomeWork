class Solution:
    def wordPattern(self, pattern: 'str', str: 'str') -> 'bool':
        split = str.split(' ')
        if len(split) != len(pattern):
            return False
        return len(set(split)) == len(set(pattern)) == len(set(zip(split,pattern)))
