/**
 * @file PQueue.h
 * @brief this file contains the definition of class PQueue.
 */

#ifndef PQUEUE_H
#define PQUEUE_H

#include <queue>
#include <iostream>
#include "../Data/Data.h"

/**
 * @brief class derived of priority_queue based on a vector of instances of class Data.
 */
class PQueue : public std::priority_queue<Data, std::vector<Data>, std::less<std::vector<Data>::value_type>>{
    public:
        int check_command(std::string str);
        void print(void);
        void get(void);
        void remove(void);
};

#endif
