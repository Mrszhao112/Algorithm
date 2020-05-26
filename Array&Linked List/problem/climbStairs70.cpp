
//方法一 参考斐波那契额 但是计算量庞大 n==44时超时
//方法二 循环 
//方法三 动态规划
//代码如下
class Solution {
public:
    int climbStairs1(int n) {
        if ( n < 2) {
            return n;
        }else if (n == 2) {
            return 2;
        }
        
        return climbStairs(n-1) +climbStairs(n-2);
    }
    
    int climbStairs2(int n) {
        if (n < 2) {
            return n;
        }
        int a = 0;
        int b = 1;
        int c = 2;
        n -= 2;
        while (n--) {
            a = b;
            b = c;
            c = a + b;
        }
        return c;
    }
    
     int climbStairs3(int n) {
        if (n == 1) {
            return 1;
        }
        vector<int> dp;
        dp.reserve(n+1);
        dp[1] = 1;
        dp[2] = 2;
        for (int i = 3; i <= n; i++) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[n];
    }
};
