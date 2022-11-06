import numpy as np

def main():
    n = int(input())
    p = list(map(int, input().split()))

    # 簡単な場合
    if p[n-1] < p[n-2]:
        temp = p[n-1]
        p[n-1] = p[n-2]
        p[n-2] = temp
        for i, a in enumerate(p):
            if i != 0:
                print(' ')
            print(a)
        print('\n')
    else:
        index = n-1
        p = np.array(p)
        l = [p[index]]
        l = np.array(l)
        while(p[index] > p[index-1]):
            l = np.append(l, p[index-1])
            index -= 1
        index -= 1
        target = np.sort(l[l < p[index]])[::-1][0]
        l[l == target] = p[index]
        l = np.sort(l)[::-1]
        l = np.insert(l, 0, target)
        p_front = p[:index]
        ans = np.hstack((p_front, l))
        for i, a in np.ndenumerate(ans):
            if i != (0,):
                print(' ', end='')
            print(a, end='')
        print('')

def main2():
    # 解答見た後に訂正
    # 後ろの昇順になっている部分の列は要素数が1個でもいいから，最初の分岐は不要
    n = int(input())
    p = list(map(int, input().split()))
    index = n-1
    p = np.array(p)
    l = [p[index]]
    l = np.array(l)
    while(p[index] > p[index-1]):
        l = np.append(l, p[index-1])
        index -= 1
    index -= 1
    target = np.sort(l[l < p[index]])[::-1][0]
    l[l == target] = p[index]
    l = np.sort(l)[::-1]
    l = np.insert(l, 0, target)
    p_front = p[:index]
    ans = np.hstack((p_front, l))
    for i, a in np.ndenumerate(ans):
        if i != (0,):
            print(' ', end='')
        print(a, end='')
    print('')

if __name__ == "__main__":
    main2()
