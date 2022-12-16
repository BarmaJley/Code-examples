import matplotlib.pyplot as plt
import statistics
import sympy as sp

b0 = 0.9
b1 = 0.1
a0 = 0.8
a1 = 0.2
h0 = 0
n = 3

eps = statistics.NormalDist(0, 1).samples(n+1, seed=303214)
vals = [i for i in range(1, n+1)]

h = [h0]
for i in range(1, n):
    h.append(b0+b1*h[i-1]+ eps[i]*(a0+a1*h[i-1]*h[i-1])**(0.5))

plt.plot(vals, h, label="Сгенерированная")

pred_h = []
for i in range(1, n+1):
    pred_h.append(b0+b1*h[i-1])
plt.plot(vals, pred_h, label="Предсказанная")

plt.legend()
#plt.show()
a0 = sp.Symbol('a0')
a1 = sp.Symbol('a1')
b0 = sp.Symbol('b0')
b1 = sp.Symbol('b1')

P = -n/2 * sp.ln(2*sp.pi) + sum(
    [-1/2*sp.ln(a0+a1*h[k-1]*h[k-1]) - sum([1/2*(h[i]-b0-b1*h[i-1])**2/(a0+a1*h[i-1]*h[i-1]) for i in range(1, n)]) for k in range(1, n)]
)
P = P.simplify().doit()
print(P.simplify().doit(), '\n')

pa0 = P.diff(a0).evalf().simplify().evalf(5)
print(pa0)
pa1 = P.diff(a1).evalf().simplify().evalf(5)
print(pa1)
pb0 = P.diff(b0).evalf().simplify().evalf(5)
print(pb0)
pb1 = P.diff(b1).evalf().simplify().evalf(5)
print(pb1)

solution = sp.solve({pa0, pa1 , pb0, pb1}, (a0, a1, b0, b1))
print(solution)

