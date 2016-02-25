/*
可能有不止一个'.'
*/
class Solution {
public:
    int compareVersion(string version1, string version2) {
        int ver1 = 0;
        int ver2 = 0;
        int i = 0;
        int j = 0;
        int len1 = version1.length();
        int len2 = version2.length();
        while(i < len1 || j < len2) { //可能出现一个后面还有'.'另一个没有的情况，所以要用或
            while(i < len1 && version1[i] != '.') {
                ver1 = ver1 * 10 + version1[i] - '0';
                i ++;
            }
            while(j < len2 && version2[j] != '.') {
                ver2 = ver2 * 10 + version2[j] - '0';
                j ++;
            }
            if(ver1 > ver2)
                return 1;
            if(ver1 < ver2)
                return -1;
            ver1 = 0; //记着要归0！！
            ver2 = 0;
            i ++;
            j ++;
        }
        return 0;
    }
};
