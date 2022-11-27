class Solution {
public:
    int countSubarrays(vector<int>& nums, int k) {
        int index = 0;
        for (int i = 0; i < nums.size(); i++)
            if (nums[i] == k)
                index = i;
        
        unordered_map<int, int> map;
        int pivot = 0;
        for (int l = index; l >= 0; l--) {
            if (nums[l] < k)
                pivot--;
            if (nums[l] > k)
                pivot++;
            
            map[pivot]++;
        }
        
        int count = 0;
        pivot = 0;
        for (int r = index; r < nums.size(); r++) {
            if (nums[r] < k)
                pivot--;
            
            if (nums[r] > k)
                pivot++;
            
            count += map[-pivot] + map[-pivot+1];
        }
        
        return count;
    }
};
