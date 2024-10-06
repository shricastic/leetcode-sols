class Solution {
private:
    void split(string& s, vector<string>& v){
        istringstream stream(s);
        string token;
        
        while(stream >> token) v.push_back(token);
    }
    
public:
    bool areSentencesSimilar(string sentence1, string sentence2) {
        vector<string> v1, v2;
        split(sentence1, v1);
        split(sentence2, v2);
            
        int n1 = v1.size(), n2 = v2.size(), i=0, j=0;
        
        while(i<n1 && i<n2 && v1[i] == v2[i]) i++;
        
        while(j<n1-i && j<n2-i && v1[n1-1-j] == v2[n2-1-j]) j++;
        
        return i+j>=n1 || i+j>=n2;
    }
};