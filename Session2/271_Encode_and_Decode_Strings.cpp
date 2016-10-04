class Codec {
public:

    // Encodes a list of strings to a single string.
    string encode(vector<string>& strs) {
        string res = "";
        int n = strs.size();
        for(int i = 0; i < n; i ++) {
            res += (to_string(strs[i].length()) + "/" + strs[i]);
        }
        return res;
    }

    // Decodes a single string to a list of strings.
    vector<string> decode(string s) {
        vector<string> res;
        while(s != "") {
            int pos = s.find('/');
            int curLen = atoi(s.substr(0, pos).c_str());
            res.push_back(s.substr(pos + 1, curLen));
            s = s.substr(pos + curLen + 1);
        }
        return res;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.decode(codec.encode(strs));
