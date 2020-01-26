#include "path.h"

int mx_check_originality(char *island1, t_head *head, int len1) {
	int j = 0;

	while (j < head->now_isld) {
		if (!mx_strncmp(island1, head->island[j].name, len1))
			if (len1 == mx_strlen(head->island[j].name))
				return j;
		j++;
	}
	return -1;
}
