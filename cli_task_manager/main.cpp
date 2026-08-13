#include <iostream>
#include "taskset.hpp"
#include <vector>
#include <string>

int main(){
    int choice = 0;
    std::vector<std::string>taskList;
    try {
        while (choice != 5){
            std::cout<<"Task List: \n Add:1 \n View: 2 \n Choice: ";
            std::cin>>choice;
            if (choice == 1){
                std::string x;
                std::cout<<"Type out a task to add: ";
                std::cin>>x;
                addTask(taskList, x);
            } 
            if (choice == 2){
                viewTask(taskList);
            }

        }
    }
    catch(const std::exception e){
        std::cout<<"Error!";
    }
    return 0;



}
