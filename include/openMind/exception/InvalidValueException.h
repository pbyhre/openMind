#ifndef INVALIDVALUEEXCEPTION_H
#define INVALIDVALUEEXCEPTION_H

#pragma once

#include <openMind/exception/Exception.h> // Base class: Exception

namespace openMind
{

namespace exception
{

template<class T>
class InvalidValueException : public Exception
{
	public:
		InvalidValueException()
		{
		}
		
		InvalidValueException(const T& value)
		{
			setValue(value);
		}
		
		~InvalidValueException()
		{
		}
		
		void setValue(const T& value)
		{
			m_value = value;
		}
		
		T getValue() const
		{
			return m_value;
		}


	private:
		T m_value;
		
};

}

}

#endif // INVALIDVALUEEXCEPTION_H
