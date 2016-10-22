// 可以不用atoi的方法，使用res=res*10+i这样的方法进行判断，减少代码量
class Solution {
public:
    int compareVersion(string version1, string version2) {
        while(version1.size() != 0 && version2.size() != 0) {
            int v1, v2;
            int pos1 = version1.find('.');
            int pos2 = version2.find('.');
            if(pos1 == string::npos) {
                v1 = stoi(version1);
                version1 = "";
            }
            else {
                v1 = stoi(version1.substr(0, pos1));
                version1 = version1.substr(pos1 + 1);
            }
            if(pos2 == string::npos) {
                v2 = stoi(version2);
                version2 = "";
            }
            else {
                v2 = stoi(version2.substr(0, pos2));
                version2 = version2.substr(pos2 + 1);
            }
            if(v1 > v2)
                return 1;
            if(v1 < v2)
                return -1;
        }
        int i = 0;
        while(i != version1.size()) {
            if(version1[i] == '0' || version1[i] == '.')
                i ++;
            else
                return 1;
        }
        i = 0;
        while(i != version2.size()) {
            if(version2[i] == '0' || version2[i] == '.')
                i ++;
            else
                return -1;
        }
        return 0;
    }
};
