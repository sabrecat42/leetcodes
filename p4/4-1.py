class Solution(object):
    def findMedianSortedArrays(self, nums1, nums2):
        """
        :type a: List[int]
        :type b: List[int]
        :rtype: float
        """

        n = len(nums1)
        m = len(nums2)

        current_a = current_b = 0

        n_plus_m = n+m
        if n_plus_m % 2 != 0:
            median_index = n_plus_m // 2
        else:
            median_index = (n_plus_m // 2) - 1

        # odd n + m
        if n_plus_m % 2 != 0:
            for i in range(0, median_index+1):
                if len(nums1) == current_a:
                    return nums2[median_index + current_b - i]
                if len(nums2) == current_b:
                    return nums1[median_index + current_a - i]
                # if a[0] > b[0]:
                if nums1[current_a] > nums2[current_b]:
                    if i == median_index:
                        # return b.pop(0)
                        return nums2[current_b]
                    else:
                        # b.pop(0)
                        current_b+=1
                else:
                    if i == median_index:
                        # return a.pop(0)
                        return nums1[current_a]
                    else:
                        # a.pop(0)
                        current_a+=1
        else:
            # for even n+m
            partial_sum = None
            for i in range(0, median_index+2):
                if len(nums1) == current_a:
                    if partial_sum is None:
                        return (nums2[median_index + current_b - i] + nums2[median_index + current_b + 1 - i]) / 2.0
                    else:
                        # print(f"l48: partial_sum = {partial_sum}")
                        return (partial_sum + nums2[median_index + current_b + 1 - i]) / 2.0
                elif len(nums2) == current_b:
                    if partial_sum is None:
                        return (nums1[median_index + current_a - i] + nums1[median_index + current_a + 1 - i]) / 2.0
                    else:
                        return (partial_sum + nums1[median_index + current_a + 1 - i]) / 2.0

                if nums1[current_a] > nums2[current_b]:
                    if i == median_index:
                        # partial_sum = b.pop(0)
                        partial_sum = nums2[current_b]
                        current_b+=1
                    elif i == median_index + 1:
                        # return (partial_sum + b.pop(0)) / 2
                        return (partial_sum + nums2[current_b]) / 2.0
                    else:
                        # b.pop(0)
                        current_b+=1
                else:
                    if i == median_index:
                        # partial_sum = a.pop(0)
                        partial_sum = nums1[current_a]
                        current_a+=1
                    elif i == median_index + 1:
                        # return (partial_sum + a.pop(0)) / 2
                        return (partial_sum + nums1[current_a]) / 2.0
                    else:
                        # a.pop(0)
                        current_a+=1

if __name__ == '__main__':
    a = Solution()
    print(a.findMedianSortedArrays([2,3,4], [1]))
