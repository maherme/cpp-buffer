/**
 * @file PQueue.cpp
 * @brief this file contains methods of class PQueue.
 */

#include <string>
#include <queue>
#include <iostream>
#include <stdlib.h>
#include "PQueue.h"
#include "../Data/Data.h"

/**
 * @brief method to capture and process the command value:priority, and to store in the queue.
 *
 * @param[in] str: the string read as command.
 *
 * @returns -1 if an error ocurred, 0 if completed OK.
 */
int PQueue::check_command(std::string str){

    Data ins_data;
    int value_i, priority_i = 0;
    size_t sz_v, sz_p;
    static long count = 0;

    try{
        value_i = stoi(str, &sz_v, 10);
    }
    catch(const std::invalid_argument){
        std::cout << "Error in command format -> value:priority (integer:integer)" << std::endl;
        return -1;
    }

    try{
        priority_i = stoi(str.substr(sz_v+1), &sz_p, 10);
    }
    catch(const std::invalid_argument){
        std::cout << "Error in command format -> value:priority (integer:integer)" << std::endl;
        return -1;
    }
    catch(const std::out_of_range){
        std::cout << "Error in command format -> value:priority (integer:integer)" << std::endl;
        return -1;
    }

    if(str.size() != (sz_v+sz_p+1)){
        std::cout << "Error in command format -> value:priority (integer:integer)" << std::endl;
        return -1;
    }

    ins_data.setval(value_i, priority_i, count);
    count++;
    this->push(ins_data);

    return 0;
}

/**
 * @brief method to print the full queue to STDOUT.
 *
 */
void PQueue::print(void){

    PQueue aux_queue = *this;

    if(aux_queue.empty() != true){
        while(aux_queue.empty() != true){
            std::cout << aux_queue.top().getval() << std::endl;
            aux_queue.pop();
        }
    }
    else{
        std::cout << "Error: buffer is empty" << std::endl;
    }
}

/**
 * Method to print the first element of the queue to STDOUT.
 *
 */
void PQueue::get(void){

    if(this->empty() == false){
        std::cout << this->top().getval() << std::endl;
    }
    else{
        std::cout << "Error: buffer is empty" << std::endl;
    }
}

/**
 * Method to remove the first element of the queue.
 *
 */
void PQueue::remove(void){

    if(this->empty() == false){
        std::cout << this->top().getval() << " will be removed" << std::endl;
        this->pop();
    }
    else{
        std::cout << "Error: buffer is empty" << std::endl;
    }
}
