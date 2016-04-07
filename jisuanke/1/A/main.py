import re
# print(re.findall('(0k(0|[1-9A-E][0-9A-E]*))', raw_input()))
print('\n'.join(re.findall('0k(?:0|[1-9A-E][0-9A-E]*)', raw_input())))
