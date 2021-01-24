#include <map>
#include <string>
#include <queue>
#include <stdlib.h>
#include <iostream>
//using namespace std;

/* Define a custom data type to store value:priority */
class Data{
    public:
    int value;
    int priority;
    Data():value(0), priority(0){}
    Data(int new_value, int new_priority):value(new_value), priority(new_priority){}
};

/* Overload the < operator */
bool operator< (const Data &Data1, const Data &Data2){return Data1.priority > Data2.priority;}
/* Overload the > operator */
bool operator> (const Data &Data1, const Data &Data2){return Data1.priority < Data2.priority;}
/* Overload the == operator */
bool operator== (const Data &Data1, const Data &Data2){return Data1.priority == Data2.priority;}

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

static void InitCommands(void);
static int CheckCommand(std::string, Data&);

int main(){

    bool loop_cond = true;
    std::string command;
    /* Declare a priority_queue and specify the order as < */
    /* The priorities will be assigned in the ascending order of priority */
    std::priority_queue<Data, std::vector<Data>, std::less<std::vector<Data>::value_type> > pqData;
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
                break;
            case c_get:
                if(pqData.empty() == false){
                    std::cout << pqData.top().value << std::endl;
                }
                else{
                    std::cout << "Error: buffer is empty" << std::endl;
                }
                break;
            case c_remove:
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
    }

    i_data.value = value_i;
    i_data.priority = priority_i;

    return 0;
}
