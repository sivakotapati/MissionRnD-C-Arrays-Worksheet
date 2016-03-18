/*
OVERVIEW:  given an array that has duplicate values remove all duplicate values.
E.g.: input: [1, 1, 2, 2, 3, 3], output [1, 2, 3]

Ex 2: [4,4,2,2,1,5] output : [4,2,1,5]

INPUTS: Integer array and length of the array .

OUTPUT: Update input array by removing duplicate values and return the final array length

ERROR CASES: Return -1 for invalid inputs.

NOTES: Don't create new array, try to change the input array.
*/

#include <stdio.h>
void quickSort(int a[], int first,int last);
int removeArrayDuplicates(int *Arr, int len)
{
	if (Arr == NULL || len <= 0) 
		return -1;
	quickSort(Arr,0,len-1);

	int i,j=0;
	for (i = 1; i < len;i++){
		if (Arr[i] != Arr[j]){
			j++;
			Arr[j] = Arr[i];
		}
	}
	return j+1;//j is length of new Array
	return -1;
}
void quickSort(int a[], int first, int last)
{
	int pivot, temp, i, j;
	if (first < last){
		pivot = first;
		i = first;
		j = last;

		while (i < j){
			while (a[i] <= a[pivot] && i < last)
				i++;
			while (a[j] > a[pivot])
				j--;
			if (i < j){
				temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
		}
		temp = a[pivot];
		a[pivot] = a[j];
		a[j] = temp;
		quickSort(a, first, j - 1);
		quickSort(a, j + 1, last);
	}
}
