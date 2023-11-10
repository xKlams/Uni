#include <stdio.h>
void merge(int leftArray[], int rightArray[], int array[], int len);
void mergeSort(int array[], int length);

int main()

{   	

	// merge sort = recursively divide array in 2, sort, re-combine

	// run-time complexity = O(n Log n)

	// space complexity    = O(n)

	

	int array[] = {8, 2, 5, 3, 4, 7, 6, 1, 26, 231, 2, 5 , 7 , 89, 1};

	

	mergeSort(array, sizeof(array)/sizeof(int));

	

	for(int i = 0; i < sizeof(array)/sizeof(int); i++){

		printf("%d ", array[i]);

	}

}



void mergeSort(int array[], int length) {

	


	if (length <= 1) return; //base case

	

	int middle = length / 2;

	int leftArray[middle];

	int rightArray[length - middle];

	

	int i = 0; //left array

	int j = 0; //right array

	

	for(; i < length; i++) {

		if(i < middle) {

			leftArray[i] = array[i];

		}

		else {

			rightArray[j] = array[i];

			j++;

		}

	}

	mergeSort(leftArray, middle);

	mergeSort(rightArray, length - middle);

	merge(leftArray, rightArray, array, length);

}



void merge(int leftArray[], int rightArray[], int array[], int len) {

	

	int leftSize = len / 2;

	int rightSize = len - leftSize;

	int i = 0, l = 0, r = 0; //indices

	

	//check the conditions for merging

	while(l < leftSize && r < rightSize) {

		if(leftArray[l] < rightArray[r]) {

			array[i] = leftArray[l];

			i++;

			l++;

		}

		else {

			array[i] = rightArray[r];

			i++;

			r++;

		}

	}

	while(l < leftSize) {

		array[i] = leftArray[l];

		i++;

		l++;

	}

	while(r < rightSize) {

		array[i] = rightArray[r];

		i++;

		r++;

	}

}
