class CollusionHandling:
    def __init__(self):
        self.linearHash=[]
        self.quadraticHash=[]
        self.linearCount=0
        self.quadraticCount=0
        self.bucketSize=0

    def create_bucket(self, bsize):
        self.bucketSize=bsize
        self.linearHash=list(None for i in range(self.bucketSize))
        self.quadraticHash=list(None for i in range(self.bucketSize))

    def has_key(self, key):
        return key % self.bucketSize

    def linear_Probing(self, name, phoneNo):
        index=0
        pos=self.has_key(phoneNo)
        print("Pos is:",pos)
        if self.linearHash[pos] == None:
            self.linearHash[pos]={name:phoneNo}
        else:
            index=(pos+1)%self.bucketSize
            while index != pos:
                if self.linearHash[index]==None:
                    self.linearHash[index]={name:phoneNo}
                    return index
                index =  (index+1)%self.bucketSize
            return -1

    def search_key_Linear_prob(self, phoneNo):
        index=0
        self.linearCount=0
        pos=self.has_key(phoneNo)
        recFound=False
        phone=0
        if self.linearHash[pos] != None:
            self.linearCount += 1
            for phone in self.linearHash[pos].values():
                if phone==phoneNo:
                    print("Phone number is in Table at position ",pos)
                    recFound=True
                else:
                    index=(pos+1)%self.bucketSize
                    while index != pos:
                        self.linearCount += 1 
                        if self.linearHash[index] != None: 
                            for phone in self.linearHash[index].values():
                                if phone==phoneNo:
                                    print("Phone number is in Table at position ",index)
                                    recFound=True
                        index =  (index+1)%self.bucketSize
        if not recFound:
            print("Phone number not found!!")
        print("Number of records searched in table to find a key is :",self.linearCount)

    def display_Linear_Hash_Table(self):
        name=None
        for i in range(self.bucketSize):
            if self.linearHash[i]==None:
                print(i, " ", None)
            else:
                print(i, self.linearHash[i])

    def quadratic_Probing(self, name, phoneNo):
        index=0
        pos=self.has_key(phoneNo)
        print("Pos is:",pos)
        if self.quadraticHash[pos] == None:
            self.quadraticHash[pos]={name:phoneNo}
        else:
            i=1
            index=pos+i*i
            while index != pos:
                print("Index:",index)
                if self.quadraticHash[index]==None:
                    self.quadraticHash[index]={name:phoneNo}
                    return index
                i+=1
                index =  (pos+i*i)%self.bucketSize
            return -1

    def search_key_quadratic_prob(self, phoneNo):
        index=0
        self.quadraticCount=0
        pos=self.has_key(phoneNo)
        recFound=False
        phone=0
        if self.quadraticHash[pos] != None:
            self.quadraticCount +=1
            for phone in self.quadraticHash[pos].values():
                if phone==phoneNo:
                    print("Phone number is in Table at position ",pos)
                    recFound=True
                else:
                    i=1
                    index=(pos+i*i)%self.bucketSize
                    while index != pos:
                        self.quadraticCount += 1 
                        if self.quadraticHash[index] != None:
                            for phone in self.quadraticHash[index].values():
                                if phone==phoneNo:
                                    print("Phone number is in Table at position ",index)
                                    recFound=True
                        i+=1
                        index =  (pos+i*i)%self.bucketSize
        if not recFound:
            print("Phone number not found!!")
        print("Number of records searched in table to find a key is :",self.quadraticCount)

    def display_quadratic_Hash_Table(self):
        name=None
        for i in range(self.bucketSize):
            if self.quadraticHash[i]==None:
                print(i, " ", None)
            else:
                print(i, self.quadraticHash[i])

c1=CollusionHandling()

bsize=int(input("Enter the Size of hash table:"))
c1.create_bucket(bsize)

choice1=0
while (choice1 !=3):
    print("\n*******Collusion Handling Techniques*******")
    print("\n1. Linear Probing")
    print("\n2. Quadratic Probing")
    print("\n3. Exit Application")
    choice1=int(input("Enter Your Choice:"))
    if choice1==1:
        choice2=0
        while choice2 !=4:
            print("\n*******Linear Probing Techniques*******")
            print("\n1. Add Record in Table")
            print("\n2. Display Table Contents")
            print("\n3. Search Telephone in Table")
            print("\n4. Back to Main")
            choice2=int(input("Enter Your Choice:"))
            if choice2 ==1:
                name=input("Enter the name of a person:")
                phoneNo = int(input("Enter phone number:"))
                result=c1.linear_Probing(name,phoneNo)
                if result == -1:
                    print("\nTable is Full!")
            elif choice2 == 2:
                c1.display_Linear_Hash_Table()
            elif choice2==3:
                phoneNo=int(input("Enter the phone number to be searched::"))
                c1.search_key_Linear_prob(phoneNo)
            elif choice2 == 4:
                break
    elif choice1 ==2:
        choice2=0
        while choice2 !=4:
            print("\n*******Quadratic Probing Techniques*******")
            print("\n1. Add Record in Table")
            print("\n2. Display Table Contents")
            print("\n3. Search Telephone in Table")
            print("\n4. Back to Main")
            choice2=int(input("Enter Your Choice:"))
            if choice2 ==1:
                name=input("Enter the name of a person:")
                phoneNo = int(input("Enter phone number:"))
                result=c1.quadratic_Probing(name,phoneNo)
                if result == -1:
                    print("\nTable is Full!")
            elif choice2 == 2:
                c1.display_quadratic_Hash_Table()
            elif choice2==3:
                phoneNo=int(input("Enter the phone number to be searched::"))
                c1.search_key_quadratic_prob(phoneNo)
            elif choice2 == 4:
                break
    elif choice1 ==3:
        break
"""
Theory Explanation:

1. What the Program Does:
   This Python program demonstrates **collision handling in hashing** using two open addressing techniques:
   - **Linear Probing**
   - **Quadratic Probing**

   The program allows users to insert, search, and display records (name and phone number) using both techniques.
   It uses a simple hash function (`key % bucketSize`) to compute the index.

2. What Data Structures Are Used and Why:
   - **Lists**:
     - `self.linearHash` and `self.quadraticHash` are lists that act as hash tables.
     - Each index in the list stores a dictionary with one key-value pair: `{name: phoneNo}`.
     - `None` represents an empty bucket.
   - **Dictionaries**:
     - Used for storing each record (`name: phoneNo`) to make retrieval and display easy.

3. Key Functionalities:
   - **create_bucket(bsize)**:
     - Initializes the hash tables with a given size filled with `None`.
   - **has_key(key)**:
     - Computes hash index using modulo operation.
   - **linear_Probing(name, phoneNo)**:
     - If the calculated index is occupied, linearly searches for the next free slot.
   - **quadratic_Probing(name, phoneNo)**:
     - If the calculated index is occupied, probes using `pos + i^2` to resolve collisions.
   - **search_key_Linear_prob(phoneNo)**:
     - Searches using linear probing and counts the number of comparisons.
   - **search_key_quadratic_prob(phoneNo)**:
     - Searches using quadratic probing and counts the number of comparisons.
   - **display_Linear_Hash_Table() / display_quadratic_Hash_Table()**:
     - Prints the current state of the hash tables.

4. Real-Life Applications:
   - **Hash Tables in Databases**:
     - Efficiently store and retrieve contact information, usernames, or IDs.
   - **Phonebooks / Directories**:
     - Where quick search and update based on keys (like phone numbers) are needed.
   - **Memory Indexing in Compilers or Interpreters**:
     - Symbol tables use hashing and often handle collisions using techniques like linear or quadratic probing.

5. Hashing and Collision Resolution Concepts:
   - **Hashing**:
     - Converts a key (like a phone number) into an index for fast access.
   - **Linear Probing**:
     - Simple method of collision resolution by checking the next index in sequence until an empty slot is found.
   - **Quadratic Probing**:
     - Avoids clustering by using a quadratic formula to find the next available slot: `pos + i^2`.
   - **Open Addressing**:
     - All elements are stored within the hash table array itself (no separate chains).

Additional Notes:
   - The program avoids key duplication and handles full table scenarios.
   - Quadratic probing reduces clustering but can have issues like non-termination without proper constraints.
   - Load factor and table size (preferably prime) play a key role in performance and avoiding infinite loops.
"""
