def main():
    n = int(input())
    l = list(map(int, input().split()))
    odd = []
    even = []
    for i in range(n):
        if l[i] % 2 == 1:
            odd.append(l[i])
        else:
            even.append(l[i])

    odd_num = len(odd)
    even_num = len(even)

    if odd_num < 2 and even_num < 2:
        print(-1)
        return
    
    odd_max = 0
    even_max = 0
    odd.sort(reverse=True)
    even.sort(reverse=True)
    if odd_num >= 2:
        odd_max = odd[0] + odd[1]

    if even_num >= 2:
        even_max = even[0] + even[1]

    print(max(odd_max, even_max))
    return 0

if __name__ == "__main__":
    main()
