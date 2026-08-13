#include <vector>
#include <string>
#include <iostream>
#include "taskset.hpp"

void addTask(std::vector<Task>& v, std::string a)
{
    v.push_back({a, false});
}

void deleteTask(std::vector<Task>&v, std::string b)
{
    if (v.empty()){
        return;
    }
    for (auto it = v.begin(); it != v.end(); it++){
        if (it->name == b){
            v.erase(it);
            return;
        }
    }
}

void viewTask(const std::vector<Task>& v) 
{
    for (Task task : v){
        std::cout<<task.name;
        std::cout<<"\n";
    }
}






