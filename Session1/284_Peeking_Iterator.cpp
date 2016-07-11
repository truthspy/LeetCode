// Below is the interface for Iterator, which is already defined for you.
// **DO NOT** modify the interface for Iterator.
class Iterator {
    struct Data;
	Data* data;
public:
	Iterator(const vector<int>& nums);
	Iterator(const Iterator& iter);
	virtual ~Iterator();
	// Returns the next element in the iteration.
	int next();
	// Returns true if the iteration has more elements.
	bool hasNext() const;
};

/**
 * 看了答案之后写的
 * 加一个变量存储下一个值，以及一个hasPeeked bool变量，记录是否已经peek过
 * 在peek()、next()和hasNext()之前，都要先进行判断是否peek过，没peek过指针才向前移
 */
class PeekingIterator : public Iterator {
private:
    bool hasPeeked;
    int peekedEle;
public:
	PeekingIterator(const vector<int>& nums) : Iterator(nums) {
	    // Initialize any member here.
	    // **DO NOT** save a copy of nums and manipulate it directly.
	    // You should only use the Iterator interface methods.
	    hasPeeked = false;
	}

    // Returns the next element in the iteration without advancing the iterator.
	int peek() {
        if(hasPeeked)
            return peekedEle;
        peekedEle = Iterator::next();
        hasPeeked = true;
        return peekedEle;
	}

	// hasNext() and next() should behave the same as in the Iterator interface.
	// Override them if needed.
	int next() {
	    if(hasPeeked) {
	        hasPeeked = false;
	        return peekedEle;
	    }
	    return Iterator::next();
	}

	bool hasNext() const {
	    if(hasPeeked)
	        return true;
	    return Iterator::hasNext();
	}
};
