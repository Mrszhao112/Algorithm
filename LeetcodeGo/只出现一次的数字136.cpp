//给定一个非空整数数组，除了某个元素只出现一次以外，其余每个元素均出现两次。找出那个只出现了一次的元素。

//说明：

//你的算法应该具有线性时间复杂度。 你可以不使用额外空间来实现吗

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        //相同的数字异或之后为零
        //0 异或任何数还是任何数字
        int ret = 0;
        for (int i = 0; i < nums.size(); i++) {
            ret ^= nums[i];
        }
        return ret;
    }
};
