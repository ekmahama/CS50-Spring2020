# . : any character
# .* : 0 or more character
# .+ : 1 or more character
# ? : Optional
# ^ : start on input
# $ end of input

import re

s = input("Do you agree: ").lower()

if re.search("^y(es)?$", re.IGNORECASE):
    print('Agreed')

if re.search('n(o)?', s):
    print('Not agreed')
