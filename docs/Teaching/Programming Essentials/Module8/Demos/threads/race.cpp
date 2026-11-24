#include <stdio.h>
#include <threads.h>

#define ITERATIONS 1000000
int inc_counter = 0;
int dec_counter = ITERATIONS;
mtx_t inc_lock;
mtx_t dec_lock;

int increment(void *t_id) {
	char id = *(char*)t_id;
	int i = 0;
    for (; i < ITERATIONS; ++i)
	{
		mtx_lock(&inc_lock);
        inc_counter++; // DATA RACE: undefined behavior!
		printf("Thread %c, Counter: %d\n", id, i);
		mtx_unlock(&inc_lock);
	}
    return 0;
}

int decrement(void *t_id) {
	char id = *(char*)t_id;
	int i = 0;
    for (; i < ITERATIONS; ++i)
	{
		mtx_lock(&dec_lock);
        dec_counter--;// DATA RACE: undefined behavior!
		printf("Thread %c, Counter: %d\n", id, i);
		mtx_unlock(&dec_lock);
	}
    return 0;
}

int main(void) {
    thrd_t a, b, c, d;
	char t_id_a = 'a';
	char t_id_b = 'b';
	char t_id_c = 'c';
	char t_id_d = 'd';
	mtx_init(&inc_lock, mtx_plain);
	mtx_init(&dec_lock, mtx_plain);
	printf("Trying to start t1");
    if (thrd_create(&a, increment, &t_id_a) != thrd_success)
        return 1;
	printf("Trying to start t2");
    if (thrd_create(&b, decrement, &t_id_b) != thrd_success) {
        thrd_join(a, NULL);
        return 1;
    }
	thrd_create(&c, increment, &t_id_c);
	thrd_create(&d, decrement, &t_id_d);

    thrd_join(a, NULL);
    thrd_join(b, NULL);
    thrd_join(c, NULL);
    thrd_join(d, NULL);

	mtx_destroy(&inc_lock);	
	mtx_destroy(&dec_lock);	
    printf("Expected: %d; actual: %d\n", 2 * ITERATIONS, inc_counter);
    printf("Expected: %d; actual: %d\n", 2 * ITERATIONS, dec_counter);
}
