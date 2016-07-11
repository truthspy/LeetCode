class ValidWordAbbr {
private:
    unordered_map<string, int> dicAbb;
    unordered_set<string> dic;
public:
    ValidWordAbbr(vector<string> &dictionary) {
        int size = dictionary.size();
        for(int i = 0; i < size; i ++) {
            bool fExist = false;
            if(dic.find(dictionary[i]) != dic.end())
                fExist = true;
            else
                dic.insert(dictionary[i]);
            string abbWord = "";
            int len = dictionary[i].length();
            if(len == 0 || len == 1 || len == 2)
                abbWord = dictionary[i];
            else {
                abbWord += dictionary[i][0];
                int count = 0;
                for(int j = 1; j < len - 1; j ++)
                    count ++;
                abbWord += (to_string(count));
                abbWord += dictionary[i][len - 1];
            }
            if(!fExist)
                dicAbb[abbWord] ++;
        }
    }
    
    bool isUnique(string word) {
        string abbWord = "";
        int len = word.length();
        if(len == 0 || len == 1 || len == 2)
            abbWord = word;
        else {
            abbWord += word[0];
            int count = 0;
            for(int j = 1; j < len - 1; j ++)
                count ++;
            abbWord += (to_string(count));
            abbWord += word[len - 1];
        }
        if(dicAbb.find(abbWord) == dicAbb.end())
            return true;
        if(dic.find(word) != dic.end() && dicAbb[abbWord] == 1)
            return true;
        return false;
    }
};



// Your ValidWordAbbr object will be instantiated and called as such:
// ValidWordAbbr vwa(dictionary);
// vwa.isUnique("hello");
// vwa.isUnique("anotherWord");