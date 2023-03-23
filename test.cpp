#include <bits/stdc++.h>
#include <string>
using namespace std;

class mysort{
    public:
        void quicksort(vector<int> &arr, int begin, int end){
            if(begin >= end) return;
            int l = begin, r = end;
            int crit = arr[begin];
            while(l<r){
                while(l < r && arr[r] >= crit) r--;
                arr[l] = arr[r];
                while(l < r && arr[l] <= crit) l++;
                arr[r] = arr[l];
            }
            arr[l] = crit;
            quicksort(arr, begin, l-1);
            quicksort(arr, l+1, end);
        }

        void bubblesort(vector<int> &arr){
            for(int i = 0; i < arr.size();i++){
                for(int j = i; j >= 1; j--){
                    if(arr[j] < arr[j-1]){
                        swap(arr[j], arr[j-1]);
                    }
                }
            }
        }

        void choosesort(vector<int> &arr){
            int pos=0;int m ;
            for(int i = arr.size()-1; i>=0; i--){
                m = 0x80000000;
                for(int j = 0; j<=i; j++){
                    if(arr[j] > m){
                        m = arr[j];pos = j;
                    }
                }
                swap(arr[pos], arr[i]);
            }
        }

        void mergesort(vector<int> &arr){
                
        }

        void mergesort(vector<int> &arr, int begin, int end){
            if(begin >= end) return;
            int mid = (begin+end)/2;
            mergesort(arr, begin, mid-1);
            mergesort(arr, mid, end);
            merge(arr, begin, mid-1, mid, end);
        }

        private:
        void merge(vector<int> &arr, int l1, int r1, int l2, int r2){
            int p1, p2; p1 = l1; p2 = l2;

        } 


};

template<typename T, typename F>
class print{
    public:
    static pri(const T& t){
        F f;
        f(t);
    }
};

template<typename T>
class rangeprint{
    void operator()(const T&t){
        cout << t.first << ' ' << t.second << endl;
    }
};

int main() {
    vector<int> arr{3,2,1,6,5,7,4,9,8,3,4,5,6,5,-1,-10,-100,-1000};
    mysort ms;
    //ms.quicksort(arr, 0, arr.size()-1);
    //ms.bubblesort(arr);
    // ms.choosesort(arr);
    typedef pair<int, int> range;
    vector<range> ranges;
    ranges.push_back({1,2});
    ranges.push_back({3,6});
    ranges.push_back({7,8});
    ranges.push_back({2,11});
    ranges.push_back({4,5});
    ranges.push_back({10,12});
    class cmp{
        bool operator()(const range &r1, const range&r2){
            if(r1.first == r2.second)
                return r1.second < r2.second;
            return r1.first < r2.first;
        }
    };
    std::sort(ranges.begin(), ranges.end(), cmp); 
    for(auto r:ranges){
        print<range, rangeprint<range>>::pri(r);
    }
}