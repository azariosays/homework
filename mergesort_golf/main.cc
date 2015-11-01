#include <iostream>
#include <vector>
#include <cstdlib>
#include <fstream>
using namespace std;

//BEGIN GOLF
//All semicolons between here and the end count as a stroke against you

//This function will sort the given vector from vec[start] to vec[end], LEAST TO GREATEST
//You must do it recursively, and can only write code in this section (between the BEGIN and END)


void merge(vector<unsigned int> &vec, int start, int mid, int end)
{
    vector<int> left(vec.begin() + start, vec.begin() + mid + 1), right(vec.begin() + mid + 1, vec.begin() + end + 1);

    int i = 0, j = 0, n1 = mid - start + 1, n2 = end - mid;
    while ( i < n1 && j < n2) {
        if (left[i] < right[j]) {
            vec[start++] = left[i++];
        } else {
            vec[start++] = right[j++];
        }
    }

    while (i < n1) {
        vec[start++] = left[i++];
    }

    while (j < n2) {
        vec[start++] = right[j++];
    }
}

void mergesort(vector<unsigned int> &vec, int start, int end)
{
    if (start < end) {
        
        mergesort(vec, start, ((start + end) / 2));
        mergesort(vec, (((start + end) / 2) + 1), end);
        merge(vec, start, ((start + end) / 2), end);
    }
}
//END GOLF

int main() {
    vector<unsigned int> vec;
    cout << "Please insert natural numbers to sort (0 to end): ";
    while (cin) {
        unsigned int temp;
        cin >> temp;
        if (!cin) break;
        if (temp == 0) break;
        vec.push_back(temp);
    }
    if (vec.size() > 0) 
        mergesort(vec,0,vec.size()-1);
    for (unsigned int i : vec) cout << i << " ";
    cout << endl;
    system("grep -c ';' main.cc >> temp");
    ifstream ins("temp");
    int golf_score;
    ins >> golf_score;
    cerr << "Number of strokes: " << golf_score - 17 << endl;
    system("rm temp");
}
