#include <iostream>
class Array {
	int m_size;
	int* m_ptr;
public:Array() {}
	  Array(int size) :m_size(size) {
		  m_ptr = new int[size];
	  }
	  Array(Array&& obj) {
		  m_size = obj.m_size;
		  m_ptr = obj.m_ptr;
		  obj.m_size = 0;
		  obj.m_ptr = nullptr;

	  }
	  Array& operator = (const Array& other) {
		  m_size = other.m_size;
		  m_ptr = new int[other.m_size];
		  for (int i = 0; i < m_size; ++i) {
			  m_ptr[i] = other.m_ptr[i];
		  }
		  return *this;
	  }
		  ~Array() {
		  delete[] m_ptr;
	  }
public:
	int getsize() {
		return m_size;
	}
};
int main() {
	Array arr(5);
	Array arr2(3);
	arr2 = std::move(arr);
	std::cout << "The size of array: " << arr2.getsize() << std::endl;
	Array arr1(std::move(arr));
	std::cout << "The size of array: " << arr1.getsize() << std::endl;
}
