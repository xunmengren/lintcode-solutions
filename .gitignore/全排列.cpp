class Solution {
public:
    /*
     * @param nums: A list of integers.
     * @return: A list of permutations.
     */
    vector<vector<int>> result;
    void digui_sw(int left,int right,vector<int> nums){
        if (left == right){
            result.push_back(nums);
            return ;
        }
        for (int i = left;i <= right;i++){
            swap (nums[i],nums[left]);
            digui_sw(left+1,right,nums);
            swap (nums[i],nums[left]);
        }
    }
    
    vector<vector<int>> permute(vector<int> &nums) {
        // write your code here
        //递归
        sort (nums.begin(),nums.end());
        if (nums.size() == 0){
            vector<int> tmp;
            result.push_back(tmp);
        }
        digui_sw(0,nums.size()-1,nums);
        return result;
    }
    
};
