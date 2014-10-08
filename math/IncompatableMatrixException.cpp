#include <openMind/exception/IncompatableMatrixException.h>

namespace openMind
{

namespace exception
{

const std::string INCOMPATABLE_MATRIX_EXCEPTION = "exception.incompatable.matrix";

IncompatableMatrixException::IncompatableMatrixException()
:Exception(INCOMPATABLE_MATRIX_EXCEPTION)
{
}

IncompatableMatrixException::~IncompatableMatrixException()
{
}


}

}

