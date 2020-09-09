class Solution(object):
    def count(self, matrix, mid):
        row = len(matrix)-1
        col = 0
        res = 0
        while row >= 0 and col < len(matrix[0]):
            if matrix[row][col] > mid:
                row -= 1
            else:
                res += row + 1
                col += 1
        return res
    
    def kthSmallest(self, matrix, k):
        m = len(matrix)
        n = len(matrix[0])
        low = matrix[0][0]
        high = matrix[m-1][n-1]
        ans = 0
        while low <= high:
            mid  = (low + high) / 2
            dis = Solution().count(matrix,mid)
            if dis < k:
                low = mid + 1
            else:
                ans = mid
                high = mid - 1
        return ans