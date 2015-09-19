#pragma once
#include "State.h"
#include "GlobalArc.h"
#include "FSMCore.h"
#include <vector>
#include <algorithm>
#include <iostream>
#include "Agent.h"
using namespace std;
/**
	State must implement 
		OnEnter();
		OnExit();
		Update();
		CheckTransition();
*/
template <typename Agent>
class FiniteStateMachine
{
public:
	FiniteStateMachine(Agent& agent);
	~FiniteStateMachine();

	void Run(float dt);
	void AddFSM(FSMCore<Agent>* sharedStates);
	void RemoveFSM();

private:
	void ChangeState(int currentFSM, FSMStates newState);

	std::vector< FSMCore<Agent>* > m_sharedStates;
	std::vector< State<Agent>* >  m_actualState;
	Agent& m_agent;
};



// ***********************************************************************************************************
// ******************************************* IMPLEMENTATIONS ***********************************************
// ***********************************************************************************************************

template<typename Agent>
FiniteStateMachine<Agent>::FiniteStateMachine(Agent& agent)
	: m_agent(agent)
{
};

template<typename Agent>
FiniteStateMachine<Agent>::~FiniteStateMachine() { };

template<typename Agent>
void FiniteStateMachine<Agent>::AddFSM(FSMCore<Agent>* sharedStates)
{
	m_sharedStates.push_back(sharedStates);
	m_actualState.push_back(sharedStates->GetDefaultState());
};

template<typename Agent>
void FiniteStateMachine<Agent>::RemoveFSM()
{
	//Pop back because all the FSM pushed in the vector are popped in inverse order
	//LIFO
	m_sharedStates.pop_back();
	m_actualState.pop_back();
};

template<typename Agent>
void FiniteStateMachine<Agent>::Run(float dt){
	for (unsigned int i = 0; i < m_actualState.size(); ++i){
		if (m_actualState[i] != nullptr){

			// Check if the FSM changes state 
			// if no globalArc => the state remain the same!
			FSMStates newState = (m_sharedStates[i]->GetGlobalArc() != nullptr) ? m_sharedStates[i]->GetGlobalArc()->CheckTransition(m_agent) : m_sharedStates[i]->GetNotValidState();
			
			ChangeState(i, newState);

			// Check if the FSM changes state
			newState = m_actualState[i]->CheckTransition(m_agent);

			// If new state is changed, changing state!
			ChangeState(i, newState);

			// Update acual state
			m_actualState[i]->Update(m_agent, dt);
		}
	}
}

template<typename Agent>
void FiniteStateMachine<Agent>::ChangeState(int currentFSM, FSMStates newState)
{
	if (m_sharedStates[currentFSM]->IsStateValid(newState) && m_sharedStates[currentFSM]->GetState(newState) != m_actualState[currentFSM]){
		std::cout << "FSM "<< currentFSM << ": Agent: " << m_agent.GetName() << " Exit from " << m_actualState[currentFSM]->GetStateName() << std::endl;
		m_actualState[currentFSM]->OnExit(m_agent);
		m_actualState[currentFSM] = m_sharedStates[currentFSM]->GetState(newState);
		std::cout << "FSM " << currentFSM << ": Agent: " << m_agent.GetName() << " Enter in: " << m_actualState[currentFSM]->GetStateName() << std::endl << std::endl;
		m_actualState[currentFSM]->OnEnter(m_agent);
	}
}