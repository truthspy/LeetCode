class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        int len = s.length();
        vector<string> result;
        unordered_map<string, int> dna;
        for(int i = 0; i < len - 9; i ++) {
            string seq = s.substr(i, 10);
            if(dna.find(seq) != dna.end()) {
                dna[seq] ++;
                if(dna[seq] == 2)
                    result.push_back(seq);
            }
            else {
                dna[seq] = 1;
            }
        }
        return result;
    }
};

//TODO
//看答案里的位操作方法
