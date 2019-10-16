# A simple bloom filter in Python 3
# Author: Flora Rosenkreuz (reindeer-cafe)
import math

class BloomFilter:

	# very simple string encode
	def SimpleStringEncode(self, data):
		hash = 0
		for x in data: hash += (ord(x))
		return hash % 20

	# implementation of the fnv hash
	def FNV(self, data):
		hash = 2166136261
		b = bytes(data, 'utf-8')
		for byte in b:
			hash = hash ^ byte
			hash = hash * 16777619
		return hash % 20

	# add a string to the filter
	def Add(self, data):
		h1 = self.SimpleStringEncode(data)
		h2 = self.FNV(data)
		self.Vector[h1] = 1
		self.Vector[h2] = 1

	# false positives are possible in a bloom filter hence is "possibly" in
	def IsPossiblyIn(self, data):
		#m num b
		h1 = self.SimpleStringEncode(data)
		h2 = self.FNV(data)
		return True if (self.Vector[h1] and self.Vector[h2]) else False

	# computes the approximate false positive rate
	def ComputeCollisionRate(self):
		n = 0
		for b in self.Vector:
			n += 1 if b else 0
		return math.pow((1 - (math.pow(math.e, (((-1 * 2) * n) / 20)))), 2)

	def __init__(self):
		self.Vector = [0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0]
