# Link to this test, plotting waves.
# https://pythonnumericalmethods.berkeley.edu/notebooks/chapter24.01-The-Basics-of-waves.html

import matplotlib.pyplot as plt
import numpy as np

plt.style.use('seaborn-poster')


x = np.linspace(0, 20, 201) #np.linspace(start, stop, num)
y = np.sin(x) #np.sin(x). make sine

#Plot and label everything
fig = plt.figure(figsize = (8, 8))

#arange 1 t/m 5
times = np.arange(5)

#return length of an object
n = len(times)

for t in times:
    plt.subplot(n, 1, t+1)
    y = np.sin(x + t)
    plt.plot(x, y, 'b')
    plt.plot(x[25], y[25], 'ro')
    plt.ylim(-1.1, 1.1)
    plt.ylabel('y')
    plt.title(f't = {t}')

plt.xlabel('Location (x)')
plt.tight_layout()
plt.show()
