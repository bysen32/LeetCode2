class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        map<string, int> wmap;
        for (int i=0; i<words.size(); ++i) {
            if (wmap.find(words[i]) == wmap.end()) {
                wmap[words[i]] = 0;
            }
            wmap[words[i]] += 1;
        }
        
        vector<pair<int, string>> records;
        for (map<string, int>::iterator it = wmap.begin(); it != wmap.end(); ++it) {
            pair<int, string> p = pair<int, string>(it->second, it->first);
            records.push_back(p);
        }
        
        pair<int, string> temp;
        for (int i=0; i<records.size(); ++i) {
            for (int j=i+1; j<records.size(); ++j) {
                if (records[j].first > records[i].first) {
                    temp = records[i];
                    records[i] = records[j];
                    records[j] = temp;
                } else if (records[i].first == records[j].first && records[i].second > records[j].second) {
                    temp = records[i];
                    records[i] = records[j];
                    records[j] = temp;
                }
            }
        }
        
        vector<string> ans;
        for (int i=0; i<records.size()&&i<k; ++i) {
            ans.push_back(records[i].second);
        }
        
        return ans;
    }
};