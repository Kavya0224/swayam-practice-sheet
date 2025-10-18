#include <vector>
using namespace std;

class MyHashMap {
public:
    vector<int> data;  // Vector to store the values for keys, indexed by key

    MyHashMap() {
        // Initialize the vector 'data' with size 1,000,001 (to cover keys 0 to 1,000,000)
        // All values are set to -1, indicating that no key is currently mapped
        data = vector<int>(1000001, -1);
    }

    // Insert a (key, value) pair into the hashmap.
    // If the key already exists, update the value.
    void put(int key, int val) {
        data[key] = val;
    }

    // Return the value to which the specified key is mapped,
    // or -1 if this map contains no mapping for the key.
    int get(int key) {
        return data[key];
    }

    // Remove the mapping for the specified key by setting its value to -1.
    void remove(int key) {
        data[key] = -1;
    }
};
