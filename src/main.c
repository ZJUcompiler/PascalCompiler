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
		if (strcmp(argv[i], "-d") == 0) printflag = 1;
		if (strcmp(argv[i], "-t") == 0) traceflag = 1;
		if (strcmp(argv[i], "-s") == 0) doSemantic = 0;
		if (strcmp(argv[i], "-y") == 0) printSymbol = 1;
	}
}

int main(int argc, char* argv[]){
	//freopen("C:/Users/shorC/Documents/GitHub/PascalCompiler/test/expression.pas", "r", stdin);

	analysisArg(argc, argv);
	yyparse();
	if(doSemantic){
		semantic_analysis(root);
	}
	//printf("now == == %d\n",buckets);
	if (printflag && !hasError && root != NULL) printTree(root, 0);
		//print_symbol_table(  buckets  );
	if(printSymbol){
		print_symbol_table(  (*(buckets+52))->nextBucket  );
		//print_symbol_table(  (*((*(buckets+28))->nextBucket+13))->nextBucket  );
		//print_symbol_table(  (*(buckets+48))->nextBucket  );
		//print_symbol_table(  (*(buckets+40))->nextBucket  );
	}
	if (hasError) printf("\nthe compiler meets some error, aborted!\n\n");

	// gen Immediate
	// IR = fopen("C:/Users/shorC/Documents/GitHub/PascalCompiler/test/expression.tac", "w");
	IR = stdout;
	codeGen(root);
	// fclose(IR);
	return 0;
}
