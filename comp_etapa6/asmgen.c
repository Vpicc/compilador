#include <stdio.h>
#include <ctype.h>
#include "asmgen.h"

#define MAX_VECTOR_PRINT_SIZE 100
#define MAX_VECTOR_PARAM_LIST 17

int firstVar = 0;

void generateAsm(TAC *tac)
{

	//Guarda o tac inicial
	TAC *initialTac = tac;
	TAC *ifTac = tac;

	FILE *fp;
	fp = fopen("asm.s", "w+");
	if (fp == NULL)
	{
		printf("Erro ao criar arquivo asm.s\n");
		exit(1);
	}
	else
	{
		printf("Arquivo asm.s com sucesso.\n");
	}
	int count = 0;
	int count2 = 0;
	int count3 = 0;
	int paramCont = 0;
	int paramContPush = 0;
	int insideFunction = 0;
	int countLabel = 0;
	int isCalled = 0;
	int startVectorDeclaretion = 0;
	int firstArrDeclared = 0;
	long sizeArrDecalred = 0;
	int doneContCond = 0;
	int numberOfCod = 0;
	int insideCond = 0;
	int firstCond = 0;
	int actualCond = 0;
	char vectorVariables[500] = {0};
	int countLabelAndLeite = 0;

	long datatypeVector = 0;
	char *paramVectorList[MAX_VECTOR_PARAM_LIST];

	//variável inicial para controle do vetor que armazena na posição vectorIndex, uma string "xxx", correspondente aquele index em assembly.
	//Exemplo, LC0 - > aaa , então a[0] = "aaa"
	int vectorIndex = 0;
	int vectorGlobalIndex = 0;
	char *vectorPrint[MAX_VECTOR_PRINT_SIZE];
	char *vectorGlobalAssing[MAX_VECTOR_PRINT_SIZE];
	int alreadyPrintedAssing = 0;

	fprintf(fp, "# START\n"
				"\t.file \"assembly.c\"\n"
				"\t.text\n"
				"\t.data\n");

	//Enquanto tiver tacnext
	while (tac)
	{
		switch (tac->type)
		{
		case TAC_PRINT:
		{
			sizeArrDecalred = 0;
			if ((tac->res) && (tac->res->text[0] == '"'))
			{
				fprintf(fp, "\n_LC%d:\n		.string	%s\n", vectorIndex, tac->res->text);
				vectorPrint[vectorIndex] = tac->res->text;
				vectorIndex++;
			}
		}
		break;
		case TAC_VARDEC:
		{
			sizeArrDecalred = 0;
			if (tac->res->datatype == DATATYPE_INT)
				fprintf(fp, "\n\t.globl	_%s\n"
							"\t.data\n"
							"\t.type	_%s, @object\n"
							"\t.size	_%s, %ld\n"
							"_%s:\t.long\t%s\n",
						tac->res->text, tac->res->text, tac->res->text, sizeof(int), tac->res->text, tac->op1->text);
			if (tac->res->datatype == DATATYPE_FLOAT)
				fprintf(fp, "\n\t.globl	_%s\n"
							"\t.data\n"
							"\t.type	_%s, @object\n"
							"\t.size	_%s, %ld\n"
							"_%s:\t.long\t%s\n",
						tac->res->text, tac->res->text, tac->res->text, sizeof(float), tac->res->text, tac->op1->text);
			if (tac->res->datatype == DATATYPE_LONG)
				fprintf(fp, "\n\t.globl	_%s\n"
							"\t.data\n"
							"\t.type	_%s, @object\n"
							"\t.size	_%s, %ld\n"
							"_%s:\t.long\t%s\n",
						tac->res->text, tac->res->text, tac->res->text, sizeof(long), tac->res->text, tac->op1->text);
			if (tac->res->datatype == DATATYPE_CHAR)
				fprintf(fp, "\n\t.globl	_%s\n"
							"\t.data\n"
							"\t.type	_%s, @object\n"
							"\t.size	_%s, %ld\n"
							"_%s:\t.long\t%s\n",
						tac->res->text, tac->res->text, tac->res->text, sizeof(char), tac->res->text, tac->op1->text);
			if (tac->res->datatype == DATATYPE_BYTE)
				fprintf(fp, "\n\t.globl	_%s\n"
							"\t.data\n"
							"\t.type	_%s, @object\n"
							"\t.size	_%s, %d\n"
							"_%s:\t.long\t%s\n",
						tac->res->text, tac->res->text, tac->res->text, 1, tac->res->text, tac->op1->text);
			if (tac->res->datatype == DATATYPE_BOOL)
				fprintf(fp, "\n\t.globl	_%s\n"
							"\t.data\n"
							"\t.type	_%s, @object\n"
							"\t.size	_%s, %d\n"
							"_%s:\t.long\t%s\n",
						tac->res->text, tac->res->text, tac->res->text, 1, tac->res->text, tac->op1->text);

			break;
		}
		case TAC_ARRDEC:
			//fprintf(stderr, "\nTAC_ARRDEC: OP1->text: %s\n OP2->text: %s\n RESULT->text: %s\n",tac->op1->text ,tac->op1->text, tac->res->text);
			if (tac->res->datatype == DATATYPE_INT)
			{
				fprintf(fp, "\n_%s:\n"
							"\t.size	_%s, %ld\n"
							"\t.globl	_%s",
						tac->res->text, tac->res->text, atoi(tac->op1->text) * sizeof(int), tac->res->text);
			}
			if (tac->res->datatype == DATATYPE_FLOAT)
			{
				fprintf(fp, "\n_%s:\n"
							"\t.size	_%s, %ld\n"
							"\t.globl	_%s",
						tac->res->text, tac->res->text, atoi(tac->op1->text) * sizeof(float), tac->res->text);
			}
			if (tac->res->datatype == DATATYPE_LONG)
			{
				fprintf(fp, "\n_%s:\n"
							"\t.size	_%s, %ld\n"
							"\t.globl	_%s",
						tac->res->text, tac->res->text, atoi(tac->op1->text) * sizeof(long), tac->res->text);
			}
			if (tac->res->datatype == DATATYPE_CHAR)
			{
				fprintf(fp, "\n_%s:\n"
							"\t.size	_%s, %ld\n"
							"\t.globl	_%s",
						tac->res->text, tac->res->text, atoi(tac->op1->text) * sizeof(char), tac->res->text);
			}
			if (tac->res->datatype == DATATYPE_BYTE)
			{
				fprintf(fp, "\n_%s:\n"
							"\t.size	_%s, %d\n"
							"\t.globl	_%s",
						tac->res->text, tac->res->text, atoi(tac->op1->text) * 1, tac->res->text);
			}
			if (tac->res->datatype == DATATYPE_BOOL)
			{
				fprintf(fp, "\n_%s:\n"
							"\t.size	_%s, %d\n"
							"\t.globl	_%s",
						tac->res->text, tac->res->text, atoi(tac->op1->text) * 1, tac->res->text);
			}
			break;
		case TAC_ARRDEC_LIST:
			fprintf(fp, "\n\t.long %s", tac->res->text);
		}
		tac = tac->next;
	}
	hashPrintAsm(fp);
	fprintf(fp, "\n# STRING\n"
				".meuString:\n"
				"\t.string \"%%d\\n\" \n"
				"\t.text\n\n"
				"\t.section	.rodata\n");

	while (initialTac)
	{
		switch (initialTac->type)
		{
		case TAC_BEGINFUN:
		{
			//fprintf(stderr, "\n\nEntrei");
			if (initialTac->res)
			{
				fprintf(fp, "# BEGIN FUN\n"
							"\t.globl	%s\n"
							"\t.type	%s, @function\n"
							"%s:\n"
							"\t.cfi_startproc\n"
							"\tpushq	%%rbp\n"
							"\tmovq	%%rsp, %%rbp\n\n",
						initialTac->res->text, initialTac->res->text, initialTac->res->text);
				insideFunction = 1;
			}
		}
		break;

		case TAC_ENDFUN:
			fprintf(fp, "# END FUN\n"
						"\tpopq	%%rbp\n"
						"\tret\n"
						"\t.cfi_endproc\n\n");
			insideFunction = 0;
			break;

		case TAC_PRINT:
		{
			if (initialTac->res)
			{
				//Precisamos saber se é string ou variável. Para saber se é string, olharemos para o primeiro caractere, que deve ser ", senao é variável.
				char *auxPrint = initialTac->res->text;
				if (auxPrint[0] == '"')
				{
					int aux = 0;
					int index = 0;
					for (aux; aux < MAX_VECTOR_PRINT_SIZE; aux++)
					{
						if (vectorPrint[aux] == initialTac->res->text)
						{
							index = aux;
						}
					}
					// fprintf(fp, "# PRINT\n"
					// 			"\tmovq	stderr(%%rip), %%rax\n"
					// 			"\tmovq	%%rax, %%rcx\n"
					// 			"\tmovl	$4, %%edx\n"
					// 			"\tmovl	$1, %%esi\n"
					// 			"\tleaq	_LC%d(%%rip), %%rdi\n"
					// 			"\tcall	fwrite@PLT\n\n",
					// 		index);
					fprintf(fp, "# PRINT\n"
								"\tleaq	_LC%d(%%rip), %%rdi\n"
								"\tmovl	$0, %%eax\n"
								"\tcall	printf@PLT\n\n",
							index);
				}
			}
			break;
		}
		case TAC_ADD:
			fprintf(fp, "# ADD\n");
			//PRIMEIRO OPERANDO
			//Verifica se é caracter ou numero
			if (isalpha(*initialTac->op1->text))
			{
				fprintf(fp, "\tmovl	_%s(%%rip), %%edx\n", initialTac->op1->text);
			}
			else
			{
				fprintf(fp, "\tmovl	$%s, %%edx\n", initialTac->op1->text);
			}
			//SEGUNDO OPERANDO
			//Verifica se é caracter ou numero
			if (isalpha(*initialTac->op2->text))
			{
				fprintf(fp, "\tmovl	_%s(%%rip), %%eax\n", initialTac->op2->text);
			}
			else
			{
				fprintf(fp, "\tmovl	$%s, %%eax\n", initialTac->op2->text);
			}
			fprintf(fp,
					"\taddl	%%edx, %%eax\n"
					"\tmovl	%%eax, _%s(%%rip)\n\n",
					initialTac->res->text);
			break;
		case TAC_SUB:
			fprintf(fp, "# SUB\n");
			//PRIMEIRO OPERANDO
			//Verifica se é caracter ou numero
			if (isalpha(*initialTac->op1->text))
			{
				fprintf(fp, "\tmovl	_%s(%%rip), %%edx\n", initialTac->op1->text);
			}
			else
			{
				fprintf(fp, "\tmovl	$%s, %%edx\n", initialTac->op1->text);
			}
			//SEGUNDO OPERANDO
			//Verifica se é caracter ou numero
			if (isalpha(*initialTac->op2->text))
			{
				fprintf(fp, "\tmovl	_%s(%%rip), %%eax\n", initialTac->op2->text);
			}
			else
			{
				fprintf(fp, "\tmovl	$%s, %%eax\n", initialTac->op2->text);
			}
			fprintf(fp,
					"\tsubl	%%eax, %%edx\n"
					"\tmovl	%%edx, _%s(%%rip)\n\n",
					initialTac->res->text);
			break;
		case TAC_MULT:
			fprintf(fp, "# MULT\n");
			//PRIMEIRO OPERANDO
			//Verifica se é caracter ou numero
			if (isalpha(*initialTac->op1->text))
			{
				fprintf(fp, "\tmovl	_%s(%%rip), %%edx\n", initialTac->op1->text);
			}
			else
			{
				fprintf(fp, "\tmovl	$%s, %%edx\n", initialTac->op1->text);
			}
			//SEGUNDO OPERANDO
			//Verifica se é caracter ou numero
			if (isalpha(*initialTac->op2->text))
			{
				fprintf(fp, "\tmovl	_%s(%%rip), %%eax\n", initialTac->op2->text);
			}
			else
			{
				fprintf(fp, "\tmovl	$%s, %%eax\n", initialTac->op2->text);
			}
			fprintf(fp,
					"\timull %%edx, %%eax\n"
					"\tmovl	%%eax, _%s(%%rip)\n\n",
					initialTac->res->text);
			break;
		//TODO: FIX TAC DIV, esta dando floating point exception
		case TAC_DIV:
			fprintf(fp, "# DIV\n");
			//PRIMEIRO OPERANDO
			//Verifica se é caracter ou numero
			if (isalpha(*initialTac->op1->text))
			{
				fprintf(fp, "\tmovl	_%s(%%rip), %%edx\n", initialTac->op1->text);
			}
			else
			{
				fprintf(fp, "\tmovl	$%s, %%edx\n", initialTac->op1->text);
			}
			//SEGUNDO OPERANDO
			//Verifica se é caracter ou numero
			if (isalpha(*initialTac->op2->text))
			{
				fprintf(fp, "\tmovl	_%s(%%rip), %%eax\n", initialTac->op2->text);
			}
			else
			{
				fprintf(fp, "\tmovl	$%s, %%ecx\n", initialTac->op2->text);
			}
			fprintf(fp,
					"\tcltd\n"
					"\tidivl %%ecx\n"
					"\tmovl	%%eax, _%s(%%rip)\n\n",
					initialTac->res->text);
			break;
		case TAC_MOVE:
			if (isalpha(*initialTac->op1->text))
			{
				fprintf(fp, "\tmovl	_%s(%%rip), %%eax\n", initialTac->op1->text);
			}
			else
			{
				fprintf(fp, "\tmovl	$%s, %%eax\n", initialTac->op1->text);
			}
			fprintf(fp, "\tmovl	%%eax, _%s(%%rip)\n\n", initialTac->res->text);
			break;
		case TAC_LESS:
		{
			fprintf(stderr, "\nEQ--\n");
			actualCond++;
			ifTac = initialTac;
			if (insideCond == 0)
			{
				insideCond++;
				numberOfCod++;
			}
			ifTac = ifTac->next;
			while (ifTac->type != TAC_IFZ)
			{
				if (insideCond && (doneContCond == 0) && (ifTac->type == TAC_EQ || ifTac->type == TAC_LE || ifTac->type == TAC_GE || ifTac->type == TAC_LESS || ifTac->type == TAC_GREATER))
					numberOfCod++;
				ifTac = ifTac->next;
			};
			doneContCond = 1;
			fprintf(stderr, "\t->%d<-", numberOfCod);
			char *savedOp1 = initialTac->op1->text;
			char *savedOp2 = initialTac->op2->text;
			char *savedResult = initialTac->res->text;
			if (insideFunction)
			{
				if (initialTac->res)
				{
					if (digitoPrimeiro(initialTac))
					{
						fprintf(fp, "\tmovl	$%s, %%edx\n", savedOp1);
					}
					else
					{
						fprintf(fp, "\tmovl	_%s(%%rip), %%edx\n", savedOp1);
					}

					if (digitoSegundo(initialTac))
					{
						fprintf(fp, "\tmovl	$%s, %%eax\n", savedOp2);
					}
					else
					{
						fprintf(fp, "\tmovl	_%s(%%rip), %%eax\n", savedOp2);
					}
					fprintf(fp, "\tcmpl	%%eax,%%edx\n");
					// fprintf(fp,"\tmovl %%edx, %s(%%rip)\n",savedResult);
					fprintf(fp, "\tjl	labelTemp2%d\n", numberOfCod - 1);
					//fprintf(fp,"\tmovl	$1, _%s(%%rip)\n",savedResult);
					if (actualCond == numberOfCod)
					{
						fprintf(fp, "\tjmp	%s\n", ifTac->res->text);
						fprintf(fp, "labelTemp2%d:\n", countLabelAndLeite);
					}
					countLabelAndLeite++;
				}
			}
		}
		break;
			break;
		case TAC_GREATER:
		{
			fprintf(stderr, "\nEQ--\n");
			actualCond++;
			ifTac = initialTac;
			if (insideCond == 0)
			{
				insideCond++;
				numberOfCod++;
			}
			ifTac = ifTac->next;
			while (ifTac->type != TAC_IFZ)
			{
				if (insideCond && (doneContCond == 0) && (ifTac->type == TAC_EQ || ifTac->type == TAC_LE || ifTac->type == TAC_GE || ifTac->type == TAC_LESS || ifTac->type == TAC_GREATER))
					numberOfCod++;
				ifTac = ifTac->next;
			};
			doneContCond = 1;
			fprintf(stderr, "\t->%d<-", numberOfCod);
			char *savedOp1 = initialTac->op1->text;
			char *savedOp2 = initialTac->op2->text;
			char *savedResult = initialTac->res->text;
			if (insideFunction)
			{
				if (initialTac->res)
				{
					if (digitoPrimeiro(initialTac))
					{
						fprintf(fp, "\tmovl	$%s, %%edx\n", savedOp1);
					}
					else
					{
						fprintf(fp, "\tmovl	_%s(%%rip), %%edx\n", savedOp1);
					}

					if (digitoSegundo(initialTac))
					{
						fprintf(fp, "\tmovl	$%s, %%eax\n", savedOp2);
					}
					else
					{
						fprintf(fp, "\tmovl	_%s(%%rip), %%eax\n", savedOp2);
					}
					fprintf(fp, "\tcmpl	%%eax,%%edx\n");
					// fprintf(fp,"\tmovl %%edx, %s(%%rip)\n",savedResult);
					fprintf(fp, "\tjg	labelTemp2%d\n", numberOfCod - 1);
					//fprintf(fp,"\tmovl	$1, _%s(%%rip)\n",savedResult);
					if (actualCond == numberOfCod)
					{
						fprintf(fp, "\tjmp	%s\n", ifTac->res->text);
						fprintf(fp, "labelTemp2%d:\n", countLabelAndLeite);
					}
					countLabelAndLeite++;
				}
			}
		}
		break;
		case TAC_LE:
		{
			fprintf(stderr, "\nEQ--\n");
			actualCond++;
			ifTac = initialTac;
			if (insideCond == 0)
			{
				insideCond++;
				numberOfCod++;
			}
			ifTac = ifTac->next;
			while (ifTac->type != TAC_IFZ)
			{
				if (insideCond && (doneContCond == 0) && (ifTac->type == TAC_EQ || ifTac->type == TAC_LE || ifTac->type == TAC_GE || ifTac->type == TAC_LESS || ifTac->type == TAC_GREATER))
					numberOfCod++;
				ifTac = ifTac->next;
			};
			doneContCond = 1;
			fprintf(stderr, "\t->%d<-", numberOfCod);
			char *savedOp1 = initialTac->op1->text;
			char *savedOp2 = initialTac->op2->text;
			char *savedResult = initialTac->res->text;
			if (insideFunction)
			{
				if (initialTac->res)
				{
					if (digitoPrimeiro(initialTac))
					{
						fprintf(fp, "\tmovl	$%s, %%edx\n", savedOp1);
					}
					else
					{
						fprintf(fp, "\tmovl	_%s(%%rip), %%edx\n", savedOp1);
					}

					if (digitoSegundo(initialTac))
					{
						fprintf(fp, "\tmovl	$%s, %%eax\n", savedOp2);
					}
					else
					{
						fprintf(fp, "\tmovl	_%s(%%rip), %%eax\n", savedOp2);
					}
					fprintf(fp, "\tcmpl	%%eax,%%edx\n");
					// fprintf(fp,"\tmovl %%edx, %s(%%rip)\n",savedResult);
					fprintf(fp, "\tjle	labelTemp2%d\n", numberOfCod - 1);
					//fprintf(fp,"\tmovl	$1, _%s(%%rip)\n",savedResult);
					if (actualCond == numberOfCod)
					{
						fprintf(fp, "\tjmp	%s\n", ifTac->res->text);
						fprintf(fp, "labelTemp2%d:\n", countLabelAndLeite);
					}
					countLabelAndLeite++;
				}
			}
		}
		break;
		case TAC_GE:
		{
			fprintf(stderr, "\nEQ--\n");
			actualCond++;
			ifTac = initialTac;
			if (insideCond == 0)
			{
				insideCond++;
				numberOfCod++;
			}
			ifTac = ifTac->next;
			while (ifTac->type != TAC_IFZ)
			{
				if (insideCond && (doneContCond == 0) && (ifTac->type == TAC_EQ || ifTac->type == TAC_LE || ifTac->type == TAC_GE || ifTac->type == TAC_LESS || ifTac->type == TAC_GREATER))
					numberOfCod++;
				ifTac = ifTac->next;
			};
			doneContCond = 1;
			fprintf(stderr, "\t->%d<-", numberOfCod);
			char *savedOp1 = initialTac->op1->text;
			char *savedOp2 = initialTac->op2->text;
			char *savedResult = initialTac->res->text;
			if (insideFunction)
			{
				if (initialTac->res)
				{
					if (digitoPrimeiro(initialTac))
					{
						fprintf(fp, "\tmovl	$%s, %%edx\n", savedOp1);
					}
					else
					{
						fprintf(fp, "\tmovl	_%s(%%rip), %%edx\n", savedOp1);
					}

					if (digitoSegundo(initialTac))
					{
						fprintf(fp, "\tmovl	$%s, %%eax\n", savedOp2);
					}
					else
					{
						fprintf(fp, "\tmovl	_%s(%%rip), %%eax\n", savedOp2);
					}
					fprintf(fp, "\tcmpl	%%eax,%%edx\n");
					// fprintf(fp,"\tmovl %%edx, %s(%%rip)\n",savedResult);
					fprintf(fp, "\tjge	labelTemp2%d\n", numberOfCod - 1);
					//fprintf(fp,"\tmovl	$1, _%s(%%rip)\n",savedResult);
					if (actualCond == numberOfCod)
					{
						fprintf(fp, "\tjmp	%s\n", ifTac->res->text);
						fprintf(fp, "labelTemp2%d:\n", countLabelAndLeite);
					}
					countLabelAndLeite++;
				}
			}
		}
		break;
		case TAC_EQ:
		{
			fprintf(stderr, "\nEQ--\n");
			actualCond++;
			ifTac = initialTac;
			if (insideCond == 0)
			{
				insideCond++;
				numberOfCod++;
			}
			ifTac = ifTac->next;
			while (ifTac->type != TAC_IFZ)
			{
				if (insideCond && (doneContCond == 0) && (ifTac->type == TAC_EQ || ifTac->type == TAC_LE || ifTac->type == TAC_GE || ifTac->type == TAC_LESS || ifTac->type == TAC_GREATER))
					numberOfCod++;
				ifTac = ifTac->next;
			};
			doneContCond = 1;
			fprintf(stderr, "\t->%d<-", numberOfCod);
			char *savedOp1 = initialTac->op1->text;
			char *savedOp2 = initialTac->op2->text;
			char *savedResult = initialTac->res->text;
			if (insideFunction)
			{
				if (initialTac->res)
				{
					if (digitoPrimeiro(initialTac))
					{
						fprintf(fp, "\tmovl	$%s, %%edx\n", savedOp1);
					}
					else
					{
						fprintf(fp, "\tmovl	_%s(%%rip), %%edx\n", savedOp1);
					}

					if (digitoSegundo(initialTac))
					{
						fprintf(fp, "\tmovl	$%s, %%eax\n", savedOp2);
					}
					else
					{
						fprintf(fp, "\tmovl	_%s(%%rip), %%eax\n", savedOp2);
					}
					fprintf(fp, "\tcmpl	%%eax,%%edx\n");
					// fprintf(fp,"\tmovl %%edx, %s(%%rip)\n",savedResult);
					fprintf(fp, "\tjz	labelTemp2%d\n", numberOfCod - 1);
					//fprintf(fp,"\tmovl	$1, _%s(%%rip)\n",savedResult);
					if (actualCond == numberOfCod)
					{
						fprintf(fp, "\tjmp	%s\n", ifTac->res->text);
						//fprintf(fp,"labelTemp1%d:\n",countLabelAndLeite);
						//fprintf(fp,"\tmovl	$0, _%s(%%rip)\n",savedResult);
						fprintf(fp, "labelTemp2%d:\n", countLabelAndLeite);
					}
					countLabelAndLeite++;
				}
			}
		}
		break;
		case TAC_DIFF:
			//fprintf(stderr, "OP1->text: %s\n OP2->text: %s\n RESULT->text: %s\n",initialTac->op1->text ,initialTac->op2->text, initialTac->res->text);
			fprintf(fp, "\n# DIFF\n");

			//PRIMEIRO OPERANDO
			//Verifica se é caracter ou numero
			if (isalpha(*initialTac->op1->text))
			{
				fprintf(fp, "\tmovl	_%s(%%rip), %%eax\n", initialTac->op1->text);
			}
			else
			{
				fprintf(fp, "\tmovl	$%s, %%eax\n", initialTac->op1->text);
			}

			//SEGUNDO OPERANDO
			//Verifica se é caracter ou numero
			if (isalpha(*initialTac->op2->text))
			{
				fprintf(fp, "\tcmpl	_%s(%%rip), %%eax\n"
							"\tje",
						initialTac->op2->text);
			}
			else
			{
				fprintf(fp, "\tcmpl	$%s, %%eax\n"
							"\tje",
						initialTac->op2->text);
			}
			break;
		case TAC_IFZ:
			//firstCond = 0;
			//actualCond = 0;
			//numberOfCod = 0;
			doneContCond = 0;
			insideCond = 0;
			//					fprintf(fp,"# IFZ\n""%s\n\n",initialTac->res->text);
			//fprintf(fp,"\t%s\n\n",initialTac->res->text);
			break;
		case TAC_LABEL:
			if (insideFunction)
			{
				//fprintf(stderr,"\n\n****ENTREI QUANTAS\n");
				//fprintf(fp,"# LABEL\n");
				fprintf(fp, "\n%s:\n",
						//"\tmovl	$0, %%eax\n",
						initialTac->res->text);
			}
			break;
		case TAC_JUMP:
			if (insideFunction)
			{
				//fprinft(fp, "\n# JUMP\n");
				fprintf(fp, "\tjmp\t%s\n\n", initialTac->res->text);
			}
			break;
		case TAC_VECTORASS:
			//fprintf(stderr, "VECTORASS\nOP1: %s\n OP2: %s\n RES: %s\n", initialTac->op1->text, initialTac->op2->text, initialTac->res->text);
			if (initialTac->res->datatype == DATATYPE_INT)
				datatypeVector = sizeof(int);
			if (initialTac->res->datatype == DATATYPE_FLOAT)
				datatypeVector = sizeof(float);
			if (initialTac->res->datatype == DATATYPE_LONG)
				datatypeVector = sizeof(long);
			if (initialTac->res->datatype == DATATYPE_BOOL)
				datatypeVector = 1;
			if (initialTac->res->datatype == DATATYPE_BYTE)
				datatypeVector = 1;
			if (initialTac->res->datatype == DATATYPE_CHAR)
				datatypeVector = 1;

			if (!isalpha(*initialTac->op2->text))
			{
				fprintf(fp, "\n# VECTOR ASS\n");
				if (isalpha(*initialTac->op1->text))
				{
					fprintf(fp, "\tmovb	_%s, %ld+_%s(%%rip)\n", initialTac->op2->text, datatypeVector * atoi(initialTac->op1->text), initialTac->res->text);
				}
				else
				{
					fprintf(fp, "\tmovb	$%s, %ld+_%s(%%rip)\n", initialTac->op2->text, datatypeVector * atoi(initialTac->op1->text), initialTac->res->text);
				}
			}
			break;

		case TAC_VEC_READ:
			//fprintf(stderr, "DATATYPE: %d\n", initialTac->op2->datatype);
			if (initialTac->op2->datatype == DATATYPE_INT)
			{
				datatypeVector = sizeof(int);
			}
			if (initialTac->op2->datatype == DATATYPE_FLOAT)
				datatypeVector = sizeof(float);
			if (initialTac->op2->datatype == DATATYPE_LONG)
				datatypeVector = sizeof(long);
			if (initialTac->op2->datatype == DATATYPE_BOOL)
				datatypeVector = 1;
			if (initialTac->op2->datatype == DATATYPE_BYTE)
				datatypeVector = 1;
			if (initialTac->op2->datatype == DATATYPE_CHAR)
				datatypeVector = 1;

			//fprintf(stderr, "OP1: %s\n OP2: %s\n RES: %s\n", initialTac->op1->text, initialTac->op2->text, initialTac->res->text);
			if (isalpha(*initialTac->op2->text))
			{
				fprintf(fp, "\n# VEC READ\n\tmovl	%ld+_%s(%%rip), %%eax\n"
							"\tmovl %%eax,  $%s(%%rip)\n",
						datatypeVector * atoi(initialTac->op2->text), initialTac->op1->text, initialTac->res->text);
			}
			else
			{
				fprintf(fp, "\n# VEC READ\n\tmovl	%ld+_%s(%%rip), %%eax\n"
							"\tmovl %%eax,  _%s(%%rip)\n",
						datatypeVector * atoi(initialTac->op2->text), initialTac->op1->text, initialTac->res->text);
			}
			break;
		}
		initialTac = initialTac->next;
	}

	fprintf(fp, "# FIXED\n"
				"\t.size	main, .-main\n"
				"\t.ident	\"GCC: (Ubuntu 7.4.0-1ubuntu1~18.04.1) 7.4.0\"\n"
				"\t.section	.note.GNU-stack,\"\",@progbits\n");
}

int digitoSegundo(TAC *tac)
{
	int i = 0;
	while (*tac->op2->text)
	{
		if (isdigit(*tac->op2->text++) == 0)
		{
			//restore one position
			*tac->op2->text--;
			return 0;
		}
		i++;
	}
	for (i; i > 0; i--)
	{
		*tac->op2->text--;
	}
	return 1;
}

int digitoPrimeiro(TAC *tac)
{
	int i = 0;
	while (*tac->op1->text)
	{
		if (isdigit(*tac->op1->text++) == 0)
		{
			//restore one position
			*tac->op1->text--;
			return 0;
		}
		i++;
	}
	//Restore the pointer.
	for (i; i > 0; i--)
	{
		*tac->op1->text--;
	}
	//printf("i is equalt to:%d\n",i);
	return 1;
}

int digitoResult(TAC *tac)
{
	int i = 0;
	while (*tac->res->text)
	{
		if (isdigit(*tac->res->text++) == 0)
		{
			//restore one position
			*tac->res->text--;
			return 0;
		}
		i++;
	}
	//Restore the pointer.
	for (i; i > 0; i--)
	{
		*tac->res->text--;
	}
	//printf("i is equalt to:%d\n",i);
	return 1;
}
