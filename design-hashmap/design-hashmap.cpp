class MyHashMap {
private:
    vector<bool> keyBuffer;
    vector<int> valBuffer;
public:
    MyHashMap() {
        keyBuffer.resize(1000001, false);
        valBuffer.resize(1000001, -1);
    }
    
    void put(int key, int value) {
        keyBuffer[key] = true;
        valBuffer[key] = value;
    }
    
    int get(int key) {
        return valBuffer[key];
    }
    
    void remove(int key) {
        keyBuffer[key] = false;
        valBuffer[key] = -1;
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */