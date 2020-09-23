#include <iostream>
#include <cmath>
using namespace std;

class Course {
    int capacity;
    Course *next, *prev;

    public:

        Course(int cap) {
            capacity = cap;
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

Course *getTail(Course **head) {
    Course *iter = *head;
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

Course *middle(Course **head) {
    Course *fast = *head;
    Course *slow = (*head)->getNext();

    Course *tail = getTail(head);

    cout << "MIDDLE STARTED...";

    while(fast != tail) {
        fast = fast->getNext();
        if(fast != tail) {
            fast = fast->getNext();
            slow = slow->getNext();
        }
    } cout << " MIDDLE COMPLETE" << endl;
    
    return slow;
}

Course *binarySearch(Course **head, int key) {
    Course *h = *head;
    Course *t = getTail(head);
    Course *mid;

    cout << "THE SEARCH HAS BEGUN..." << endl;

    do {
        Course *mid = middle(head);

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
    } cout << "POPULATED" << endl;

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