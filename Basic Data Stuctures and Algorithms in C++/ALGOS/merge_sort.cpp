#include <iostream>
#include <vector>

using namespace std;

void merge_sort(vector<int> &v, int start, int end){
    if(start >=  end){
        return;
    }
    else{
        int mid = (start + end) / 2;
        merge_sort(v, start, mid);
        merge_sort(v, mid + 1, end);
        int i = start;
        int j = mid + 1;
        while(i <= mid && j <= end){
            if(v[i] > v[j]){
                int temp = v[i];
                v[i] = v[j];
                v[j] = temp;
                i++;
                j++;
            }else{
                i++;
            }
        }
    }
}

int main(){
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    vector<int> v(n,0);
    cout << "Enter the elements to be sorted: ";
    for(int i = 0; i < v.size(); i++){
        int temp;
        cin >> temp;
        v[i] = temp;
    }

    merge_sort(v, 0 , v.size()-1);

    cout << "The sorted array is \n";
    for(int i = 0; i < v.size(); i++){
        cout << v[i] << " ";
    }
    cout << endl;

    return 0;
}