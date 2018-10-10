#ifndef AMA_ERRORSTATE_H
#define AMA_ERRORSTATE_H

#include <iostream>

using namespace std;

namespace AMA {
    
    class ErrorState {
        char *errorMessage;
    public:
        
        explicit ErrorState(const char* error = nullptr);
     
        ErrorState(const ErrorState& em) = delete;
        ErrorState& operator=(const ErrorState& em) = delete;
        virtual ~ErrorState();
        void clear();
        bool isClear() const;
        void message(const char* str);
        const char* message()const;
        
        /*	std::ostream & write(std::ostream & ostr);*/
        
        
    };
    
    
    std::ostream& operator << (std::ostream& ostr, const ErrorState&);
}
#endif
