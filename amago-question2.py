from heapq import *
import pdb

def twoPartitions(val, maxVal):
	return [(val -r, r) for r in 
	        reversed(range((val+1)/2, min(maxVal+1,val)))
	       ]
	       
def leaf(node):
	if node.left is None and node.right is None:
		return True
	return False

def height(root):
	if leaf(root):
		return 1
	return 1 + max(height(root.left), height(root.right))

def getMaxVaueOnLowerLevels(maxValues, level):
	if level >= len(maxValues) - 1:
		return 0
	return max([val for val in maxValues[level+1:]])

def buildTreeCountMap(root, val):
	pdb.set_trace()
	priorityQueue = [(-1*val, root, val, 0)]
	heapify(priorityQueue)
	treeCountMap = {}
	maxValues = [0] * height(root)
	while len(priorityQueue):
		val, node, maxVal, level = heappop(priorityQueue)
		val = -1 * val
		maxVaueOnLowerLevels = getMaxVaueOnLowerLevels(maxValues, level)
		if leaf(node):
			if val < maxVaueOnLowerLevels:
				continue
			if (node,val) not in treeCountMap:
				treeCountMap[(node, val)] = 1
			continue
		for a,b in twoPartitions(val, maxVal):
			heappush(priorityQueue, (-1*b, node.right, a, level+1))
			heappush(priorityQueue, (-1*a, node.left, a, level+1))
		maxValues[level] = val
	return treeCountMap

def numTrees(root, tcMap, val):
	if leaf(root):
		return tcMap[(root,val)] if (root, val) in tcMap else 0
	if (root,val) not in tcMap:
		count = 0
		for a,b in twoPartitions(val, 100):
			count += numTrees(root.left, tcMap, a) * numTrees(root.right, tcMap, b)
		tcMap[(root,val)] = count
	return tcMap[(root,val)]
	
class Tree:
	def __init__(self):
		self.left = None
		self.right = None
		self.val = 0

def build3NodeTree():
	root = Tree()
	root.left = Tree()
	root.right = Tree()
	return root

def buildTree():
	root = build3NodeTree()
	root.right = build3NodeTree()
	root.left  = build3NodeTree()
	root.left.right = build3NodeTree()
	return root

root = buildTree()
tcMap = buildTreeCountMap(root, 10)
test = numTrees(root, tcMap, 10)
print test