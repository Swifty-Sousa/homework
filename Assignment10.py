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

def lookup_average_(index, book_dict,arlist):
    rating= arlist[index]
    name= book_dict[index][0]
    author= book_dict[index][1]
    return "(%f) %s by %s" (rating,name,author)
#part 2

class Recommender:
    #Constructor here
	def read_books(self, file_name):
		"""
		"""
		return None

	def read_users(self, file_name):
		"""
		"""
		return None

	def calculate_average_rating(self):
		"""
		"""
		return

	def lookup_average_rating(self, book_index):
		"""
		"""
		return average_rating_string

	def calc_similarity(self, user1, user2):
		"""
		"""
		return similarity_measure

	def get_most_similar_user(self, current_user_id):
		"""
		"""
		return best_user_match_id

	def recommend_books(self, current_user_id):
		"""
		"""
		return recommendations_list






    



def testcases():








if __name__=='__main__': testcases()