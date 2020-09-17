#include <iostream>
using namespace std;

class Course {
        int capacity;
        int *ptr_next;
        int *ptr_prev;
    public:
        void binarySearch() {
            // 
        }

        int getCapactiy() {
            return this->capacity;
        } int *getNext() {
            return this->ptr_next;
        } int *getPrev() {
            return this->ptr_prev;
        }

        void setCapacity(int capacity) {
            this->capacity = capacity;
        } void setNext(int *next) {
            this->ptr_next = next;
        } void setPrev(int *prev) {
            this->ptr_prev = prev;
        }

        int main() {
            string task, key;
            cin >> task;
            cin >> key;
            
        }
}