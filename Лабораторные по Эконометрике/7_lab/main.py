import sympy as sp
import pandas as pd
import matplotlib.pyplot as plt

eps = 0.01
df = pd.read_excel('Data.xlsx') # can also index sheet by name or fetch all sheets
l = df['ALRS'].tolist()


R1 = l[:2]
R2 = l[2:]
#print(R1, R2)
m1 = 1/len(R1)*sum(R1)
m2 = 1/len(R2)*sum(R2)

print("m1 = {}; m2 = {}".format(m1, m2))
m11 = m1 + 10*eps
m22 = m2 + 10*eps
while abs(m11-m1) > eps or abs(m22-m2) > eps:
    m11 = m1
    m22 = m2
    R1 = []
    R2 = []
    for i in range(1, len(l)):
        if abs(l[i] - m1) < abs(l[i] - m2):
            R1.append(l[i])
        else:
            R2.append(l[i])
    m1 = 1/len(R1)*sum(R1)
    m2 = 1/len(R2)*sum(R2)

Y1 = [0]*len(R1)
Y2 = [0]*len(R2)


plt.plot(R1, Y1, 'o', color="purple")
plt.plot(R2, Y2, 'o', color='yellow')

plt.show()