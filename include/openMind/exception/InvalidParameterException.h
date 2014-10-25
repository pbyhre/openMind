#ifndef INVALIDPARAMETEREXCEPTION_H
#define INVALIDPARAMETEREXCEPTION_H

#include <openMind/exception/Exception.h>
#include <string>
#include <vector>

namespace openMind
{

namespace exception
{

class InvalidParameterException : public Exception
{
	public:
		InvalidParameterException();
		InvalidParameterException(const std::string& func, const std::string& parm, const std::string& msg_code);
		InvalidParameterException(const std::string& func, const std::string& parm, const std::string& msg_code, const std::vector<std::string>& args);
		
		~InvalidParameterException();
	
		void setFunctionName(const std::string& func);
		std::string getFunctionName();
		
		void setParameterName(const std::string& parm);
		std::string getParameterName();
		
	private:
		std::string		m_function_name;
		std::string		m_parameter_name;

};

}

}

#endif // INVALIDPARAMETEREXCEPTION_H
