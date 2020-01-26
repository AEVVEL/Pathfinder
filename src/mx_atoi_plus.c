#include "path.h"

int mx_atoi_plus(char *str) {
	int result = 0;
	int i = -1;
	
	if (str == NULL)////
		return 2;///
	while(str[++i]) {
		if (mx_isdigit(str[i])) {
			result = result * 10 + str[i] - '0';
		}
		if (!mx_isdigit(str[i]))
			return -1;
	}
	return result;
}
