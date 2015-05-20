
// ** Forward dec
class ViewComponent;
// ** END

class Home{

	Home(unsigned int staminaRecoveredEachFrame);
	~Home();

	unsigned int GetStaminaRecovered() const;

	void SetViewComponent(ViewComponent*);

private:
	const unsigned int STAMINA_RECOVERED;

	ViewComponent* viewInfo;
};