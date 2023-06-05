def horspool(text, pattern) :
    n = len(text)
    m = len(pattern)

    if n < m :
        print('false')
        return

        # 预处理 Bad Character 规则
        T = [m] * 128
        for i in range(m - 1) :
            T[ord(pattern[i])] = m - 1 - i

            # 在文本中搜索模式串
            positions = []
            i = m - 1
            while i < n:
k = 0
while k < m and text[i - k] == pattern[m - 1 - k] :
    k += 1
    if k == m :
        positions.append(i - m + 1)
        i += T[ord(text[i])]

     

            # 输出 Bad Character 规则
            for i in range(m - 1) :
                c = pattern[i]
                print(c + ':' + str(T[ord(c)]))

                # 计算其他字符的移动距离
                other = sum(1 for c in T if c == m)
                print('else:' + str(other))

                # 输出模式每次出现的位序
                print(' '.join(str(p) for p in positions))

                text = input()
                pattern = input()

                horspool(text, pattern)

             if len(positions) == 0 :
                print('false')
                return