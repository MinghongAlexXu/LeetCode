class Solution:
    @staticmethod
    def getSum(a: int, b: int) -> int:
        mask = 0xffffffff
        a, b = a & mask, b & mask
        while b != 0:
            a, b = (a ^ b), (a & b) << 1 & mask
        return a if a <= 0x7fffffff else ~(a ^ mask)

assert Solution.getSum(1, 2) == 3
assert Solution.getSum(2, 3) == 5
