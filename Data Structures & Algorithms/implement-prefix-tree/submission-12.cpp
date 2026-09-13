// Prefix Tree / Trie Implementation
class PrefixTree {
private:
    // Node structure for Trie
    struct TrieNode {
        TrieNode *children[26]; // Each node can have up to 26 children (for 'a'-'z')
        bool isEndOfWord;       // True if node represents the end of a word

        TrieNode() { // Constructor
            for(int i = 0; i < 26; i++) {
                children[i] = nullptr; // Initially no children
            }
            isEndOfWord = false;       // Initially not end of any word
        }
    };

public:
    TrieNode *root; // Root of the Trie

    // Constructor for PrefixTree
    PrefixTree() {
        root = new TrieNode(); // Initialize root node
    }
    
    // Insert a word into the Trie
    void insert(string word) {
        TrieNode *node = root; // Start from root
        for(int i = 0; i < word.size(); i++) {
            int index = word[i] - 'a'; // Map character to index 0-25
            if(node->children[index] == nullptr) {
                node->children[index] = new TrieNode(); // Create node if not exists
            }
            node = node->children[index]; // Move to child node
        }
        node->isEndOfWord = true; // Mark last node as end of word
    }
    
    // Search for a word in the Trie
    bool search(string word) {
        TrieNode *node = root; // Start from root
        for(char ch : word) {
            int index = ch - 'a'; 
            if(node->children[index] == nullptr) {
                return false; // If child doesn't exist, word not found
            }
            node = node->children[index]; // Move to child
        }
        return node->isEndOfWord; // Word found only if end node is true
    }
    
    // Check if there exists any word that starts with the given prefix
    bool startsWith(string prefix) {
        TrieNode *node = root; // Start from root
        for(char ch : prefix) {
            int index = ch - 'a';
            if(node->children[index] == nullptr) {
                return false; // Prefix not found
            }
            node = node->children[index]; // Move to child
        }
        return true; // All prefix letters found
    }
};
