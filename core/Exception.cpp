#include <openMind/core.h>
#include <openMind/exception/Exception.h>

namespace openMind
{

namespace exception
{

Exception::Exception()
{
	m_nested_exception = NULL;
}

Exception::Exception(const std::string& code)
{
	m_nested_exception = NULL;
	m_code = code;
}

Exception::Exception(const std::string& code, const std::vector<std::string>& args)
{
	m_nested_exception = NULL;
	m_code = code;
	m_args = args;
}

Exception::Exception(const std::string& code, const Exception& ex)
{
	setNestedException(ex);
	m_code = code;
}

Exception::Exception(const std::string& code, const std::vector<std::string>& args, const Exception& ex)
{
	setNestedException(ex);
	m_code = code;
	m_args = args;
}
		
Exception::~Exception()
{
	if (NULL != m_nested_exception)
	{
		delete m_nested_exception;
		m_nested_exception = NULL;
	}
}
		
Exception& Exception::operator = (const Exception& ex)
{
	if (this != &ex)
	{
		m_code = ex.m_code;
		m_args = ex.m_args;
		if (NULL != m_nested_exception)
		{
			delete m_nested_exception;
			m_nested_exception = NULL;
		}
		if (NULL != ex.m_nested_exception)
		{
			setNestedException(*ex.m_nested_exception);
		}
	}
	return *this;
}
		
void Exception::setCode(const std::string& code)
{
	m_code = code;
}
		
void Exception::setArgs(const std::vector<std::string>& args)
{
	m_args = args;
}

void Exception::setNestedException(const Exception& nested)
{
	if (NULL != m_nested_exception)
	{
		delete m_nested_exception;
		m_nested_exception = NULL;
	}
	
	m_nested_exception = new Exception();	
}
		
const std::string& Exception::getCode() const
{
	return m_code;
}

const std::vector<std::string>& Exception::getArgs() const
{
	return m_args;
}

Exception* Exception::getNestedException() const
{
	return m_nested_exception;
}



}

}
