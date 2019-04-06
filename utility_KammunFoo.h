#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/***************************************************************************************************************************
********Function Descriptions********

void validateFiles(const studentrecord *, int *, char *, FILE **, FILE **, int, char **);
//Function that validates if commandline arguments are in the form: lettergrader.c inputFile.txt outputFile. If further
  validates if inputFile.txt can be read and outputFile.txt can be created. Finally, it keeps a running total of the
  number of students in the inputFile.txt. If the number of students is not between 1 and 100, user will be notified
  and the program exits.

void readIntoStruct(studentrecord *, int *, char *, FILE **);
//Function that reads the inputFile.txt into the structure one line at a time, and then separates the each line into individual
  fields, i.e., q1, q2, q3, q4, midi, midii, and final. 

void getAverage(const studentrecord *, float *, int *);
//Function that calculates the averages of q1, q2, q3, q4, midi, midii, and final based on the actual number of students
  in the inputFile.txt.

void getMin(const studentrecord *, int *, int *);
//Function that calculates the mininums of q1, q2, q3, q4, midi, midii, and final based on the actual number of students
  in the inputFile.txt.

void getMax(const studentrecord *, int *, int *);
//Function that calculates the maximums of q1, q2, q3, q4, midi, midii, and final based on the actual number of students
  in the inputFile.txt.

void printAvgMaxMin(float *, int *, int *, char **);
//Function that prints on the console (screen) the averages, minimuns, and maximums of q1, q2, q3, q4, midi, midii, and 
  final based on the actual number of students
  in the inputFile.txt.

void getFinalScore(studentrecord *, int *);
//Function calculates the final scores of students based on the weighted scores of q1, q2, q3, q4, midi, midii, and final.

void getGrade(studentrecord *, int *);
//Function that assigns a letter grade to students based on the final scores of students.

void writeGradeSortedbyName(studentrecord *, int *, FILE **, char **);
//Function that sorts the students' names in alphabetical order and writes the sorted names along with the students' letter
  grades into the outputFile.txt.

****************************************************************************************************************************/

/************Stucture Declaration************/
typedef struct
{
	char name[30];
	int q1, q2, q3, q4, midi, midii, final;
	double finalscore;
	char grade;

}studentrecord;

/****************************Function Prototypes (Declarations)****************************/
void validateFiles(const studentrecord *, int *, char *, FILE **, FILE **, int, char **);
void readIntoStruct(studentrecord *, int *, char *, FILE **);
void getAverage(const studentrecord *, float *, int *);
void getMin(const studentrecord *, int *, int *);
void getMax(const studentrecord *, int *, int *);
void printAvgMaxMin(float *, int *, int *, char **);
void getFinalScore(studentrecord *, int *);
void getGrade(studentrecord *, int *);
void writeGradeSortedbyName(studentrecord *, int *, FILE **, char **);