class Stack {
private:
    queue<int> que1;//负责进
    queue<int> que2;
public:
    // Push element x onto stack.
    void push(int x) {//都从que1进
        que1.push(x);
    }

    // Removes the element on top of the stack.
    void pop() {
        int temp;
        if(!que1.empty())//栈顶就是最后进来的，那如果que1不空，肯定在这里
        {
            while(que1.size()>1)
            {
                temp=que1.front();
                que1.pop();
                que2.push(temp);
            }
            que1.pop();
        }
        else
        {
            while(que2.size()>1)
            {
                temp=que2.front();
                que2.pop();
                que1.push(temp);
            }
            que2.pop();
        }
    }

    // Get the top element.
    int top() {
        int temp;
        if(!que1.empty())//栈顶就是最后进来的，那如果que1不空，肯定在这里
        {
            while(!que1.empty())
            {
                temp=que1.front();
                que1.pop();
                que2.push(temp);
            }
        }
        else
        {
            while(!que2.empty())
            {
                temp=que2.front();
                que2.pop();
                que1.push(temp);
            }
        }
        return temp;
    }

    // Return whether the stack is empty.
    bool empty() {
        return que1.empty() && que2.empty();
        
    }
};