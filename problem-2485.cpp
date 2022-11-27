class Solution {
public:
    int pivotInteger(int n) {
        int left = 0;
        int right = 0;
        for (int i = 1; i <= n; i++) 
            right += i;
        
        for (int i = 1; i <= n; i++) {
            right -= i;
            if (left == right)
                return i;
            left += i;
        }
        return -1;
    }

};
