class MinStack {

private:
    struct Node {
        Node * next;
        Node * lastMin;
        int value;
        Node(int x) : value(x), next(NULL) {}
    };
    
    Node * topPtr;
    Node * minPtr;
    
public:
    /** initialize your data structure here. */
    MinStack() {
        topPtr = NULL;
        minPtr = NULL;
    }
    
    void push(int x) {
        Node * newNode = new Node(x);
        if(topPtr == NULL)
        {
            minPtr = newNode;
            newNode->lastMin = NULL;
        }
        else
        {
            if(newNode->value < minPtr->value)
            {
                newNode->lastMin = minPtr;
                minPtr = newNode;
            }
        }
        newNode->next = topPtr;
        topPtr = newNode; 
        
    }
    
    void pop() {
        if(topPtr == minPtr)
            minPtr = topPtr->lastMin;
        Node * delPtr = topPtr;
        topPtr = topPtr->next;
        delete delPtr;
    }
    
    int top() {
        return topPtr->value;
    }
    
    int getMin() {
        return minPtr->value;
    }
};
