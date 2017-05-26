#include "malloc.h"

pthread_mutex_t		*get_mutex(void)
{
	static pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

	return (&mutex);
}
