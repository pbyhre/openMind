#ifndef EXCEPTION_H
#define EXCEPTION_H

#include <string>
#include <vector>


#pragma once

namespace openMind
{

namespace exception
{

class Exception
{
	public:
		Exception();
		Exception(const std::string& code);
		Exception(const std::string& code, const std::vector<std::string>& args);
		Exception(const std::string& code, const Exception& ex);
		Exception(const std::string& code, const std::vector<std::string>& args, const Exception& ex);
		
		~Exception();
		
		Exception& operator = (const Exception& m);
		
		void setCode(const std::string& message);
		void setArgs(const std::vector<std::string>& args);
		void setNestedException(const Exception& nested);
		
		const std::string& getCode() const;
		const std::vector<std::string>& getArgs() const;
		Exception* getNestedException() const;

	private:
		Exception*					m_nested_exception;
		std::vector<std::string>	m_args;
		std::string					m_code;
};

}

}

#endif // MATRIX_H
