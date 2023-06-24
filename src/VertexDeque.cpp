#include "hdr/VertexDeque.hpp"

VertexDeque::VertexDeque()
: mDeque {}
{

}

VertexDeque::VertexDeque(size_t amount)
: mDeque {amount}
{

}

VertexDeque::~VertexDeque()
{
}

size_t VertexDeque::size() const
{
	return mDeque.size();
}

void VertexDeque::push(const sf::Vertex& v)
{
	mDeque.push_back(v);
}

sf::Vertex& VertexDeque::pop()
{
	if(size()==0)
	{
		throw std::logic_error("Could not pop from VertexDeque : Deque is empty.");
	}
	return *mDeque.erase(mDeque.begin());
}

sf::Vertex& VertexDeque::operator[](size_t index)
{
	if(index < 0 || index >= size())
	{
		throw std::logic_error("Could access element : out of bound index.");
	}
	return mDeque[index];
}

const sf::Vertex& VertexDeque::operator[](size_t index) const
{
	if(index < 0 || index >= size())
	{
		throw std::logic_error("Could access element : out of bound index.");
	}
	return mDeque[index];
}