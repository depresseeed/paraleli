#include "CRat.h"
#include "CRat0.h"

#include <chrono>
#include <omp.h>

void parallel(int arr_size, size_t nn)
{
    vector<CRat0> vec1;
    vector<CRat0> vec2;
    vector<CRat0> vec_rez;

    fr* arr = (fr*)malloc(sizeof(fr) * nn);
    for (int i = 0; i < arr_size; i++)
    {

        for (int j = 0; j < nn; j++)
        {
            arr[j].q = abs(rand() % 10) + 1;
            arr[j].p = rand() % 10 + 1;
        }

        vec1.push_back(CRat0( nn, arr, "data1"));
        vec2.push_back(CRat0( nn, arr , "data2"));
    }

  
    auto start = std::chrono::system_clock::now();
    for (int i = 0; i < arr_size; i++)
    {
        vec_rez.push_back(vec1[i] + vec2[i]);
    }
    auto end = std::chrono::system_clock::now();
    int elapsed_ms = static_cast<int>(std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count());
    std::cout << "Make add operator without parallelization: " << elapsed_ms << " ms" << endl;

    
    auto start1 = std::chrono::system_clock::now();
   
    int d = 0;
#pragma omp parallel for shared(vec1, vec2, vec_rez) private(d)
    for (d = 0; d < arr_size; d++)
    {
        vec_rez[d] = vec1[d] + vec2[d];
    }
    auto end1 = std::chrono::system_clock::now();
    int elapsed_marr_size = static_cast<int>(std::chrono::duration_cast<std::chrono::milliseconds>(end1 - start1).count());
    std::cout << "Make add operator with parallelization: " << elapsed_marr_size << "ms" << endl;

    //
    vec1.clear();
    vec2.clear();
    vec_rez.clear();
}