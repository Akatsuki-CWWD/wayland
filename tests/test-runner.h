#ifndef _TEST_RUNNER_H_
#define _TEST_RUNNER_H_

struct test {
	const char *name;
	void (*run)(void);
};

#define TEST(name)						\
	static void name(void);					\
								\
	const struct test test##name			\
		 __attribute__ ((section ("test_section"))) = {	\
		#name, name					\
	};							\
								\
	static void name(void)

#endif
