class LRUCache {
public:
    int cap;
    unordered_map<int, pair<int,bool>>:: iterator current;
    void next()
    {
        if(current == m.end())
            current = m.begin();
        else
            current++;
    }
    unordered_map<int, pair<int,bool>> m;
    LRUCache(int capacity) {
        cap = capacity;
    }
    
    int get(int key) {
        current = m.find(key);
        if(current != m.end())
        {
            int ret = current -> second.first;
            current -> second.second = true;
            next();
            return ret;
        }
        else
        {
            return -1;
        }
    }
    
    void put(int key, int value) {
        if( m.size() < cap )
        {
            current = (m.insert(make_pair(key,make_pair(value,true)))).first;
            next();
        }
        else
        {
            while( current->second.second )
            {
                current->second.second = false;
                next();
            }
            m.erase(current);
            put(key,value);
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
