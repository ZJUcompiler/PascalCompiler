#include <zconf.h>
#include <x86.h>
#include "globals.h"
#include "util.h"
#include "symbol.h"
#include "cgen.h"

int yyparse();
extern int totalLine;
extern TreeNode * root;
extern int hasError;
extern symbolNode buckets[BUCKET_SIZE+1];
int traceflag = 0;
int printflag = 0;
int doSemantic = 1;
int printSymbol = 0;
char fileName[64];
char filePreName[64];


void printTree(TreeNode* t, int depth){
	static int flag[100];
	static int step = 3;
	int i;
	if (t->sibling == NULL) flag[depth] = 0;
	else flag[depth] = 1;

	for (i=0; i<depth*step; i++) {
		if (i <= (depth-1)*step){
			if (i % step == 0 && flag[i / step + 1]) printf("|");
			else if (i == (depth-1)*step) printf("|");
			else printf(" ");
		} else printf("-");
	}
	printTreeNode(t);
	TreeNode* p = t->child;
	while (p != NULL){
		printTree(p, depth+1);
		p = p->sibling;
	}
}

void analysisArg(int argc, char* argv[]){
	int i;
	for (i=0; i<argc; i++) {
		if (strcmp(argv[i], "-d") == 0)
			printflag = 1;
		else if (strcmp(argv[i], "-t") == 0)
			traceflag = 1;
		else if (strcmp(argv[i], "-s") == 0)
			doSemantic = 0;
		else if (strcmp(argv[i], "-y") == 0)
			printSymbol = 1;
		else {
			strcpy(fileName, argv[i]);
		}
	}
	if (argc < 2 || access(fileName, F_OK) < 0) {
		fprintf(stderr, "No pascal source file specified!\n");
		exit(1);
	}
	i = 0;
	while (fileName[i] != '.' && fileName[i] != '\0') {
		filePreName[i] = fileName[i];
		i++;
	}
	filePreName[i] = '\0';
}

int main(int argc, char* argv[]){
	char IR_name[64], CODE_name[64];
	extern FILE *CODE;
	analysisArg(argc, argv);
	freopen(fileName, "r", stdin);
	yyparse();
	if(doSemantic){
		semantic_analysis(root);
	}
//	printf("now == == %d\n",buckets);
	if (printflag && !hasError && root != NULL) printTree(root, 0);
	print_symbol_table(  buckets  );
	if(printSymbol){
		print_symbol_table(  (*(buckets+28))->nextBucket  );
		print_symbol_table(  (*((*(buckets+28))->nextBucket+13))->nextBucket  );
		print_symbol_table(  (*(buckets+48))->nextBucket  );
		print_symbol_table(  (*(buckets+40))->nextBucket  );
	}
	if (hasError) printf("\nthe compiler meets some error, aborted!\n\n");

	// gen Immediate

	strcpy(IR_name, filePreName);
	strcat(IR_name, ".tac");
	strcpy(CODE_name, filePreName);
	strcat(CODE_name, ".s");
	IR = fopen(IR_name, "w");
	codeGen(root);
	fclose(IR);
	IR = fopen(IR_name, "r");
	CODE = fopen(CODE_name, "w");
	genX86Asm(IR);
	fclose(CODE);
	return 0;
}
