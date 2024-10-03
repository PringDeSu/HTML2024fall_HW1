import matplotlib
import matplotlib.pyplot as plt

N = 1000
data = []
for i in range(N):
    data.append(int(input()))

plt.hist(data, density = False, cumulative = False)
plt.title("number of updates before reaching w_PLA")
plt.xlabel("number of updates")
# plt.show()
plt.savefig("figure_10.png")
