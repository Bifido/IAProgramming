#include <list>

// Forward decl
class Stato;

class NanoAgent
{
	std::list<Stato*> states;
	// NOTA: potrebbe mantere anche info sullo stato attuale

public:
	
	Stato* NextState(Stato* currentState);

	NanoAgent();
	~NanoAgent();
};

