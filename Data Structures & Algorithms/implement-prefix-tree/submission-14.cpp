class PrefixTree {

private:
    // Node structure for Trie
    struct TrieNode {
        TrieNode *children[26]; // 26 children for each lowercase letter
        bool isendofword;       // true if this node represents the end of a word

        TrieNode() { 
            for(int i = 0; i < 26; i++) {
                children[i] = nullptr; // Initialize all children to nullptr
            }
            isendofword = false;      // Initially not end of a word
        }
    };

public:
    TrieNode *root; // Root of the Trie

    // Constructor
    PrefixTree() {
       root = new TrieNode(); 
    }
    
    // Insert a word into the Trie
    void insert(string word) {
        TrieNode *node = root; // Start from root
        for(int i = 0; i < word.size(); i++) {
            int ch = word[i] - 'a'; // Map character to index 0-25
            if(node->children[ch] == nullptr) {
                node->children[ch] = new TrieNode(); // Create node if not exists
            }
            node = node->children[ch]; // Move to child node
        }
        node->isendofword = true; // Mark the last node as end of word
    }
    
    // Search for a complete word in the Trie
    bool search(string word) {
        TrieNode *node = root; // Start from root
        for(int i = 0; i < word.size(); i++) {
            int index = word[i] - 'a';
            if(node->children[index] == nullptr) {
                return false; // Word not found
            }
            node = node->children[index]; // Move to next node
        }
        return node->isendofword; // Word exists only if end-of-word is true
    }
    
    // Check if there exists any word in the Trie that starts with given prefix
    bool startsWith(string prefix) {
        TrieNode *node = root; // Start from root
        for(int i = 0; i < prefix.size(); i++) {
            int index = prefix[i] - 'a';
            if(node->children[index] == nullptr) {
                return false; // Prefix not found
            }
            node = node->children[index]; // Move to next node
        }
        return true; // All prefix letters found
    }
};
