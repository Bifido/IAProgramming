#include "SFML\System\Vector2.hpp"

// ** Forward dec
class ViewComponent;
// ** END

class Mine{
	
public:
	Mine(unsigned int MaxStoneNumber);
	~Mine();

	unsigned int GetActualStonesNumber() const;
	ViewComponent* GetViewComponent() const;
	const sf::Vector2<float>& GetPosition() const;

	unsigned int DecrementStonesNumber(unsigned int stoneToRemove);

	void SetViewComponent(ViewComponent*);
	void SetPosition(const sf::Vector2<float>& newPos);

private:
	const unsigned int MAX_STONES_NUMBER;
	unsigned int numberOfStoneAvailable;
	
	sf::Vector2<float> pos;

	ViewComponent* viewInfo;
};