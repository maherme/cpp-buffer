#include <string>
#include <queue>
#include <iostream>
#include <stdlib.h>
#include "functions.h"
#include "../Data/Data.h"

extern std::priority_queue<Data, std::vector<Data>, std::less<std::vector<Data>::value_type> > pqData;

static bool IsNumber(const std::string& str);

/* Function to capture and process the command value:priority.
 *
 * Parameters:
 * str: the string read as command.
 * i_data: class where value and priority are stored.
 *
 * Return: -1 if an error ocurred, 0 if completed OK.
 */
int CheckCommand(std::string str, Data& i_data){

    std::string value_s, priority_s;
    int value_i, priority_i = 0;
    size_t pos_colon;
    size_t str_len;
    static long count = 0;

    if((pos_colon = str.find_first_of(":")) == std::string::npos){
        std::cout << "Error in command format -> value:priority (integer:integer)" << std::endl;
        return -1;
    }
    else{
        value_s = str.substr(0, pos_colon);
        if(IsNumber(value_s)){
            try{
                value_i = stoi(value_s, nullptr, 10);
            }
            catch(const std::invalid_argument){
                std::cout << "Error in command format -> value:priority (integer:integer)" << std::endl;
                return -1;
            }
        }
        else{
            std::cout << "Error in command format -> value:priority (integer:integer)" << std::endl;
            return -1;
        }
        priority_s = str.substr(pos_colon+1, str.length());
        if(IsNumber(priority_s)){
            try{
                priority_i = stoi(priority_s, nullptr, 10);
            }
            catch(const std::invalid_argument){
                std::cout << "Error in command format -> value:priority (integer:integer)" << std::endl;
                return -1;
            }
        }
        else{
            std::cout << "Error in command format -> value:priority (integer:integer)" << std::endl;
            return -1;
        }

        i_data.value = value_i;
        i_data.priority = priority_i;
        i_data.number = count;
        count++;
    }

    return 0;
}

/* Function to print buffer to STDOUT.
 *
 */
void Print(void){

    static std::priority_queue<Data, std::vector<Data>, std::less<std::vector<Data>::value_type> > pqTemp;

    if(pqData.empty() != true){
        while(pqData.empty() != true){
            pqTemp.push(pqData.top());
            std::cout << pqData.top().value << std::endl;
            pqData.pop();
        }

        pqData = pqTemp;

        while(pqTemp.empty() != true){
            pqTemp.pop();
        }
    }
    else{
        std::cout << "Error: buffer is empty" << std::endl;
    }
}

/* Function to print the first element of the buffer to STDOUT.
 *
 */
void Get(void){

    if(pqData.empty() == false){
        std::cout << pqData.top().value << std::endl;
    }
    else{
        std::cout << "Error: buffer is empty" << std::endl;
    }
}

/* Function to remove the first element of the buffer.
 *
 */
void Remove(void){

    if(pqData.empty() == false){
        std::cout << pqData.top().value << " will be removed" << std::endl;
        pqData.pop();
    }
    else{
        std::cout << "Error: buffer is empty" << std::endl;
    }
}

static bool IsNumber(const std::string& str){

    return str.find_first_not_of("0123456789") == std::string::npos;
}
