#pragma once
#include <iostream>
#include <iostream>


namespace SGT {

	class String {
	private:
		char* m_string;
		size_t m_length;
	private:
		void swap(char& first, char& second) {
			char temp = first;
			first = second;
			second = temp;
		}
	public:
		//------------------------Constructor------------------------------

		String()
			:m_string(nullptr), m_length(0){ }
		//Time Complexity: O(N)
		String(const char* text) {
			m_length = strlen(text);
			m_string = new char[m_length];
			memcpy(m_string, text, m_length);
		}
		//Time Complexity: O(N)
		String(const String& other) {
			//Copy another String into the new String
			m_length = other.m_length;
			m_string = new char[m_length];
			memcpy(m_string, other.m_string, m_length);
		}

		//Time Complexity: O(1)
		String(String&& other) noexcept {
			//Move another String into the new String
			// it'll work when you use std::move();
			m_length = other.m_length;
			m_string = other.m_string;

			other.m_length = 0;
			other.m_string = nullptr;
		}
		~String() {
			delete[] m_string;
		}

		//------------------------Methods------------------------------

		const size_t length() const {
			return m_length;
		}

		//Time Complexity: O(N)
		//ASCII: A-Z ==> 65-90 
		void toLowerCase() {
			for (int i = 0; i < m_length; i++) {
				if (m_string[i] > 64 && m_string[i] < 91) {
					m_string[i] += 32;
				}
			}
		}
		//Time Complexity: O(N)
		//ASCII: a-z ==> 97-122 
		void toUpperCase() {
			for (int i = 0; i < m_length; i++) {
				if (m_string[i] > 96 && m_string[i] < 123) {
					m_string[i] -= 32;
				}
			}
		}
		//Time Complexity: O(N/2) ==> O(N)
		void reverse() {
			size_t size = m_length - 1;
			for (int i = 0; i < size/2; i++) {
				swap(m_string[i], m_string[size - i]);
			}
		}

		//Check if the strings are the same
		//Time Complexity: O(N)
		const bool isTheSame(const String& other) const{
			for (int i = 0; i < m_length; i++) {
				if (m_length != other.m_length && !m_string[i] != other.m_string[i])
					return false;
			}
			return true;
		}

		const bool isTheSame(const char* text) const {
			for (int i = 0; i < m_length; i++) {
				if (m_length != strlen(text) && !m_string[i] != text[i])
					return false;
			}
			return true;
		}

		//------------------------Operator-Overloading------------------------------
		friend std::ostream& operator << (std::ostream& stream, const String& str) {
			
			if (str.m_string != nullptr) {
				for(int i = 0; i < str.m_length; i++)
				stream << str.m_string[i];
			}
			else {
				stream << "null";
			}

			return stream;
		}
	};
}