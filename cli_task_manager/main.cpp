#include <iostream>
#include "taskset.hpp"
#include <vector>
#include <string>

int main(){
    int choice = 0;
    std::vector<Task>taskList;
    try {
        while (choice != 7){
            std::cout<<"Enter your choice: ";
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
            if (choice == 3){
                std::string x;
                std::cout<<"Type out a task to delete: ";
                std::cin>>x;
                deleteTask(taskList, x);
            }
            if (choice == 4){
                std::string x;
                std::cout<<"Type out a task to complete: ";
                std::cin>>x;
                markComp(taskList, x);
            }
            if (choice == 5){
                std::string x;
                std::cout<<"Type out a task to mark incomplete: ";
                std::cin>>x;
                markInComp(taskList, x);
            }
            if (choice == 6){
                std::cout<<"Task List:\nAdd:1\nView:2\nDelete:3\nMark:4\nUnmark:5\nHelp:6\n";
            }

        }
    }
    catch(const std::exception e){
        std::cout<<"Error!";
    }
    return 0;



}
