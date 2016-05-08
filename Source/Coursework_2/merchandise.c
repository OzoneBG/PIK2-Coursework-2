#include "merchandise.h"

void read_all_merchandise(Vector* vec)
{
	FILE* db = fopen("database.bin", "r");

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

		printf("Read %d records..\n\n", count);

		fclose(db);
	}
	else
	{
		printf("Unable to open file!");
	}
}
