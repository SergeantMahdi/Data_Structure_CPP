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

		void insertAt(const int& index, const _Type& data) {
			SGT::DoublyNode<_Type>* newNode = new SGT::DoublyNode<_Type>(data);

			if (index < 0) {
				std::cerr << "[Inavlid]: index cannot be negative\n";
				return;
			}
			if (index == 0) {
				newNode->nextNode = m_head;
				m_head->previousNode = newNode;
				m_head = newNode;
				m_size++;
				return;
			}
			if (index >= m_size) {
				m_tail->nextNode = newNode;
				newNode->previousNode = m_tail;
				m_tail = newNode;
				m_size++;
				return;
			}

			SGT::DoublyNode<_Type>* temp = m_head;
			for (int i = 0; i < index; i++) {
				temp = temp->nextNode;
			}

			newNode->nextNode = temp->nextNode;
			newNode->previousNode = temp;
			temp->nextNode->previousNode = newNode;
			temp->nextNode = newNode;
			m_size++;
		}

		const size_t size() const {
			return m_size;
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