/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Constructor initializes an empty nested list.
 *     NestedInteger();
 *
 *     // Constructor initializes a single integer.
 *     NestedInteger(int value);
 *
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Set this NestedInteger to hold a single integer.
 *     void setInteger(int value);
 *
 *     // Set this NestedInteger to hold a nested list and adds a nested integer to it.
 *     void add(const NestedInteger &ni);
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
// TODO: 非递归方法，用栈实现
// 遇到'['就在栈中加一个nestedinteger，并把start设为i+1
// 遇到','就在栈顶的元素中加入start到i-1组成的数
// 遇到']'就弹出栈顶元素，再把弹出的元素加入到新的栈顶中
class Solution {
public:
    NestedInteger deserialize(string s) {
        NestedInteger res;
        if(s == "")
            return res;
        if(s.find('[') != 0) {
            res.setInteger(atoi(s.c_str()));
            return res;
        }
        if(s.size() == 2)
            return res;
        int cnt = 0;
        int start = 1;
        for(int i = 1; i < s.size(); i ++) {
            if(cnt == 0 && (s[i] == ',' || s[i] == ']')) {
                res.add(deserialize(s.substr(start, i - start)));
                start = i + 1;
            }
            else if(s[i] == '[')
                cnt ++;
            else if(s[i] == ']')
                cnt --;
        }
        /* 下面的写法不对！比如[[[4,[3]]]]，直接用逗号分隔有问题
        s = s.substr(1);
        s.pop_back();
        while(s != "") {
            int pos = s.find(',');
            if(pos == string::npos) {
                res.add(deserialize(s));
                break;
            }
            string cur = s.substr(0, pos);
            res.add(deserialize(cur));
            s = s.substr(pos + 1);
        }*/
        return res;
    }
};
