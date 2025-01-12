# CS 302 program 4/5
# Layaal Khellah 
# This program is meant to help the user match classrooms in FAB for 
# computer science use 

#red/black to make things a bit easier
from unicodedata import name


BLACK = False
RED = True

class classroom:
    def __init__(self):
        self._seats = 0
        self._size = 0
        self.left = None
        self.right = None
        self.parent = None
        self.red = False #black is false, true is red


    # def change_size(self, x):
        # self._size = x
    # removed this function because size and seats are redundant 
    def getLeft(self) -> object:
        return self.left
    
    def setLeft(self, left: object):
        self.left = left;
    
    def getRight(self) -> object:
        return self.right

    def setRight(self, right: object):
        self.right = right;
    
    def getParent(self) -> object:
        return self.parent

    def setParent(self, parent: object):
        self.parent = parent;
    
    def getColor(self) -> bool:
        return self.red

    def setColor(self, color: bool):
        self.color = color;
    
    def checkSize(self, inSeats: int):
        if (self._seats == inSeats): return True
        return False
  
    def specify_seats(self, num = None):
        found = False
        if(num):
            if not isinstance(num, str):
            #if num.isdigit():
                x = int(num)
                if x >= 0:
                    self._seats = x
                    return
                 
        while not found:     
            x = (input("Enter in a positive number of seats: "))
            #if not isinstance(x, str):
            if x.isdigit():
                x = int(x)
                if x >= 0:
                    found = True
        self._seats = x

    
    def __ge__(self,op2):
        if self.seats >= op2.seats:
            return True
        return False
  
        
    # how to call ths function
    # a_classroom = classroom()
    # a_classroom.specify_seats (10) # implicitly passes self

    
class standard(classroom):
    
    def __init__ (self):
        super().__init__()
        self._desks = 0
   
    def specify_desks(self, num = None): #oculd be less desks than students if students share larger desks
        if(num):
            x = int(num)
        else:
            x = int(input("Enter number of desks for standard class: "))
        
        if x < 0: 
            #reprompt w do while
            while(x<0):
                print("invalid input, no negative values.")
                if(num):
                    x = 0
                else:
                    x = int(input("Enter number of desks for standard class: "))
            self.desks = x
        
    
    


class lab (classroom):
    
    def __init__(self):
        super().__init__()
        self._computers = 0
    
    def specify_computers(self):
        self._computers = input("Enter number of computers available: ") 
        # return 0 or 1 for unit testing, unit test checks return type


class attend_anywhere (classroom):
    
    def __init__(self):
        super().__init__()
        self._hybrid = "no"  
    
    def specify_format(self):
        self._hybrid = input("Is this class hybrid? yes/no: ") # if not yes or not, thats an easy unit test (number, another string)
        
class Tree:
    def __init__(self):
        self.root = None

    def __del__(self):
        pass

    def retrieveRecursive(self, current: classroom, seats: int) -> classroom:
        if current is None: return None
        if (current.checkSize(seats)): return current
        
        left = self.retrieveRecursive(current.getLeft(), seats)
        right = self.retrieveRecursive(current.getRight(), seats)
        
        if left is not None: return left
        if right is not None: return right

        return None

    def retrieve(self, seats: int) -> classroom:
        if self.root is None: return None
        if seats < 0: return None
        
        return self.retrieveRecursive(self.root, seats)

    def iOS(self, root: classroom) -> classroom:
        if (root.getLeft() is None): return root
        return self.iOS(root.getLeft())

    def fixDouble(self, current: classroom):

        return

    def removeRecursive(self, removing: classroom):
        temp: classroom = None
        
        if (removing.getRight() is None) and (removing.getLeft() is None): temp = None
        elif (removing.getLeft() is None): temp = removing.getRight()
        elif (removing.getRight() is None): temp = removing.getLeft()
        else: temp = self.iOS(removing.getRight())

        doubleBlack = False

        parent: classroom = removing.getParent()

        if (temp is None):
            if (removing.getColor() == BLACK): self.fixDouble(removing)
            else:
                if (removing >= parent) and (parent.getLeft() is not None): parent.getLeft().setColor(RED)
                elif(parent.getRight() is not None): parent.getRight().setColor(RED)
            
            removing.setLeft(None)
            removing.setRight(None)
            if (removing == removing.getParent.getRight()): removing.getParent().setRight(None)
            elif (removing == removing.getParent.getLeft()): removing.getParent().setLeft(None)

    def remove(self, seats: int):
        if (seats < 0): return
        removing = self.retrieve(seats)
        if removing is None: return None

        return self.removeRecursive(removing)

    def rotate(self, current: classroom, LR: bool):
        if LR: 
            right = current.getRight()
            if (current == self.root): self.root = right

            if (current.getParent() is not None):
                if (current < current.getParent()): current.getParent().setLeft(right)
                else: current.getParent.setRight(right)
        
            right.setParent(current.getParent())
            current.setParent(right)
            current.setRight(right.getLeft())

            if (right.getLeft() is not None): right.getLeft().setParent(current)
            right.setLeft(current)

        else:
            left = current.getLeft()
            if (current == self.root): root = left

            if (current.getParent() is not None):
                if (current < current.getparent()): current.getParent().setLeft(left)
                else: current.getParent.setRight(left)
            
            left.setParent(current.getParent())
            current.setParent(left)

            current.setLeft(left.getRight())

            if (left.getRight() is not None): left.getRight().setparent(current)

            left.setRight(current)


        return

    def balanceTree(self, current: classroom):
        parent = current.getParent()
        grandParent = parent.getParent()

        while (current is not self.root) and (current.getColor is not BLACK) and (parent.getColor is RED):
            parent = current.getParent()
            grandParent = parent.getParent()

            if (parent < grandParent): #this means parent is a left child
                uncle = grandParent.getRight()

                if (uncle is not None) and (uncle.getColor() == RED):
                    grandParent.setColor(RED)
                    parent.setColor(BLACK)
                    uncle.setColor(BLACK)
                    current = grandParent
                else: #uncle either nonexistent or black
                    if current >= parent: #current is a right child
                        self.rotate(parent, True) #still haven't implemented
                        current = parent
                        parent = current.getparent()
                    self.rotate(grandParent, False)
                    temp = parent.getColor()
                    parent.setColor(grandParent.getColor())
                    grandParent.setColor(temp)
                    current = parent
            else: #parent is a right child
                uncle = grandParent.getLeft()

                if (uncle is not None) and (uncle.getColor() == RED):
                    grandParent.setColor(RED)
                    parent.setColor(BLACK)
                    uncle.setColor(BLACK)
                    current = grandParent
                else:
                    if current < parent: #current is left child
                        self.rotate(parent, False)
                        current = parent
                        parent = current.getParent()
                    
                    self.rotate(grandParent, True)
                    temp = parent.getColor()
                    grandParent.setColor(temp)
                    current = parent

        self.root.setColor(BLACK)
        return

    def insertRecursive(self, root: classroom, inserting: classroom, parent: classroom):
        if root is None:
            root = inserting
            inserting.setParent(parent)

            if (root >= parent): parent.setRight(root)
            else: parent.setLeft(root)
            return inserting
        
        if (inserting >= root): self.root.setRight(self.insertRecursive(self.root.getRight(), inserting, None))
        self.root.setLeft(self.insertRecursive(self.root.getLeft(), inserting, None))

    def insert(self, inserting: classroom):
        if self.root is None: 
            inserting.setColor(BLACK)
            return inserting
        else:
            if inserting >= self.root: #need to implement operator overloading for classroom class or change this to a compare func.
                self.root.setRight(self.insertRecursive(self.root.getRight(), inserting, None)) #need to implement setters and getters for left, right, and parent

            else: self.root.setLeft(self.insertRecursive(self.root.getLeft(), inserting, None))
            self.balanceTree(inserting)


    def set_left(self, a_left):
        self.left = a_left

    def set_right(self, a_right):
        self.right = a_right

    def set_parent(self, a_parent):
        self.Parent = a_parent

    def get_left(self):
        return self.left
    def get_right(self):
        return self.right

    def get_Parent(self):
        return self.parent

    

def user_input():
    # x = input("Enter max class occupants allowed: ")
   # a_classroom = classroom()
    # pass in a number in quotes specify_seats("-2") not (-2)
    # a_classroom.specify_seats(-2)
    answer = input("what type of classroom would you like to add: standard, lab, attend anywhere: ")
    
    


# def main():
class available():
    def __init__(self):
        head = None
        self.name = " "
        self.size = 0



if __name__ == "__main__": #if this block gets lengthy, make a function called name and store it
    print("welcome to classroom schedule. Here are the available classrooms: ")
    
    available_classes = []
    class1 = available()
    class1.name = "standard"
    class1.size = 20
    available_classes.append(class1)
    
    class2 = available()
    class2.name = "lab"
    class2.size = 15
    available_classes.append(class2)
    
    class3 = available()
    class3.name = "attend anywhere"
    class3.size = 50
    available_classes.append(class3)

    for i in available_classes:
        print (available_classes[i].name)
        
    user_input()


    # available_classes.append
    
    