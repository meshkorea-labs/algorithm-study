#include <bits/stdc++.h>
using namespace std;

const int MAX_FENCE_HEIGHT = 1000;

void checkFenceDiff(int fenceCount, int* diff, int* counter, int index) {

	int count = 1;
	int i;
	int compareValue = diff[index];

	cout << " compareValue : " << compareValue << endl;

	for(i = index; i < fenceCount - 1; i++){

		if(compareValue <= diff[i + 1]){
			count++;
			cout << " compareValue : " << compareValue << " count : " << count << endl;
		}else{
			break;
		}
		if(compareValue < diff[i + 1]){
			checkFenceDiff(fenceCount, diff, counter, i + 1);
		}
	}

	int existCount = counter[compareValue] ;
	cout << " diff index : " << index << " diff[index] : " << diff[index] << " existCount : " << existCount << " count : " << count << endl;
	if(existCount < count){
		counter[compareValue] = count + 1;
	}
}

int main () {

	int count;
  	cin >> count;

  	cout << " count is : " << count << endl;

	int fence[count];
	int diff[count - 1];
	int counter[MAX_FENCE_HEIGHT] = {0,};
	int maxArea = 0;

	for(int i = 0; i < count ; i++){
		int x;
		cin >> x;
		fence[i] = x;	

		if(i != 0){
			int a = fence[i];
			int b = fence[i - 1];

			if(a >= b){
				diff[i - 1] = b;
			}else{
				diff[i - 1] = a;
			}
			cout << "diff is : " << diff[i - 1] << endl; 
		}

		if(x > maxArea)
			maxArea = x;
		cout << x << endl;
	}

	for(int j = 0; j < count - 1 ; j++){
		cout << j << endl;
	}


	checkFenceDiff(count, diff, counter, 0);
	for(int i = 0;i < 10; i++){
		cout << " i is : " << i << " counter value is : " << counter[i] << endl;
		int area = (counter[i]) * i;
		if(area > maxArea)
			maxArea = area;
	}

	cout << "Max Area is : " << maxArea << endl;

	return 0;
}