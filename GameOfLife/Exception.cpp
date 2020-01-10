#include "Exception.h"
using namespace std;
Exception::Exception(const string& err): err(err)
{
}

Exception::Exception(const Exception& exception): err(exception.err)
{
}

Exception::~Exception()
= default;

string Exception::getErr()
{
    return err;
}
