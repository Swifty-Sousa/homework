#Author: Christian F. Sousa
# TA: Thomas Lillis
import os

# part a 
def read_books(name):
    books=[] #start with an empty list
    try:
        f= open(name)
        for l in f:
            l=l.strip() # remove /n char
            l=l.split(',')# makes list of [author,book]
            l=l.reverse() # makes the list [book, author]
            books.append(l)
    except:
        return None
def read_users(user):
    empty={}     # only used if the file is empty 
    ratings={}
    try:
        f= open(user)
        if os.stat(user)==0:
            return empty
        for l in f:
            l=l.strip()
            l=l.split()
            name=l[0]
            del l[0]
            rat=l
            ratings[name]=l
        return ratings
    except:
        return None

