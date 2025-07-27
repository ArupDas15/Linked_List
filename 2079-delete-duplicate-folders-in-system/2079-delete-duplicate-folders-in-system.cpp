class Solution {
    struct trienode {
    string folder;
    bool remove;
    map<string, trienode*> child;
    trienode(string folder) {
        this->folder = folder;
        this->remove = false;
    }
};
// Step 1: Build Trie.
void trieInsert(trienode* root, vector<string>& path) {
    for(auto &s: path) {
        if(!root->child.count(s)) {
	    root->child[s] = new trienode(s);
	}
	root = root->child[s];
    }
}
// Step 2: Serialise trie + Deduplicate
string markRepeating(trienode* root, unordered_map<string, trienode*>& visited){
    string subfolder;
    for(auto& [childfolder, childnode]: root->child) {
	subfolder += markRepeating(childnode, visited);
    }
    if(subfolder.length()) {
	// is the current node identical to any of the previously visited node.
        if(visited.count(subfolder)) {
	        visited[subfolder]->remove = true;
            root->remove = true;
        } else {
	    visited[subfolder] = root;
	}
    }
    return "[" + root->folder + subfolder + "]"; 
}
void savePath(trienode* root, vector<string>& cur_path, vector<vector<string>>& res) {
    if(root->remove) {
        return;
    }
    cur_path.push_back(root->folder);
    res.push_back(cur_path);
    for(auto &[subfolder,childnode]: root->child) {
        savePath(childnode, cur_path, res);
    }
    cur_path.pop_back();
}
public:
    vector<vector<string>> deleteDuplicateFolder(vector<vector<string>>& paths) {
        //Step-1: Insert all paths in TRIE.
	trienode* root = new trienode("/");
	for(auto& path: paths) {
	    trieInsert(root, path);
	}

	//Step-2: Mark repeating paths
	unordered_map<string, trienode*> visited;
	markRepeating(root, visited);

	//Step-3: Save the path after deletion
	vector<vector<string>> res;
	vector<string> cur_path;
	for(auto &[subfolder, childnode]: root->child) {
	    savePath(childnode, cur_path, res);
	}
        return res;
    }
};