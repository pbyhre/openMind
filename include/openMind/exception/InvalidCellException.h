#ifndef INVALIDCELLEXCEPTION_H
#define INVALIDCELLEXCEPTION_H

#pragma once

#include <openMind/exception/Exception.h> // Base class: Exception

namespace openMind
{

namespace exception
{

class InvalidCellException : public Exception
{
	public:
		InvalidCellException();
		InvalidCellException(unsigned int row, unsigned int col);
		~InvalidCellException();
		
		void setCell(unsigned int row, unsigned int col);
		unsigned int getRow() const;
		unsigned int getCol() const;

	private:
		unsigned int m_row;
		unsigned int m_col;
};

}

}

#endif // INVALIDCELLEXCEPTION_H
