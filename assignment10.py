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
            l=list(reversed(l)) # makes the list [book, author]
            books.append(l)
        return books
    except:
        return None
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
        l=map(float,l)
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
    ave_rating=[] #currently empty list that will be filled with the average ratings of each book
    rlist=[] #a currently empty list that will be filled with lists of ratings from the ratings dictionary
    rbook=[] # stores all the ratings for each individial book
    ave=0.0
    leng=0.0 
    for l in rdict:
        rlist=rdict.values() #appends list for every key in rdict
    holder=[] #holder list for use in next step
    #this next nested loop enstially converts rlist into a list of list of book ratings. so rbook[0] is a list of 
    #all the ratings for book one
    for i in range (0,len(rlist[0])):
        for ratings in range (0,len(rlist)):
           if rlist[ratings][1]!=0:
               holder.append(rlist[ratings][i])
        rbook.append(holder)
        holder=[]
    #now to calculate the averages
    final_ratings=[]
    for i in rbook:
        leng=valid_leng(i)
        ave=sum(i)/leng
        final_ratings.append(ave)
        ave=0.0
        leng=0.0
    return final_ratings

def lookup_average_rating(index, book_dict,arlist):
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
        self.calculate_average_rating()

    def read_books(self, file_name):
        try:
            f= open(name)
            for l in f:
                l=l.strip() # remove /n char
                l=l.split(',')# makes list of [author,book]
                l=list(reversed(l)) # makes the list [book, author]
                self.book_list.append(l)
        except:
            return None
    def read_users(self, file_name):
        self.user_dictionary= read_users(file_name) 
        return None

    def calculate_average_rating(self):
        self.average_rating_list=calculate_average_rating(self.user_dictionary)
        return None
    def lookup_average_rating(self, book_index):
        a=lookup_average_rating(book_index,self.book_list,self.average_rating_list)
        return a

    def calc_similarity(self, user1, user2):
        u1=self.user_dictionary[user1]
        u2= self.user_dictionary[user2]
        sim=0
        for i in range (0,len(u1)):
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
                machid=Id
                a=b
        return machid
            

    def recommend_books(self, uid):
        match = self.get_most_similar_user(uid) 
        leng=len(self.user_dictionary[uid])
        uid= self.user_dictionary[uid]
        match=self.user_dictionary[match]
        ratings=[]
        for i in range (0,leng):
            if match[i]== 3 or 5:
                if uid[i]==0:
                    ratings.append(lookup_average_rating(match[i],self.user_dictionary,self.average_rating_list))
        return ratings



def main():
    
    if __name__ == "__main__":
        main()