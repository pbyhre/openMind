#include <openMind/exception/InvalidParameterException.h>

namespace openMind
{

namespace exception
{

const std::string INVALID_PARAMETER_EXCEPTION = "exception.invalid.parameter";
	
InvalidParameterException::InvalidParameterException()
:Exception(INVALID_PARAMETER_EXCEPTION)
{
}

InvalidParameterException::InvalidParameterException(const std::string& func, const std::string& parm, const std::string& msg_code)
:Exception(msg_code)
{
	setFunctionName(func);
	setParameterName(parm);
}

InvalidParameterException::InvalidParameterException(const std::string& func, const std::string& parm, const std::string& msg_code, const std::vector<std::string>& args)
:Exception(msg_code, args)
{
	setFunctionName(func);
	setParameterName(parm);
}		

InvalidParameterException::~InvalidParameterException()
{
}


void InvalidParameterException::setFunctionName(const std::string& func)
{
	m_function_name = func;
}

std::string InvalidParameterException::getFunctionName()
{
	return m_function_name;
}

void InvalidParameterException::setParameterName(const std::string& parm)
{
	m_parameter_name = parm;
}

std::string InvalidParameterException::getParameterName()
{
	return m_parameter_name;
}

}

}

