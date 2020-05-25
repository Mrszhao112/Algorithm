//给你一个包含 n 个整数的数组 nums，判断 nums 中是否存在三个元素 a，b，c ，使得 a + b + c = 0 ？请你找出所有满足条件且不重复的三元组。

//注意：答案中不可以包含重复的三元组。

//这道题可以用暴力方法与哈希表方法去完成 因为目前阶段为数组与链表部分 故下面的方法是暴力法求解 
//感兴趣的朋友可以尝试使用哈希表进行优化
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ret;
        sort(nums.begin(),nums.end());//先排序
        if (nums.size() < 3) { //特殊边界情况
            return ret;
        }
        if (nums[0] > 0) {
            return ret;
        }

        int left;
        int right;
        for (int i = 0; i < nums.size(); ++i) {
            if (i > 0 && nums[i] == nums[i-1]) { //去重
                continue;
            }

            left = i+1;
            right = nums.size() - 1;

            while (left < right) {
                int sum = nums[i] + nums[left] +nums[right]; 
                if (sum == 0) {
                    //元素入vector
                     ret.push_back(vector<int>{nums[i],nums[left],nums[right]});
                    //去重
                     while (left < right && nums[left] == nums[left+1]) {
                         ++left;
                     }
                     while (left < right && nums[right] == nums[right-1]) {
                         --right;
                     }
                     ++left;
                     --right;
                }else if (sum > 0) {
                    --right;
                }else {
                    ++left;
                }
            }
        }
        return ret;
    }
};
