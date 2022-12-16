import sympy as sp
import pandas as pd
import matplotlib.pyplot as plt
import math
import statistics

df = pd.read_excel('Data.xlsx') # can also index sheet by name or fetch all sheets
l = df['ALRS'].tolist()
_l = 298

a0 = 0
a1 = 0.75
σ = 1
n = 298
eps1 = statistics.NormalDist(1, 0.025).samples(n, seed=30)

eps = statistics.NormalDist(-1, 0.025).samples(n, seed=30)
l = eps1 + eps


p1=p2=0.5
R1 = l[:_l]
R2 = l[_l:]

m1 = 1/_l*sum(l[:_l])
m2 = 1/(len(l)-_l)*sum(l[_l:])

print(m1 , m2)
sg12 = 1/_l*sum([l[i]*l[i]-m1*m1 for i in range(_l+1)])
sg22 = 1/(len(l)-_l)*sum([l[i]*l[i]-m1*m1 for i in range(_l+1,len(l))])
eps = 0.01
ep1 = 2*eps
ep2 = 2*eps
while ep1 > eps or ep2 > eps:
    m11 = m1
    m22 = m2
    alpha1 = []
    alpha2 = []
    for i in range(len(l)):
        #((1 / math.sqrt(2 * sp.pi * sg12) * math.exp(-((l[i] - m1) ** 2) / (2 * sg12)) * p1) + (1 / math.sqrt(2 * sp.pi * sg22) * math.exp(-((l[i] - m2) ** 2) / (2 * sg22)) * p2)))
        alpha1.append((1/math.sqrt(2*sp.pi*sg12)*math.exp(-((l[i]-m1)**2)/(2*sg12))*p1))
        alpha2.append((1/math.sqrt(2*sp.pi*sg22)*math.exp(-((l[i]-m2)**2)/(2*sg22))*p2))

    _p1 = 1/len(l)*sum(alpha1)
    _p2 = 1/len(l)*sum(alpha2)

    m1 = 1/sum(alpha1)*sum([alpha1[i]*l[i] for i in range(len(l))])
    m2 = 1/sum(alpha2)*sum([alpha2[i]*l[i] for i in range(len(l))])

    _sg12 = 1/sum(alpha1)*sum([alpha1[i]*l[i]*l[i]-m1*m1 for i in range(len(l))])
    _sg22 = 1/sum(alpha2)*sum([alpha2[i]*l[i]*l[i]-m2*m2 for i in range(len(l))])

    ep1 = abs(m1-m11)
    ep2 = abs(m2-m22)

print(_p1, _p2)
print(m1, m2)
print(_sg12, _sg22)

_R1 = []
_R2 = []

for i in range(len(l)):
    if (1/math.sqrt(2*sp.pi*sg12)*math.exp(-((l[i]-m1)**2)/(2*sg12))*p1) >= (1/math.sqrt(2*sp.pi*sg22)*math.exp(-((l[i]-m2)**2)/(2*sg22))*p2):
        _R1.append(l[i])
    else:
        _R2.append(l[i])

Y1 = [0]*len(_R1)
Y2 = [0]*len(_R2)


plt.plot(_R1, Y1, 'o', color="red")
plt.plot(_R2, Y2, 'o', color='yellow')

plt.show()