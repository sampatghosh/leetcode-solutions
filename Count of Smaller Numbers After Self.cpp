class Solution {
public:
    void merge(vector<pair<int,pair<int,int> > > &arr, int l, int m, int r) {
        int i, j, k;
        int n1 = m - l + 1;
        int n2 = r - m;
        vector<pair<int,pair<int,int> > > L(n1), R(n2);
        for (i = 0; i < n1; i++)
            L[i] = arr[l + i];
        for (j = 0; j < n2; j++)
            R[j] = arr[m + 1 + j];
        i = 0;
        j = 0;
        k = l;
        while (i < n1 && j < n2) {
            if (L[i] > R[j]) {
                L[i].second.second+=n2-j;
                arr[k] = L[i];
                i++;
            }
            else {
                arr[k] = R[j];
                j++;
            }
            k++;
        }
        while (i < n1) {
            arr[k] = L[i];
            i++;
            k++;
        }
        while (j < n2) {
            arr[k] = R[j];
            j++;
            k++;
        }
    }
    void mergeSort(vector<pair<int,pair<int,int> > > &vec, int l, int r) {
        if(l < r) {
            int mid = l + (r-l) / 2;
            mergeSort(vec,l,mid);
            mergeSort(vec,mid+1,r);
            merge(vec,l,mid,r);
        }
    }
    vector<int> countSmaller(vector<int>& nums) {
        vector<int> out(nums.size());
        vector<pair<int,pair<int,int> > > vec;
        for(int i = 0; i < nums.size(); ++i)
            vec.push_back(make_pair(nums[i],make_pair(i,0)));
        mergeSort(vec,0,nums.size()-1);
        for(int i = 0; i < nums.size(); ++i)
            out[vec[i].second.first] = vec[i].second.second;
        return out;
    }
};