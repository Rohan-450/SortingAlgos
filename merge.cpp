#include <iostream>
using namespace std;

void print_array(int a[],int n){
	for (int i=0;i<n;i++){
		cout<<a[i]<<" ";
	}
	return;
}
void merge(int a[],int s,int mid,int e){
	int b[100];		//new array initialized
	int i = s;
	int j = mid + 1;
	int k = s;
	
	while (i <= mid && j <= e){		//comparing each element of the individual sub arrays
		if (a[i] <= a[j]){			//and pushing them into the new array b[]
			b[k] = a[i];
			i ++;
		}
		else{
			b[k] = a[j];
			j ++;
		}
		k ++;
	}
	while (i <= mid){	//checking whether any element is left in either of the sub
		b[k] = a[i];	//arrays and pushing them into the new array
		k ++;
		i ++;
	}
	while (j <= e){
		b[k] = a[j];
		k ++;
		j ++;
	}
	for (int i=s;i<=e;i++){		//reassigning all the values of the new array to the
        a[i] = b[i];			//previous array
    }
	return;
}

void merge_sort(int a[],int s,int e){
	if (s < e){
		int mid = (s + e) / 2;	//dividing the array about the mid element
		merge_sort(a,s,mid);		//repeated continuous division until we get arrays
		merge_sort(a,mid + 1,e);	//of single elements
		merge(a,s,mid,e);	//combines those sub arrays into a single sorted array
	}
	return;
}

int main(){
	int a[100],n;
	cout<<"How many elements:";
	cin>>n;
	cout<<"Enter "<<n<<" elements:";
	for (int i=0;i<n;i++){
		cin>>a[i];
	}
	cout<<"Original array:";
	print_array(a,n);
	int s = 0;
	int e = n - 1;
	merge_sort(a,s,e);
	cout<<"\nSorted array:";
	print_array(a,n);
	return 0;
}