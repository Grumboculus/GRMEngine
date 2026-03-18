#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <stdexcept>

namespace engine {
namespace data_structs {

    /**
     * @brief A dynamic array implementation that resizes automatically.
     * 
     * @tparam T The type of data to store in the Vector.
     */
    template <typename T>
    class Vector {
        private:
            T* m_data;    // Pointer to the underlying array data
            int size;     // Current number of elements in the Vector
            int capacity; // Maximum currently allocated capacity
        
        public:
            /**
             * @brief Default constructor. Initializes an empty Vector with a default capacity of 4.
             */
            Vector() {
                capacity = 4;
                size = 0;
                m_data = new T[capacity];
            }

            /**
             * @brief Destructor. Frees the allocated memory.
             */
            ~Vector() {
                delete[] m_data;
            }

            /**
             * @brief Adds an element to the end of the Vector.
             * Resizes the internal array capacity if necessary.
             * 
             * @param insert The element to append.
             */
            void Push(T insert) {
                // Resize if maximum capacity is reached
                if (size == capacity) {
                    capacity = capacity * 2;
                    T* temp = new T[capacity];
                    for (int i = 0; i < size; i++) {
                        temp[i] = m_data[i];
                    }

                    delete[] m_data;
                    m_data = temp;
                }

                // Insert the new element and increment size
                m_data[size] = insert;
                size++;
            }

            /**
             * @brief Removes the last element from the Vector.
             */
            void Pop() {
                if (size > 0) {
                    size--;
                }
            }

            /**
             * @brief Retrieves a reference to the element at the specified index.
             * 
             * @param index The index of the element to retrieve.
             * @return T& A reference to the element.
             * @throws std::out_of_range If the index is out of bounds.
             */
            T& Get(int index) {
                if (size <= index || index < 0) {
                    throw std::out_of_range("Out of bounds.");
                }
                return m_data[index];
            }

            /**
             * @brief Retrieves a const reference to the element at the specified index.
             * 
             * @param index The index of the element to retrieve.
             * @return const T& A const reference to the element.
             * @throws std::out_of_range If the index is out of bounds.
             */
            const T& Get(int index) const {
                if (size <= index || index < 0) {
                    throw std::out_of_range("Out of bounds.");
                }
                return m_data[index];
            }

            /**
             * @brief Gets the current number of elements in the Vector.
             * 
             * @return int The number of elements.
             */
            int Size() const {
                return size;
            }

            /**
             * @brief Copy constructor. Performs a deep copy of the other Vector.
             * 
             * @param other The Vector to copy from.
             */
            Vector(const Vector& other) {
                capacity = other.capacity;
                size = other.size;

                m_data = new T[capacity];
                for (int i = 0; i < size; i++) {
                    m_data[i] = other.m_data[i];
                }
            }

            /**
             * @brief Copy assignment operator. Performs a deep copy.
             * 
             * @param other The Vector to assign from.
             * @return Vector& A reference to this Vector.
             */
            Vector& operator=(const Vector& other) {
                if (this == &other) {
                    return *this; // Handle self-assignment
                }

                // Free existing data
                delete[] m_data;

                // Copy over properties and allocate new array
                capacity = other.capacity;
                size = other.size;

                m_data = new T[capacity];
                for (int i = 0; i < size; i++) {
                    m_data[i] = other.m_data[i];
                }

                return *this;
            }

            /**
             * @brief Move constructor. Takes ownership of the other Vector's resources.
             * 
             * @param other The Vector to move from.
             */
            Vector(Vector&& other) noexcept {
                size = other.size;
                capacity = other.capacity;

                m_data = other.m_data;

                // Reset the moved-from Vector
                other.m_data = nullptr;
                other.capacity = 0;
                other.size = 0;
            }

            /**
             * @brief Move assignment operator. Takes ownership of the other Vector's resources.
             * 
             * @param other The Vector to move from.
             * @return Vector& A reference to this Vector.
             */
            Vector& operator=(Vector&& other) noexcept {
                if (this == &other) {
                    return *this; // Handle self-assignment
                }

                // Free existing data
                delete[] m_data;

                // Steal data
                size = other.size;
                capacity = other.capacity;
                m_data = other.m_data;

                // Reset the moved-from object
                other.m_data = nullptr;
                other.capacity = 0;
                other.size = 0;

                return *this;
            }

            /**
             * @brief Array subscript operator overloading.
             * 
             * @param index The index to access.
             * @return T& A reference to the accessed element.
             */
            T& operator[](int index) {
                return this->Get(index);
            }

            /**
             * @brief Clears the Vector, effectively setting its size to 0.
             */
            void Clear() {
                size = 0;
            }

            /**
             * @brief Checks if the Vector is empty.
             * 
             * @return true If the Vector contains no elements.
             * @return false If the Vector contains one or more elements.
             */
            bool isEmpty() const {
                return size == 0;
            }
    };

}
}

#endif