#include <iostream>
#include <cmath>
using namespace std;


/**
 * 
 * NOTE: The acronym "DLL" will refer to "Doubly Linked List"
 * 
 */


class Course {

        /**
         * This struct will be each node of the DLL
         */
        struct Node {
            int capacity;
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

        Node *head, *tail;

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

        /**
         * Finds middle Node of a DLL whose head and tail Nodes are given
         * @param head The first element of the DLL
         * @param tail The last element of the DLL
         */
        Node *middle(Node *head, Node *tail) {
            Node *fast = head;
            Node *slow = head->ptr_next;

            while(fast != tail) {
                fast = fast->ptr_next;
                if(fast != tail) {
                    fast = fast->ptr_next;
                    slow = slow->ptr_next;
                }
            } return slow;
        }

    public:

        Course();

        Course(Node*);

        /**
         * Adds elements to the end of the DLL
         * @param new The Node to be added to the DLL
         */
        void append(Node n) {
            Node nCopy = n;
            
            if(this->head == NULL) {                // Empty DLL
                this->head = &nCopy;
                this->tail = this->head;
            } else {                                // Non-Empty DLL
                nCopy.ptr_prev = this->tail;
                this->tail->ptr_next = &nCopy;
                this->tail = &nCopy;
            }
        }

        /**
         * Binary searches through the DLL whose head Node is given
         * @param head The first element of the DLL
         * @param key The value that is being searched for
         */
        Node *binarySearch(Node *head, int key) {
            Node *tail, *mid;
            do {
                Node *mid = middle(head, tail);

                if(mid == NULL) return NULL;                            // Null mid catch
                else if(mid->capacity == key) return mid;               // Mid is the desired element
                else if(mid->capacity < key) head = mid->ptr_next;      // Mid comes BEFORE the desired element in the DLL
                else tail = mid;                                        // Mid comes AFTER the desired element in the DLL
            } while(tail == NULL || head != tail);
        }

        /**
         * Output the result of the given task
         * @param result A ptr to the Node that has been dealt with ( value equal to key )
         */
        void output(Node *result) {
            //
        }

        /**
         * Output the resulting DLL of the given task
         * @param result A ptr to the DLL in question
         */
        void output(Course *result) {
            //
        }

        int main() {
            string task, key;
            cin >> task;                    // Intake the task and seach key
            cin >> key;

            cin.ignore(1, '\n');
            Node head;
            Node *prev;
            bool firstTime = true;

            string val = "";
            Course *list = new Course();
            while(val != "s") {             // Populate doubly linked list based on second line of string
                cin >> val;
                Node tmp;

                tmp.capacity = strToInt(val);
                (*list).append(tmp);


                // if(!firstTime) {
                    // Node previous = *prev;
                    // tmp.ptr_prev = previous.ptr_prev;
                    // previous.ptr_next = &tmp;
                // } else Course list (&tmp);

                // firstTime = false;
                // prev = &tmp;
            }

            switch(strToInt(task)) {                // Execute proper task
                case 0:
                    
                    Node *result = binarySearch(&head, strToInt(key));
                    output(result);

                    break;
                case 1:

                    // Insert / Delete

                    break;
                default: break;
            }
        }
};