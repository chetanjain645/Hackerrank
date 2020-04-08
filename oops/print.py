for i in range(65, 91):
    print(chr(i), end=' ')

print('\n')
for i in range(78, 104):
    if i > 90:
        print(chr(i-26), end=' ')
    else:
        print(chr(i), end=' ')
