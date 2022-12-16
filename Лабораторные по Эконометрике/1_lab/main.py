import matplotlib.pyplot as plt
import statistics

μ = 0.0
σ = 0.1
n = 500

eps = statistics.NormalDist(μ, σ**2).samples(n, seed=123124123)
vals = [i for i in range(1, n+1)]

plt.plot(vals, eps)
plt.savefig("graphic.png")
plt.show()