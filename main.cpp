#include <map>
#include <string>
#include <stdlib.h>
#include <iostream>
using namespace std;

/* Value definitions of the different values */
enum CommandValues{
    c_not_defined,
    c_exit,
    c_print,
    c_get,
    c_remove
};

/* Map to associate the strings with the enum values */
static map<string, CommandValues>s_mapCommandValues;

static void InitCommands(void);

int main(){

    bool loop_cond = true;
    string command;

    InitCommands();

    while(loop_cond == true){

        cout << "Please, enter a command\n";
        cin >> command;

        switch(s_mapCommandValues[command]){
            case c_exit:
		exit(EXIT_SUCCESS);
                break;
            case c_print:
                break;
            case c_get:
                break;
            case c_remove:
                break;
            default:
                break;
        }
    }

    return 0;
}

/* Function to initialize command values
 *
 */
static void InitCommands(void){
    s_mapCommandValues["exit"] = c_exit;
    s_mapCommandValues["print"] = c_print;
    s_mapCommandValues["get"] = c_get;
    s_mapCommandValues["remove"] = c_remove;
}
