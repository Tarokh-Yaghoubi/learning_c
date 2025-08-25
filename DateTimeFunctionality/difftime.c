

#include "../requirements.h"


int main(void) {

	struct tm time_a = {

		.tm_year=82,	// years since 1900
		.tm_mon=3,
		.tm_mday=12,
		.tm_hour=4,
		.tm_min=00,
		.tm_sec=04,
		.tm_isdst=-1,
	};

	struct tm time_b = {

		.tm_year=120,	// years since 1900
		.tm_mon=10,
		.tm_mday=15,
		.tm_hour=16,
		.tm_min=27,
		.tm_sec=00,
		.tm_isdst=-1,
	};

	time_t cal_a = mktime(&time_a);
	time_t cal_b = mktime(&time_b);

	double diff = difftime(cal_b, cal_a);
	double years = diff / 60 / 60 / 24 / 365.2425;

	printf("%f seconds (%f years) between events\n", diff, years);
	return 0;

}
