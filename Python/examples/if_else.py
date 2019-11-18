number = 23
guess = int(input("enter an integer :"))

if guess == number:
    print("guess == number")
elif guess < number:
    print("guess < number")
else:
     print("guess > number")

print("Done")