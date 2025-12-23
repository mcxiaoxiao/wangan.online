from sklearn.cluster import DBSCAN
import numpy as np

# 输入数据：一维数组
X = np.array([2, 4, 8, 6, 5, 3, 14, 18, 16, 20, 25, 26]).reshape(-1, 1)

# 创建 DBSCAN 对象
dbscan = DBSCAN(eps=2, min_samples=3)

# 聚类
labels = dbscan.fit_predict(X)

# 输出结果
for i in range(max(labels) + 1):
    print(f"Cluster {i+1}: {list(X[labels == i].ravel())}")
print(f"Noise: {list(X[labels == -1].ravel())}")