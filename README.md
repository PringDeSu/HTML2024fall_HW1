# HTML Home Work 1 Code
### B13902149 高翊恩
### last edit: 2024/10/03
---

## Main script (PLA algorithm)
```
g++ -std=c++17 ./main.cpp -D PRINT -O3
./a.out iteration_count_1.txt length_1.txt
g++ -std=c++17 -D PLA_MODIFIED ./main.cpp -D PRINT -O3
./a.out iteration_count_2.txt length_2.txt
```

## Generate Figure
```
python3 -m venv ./python
./python/bin/pip install matplotlib PyQt6
./python/bin/python ./python/plot_10.py < ./iteration_count_1.txt
./python/bin/python ./python/plot_11.py < ./length_1.txt
./python/bin/python ./python/plot_12.py < ./iteration_count_2.txt
```
