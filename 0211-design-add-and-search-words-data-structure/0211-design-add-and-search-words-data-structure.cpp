#define ALPHABET_SIZE 26
#define CHAR_TO_INDEX(c) ((int) c - 'a')
struct Trienode {
    char c;
    bool isWordEnd;
    Trienode* children[ALPHABET_SIZE];
};
Trienode* pNode;

class WordDictionary {
public:
    WordDictionary() {
        pNode = new Trienode;
        pNode->c = '/';
        pNode->isWordEnd = false;
        for(int i = 0; i < ALPHABET_SIZE; i++) {
            pNode->children[i] = nullptr;
        }
    }
    
    void addWord(string word) {
        Trienode* pCrawl = pNode;
        for(int i = 0; i < word.length(); i++) {
            int index = CHAR_TO_INDEX(word[i]);
            if (!pCrawl->children[index]) {
                pCrawl->children[index] = new Trienode;
                pCrawl->children[index]->c = word[i];
                for(int j = 0; j < ALPHABET_SIZE; j++) {
                    pCrawl->children[index]->children[j] = nullptr;
                }
                pCrawl->children[index]->isWordEnd=false;
            }
            pCrawl = pCrawl->children[index];
        }
        pCrawl->isWordEnd=true;
    }
     bool searchHelper(const string& word, int idx, Trienode* node) {
    if (!node) return false;              // dead path
    if (idx == word.length())              // reached end of search word
        return node->isWordEnd;

    char ch = word[idx];

    if (ch == '.') {                       // wildcard: try all children
        for (int i = 0; i < ALPHABET_SIZE; i++) {
            if (node->children[i] && searchHelper(word, idx + 1, node->children[i]))
                return true;
        }
        return false;
    } else {                               // normal letter
        int index = ch - 'a';
        return searchHelper(word, idx + 1, node->children[index]);
    }
}
    bool search(string word) {
        return searchHelper(word, 0, pNode);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */