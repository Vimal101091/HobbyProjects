
template <typename T> class Stack
{
private:
    int size;
    int top;
    T* stack;

public:
    Stack(int s);
    ~Stack();
    void push(T element);
    T pop();
    void display();
    bool isfull();
    bool isempty();
};

template <typename T> Stack<T>::Stack(int s)
{
    stack = new T[s];
    size = s;
    top = -1;
}

template <typename T> Stack<T>::~Stack()
{
    delete[] stack;
}

template <typename T> void Stack<T>::push(T element)
{
    if(this->isfull()) {
        std::cout << "Stack is full" << std::endl;
        return;
    } else {
        ++top;
        stack[top] = element;
    }
}

template <typename T> T Stack<T>::pop()
{
    T element{};
    if(!this->isempty()) {
        element = stack[top];
        top--;
        return element;
    } else {
        std::cout << "Stack is empty" << std::endl;
        return -1;
    }
}

template <typename T> void Stack<T>::display()
{
    if(this->isfull()) {
        std::cout << "Stack is full" << std::endl;
    } else {
        for(int i = 0; i <= top; ++i)
            std::cout << stack[i] << std::endl;
    }
    std::cout << std::endl;
}

template <typename T> bool Stack<T>::isfull()
{
    return top == size;
}

template <typename T> bool Stack<T>::isempty()
{
    return top == -1;
}