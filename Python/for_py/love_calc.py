print("Welcome to Love Calculator")
name1 = input("Enter your name: ").lower()
name2 = input("Enter his/her name: ").lower()
t = name1.count('t') + name2.count('t')
r = name1.count('r') + name2.count('r')
u = name1.count('u') + name2.count('u')
e = name1.count('e') + name2.count('e')
l = name1.count('l') + name2.count('l')
o = name1.count('o') + name2.count('o')
v = name1.count('v') + name2.count('v')
love = int(str(t+r+u+e)+str(l+o+v+e))
if love > 90 or love < 10:
    print(f"Your score is {love}. You go together like coke and mentos")
elif love>40 and love<50:
    print(f"Your score is {love}. You are alright together")
else:
    print(f"Your score is {love}.")

