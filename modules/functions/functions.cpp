#include <string>
#include <queue>
#include <iostream>
#include <stdlib.h>
#include "functions.h"
#include "../Data/Data.h"

/* Function to capture and process the command value:priority.
 *
 * Parameters:
 * str: the string read as command.
 * &pqData: priority_queue reference to store object Data with value:priority fields.
 *
 * Return: -1 if an error ocurred, 0 if completed OK.
 */
int CheckCommand(std::string str, std::priority_queue<Data, std::vector<Data>, std::less<std::vector<Data>::value_type>> &pqData){

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
    pqData.push(ins_data);

    return 0;
}

/* Function to print buffer to STDOUT.
 *
 * Parameters:
 * pqData: priority_queue for reading the objects of class Data in the queue.
 */
void Print(std::priority_queue<Data, std::vector<Data>, std::less<std::vector<Data>::value_type>> pqData){

    if(pqData.empty() != true){
        while(pqData.empty() != true){
            std::cout << pqData.top().getval() << std::endl;
            pqData.pop();
        }
    }
    else{
        std::cout << "Error: buffer is empty" << std::endl;
    }
}

/* Function to print the first element of the buffer to STDOUT.
 *
 * Parameters:
 * pqData: priority_queue for reading the first object of class Data in the queue.
 */
void Get(std::priority_queue<Data, std::vector<Data>, std::less<std::vector<Data>::value_type>> pqData){

    if(pqData.empty() == false){
        std::cout << pqData.top().getval() << std::endl;
    }
    else{
        std::cout << "Error: buffer is empty" << std::endl;
    }
}

/* Function to remove the first element of the buffer.
 *
 * Parameters:
 * &pqData: priority_queue reference for reading and removing the first object of class Data in the queue.
 */
void Remove(std::priority_queue<Data, std::vector<Data>, std::less<std::vector<Data>::value_type>> &pqData){

    if(pqData.empty() == false){
        std::cout << pqData.top().getval() << " will be removed" << std::endl;
        pqData.pop();
    }
    else{
        std::cout << "Error: buffer is empty" << std::endl;
    }
}
