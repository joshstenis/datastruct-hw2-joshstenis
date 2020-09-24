#include <iostream>
#include <cmath>
using namespace std;

/**
 * Converts a string number into an integer -- (ex. "-140" == -140)
 * @param str The string number
 */
int strToInt(string str) {
    int val = 0;
    for(int i=0 ;i < str.length(); i++) {
        if(str[i] != '-')
            val += pow(10, str.length()-i) * (str[i] - 48);
    } if(str[0] == '-') val *= -1;
    
    return val/10;
}

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
 * Compares the given key to every node in DLL
 * @param head The head node of the DLL
 * @param key The value to be compared
 * @return The first node found that is >= the key
 */
Course *findSort(Course **head, int key) {
    Course *iter = *head;
    while(iter->getNext() != NULL && iter->getNext()->getCap() < key)
        iter = iter->getNext();
    return iter;
}

/**
 * Inserts a node of given value at the end of given DLL
 * @param head The head of given DLL
 * @param capacity The value to be stored in the node
 */
void sortedInsert(Course **head, int capacity) {
    Course *newNode = new Course(capacity);

    if(*head == NULL) *head = newNode;          // If empty
    else {                                                    // Otherwise
        Course *node = findSort(head, capacity);

        newNode->setNext(node->getNext());
        node->setNext(newNode);
        newNode->setPrev(node);
    }
}

/**
 * Insert nodes at the end of the DLL
 * @param head The head of the DLL
 * @param capacity The value of the new node
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
 * Returns the index of given key value in DLL
 * @param head The head node of the DLL
 * @param key The key value to be found
 * @return The index of the DLL element containing given key value
 */
int getIndexOf(Course **head, Course **key) {
    int i = 0;
    Course *iter = *head;
    while(iter->getNext() != NULL && iter->getCap() != (*key)->getCap()) {
        i++;
        iter = iter->getNext();
    } return i;
}

/**
 * Finds the middle node of the given DLL ( or segment thereof )
 * @param start The starting bound for the DLL ( or segment thereof ) to be median'd
 * @param end The ending bound for the DLL ( or segment thereof ) to be median'd
 */
Course *middle(Course **start, Course **end) {
    Course *fast = (*start)->getNext();
    Course *slow = *start;

    while(fast != *end) {
        fast = fast->getNext();
        if(fast != *end) {
            fast = fast->getNext();
            slow = slow->getNext();
        }
    } return slow;
}

/**
 * Binary searches the DLL given for the key value given
 * @param head The head node of the DLL to be searched
 * @param key The value being searched for
 */
Course *binarySearch(Course **head, int key) {
    Course *h = *head;
    Course *t = getTail(head);
    
    if((*head)->getCap() < key || getTail(head)->getCap() > key) return NULL;

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
 * Outputs the result of binary search
 * @param result The resulting
 * @param key The key value
 */
void outputSearchResult(Course **result, int key) {
    if(*result == NULL) cout << "Value " << key << " was not found" << endl;
    else cout << "Value " << key << " was found." << endl;
}

/**
 * Returns the length of the given DLL
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

/**
 * Prints out the DLL
 * @param head The head node of the DLL
 */
void printDLL(Course **head) {
    Course *iter = *head;
    int i = 0;
    while(iter->getNext() != NULL) {
        cout << iter->getCap() << " ";
        iter = iter->getNext();
    }
}

int main() {
    int task, key;
    string val;
    cin >> task;
    cin >> key;
    cin.ignore(1, '\n');

    Course *head = NULL;                // Create head node

    while(val != "s") {                // Populate DLL based off head node
        cin >> val;
        insertEnd(&head, strToInt(val));
    }

    switch(task) {                      // Complete assigned task
        case 0:
        {
            Course *result = binarySearch(&head, key);
            if(result == NULL) cout << "-1";
            else cout << getIndexOf(&head, &result);
        } break;

        case 1:
        {
            Course *searchResult = binarySearch(&head, key);
            if(searchResult == NULL)
                sortedInsert(&head, key);
            else {
                searchResult->getPrev()->setNext(searchResult->getNext());
                searchResult->getNext()->setPrev(searchResult->getPrev());
            } printDLL(&head);
        } break;

        default: break;
    }
}