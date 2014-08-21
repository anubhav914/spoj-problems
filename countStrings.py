def factors(L):
	facs = [x for x in range(1,L/2+1) if L%x == 0]
	return facs

def sepParanthesis(regex):
	""" The regex is of form (r1)(r2), return r1, r2"""
	count = 0
	for i in range(len(regex)):
		if regex[i] == '(': count +=1
		elif regex[i] == ')': count -=1
		if count == 0: return regex[:i+1], regex[i+1:]

def breakSequence(regex):
	""" Takes a regex that is a seq, return two regexes """
	""" A seq can be of form {a}(r1), or (r1){b} or {a}{b} or (r1)(r2)
	brackets and braces are parts of the regex, so we should return them as it is"""
	if regex[0] == '{'  : return regex[:3], regex[3:]
	if regex[-1] == '}' : return regex[:-3], regex[-3:]
	return sepParanthesis(regex)

def identifyType(regex):
	"""Takes a regex of {a}, {b}, (R1R2), (R1|R2), (R1*)
	and return type, regex1, regex2"""
	if len(regex) == 3: return 'lit', regex[1]
	regex = regex[1:-1]
	if regex[-1] == '*': return 'star', regex[0:-1]
	if '|' in regex:
		temp = regex.split('|')
		return 'alt', temp[0], temp[1]
	return 'seq', breakSequence(regex)

def countStrings(type, r1, r2, L):
	""" takers a regex of form type(r1,r2) and counts the number
	of strings that can be formed of length L"""
	""" type can be alt, seq, lit, star"""
	if type == 'lit': return L == 1
	if type == 'alt': 
		return countRegexStrings(r1, L) + countRegexStrings(r2, L)
	if type == 'star':
		return sum([pow(countRegexStrings(r1, l), L/l) for l in factors(L)])
	return sum([ countRegexStrings(r1 , l) + countRegexStrings(r2, L - l)
				for l in range(L+1) ])

def countRegexStrings(regex, L):
	return countStrings(identifyType(regex), L)

def test():
	assert(countRegexStrings('(({a}{b})|({b}{a}))', 2)) == 2
	assert(countRegexStrings('((a|b)*)', 5)) == 32
