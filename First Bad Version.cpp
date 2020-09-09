class Solution {
public:
    long long int firstBadVersion(long long int r) {
        long long int l = 1;
        while(l < r) {
            long long int mid = (l + r) / 2;
            if(isBadVersion(mid))
                r = mid;
            else
                l = mid + 1;
        }
        return l;
    }
};