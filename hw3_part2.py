#Part 3.1

#Function to check if a string is a palindrome
def is_palindrome(str):
    reversed_string = ''.join(reversed(str))
    return (reversed_string == str)

#Function to get all substrings of a given length of a string
def get_all_substrings_in_a_given_length(str, length):
    return [str[start_index: start_index + length] for start_index in range(len(str) - length + 1)]

#Function to set the values that will go into the dictionary
def get_dict_values(str, length):
    substrings = get_all_substrings_in_a_given_length(str, length)
    values = []
    for element in substrings:
        if(is_palindrome(element)):
          values.append(element)
    return values

def get_palindrom_dict(str):
    new_dict = {}
    if (str == ""):
        return new_dict
    
    for t in range(1,len(str) + 1):
       values = get_dict_values(str, t)
       if(values):
            new_dict[t] = values
    return new_dict

dict1 = get_palindrom_dict("AbbAcaBBa")
for k, v in dict1.items():
    print(k , 'is for' , v)
print("-----------")
dict2 = get_palindrom_dict("aaa")
for k, v in dict2.items():
    print(k , 'is for' , v)
print("-----------")
dict3 = get_palindrom_dict("horse")
for k, v in dict3.items():
    print(k , 'is for' , v)
print("-----------")
dict4 = get_palindrom_dict("aAaAa")
for k, v in dict4.items():
    print(k , 'is for' , v)
print("-----------")
dict5 = get_palindrom_dict("   ")
for k, v in dict5.items():
    print(k , 'is for' , v)
print("-----------")
dict6 = get_palindrom_dict("9")
for k, v in dict6.items():
    print(k , 'is for' , v)
print("-----------")