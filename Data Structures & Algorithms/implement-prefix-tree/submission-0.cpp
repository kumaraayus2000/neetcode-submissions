class PrefixTree {

private:
    struct TrieNode{
        TrieNode * children[26]; //for 26 alphabet
        bool isEndOfWord;

        TrieNode(){
            for(int i=0;i<26;i++){
                children[i] = nullptr; //making all null
            }
        isEndOfWord = false; //making end false
        }
    };
    TrieNode *root;
public:
    PrefixTree() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode * node = root;

        for(char ch : word){
            int index = ch - 'a';
            if(node->children[index]==nullptr){
                node->children[index] = new TrieNode();
            }
        node = node->children[index];    
        }
        node->isEndOfWord = true;
    }
    
    bool search(string word) {
        TrieNode *node = root;

        for(char ch : word){
            int index = ch - 'a';
            if(node->children[index]==nullptr){
                return false;
            }
            node = node->children[index];
        }
        return node->isEndOfWord;
    }
    
    bool startsWith(string prefix) {
        TrieNode *node =root;
        for(char ch : prefix){
            int index = ch - 'a';
            if(node->children[index]==nullptr){
                return false;
            }
            node = node->children[index];
        }
        return true;
    }
};
