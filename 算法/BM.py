def build_bad_char_table(pattern):
    """构建坏字符表"""
    bad_char = {}
    length = len(pattern)
    for i in range(length - 1):
        bad_char[pattern[i]] = length - 1 - i
    return bad_char

def build_good_suffix_table(pattern):
    """构建好后缀表"""
    good_suffix = [0] * (len(pattern) + 1)
    i = len(pattern)
    j = len(pattern) + 1
    border_table = [0] * (len(pattern) + 1)
    border_table[i] = j

    while i > 0:
        while j <= len(pattern) and pattern[i - 1] != pattern[j - 1]:
            if good_suffix[j] == 0:
                good_suffix[j] = j - i
            j = border_table[j]
        i -= 1
        j -= 1
        border_table[i] = j

    j = border_table[0]
    for i in range(len(pattern) + 1):
        if good_suffix[i] == 0:
            good_suffix[i] = j
        if i == j:
            j = border_table[j]
    return good_suffix

def boyer_moore_search(text, pattern):
    """BM算法搜索函数"""
    bad_char = build_bad_char_table(pattern)
    good_suffix = build_good_suffix_table(pattern)
    print("Bad Character Table:", bad_char)
    print("Good Suffix Table:", good_suffix)
    m = len(pattern)
    n = len(text)

    i = 0
    while i <= n - m:
        j = m - 1
        while j >= 0 and pattern[j] == text[i + j]:
            j -= 1
        if j < 0:
            return i
        else:
            i += max(good_suffix[j + 1], j - bad_char.get(text[i + j], -1))

    return -1

# PPT示例
text = "GCATCGCAGAGAGTATACAGTACG"
pattern = "CAGAGAG"
# 考试时可能要注意Bad Character表包括T=8

# text = "HERE IS A SIMPLE EXAMPLE"
# pattern = "EXAMPLE"

index = boyer_moore_search(text, pattern)
print(f"Pattern found at index: {index}")