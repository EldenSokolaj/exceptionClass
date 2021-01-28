#ifndef EXCEPTION_CLASS_H
#define EXCEPTION_CLASS_H

#include <iostream>
#include <cstring>
using namespace std;

/*
 & Types
 & 0 --> successful with exception
 & 1 --> error
 & 2 --> warning
*/

class except{
    public:
        string msg;
        char type;
        time_t when;
        string where;
        
        except(string text, string opname, char t = 1){
            where = opname;
            when = time(NULL);
            msg = text;
            type = t;
        }
        
        string str(){
            string t;
            if(type == 1){
                t = "error";
            } else if(type == 2){
                t = "warning";
            } else if(type == 0){
                t = "success";
            } else {
                t = "unknown";
            }
            char* w = ctime(&when);
            w[strlen(w) - 1] = '\0';
            return string(w) + " [" + t + "] [" + where + "]: " + msg;
        }
        
        operator string(){
            return this->str();
        }
        
        friend ostream & operator << (ostream &out, except &e);
};

ostream& operator<<(ostream& os, except& e){
    os << e.str();
    return os;
}

#endif
