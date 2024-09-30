# HTML Home Work 1 Code
### B13902149 高翊恩
### last edit: 2024/09/29
---

## Main script (PLA algorithm)
```
g++ -std=c++17 main.cpp
./a.out iteration_count_1.txt length_1.txt
g++ -std=c++17 -D PLA_MODIFIED main.cpp
./a.out iteration_count_2.txt length_2.txt
```

## Generate Figure
```
python3 -m venv ./python
./python/bin/pip install matplotlib PyQt6 PySide2
./python/bin/activate
python ./python/plot_10.py
python ./python/plot_11.py
python ./python/plot_12.py
```
