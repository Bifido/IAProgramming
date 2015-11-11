#include "Steering\SteeringFactory.h"
#include "Steering\Seek.h"
#include "Steering\Evade.h"
#include "Steering\Arrive.h"

Steering* SteeringFactory::BuildSteering(SteeringType _steeringType)
{
	switch (_steeringType)
	{
	case Seek:
		return new ::Seek("SeekTarget");
		break;

	case Evade:
		return new ::Evade("EvadeTarget");
		break;

	case Arrive:
		return new ::Arrive("ArriveTarget");
		break;

	default:
		break;
	}
}

void SteeringFactory::ReleaseSteering(Steering*& _steeringToRelease)
{
	if (_steeringToRelease != nullptr)
	{
		delete _steeringToRelease;
	}
	_steeringToRelease = nullptr;
}