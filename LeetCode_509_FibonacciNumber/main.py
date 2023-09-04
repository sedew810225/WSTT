class Solution:

    def fib(self, n: int) -> int:
        dt = [0 for _ in range(31)]

        dt[0] = 0
        dt[1] = 1

        for i in range (2,n+1) :
            dt[i] = dt[i-1] + dt[i-2]

        return dt[n]

    def fib1(self, n: int) -> int:
        if n == 0:
            return 0
        if n == 1:
            return 1

        return self.fib(n-1) + self.fib(n-2)