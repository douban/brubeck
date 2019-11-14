#include "sput.h"
#include "brubeck.h"
#include "stdio.h"

static void check_eq(double f, const char *str)
{
	char buf[32];
	brubeck_ftoa(buf, f);
	printf("==== output for %f is %s", f, buf);
	sput_fail_unless(strcmp(str, buf) == 0, str);
}

void test_ftoa(void)
{
	check_eq(0.0, "0");
	check_eq(0.00001234, "0");
	check_eq(0.001234, "0.0012");
	check_eq(1234.0, "1234");
	check_eq(1234.5, "1234.5");
	check_eq(1234.567, "1234.567");
	check_eq(123456789123.0, "123456789123");
	check_eq(0.31415926, "0.3141");
	check_eq(3.1415926, "3.1415");
	check_eq(314159265358.979323846, "314159265358.9793");
	check_eq(999.999, "999.999");
	check_eq(0.9999, "0.9999");
	check_eq(999999999999999999.99999, "1000000000000000000");
}
