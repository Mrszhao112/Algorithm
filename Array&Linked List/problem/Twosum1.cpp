//给定一个整数数组 nums 和一个目标值 target，请你在该数组中找出和为目标值的那 两个 整数，并返回他们的数组下标。

//你可以假设每种输入只会对应一个答案。但是，数组中同一个元素不能使用两遍。

//暴力求
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
       vector<int> ret;
       int start = 0;
       int cur = 0;
       int flag = 0;
       for (start; start < nums.size(); start++) {
           int val = target - nums[start];
           for (cur = start + 1; cur < nums.size(); cur++) {
               if (nums[cur] == val) {
                   flag = 1;
                   break;
               }
           }
           if(flag == 1) {
               break;
           }
       }
       ret.push_back(start);
       ret.push_back(cur);
       return ret;
    }
};
//哈希
vector<int> twoSum(vector<int> &numbers, int target)
{
    //Key is the number and value is its index in the vector.
	unordered_map<int, int> hash;
	vector<int> result;
	for (int i = 0; i < numbers.size(); i++) {
		int numberToFind = target - numbers[i];

            //if numberToFind is found in map, return them
		if (hash.find(numberToFind) != hash.end()) {
                    //+1 because indices are NOT zero based
			result.push_back(hash[numberToFind] + 1);
			result.push_back(i + 1);			
			return result;
		}

            //number was not found. Put it in the map.
		hash[numbers[i]] = i;
	}
	return result;
}
