#pragma once
#include "../Node/DoublyNode.h"

namespace SGT {

	template<typename _Type>
	class List {
	private:
		SGT::DoublyNode<_Type>* m_head;
		SGT::DoublyNode<_Type>* m_tail;
		size_t m_size;

	public:
		List()
			:m_head(nullptr), m_tail(nullptr), m_size(0) {
		}

		List(const _Type& data) {
			m_head = new SGT::DoublyNode<_Type>(data);
			m_size++;
		}
		~List() {

		}

		void push_back(const _Type& data) {

			SGT::DoublyNode<_Type>* newNode = new SGT::DoublyNode<_Type>(data);

			if (m_head == nullptr) {
				m_head = newNode;
				m_tail = newNode;
				m_size++;
				return;
			}

			m_tail->nextNode = newNode;
			newNode->previousNode = m_tail;
			m_tail = newNode;
			m_size++;

		}

		void printData() {
			SGT::DoublyNode<int>* temp = m_head;

			while(temp != nullptr) {
				std::cout << "[" << temp << "]: " << temp->data << std::endl;
				temp = temp->nextNode;
			}
		}

	};
}