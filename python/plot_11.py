import matplotlib
import matplotlib.pyplot as plt
import pandas as pd

data = []
big = 200
N = 1000
for i in range(N):
    tmp = input().strip().split()
    for j in range(len(tmp)):
        tmp[j] = float(tmp[j])
    data.append(tmp)
    if len(data[i]) < big:
        big = len(data[i])
ll = []
for i in range(1, big + 1):
    ll.append(i)
for i in range(N):
    data[i] = data[i][:big]
    plt.plot(ll, data[i], color = "b")

plt.title("the length of w_k")
plt.xlabel("k-th updates")
# plt.show()
plt.savefig("figure_11.png")
