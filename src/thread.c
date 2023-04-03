#include "../includes/Philosophers.h"

void	*thread_routine(void *data)
{
	pthread_t tid;

	// La fonction pthread_self() renvoie
	// l'identifiant propre à ce thread.
	tid = pthread_self();
	printf("%sThread [%ld]: Le plus grand ennui c'est d'exister sans vivre.%s\n",
		YELLOW, tid, NC);
	return (NULL); // Le thread termine ici.
}

void jsp()
{
		pthread_t	tid1;	// Identifiant du premier thread
	pthread_t	tid2;	// Identifiant du second thread

	// Création du premier thread qui va directement aller
	// exécuter sa fonction thread_routine.
	pthread_create(&tid1, NULL, thread_routine, NULL);
	printf("Main: Creation du premier thread [%lu]\n", tid1);
	// Création du second thread qui va aussi exécuter thread_routine.
	pthread_create(&tid2, NULL, thread_routine, NULL);
	printf("Main: Creation du second thread [%lu]\n", tid2);
	// Le main thread attend que le nouveau thread
	// se termine avec pthread_join.
	pthread_join(tid1, NULL);
	printf("Main: Union du premier thread [%lu]\n", tid1);
	pthread_join(tid2, NULL);
	printf("Main: Union du second thread [%lu]\n", tid2);

}