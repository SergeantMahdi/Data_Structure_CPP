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
		void swap( _Type& first, _Type& second);
		void reallocate();

	public:
		Vector();
		~Vector();

		void push_back(const _Type& data);
		void insertAt(const _Type& data, const int& index);
		void printData() const;
		const size_t size() const;
		void reverse();
		void removeAt(const int& index);
		void remove(const _Type& data);
		_Type pop_back();
		const bool linearSearch(const _Type& data) const;
		const bool BinarySearch(const _Type& data) const;
		const _Type max() const;

		//--------------OverLoading Operators-------------
		_Type& operator[] (const int& index) const;

	};


	//==================== Definitions ===================

	//___________________ PRIVATE METHODS________________
	

	//Swap: time complexity: O(1)
	template<typename _Type>
	void Vector<_Type>::swap(_Type& first, _Type& second)
	{
		_Type temp = first;
		first = second;
		second = temp;
	}

	//Reallocate: if the size of the array is exceeded its capacity, increase the size of array 1.5 times more
	//Time complexity: O(N)
	template<typename _Type>
	void Vector<_Type>::reallocate()
	{
		m_capacity *= 1.5;
		_Type* newArray = new _Type[m_capacity];

		for (int i = 0; i < m_size; i++) {
			newArray[i] = m_array[i];
		}

		delete[] m_array;

		m_array = newArray;
	}

	//___________________ PUBLIC METHODS________________

	template<typename _Type>
	 Vector<_Type>::Vector()
		 :m_capacity(10), m_size(0) {
		 m_array = new _Type[m_capacity];
	 }

	 template<typename _Type>
	 Vector<_Type>::~Vector()
	 {
		 delete[] m_array;
	 }

	 //Push_back: add a new data into the array
	 //Time complexity: Best case O(1) | Worst case (reallocation happens): O(N)
	template<typename _Type>
	void Vector<_Type>::push_back(const _Type& data)
	{
		if (m_capacity == m_size) {
			reallocate();
		}

		m_array[m_size++] = data;
	}

	//InsertAt: add a new data into a certain index of the array
	//Time complexity: Best case O(1) | Worst case (reallocation happens or the target index is the initial element): O(N) 
	template<typename _Type>
	void Vector<_Type>::insertAt(const _Type& data, const int& index)
	{
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

	//PrintData: Time complexity: O(N)
	template<typename _Type>
	void Vector<_Type>::printData() const
	{
		for (int i = 0; i < m_size; i++) {
			std::cout << "[" << i + 1 << "]: " << m_array[i] <<std::endl;
		}
	}

	//Size: Time complexity: O(1)
	template<typename _Type>
	const size_t Vector<_Type>::size() const
	{
		return m_size;
	}
	//Reverse: reverse the array
	// Time complexity: O(n/2) ==> O(N)
	template<typename _Type>
	void Vector<_Type>::reverse()
	{
		size_t size = m_size - 1;

		for (int i = 0; i < size / 2; i++) {
			swap(m_array[i], m_array[size - i]);
		}
	}

	//removeAt: remove an element at a certain index
	// Time complexity: O(N)
	template<typename _Type>
	void Vector<_Type>::removeAt(const int& index)
	{
		if (index < 0 || index > m_size) {
			throw std::out_of_range("[Access violation]: cannot access the value outside the range of array");
			return;
		}
		for (int i = index; i < m_size - 1; i++) {
			m_array[i] = m_array[i + 1];
		}
		m_size--;
	}

	//removeAt: find and remove an element from the array
	// Time complexity: O(2n) == O(N)
	template<typename _Type>
	void Vector<_Type>::remove(const _Type& data)
	{
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

	//Pop_back: Return and remove the last element
	//Time Complexity: O(1)
	template<typename _Type>
	_Type Vector<_Type>::pop_back()
	{
		_Type data = std::move(m_array[m_size - 1]);
		m_size--;
		
		return data;
	}

	//LinearSearch: check if an element exists, using transitioning method
	// Transitioning Method: There is always a chance that a user searches for the same data over an over
	// in this case everytime the element is searched we move the element one slot to the front so the next time
	// a user search for it, it'll make less process to get the same value
	// Time complexity: O(n)
	template<typename _Type>
	const bool Vector<_Type>::linearSearch(const _Type& data) const
	{
		for (int i = 0; i < m_size; i++) {
			if (m_array[i] == data) {
				if (i != 0) {
					swap(m_array[i], m_array[i - 1]);
				}
				return true;
			}
		}
		return false;
	}
	//BinarySearch: check if an element exists
	// [NOTE]: in binary search array must be sorted
	// Time complexity: O(Log n)
	template<typename _Type>
	const bool Vector<_Type>::BinarySearch(const _Type& data) const
	{

		int low = 0;
		int high = m_size - 1;
		int middle;

		while (low <= high) {

		middle= low + high / 2;

			if (data == m_array[middle]) {
				return true;
			}
			else if (data > m_array[middle]) {
				low = middle + 1;
			}
			else if (data < m_array[middle]) {
				high = middle - 1;
			}
		}
		return false;
	}

	//Max: Find the maximum number of the array (Only for comparable data types)
	//Time Complexity: O(N)
	template<typename _Type>
	const _Type Vector<_Type>::max() const
	{
		_Type max = m_array[0];
		for (int i = 1; i < m_size; i++) {
			if (m_array[i] > max) {
				max = m_array[i];
			}
		}
		return max;
	}

	//---------------------Operator Overloaing-------------------------------
	template<typename _Type>
	_Type& Vector<_Type>::operator[](const int& index) const
	{
		if (index < 0 || index > m_size) {
			throw std::out_of_range("[Access violation]: cannot access the value outside the range of array");
			std::exit(1);
		}

		return m_array[index];
	}
}