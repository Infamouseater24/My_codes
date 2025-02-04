age = int(input("your age: "))
if age>=90:
    days = 0
    months = 0
    weeks = 0
else:
    months = (90-age) * 12
    days = 365*(90-age)
    weeks = 52 * (90-age)
print(f"You have {days} in days {months} in months and {weeks} in weeks , time left")