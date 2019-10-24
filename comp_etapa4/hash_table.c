// Victor de Almeida Piccoli Ferreira
// Lucas Cardoso Tavares

/*
    Hash Table code based on the teacher Johann class
*/

#include "hash_table.h"

void hashInit(void)
{
	int i;
	for (i = 0; i < HASH_SIZE; ++i)
		Table[i] = NULL;
}

int hashAddress(char *text)
{
	int address = 1;
	int i;

	for (i = 0; i < strlen(text); ++i)
		address = (address * text[i] % HASH_SIZE + 1);

	return address - 1;
}

HASH_NODE *hashFind(char *text)
{
	int address = hashAddress(text);
	HASH_NODE *node;

	node = Table[address];

	while (node != NULL)
	{
		if (strcmp(node->text, text) != 0)
			node = node->next;
		else
			return node;
	}

	return NULL;
}

HASH_NODE *hashInsert(char *text, int type)
{

	HASH_NODE *newnode;
	if (newnode = hashFind(text))
		return newnode;
	int address = hashAddress(text);
	newnode = (HASH_NODE *)calloc(1, sizeof(HASH_NODE));
	newnode->type = 1;
	newnode->text = (char *)calloc(strlen(text) + 1, sizeof(char));
	strcpy(newnode->text, text);
	newnode->type = type;
	newnode->next = Table[address];
	Table[address] = newnode;

	return newnode;
}

void hashPrint(void)
{
	int i;
	HASH_NODE *node = 0;

	for (i = 0; i < HASH_SIZE; i++)
	{
		for (node = Table[i]; node; node = node->next)
		{
			printf("Table[%d] = %s\n", i, node->text);
		}
	}
}

void hashCheckUndeclared()
{
	return;
}