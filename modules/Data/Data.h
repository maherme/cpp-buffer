#ifndef DATA_H
#define DATA_H

/* Define a custom data type to store value:priority */
class Data{
    int value;
    int priority;
    long number;
    public:
    Data();
    Data(int new_value, int new_priority, long new_number);
    int getval (void) const;
    void setval (int new_value, int new_priority, long new_number);

    friend bool operator< (const Data &Data1, const Data &Data2){
        bool ret = false;
        if(Data1.priority == Data2.priority){
            ret = (Data1.number > Data2.number);
        }
        else{
            ret = (Data1.priority > Data2.priority);
        }
        return ret;
    }
    friend bool operator> (const Data &Data1, const Data &Data2){
        bool ret = false;
        if(Data1.priority == Data2.priority){
            ret = (Data1.number > Data2.number);
        }
        else{
            ret = (Data1.priority < Data2.priority);
        }
        return ret;
    }
};

#endif
