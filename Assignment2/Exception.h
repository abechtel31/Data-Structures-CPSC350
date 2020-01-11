#ifndef EXCEPTION_H
#define EXCEPTION_H

#include <string>
using namespace std;

class Exception{
public:
    explicit Exception(const string& err);
    Exception(const Exception& Exception);
    virtual ~Exception();
    string getErr();

protected:
    string err;
};

#endif
