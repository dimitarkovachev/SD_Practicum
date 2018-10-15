#pragma once

template<typename T>
class Node {
public:
	T value;
	Node<T>* next;
public:
	Node() {
		next = NULL;
	}
	Node(const T& _value, Node<T>* _next);
};

template<typename T>
class Stack {
private:
	Node<T>* top;
	size_t stackSize;

	void init();

	void erase();

	void copyReverse(const Stack& src);

	void copy(const Stack& src);

	bool isEmpty();
public:
	Stack();

	Stack(const Stack& src);

	~Stack();

	Stack& operator=(const Stack& src);

	size_t size();

	void push(T& value);

	void pop();

	T& getTop();
};


template<typename T>
Node<T>::Node(const T& _value, Node<T>* _next) {
	value = _value;
	next = _next;
}

template <typename T> void Stack<T>::init() {
	stackSize = 0;
	top = NULL;
}

template<typename T> void Stack<T>::erase() {
	for (size_t i = 0; i < stackSize; i++) {
		this->pop();
	}
}

template <typename T> void Stack<T>::copyReverse(const Stack<T>& src) {
	Node<T>* node = src.top;
	for (size_t i = 0; i < src.stackSize; i++) {
		push(node->value);
		node = node->next;
	}
	stackSize = src.stackSize;
}

template <typename T> void Stack<T>::copy(const Stack<T>& src) {
	Stack<T> reversed;
	reversed.copyReverse(src);
	this->copyReverse(reversed);
}

template <typename T> bool Stack<T>::isEmpty() {
	return top == NULL;
}

template <typename T> Stack<T>::Stack() {
	init();
}

template <typename T> Stack<T>::Stack(const Stack<T>& src) {
	this->copy(src);
}

template <typename T> Stack<T>::~Stack() {
	this->erase();
}

template <typename T> Stack<T>& Stack<T>::operator=(const Stack<T>& src) {
	if (this != &src) {
		this->erase();
		this->init();
		this->copy(src);
	}
	return *this;
}

template <typename T> size_t Stack<T>::size() {
	return stackSize;
}

template <typename T> void Stack<T>::push(T& value) {
	Node<T>* newNode = new Node<T>(value, this->top);
	if (newNode) {
		this->top = newNode;
		stackSize++;
	}
}

template <typename T> void Stack<T>::pop() {
	if (!isEmpty()) {
		Node<T>* remove = this->top;
		this->top = this->top->next;
		delete remove;
		stackSize--;
	}
}

template <typename T> T& Stack<T>::getTop() {
	return top->value;
}


