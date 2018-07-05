#include <iostream>
#include <stdio.h>

using namespace std;

int MaxSumNoDrop(int *data, int begin, int length){
int max = -1;
int sum[begin+length];
	for (int i = begin; i < begin+length; ++i){
		sum[i] = data[i];
		if(max < sum[i]){
			max = sum[i];
		}
		for(int j = begin; j < i - 1; ++j){
			if(data[i] > data[j] && sum[i] < sum[j] + data[i]){
				sum[i] = sum[j] + data[i];
				if(max < sum[i]){
					max = sum[i];
				}
			}
		}
	}
	return max;
}

int main(){
	int *data;
	int N;
	while (cin >> N){
		data = new int[N];
		for (int i = 0; i < N; ++i){
			cin >> data[i];
		}
		int max1 = MaxSumNoDrop(data, 0, N-1);
		int max2 = MaxSumNoDrop(data, 1, N-1);
		if(N == 1) max1 = max2 = data[0];
		if (max1 > max2){
			cout << max1 << endl;
		}else{
			cout << max2 << endl;
		}
		delete []data;
	}
}