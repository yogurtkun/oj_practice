class Solution(object):
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        d = {}
        for i in range(len(nums)):
            if nums[i] not in d:
                d[nums[i]] = [i]
            else:
                d[nums[i]].append(i)
        for key in d.keys():
            if target - key == key:
                if len(d[key]) > 1:
                    return d[key]
                else:
                    continue
            if target - key in d:
                return [d[key][0],d[target- key][0]]