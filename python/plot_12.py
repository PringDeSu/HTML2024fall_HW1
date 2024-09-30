import matplotlib
import matplotlib.pyplot as plt
import pandas as pd

N = 1000
data = []
for i in range(N):
    data.append(int(input()))

plt.hist(data, density = False, cumulative = False, color = "r")
plt.title("number of updates before reaching w_PLA")
plt.xlabel("number of updates")
# plt.show()
plt.savefig("figure_12.png")
