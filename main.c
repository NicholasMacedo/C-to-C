#include "a1.h"

int main(int argc, char *argv[])
{
    item * programList;

	if (argc != 2) {
        printf("Please run the code with the following format: ./a1 fileName.cc\n");
        exit(1);
	}

    FILE * filePointer = openFile(argv[1]);

    programList = readFile(filePointer);
    fclose(filePointer);

    programList = replaceClass(programList);

    numFunctInClass(programList);
    programList =  changeFunctInClass (programList);

    renameFunctionsInCode(programList);
    replaceVarInClassFunct(programList);

    toFile(programList, argv[1]);

    freeList(programList);
	return 0;
}

