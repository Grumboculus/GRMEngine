#ifndef LINKEDLIST_HPP
#define LINKEDLIST_HPP

#include <stdexcept>

namespace engine {
namespace tables {

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
            int size;
            
        public:
            
            LinkedList() {
                head = nullptr
                size = 0;
            }

            ~LinkedList() {
                Node<T>* current = head;
                while (current != nullptr) {
                    Node<T>* nextNode = current->next; // Save the next pointer before deleting
                    delete current;                    // Free the memory
                    current = nextNode;
                }
            }

            void push_front(const T& value) {
                Node<T>* NewNode = new Node<T>;

                NewNode->value = value;
                NewNode->next = head;

                head = NewNode;

                size++;
            }

            void push_back(const T& value) {
                Node<T>* NewNode = new Node<T>;
                NewNode->value = value;
                NewNode->next = nullptr;

                if (head == nullptr) {
                    head = NewNode;
                } else {
                    Node<T>* current = head;

                    while (current->next != nullptr) {
                        current = current->next;
                    }

                    current->next = NewNode;
                }
                size++;
            }

            void pop_front() {
                if (head == nullptr) return;

                Node<T>* nodeToDelete = head;

                head = head->next;

                delete nodeToDelete;

                size--;
            }

            void pop_back() {
                if (head == nullptr) return;

                if (head->next == nullptr) {
                    delete head;
                    head = nullptr;
                    size--;
                    return;
                }

                Node<T>* current = head;
                while (current->next->next != nullptr) {
                    current = current->next;
                }

                delete current->next;

                current->next = nullptr;

                size--;
            }

            void insert(T insert, int index) {
                if ( index < 0 || index > size ) { throw std::out_of_range("Index provided is out of bounds.")};

                Node<T>* InsertedNode = new Node<T>;

                InsertedNode->value = insert;

                if (index == 0) {
                    InsertedNode->next = head;
                    head = InsertedNode;
                    return;
                }

                Node<T>* current = head;
                for ( int i = 0; i < index - 1; i++) {
                    current = current->next;
                }

                Node<T>* Temporary = current->next;

                current->next = InsertedNode;
                InsertedNode->next = Temporary;

                size++;
            }
            
            void remove(int index) {
                if ( index > size || index < -1 ) throw std::out_of_range("Provided Index was out of bounds.");

                if ( index == 0 ) {
                    Node<T>* Temporary = head->next;

                    delete head;
                    Temporary = head;
                }

                Node<T>* current = head;
                for ( int i = 0; i < index - 1; i++) {
                    current = current->next;
                }

                if ( current->next == nullptr ) {
                    delete current->next;
                }

                Node<T>* afterList = current->next->next;

                delete current->next;

                current->next = afterList;

                size--;
            }
    
            void erase(T removedValue) {
                Node<T>* current = head;
                for ( int i = 0; i < size; i++) {
                    current = current->next;

                    if (current->next->value == removedValue) {
                        Node<T>* temporarynext = current->next;

                        delete current->next;

                        current->next = temporarynext;

                        size--;
                    }
                }
            }
    
            Node<T>* front() {
                return head;
            }

            Node<T>* back() {
                Node<T>* current = head;
                while ( current->next != nullptr ) {
                    current->next;
                }

                return current;
            }

            Node<T>* at(int index) {
                Node<T>* current = head;

                for ( int i = 0; i < index; i++) {
                    current = current->next;
                }

                return current;
            }

            Node<T>* operator[](int index) {
                return this->at(index);
            }
    
            int size() {return size;}

            bool isEmpty() {
                return size == 0;
            }
    
            /*
                TO FIX:
                    Currently returns only one value
                    No safety if no value found
            */
            Node<T>* find(T neededValue) {
                Node<T>* current = head;
                for (int i = 0; i < size; i++) {
                    current = current->next

                    if (current->value == neededValue) return current;
                }
            }
    
            
    };

}
}

#endif