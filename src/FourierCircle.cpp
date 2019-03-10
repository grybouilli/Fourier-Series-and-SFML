#include "hdr/FourierCircle.hpp"

FourierCircle::FourierCircle()
: mChild(nullptr)
, mCurrentAngle(0.f)
, mChildren(0)
, mN(1)
{
}

FourierCircle::FourierCircle(float radius, int children, int n)
: mCircle(radius  * (4 / (n * 3.1456f)))
, mChild(new FourierCircle())
, mCurrentAngle(0.f)
, mChildren(children)
, mN(n)
{
	mCircle.setFillColor(sf::Color::Transparent);
	mCircle.setOutlineColor(sf::Color(255,255,255,150));
	mCircle.setOutlineThickness(3.f);
	mCircle.setOrigin(radius  * (4 / (n * 3.1456f)), radius  * (4 / (n * 3.1456f)));

	if(mChildren > 0)
	{
		mChild = new FourierCircle(radius, mChildren - 1, n + 2);
	} else
	{
		mChild = nullptr;
		mPoint = sf::CircleShape(5.f);
		mPoint.setFillColor(sf::Color::White);
		mPoint.setOrigin(5.f, 5.f);
	}
}

void FourierCircle::setRadius(float radius)
{
	mCircle.setRadius(radius);
	adjustChildLocation();
}
float FourierCircle::getRadius() const
{
	return mCircle.getRadius();
}

void FourierCircle::update(sf::Time dt)
{
	mCurrentAngle += dt.asSeconds();
	adjustChildLocation();
	if(mChildren > 0)
	{
		mChild->update(dt);
	} else
	{
		adjustPointLocation();
	}
}

sf::Vector2f FourierCircle::getFPointPosition() const
{
	sf::Vector2f position {};

	if(mChildren > 0)
	{
		sf::Transform transform = getTransform();
		position = transform.transformPoint(mChild->getFPointPosition());
	} else
	{
		sf::Transform transform = getTransform();
		return transform.transformPoint(mPoint.getPosition());
	}

}

void FourierCircle::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	states.transform *= getTransform();
	target.draw(mCircle, states); //comment this line if you want to visualize only the final point
	if(mChildren > 0)
	{
		mChild->draw(target,states);
	} else
	{
		target.draw(mPoint, states);
	}

}

void FourierCircle::adjustChildLocation()
{
	if(mChild == nullptr)
	{
		adjustPointLocation();
		return;
	}

	float circleRadius = mCircle.getRadius();
	float newX = circleRadius * std::cos(mN * mCurrentAngle);
	float newY = circleRadius * std::sin(mN * mCurrentAngle);
	mChild->setPosition(newX, newY);
	mChild->adjustChildLocation();
}

void FourierCircle::adjustPointLocation()
{
	float circleRadius = mCircle.getRadius();
	float newX = circleRadius * std::cos(mN * mCurrentAngle);
	float newY = circleRadius * std::sin(mN * mCurrentAngle);
	mPoint.setPosition(newX, newY);
}