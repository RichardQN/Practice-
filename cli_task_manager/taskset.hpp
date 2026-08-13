#include <vector>
#include <string>
#ifndef TASKSET_HPP
#define TASKSET_HPP

struct Task {
    std::string name;
    bool comp = false;
};

void addTask(std::vector<Task>& v, std::string a);
void viewTask(const std::vector<Task>& v);
void deleteTask(std::vector<Task>&v, std::string b);
void markComp(std::vector<Task>&v, std::string c);
void markInComp(std::vector<Task>&v, std::string d);

#endif