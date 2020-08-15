//给定一个数组 nums，编写一个函数将所有 0 移动到数组的末尾，同时保持非零元素的相对顺序。
//限制
//不能使用额外数组空间 尽量减少操作次数

//两种指针操作 
class Solution {
public:
    void moveZeroes1(vector<int>& nums) {
    int zero = 0;
    for (int i = 0; i < nums.size(); i++) { //移动非零到数组前面部分
        if (nums[i] != 0) {
            nums[zero++] = nums[i];
        }
    }
    for (int i = zero; i < nums.size(); i++) {//填充数组后面应该为零的元素
        nums[i] = 0;
    }
}

    void moveZeroes2(vector<int>& nums) {
    for (int zero = 0, cur = 0; cur < nums.size(); cur++) {// 一次循环遍历交换零与非零
        if (nums[cur] != 0) {
            swap(nums[zero++], nums[cur]);
        }
    }
}
};


class Solution {
public:
    void moveZeroes(vector<int>& nums) {//方案一优化
        int index = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] != 0) {
                nums[index] = nums[i];
                if (index != i) {
                    nums[i] = 0;
                }
                ++index;
            }
        }
    }
};
