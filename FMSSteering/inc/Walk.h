#include "State.h"
#include "NanoAgent.h"

class Walk: public State<NanoAgent>
{
public:
	Walk();
	~Walk();

	void OnEnter(NanoAgent*);
	void OnExit(NanoAgent*);
	void Update(NanoAgent*);
};

