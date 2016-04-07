import re
print re.sub(r'\([a-zA-Z]+\)|[^a-zA-Z0-9\s\(\)]\)', lambda s: '<S>'+s.group(0)+'</S>', raw_input())