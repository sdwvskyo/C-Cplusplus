/*--------------------------------------------------------------
 *  * Filename: expr.c
 *   * by@current 491072874@qq.com
 *    * Last modified: 2014/09/11 04:13
 *     * Description: process expression via expression tree
 *      *-------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct tag
{

		struct tag *left;
			struct tag *right;
				char *data;
}node;

void pre_process(char *exp)
{

	char *fast = exp, *last = exp - 1;
	for(; *fast != '\0'; ++fast)
	{

		if(*fast != ' ' && *fast != '\n')
		{

			*(++last) = *fast;
		}
	}
	*(++last) = '\0';

	/*if the character represents minus, replace it with '#',
	 *	  we'll reinterpret '-' as sign to meet the requirement of atoi()*/
	fast = exp;
	while(*fast != '\0')
	{

		if(*fast == '-')
		{

			if(*(fast-1) == ')' || isdigit(*(fast-1)))
			{
				*fast = '#';
			}
		}
		++fast;
	}
}

/* in an expression tree, operands are stored in leaves,
 *    operators ars stored in roots, the earlier an operator is activatied,
 *       the lower the level where its been stored in the tree, this function is used to 
 *          get the index of the LAST activatied operator in the notation*/
int getLastOpt(char *str, int bg, int end)
{

	int bracket_level = 0;
	int AddSub = 0;
//	if there is no operator in the subset of the notation, returns -1
		int idx = -1;
		for(int i = bg; i < end; ++i)
		{

			/*the function is called recursivly while building the expression tree, 
			  each time arg bg and end defines a subset of origin notation str,
			  so we need to ignore the brackets pair enclosing the whole notation*/
			while(*(str+bg) == '(' && *(str+end) == ')')
			{

				++bg, --end;
				i = bg;
			}

			/* an operator enclosed by brackets mustnt be the last to be activated*/
			if(*(str+i) == '(')
			{

				++bracket_level;
			}
			else if(*(str+i) == ')')
			{

				--bracket_level;
			}

			else if(*(str+i) == '#' || *(str+i) == '+' && bracket_level == 0)
			{

				idx = i;
				AddSub = 1;
			}
			/* operator * and operator \ has higher priority than + and -,
			   so they mustnt be the last to be activated while + and - exists*/
			else if(*(str+i) == '*' || *(str+i) == '/' && bracket_level == 0 &&AddSub == 0)
			{
				idx = i;
			}
		}
		return idx;
}

node *create_exp_tree(char *str, int bg, int end)
{

	node *p = (node*)calloc(1, sizeof(node));
	int index = getLastOpt(str, bg, end);
	/*if the subset contains no operator, put it in the leaf
	  and the recursion is over*/
	if(index == -1)
	{

		while(*(str+bg) == '(' && *(str+end) == ')')
		{

			++bg, --end;
		}
		p->data = (char*)calloc(1, end - bg + 2);
		int i = bg, j = 0;
		for(; i <= end; ++i)
		{

			p->data[j++] = *(str+i);
		}
		p->data[j] = '\0';
		p->left = NULL;
		p->right = NULL;
	}
	/* otherwise, the operator is stored in roots, and the recursion continues*/
	else
	{

		p->data = (char*)calloc(1,2);
		p->data[0] = *(str+index);
		p->data[1] = '\0';

		while(*(str+bg) == '(' && *(str+end) == ')')
		{

			++bg, --end;
		}
		p->left = create_exp_tree(str, bg, index -1);
		p->right = create_exp_tree(str, index + 1, end);
	}
	return p;
}

void rpoland(node* exp)
{

	if(exp != NULL)
	{

		rpoland(exp->left);
		rpoland(exp->right);
		printf("%s ", exp->data);
	}
}

void poland(node *exp)
{

	if(exp != NULL)
	{

		printf("%s ", exp->data);
		poland(exp->left);
		poland(exp->right);
	}
}

void normal(node *exp)
{

	if(exp != NULL)
	{

		normal(exp->left);
		printf("%s ", exp->data);
		normal(exp->right);
	}
}

int main()
{

	char s[1024];
	node *expression = NULL;

	fgets(s, 1024, stdin);

	pre_process(s);
	expression = create_exp_tree(s, 0, strlen(s)-1);

	rpoland(expression);
	printf("\n");
	poland(expression);
	printf("\n");
	normal(expression);
	printf("\n");

	return 0;
}
