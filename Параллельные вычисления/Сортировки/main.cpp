// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cstdlib>
#include <omp.h>
#include <vector>

using namespace std;

void merge(int n, vector<int>& arr, int start, int medium, int end);


void PrintNewMass(vector<int> arr, int n) {
    for (int i = 0; i < n; i++){
        std::cout << arr[i] << " ";
    }
    cout << endl;
}

void BubbleSort(int n, vector<int>& arr, int thread=1) {
        int i, j;
        bool swapped;
        for (i = 0; i < n-1; i++) {
            swapped = false;
            for (j = 0; j < n-i-1; j++) {
                if (arr[j] > arr[j+1]) {
                    swap(arr[j], arr[j+1]);
                    swapped = true;
                }
            }
            if (!swapped)
                break;
        }
}

void BubbleSortParallel(int n, vector<int>& arr, int threads) {
    int i, j, num_thread, start, end;

    omp_set_num_threads(threads);
#pragma omp parallel shared(arr, n, threads) private(i, j, num_thread, start, end)
    {
        num_thread = omp_get_thread_num();
        int size = n + (n % threads != 0 ? (threads - size % threads) : 0);
        start = num_thread*(size/threads);
        end = start + size/threads - 1;

        bool swapped;
        for (i = start; i < end; i++) {
            swapped = false;
            for (j = start; j < end; j++) {
                if (arr[j] > arr[j+1]) {
                    swap(arr[j], arr[j+1]);
                    swapped = true;
                }
            }
            if (!swapped)
                break;
        }
    }

    int oldThreads = threads;
    while (threads > 1) {
        threads /= 2;
        omp_set_num_threads(threads);
#pragma omp parallel shared(arr, n, threads) private(i, j, num_thread, start, end)
        {
            num_thread = omp_get_thread_num();
            int size = n + (n % threads != 0 ? (threads - size % threads) : 0);
            start = num_thread * (size / threads);
            end = start + size / threads - 1;

            int medium = start + size / threads / 2;
            merge(n, arr, start, medium, end);
        }
    }


    int size = n + (n % oldThreads != 0 ? (oldThreads - n % oldThreads) : 0);
    int medium = size / 2;
    merge(n, arr, 0, medium, n-1);

    threads = oldThreads;
    omp_set_num_threads(threads);

}

void InsSort(int n, vector<int>& arr, int thread=1) {
    for (int i = 1; i < n; i++) {
        for (int j = i; j > 0 && arr[j - 1] > arr[j] ; j--) {
            int tmp = arr[j - 1];
            arr[j - 1] = arr[j];
            arr[j] = tmp;
        }
    }
}


void InsSortParallel(int n, vector<int>& arr, int threads) {
    int i, j, num_thread, start, end;

    omp_set_num_threads(threads);
#pragma omp parallel shared(arr, n, threads) private(i, j, num_thread, start, end)
    {
        num_thread = omp_get_thread_num();
        int size = n + (n % threads != 0 ? (threads - size % threads) : 0);
        start = num_thread*(size/threads);
        end = start + size/threads - 1;

        for (i = start-1; i < end+1; i++) {
            for (j = i; j > start && arr[j - 1] > arr[j]; j--) {
                swap(arr[j-1], arr[j]);
            }
        }
    }


    int oldThreads = threads;
    while (threads > 1) {
        threads /= 2;
        omp_set_num_threads(threads);
#pragma omp parallel shared(arr, n, threads) private(i, j, num_thread, start, end)
        {
            num_thread = omp_get_thread_num();
            int size = n + (n % threads != 0 ? (threads - size % threads) : 0);
            start = num_thread * (size / threads);
            end = start + size / threads - 1;

            int medium = start + size / threads / 2;
            merge(n, arr, start, medium, end);
        }
    }


    int size = n + (n % oldThreads != 0 ? (oldThreads - n % oldThreads) : 0);
    int medium = size / 2;
    merge(n, arr, 0, medium, n-1);

    threads = oldThreads;
    omp_set_num_threads(threads);

}

void merge(int n, vector<int>& arr, int start, int medium, int end) {
    int indexFirst{ start }, indexSecond{ medium };
    vector<int> subVec;

    while (indexFirst < medium || indexSecond <= end) {
        if (indexFirst < medium && indexSecond <= end) {
            if (arr[indexFirst] < arr[indexSecond])
                subVec.push_back(arr[indexFirst++]);
            else
                subVec.push_back(arr[indexSecond++]);
        }
        else
            if (indexFirst < medium) {
                while (indexFirst < medium)
                    subVec.push_back(arr[indexFirst++]);
        }
        else
            if (indexSecond <= end) {
                while (indexSecond <= end)
                    subVec.push_back(arr[indexSecond++]);
        }
    }

    for (int i = start; i <= end; i++) {
        arr[i] = subVec[i - start];
    }
}

int comp(const void* i, const void* j) {
    return *(int*)i - *(int*)j;
}

enum class ordered
{
    increase,
    decrease,
    not_ordered,
};

vector<int> generate_arr(int size, ordered start_order) {
    vector<int> a;

    srand(time(0));

    if (start_order == ordered::not_ordered) {
        for (int i = 0; i < size; ++i) {
            a.push_back(rand() % 1000);
        }
    }
    else if (start_order == ordered::increase) {
        for (int i = 0; i < size; ++i) {
            a.push_back(i);
        }
    }
    else if (start_order == ordered::decrease) {
        for (int i = 0; i < size; ++i) {
            a.push_back(size - i);
        }
    }

    return a;
}

typedef void(*sort_func) (int, vector<int>&, int);

double test_time_sort(int num, sort_func sort_f, ordered start_order) {
    vector<int> a = generate_arr(num, start_order);

    double test_time;

    auto start = clock();
    sort_f(num, a, 8);
    auto end = clock();

    test_time = static_cast<double>(end - start) / CLOCKS_PER_SEC;

    return test_time;
}

int main() {
    vector<int> a = generate_arr(16, ordered::not_ordered);
    vector<int> a2 = generate_arr(16, ordered::not_ordered);
    PrintNewMass(a, 16);
    BubbleSortParallel(16, a, 4);
    PrintNewMass(a, 16);
    cout << endl;
    PrintNewMass(a2, 16);
    InsSortParallel(16, a2, 4);
    PrintNewMass(a2, 16);


 //   vector<int> n{10, 100, 1000, 10000};
/*
    vector<int> n{10, 100, 1000, 10000, 100000};
    int num_tests{ static_cast<int>(n.size()) };
    vector<vector<double>> res(num_tests);

    vector<ordered> arr_orders{ ordered::increase, ordered::not_ordered, ordered::decrease };

    void (*funcs[4]) (int, vector<int>&, int) = {BubbleSortParallel, BubbleSort, InsSortParallel, InsSort};

    for (int index_func = 0; index_func < 4; ++index_func) {
        for (int i = 0; i < num_tests; i++) {
            for (auto arr_order : arr_orders) {
                int N = n[i];
                res.push_back(vector<double>());

                int index = res.size() - 1;

                for (int j = 0; j < 4; ++j)
                    res[index].push_back(test_time_sort(N, funcs[index_func], arr_order));

                double sum = 0.0;
                for (int j = 0; j < 4; ++j) {
                    sum += res[index][j];
                }

                double val{ sum / 4 };
                res[index].push_back(val);

                string s;
                switch (arr_order)
                {
                    case ordered::increase:
                        s = "increase";
                        break;
                    case ordered::decrease:
                        s = "decrease";
                        break;
                    case ordered::not_ordered:
                        s = "not_ordered";
                        break;
                    default:
                        break;
                }

                string s_func;
                switch (index_func)
                {
                    case 0:
                        s_func = "paralleled buble sort";
                        break;
                    case 1:
                        s_func = "buble sort";
                        break;
                    case 2:
                        s_func = "paralleled insert sort";
                        break;
                    case 3:
                        s_func = "insert sort";
                        break;
                    default:
                        break;
                }

                printf("n = %d, type_sort = %s, order = %s\nt1: %f\nt2: %f\nt3: %f\nt4: %f\nAVG=%f\n____________________\n",
                       n[i], s_func.c_str(), s.c_str(), res[index][0], res[index][1], res[index][2], res[index][3], res[index][4]);
            }
        }
    }

    for (int i = 0; i < res.size(); ++i) {
        for (int j = 0; j < res[i].size(); ++j) {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
*/
    return 0;
}


