import matplotlib.pyplot as plt
import statistics

a0 = -1
a1 = 0.5
b1 = 0.1
sigma = 0.1
h0 = 0
n = 100

eps = statistics.NormalDist(0, 1).samples(n, seed=3320)
vals = [i for i in range(0, n)]

h = [h0]
for i in range(1, n):
    h.append(a0 + a1*h[i-1]+b1*eps[i-1]+sigma*eps[i])

arima = [0]
for i in range(n):
    for j in range(i):
        arima[i] +=h[j]
    arima.append(0)

plt.plot(vals[:-1], arima[1:-1])

plt.savefig("graphic.png")
plt.show()