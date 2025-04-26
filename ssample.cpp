#include "iostream"
using namespace std;
int main(){
    class Employee{
        public:
            int id;
            string name;
            Employee(int id, string name){
                this->id = id;
                this->name = name;
            }
    };
}