class Solution {
public:
    int jump(vector<int>& nums) {
        int l = 0;
        for(int i=0;i<nums.size()-1;) {
            int id=i+nums[i];
            ++l;
            if(id>=nums.size()-1)
                break;
            for(int j=i+1;j<nums.size() && j<=i+nums[i];++j) {
                if(j+nums[j]>=id+nums[id])
                    id=j;
            }
            i=id;
        }
        return l;
    }
};