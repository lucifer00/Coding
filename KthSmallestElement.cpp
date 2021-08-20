// { Driver Code Starts
//Initial function template for C++

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution{
public: void heapify(int a[], int n, int pos) {
    int l=2*pos+1;
    int r=2*pos+2;
    int minimum=pos;
    if(l<n&&a[l]<a[minimum])minimum=l;
    if(r<n&&a[r]<a[minimum])minimum=r;
    if(minimum!=pos){
        int t = a[minimum];
        a[minimum] = a[pos];
        a[pos] = t;
        heapify(a,n,minimum);
    }
}
public: int deleteFromHeap(int a[], int n) {
	int x = a[n-1];
	a[0] = x;
	heapify(a,n-1,0);
	return n-1;
}

    public:
    int kthSmallest(int arr[], int l, int r, int k) {
         int n = r-l+1;
        for(int i=(n/2)-1;i>=0;i--) {
            heapify(arr, n, i);
        }
        int i = 0;
    while(i!=k-1) {
        n = deleteFromHeap(arr, n);
        i++;
    }
    return arr[0];

    }
};
 
int main()
{
    int test_case;
    cin>>test_case;
    while(test_case--)
    {
        int number_of_elements;
        cin>>number_of_elements;
        int a[number_of_elements];
        
        for(int i=0;i<number_of_elements;i++)
            cin>>a[i];
            
        int k;
        cin>>k;
        Solution ob;
        cout<<ob.kthSmallest(a, 0, number_of_elements-1, k)<<endl;
    }
    return 0;
}
