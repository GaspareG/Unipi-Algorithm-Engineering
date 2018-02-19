# 6 Set Intersection

 
- Merge-based Set intersection ([merge_intersection.hpp](merge_intersection.hpp))
- Binary-search-based Set intersection ([binary_search.hpp](binary_search_intersection.hpp))
- Mutual Partitioning Set intersection ([mutual_partitioning.hpp](mutual_partitioning.hpp))
- Doubling Search Set intersection ([doubling_search.hpp](doubling_search.hpp))


Benchmark
------------------

Intersection between two sets A and B, M = |A| < N = |B| 

Complexities:
- STL O(M+N)
- Merge-based O(M+N) 
- Binary Search O(M*log(N))
- Mutual Partitioning O(M(1+log(N/M)))
- Doubling Search O(M(1+log(N/M)))

Execution times (avg of 100):

|  M  |  N  |  STL  |  Merge-based  |  Binary Search  |  Mutual Partitioning  |  Doubling Search  |
|:---:|:---:|:-----:|:-------------:|:---------------:|:---------------------:|:------------------:|
|      100 |      100 | 0.000s | 0.000s | 0.000s | 0.000s | 0.000s |
|      100 |     1000 | 0.000s | 0.000s | 0.000s | 0.000s | 0.000s |
|     1000 |     1000 | 0.000s | 0.000s | 0.001s | 0.000s | 0.001s |
|      100 |    10000 | 0.000s | 0.000s | 0.000s | 0.000s | 0.000s |
|     1000 |    10000 | 0.000s | 0.001s | 0.001s | 0.000s | 0.001s |
|    10000 |    10000 | 0.001s | 0.001s | 0.007s | 0.003s | 0.007s |
|      100 |   100000 | 0.003s | 0.004s | 0.004s | 0.000s | 0.000s |
|     1000 |   100000 | 0.003s | 0.004s | 0.001s | 0.001s | 0.001s |
|    10000 |   100000 | 0.003s | 0.005s | 0.008s | 0.004s | 0.009s |
|   100000 |   100000 | 0.008s | 0.012s | 0.082s | 0.026s | 0.082s |
|      100 |  1000000 | 0.028s | 0.044s | 0.263s | 0.001s | 0.001s |
|     1000 |  1000000 | 0.029s | 0.044s | 0.002s | 0.002s | 0.002s |
|    10000 |  1000000 | 0.029s | 0.044s | 0.011s | 0.007s | 0.012s |
|   100000 |  1000000 | 0.034s | 0.051s | 0.097s | 0.044s | 0.105s |
|  1000000 |  1000000 | 0.084s | 0.118s | 0.919s | 0.259s | 0.948s |
|      100 | 10000000 | 0.276s | 0.445s | 3.612s | 0.006s | 0.007s |
|     1000 | 10000000 | 0.281s | 0.441s | 0.010s | 0.008s | 0.009s |
|    10000 | 10000000 | 0.285s | 0.457s | 0.026s | 0.018s | 0.025s |
|   100000 | 10000000 | 0.300s | 0.506s | 0.141s | 0.089s | 0.162s |
|  1000000 | 10000000 | 0.347s | 0.550s | 1.129s | 0.441s | 1.164s |
| 10000000 | 10000000 | 0.900s | 1.208s | 10.844s | 2.712s | 10.976s |

