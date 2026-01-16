class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        unordered_set<int>s;
        for(int x:nums)
        {
            if(s.count(x)) //set me unique elements hi store hote hai so is line me check krenge element ek se jada baar hai agar hai to wahi answer hai 
            {
                return x; //duplicate
            }
            s.insert(x); // and uske alawa baki elements ko insert krenge 
        }
        return -1;
    }
};