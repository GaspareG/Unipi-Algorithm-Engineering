# 3 Random Sampling

#### Disk model and known sequence length
 
- Drawing from all un-sampled positions ([drawing_sampling.hpp](drawing_sampling.hpp))
- Dictionary of sampled positions ([dictionary_sampling.hpp](dictionary_sampling.hpp))
- Sorting sampling ([sorting_sampling.hpp](sorting_sampling.hpp))

#### Streaming model and known sequence length

- Scanning and selecting ([scanning_sampling.hpp](scanning_sampling.hpp))

#### Streaming model and unknown sequence length

- Heap and random keys ([heap_sampling.hpp](heap_sampling.hpp))
- Reservoir sampling ([reservoir_sampling.hpp](reservoir_sampling.hpp))

Complexities
-----------

Sampling m integer from a set S of size n.
Block size = B

|   Algorithm     |    Time     | Space | Rnd  |     I/Os       |
|:----------------|:-----------:|:-----:|:----:|:--------------:|
| **Drawing**     | O(n)        |  O(n) | m    | O(m)           |
| **Dictionary**  | O(m)        |  O(m) | O(m) | O(min(m, n/B)) |
| **Sorting**     | O(m*log(m)) |  O(m) | O(m) | O(min(m, n/B)) |
| **Scanning**    | O(n)        |  O(m) | n    | O(n/B)         |
| **Heap**        | O(n*log(m)) |  O(m) | n    | O(n/B)         |
| **Reservoir**   | O(n)        |  O(m) | n    | O(n/B)         |

Benchmark
------------------

Sorting sampling omitted (too slow)
Execution times (avg of 10):

|  M  |  N  | Drawing  |  Dictionary  |  Scanning  | Heap | Reservoir |
|----:|----:|-----:|---------:|------------:|----------:|----:|
|       100 |      1000 | 0.000021s | 0.000140s  | 0.000067s | 0.000794s  | 0.000128s |
|       100 |     10000 | 0.000009s | 0.000053s  | 0.000268s | 0.000898s  | 0.000525s |
|      1000 |     10000 | 0.000076s | 0.000785s  | 0.000304s | 0.004595s  | 0.000510s |
|       100 |    100000 | 0.000082s | 0.000058s  | 0.002470s | 0.004722s  | 0.004450s |
|      1000 |    100000 | 0.000095s | 0.000627s  | 0.002393s | 0.008637s  | 0.005241s |
|     10000 |    100000 | 0.000506s | 0.007404s  | 0.002598s | 0.045067s  | 0.004215s |
|       100 |   1000000 | 0.000727s | 0.000061s  | 0.023856s | 0.041623s  | 0.043153s |
|      1000 |   1000000 | 0.000509s | 0.000617s  | 0.024058s | 0.050538s  | 0.044870s |
|     10000 |   1000000 | 0.001315s | 0.008506s  | 0.025360s | 0.108167s  | 0.045657s |
|    100000 |   1000000 | 0.006382s | 0.116569s  | 0.025558s | 0.555261s  | 0.044865s |
|       100 |  10000000 | 0.007306s | 0.000057s  | 0.247114s | 0.410143s  | 0.439367s |
|      1000 |  10000000 | 0.007030s | 0.000679s  | 0.251875s | 0.428127s  | 0.448571s |
|     10000 |  10000000 | 0.007918s | 0.007719s  | 0.238974s | 0.499628s  | 0.441396s |
|    100000 |  10000000 | 0.015778s | 0.107232s  | 0.240327s | 1.225629s  | 0.444014s |
|   1000000 |  10000000 | 0.116045s | 2.263628s  | 0.287852s | 8.231066s  | 0.519739s |
|       100 | 100000000 | 0.090859s | 0.000069s  | 2.710684s | 4.477015s  | 4.825889s |
|      1000 | 100000000 | 0.066139s | 0.001043s  | 2.518072s | 4.181679s  | 4.418446s |
|     10000 | 100000000 | 0.063151s | 0.007479s  | 2.433381s | 4.284428s  | 4.367758s |
|    100000 | 100000000 | 0.072447s | 0.105102s  | 2.399164s | 5.303580s  | 4.481434s |
|   1000000 | 100000000 | 0.165201s | 1.742138s  | 2.461771s | 15.021817s | 4.520372s |
|  10000000 | 100000000 | 2.926395s | 22.165197s | 2.597075s | 86.029406s | 4.618594s |

