class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        vector<int> ans(nums.size());
        for(int i=0;i<nums.size();i++){
            if(nums[i]==2) ans[i]=-1;
            else{
                int temp=nums[i]/2;
                while((temp|temp+1)!=nums[i]){
                    temp++;
                }
                ans[i]=temp;
            }
        }
        return ans;
    }
};