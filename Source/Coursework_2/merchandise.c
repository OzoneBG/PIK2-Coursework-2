#include "merchandise.h"

void read_all_merchandise(FILE * db, Vector* vec)
{
	if (db != NULL)
	{
		struct Merchandise current;
		int count = 0;
		
		while(1)
		{
			fread(&current, sizeof(struct Merchandise), 1, db);
			if (feof(db))
			{
				break;
			}
			else
			{
				vector_append(vec, &current);
				count++;
			}
		}

		printf("Read %d records..\n", count);
	}
}
