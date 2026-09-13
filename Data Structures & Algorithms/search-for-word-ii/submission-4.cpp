class Solution {
public:
    vector<string> result;  // To store found words
    int m, n;               // Dimensions of the board

    // TrieNode structure: stores children and word-related data
    struct trieNode {
        bool endOfWord;        // Flag to mark end of a word
        string word;           // The word associated with this node
        trieNode* children[26]; // Array for 26 possible children (a-z)
        
        trieNode() { 
            for(int i = 0; i < 26; i++) {
                children[i] = nullptr; // Initialize all children to nullptr
            }
            endOfWord = false;   // Not end of word initially
            word = "";           // No word associated initially
        }
    };

    // Helper function to create a new trie node
    trieNode* getNode() {
        trieNode* newNode = new trieNode();  // Create a new TrieNode
        return newNode;                      // Return the newly created node
    }

    // Insert a word into the Trie
    void insert(trieNode* root, string& word) {
        trieNode* crawler = root;  // Start from root
        for(int i = 0; i < word.length(); i++) {
            char ch = word[i];  // Get the character at index 'i'
            if(crawler->children[ch - 'a'] == nullptr) {
                crawler->children[ch - 'a'] = getNode(); // Create a new node if it doesn't exist
            }
            crawler = crawler->children[ch - 'a']; // Move to the next node
        }
        crawler->endOfWord = true; // Mark the end of the word
        crawler->word = word;      // Store the word at the end of the node
    }

    // DFS function to explore the board and find words
    void findWords(vector<vector<char>>& board, int i, int j, trieNode* root) {
        if(i < 0 || i >= m || j < 0 || j >= n) return;   // Out of bounds
        if(board[i][j] == '#' || root->children[board[i][j] - 'a'] == nullptr) return; // Already visited or no match

        char temp = board[i][j];   // Save the current character
        root = root->children[temp - 'a'];   // Move to the next node in Trie

        // If we find a complete word, add it to the result
        if(root->endOfWord) {
            result.push_back(root->word);  // Add the word to the result
            root->endOfWord = false; // Avoid duplicates by marking it as non-end
        }

        board[i][j] = '#'; // Mark the current cell as visited (using '#' or any unique symbol)

        // Explore all 4 directions (left, right, up, down)
        vector<vector<int>> directions{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        for(const vector<int>& dir : directions) {
            int new_i = i + dir[0];   // New row
            int new_j = j + dir[1];   // New column
            findWords(board, new_i, new_j, root); // Recursive DFS call
        }

        board[i][j] = temp; // Restore the original character after DFS
    }

    // Main function to find all words in the board
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        m = board.size();           // Set the number of rows
        n = board[0].size();        // Set the number of columns
        trieNode* root = getNode(); // Create the root node for Trie

        // Insert all words into the Trie
        for(string& word : words) {
            insert(root, word);
        }

        // Start DFS for every cell on the board
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                char ch = board[i][j];
                if(root->children[ch - 'a'] != nullptr) {
                    findWords(board, i, j, root); // Start DFS if Trie has matching child
                }
            }
        }

        return result; // Return the result containing all found words
    }
};
