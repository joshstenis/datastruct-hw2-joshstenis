#include <iostream>
#include <cmath>
using namespace std;

class Course {
    int capacity;
    Course *next, *prev;

    public:

        Course(int cap) {
            capacity = cap;
            next = NULL;
            prev = NULL;
        }

        /**
         * Returns the capacity
         * @return The capacity 
         */
        int getCap() {
            return capacity;
        }

        /**
         * Sets the next ptr
         * @param next The ptr to be set as next
         */
        void setNext(Course *next) {
            this->next = next;
        }

        /**
         * Sets the prev ptr
         * @param prev The ptr to be set as prev
         */
        void setPrev(Course *prev) {
            this->prev = prev;
        }

        /**
         * Returns the next ptr
         * @return The next ptr 
         */
        Course *getNext() {
            return next;
        }

        /**
         * Returns the prev ptr
         * @return The prev ptr 
         */
        Course *getPrev() {
            return prev;
        }
};

/**
 * Finds the tail node of the DLL containing the given node
 * @param node Any node in the DLL ( doesnt matter which node in the DLL )
 * @return A ptr to the tail node of the DLL
 */
Course *getTail(Course **node) {
    Course *iter = *node;
    while(iter->getNext() != NULL)
        iter = iter->getNext();
    return iter;
}

/**
 * Finds the head node of the DLL containing the given node
 * @param node Any node in the DLL ( doesnt matter which node in the DLL )
 * @return A ptr to the head node of the DLL
 */
Course *getHead(Course **node) {
    Course *iter = *node;
    while(iter->getPrev() != NULL)
        iter = iter->getPrev();
    return iter;
}

/**
 * Inserts a node of given value at the end of given DLL
 * @param head The head of given DLL
 * @param capacity The value to be stored in the node
 */
void insertEnd(Course **head, int capacity) {
    Course *node = new Course(capacity);

    if(*head == NULL) *head = node;
    else {
        Course *tail = getTail(head);
        tail->setNext(node);
        node->setPrev(tail);
    }
}

/**
 * Finds the middle node of the given DLL ( or segment thereof )
 * @param start The starting bound for the DLL ( or segment thereof ) to be median'd
 * @param end The ending bound for the DLL ( or segment thereof ) to be median'd
 */
Course *middle(Course **start, Course **end) {
    Course *fast = (*start)->getNext();
    Course *slow = *start;

    cout << "MIDDLE STARTED...";

    while(fast != *end) {
        fast = fast->getNext();
        if(fast != *end) {
            fast = fast->getNext();
            slow = slow->getNext();
        }
    } cout << " MIDDLE COMPLETE" << endl;
    
    return slow;
}

/**
 * Binary searches the DLL given for the key value given
 * @param head The head node of the DLL to be searched
 * @param key The value being searched for
 */
Course *binarySearch(Course **head, int key) {
    Course *h = *head;
    Course *t = getTail(head);

    do {
        Course *mid = middle(&h, &t);

        if(mid == NULL) return NULL;                            // Null mid catch
        else if(mid->getCap() == key) return mid;               // Mid is the desired element
        else if(mid->getCap() < key) h = mid->getNext();         // Mid comes BEFORE the desired element in the DLL
        else t = mid;                                           // Mid comes AFTER the desired element in the DLL
    } while(t == NULL || h != t);
    return NULL;
}

/**
 * DEBUGGING: Outputs the result of binary search
 * @param result The resulting
 * @param key The key value
 */
void outputSearchResult(Course **result, int key) {
    if(*result == NULL) cout << "Value " << key << " was not found" << endl;
    else cout << "Value " << key << " was found." << endl;
}

/**
 * DEBUGGING: Returns the length of the given DLL
 * @param head The head of the DLL
 * @return The length of the DLL
 */
int dllLength(Course **head) {
    Course *iter = *head;
    int i = 0;
    while(iter->getNext() != NULL) {
        iter = iter->getNext();
        i++;
    } return i;
}

int main() {
    int task, key, val;
    cin >> task;
    cin >> key;
    cin.ignore(1, '\n');

    Course *head = NULL;                // Create head node
    cin >> val;
    insertEnd(&head, val);

    while(!cin.fail()) {                // Populate DLL based off head node
        cin >> val;
        insertEnd(&head, val);
    } cout << "POPULATED - LENGTH: " << dllLength(&head) << endl;

    switch(task) {                      // Complete assigned task
        case 0:
        {
            Course *result = binarySearch(&head, key);
            outputSearchResult(&result, key);
        } break;

        case 1:
        {
            // INSERT / DELETE
        } break;

        default: break;
    }
}