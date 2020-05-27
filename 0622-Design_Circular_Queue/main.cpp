// 循环队列，队首headIndex和和队尾tailIndex，与队列当前实际长度间关系如下：
// tailIndex = (headIndex + count - 1) mod capacity
// 其中 capacity 是数组长度(最大容量)，count 是队列长度（当前实际容量）
// 所以，可以定义 headIndex、count 或 headIndex、tailIndex来求得另一个
// [..[head, tail]..] [.., tail]..[head, ..]
// pstore原子操作，先加不行再退回来，线程安全是如何实现的，锁还是原子操作？
// printk用的是双指针，怎么看是满还是空呢？线程安全是靠spin lock吗？
class MyCircularQueue {
    vector<int> qe;
    int headIndex = 0;
    int tailIndex = 0;
    int sz = 0; // 虽然可以用head tail得到sz，但只考head tail没法确认是满，还是空
    int cap = 0;
public:
    /** Initialize your data structure here. Set the size of the queue to be k. */
    MyCircularQueue(int k) {
		qe = vector<int>(k);
        cap = k;
    }
    
    /** Insert an element into the circular queue. Return true if the operation is successful. */
    bool enQueue(int value) {
		if (isFull())
        	return false;
        if (!isEmpty()) // 空的时候，tailIndex不能动，要存到tailIndex当下的位置
        	tailIndex = (tailIndex + 1) % cap;
        qe[tailIndex] = value;
        sz++;
        return true; 
    }
    
    /** Delete an element from the circular queue. Return true if the operation is successful. */
    bool deQueue() {
		if (isEmpty())
        	return false;
        if (sz != 1) // 只有一个的时候，删掉headIndex不能动，否则跟tailIndex就错开了
        	headIndex = (headIndex + 1) % cap;
        sz--;
        return true;
    }
    
    /** Get the front item from the queue. */
    int Front() {
        if (isEmpty())
        	return -1;
        return qe[headIndex];
    }
    
    /** Get the last item from the queue. */
    int Rear() {
		if (isEmpty())
        	return -1;
        return qe[tailIndex];
    }
    
    /** Checks whether the circular queue is empty or not. */
    bool isEmpty() {
		return sz == 0;
    }
    
    /** Checks whether the circular queue is full or not. */
    bool isFull() {
		return sz == cap;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */