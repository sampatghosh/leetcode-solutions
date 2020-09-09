class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        int carry = 0, flag = 0;
        for(int i = n - 1; i >= 0; --i) {
            if(i == n-1) {
                digits[i] += 1;
                if(digits[i]<10) {
                    flag = 1;
                    break;
                }
                carry = digits[i] / 10;
                digits[i] %= 10;
            }
            else {
                digits[i] += carry;
                if(digits[i]<10) {
                    flag = 1;
                    break;
                }
                carry = digits[i] / 10;
                digits[i] %= 10;
            }
        }
        if(flag==1)
            return digits;
        else {
            vector<int> out;
            out.push_back(carry);
            for(int i = 0;i < n;++i)
                out.push_back(digits[i]);
            return out;
        }
    }
};