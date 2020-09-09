class Solution {
public:
    vector<int> original;
    Solution(vector<int>& nums) {
        original = nums;
    }

    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        return original;
    }

    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        vector<int> current = original;
        for(int i = 0; i < current.size(); ++i) {
            int id = i + rand()%(current.size()-i);
            swap(current[i],current[id]);
        }
        return current;
    }
};