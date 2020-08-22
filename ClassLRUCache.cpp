class LRUCache
{
private:
 map<int,int> m;
 int cap;
 list<int> q;
public:
    LRUCache(int capacity)
    {
        // constructor for cache
        cap = capacity;
    }
    
     int get(int key)
    {
        // this function should return value corresponding to key
       if(m.find(key) == m.end()) return -1;
       
       q.remove(key);
       q.push_front(key);
       return m[key];
       
        
    }
    
     void set(int key, int value)
    {
        // storing key, value pair
        if(m.find(key) != m.end())
        {
            q.remove(key);
            q.push_front(key);
            m[key] = value;
            return;
        }
        
        if(q.size() == cap)
        {
            int last = q.back();
            q.pop_back();
            m.erase(last);
            
        }
        m[key] = value;
        q.push_front(key);
        
        
    }
};
