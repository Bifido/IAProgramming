#include "SFML\System\Vector2.hpp"

// ** Forward dec
class ViewComponent;
// ** END

class Home{

public:
	Home(unsigned int staminaRecoveredEachFrame);
	~Home();

	unsigned int GetStaminaRecovered() const;
	const sf::Vector2<float>& GetPosition() const;

	void SetViewComponent(ViewComponent*);
	void SetPosition(const sf::Vector2<float>& newPos);

private:
	const unsigned int STAMINA_RECOVERED;

	sf::Vector2<float> pos;

	ViewComponent* viewInfo;
};