class Codec {
public:
    string serialize(TreeNode * root) {
        string ret;
        if(!root)
            return "N ";
        ret += to_string(root->val) + " ";
        ret += serialize(root->left);
        ret += serialize(root->right);
        return ret;
    }
    TreeNode * deserialize(string data) {
        istringstream ss(data);
        return decode(ss);
    }
    TreeNode* decode(istringstream& ss) {
        string cur;
        ss >> cur;
        if(cur[0] == 'N' || cur.empty())
            return NULL;
        TreeNode *root = new TreeNode(stoi(cur));
        root->left = decode(ss);
        root->right = decode(ss);
        return root;
    }

};