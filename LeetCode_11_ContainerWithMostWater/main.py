from typing import List
class Solution:
    def maxArea(self, height: List[int]) -> int:

        max_area = 0
        left = 0
        right = len(height) - 1
        min_height = 0

        while left < right:
            height_left = height[left]
            height_right = height[right]

            area = (right - left) * min(height_left, height_right)
            if area > max_area:
                max_area = area

            if height_right > height_left:
                while left < right and height[left] >= height[left + 1]:
                    left += 1
                left += 1
            else:
                while left < right and height[right] >= height[right - 1]:
                    right -= 1
                right -= 1

        return max_area
