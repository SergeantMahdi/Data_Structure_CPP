#pragma once

#include <iostream>

namespace SGT {

	template<typename _Type>
	class Vector {

	private:
		_Type* m_array;
		size_t m_capacity;
		size_t m_size;

	private:
		//Swap Time Complexity: O(1)
		void swap(_Type& first, _Type& second) {
			_Type temp = first;
			first = second;
			second = temp;
		}

		//Reallocate Time complexity: O(N)
		void reallocate(){ 
			//if the size of the array is exceeded its capacity, increase the size of array 1.5 times more

			m_capacity *= 1.5;
			_Type* newArray = new _Type[m_capacity];

			for (int i = 0; i < m_size; i++) {
				newArray[i] = std::move(m_array[i]);
			}

			delete[] m_array;

			m_array = newArray;
		}

		//shrinkMemoryAllocation Time complexity: O(N)
		void shrinkMemoryAllocation() {
			//shrink the capacity of the vector
			m_capacity /= 1.5;
			_Type* newArray = new _Type[m_capacity];

			for (int i = 0; i < m_size; i++) {
				newArray[i] = std::move(m_array[i]);
			}

			delete[] m_array;

			m_array = newArray;
		}

	public:
		Vector() 
			:m_capacity(10), m_size(0) {
			m_array = new _Type[m_capacity];
		}

		~Vector() {

			delete[] m_array;
		}

		//push_back Time complexity: Best case O(1) | Worst case (reallocation happens): O(N)
		void push_back(const _Type& data) {
			//add a new data into the array

			if (m_capacity == m_size) {
				reallocate();
			}

			m_array[m_size++] = data;
		}


		void push_back(_Type&& data) {

			if (m_capacity == m_size) {
				reallocate();
			}

			m_array[m_size++] = std::move(data);
		}

		//insertAt Time complexity: Best case O(1) | Worst case (reallocation happens or the target index is the initial element): O(N) 
		void insertAt(const _Type& data, const int& index) {
			//add a new data into a certain index of the array

			std::cout << "Allocating memory" << std::endl;
			if (m_capacity == m_size) {
				reallocate();
			}
			if (index < 0 || index > m_size) {
				throw std::out_of_range("[Access violation]: cannot access the value outside the range of array");
				return;
			}

			for (int i = m_size; i > index; i--) {
				m_array[i] = m_array[i - 1];
			}

			m_array[index] = data;
			m_size++;
		}

		//PrintData Time complexity: Time complexity: O(N)
		void printData() const {
			if (m_size == 0) {
				std::cout << "Vector is empty\n";
			}
			
			for (int i = 0; i < m_size; i++) {
				std::cout << "[" << i + 1 << "]: " << m_array[i] << std::endl;
			}
			std::cout << "======================================\n";
		}

		//Size: Time complexity: O(1)
		const size_t size() const {
			return m_size;
		}

		//Reverse Time complexity: O(n/2) ==> O(N)
		void reverse() {
			//reverse the array

			size_t size = m_size - 1;

			for (int i = 0; i < size / 2; i++) {
				swap(m_array[i], m_array[size - i]);
			}
		}

		//removeAt Time complexity: O(N)
		void removeAt(const int& index) {
			/*
			remove an element at a certain index
	        [NOTE]: if you want to remove and add element at a certain location,
			you'd better use list.
			*/

			if (index < 0 || index > m_size) {
				throw std::out_of_range("[Access violation]: cannot access the value outside the range of array");
				return;
			}
			if (m_capacity > 10 && m_size == m_capacity / 3) { //if only 1/3 of memory blocks filled with data shrink the occupied memory block 
				shrinkMemoryAllocation();
			}
			for (int i = index; i < m_size - 1; i++) {
				m_array[i] = m_array[i + 1];
			}
			m_size--;
		}

		//remove Time complexity: O(2n) == O(N)
		void remove(const _Type& data) {
			//find and remove an element from the array

			if (m_capacity > 10 && m_size == m_capacity / 3) {
				shrinkMemoryAllocation();
			}
			for (int i = 0; i < m_size; i++) {
				std::cout << "Array: " << m_array[i] << ", Data: " << data << std::endl;
				if (m_array[i] == data) {
					for (int j = i; j < m_size; j++) {
						m_array[j] = m_array[j + 1];
					}
					m_size--;
					return;
				}
			}

			std::cout << "[Invalid]: The given data doesn't exit\n";
		}

		//pop Time Complexity: O(1)
		_Type pop() {
			//Return and remove the last element

			if (m_capacity > 10 && m_size == m_capacity / 3) {
				shrinkMemoryAllocation();
			}
			_Type data = std::move(m_array[m_size - 1]);
			m_size--;

			return data;
		}

		//reeserve Time Complexity: O(N)
		void reserve(const size_t& reservedMemorySize) {
			//reserve certain slots of memory to avoid reallocation
			m_capacity += reservedMemorySize;

			_Type* newArray = new _Type[m_capacity];

			for (int i = 0; i < m_size; i++) {
				newArray[i] = m_array[i];
			}

			delete[] m_array;

			m_array = newArray;
		}


		const size_t maxCapacity() {

			return m_capacity;
		}

		//clear Time Complexity: O(1)
		void clear() {

			delete[] m_array;
			m_capacity = 10;
			m_array = new _Type[m_capacity];
			m_size = 0;
		}

		//--------------OverLoading Operators-------------
		_Type& operator[] (const int& index) {

			if (index < 0 || index > m_size) {
				throw std::out_of_range("[Access violation]: cannot access the value outside the range of array");
				std::exit(1);
			}

			return m_array[index];
		}


		const _Type& operator[] (const int& index) const {
			if (index < 0 || index > m_size) {
				throw std::out_of_range("[Access violation]: cannot access the value outside the range of array");
				std::exit(1);
			}

			return m_array[index];
		}


	};

}