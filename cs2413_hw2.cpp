#include <iostream>
#include <cmath>
using namespace std;


/**
 * 
 * NOTE: The acronym "DLL" will refer to "Doubly Linked List"
 * 
 */

/**
 * This struct will be each node of the DLL
 */
struct Node {
    int capacity = 0;
    Node *ptr_next, *ptr_prev;

    /**
     * Checks if two Node objects are the identical
     * @param n The Node object to be compared to the first Node object ( Node.compare(Node) )
     */
    bool equals(Node n) {
        if(this->capacity != n.capacity) return false;
        else if(this->ptr_next != n.ptr_next) return false;
        else if(this->ptr_prev != n.ptr_prev) return false;

        return true;
    }
};


class Course {

    private:
        Node *head, *tail;

        /**
         * Finds middle Node of a DLL whose head and tail Nodes are given
         * @param head The first element of the DLL
         * @param tail The last element of the DLL
         */
        Node *middle(Node *head, Node *tail) {
            Node *fast = head;
            Node *slow = head->ptr_next;

            cout << "MIDDLE STARTED...";

            while(fast != tail) {
                fast = fast->ptr_next;
                if(fast != tail) {
                    fast = fast->ptr_next;
                    slow = slow->ptr_next;
                }
            } cout << " MIDDLE COMPLETE" << endl;
            
            return slow;
        }

    public:

        Course();

        Course(Node*);

        /**
         * Adds elements to the end of the DLL
         * @param new The Node to be added to the DLL
         */
        // void append(Node *n) {
        //     Node nCopy;

        //     nCopy.capacity = n->capacity;
        //     nCopy.ptr_next = n->ptr_next;
        //     nCopy.ptr_prev = n->ptr_prev;

        //     if(this->head == NULL) {                // Empty DLL
        //         this->head = &nCopy;
        //         this->tail = this->head;
        //     } else {                                // Non-Empty DLL
        //         nCopy.ptr_prev = this->tail;
        //         this->tail->ptr_next = &nCopy;
        //         this->tail = &nCopy;
        //     }
        // }

        /**
         * Binary searches through the DLL whose head Node is given
         * @param head The first element of the DLL
         * @param key The value that is being searched for
         */
        Node *binarySearch(Node *head, Node *tail, int key) {
            Node *h = head;
            Node *t = tail;
            Node *mid;

            cout << "THE SEARCH HAS BEGUN..." << endl;

            do {
                Node *mid = middle(h, t);

                if(mid == NULL) return NULL;                            // Null mid catch
                else if(mid->capacity == key) return mid;               // Mid is the desired element
                else if(mid->capacity < key) h = mid->ptr_next;         // Mid comes BEFORE the desired element in the DLL
                else t = mid;                                           // Mid comes AFTER the desired element in the DLL
            } while(t == NULL || h != t);
            return NULL;
        }

        /**
         * Sets the head of a DLL
         * @param h The Node ptr to be set to the head of the DLL
         */
        void setHead(Node *h) {
            head = h;
        }

        /**
         * Sets the tail of a DLL
         * @param t The Node ptr to be set to the tail of the DLL
         */
        void setTail(Node *t) {
            tail = t;
        }

        /**
         * Returns the head Node of the DLL
         * @return The head Node of the DLL
         */
        Node *getHead() {
            return head;
        }

        /**
         * Returns the tail Node of the DLL
         * @return The tail Node of the DLL
         */
        Node *getTail() {
            return tail;
        }

        /**
         * Output the resulting DLL of the given task
         * @param result A ptr to the DLL in question
         */
        void output() {
            Node *n = this->getHead();

            cout << n->capacity;
            while(n != this->getTail()) {
                n = n->ptr_next;
                cout << " " << n->capacity;
            } 
        }

        /**
         * Output the result of the given task
         * @param result A ptr to the Node that has been dealt with ( value equal to key )
         */
        void output(Node *result) {
            if(result == NULL) {
                cout << "The given key has not been found in this list" << endl;
            } else {
                cout << "The given key " << result->capacity << " has been found in this list" << endl;
            }
        }
};

/**
 * CONSTRUCTOR for empty Course object ( DLL )
 */
Course::Course() {
    head = NULL;
    tail = NULL;
}

/**
 * CONSTRUCTOR providing a head Node object
 * @param head Ptr to the head Node object of the DLL
 */
Course::Course(Node *head) {
    this->head = head;

    Node *tmp = head;
    while(tmp != NULL) {                        // Sets tail value to last element in DLL rabbit hole
        if(tmp->ptr_next == NULL) break;
        else tmp = tmp->ptr_next;
    } tail = tmp;
}

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

int main() {
    string task, key;
    cin >> task;                    // Intake the task and seach key
    cin >> key;

    int val;
    bool firstTime = true;
    Course *list = new Course();

    cin.ignore(1, '\n');
    while(!cin.fail()) {             // Populate doubly linked list based on second line of string

        // Node prev;
        // cin >> val;
        // prev.capacity = val;

        // Node curr;
        // cin >> val;
        // curr.capacity = val;

        // Node next;
        // cin >> val;
        // next.capacity = val;

        // if(firstTime) {
        //     list->setHead(&prev);
        //     firstTime = false;
        // }

        // prev.ptr_next = &curr;

        // curr.ptr_prev = &prev;
        // curr.ptr_next = &next;

        // next.ptr_prev = &curr;
    } cout << "POPULATED" << endl;
    list->output();
    cout << endl;

    switch(strToInt(task)) {                // Execute proper task
        case 0:
            {
                Node *result = list->binarySearch(list->getHead(), list->getTail(), strToInt(key));
                cout << "SEARCH COMPLETE: " << result->capacity << endl;
                list->output(result);
            } break;
        case 1:
            {} break;
            // Insert / Delete
        default: break;
    }

    return 0;
}