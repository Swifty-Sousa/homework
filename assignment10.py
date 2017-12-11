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
#removes teh name from the list and conveerts it all to ints
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
# ended up not using this fuction 
def valid_leng(numbers):
    count=0
    for i in numbers:
        if i !=0:
            count+=1
    return count

#this fuction takes in the userdictionatry form one of the above fuctions 
#gets the lists of ratings and puts them in alist
#inversts the lists so that its is a two d array of lists where the list at each index is all the ratings 
#for an indivdual book 
#then counts all the scores that are not zero for each book
#calculates the average for each individual book and puts it in list
#returns the list
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
            

#this fuction takes in an index the dictionary of books, and the list of ratings
#finds the rating of a book with thee gievn index and saves it to rating
#finds the book name and author and saves them to variabales via the same method
#prints it all out in the format specified in the documentaion 
def lookup_average_rating(index, book_dict,arlist):
    #print arlist
    rating= arlist[index]
    name= book_dict[index][0]
    author= book_dict[index][1]
    return "(%.2f) %s by %s" %(rating,name,author)
#part 2

class Recommender:
    #defaul constructor, not much to say here, has all the variables and fuction declarations specified in the documentaion 
    def __init__(self,books_filename, ratings_filename):
        self.book_list=[]
        self.user_dictionary={}
        self.average_rating_list=[]
        self.read_books(books_filename)
        self.read_users(ratings_filename)
    #almost identiacl to the read books from above but this time
    #it modifies self.book_list instead of a fucntion variable
    # this does not return anythin unless te file does not open
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
    
    #this fuction is almost identical to read_users near the top 
    # opens file (returns none if it cannot be opened), returns an empty dictionary if the file is empty
    #for every line in the file
    # removes endline char, parese, saves name to variable, deletes name from list, converts ratings to ints, 
    #stores names and ratings lists in dictionary
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

    #this fuction is literallty the same as clculate avereage rationg form before, 
    #the only difference is that this modifies the class varaiable averave rating list
    #so i just called calc average rating with the correct variabel and have it so 
    # the avereage ratigs list becaomes the list the a calc ave from above returns
    def calculate_average_rating(self):
        self.average_rating_list=calculate_average_rating(self.user_dictionary)
        return None
    #just like the fuction directly above this one, i have already written a fuction that functions identically to this one
    #so I jsut had it call that fuction and returen the output that the other fuction returns
    def lookup_average_rating(self, book_index):
        a=lookup_average_rating(book_index,self.book_list,self.average_rating_list)
        return a

    # this fuction finds the similarity between the two inputeed users
    # first finds the length of one of the rating lists (lists are all the same length)
    # sets a variabel to the rating list for each user
    #then for each index in the lists
    # multiplies the indidies and adds it to the vriable sim which starts at 0
    #retursn sim.
    def calc_similarity(self, user1, user2):
        leng=len(self.user_dictionary[user1])
        u1=self.user_dictionary[user1]
        u2= self.user_dictionary[user2]
        sim=0
        for i in range (0,leng):
            mult=u1[i]*u2[i]
            sim+= mult
        return sim
        #this fuction finds and retuns the most similar user to the one input in the fuction
        # it does this by 
        # taking every userid and putting it into the self.calc_similarity 
        #saves the hgihest similarity score and the corresponding userid until it finds a better match
        # excludes the oridinal user by cheeking if the userid is teh same as the given one
        #returs the userid of the closest user
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
            
        #this fuction is a little broken still but i have aran out of time
        # it is suppost to find the most similar user to the one given to the fuction by calling 
        #find most simialr user
        #then it searches for books that the original usr has not read (has a score of 0)
        #checks if the beest matching user rates the book 3 or 5
        # if so calles lookupaveragerating with the index and the membere calss dictionary and list 
        #appends this value to the list
        #reuturns the list
    def recommend_books(self, uid):
        match = self.get_most_similar_user(uid) 
        leng=len(self.user_dictionary[uid])
        uid= self.user_dictionary[match]
        match=self.user_dictionary[match]
        ratings=[]
        for i in range (0,leng):
            if match[i]== 3 or 5:
                if uid[i]==0:
                    #print match[i]
                    ratings.append(lookup_average_rating(match[i],self.user_dictionary,self.average_rating_list))
        return ratings

#some of my testcases

def main():
    book_list=read_books("book.txt")
    user_dictionary=read_users("ratings.txt")
    average_rating_list=calculate_average_rating(user_dictionary)
    #a=read_users("ratings.txt")
    #calculate_average_rating(a
    #print lookup_average_rating(0,book_list,average_rating_list)
    r=Recommender("book.txt", "ratings.txt")
    print r.get_most_similar_user("Rudy_Ann")
    #print(r.user_dictionary)
    #print r.recommend_books("Brian")
    #print(r.calc_similarity("Cust9","Shannon"))
if __name__ == "__main__":
    main()