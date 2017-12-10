#Author: Christian F. Sousa
# TA: Thomas Lillis
import os

# part a 
#this fuction:
#opens file (returns none if file does not exist)
#and for each line in the file
#removes endline char, parses on space and reversed order of the list to get the right order
#then appends to the list books,
#finally returns the list
def read_books(name):
    books=[] #start with an empty list
    try:
        f= open(name)
        for l in f:
            l=l.strip() # remove /n char
            l=l.split(',')# makes list of [author,book]
            l=list(reversed(l)) # makes the list [book, author]
            books.append(l)
        return books
    except:
        return None
#this fuction is very similar to the above fuction
#opens file(returns none if file is not found) checks if the file is empty and returns an empty dictionary if it is 
#for line in the file
#removes endline char, parses on space, stores the fist thing in the list as the name
def read_users(user):
    empty={}     # only used if the file is empty 
    ratings={}
    try:
        f= open(user)
    except:
        return None
    if os.stat(user)==0: #this checks if the file is empty (thank you stack overflow)
        return empty
    for l in f:
        l=l.strip()
        l=l.split()
        name=l[0]
        del l[0]
        l=map(int,l)
        ratings[name]=l
    return ratings

#takes in a list of ratings and finds which ones are valid ratings ie, not 0 and counts them
def valid_leng(numbers):
    count=0
    for i in numbers:
        if i !=0:
            count+=1
    return count

def calculate_average_rating(rdict):
    rlist= rdict.items()# rlist is now a list of touples which have the key and value
    averages=[]
    holder=0.0 #just a holder variable to calculatee aveerges in befor I append to a list
    summ=0.0
    length=0.0
    for i in range(0,len(rlist[0][1])):
        for keys in rdict:
            if rdict[keys][i]!=0:
                summ += rdict[keys][i]
                length+= 1
        holder=summ/length
        averages.append(holder)
        length=0.0
        summ=0.0
    return averages
            


def lookup_average_rating(index, book_dict,arlist):
    #print arlist
    rating= arlist[index]
    name= book_dict[index][0]
    author= book_dict[index][1]
    return "(%.2f) %s by %s" %(rating,name,author)
#part 2

class Recommender:
    def __init__(self,books_filename, ratings_filename):
        self.book_list=[]
        self.user_dictionary={}
        self.average_rating_list=[]
        self.read_books(books_filename)
        self.read_users(ratings_filename)

    def read_books(self, file_name):
        try:
            f= open(file_name)
            for l in f:
                l=l.strip() # remove /n char
                l=l.split(',')# makes list of [author,book]
                l=list(reversed(l)) # makes the list [book, author]
                self.book_list.append(l)
        except:
            return None

    def read_users(self, file_name):
        empty={}     # only used if the file is empty 
        try:
            f= open(file_name)
        except:
            return None
        if os.stat(file_name)==0: #this checks if the file is empty (thank you stack overflow)
            return empty
        for l in f:
            l=l.strip()
            #print(l)
            l=l.split()
            #print(l)
            name=l[0]
            del l[0]
            l=map(int,l)
            #print l
            #print(l)
            #for i in l:
            #   i=float(i)
            #  print(i)
            #print(l)
            #l=ll
            self.user_dictionary[name]=l
        f.close()
    def calculate_average_rating(self):
        self.average_rating_list=calculate_average_rating(self.user_dictionary)
        return None
    def lookup_average_rating(self, book_index):
        a=lookup_average_rating(book_index,self.book_list,self.average_rating_list)
        return a

    def calc_similarity(self, user1, user2):
        leng=len(self.user_dictionary[user1])
        u1=self.user_dictionary[user1]
        u2= self.user_dictionary[user2]
        sim=0
        for i in range (0,leng):
            mult=u1[i]*u2[i]
            sim+= mult
        return sim

    def get_most_similar_user(self, userid):
        matchid=""
        a=0
        b=0
        for key in self.user_dictionary:
            if key == userid:
                continue
            Id=key
            b=self.calc_similarity(userid,Id)
            if b>a:
                matchid=Id
                a=b
        return matchid
            

    def recommend_books(self, uid):
        match = self.get_most_similar_user(uid) 
        leng=len(self.user_dictionary[uid])
        uid= self.user_dictionary[match]
        match=self.user_dictionary[match]
        ratings=[]
        for i in range (0,leng):
            if match[i]== 3 or 5:
                if uid[i]==0:
                    print match[i]
                    ratings.append(lookup_average_rating(match[i],self.user_dictionary,self.average_rating_list))
        return ratings



def main():
    book_list=read_books("book.txt")
    user_dictionary=read_users("ratings.txt")
    average_rating_list=calculate_average_rating(user_dictionary)
    #a=read_users("ratings.txt")
    #calculate_average_rating(a
    print lookup_average_rating(0,book_list,average_rating_list)
    r=Recommender("book.txt", "ratings.txt")
    #print(r.user_dictionary)
    #print r.recommend_books("Brian")
    #print(r.calc_similarity("Cust9","Shannon"))
if __name__ == "__main__":
    main()