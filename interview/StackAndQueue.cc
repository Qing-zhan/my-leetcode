1. Use two stack to mitigate a queue
2. Use two queue to mitigate a stack

1. Use two stack to mitigate a queue

queue
----------------------------
->->->->->->->->->->->->->->
----------------------------

stack 1
-----------------
|->->->->->->->-
-----------------

stack 2
-----------------
<-<-<-<-<-<-<-<-|
-----------------

s1 is used to dequeue, s2 is used to enqueue
enqueue: push to s1
dequeue: if s2 is empty, push all elements from s1 to s2, else pop s2


class Queue {
  public:
    Queue() {}
    ~Queue() {}

  public:
    void enqueue(int n);
    int dequeue();
    int peek();
    bool empty();

  private:
    stack<int> s1;
    stack<int> s2;
};

void Queue::enqueue(int n) {
  s1.push(n);
}

int Queue::dequeue() {
  if (s2.empty()) {
    while (!s1.empty()) {
      s2.push(s1.top());
      s1.pop();
    }
  }  
  int temp = s2.top();
  s2.pop();
  return temp;
}

bool Queue::empty() {
  return s1.empty() && s2.empty();
}



2. Use two queue to mitigate a stack

q1 is used to push to stack, q2 is used to pop stack
push: enqueue to q1
pop: if q1 is not empty, rotate q1, then dequeue q1 to q2, then rotate q2 its original size times


class Stack {
  public:
    Stack() {}
    ~Stack() {}

  public:
    void push(int n);
    bool pop();
    int front();
    bool empty();

  private:
    queue<int> q1;
    queue<int> q2;
};

void Stack::push(int n) {
  q1.enqueue(n);
}

int Stack::front() {
  if (q1.empty() && q2.empty()) raise_assert_error;
  if (!q1.empty()) {
    for (int i = 0; i < q1.size(); ++i) q1.enqueue(q1.dequeue());
    int len_2 = q2.size();
    while (!q1.empty()) q2.enqueue(q1.dequeue());
    for (int i = 0; i < len_2; ++i) q2.enqueue(q2.dequeue()); 
  }
  return q2.peek();
}

bool Stack::pop() {
  Stack::front();
  q2.dequeue();
}

bool Stack::empty() {
  return q1.empty() && q2.empty();
}
