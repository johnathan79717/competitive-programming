class Solution:
    def twoSum(self, numbers, target):
        index = range(len(numbers))
        index.sort(key=lambda i: numbers[i])
        l = 0
        r = len(numbers) - 1
        while l < r:
            if numbers[index[l]] + numbers[index[r]] < target:
                l += 1
            elif numbers[index[l]] + numbers[index[r]] > target:
                r -= 1
            elif index[l] < index[r]:
                return [index[l]+1, index[r]+1]
            else:
                return [index[r]+1, index[l]+1]