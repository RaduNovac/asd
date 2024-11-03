#include <iostream>
using namespace std;

void merge(int v[], int const left, int const mid, int const right){
	int n1 = mid - left + 1;
	int n2 = right - mid;

	// Creo  gli array temporanei
	auto *v_left = new int[n1], *v_right = new int[n2];

	// Copio i dati negli array temporanei
	for (auto i = 0; i < n1; i++){
        v_left[i] = v[left + i];
    }
	for (auto j = 0; j < n2; j++){
        v_right[j] = v[mid + 1 + j];
    }

	int indice_sotto_array_1 = 0, // Indice iniziale del primo sotto-array
        indice_sotto_array_2 = 0, // Indice iniziale del secondo sotto-array
        indice_array_unito= left; // Indice iniziale del sotto-array unito

	// Merge the temp arrays back into array[left..right]
	while (indice_sotto_array_1 < n1 && indice_sotto_array_2 < n2) {
		if (v_left[indice_sotto_array_1] <= v_right[indice_sotto_array_2]) {
			v[indice_array_unito] = v_left[indice_sotto_array_1];
            indice_sotto_array_1++;
		}
		else {
			v[indice_array_unito] = v_right[indice_sotto_array_2];
            indice_sotto_array_2++;
		}
        indice_array_unito++;
	}
	// Copy the remaining elements of
	// left[], if there are any
	while (indice_sotto_array_1 < n1) {
		v[indice_array_unito] = v_left[indice_sotto_array_1];
        indice_sotto_array_1++;
        indice_array_unito++;
	}
	// Copy the remaining elements of
	// right[], if there are any
	while (indice_sotto_array_2 < n2) {
		v[indice_array_unito] = v_right[indice_sotto_array_2];
        indice_sotto_array_2++;
        indice_array_unito++;
	}
	delete[] v_left;
	delete[] v_right;
}

void mergeSort(int v[], int const begin, int const end)
{
	if (begin < end){
        int mid = (begin + end) / 2;//Prende comunque la parte itnera  inferiore, sennò si usa floor  dalla libreria cmath
        mergeSort(v, begin, mid);
        mergeSort(v, mid + 1, end);
        merge(v, begin, mid, end);
    }
}

void printArray(int A[], int size)
{
	for (auto i = 0; i < size; i++)
		cout << A[i] << " ";
}

int main()
{
	int v[] = { 12, 11, 13, 5, 6, 7 };
	auto dim_v = sizeof(v) / sizeof(v[0]);

	cout << "L'array di partenza (non ordinato e':)" << endl;
	printArray(v, dim_v);

	mergeSort(v, 0, dim_v - 1);

	cout << "\nL'array ordinato e':" << endl;
	printArray(v, dim_v);

	return 0;
}
