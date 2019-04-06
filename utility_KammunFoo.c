#include "utility_KammunFoo.h"

//Function that validates commandline arguments, inputFile.txt and outputFile.txt.
void validateFiles(const studentrecord *student, int *num, char *buf, FILE **inFilePointer, FILE **outFilePointer, int argc, char **argv)
{
	if (argc != 3)		//Snippet that ensures commandline arguments are in the form: lettergrader.c inputFile.txt outputFile.
	{
		printf("\n\tUsage: %s inputFile.txt outputFile.txt\n\n", argv[0]);
		printf("\tProgram exited.\n\n\t");
		exit(EXIT_FAILURE);
	}

	else if ((*inFilePointer = fopen(argv[1], "r")) == NULL)		//Snippet that checks if inputFile.txt can be read.
	{
		printf("\n\tCannot open \"%s\" file.\n", argv[1]);
		printf("\tProgram exited.\n\n\t");
		exit(EXIT_FAILURE);

	}

	else if ((*outFilePointer = fopen(argv[2], "w")) == NULL)		//Snippet that checks if outputFile.txt can be created.
	{
		printf("\n\tCannot create \"%s\" file.\n\n", argv[2]);
		printf("\tProgram exited.\n\n\t");
		exit(EXIT_FAILURE);
	}

	else		//Snippet that notifies user where input/output will be read from/written into.
	{
		printf("\n\tInput will be read from: %s\n", argv[1]);
		printf("\tOutput will be written into: %s\n", argv[2]);
		printf("\n");
	}

	while (fgets(buf, 100 * sizeof(char), *inFilePointer) != NULL && buf[0] != '\n')		//Snippet that reads the inputFile.txt line by line and keeps a running total
	{																						//of the number of students.
		(*num)++;
	}

	if (*num == 0 || *num > 100)		//Snippet that ensures the number of students in the inputFile.txt is between 1 and 100. 
	{
		printf("\tNumber of students in InputFile \"%s\" = %d.\n", argv[1], *num);
		printf("\tPlease keep the number of students between 1 and 100.\n");
		printf("\tNo data have been processed.\n\n\t");
		fprintf(*outFilePointer, "\nNumber of students in InputFile \"%s\" = %d.\n", argv[1], *num);
		fprintf(*outFilePointer, "Please keep the number of students between 1 and 100.\n");
		fprintf(*outFilePointer, "No data have been processed.\n\n");

		if (fclose(*inFilePointer) != 0 || fclose(*outFilePointer) != 0)		//Snippet that closes both the inputFile.txt and outputFile.txt if the
		{																		//number of students is not between 1 and 100 before the program exits.
			printf("\tError in closing files\n\t");
			exit(EXIT_FAILURE);
		}

		exit(EXIT_SUCCESS);
	}

	printf("\tNumber of students in InputFile \"%s\" = %d\n", argv[1], *num);		//Snippet that prints on the screen (console) the actual number of
	rewind(*inFilePointer);															//students in the inputFile.txt.
}

void readIntoStruct(studentrecord *student, int *num, char *buf, FILE **inFilePointer)		//Function that reads the inputFile.txt into the structure one line
{																							//at a time.
	char *pToken;
	int i;
	for (i = 0; i < *num, (fgets(buf, 100 * sizeof(char), *inFilePointer) != NULL && buf[0] != '\n'); i++)		//Snippet that separates each line read from the
	{																											//inputFile.txt into individual fields.
		pToken = strtok(buf, ",");
		strcpy(student[i].name, pToken);

		pToken = strtok(NULL, ",");
		student[i].q1 = atoi(pToken);

		pToken = strtok(NULL, ",");
		student[i].q2 = atoi(pToken);

		pToken = strtok(NULL, ",");
		student[i].q3 = atoi(pToken);

		pToken = strtok(NULL, ",");
		student[i].q4 = atoi(pToken);

		pToken = strtok(NULL, ",");
		student[i].midi = atoi(pToken);

		pToken = strtok(NULL, ",");
		student[i].midii = atoi(pToken);

		pToken = strtok(NULL, ",");
		student[i].final = atoi(pToken);
	}
}

void getAverage(const studentrecord *student, float *ScoreAvg, int *num)		//Function that calculates the averages of students' scores.
{
	int i;
	float total = 0.0;
	for (i = 0; i < *num; i++)
		total += student[i].q1;
	ScoreAvg[0] = total / *num;

	total = 0.0;
	for (i = 0; i < *num; i++)
		total += student[i].q2;
	ScoreAvg[1] = total / *num;

	total = 0.0;
	for (i = 0; i < *num; i++)
		total += student[i].q3;
	ScoreAvg[2] = total / *num;

	total = 0.0;
	for (i = 0; i < *num; i++)
		total += student[i].q4;
	ScoreAvg[3] = total / *num;

	total = 0.0;
	for (i = 0; i < *num; i++)
		total += student[i].midi;
	ScoreAvg[4] = total / *num;

	total = 0.0;
	for (i = 0; i < *num; i++)
		total += student[i].midii;
	ScoreAvg[5] = total / *num;

	total = 0.0;
	for (i = 0; i < *num; i++)
		total += student[i].final;
	ScoreAvg[6] = total / *num;
}

void getMin(const studentrecord *student, int *ScoreMin, int *num)		//Function that calculates the minimums of students' scores.
{
	int i;
	for (i = 0; i < *num; i++)
	{
		if (i == 0)
			ScoreMin[0] = student[i].q1;
		if (student[i].q1 < ScoreMin[0])
			ScoreMin[0] = student[i].q1;
	}

	for (i = 0; i < *num; i++)
	{
		if (i == 0)
			ScoreMin[1] = student[i].q2;
		if (student[i].q2 < ScoreMin[1])
			ScoreMin[1] = student[i].q2;
	}

	for (i = 0; i < *num; i++)
	{
		if (i == 0)
			ScoreMin[2] = student[i].q3;
		if (student[i].q3 < ScoreMin[2])
			ScoreMin[2] = student[i].q3;
	}

	for (i = 0; i < *num; i++)
	{
		if (i == 0)
			ScoreMin[3] = student[i].q4;
		if (student[i].q4 < ScoreMin[3])
			ScoreMin[3] = student[i].q4;
	}

	for (i = 0; i < *num; i++)
	{
		if (i == 0)
			ScoreMin[4] = student[i].midi;
		if (student[i].midi < ScoreMin[4])
			ScoreMin[4] = student[i].midi;
	}

	for (i = 0; i < *num; i++)
	{
		if (i == 0)
			ScoreMin[5] = student[i].midii;
		if (student[i].midii < ScoreMin[5])
			ScoreMin[5] = student[i].midii;
	}

	for (i = 0; i < *num; i++)
	{
		if (i == 0)
			ScoreMin[6] = student[i].final;
		if (student[i].final < ScoreMin[6])
			ScoreMin[6] = student[i].final;
	}
}

void getMax(const studentrecord *student, int *ScoreMax, int *num)		//Function that calculates the maximums of students' scores.
{
	int i;
	for (i = 0; i < *num; i++)
	{
		if (i == 0)
			ScoreMax[0] = student[i].q1;
		if (student[i].q1 > ScoreMax[0])
			ScoreMax[0] = student[i].q1;
	}

	for (i = 0; i < *num; i++)
	{
		if (i == 0)
			ScoreMax[1] = student[i].q2;
		if (student[i].q2 > ScoreMax[1])
			ScoreMax[1] = student[i].q2;
	}

	for (i = 0; i < *num; i++)
	{
		if (i == 0)
			ScoreMax[2] = student[i].q3;
		if (student[i].q3 > ScoreMax[2])
			ScoreMax[2] = student[i].q3;
	}

	for (i = 0; i < *num; i++)
	{
		if (i == 0)
			ScoreMax[3] = student[i].q4;
		if (student[i].q4 > ScoreMax[3])
			ScoreMax[3] = student[i].q4;
	}

	for (i = 0; i < *num; i++)
	{
		if (i == 0)
			ScoreMax[4] = student[i].midi;
		if (student[i].midi > ScoreMax[4])
			ScoreMax[4] = student[i].midi;
	}

	for (i = 0; i < *num; i++)
	{
		if (i == 0)
			ScoreMax[5] = student[i].midii;
		if (student[i].midii > ScoreMax[5])
			ScoreMax[5] = student[i].midii;
	}

	for (i = 0; i < *num; i++)
	{
		if (i == 0)
			ScoreMax[6] = student[i].final;
		if (student[i].final > ScoreMax[6])
			ScoreMax[6] = student[i].final;
	}
}

void printAvgMaxMin(float *ScoreAvg, int *ScoreMin, int *ScoreMax, char **argv)		//Function that prints on the console (screen) the averages, minimuns, and maximums
{																					//of students' scores.
	printf("\n");
	printf("\tLetter grade has been calculated for students listed in input file \"%s\"\n"
		"\tand written to output file \"%s\".\n", argv[1], argv[2]);
	printf("\n");
	printf("\tHere is the class averages:\n");
	printf("\t\t\t Q1\t Q2\t Q3\t Q4\tMidI\tMidII\tFinal\n");
	printf("\tAverage:\t%5.2f\t%5.2f\t%5.2f\t%5.2f\t%5.2f\t%5.2f\t%5.2f\n", ScoreAvg[0], ScoreAvg[1], ScoreAvg[2], ScoreAvg[3], ScoreAvg[4], ScoreAvg[5], ScoreAvg[6]);
	printf("\tMinimum:\t%5d\t%5d\t%5d\t%5d\t%5d\t%5d\t%5d\n", ScoreMin[0], ScoreMin[1], ScoreMin[2], ScoreMin[3], ScoreMin[4], ScoreMin[5], ScoreMin[6]);
	printf("\tMaximum:\t%5d\t%5d\t%5d\t%5d\t%5d\t%5d\t%5d\n", ScoreMax[0], ScoreMax[1], ScoreMax[2], ScoreMax[3], ScoreMax[4], ScoreMax[5], ScoreMax[6]);
	printf("\n\t");
}

void getFinalScore(studentrecord *student, int *num)		//Function calculates the final scores of students based on the weighted scores of all tests.
{
	int i;
	for (i = 0; i < *num; i++)
		student[i].finalscore = student[i].q1 * .1 + student[i].q2 * .1 + student[i].q3 * .1 + student[i].q4 * .1 + student[i].midi * .2 + student[i].midii * .15 + student[i].final * .25;
}

void getGrade(studentrecord *student, int *num)		//Function that assigns a letter grade to students based on the final scores of students.
{
	int i;
	for (i = 0; i < *num; i++)
	{
		if (student[i].finalscore >= 90)
			student[i].grade = 'A';

		else if (student[i].finalscore >= 80)
			student[i].grade = 'B';

		else if (student[i].finalscore >= 70)
			student[i].grade = 'C';

		else if (student[i].finalscore >= 60)
			student[i].grade = 'D';

		else
			student[i].grade = 'F';
	}
}

void writeGradeSortedbyName(studentrecord *sortstudent, int *num, FILE **outFilePointer, char **argv)			//Function that sorts the students' names in alphabetical order
{																												//and writes the sorted names along with the students' letter
	fprintf(*outFilePointer, "\nLetter grade for %d students given in \"%s\" file is:\n\n", *num, argv[1]);		//grades into the outputFile.txt.
	studentrecord temp;
	int i, k;
	for (i = 0; i < *num - 1; i++)
		for (k = i + 1; k < *num; k++)
			if (strcmp(sortstudent[i].name, sortstudent[k].name) > 0)
			{
				temp = sortstudent[i];
				sortstudent[i] = sortstudent[k];
				sortstudent[k] = temp;
			}

	for (i = 0; i < *num; i++)
		fprintf(*outFilePointer, "%-30s: \t%c\n", sortstudent[i].name, sortstudent[i].grade);
}