import prog4


# Write all possible test conditions for reading in size
def test_specify_seats():
    a_classroom = prog4.classroom() 
    a_classroom.specify_seats(30) #postive case
    assert a_classroom._seats == 30 

  # if want to work, if arg is bad input, then fail instead of reprompt
  #  a_classroom.specify_seats(-30) #negative case
  #  assert a_classroom._seats != -30 #will fail test since it got set to -30, so the fail is good 
    
  #  a_classroom.specify_seats("a") #string
  #  assert a_classroom._seats != "a" 

  #this test doesn-t work when invalid input is sent in because the specify seats function 
  # doesn't allow for a fail case, it'll prompt if the sent in arg is invalid (neg int, or non int)






