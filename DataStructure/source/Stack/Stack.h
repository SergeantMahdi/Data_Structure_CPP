#pragma once

#include "../Node/SinglyNode.h"
namespace SGT {

	template<typename _Type>
	class Stack {
	private:
		using Node = SGT::SinglyNode<_Type>;
	private:
		Node* m_head;
		size_t m_size;

	public:
		Stack()
			:m_head(nullptr), m_size(0) {}

		//Push Time Complexity: O(1)
		void push(const _Type& data) {
			//Add the data to the head of container.

			Node* newNode = new Node(data);

			if (m_size == 0) {
				m_head = newNode;
				m_size++;
				return;
			}

			newNode->nextNode = m_head;
			m_head = newNode;
			m_size++;
		}

		//Pop Time Complexity: O(1)
		void pop() {
			//Remove the head from container
			Node* temp = m_head;
			m_head = m_head->nextNode;
			delete temp;
			m_size--;
		}

		const bool isEmpty() const {
			if (m_size != 0) {
				return false;
			}
			return true;
		}

		_Type& top() const {
			return m_head->data;
		}

		const size_t size() const {
			return m_size;
		}

		void printData() {
			Node* temp = m_head;

			while(temp){
				std::cout << "[" << &temp << "]: " << temp->data << std::endl;
				temp = temp->nextNode;
			}
		}

	};

}