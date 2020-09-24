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

        int getCap() {
            return capacity;
        }

        void setNext(Course *next) {
            this->next = next;
        }

        void setPrev(Course *prev) {
            this->prev = prev;
        }

        Course *getNext() {
            return next;
        }

        Course *getPrev() {
            return prev;
        }
};

Course *getTail(Course **node) {
    Course *iter = *node;
    while(iter->getNext() != NULL)
        iter = iter->getNext();
    return iter;
}

Course *getHead(Course **node) {
    Course *iter = *node;
    while(iter->getPrev() != NULL)
        iter = iter->getPrev();
    return iter;
}

void insertEnd(Course **head, int capacity) {
    Course *node = new Course(capacity);

    if(*head == NULL) *head = node;
    else {
        Course *tail = getTail(head);
        tail->setNext(node);
        node->setPrev(tail);
    }
}

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

Course *binarySearch(Course **head, int key) {
    Course *h = *head;
    Course *t = getTail(head);

    cout << "THE SEARCH HAS BEGUN..." << endl;

    do {
        Course *mid = middle(&h, &t);

        if(mid == NULL) return NULL;                            // Null mid catch
        else if(mid->getCap() == key) return mid;               // Mid is the desired element
        else if(mid->getCap() < key) h = mid->getNext();         // Mid comes BEFORE the desired element in the DLL
        else t = mid;                                           // Mid comes AFTER the desired element in the DLL
    } while(t == NULL || h != t);
    return NULL;
}

void output(Course **result, int key) {
    if(result == NULL) cout << "Value " << key << " was not found" << endl;
    else cout << "Value " << key << " was found." << endl;
}

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
            output(&result, key);
        } break;

        case 1:
        {
            // INSERT / DELETE
        } break;

        default: break;
    }
}