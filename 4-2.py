class Solution(object):
    def findMedianSortedArrays(self, nums1, nums2):
        """
        :type a: List[int]
        :type b: List[int]
        :rtype: float
        """
        a = nums1[:]
        b = nums2[:]

        n = len(a)
        m = len(b)

        n_plus_m = n+m
        if n_plus_m % 2 != 0:
            median_index = n_plus_m // 2
        else:
            median_index = (n_plus_m // 2) - 1

        # odd n + m
        if n_plus_m % 2 != 0:
            for i in range(0, median_index+1):
                if len(a) == 0:
                    return b[median_index - i]
                if len(b) == 0:
                    return a[median_index - i]
                # if a[0] > b[0]:
                if a[0] > b[0]:
                    if i == median_index:
                        return b.pop(0)
                        # return nums2[current_b]
                    else:
                        b.pop(0)
                        # current_b+=1
                else:
                    if i == median_index:
                        return a.pop(0)
                        # return nums1[current_a]
                    else:
                        a.pop(0)
                        # current_a+=1
        else:
            # for even n+m
            partial_sum = None
            for i in range(0, median_index+2):
                if len(a) == 0:
                    if partial_sum is None:
                        return (b[median_index - i] + b[median_index + 1 - i]) / 2.0
                    else:
                        return (partial_sum + b[median_index + 1 - i]) / 2.0
                elif len(b) == 0:
                    if partial_sum is None:
                        return (a[median_index - i] + a[median_index + 1 - i]) / 2.0
                    else:
                        return (partial_sum + a[median_index + 1 - i]) / 2.0

                if a[0] > b[0]:
                    if i == median_index:
                        partial_sum = b.pop(0)
                        # partial_sum = nums2[current_b]
                        # current_b+=1
                    elif i == median_index + 1:
                        return (partial_sum + b.pop(0)) / 2
                        # return (partial_sum + nums2[current_b]) / 2.0
                    else:
                        b.pop(0)
                        # current_b+=1
                else:
                    if i == median_index:
                        partial_sum = a.pop(0)
                        # partial_sum = nums1[current_a]
                        # current_a+=1
                    elif i == median_index + 1:
                        return (partial_sum + a.pop(0)) / 2
                        # return (partial_sum + nums1[current_a]) / 2.0
                    else:
                        a.pop(0)
                        # current_a+=1

if __name__ == '__main__':
    a = Solution()
    print(a.findMedianSortedArrays([2,3], [2,7]))
