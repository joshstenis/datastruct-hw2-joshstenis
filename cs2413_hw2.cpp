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
         * This struct will be each node of the DLL
         */
        struct Node {
            int capacity;
            Node *ptr_next, *ptr_prev;
        };

    public:

        /**
         * Insert an element into the doubly linked list if key is not already present
         * @param key The value to be inserted into the DLL
         */
        void insert(int key) {

        }

        int main() {
            string task, key;
            string val = "";
            cin >> task;                    // Intake the task and seach key
            cin >> key;

            cin.ignore(1, '\n');
            Node *prev;
            bool firstTime = true;

            while(val != "s") {             // Create doubly linked list based on second line of string
                cin >> val;
                Node tmp;

                tmp.capacity = strToInt(val);
                if(!firstTime) {
                    Node previous = *prev;

                    tmp.ptr_prev = previous.ptr_prev;
                    previous.ptr_next = &tmp;
                } firstTime = false;

                prev = &tmp;
            }

            switch(strToInt(task)) {                // Execute proper task
                case 0:

                    // Binary search

                    break;
                case 1:

                    // Insert / Delete

                    break;
                default: break;
            }
        }
};