#pragma once
#include "../Node/DoublyNode.h"

namespace SGT {

	template<typename _Type>
	class List {
	private:
		#define Node SGT::DoublyNode<_Type>

	private:
		Node* m_head;
		Node* m_tail;
		size_t m_size;


	public:
		List()
			:m_head(nullptr), m_tail(nullptr), m_size(0) {
		}

		List(const _Type& data) {
			m_head = new Node(data);
			m_size++;
		}
		~List() {

		}

		//Time Complexity: O(1)
		void push_back(const _Type& data) {

			Node* newNode = new Node(data);

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
		void push_front(const _Type& data) {

			Node* newNode = new Node(data);

			if (m_head == nullptr) {
				m_head = newNode;
				m_tail = newNode;
				m_size++;
				return;
			}

			m_head->previousNode = newNode;
			newNode->nextNode = m_head;
			m_head = newNode;
			m_size++;

		}

		//Time Complexity: O(N)
		void insertAt(const int& index, const _Type& data) {
			Node* newNode = new Node(data);

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

			newNode->nextNode = temp;
			newNode->previousNode = temp->previousNode;
			temp->previousNode->nextNode = newNode;
			temp->previousNode = newNode;
			m_size++;
		}

		//Time Complexity: O(1)
		const size_t size() const {
			return m_size;
		}

		//Time Complexity: O(1)
		_Type pop() {
			
			Node* temp = m_tail;
			_Type data = m_tail->data;

			m_tail = m_tail->previousNode;
			m_tail->nextNode = nullptr;

			delete temp;
			m_size--;

			return data;

		}

		//Time Complexity: O(N)
		void remove(const int& index) {
			Node* temp = m_head;
			if (index < 0) {
				std::cerr << "[Inavlid]: index cannot be negative\n";
				return;
			}
			if (index > m_size  - 1) {
				std::cerr << "[Inavlid]: index cannot be bigger than list size\n";
				return;
			}
			if (index ==  m_size - 1) {
				Node* lastNode = m_tail;
				m_tail = m_tail->previousNode;
				delete lastNode;
				return;
			}

			for (int i = 0; i < index; i++) {
				temp = temp->nextNode;
			}

			temp->previousNode->nextNode = temp->nextNode;
			temp->nextNode->previousNode = temp->previousNode;
			delete temp;
			m_size--;

		}
		//Time Complexity: O(1)
		void remove_front() {
			Node* temp = m_head;
			m_head = m_head->nextNode;
			delete temp;
			m_head->previousNode = nullptr;
			m_size--;
		}

		//Time Complexity: O(1)
		void remove_back() {
			Node* temp = m_tail;
			m_tail = m_tail->previousNode;
			delete temp;
			m_tail->nextNode = nullptr;
			m_size--;
		}

		//Time Complexity: O(1)
		void append(const List& secondList) {

			if (secondList.size() == 0) {
				return;
			}

			m_tail->nextNode = secondList.m_head;
			secondList.m_head->previousNode = m_tail;
			m_tail = secondList.m_tail;
			return;

		}
		//Time Complexity: O(N)
		void printData() {
			SGT::DoublyNode<int>* temp = m_head;

			while(temp != nullptr) {
				std::cout << "[" << temp << "]: " << temp->data << std::endl;
				temp = temp->nextNode;
			}
		}

	};
}