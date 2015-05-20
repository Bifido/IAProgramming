Cosa ho fatto:

Aggiunto a State e GlabalArc una ref alla FSMCore in modo che ogni stato abbia gli altri stati dove cambiare
Messo qualche const qua e la

PROBLEMA
FiniteStateMachine
- ogni stato ha bisogno del puntatore all'agent (che sarebbe meglio come ref) ma la FSM non ce l'ha
	Soluzioni:
		Gli viene passato ad ogni ciclo nel Run (blea)
		Se lo salva come FSMCore<NanoAgent> e lo passa agli stati ad ogni ciclo
			(FSMCore<NanoAgent> ora non serve più visto che ogni stato ha la sua
			ma per renderlo utile potremmo passarlo al CheckTransition e toglierlo dagli stati e GlobalArc
			ma adesso x me è troppo tardi per questo reverse e quindi lo lascio a te.. =/
			P.S. nel primo commit ci sono cose giuste,
			nel scondo ci sono le cose su cui potresti fare reverse (ma se lo fai dopo devi sistemare qualche const e nome))


