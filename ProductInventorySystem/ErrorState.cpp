#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <string>
#include <cstring>
#include "ErrorState.h"

using namespace std;
using namespace AMA;

namespace AMA {
  
    ErrorState::ErrorState(const char * error){
        if (error == nullptr) {
            errorMessage =nullptr;
        }else{
            message(error);
        }
        
        
    }
    
    ErrorState::~ErrorState(){
        delete [] errorMessage;
        errorMessage = nullptr;
    }
    
    void ErrorState::clear(){
        delete [] errorMessage;
        errorMessage = nullptr;
    }
    
    bool ErrorState::isClear() const{
        return (errorMessage== nullptr);
    }
    
    void ErrorState::message(const char * str){
        delete [] errorMessage;
        errorMessage = new char [strlen(str) + 1];
        strncpy(errorMessage, str, strlen(str));
        errorMessage[strlen(str) ] = '\0';
        
    }
    
    const char * ErrorState::message() const{
        return errorMessage;
    }
    
    
    
    std::ostream& operator<<(std::ostream& ostr, const ErrorState& obj){
        if (!obj.isClear()) {
            ostr << obj.message();
        }
        
        
        return ostr;
    }
}

