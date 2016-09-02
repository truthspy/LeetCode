// Using iterator
// 可以少复制vector
class Vector2D {
private:
    vector<vector<int>>::iterator i, end;
    int j;
public:
    Vector2D(vector<vector<int>>& vec2d) {
        i = vec2d.begin();
        end = vec2d.end();
        j = 0;
    }

    int next() {
        int res = (*i)[j];
        j ++;
        return res;
    }

    bool hasNext() {
        while(i != end) {
            if(j < (*i).size())
                return true;
            j = 0;
            i ++;
        }
        return false;
    }
};

/**
 * Your Vector2D object will be instantiated and called as such:
 * Vector2D i(vec2d);
 * while (i.hasNext()) cout << i.next();
 */
/*
class Vector2D {
private:
    int curPos;
    int curRow;
    vector<vector<int>> vals;
public:
    Vector2D(vector<vector<int>>& vec2d) {
        vals = vec2d;
        curPos = 0;
        curRow = 0;
    }

    int next() {
        int res = vals[curRow][curPos];
        curPos ++;
        return res;
    }

    bool hasNext() {
        while(curRow < vals.size()) {
            if(curPos < vals[curRow].size())
                return true;
            else {
                curPos = 0;
                curRow ++;
            }
        }
        return false;
    }
};
 */
