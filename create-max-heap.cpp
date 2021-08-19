#include <iostream>
using namespace std;

void heapify(int a[], int n, int pos) {
    int l=2*pos+1;
    int r=2*pos+2;
    int largest=pos;
    if(l<n&&a[l]>a[largest])largest=l;
    if(r<n&&a[r]>a[largest])largest=r;
    if(largest!=pos){
        int t = a[largest];
        a[largest] = a[pos];
        a[pos] = t;
        heapify(a,n,largest);
    }
}
int main() {
	int a[] = {1,2,3,4,5};
	int n = 5;
	int start = (n/2) - 1;
	for(int i=start;i>=0;i--){
	    heapify(a,n,i);
	}
	for(int i=0;i<n;i++) {
	    cout<<a[i]<<" ";
	}
	return 0;
}
