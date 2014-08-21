def leaf(node):
	if node.left is None and node.right is None:
		return True
	return False

def twoPartitions(val, maxVal):
	return [(val -r, r) for r in 
	        reversed(range((val+1)/2, min(maxVal+1,val)))
	       ]

# def twoPartitions(val):
# 	return [(r, val-r) for r in range(1, val/2 +1)]

def nodesOnLevel(queue, level):
	nodeVals = []
	while len(queue):
		node,lev = queue[0]
		if lev > level:
			return nodeVals, queue
		if node.val != -1:
			nodeVals.append(node.val)
		queue.pop(0)
		if not leaf(node):
			queue.append((node.left,lev+1))
			queue.append((node.right,lev+1))
	return nodeVals, queue

def levels(tree):
	if leaf(tree):
		return 1
	return 1 + max(levels(tree.left), levels(tree.right))

def ascending(vals):
	for x in range(len(vals)-1):
		if vals[x] > vals[x+1]:
			return False
	return True

def valid(tree):
	prevMinVal = tree.val
	queue = []
	queue.append((tree, 0))
	for level in range(levels(tree)):
		nodeVals,queue = nodesOnLevel(queue,level)
                if nodeVals:
                  if not ascending(nodeVals): return False
                  if max(nodeVals) > prevMinVal: return False
                else: return True
                prevMinVal = min(nodeVals)
        return True

def complete(tree):
	if tree.val == -1: return False
	if leaf(tree): return True
	return complete(tree.left) and complete(tree.right)

def nextNode(tree, val): 
	if leaf(tree): return (None, val)
	if tree.left.val == -1 and tree.right.val == -1:
		return (tree, val)
	lNode, lMax = nextNode(tree.left, tree.left.val)
	rNode, rMax = nextNode(tree.right, tree.left.val)
	if(lNode and rNode):
		return (rNode,rMax) if rNode.val >  lNode.val else (lNode, lMax)
	return (lNode, lMax) if lNode else (rNode,rMax)


def copy(tree):
	newTree = Tree()
	newTree.val = tree.val
	if leaf(tree):
		return newTree
	newTree.left, newTree.right = copy(tree.left), copy(tree.right)
	return newTree

def countTrees(tree):
	count, queue = 0, []
	queue.append(tree)
	while len(queue):
		tree = queue[0]
		queue.pop(0)
		if not valid(tree): continue
		if complete(tree): 
			count +=1
			continue
		node, maxVal = nextNode(tree, tree.val)
		for leftChildVal,rightChildVal in twoPartitions(node.val, maxVal):
			node.left.val = leftChildVal
			node.right.val = rightChildVal
			newTree = copy(tree)
			queue.append(newTree)
	return count

class Tree:
	def __init__(self):
		self.left = None
		self.right = None
		self.val = -1

def buildTree(huffmanCodes):
	root = Tree()
	for code in huffmanCodes:
		root = makeNodes(root, code)
	return root

def makeNodes(root, code):
	node = root
	for digit in code:
		if digit == '0':
			if node.left is None:
				node.left = Tree()
			node = node.left
		if digit == '1':
			if node.right is None:
				node.right = Tree()
			node = node.right
	return root

if __name__ == '__main__':
	while True:
		inputs = raw_input().split()
		if inputs[0] == '0': break
		tree = buildTree(inputs[1:])
		tree.val = 100
		print countTrees(tree)