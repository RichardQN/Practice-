#include <vector>
#include <string>
#include <iostream>
#include "taskset.hpp"

void addTask(std::vector<std::string>& v, std::string a)
{
    v.push_back(a);
}

void viewTask(const std::vector<std::string>& v) 
{
    for (std::string task : v){
        std::cout<<task;
        std::cout<<"\n";
    }
}






