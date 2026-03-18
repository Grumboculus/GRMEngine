#ifndef LINKEDLIST_HPP
#define LINKEDLIST_HPP

#include <stdexcept>
#include "../Vector/Vector.hpp"

namespace engine {
namespace data_structs {

    /**
     * @brief A basic Node structure used inside the LinkedList.
     * 
     * @tparam T The data type stored in the node.
     */
    template <typename T>
    struct Node {
        T value;     // Data value of this node
        Node* next;  // Pointer to the next node in the list
    };

    /**
     * @brief A templated LinkedList data structure.
     * 
     * @tparam T The data type to store in the LinkedList.
     */
    template <typename T>
    class LinkedList {
        private:
            Node<T>* head; // Pointer to the start of the list
            int m_size;    // Renamed size to m_size to prevent shadowing
            
        public:
            
            LinkedList() {
                head = nullptr;
                m_size = 0;
            }

            // Copy Constructor
            LinkedList(const LinkedList& other) {
                head = nullptr;
                m_size = 0;
                Node<T>* current = other.head;
                while (current != nullptr) {
                    push_back(current->value);
                    current = current->next;
                }
            }

            // Copy Assignment
            LinkedList& operator=(const LinkedList& other) {
                if (this == &other) return *this;
                clear();
                Node<T>* current = other.head;
                while (current != nullptr) {
                    push_back(current->value);
                    current = current->next;
                }
                return *this;
            }

            // Move Constructor
            LinkedList(LinkedList&& other) noexcept : head(other.head), m_size(other.m_size) {
                other.head = nullptr;
                other.m_size = 0;
            }

            // Move Assignment
            LinkedList& operator=(LinkedList&& other) noexcept {
                if (this == &other) return *this;
                clear();
                head = other.head;
                m_size = other.m_size;
                other.head = nullptr;
                other.m_size = 0;
                return *this;
            }

            ~LinkedList() {
                clear();
            }

            void clear() {
                Node<T>* current = head;
                while (current != nullptr) {
                    Node<T>* nextNode = current->next;
                    delete current;                    
                    current = nextNode;
                }
                head = nullptr;
                m_size = 0;
            }

            void push_front(const T& value) {
                Node<T>* newNode = new Node<T>;

                newNode->value = value;
                newNode->next = head;

                head = newNode;

                m_size++;
            }

            void push_back(const T& value) {
                Node<T>* newNode = new Node<T>;
                newNode->value = value;
                newNode->next = nullptr;

                if (head == nullptr) {
                    head = newNode;
                } else {
                    Node<T>* current = head;

                    while (current->next != nullptr) {
                        current = current->next;
                    }

                    current->next = newNode;
                }
                m_size++;
            }

            void pop_front() {
                if (head == nullptr) return;

                Node<T>* nodeToDelete = head;

                head = head->next;

                delete nodeToDelete;

                m_size--;
            }

            void pop_back() {
                if (head == nullptr) return;

                if (head->next == nullptr) {
                    delete head;
                    head = nullptr;
                    m_size--;
                    return;
                }

                Node<T>* current = head;
                while (current->next->next != nullptr) {
                    current = current->next;
                }

                delete current->next;

                current->next = nullptr;

                m_size--;
            }

            void insert(const T& insertedValue, int index) {
                if ( index < 0 || index > m_size ) { throw std::out_of_range("Index provided is out of bounds."); }

                Node<T>* insertedNode = new Node<T>;

                insertedNode->value = insertedValue;

                if (index == 0) {
                    insertedNode->next = head;
                    head = insertedNode;
                    m_size++;
                    return;
                }

                Node<T>* current = head;
                for ( int i = 0; i < index - 1; i++) {
                    current = current->next;
                }

                Node<T>* temp = current->next;

                current->next = insertedNode;
                insertedNode->next = temp;

                m_size++;
            }
            
            void remove(int index) {
                if ( index >= m_size || index < 0 ) throw std::out_of_range("Provided Index was out of bounds.");

                if ( index == 0 ) {
                    Node<T>* temp = head->next;

                    delete head;
                    head = temp;
                    m_size--;
                    return;
                }

                Node<T>* current = head;
                for ( int i = 0; i < index - 1; i++) {
                    current = current->next;
                }

                Node<T>* nodeToDelete = current->next;
                current->next = nodeToDelete->next;

                delete nodeToDelete;
                m_size--;
            }
    
            void erase(const T& removedValue) {
                // Erase ALL matching values
                while (head != nullptr && head->value == removedValue) {
                    pop_front();
                }

                if (head == nullptr) return;

                Node<T>* current = head;
                while (current->next != nullptr) {
                    if (current->next->value == removedValue) {
                        Node<T>* nodeToDelete = current->next;
                        current->next = nodeToDelete->next;
                        delete nodeToDelete;
                        m_size--;
                    } else {
                        current = current->next;
                    }
                }
            }
    
            T& front() {
                if (head == nullptr) throw std::domain_error("List head points to null.");
                return head->value;
            }

            const T& front() const {
                if (head == nullptr) throw std::domain_error("List head points to null.");
                return head->value;
            }

            T& back() {
                if (head == nullptr) throw std::domain_error("List head points to null.");

                Node<T>* current = head;

                while ( current->next != nullptr ) {
                    current = current->next;
                }

                return current->value;
            }

            const T& back() const {
                if (head == nullptr) throw std::domain_error("List head points to null.");

                Node<T>* current = head;

                while ( current->next != nullptr ) {
                    current = current->next;
                }

                return current->value;
            }

            T& at(int index) {
                if (index < 0 || index >= m_size) throw std::out_of_range("Index provided is out of bounds.");

                Node<T>* current = head;

                for ( int i = 0; i < index; i++) {
                    current = current->next;
                }

                return current->value;
            }

            const T& at(int index) const {
                if (index < 0 || index >= m_size) throw std::out_of_range("Index provided is out of bounds.");

                Node<T>* current = head;

                for ( int i = 0; i < index; i++) {
                    current = current->next;
                }

                return current->value;
            }

            T& operator[](int index) {
                return this->at(index);
            }

            const T& operator[](int index) const {
                return this->at(index);
            }
    
            int size() const {return m_size;}

            bool isEmpty() const {
                return m_size == 0;
            }
    
            engine::data_structs::Vector<Node<T>*> find(const T& neededValue) {
                Node<T>* current = head;

                engine::data_structs::Vector<Node<T>*> ReturnVector;

                while (current != nullptr) {
                    if (current->value == neededValue) {
                        ReturnVector.Push(current);
                    }
                    current = current->next;
                }

                return ReturnVector;
            }
    
            
    };

}
}

#endif