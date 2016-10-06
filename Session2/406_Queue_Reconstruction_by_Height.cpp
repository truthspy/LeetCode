// from discuss https://discuss.leetcode.com/topic/60394/easy-concept-with-python-c-java-solution
// 太机智了
class Solution {
public:
    static bool cmp(const pair<int,int>& a, const pair<int,int>& b) {
        if(a.first == b.first)
            return a.second < b.second;
        return a.first > b.first;
    }
    vector<pair<int, int>> reconstructQueue(vector<pair<int, int>>& people) {
        sort(people.begin(), people.end(), cmp);
        vector<pair<int,int>> res;
        for(int i = 0; i < people.size(); i ++) {
            res.insert(res.begin() + people[i].second, people[i]);
        }
        return res;
    }
};
