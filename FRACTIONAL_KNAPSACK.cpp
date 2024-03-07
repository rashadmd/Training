#include <bits/stdc++.h>
using namespace std;
 
struct Item {
	int value, weight;
 
	Item(int value, int weight)
    	: value(value), weight(weight)
	{
	}
};
 
bool cmp(struct Item a, struct Item b)
{
	double r1 = (double)a.value / a.weight;
	double r2 = (double)b.value / b.weight;
	return r1 > r2;
}
 
double fractionalKnapsack(struct Item arr[], int N, int size)
{
	sort(arr, arr + size, cmp);
 
	int curWeight = 0;
	double finalvalue = 0.0;
 
	cout << "Selected items:" << endl;
	for (int i = 0; i < size; i++) {
    	if (curWeight + arr[i].weight <= N) {
        	cout << "Item " << i+1 << ": Value: " << arr[i].value << ", Weight: " << arr[i].weight << endl;
        	curWeight += arr[i].weight;
        	finalvalue += arr[i].value;
    	}
    	else {
        	int remain = N - curWeight;
        	finalvalue += arr[i].value * ((double)remain / arr[i].weight);
        	cout << "Item " << i+1 << ": Value: " << arr[i].value << ", Weight: " << arr[i].weight
             	<< " (Fractional, " << remain << " out of " << arr[i].weight << " taken)" << endl;
        	break;
    	}
	}
 
	return finalvalue;
}
 
int main()
{
	int N = 15;
 
	Item arr[] = { { 5, 1 },
               	{ 10, 3 },
               	{ 15, 5 },
               	{ 7, 4 },
               	{ 8, 1 },{ 9, 3},{ 4, 2 }
	};
 
	int size = sizeof(arr) / sizeof(arr[0]);
 
	cout << "Maximum profit earned = " << fractionalKnapsack(arr, N, size) << endl;
	return 0;
}
