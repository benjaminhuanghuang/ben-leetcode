class Solution(object):
    def merge_sorted_array(self, nums1, m, nums2, n):
        for i in range(n):
            nums1[i + m] = nums2[i]
            nums1.sort()

    # http://www.lai18.com/content/10925511.html
    # http://www.jiuzhang.com/solutions/merge-sorted-array/
    def merge_sorted_array_2(self, nums1, m, nums2, n):
        i = m - 1
        j = n - 1
        index = m + n - 1

        while i >= 0 and j >= 0:
            if nums1[i] > nums2[j]:
                nums1[index] = nums1[i]
                index -= 1
                i -= 1
            else:
                nums1[index] = nums2[j]
                index -= 1
                j -= 1

        while i >= 0:
            nums1[index] = nums1[i]
            index -= 1
            i -= 1

        while j >= 0:
            nums1[index] = nums2[j]
            index -= 1
            j -= 1
