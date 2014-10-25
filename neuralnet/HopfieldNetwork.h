#ifndef HOPFIELDNETWORK_H
#define HOPFIELDNETWORK_H

#include <vector>
#include <openMind/math/Matrix.h>


namespace openMind
{

namespace neuralnet
{

class HopfieldNetwork
{
	public:
		HopfieldNetwork();
		HopfieldNetwork(unsigned int size);
		~HopfieldNetwork();
		
		unsigned int getSize() const;
		void setSize(unsigned int size);
		
		std::vector<bool> present(const std::vector<bool>& values);
		
		void train(const std::vector<bool>& pattern);
		
		private:
			unsigned int			m_size;
			openMind::math::Matrix	m_weights;
};

}

}

#endif // HOPFIELDNETWORK_H
