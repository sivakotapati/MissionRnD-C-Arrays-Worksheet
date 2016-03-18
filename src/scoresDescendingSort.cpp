/*
OVERVIEW:  You are given scores for students of a class in alphabetical order. Write a function that sorts these scores in descending order.
Input is array of structures of type student (each student has name and score).
E.g.: If input is [ { "stud1", 20 }, { "stud2", 30 }, { "stud3", 40 } ] (three students with marks 20, 30 , 40).
Output for this will be [ { "stud3", 40 }, { "stud2", 30 }, { "stud1", 20 } ]

INPUTS: Array of structures of type student, length of array.

OUTPUT: Sort the array in descending order of scores.

ERROR CASES: Return NULL for invalid Inputs.

NOTES:
*/

#include <stdio.h>
#include<string.h>
struct student {
	char name[10];
	int score;
};

void * scoresDescendingSort(struct student *students, int len) {
	if (students == NULL || len <= 0)
		return NULL;
	int i, j, max, t;
	char tname[10];

	//selection sorting
	for (i = 0; i < len - 1; i++){
		max = i;
		for (j = i + 1; j < len; j++){
			if (students[j].score >students[max].score){
				max = j;
			}
		}
		if (max != i){
			//swapping scores
			t = students[i].score;
			students[i].score = students[max].score;
			students[max].score = t;

			//swapping names
			strcpy(tname, students[i].name);
			strcpy(students[i].name, students[max].name);
			strcpy(students[max].name, tname);
		}
	}
	return NULL;
}