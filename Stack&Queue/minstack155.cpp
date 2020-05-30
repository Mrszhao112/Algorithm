//设计一个支持 push ，pop ，top 操作，并能在常数时间内检索到最小元素的栈。

//push(x) —— 将元素 x 推入栈中。
/pop() /—— 删除栈顶的元素。
top() —— 获取栈顶元素。
getMin() —— 检索栈中的最小元素。

//辅助空间 一个存每次更小的元素 一个正常存储元素
class MinStack {
    stack<int> x_stack;
    stack<int> min_stack;
public:
    MinStack() {
        min_stack.push(INT_MAX);
    }
    
    void push(int x) {
        x_stack.push(x);
        min_stack.push(min(min_stack.top(), x));
    }
    
    void pop() {
        x_stack.pop();
        min_stack.pop();
    }
    
    int top() {
        return x_stack.top();
    }
    
    int getMin() {
        return min_stack.top();
    }
};
//方法二 略加改进的方法
class MinStack {
private:
    stack<int> s1;
    stack<int> s2;
public:
    void push(int x) {
	    s1.push(x);
	    if (s2.empty() || x <= getMin())  s2.push(x);	    
    }
    void pop() {
	    if (s1.top() == getMin())  s2.pop();
	    s1.pop();
    }
    int top() {
	    return s1.top();
    }
    int getMin() {
	    return s2.top();
    }
};
