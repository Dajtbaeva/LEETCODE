SKATALA(())
981. Time Based Key-Value Store
https://leetcode.com/problems/time-based-key-value-store/
Input
["TimeMap", "set", "get", "get", "set", "get", "get"]
[[], ["foo", "bar", 1], ["foo", 1], ["foo", 3], ["foo", "bar2", 4], ["foo", 4], ["foo", 5]]
Output
[null, null, "bar", "bar", null, "bar2", "bar2"]

Explanation
TimeMap timeMap = new TimeMap();
timeMap.set("foo", "bar", 1);  // store the key "foo" and value "bar" along with timestamp = 1.
timeMap.get("foo", 1);         // return "bar"
timeMap.get("foo", 3);         // return "bar", since there is no value corresponding to foo at timestamp 3 and timestamp 2, then the only value is at timestamp 1 is "bar".
timeMap.set("foo", "bar2", 4); // store the key "foo" and value "bar2" along with timestamp = 4.
timeMap.get("foo", 4);         // return "bar2"
timeMap.get("foo", 5);         // return "bar2"

class TimeMap {
public:
    unordered_map<string,vector<pair<int,string>>> mp;
    TimeMap() {}
    
    void set(string key, string value, int timestamp) {   
        mp[key].push_back({timestamp,value});
    }
    string getVal(vector<pair<int,string>> &v,string key,int tmp){   
        int low=0;
        int high=v.size()-1;  
        while(low<=high){
            int mid=(low+high)/2;
            if(v[mid].first==tmp)
            return v[mid].second;
            else{
                if(v[mid].first<tmp) low=mid+1;
                else high=mid-1;
            }  
        }
        if(low==0) return ""; 
        return v[low-1].second;
    }
    
    string get(string key, int tmp) {  
        return getVal(mp[key],key,tmp);    
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */
