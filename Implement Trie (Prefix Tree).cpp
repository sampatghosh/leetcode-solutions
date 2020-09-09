class Trie {
    Trie *next[26];
    bool end = false;
public:
    /** Initialize your data structure here. */
    Trie() {
        memset(next, 0, sizeof next);
    }

    /** Inserts a word into the trie. */
    void insert(string word) {
        Trie *curr = this;
        for(char c : word) {
            if(!curr->next[c-'a'])
                curr->next[c-'a'] = new Trie();
            curr = curr->next[c-'a'];
        }
        curr->end = true;
    }

    /** Returns if the word is in the trie. */
    bool search(string word) {
        Trie *curr = this;
        for(char c : word) {
            if(!curr->next[c-'a'])
                return false;
            curr = curr->next[c-'a'];
        }
        if(curr->end)
            return true;
        else
            return false;
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        Trie *curr = this;
        for(char c : prefix) {
            if(!curr->next[c-'a'])
                return false;
            curr = curr->next[c-'a'];
        }
        return true;
    }
};
