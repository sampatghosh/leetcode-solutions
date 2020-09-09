class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> out;
        if(digits.empty())
            return out;
        vector<string> pad={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        out.push_back("");
        for(int i=0;i<digits.length();++i) {
            int n = digits[i]-'0';
            if(n < 2)
                continue;
            string temp = pad[n];
            vector<string> inter;
            for(int j=0;j<temp.length();++j)
                for(int k=0;k<out.size();++k)
                    inter.push_back(out[k]+temp[j]);
            out.swap(inter);
        }
        return out;
    }
};