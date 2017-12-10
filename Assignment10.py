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
        return books
    except:
        return None
def read_users(user):
    empty={}     # only used if the file is empty 
    ratings={}
    try:
        f= open(user)
        if os.stat(user)==0: #this checks if the file is empty (thank you stack overflow)
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
        return Non
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
    rbook[] # stores all the ratings for each individial book 
    for l in rdict:
        rlist.append(rdict) #appends list for every key in rdict
    holder=[] #holder list for use in next step
    #this next nested loop enstially converts rlist into a list of list of book ratings. so rbook[0] is a list of 
    #all the ratings for book one
    for i in range (0,len(rlist)):
        for ratings in rlist:
            holder.append(ratings[i])
        rbook.append(holder)
        holder=[]
    #now to calculate the averages
    final_ratings=[]
    for i in rbook:
        i=map(float,i)#this converts all the numbers in all the lists to floating point values
    for i in rbook:
        leng =valid_leng(i)
        ave= sum(l)/leng
        final_ratings.append(ave)

def lookup_average_rating(index, book_dict,arlist):
    rating= arlist[index]
    name= book_dict[index][0]
    author= book_dict[index][1]
    return "(%f) %s by %s" (rating,name,author)
#part 2

class Recommender:
    def __init__(self,books_filname, ratings_filename):
        self.book_list
        self.user_dictionary
        self.average_rating_list

	def read_books(self, file_name):
        self.book_list=read_books(file_name)
		return None

	def read_users(self, file_name):
        self.user_dictionary=read_users(file_name) 
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
        for key in user_dictionary:
            if key == userid:
                continue
            Id=key
            b=calc_similarity(userid,Id)
            if b>a:
                machid=Id
                a=b
        return machid
            

	def recommend_books(self, uid):
       match = get_most_similar_user(uid) 
       leng=len(self.user_dictionary[uid])
       uid= self.user_dictionary[uid]
       match=self.user_dictionary[match]
       ratings=[]
       for i in range (0,leng):
          if match[i]= 3 or 5 and uid[i]==0:
              ratings.append(lookup_average_rating(mach[i]))
        return ratings







    


def testcases(): 




if __name__=='__main__': testcases()