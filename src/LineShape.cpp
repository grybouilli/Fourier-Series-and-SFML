#include "hdr/LineShape.hpp"
#include <iostream>

LineShape::LineShape()
: mVertices {}
{}

LineShape::LineShape(size_t verticesCount)
: mVertices(verticesCount)
{}

void LineShape::push(sf::Vector2f pos, sf::Color color)
{
	sf::Vertex vertex(pos, color);
	mVertices.push_back(vertex);
}

void LineShape::push(sf::Vertex vertex)
{
	mVertices.push_back(vertex);
}

void LineShape::pop()
{
	mVertices.erase(mVertices.begin());
}

void LineShape::update(sf::Time dt)
{
	if(mVertices.size() < 2)
		return;


	for(auto i = mVertices.size()-1; i != 0; --i)
	{
		mVertices[i].position.x = mVertices[i-1].position.x;
	}

	mVertices[0].position.x += dt.asSeconds() * 100.f;

	if(mVertices.size() > 10000)
	{
		pop();
	}
}

void LineShape::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	states.transform *= getTransform();

	target.draw(&mVertices[0], mVertices.size(), sf::LineStrip, states);
}