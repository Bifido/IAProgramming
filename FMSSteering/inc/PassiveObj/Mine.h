
// ** Forward dec
class ViewComponent;
// ** END

class Mine{
	
	Mine(unsigned int MaxStoneNumber);
	~Mine();

	unsigned int GetActualStonesNumber() const;
	ViewComponent* GetViewComponent() const;
	unsigned int DecrementStonesNumber(unsigned int stoneToRemove);

	void SetViewComponent(ViewComponent*);

private:
	const unsigned int MAX_STONES_NUMBER;
	unsigned int numberOfStoneAvailable;
	
	ViewComponent* viewInfo;
};