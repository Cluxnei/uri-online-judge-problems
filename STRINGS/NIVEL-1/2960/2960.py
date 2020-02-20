
def unique(list1): 
    unique_list = []  
    for x in list1: 
        if x not in unique_list: 
            unique_list.append(x) 
    return unique_list

testedConsonants = []
def isConsonant(char):
    if char not in ['a', 'e', 'i', 'o', 'u']:
        if char not in testedConsonants:
            testedConsonants.append(char)
            return True
        return False

n = int(input())
titles = []
words = []
for i in range(0, n):
    m = int(input())
    word = ''
    for j in range(0, m):
        title = input()
        titles.append(title)
        word += title[0]
    words.append(word)
languageName = ''
for word in words:
    languageName += word[0]
print('Nome da Linguagem: ' + languageName.upper())
print('Lista de Palavras:')
for word in words:
    print(word.lower())
concatedWords = "".join(words)
vowels = ['a', 'e', 'i', 'o', 'u']
numberOfVowels = 0
numberOfConsonants = 0
for word in words:
    for c in word:
        if c.lower() in vowels:
            numberOfVowels += 1
            vowels.remove(c.lower())
for word in words:
    for c in word:
        numberOfConsonants += 1 if isConsonant(c.lower()) else 0
print('Numero de Vogais: ' + str(numberOfVowels))
print('Numero de Consoantes: ' + str(numberOfConsonants))
print('Numero Total de Letras: ' + str(numberOfConsonants + numberOfVowels))
numberOfChars = 0
testedChars = []
for word in words:
    for c in word:
        if c not in testedChars:
            testedChars.append(c)
            numberOfChars += 1
if numberOfConsonants == 0:
    print('Linguagem Ruim')
    exit(0)
timeForLearn = float((numberOfChars + numberOfVowels) / numberOfConsonants)
print('Tempo para aprender: {:.1f}'.format(timeForLearn) + ' horas')
