class Solution {
public:
    /*
     * @param :  A list of integers
     * @return: A list of unique permutations
     */
    vector<vector<int>> result;
    bool not_find(int left,int k,vector<int> nums)
    {
	    if (k > left)
		    for (int i = left; i<k; i++)
			    if (nums[i] == nums[k])
				    return false;
	    return true;
    }
    
    void digui_sw(int left,int right,vector<int> nums){
        if (left == right){
            result.push_back(nums);
            return;
        }
        for (int i = left; i <= right; i++){
            if (not_find(left,i,nums)){
                swap (nums[i],nums[left]);
                digui_sw(left+1,right,nums);
                swap (nums[i],nums[left]);
            }
        }
    }
    vector<vector<int>> permuteUnique(vector<int> &nums) {
        // write your code here
        if (nums.size() == 0){
            result.push_back(nums);
            return result;
        }
        digui_sw(0,nums.size()-1,nums);
        return result;
    }
};
