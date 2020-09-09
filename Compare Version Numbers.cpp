class Solution {
public:
    int compareVersion(string version1, string version2) {
        int l1 = version1.length();
        int l2 = version2.length();
        if(!l1 && !l2)
            return 0;
        string s = "";
        vector<int> a1,a2;
        for(int i = 0;i < l1; ++i) {
            if(version1[i]=='.') {
                a1.push_back(stoi(s));
                s = "";
            } else
                s += version1[i];
        }
        if(l1) {
            a1.push_back(stoi(s));
            s = "";
        }
        for(int i = 0;i < l2; ++i) {
            if(version2[i]=='.') {
                a2.push_back(stoi(s));
                s = "";
            } else
                s += version2[i];
        }
        if(l2) {
            a2.push_back(stoi(s));
        }
        int i1=0,ans = INT_MIN;
        while(i1 < a1.size() || i1 < a2.size()) {
            if(i1 < a1.size() && i1 < a2.size()) {
                if(a1[i1] > a2[i1]) {
                    if(ans == -1)
                        break;
                    else
                        ans = 1;
                } else if(a1[i1] < a2[i1]) {
                    if(ans == 1 )
                        break;
                    else
                        ans = -1;
                } else {
                    if(ans == -1 || ans == 1)
                        break;
                    else
                        ans = 0;
                }
            } else if (i1 < a1.size()) {
                if(a1[i1] > 0) {
                    if(ans == -1)
                        break;
                    else
                        ans = 1;
                } else if(a1[i1] < 0) {
                    if(ans == 1)
                        break;
                    else
                        ans = -1;
                } else if(a1[i1] == 0) {
                    if(ans == -1 || ans == 1)
                        break;
                    else
                        ans = 0;
                }
            } else {
                if(0 > a2[i1]) {
                    if(ans == -1 )
                        break;
                    else
                        ans = 1;
                } else if(0 < a2[i1]) {
                    if(ans == 1 )
                        break;
                    else
                        ans = -1;
                } else if (0 == a2[i1]) {
                    if(ans == -1 || ans == 1)
                        break;
                    else
                        ans = 0;
                }
            }
            ++i1;
        }
        return ans;
    }
};