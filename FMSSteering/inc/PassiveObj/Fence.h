#include "SFML\System\Vector2.hpp"
#include "Constants.h"
// ** Forward dec
class ViewComponent;
// ** END

class Fence{

public:
	Fence(const sf::Vector2<float> pos, const sf::Vector2<float> fenceSize);
	~Fence(){};

	const sf::Vector2<float>& GetPosition() const;
	const sf::Vector2<float>& GetUpperLeftCornerPos() const;
	const sf::Vector2<float>& GetLowerRightCornerPos() const;

	const sf::Vector2<float> GetRandomPointInside() const;
	const sf::Vector2<float> GetRandomPointOutside() const;
	const sf::Vector2<float>& GetEscapingPoint() const;

	bool IsPointInside(const sf::Vector2<float>& position) const;

	void SetViewComponent(ViewComponent*);

private:
	/*	coord (0,0) is the upper left corner of the screen
	*	coord (1,1) is the lower right corner of the screen
	*	so if position is (x,y), the lowerRightCorner of the fence (position.x + fenceSize.x,position.y + fenceSize.y) */
	sf::Vector2<float> m_vPosition;  

	//it's (position.x + fenceSize.x,position.y + fenceSize.y);
	sf::Vector2<float> m_vLowerRightCorner;
	sf::Vector2<float> m_vEscapingPoint;

	ViewComponent* m_oViewInfo;
};