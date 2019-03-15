#ifndef GUARD_LINESHAPE_HPP
#define GUARD_LINESHAPE_HPP

#include <SFML/Graphics.hpp>
#include "hdr/VertexDeque.hpp"

class LineShape : public sf::Drawable, public sf::Transformable
{
public:
	LineShape();
	LineShape(size_t verticesCount);

	void push(sf::Vector2f pos, sf::Color color = sf::Color::White);
	void push(sf::Vertex vertex);

	void pop();

	void update(sf::Time dt);

private:
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

private:
	VertexDeque	mVertices;
};
#endif