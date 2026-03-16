#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <stdexcept>

namespace engine {
namespace tables {

    template <typename T>
    class Vector {
        private:
            T* m_data;
            int size;
            int capacity;
        
        public:
            Vector() {
                capacity = 4;
                size = 0;
                m_data = new T[capacity];
            }

            ~Vector() {
                delete[] m_data;
            }

            void Push(T insert) {
                if (size == capacity) {
                    T* temp = new T[capacity * 2];
                    for (int i = 0; i < size; i++) {
                        temp[i] = m_data[i];
                    }

                    delete[] m_data;
                    m_data = temp;
                    capacity = capacity * 2;
                }

                m_data[size] = insert;
                size++;
            }

            void Pop() {
                if (size > 0) {
                    size--;
                }
            }

            T& Get(int index) {
                if (size <= index || index < 0) {
                    throw std::out_of_range("Out of bounds.");
                }
                return m_data[index];
            }

            const T& Get(int index) const {
                if (size <= index || index < 0) {
                    throw std::out_of_range("Out of bounds.");
                }
                return m_data[index];
            }

            int Size() const {
                return size;
            }

            Vector(const Vector& other) {
                capacity = other.capacity;
                size = other.size;

                m_data = new T[capacity];
                for (int i = 0; i < size; i++) {
                    m_data[i] = other.m_data[i];
                }
            }

            Vector& operator=(const Vector& other) {
                if (this == &other) {
                    return *this;
                }

                delete[] m_data;

                capacity = other.capacity;
                size = other.size;

                m_data = new T[capacity];
                for (int i = 0; i < size; i++) {
                    m_data[i] = other.m_data[i];
                }


                return *this;
            }

            Vector(Vector&& other) {
                size = other.size;
                capacity = other.capacity;

                m_data = other.m_data;

                other.m_data = nullptr;
                other.capacity = 0;
                other.size = 0;
            }

            Vector& operator=(Vector&& other) {
                if (this == &other) {return *this;}

                delete[] m_data;

                size = other.size;
                capacity = other.capacity;

                m_data = other.m_data;

                other.m_data = nullptr;
                other.capacity = 0;
                other.size = 0;

                return *this;
            }

            T& operator[](int index) {
                return this->Get(index);
            }

            void Clear() {
                size = 0;
            }

            bool isEmpty() const {
                return size == 0;
            }
    };

}
}

#endif