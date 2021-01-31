#ifndef _FUNCTIONS_H
#define _FUNCTIONS_H

#include <string>
#include <queue>
#include "../Data/Data.h"

int CheckCommand(std::string str, std::priority_queue<Data, std::vector<Data>, std::less<std::vector<Data>::value_type>> &);
void Print(std::priority_queue<Data, std::vector<Data>, std::less<std::vector<Data>::value_type>>);
void Get(std::priority_queue<Data, std::vector<Data>, std::less<std::vector<Data>::value_type>>);
void Remove(std::priority_queue<Data, std::vector<Data>, std::less<std::vector<Data>::value_type>> &);

#endif
