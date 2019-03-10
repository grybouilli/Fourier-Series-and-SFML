#ifndef GUARD_FOURIERCIRCLE_HPP
#define GUARD_FOURIERCIRCLE_HPP

class FourierCircle : public sf::Drawable, public sf::Transformable
{
public:
	FourierCircle();
	FourierCircle(float radius, int children, int n = 1);

	void setRadius(float radius);
	float getRadius() const;

	void update(sf::Time dt);

	sf::Vector2f getFPointPosition() const;

private:
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

	void adjustChildLocation();
	void adjustPointLocation();

private:
	sf::CircleShape mCircle, mPoint;
	FourierCircle*  mChild;
	float			mCurrentAngle;
	int				mChildren;
	int				mN;
};

#endif