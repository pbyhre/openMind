#include <openMind/exception/InvalidCellException.h>

namespace openMind
{

namespace exception
{

const std::string INVALID_CELL_EXCEPTION = "exception.invalid.cell";

InvalidCellException::InvalidCellException()
:Exception(INVALID_CELL_EXCEPTION)
{
	setCell(0, 0);
}

InvalidCellException::InvalidCellException(unsigned int row, unsigned int col)
:Exception(INVALID_CELL_EXCEPTION)
{
	setCell(row, col);
}

InvalidCellException::~InvalidCellException()
{
}

void InvalidCellException::setCell(unsigned int row, unsigned int col)
{
	m_row = row;
	m_col = col;
	
	std::vector<std::string> args;
	args.push_back(std::to_string(row));
	args.push_back(std::to_string(col));
	setArgs(args);
}

unsigned int InvalidCellException::getRow() const
{
	return m_row;
}

unsigned int InvalidCellException::getCol() const
{
	return m_col;
}


}

}

