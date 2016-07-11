//O(n^2)的做法，太慢了。。
class Solution {
public:
    int hIndex(vector<int>& citations) {
        int size = citations.size();
        if(size == 0)
            return 0;
        for(int i = size; i > 0; i --) {
            int count = 0;
            int same = 0;
            for(int j = 0; j < size; j ++) {
                if((size - j) < (i - count - same))
                    break;
                if(citations[j] > i)
                    count ++;
                if(citations[j] == i)
                    same ++;
                if(count > i)
                    break;
            }
            if(count == i)
                return i;
            else if(count < i && ((count + same) >= i))
                return i;
        }
        return 0;
    }
};

//O(n)的做法
/**
 * dicuss的做法
 * H最大值为数组长度
 * 记录<=H的每个引用的数目
 * 从后向前遍历
 */
class Solution {
public:
    int hIndex(vector<int>& citations) {
        int size = citations.size();
        if(size == 0)
            return 0;
        vector<int> total(size + 1, 0);
        for(int i = 0; i < size; i ++) {
            if(citations[i] >= size)
                total[size] ++;
            else
                total[citations[i]] ++;
        }
        int sum = 0;
        for(int i = size; i >= 0; i --) {
            sum += total[i];
            if(sum >= i)
                return i;
        }
        return 0;
    }
};
