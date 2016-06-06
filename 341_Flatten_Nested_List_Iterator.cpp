/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
/**
 * http://www.cnblogs.com/grandyang/p/5358793.html
 * 看了答案写的
 * 用栈实现，将vector中的元素倒序压入栈中，调用hasnext时，取栈顶元素，如果不是整数，倒序压栈，直到栈顶为整数
 */
class NestedIterator {
private:
    stack<NestedInteger> s;
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        for(int i = nestedList.size() - 1; i >= 0; i --)
            s.push(nestedList[i]);
    }

    int next() {
        NestedInteger cur = s.top();
        s.pop();
        return cur.getInteger();
    }

    bool hasNext() {
        while(!s.empty()) {     //注意要用while！
            NestedInteger cur = s.top();
            if(cur.isInteger())
                return true;
            s.pop();            //注意要先把当前元素pop
            for(int i = cur.getList().size() - 1; i >= 0; i --) 
                s.push(cur.getList()[i]);
        }
        return false;
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */
