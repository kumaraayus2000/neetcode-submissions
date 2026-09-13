class LRUCache {
public:
    list<int> dll; // Doubly Linked List to maintain order of usage (front = most recent, back = least recent)
    map<int, pair<list<int>::iterator, int>> mp; 
    // Map: key -> {iterator to DLL, value}
    int n; // Remaining capacity

    LRUCache(int capacity) {
        n = capacity; // Initialize capacity
    }

    // Helper function to mark a key as most recently used
    void makemostrecentlyused(int key) {
        // Remove the node from its current position in DLL
        dll.erase(mp[key].first);

        // Add it to the front of DLL (most recent)
        dll.push_front(key);

        // Update map with new iterator pointing to front
        mp[key].first = dll.begin();
    }

    // Get the value of the key if it exists, else return -1
    int get(int key) {
        if(mp.find(key) == mp.end()) {
            return -1; // Key not found
        }

        // Key exists, move it to front as most recently used
        makemostrecentlyused(key);

        // Return the value
        return mp[key].second;
    }

    // Insert or update the value of the key
    void put(int key, int value) {
        if(mp.find(key) != mp.end()) {
            // Key already exists, update value
            mp[key].second = value;

            // Move it to front as most recently used
            makemostrecentlyused(key);
        } else {
            // New key, insert at front of DLL
            dll.push_front(key);

            // Add to map
            mp[key] = {dll.begin(), value};

            // Reduce remaining capacity
            n--;
        }

        // If capacity exceeded, remove least recently used item
        if(n < 0) {
            int key_to_delete = dll.back(); // Last element in DLL = least recently used
            mp.erase(key_to_delete); // Remove from map
            dll.pop_back(); // Remove from DLL
            n++; // Restore capacity
        }
    }
};
