def pre_kmp(x: str, kmpNext: list[int]) -> None:
    """
    计算 KMP 算法的 next 数组。
    :param x: 模式字符串
    :param kmpNext: 存储 next 数组的列表
    """
    m = len(x)
    i, j = 0, -1
    kmpNext[0] = -1

    while i < m:
        while j > -1 and x[i] != x[j]:
            j = kmpNext[j]
        i += 1
        j += 1
        if i < m:
            if x[i] == x[j]:
                kmpNext[i] = kmpNext[j]
            else:
                kmpNext[i] = j

# 测试代码
if __name__ == '__main__':
    # pattern = "GCAGAGAG"
    # pattern = "GCAGCAG"
    pattern = "GCAGCTA"
 

    m = len(pattern)
    kmpNext_table = [-1] * (m + 1)  # 初始化 next 数组，多一位以匹配 C 语言的数组下标
    pre_kmp(pattern, kmpNext_table)
    print( pattern, "KMP Next 表:", kmpNext_table[:-1])  # 去掉最后一位冗余