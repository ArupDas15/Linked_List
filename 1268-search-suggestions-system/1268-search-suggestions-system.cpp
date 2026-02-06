#define ALPHABET_SIZE 26
#define CHAR_TO_INDEX(c) ((int) c - (int) 'a')

struct Trienode {
    struct Trienode* children[ALPHABET_SIZE];
    bool isWordEnd;
};

struct Trienode* getNode(){
    Trienode* newNode = new Trienode;
    newNode->isWordEnd = false;

    for(int i = 0; i < ALPHABET_SIZE; i++) {
        newNode->children[i] = nullptr;
    }
    return newNode;
}

void insertKey(Trienode* root, const string& key) {
    Trienode* parentNode = root;
    for (char ch : key) {
        int index = CHAR_TO_INDEX(ch);
        if (parentNode->children[index] == nullptr) {
            parentNode->children[index] = getNode();
        }
        parentNode = parentNode->children[index];
    }
    parentNode->isWordEnd = true;
}

bool isLastNode(Trienode* root) {
    for(int i = 0; i < ALPHABET_SIZE; i++) {
        if (root->children[i] != nullptr) {
            return false;
        }
    }
    return true;
}
void suggestionsRec(Trienode* root, string currPrefix, vector<string>& ans) {
    if (ans.size() == 3) return;
    if (root->isWordEnd) ans.push_back(currPrefix);
    if (isLastNode(root)) return;
    for (int i = 0; i < ALPHABET_SIZE && ans.size() < 3; i++) {
        if (root->children[i]) {
            currPrefix.push_back('a' + i);
            suggestionsRec(root->children[i], currPrefix, ans);
            currPrefix.pop_back();
        }
    }
}
class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        Trienode* root = getNode();
        vector<vector<string>> res;

        // Construct the trie
        for(int i = 0; i < products.size(); i++) {
            insertKey(root, products[i]);
        }

        for(int i = 0; i < searchWord.length(); i++) {
            vector<string> ans;
            string query = searchWord.substr(0, i + 1);
            Trienode* pNode = root;
            bool found = true;

            for(char ch : query) {
                int index = CHAR_TO_INDEX(ch);
                
                if(!pNode->children[index]) {
                    found = false;
                    break;
                }
                pNode = pNode->children[index];
            }
            if (!found) {           
                // add empty suggestion for the query string
                res.push_back(ans);
                continue;
            }    
            bool isWord = pNode->isWordEnd;
            bool last = isLastNode(pNode);
            // if query is a word and does not have children
            if(isWord && last) {
                ans.push_back(query);
            }
            else {
                suggestionsRec(pNode, query, ans);
            }
            res.push_back(ans);
        }
        return res;
    }
};