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
	const sf::Vector2<float>& GetLowerLeftCornerPos() const;
	const sf::Vector2<float>& GetUpperRightCornerPos() const;

	const sf::Vector2<float> GetRandomPointInside() const;
	const sf::Vector2<float> GetRandomPointOutside() const;

	bool IsPointInside(const sf::Vector2<float>& position) const;

	void SetViewComponent(ViewComponent*);

private:
	sf::Vector2<float> m_vPosition;
	sf::Vector2<float> m_vLowerLeftCorner;
	sf::Vector2<float> m_vUpperRightCorner;

	ViewComponent* m_oViewInfo;
};