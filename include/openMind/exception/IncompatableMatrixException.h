#ifndef INCOMPATABLEMATRIXEXCEPTION_H
#define INCOMPATABLEMATRIXEXCEPTION_H

#include <openMind/exception/Exception.h> // Base class: Exception

namespace openMind
{

namespace exception
{

class IncompatableMatrixException : public Exception
{
public:
	IncompatableMatrixException();
	~IncompatableMatrixException();

};

}

}

#endif // INCOMPATABLEMATRIXEXCEPTION_H
