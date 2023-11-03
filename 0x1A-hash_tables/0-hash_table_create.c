#include "hash_tables.h"

/**
 * hash_table_create - Creates a hash table
 * @size: Unsigned long int size of array
 * Return: A pointer to the newly created hash table, or NULL on failure
 */

hash_table_t *hash_table_create(unsigned long int size)
{
	hash_table_t *ht;
	unsigned long int i;

	/* Allocate memory for hash table */
	ht = malloc(sizeof(hash_table_t));

	if (ht == NULL)
		return (NULL);

	ht->size = size;
	/* Allocate memory for array */
	ht->array = malloc(sizeof(hash_node_t *) * size);

	if (ht->array == NULL)
	{
		/* Free hash table if array allocation fails */
		free(ht);
		return (NULL);
	}

	for (i = 0; i < size; i++)
		/* Initialize array elements to NULL */
		ht->array[i] = NULL;

	return (ht);
}
