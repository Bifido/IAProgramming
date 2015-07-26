#include "SFML\System\Vector2.hpp"
#include "Constants.h"
// ** Forward dec
class ViewComponent;
// ** END

class Fence{

public:
	Fence();
	~Fence();

	const sf::Vector2<float>& GetPosition() const;
	const sf::Vector2<float>& GetLowerLeftCornerPos() const;
	const sf::Vector2<float>& GetUpperRightCornerPos() const;

	void SetViewComponent(ViewComponent*);

private:
	sf::Vector2<float> m_vLowerLeftCorner = MagicNumber::POS_BACKGROUND_FENCE - MagicNumber::FENCE_HALF_SIZE;
	sf::Vector2<float> m_vUpperRightCorner = MagicNumber::POS_BACKGROUND_FENCE + MagicNumber::FENCE_HALF_SIZE;

	ViewComponent* m_oViewInfo;
};