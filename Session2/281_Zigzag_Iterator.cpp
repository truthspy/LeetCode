// Todo 对n个vector的情况
// 可以把begin和end存成iterator的pair在一个队列里，到了末尾就不加入队列，队列为空表示hasnext为false

class ZigzagIterator {
    vector<int>::iterator i1, e1;
    vector<int>::iterator i2, e2;
    int x;
public:
    ZigzagIterator(vector<int>& v1, vector<int>& v2) {
        x = 0;
        i1 = v1.begin();
        i2 = v2.begin();
        e1 = v1.end();
        e2 = v2.end();
    }

    int next() {
        int res = 0;
        if(x == 0) {
            res = (*i1);
            i1 ++;
        }
        else {
            res = (*i2);
            i2 ++;
        }
        x = 1 - x;
        return res;
        
    }

    bool hasNext() {
        if(x == 0) {
            if(i1 != e1)
                return true;
            x = 1;
            return (i2 != e2);
        }
        else {
            if(i2 != e2)
                return true;
            x = 0;
            return (i1 != e1);
        }
    }
};

/**
 * Your ZigzagIterator object will be instantiated and called as such:
 * ZigzagIterator i(v1, v2);
 * while (i.hasNext()) cout << i.next();
 */
