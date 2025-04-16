#pragma once
#include "../Node/SinglyNode.h"
namespace SGT{

template <typename _Type>
class Queue {
private:
	using Node = SGT::SinglyNode<_Type>;

private:
	Node* m_head;
	Node* m_tail;
	size_t m_size;

public:

	Queue()
		:m_head(nullptr), m_tail(nullptr),m_size(0){}

	~Queue() {
		Node* head = m_head;
		Node* temp = m_head;

		while (temp) {
			temp = temp->nextNode;
			delete head;
			head = temp;
			
		}
	}
	void push(const _Type& data) {

		Node* newNode = new Node(data);

		if (!m_head) {
			m_head = newNode;
			m_tail = newNode;
			m_size++;
		}

		m_tail->nextNode = newNode;
		m_tail = newNode;
		m_size++;

	}

	_Type pop() {
		if (!m_head) {
			std::cout << "Queue is Empty\n";
			return NULL;
		}
		Node* temp = m_head;
		_Type temporaryData = temp->data;

		m_head = m_head->nextNode;
		delete temp;
		m_size--;

		return temporaryData;
	}

	const size_t size() const{
		return m_size;
	}

	void printData() {
		Node* temp = m_head;

		while (temp) {
			std::cout << "[" << &temp << "]: " << temp->data << std::endl;
			temp = temp->nextNode;
		}
	}

};

}