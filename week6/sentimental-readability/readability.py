from cs50 import get_string

text = get_string("Text: ")

# Store the number of letters, words and sentences
letters = 0
words = 1
sentences = 0

# Count the number of letters, words and sentences
for i in range(len(text)):
    if text[i].isalpha():
        letters += 1
    elif text[i].isspace():
        words += 1
    elif text[i] == '.' or text[i] == '!' or text[i] == '?':
        sentences += 1

l = (letters / words) * 100
s = (sentences / words) * 100
# Calculate the index
index = round(0.0588 * l - 0.296 * s - 15.8)
if index >= 16:
    print("Grade 16+")
elif index < 1:
    print("Before Grade 1")
else:
    print(f"Grade {index}")