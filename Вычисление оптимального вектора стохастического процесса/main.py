import numpy as np
import pandas as pd
from scipy.optimize import LinearConstraint, minimize
from scipy.stats import norm
from operator import itemgetter


def norma(arr):
    s = 0
    arr = np.asarray(arr)
    for i in range(0, len(arr)):
        s += arr[i] * arr[i]
    return np.sqrt(s)


def MCD(V, L, H=0):
    if type(H) == int:
        H1 = V[:L]
    else:
        H1 = H
    R1 = H1.mean()
    C1 = H1.cov()

    d = [np.asarray((1 / C1) * V.iloc[i] - R1).dot(np.asarray(V.iloc[i] - R1)) for i in range(len(V))]
    arg_sort = sorted(range(len(d)), key=lambda i: d[i][0])
    d = [d[i] for i in arg_sort]
    V = pd.concat([V.iloc[i] for i in arg_sort], axis=1, ignore_index=False).transpose()

    H2 = V[:L]
    R2 = H2.mean()
    C2 = H2.cov()



    if norma(C2)[0] < norma(C1)[0] and norma(C2)[1] < norma(C1)[1]:
        return MCD(V, L, H2)
    else:
        return H2


def function(betta, R, C):
    return lambda x: -1 * ((np.dot(R, x.reshape(2, 1)) - (1 / norm.cdf(betta)) * np.sqrt(
        np.dot(np.dot(C, x.reshape(2, 1)).T, x.reshape(2, 1)))).flatten()[0])


def opt_vec(betta, R, C):
    x = np.zeros(2)
    lincon = LinearConstraint([[0, 1], [1, 0]], [0, 0], [np.inf, np.inf])
    lincon_2 = LinearConstraint([[1, 1]], [1], [1])
    f = function(betta, R, C)
    x = minimize(f, np.array([0.5, 0.5]), constraints=[lincon, lincon_2]).x
    return x


n, N = 2, 298
file = 'Data.xlsx'
df = pd.read_excel(file)

V = pd.concat([df['ROLO'], df['GAZP']], axis=1)
V1 = V[0:N // 2]
V2 = V[N // 2 + 1:N]

H1 = MCD(V1, 100)

R1 = H1.mean()
C1 = H1.cov()

print("Среднее: ", np.asarray(R1))
print("Ков. матрица: \n", np.asarray(C1))
betta = 0.75

RV2 = V2.mean()
CV2 = V2.cov()

x = opt_vec(betta, RV2, CV2)

Vcp = 0
D = 0
Vmin = 100
for i in range(0,N//2-1):
    Vcp += np.dot(np.asarray(V2.iloc[i]), x)
    D += np.dot(np.asarray(V2.iloc[i]),x) * np.dot(np.asarray(V2.iloc[i]), x)
    if Vmin > np.dot(np.asarray(V2.iloc[i]), x):
        Vmin = np.dot(np.asarray(V2.iloc[i]), x)

Vcp *= 1/norma(V2)
D = (D * 1/norma(V2)) - (Vcp * Vcp)

print("Vcp = ", Vcp)
print("Vmin = ", Vmin)
print("D = ", D)
