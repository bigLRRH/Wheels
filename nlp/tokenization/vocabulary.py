# todo 合并fmm和rmm
def fmm(dict, sentence):  # 正向最大匹配算法FMM函数，参数dict: 词典 ，参数sentence: 句子
    fmm_result = []
    max_len = max([len(item) for item in dict])  # max_len定义为词典中最长词长度
    start = 0
    while start != len(sentence):  # FMM 为正向，start 从初始位置开始，指向结尾即为结束
        index = start + max_len  # index 的初始值为 start 的索引 + 词典中元素的最大长度或句子末尾
        if index > len(sentence):
            index = len(sentence)
        for i in range(max_len):
            # 当分词在字典中时或分到最后一个字时，将其加入到结果列表中
            if (sentence[start:index] in dict) or (len(sentence[start:index]) == 1):
                # print(sentence[start:index], end='/')
                fmm_result.append(sentence[start:index])
                start = index  # 分出一个词，start 设置到 index 处
                break
            index += -1  # 如果匹配失败，则去掉最后一个字符
    return fmm_result


def rmm(dict, sentence):  # 逆向最大匹配算法RMM函数，参数dict: 词典 ，参数sentence: 句子
    rmm_result = []
    max_len = max([len(item) for item in dict])  # max_len定义为词典中最长词长度
    start = len(sentence)
    while start != 0:  # RMM 为逆向，start 从末尾位置开始，指向开头位置即为结束
        index = start - max_len  # 逆向时 index 的初始值为 start 的索引 - 词典中元素的最大长度或句子开头
        if index < 0:
            index = 0
        for i in range(max_len):
            # 当分词在字典中时或分到最后一个字时，将其加入到结果列表中
            if (sentence[index:start] in dict) or (len(sentence[index:start]) == 1):
                # print(sentence[index:start], end='/')
                rmm_result.insert(0, sentence[index:start])
                start = index  # 分出一个词，start 设置到 index 处
                break
            index += 1  # 如果匹配失败，则去掉最前面一个字符
    return rmm_result


def BM(dict, sentence):  # 双向最大匹配（BM），参数dict: 词典 ，参数sentence: 句子
    res1 = fmm(dict, sentence)  # res1 为 FMM 结果
    res2 = rmm(dict, sentence)  # res2 为 RMM 结果
    if len(res1) == len(res2):  # 若分词数相同，则分情况讨论
        if res1 == res2:  # 若FMM 与 RMM 的结果相同，则可取任意一个
            return res1
        else:  # res1_sn 和 res2_sn 为两个分词结果的单字数量，若二者不同，则返回单字较少的
            res1_sn = len([i for i in res1 if len(i) == 1])
            res2_sn = len([i for i in res2 if len(i) == 1])
            return res1 if res1_sn < res2_sn else res2
    else:  # 若分词数不同，则取分出词较少的
        return res1 if len(res1) < len(res2) else res2
