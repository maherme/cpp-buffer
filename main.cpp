#include <map>
#include <string>
#include <queue>
#include <stdlib.h>
#include <iostream>

/* Define a custom data type to store value:priority */
class Data{
    public:
    int value;
    int priority;
    long number;
    Data():value(0), priority(0), number(0){}
    Data(int new_value, int new_priority, long new_number):value(new_value), priority(new_priority), number(new_number){}
};

/* Overload the < operator for storing values in priority
 * descending order (1 has n higher priority than 2).
 */
bool operator< (const Data &Data1, const Data &Data2){

    bool ret = false;

    if(Data1.priority == Data2.priority){
        ret = (Data1.number > Data2.number);
    }
    else{
        ret = (Data1.priority > Data2.priority);
    }

    return ret;
}

/* Overload the > operator for storing values in priority
 * ascending order (2 has n higher priority than 1).
 */
bool operator> (const Data &Data1, const Data &Data2){

    bool ret = false;
    if(Data1.priority == Data2.priority){
        ret = (Data1.number > Data2.number);
    }
    else{
        ret = (Data1.priority < Data2.priority);
    }

    return ret;
}

/* Value definitions of the different values */
enum CommandValues{
    c_not_defined,
    c_exit,
    c_print,
    c_get,
    c_remove
};

/* Map to associate the strings with the enum values */
static std::map<std::string, CommandValues>s_mapCommandValues;
/* Declare a priority_queue and specify the order as < */
/* The priorities will be assigned in the ascending order of priority */
static std::priority_queue<Data, std::vector<Data>, std::less<std::vector<Data>::value_type> > pqData;

static void InitCommands(void);
static int CheckCommand(std::string, Data&);
static void Print(void);
static void Get(void);
static void Remove(void);

int main(){

    bool loop_cond = true;
    std::string command;
    Data ins_data;

    InitCommands();

    while(loop_cond == true){

        std::cout << "Please, enter a command" << std::endl;
        std::cin >> command;

        switch(s_mapCommandValues[command]){
            case c_exit:
                exit(EXIT_SUCCESS);
                break;
            case c_print:
                Print();
                break;
            case c_get:
                Get();
                break;
            case c_remove:
                Remove();
                break;
            default:
                if(CheckCommand(command, ins_data) == 0){
                    pqData.push(ins_data);
                }
                break;
        }
    }

    return 0;
}

/* Function to initialize command values.
 *
 */
static void InitCommands(void){
    s_mapCommandValues["exit"] = c_exit;
    s_mapCommandValues["print"] = c_print;
    s_mapCommandValues["get"] = c_get;
    s_mapCommandValues["remove"] = c_remove;
}

/* Function to capture and process the command value:priority.
 *
 * Parameters:
 * str: the string read as command.
 * i_data: class where value and priority are stored.
 *
 * Return: -1 if an error ocurred, 0 if completed OK.
 */
static int CheckCommand(std::string str, Data& i_data){

    std::string value_s, priority_s;
    int value_i, priority_i = 0;
    size_t pos_colon;
    size_t str_len;
    static long count = 0;

    if((pos_colon = str.find_first_of(":")) == std::string::npos){
        std::cout << "Error in command format -> value:priority (integer:integer)" << std::endl;
    }
    else{
        value_s = str.substr(0, pos_colon);
        try{
            value_i = stoi(value_s, nullptr, 10);
        }
        catch(const std::invalid_argument){
        std::cout << "Error in command format -> value:priority (integer:integer)" << std::endl;
            return -1;
        }
        priority_s = str.substr(pos_colon+1, str.length());
        try{
            priority_i = stoi(priority_s, nullptr, 10);
        }
        catch(const std::invalid_argument){
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
static void Print(void){

    int i = 0;
    int data_size = 0;
    Data *data_array;

    data_size = pqData.size();

    if(data_size != 0){
        data_array = new Data[data_size];
        if(data_array == 0x0){
            std::cout << "Error: insufficient memory for execute print" << std::endl;
            return;
        }
        else{
            for(i = 0; i < data_size; i++){
                data_array[i] = pqData.top();
                pqData.pop();
                std::cout << data_array[i].value << std::endl;
            }
            for(i = 0; i < data_size; i++){
                pqData.push(data_array[i]);
            }
            delete [] data_array;
        }
    }
    else{
        std::cout << "Error: buffer is empty" << std::endl;
    }
}

/* Function to print the first element of the buffer to STDOUT.
 *
 */
static void Get(void){

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
static void Remove(void){

    if(pqData.empty() == false){
        std::cout << pqData.top().value << " will be removed" << std::endl;
        pqData.pop();
    }
    else{
        std::cout << "Error: buffer is empty" << std::endl;
    }
}
