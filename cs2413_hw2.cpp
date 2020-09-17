#include <iostream>
#include <cmath>
using namespace std;

class Course {

        int capacity;
        int *ptr_next;
        int *ptr_prev;

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

    public:

        Course(int capactiy) {
            this->capacity = capacity;
        }

        Course(int capactiy, int *prev) {
            this->capacity = capacity;
            this->ptr_prev = prev;
        }

        Course(int capactiy, int *next) {
            this->capacity = capacity;
            this->ptr_next = next;
        }

        Course(int capacity, int *prev, int *next) {
            this->capacity = capacity;
            this->ptr_next = next;
            this->ptr_prev = prev;
        }

        /**
         * Sets the integer value stored by the Course object
         * @param capacity The integer value to be stored
         */
        void setCapacity(int capacity) {
            this->capacity = capacity;
        }
        
        /**
         * Sets the Course object's pointer to next doubly linked list object
         * @param next The pointer to be assigned to the ptr_next field
         */
        void setNext(int *next) {
            this->ptr_next = next;
        }
        
        /**
         * Sets the Course object's pointer to previous doubly linked list object
         * @param prev The pointer to be assigned to the ptr_prev field
         */
        void setPrev(int *prev) {
            this->ptr_prev = prev;
        }

        /**
         * Get the value stored in the Course object
         * @return The integer value stored by the Course object
         */
        int getCapactiy() {
            return this->capacity;
        }
        
        /**
         * Get the next Course object in the doubly linked list
         * @return The pointer to the next Course object in the list
         */
        int *getNext() {
            return this->ptr_next;
        }
        
        /**
         * Get the previous Course object in the doubly linked list
         * @return The pointer to the previous Course object in the list
         */
        int *getPrev() {
            return this->ptr_prev;
        }

        int main() {
            string task, key, val;
            cin >> task;
            cin >> key;

            cin.ignore(1, '\n');
            do {
                cin >> val;
                Course c (strToInt(val));
            } while(val != "s");
        }
};