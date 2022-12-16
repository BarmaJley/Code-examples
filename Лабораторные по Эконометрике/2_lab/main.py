import matplotlib.pyplot as plt
import statistics

μ = 1
b1 = 0.85
b0 = 0.1
σ = 1
n = 30

eps = statistics.NormalDist(μ, σ**2).samples(n, seed=30)
vals = [i for i in range(1, n)]

h = []
for i in range(n-1):
    h.append(μ+b0*eps[i+1] + b1*eps[i])

plt.plot(vals, h, label="Сгенерированная")

pred_h = [b1*h[0], 0]
for i in range(1, n-2):
    for j in range(1, i+1):
        pred_h[i] += h[j]*(b1**(i-j+1))*(-1)**(i-j)
    pred_h.append(0)

plt.plot(vals, pred_h, label="Предсказанная")

plt.legend()
plt.savefig("graphic.png")
plt.show()



