#ifndef LINKEDLIST_HPP
#define LINKEDLIST_HPP

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
            
        public:
            // Define expected list methods here
    };

}
}

#endif