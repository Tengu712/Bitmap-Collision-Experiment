import os
import subprocess
import numpy as np
import matplotlib.pyplot as plt

# define paths
path_naive = './out/test-naive.exe'
path_circle = './out/test-circle.exe'
path_square = './out/test-square.exe'

# check if exe files exist
print('[ info ] check exe files...')
is_naive = os.path.isfile(path_naive)
is_circle = os.path.isfile(path_circle)
is_square = os.path.isfile(path_square)
if not (is_circle and is_naive and is_square):
  print('[ error ] run test.bat first.')
  exit()
print('[ info ] ok.')

# define a function to exec subprocess
def exec_subprocess(cmd):
  proc = subprocess.Popen(cmd, stdout=subprocess.PIPE)
  res = [0]
  for line in proc.stdout:
    line_ = line.decode('utf-8')
    print(line_.replace('\r','').replace('\n',''))
    res.append(float(line_.split()[-1]))
  proc.wait()
  return res

# define exec exe files
print('[ info ] start test-naive.exe...')
res_of_naive = exec_subprocess("./out/test-naive.exe")
print('[ info ] start test-circle.exe...')
res_of_circle = exec_subprocess("./out/test-circle.exe")
print('[ info ] start test-square.exe...')
res_of_square = exec_subprocess("./out/test-square.exe")

# prepare figure
fig = plt.figure()
ax = fig.add_subplot(1, 1, 1)
ax.set_xlabel('Number of Entities')
ax.set_ylabel('Elapsed Time [s]')
x = np.array([
  0,
  100,
  500,
  1000,
  2000,
  3000,
  4000,
  5000,
])
#   naive
y = np.array(res_of_naive)
y /= 1000
ax.plot(x, y)
#   circle
y = np.array(res_of_circle)
y /= 1000
ax.plot(x, y)
#   square
y = np.array(res_of_square)
y /= 1000
ax.plot(x, y)

# save as graph-all.png
ax.legend(["Naive", "Circle", "Square"])
plt.savefig("img/graph-all.png")

# save as graph-part.png
ax.set_xlim(0, 2000)
ax.set_ylim(0, 2)
plt.savefig("img/graph-part.png")
