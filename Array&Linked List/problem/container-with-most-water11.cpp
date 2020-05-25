//给你 n 个非负整数 a1，a2，...，an，每个数代表坐标中的一个点 (i, ai) 。
//在坐标内画 n 条垂直线，垂直线 i 的两个端点分别为 (i, ai) 和 (i, 0)。
//找出其中的两条线，使得它们与 x 轴共同构成的容器可以容纳最多的水。

class Solution {
public:
    int maxArea(vector<int>& height) {
        //左右夹逼 每次保存最大值直到跳出循环
        int left = 0;
        int right = height.size() - 1;
        int sum = 0; 
        while (left < right) {
            int cur_height = min(height[left], height[right]);
            if (sum < (right - left) * cur_height) {
                sum = (right - left) * cur_height;
            }
            if (height[left] < height [right]) {
                ++ left;
            }else {
                --right;
            }
        }
        return sum;
    }
};
