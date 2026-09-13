class PrefixTree {
    private:
       struct TrieNode{
            TrieNode *children[26];
            bool isEndOfWord;
            TrieNode(){ //constructor
            for(int i=0;i<26;i++){
                children[i] = nullptr;
            }
            isEndOfWord = false;
            }
        };
public:
    TrieNode * root;
    PrefixTree() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode * root1 = root;
        for(int i=0;i<word.size();i++){
            int index = word[i]-'a';
            if(root1->children[index]==nullptr){
            root1->children[index] = new TrieNode();
            }
        root1=root1->children[index];    
        }
        root1->isEndOfWord = true;
    }
    
    bool search(string word) {
        TrieNode *root2 = root;
        for(char w1:word){
            int index = w1-'a';
            if(root2->children[index]==nullptr){
                return false;
            }
            root2=root2->children[index];
        }
        return root2->isEndOfWord;
    }
    
    bool startsWith(string prefix) {
        TrieNode *root2 = root;
        for(char w1:prefix){
            int index = w1-'a';
            if(root2->children[index]==nullptr){
                return false;
            }
            root2=root2->children[index];
        }
        return true;
    }
};
