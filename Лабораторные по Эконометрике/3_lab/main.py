import matplotlib.pyplot as plt
import statistics
import sympy as sp

a0 = 0
a1 = 0.75
σ = 1
n = 1000

eps = statistics.NormalDist(a0, σ**2).samples(n, seed=30)
vals = [i for i in range(1, n)]

h = [0]
for i in range(1, n-1):
    h.append(a0+a1*h[i-1] + σ*eps[i])

plt.plot(vals, h, label="Сгенерированная")


pred_h = [a1*h[i+1] for i in range(n-2)]
pred_h.insert(0, 0)
plt.plot(vals, pred_h, label="Предсказанная")

plt.legend()
# plt.savefig("graphic.png")
plt.show()

_a0 = sp.Symbol("a0")
_a1 = sp.Symbol("a1")
_sigma = sp.Symbol("σ")

f1 = sum([h[k]-_a0-_a1*h[k-1] for k in range(1, n-1)])
f2 = sum([h[k]*h[k-1]-_a0*h[k-1]-_a1*h[k-1]*h[k-1] for k in range(1, n-1)])
solution = sp.solve((f1, f2), (_a0, _a1))
solution2 = 1/98*sum([h[k]-a0-a1*h[k-1] for k in range(1, n-1)])

print('a0 =', solution[_a0])
print('a1 =', solution[_a1])
print('sigma =', solution2**(1/2))

