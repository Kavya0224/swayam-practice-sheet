class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        int n=arr.size()-1;
        vector<int> vis(n+1,false);
        queue<int> q;
        q.push(start);
        while(!q.empty()){
            int idx=q.front();
            vis[idx]=true;
            q.pop();
            if(arr[idx]==0) return true;
            if(idx+arr[idx]<=n &&!vis[idx+arr[idx]])q.push(idx+arr[idx]);
            if(idx-arr[idx]>=0 &&!vis[idx-arr[idx]]) q.push(idx-arr[idx]);
        }
        return false;
    }
};