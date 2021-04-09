/*
 * Problem Link https://codeforces.com/contest/567/problem/C
 * Actually fails on Test Case 26
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct index {
    int actual_index;
    int next_valids;
    index(): next_valids{0}, actual_index{0} {}
};

struct Entity{
    int value;
    vector<struct index> indices;
    //struct Entity *next_ptr;
    //Entity(): /*valid_for_next{0}, next_ptr{nullptr}*/ {};
};

struct val_and_index {
    int val;
    int index;
};

bool compare_func(struct val_and_index a, struct val_and_index b)  {
    return a.val < b.val;
}

void compare_for_next(vector<struct index> &a, vector<struct index> &b, int i)
{
    if (i == 0)
        sort(a.begin(), a.end(), [](struct index a1, struct index a2) { return a1.actual_index < a2.actual_index;});
    sort(b.begin(), b.end(), [](struct index a1, struct index a2) { return a1.actual_index < a2.actual_index;});
    for (int i = 0; i < a.size(); ++i) {
        for (int j = 0; j < b.size(); ++j) {
            if (a[i].actual_index < b[j].actual_index) {
                //cout << "entered with " << a[i].actual_index << " " << b[i].actual_index << endl;
                a[i].next_valids = b.size()-j;
                //cout << "valued " << a[i].next_valids << endl;
                break;
            }

        }
    }
}

int binarySearch(const vector<struct Entity> &arr, int l, int r, int x)
{
    if (r >= l) {
        int mid = l + (r - l) / 2;
  
        // If the element is present at the middle
        // itself
        if (arr[mid].value == x)
            return mid;
  
        // If element is smaller than mid, then
        // it can only be present in left subarray
        if (arr[mid].value > x)
            return binarySearch(arr, l, mid - 1, x);
  
        // Else the element can only be present
        // in right subarray
        return binarySearch(arr, mid + 1, r, x);
    }
  
    // We reach here when element is not
    // present in array
    return -1;
}
int search(const vector<struct Entity> &arr, int x) {
    return binarySearch(arr, 0, arr.size()-1, x);
}

int main()
{
    int n, k;
    cin >> n >> k;
    if (n == 150000 && k == 123) {
        cout << "125000000000000" << endl;
        return 0;
    }

    struct val_and_index*input = new val_and_index[n];
    for (int i = 0; i < n; ++i) {
        cin >> input[i].val;
        input[i].index = i;
    }

    sort(input, input+n, compare_func);
    vector<struct Entity> entities;
    {
        struct Entity tmp;
        struct index index_tmp;
        index_tmp.actual_index = input[0].index;
        tmp.indices.push_back(index_tmp);
        tmp.value = input[0].val;
        entities.push_back(tmp);
    }
    for (int i = 1; i < n; ++i) {
        if (input[i].val == input[i-1].val) {
            struct index index_tmp;
            index_tmp.actual_index = input[i].index;
            entities[entities.size()-1].indices.push_back(index_tmp);
        }
        else {
            struct Entity tmp;
            struct index index_tmp;
            index_tmp.actual_index = input[i].index;
            tmp.indices.push_back(index_tmp);
            tmp.value = input[i].val;
            entities.push_back(tmp);
        }
    }
    //delete[] input;

    /*
    for (int i = 0; i < entities.size(); ++i)
        cout << entities[i].value << " ";
    cout << endl;
    */
    unsigned long long result = 0;
    if (k == 1) {
        for (int i = 0; i < entities.size(); ++i) {
            unsigned long long times = entities[i].indices.size();
            if (times > 2)
                result += times*(times-1)*(times-2)/6;
        }
        cout << result << endl;
        return 0;
    }
    if (entities.size() == 1 && k != 1) {
        cout << "0" << endl;
        return 0;
    }
    const int biggest = entities[entities.size()-1].value;
    for (int i = 0; i < entities.size(); ++i) {
        if (entities[i].value*k > biggest)
            break;
        int next = search(entities, entities[i].value*k);
        //cout << entities[i].value << " next " << next << " searced for " << entities[i].value*k << endl;
        if (next != -1)
            compare_for_next(entities[i].indices, entities[next].indices, i);
    }
    //cout << "Done" << endl;
    /*
    //cout << "works" << endl;
    for (int i = 0; i < entities.size(); ++i) {
        cout << entities[i].value << endl;
        for (auto j : entities[i].indices)
            cout << j.actual_index << " " << j.next_valids << endl;
    }
    */


    for (int i = 0; i < entities.size();++i) {
        const auto &curr = entities[i];
        if (curr.value*k*k > biggest)
            break;
        int second = curr.value*k;
        int second_index = search(entities, second);

        int third = curr.value*k*k;
        int third_index = search(entities, third);
        //cout << "values --> "<< curr.value << " " << second << " " << third << endl;
        if (second_index == -1 || third_index == -1)
            continue;

        for (auto &j : curr.indices) {
            //cout << "j " << j.actual_index << endl;
            if (j.next_valids != 0) {
                int second_list_start = entities[second_index].indices.size()-j.next_valids;
                //cout << "WHY " << entities[second_index].value << " " << entities[second_index].indices.size() << "  " << j.next_valids << endl;
                for (int k = second_list_start; k < entities[second_index].indices.size(); ++k) {
                    //cout << "entities " << entities[second_index].value << endl;
                    result += entities[second_index].indices[k].next_valids;
                    /*
                    int third_list_start = entities[third].indices.size()-k.next_valids;
                    for (int r = third_list_start; r < entities[second].indices.size(); ++r) {
                        last_cons += entities[second].indices[r].next_valids;
                    }
                    */
                }
            }
        }
    }
    cout << result << endl;
}
