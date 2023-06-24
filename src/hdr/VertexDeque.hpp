#pragma once

#include <SFML/Graphics/Vertex.hpp>
#include <vector>

class VertexDeque
{
public:
	VertexDeque();
	VertexDeque(size_t);

	~VertexDeque();

	size_t 		size() const;

	void		push(const sf::Vertex&);
	sf::Vertex& pop();

	sf::Vertex&			operator[](size_t);
	const sf::Vertex&	operator[](size_t) const;

private:
	std::vector<sf::Vertex> mDeque;
};