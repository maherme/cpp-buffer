#include <map>
#include <string>
#include <queue>
#include <stdlib.h>
#include <iostream>
#include "config.h"
#include "modules/functions/functions.h"
#include "modules/Data/Data.h"

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

int main(){

    /* Declare a priority_queue and specify the order as < */
    /* The priorities will be assigned in the ascending order of priority */
    std::priority_queue<Data, std::vector<Data>, std::less<std::vector<Data>::value_type>> pqData;

    bool loop_cond = true;
    std::string command;

    std::cout << "Priority Buffer" << std::endl;
    std::cout << "Version: " << VERSION_MAJOR << "." << VERSION_MINOR << std::endl;

    InitCommands();

    while(loop_cond == true){

        std::cout << "Please, enter a command" << std::endl;
        std::cin >> command;

        switch(s_mapCommandValues[command]){
            case c_exit:
                exit(EXIT_SUCCESS);
                break;
            case c_print:
                Print(pqData);
                break;
            case c_get:
                Get(pqData);
                break;
            case c_remove:
                Remove(pqData);
                break;
            default:
                CheckCommand(command, pqData);
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
