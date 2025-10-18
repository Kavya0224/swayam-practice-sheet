#include <vector>
using namespace std;

class MyHashMap {
public:
    vector<int> data;

    MyHashMap() {
        // Declare vector of size 100001 with all values initialized to -1
        data = vector<int>(1000001, -1);
    }

    void put(int key, int val) {
        data[key] = val;
    }

    int get(int key) {
        return data[key];
    }

    void remove(int key) {
        data[key] = -1;
    }
};
