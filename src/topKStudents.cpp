/*
OVERVIEW:  You are given scores for students of a class in alphabetical order. Write a function that returns the names and scores of top K students.
Input is array of structures of type student (each student has name and score).
E.g.: If input is [ { "stud1", 20 }, { "stud2", 30 }, { "stud3", 40 } ] (three students with marks 20, 30 , 40) and K value is 2.
return top 2 students [ { "stud2", 30 }, { "stud3", 40 } ]

INPUTS: array of structures of type student, length of the array, integer K.

OUTPUT: Return top K students from array. Output need not be in decreasing order of scores.

ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/

#include <iostream>
#include <malloc.h>
#include<stdio.h>
#include<string.h>

struct student {
	char *name;
	int score;
};

struct student ** topKStudents(struct student *students, int len, int K) {
	if (students == NULL || len <= 0||K<=0)
		return NULL;

	struct student **s1 = (struct student **)malloc(K*sizeof(struct student *));
    struct student *s = (struct student *)malloc(sizeof(struct student));

	int i, j, max, t=0;
	char tname[10];
	//sorting
	for (i = 0; i < len; i++){
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

			/*//swapping names
			strcpy(tname, students[i].name);
			strcpy(students[i].name, students[max].name);
			strcpy(students[max].name, tname);*/
		}
	}
	if (K > len)
		K = len;
	/*for (i =0; i<K; i--){
		strcpy((*s[i]).name,students[i].name);
		(*s[i]).score = students[i].score;
	}*/
	for (i = 0; i < K; i++){
		s1[i] = &students[i];
	}
	//s1 = &s;
	return s1;
	return NULL;
}