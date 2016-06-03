class Solution {
public:
    string simplifyPath(string path) {
        vector<string> myPath;
        int i = 0;
        int j = -1;
        int len = path.length();
        while(i < len) {
            if(path[i] == '/') {
                if(i != (j + 1)) {          //注意第一个"/"，要把j初始化为-1
                    string sub = path.substr(j + 1, i - j - 1);
                    if(sub == "..") {
                        if(!myPath.empty())
                            myPath.pop_back();
                    }
                    else if(sub != ".")
                        myPath.push_back(sub);
                }
                j = i;
            }
            i ++;
        }
        i --;
        if(path[i] != '/') {
            string sub = path.substr(j + 1, i - j);
            cout << sub << endl;
            if(sub == "..") {
                if(!myPath.empty())
                    myPath.pop_back();
            }
            else if(sub != ".")
                myPath.push_back(sub);
        }
        if(myPath.empty())
            return "/";
        string result = "";
        for(i = 0; i < myPath.size(); i ++) {
            result += ("/" + myPath[i]);
        }
        return result;
    }
};
