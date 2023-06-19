/**
 * This code outputs a sequence of document page numbers for physical printing in a specific layout
 * with 4 pages per sheet. (I can't remember what the layout looks like.)
 */

#include <stdio.h>

#define PAGES 144

int main(int argc, char **argv) {
	int last = (PAGES & 7) ? (PAGES | 7) + 1 : PAGES;
	register int page;
	for (int i = 0; i << 3 < PAGES; i++) {
		page = (i << 2) + 1;
		if (page <= PAGES)
			printf("%d", page);
		printf(",");
		++page;
		if (page <= PAGES)
			printf("%d", page);
		printf(",");
		page = last - (i << 2) - 1;
		if (page <= PAGES)
			printf("%d", page);
		printf(",");
		++page;
		if (page <= PAGES)
			printf("%d", page);
		if (i+1 << 3 < PAGES)
			printf(",");
	}
	printf("\n");
	for (int i = 0; i << 3 < PAGES; i++) {
		page = (i << 2) + 3;
		if (page <= PAGES)
			printf("%d", page);
		printf(",");
		++page;
		if (page <= PAGES)
			printf("%d", page);
		printf(",");
		page = last - (i << 2) - 3;
		if (page <= PAGES)
			printf("%d", page);
		printf(",");
		++page;
		if (page <= PAGES)
			printf("%d", page);
		if (i+1 << 3 < PAGES)
			printf(",");
	}
	printf("\n");
	return 0;
}
