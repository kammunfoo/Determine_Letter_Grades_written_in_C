#include "utility_KammunFoo.h"

int main(int argc, char *argv[])		//Main function that declares, defines, and initializes variables, arrays, and the structure.
{
	int num = 0;
	char buf[100];
	float ScoreAvg[7];
	int ScoreMin[7];
	int ScoreMax[7];
	studentrecord student[100];
	FILE *inFilePointer = NULL, *outFilePointer = NULL;

	/************************************Calling Functions************************************/
	validateFiles(student, &num, buf, &inFilePointer, &outFilePointer, argc, argv);
	readIntoStruct(student, &num, buf, &inFilePointer);
	getAverage(student, ScoreAvg, &num);
	getMin(student, ScoreMin, &num);
	getMax(student, ScoreMax, &num);
	printAvgMaxMin(ScoreAvg, ScoreMin, ScoreMax, argv);
	getFinalScore(student, &num);
	getGrade(student, &num);
	writeGradeSortedbyName(student, &num, &outFilePointer, argv);

	if (fclose(inFilePointer) != 0 || fclose(outFilePointer) != 0)		//Snippet that closes the inputFile.txt and outputFile.txt
		printf("\tError in closing files\n");							//before the program exits.

	return 0;
}