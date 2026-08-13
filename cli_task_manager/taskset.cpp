#include <vector>
#include <string>
#include <iostream>
#include "taskset.hpp"

void markInComp(std::vector<Task>&v, std::string d)
{
    for (auto it = v.begin(); it < v.end(); it++){
        if (it->name == d){
            it->comp = false;
            return;
        }
    }
}
void markComp(std::vector<Task>&v, std::string c)
{
    for (auto it = v.begin(); it < v.end(); it++){
        if (it->name == c){
            it->comp = true;
            return;
        }
    }
}

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
    std::string done = "[x] ";
    std::string notDone = "[] ";
    int count = 1;
    for (Task task : v){
        if (task.comp) {
            std::cout << count << ". " << done << task.name;
            std::cout<<"\n";
        } else {
            std::cout<< count << ". " << notDone << task.name;
            std::cout<<"\n";
        }
        count += 1;
    }
}






