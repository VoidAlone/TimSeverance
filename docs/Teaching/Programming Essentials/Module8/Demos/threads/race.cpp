#include <stdio.h>
#include <threads.h>

#define ITERATIONS 1000000
int counter = 0;
mtx_t lock;

int increment(void *t_id) {
	char id = *(char*)t_id;
	int i = 0;
    for (; i < ITERATIONS; ++i)
		mtx_lock(&lock);
        counter++; // DATA RACE: undefined behavior!
		printf("Thread %c, Counter: %d\n", id, i);
		mtx_unlock(&lock);
    return 0;
}

int main(void) {
    thrd_t a, b;
	mtx_init(&lock, mtx_plain);
    if (thrd_create(&a, increment, 'a') != thrd_success)
        return 1;
    if (thrd_create(&b, increment, 'b') != thrd_success) {
        thrd_join(a, NULL);
        return 1;
    }

    thrd_join(a, NULL);
    thrd_join(b, NULL);
	
	mtx_destroy(&lock);	
    printf("Expected: %d; actual: %d\n", 2 * ITERATIONS, counter);

}
