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
		if (strcmp(node->text, text))
			node = node->next;
		else
		{
			return node;
		}
	}

	return NULL;
}

HASH_NODE *hashInsert(char *text, int type)
{

	HASH_NODE *newnode;
	int address = hashAddress(text);

	if (newnode = hashFind(text))
		return newnode;

	newnode = (HASH_NODE *)calloc(1, sizeof(HASH_NODE));
	newnode->type = type;
	newnode->text = (char *)calloc(strlen(text) + 1, sizeof(char));
	strcpy(newnode->text, text);

	switch (type)
	{
	case SYMBOL_LIT_INT:
		newnode->datatype = DATATYPE_INT;
		break;
	case SYMBOL_LIT_FLOAT:
		newnode->datatype = DATATYPE_FLOAT;
		break;
	case SYMBOL_LIT_CHAR:
		newnode->datatype = DATATYPE_BYTE;
		break;
	case SYMBOL_LIT_STRING:
		newnode->datatype = DATATYPE_STRING;
		break;
	}

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

int hashCheckUndeclared()
{
	int i;
	int errors = 0;
	HASH_NODE *node;

	for (i = 0; i < HASH_SIZE; ++i)
		for (node = Table[i]; node; node = node->next)
			if (node->type == SYMBOL_TK_IDENTIFIER)
			{
				fprintf(stderr, "SemanticError: Undeclared identifier %s\n", node->text);
				++errors;
			}
	return errors;
}