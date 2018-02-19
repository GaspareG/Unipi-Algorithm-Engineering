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

Execution times (avg of 10):

|  M  |  N  |  STL  |  Merge-based  |  Binary Search  |  Mutual Partitioning  |  Doubling Search  |
|:---:|:---:|:-----:|:-------------:|:---------------:|:---------------------:|:------------------:|
|       100 |    100000 | 0.001s | 0.001s | 0.000s | 0.000s | 0.000s |
|      1000 |    100000 | 0.000s | 0.000s | 0.000s | 0.000s | 0.000s |
|     10000 |    100000 | 0.001s | 0.000s | 0.002s | 0.001s | 0.001s |
|    100000 |    100000 | 0.002s | 0.002s | 0.012s | 0.006s | 0.003s |
|       100 |   1000000 | 0.003s | 0.003s | **0.001s** | **0.001s** | **0.001s** |
|      1000 |   1000000 | 0.003s | 0.003s | 0.002s | 0.002s | **0.001s** |
|     10000 |   1000000 | 0.003s | 0.003s | 0.004s | 0.004s | **0.002s** |
|    100000 |   1000000 | 0.006s | **0.005s** | 0.018s | 0.016s | 0.008s |
|   1000000 |   1000000 | 0.022s | **0.021s** | 0.135s | 0.057s | 0.035s |
|       100 |  10000000 | 0.027s | 0.027s | 0.029s | 0.029s | **0.026s** |
|      1000 |  10000000 | **0.029s** | 0.031s | 0.030s | 0.031s | 0.032s |
|     10000 |  10000000 | 0.030s | **0.028s** | 0.033s | 0.034s | 0.034s |
|    100000 |  10000000 | 0.032s | **0.031s** | 0.059s | 0.063s | 0.048s |
|   1000000 |  10000000 | 0.053s | **0.048s** | 0.214s | 0.178s | 0.095s |
|  10000000 |  10000000 | 0.222s | **0.217s** | 1.549s | 0.611s | 0.376s |
|       100 | 100000000 | 0.288s | 0.286s | 0.267s | 0.275s | **0.265s** |
|      1000 | 100000000 | 0.285s | 0.288s | 0.277s | 0.274s | **0.263s** |
|     10000 | 100000000 | 0.290s | 0.288s | 0.270s | 0.268s | **0.268s** |
|    100000 | 100000000 | 0.284s | **0.283s** | 0.310s | 0.325s | 0.298s |
|   1000000 | 100000000 | 0.328s | **0.316s** | 0.573s | 0.591s | 0.416s |
|  10000000 | 100000000 | 0.526s | **0.481s** | 2.241s | 1.735s | 0.928s |
| 100000000 | 100000000 | 2.188s | **2.132s** | 15.845s | 5.894s | 3.622s |

