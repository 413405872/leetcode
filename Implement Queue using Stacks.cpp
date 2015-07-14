class Queue {
private:
    stack<int> sta1;
    stack<int> sta2;
public:
    // Push element x to the back of queue.
    void push(int x) {
        sta1.push(x);
    }

    // Removes the element from in front of queue.
    void pop(void) {
        if(sta2.empty())
        {
            while(!sta1.empty())
            {
                int temp=sta1.top();
                sta1.pop();
                sta2.push(temp);
            }
        }
        sta2.pop();
    }

    // Get the front element.
    int peek(void) {
        if(sta2.empty())
        {
            while(!sta1.empty())
            {
                int temp=sta1.top();
                sta1.pop();
                sta2.push(temp);
            }
        }
        return sta2.top();
    }

    // Return whether the queue is empty.
    bool empty(void) {
        return sta1.empty()&&sta2.empty();
    }
};