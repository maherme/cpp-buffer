#include "Data.h"

/* Default constructor */
Data::Data(){
    value = 0;
    priority = 0;
    number = 0;
}

/* Overload constructor */
Data::Data(int new_value, int new_priority, long new_number){
    value = new_value;
    priority = new_priority;
    number = new_number;
}
