def insertionsort(liste):
    for j in range(1,len(liste)):
        key = liste[j]
        i = j - 1
        while i >= 0 and key < liste[i]:
            liste[i+1] = liste[i]
            i -= 1
    liste[i+1] = key
