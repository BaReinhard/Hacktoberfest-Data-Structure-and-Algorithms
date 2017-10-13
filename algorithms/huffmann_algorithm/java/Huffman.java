package Lecture25;

import java.util.HashMap;
import java.util.Set;

import Lecture19.BinaryTree;
import Lecture21.Heap;

public class Huffman {
	private HashMap<Character, String> encoder;
	private HashMap<String, Character> decoder;
	

	public Huffman(String sourceString){
		// 1. prepare freq map
		HashMap<Character, Integer> freqMap = new HashMap<>();
		for(int i = 0; i < sourceString.length(); i++){
			char ch = sourceString.charAt(i);
			
			if(freqMap.containsKey(ch)){
				freqMap.put(ch, freqMap.get(ch) + 1);
			} else {
				freqMap.put(ch, 1);
			}
		}
		
		
		// 2. Prepare bt's for each key freqmap and add to a min heap
		Heap<Integer, Pair> minHeap = new Heap<>(true);
		
		Set<Character> allChars = freqMap.keySet();
		for(Character ch: allChars){
			BinaryTree bt = new BinaryTree(ch, null, null);
			Pair pair = new Pair(freqMap.get(ch), bt);
			
			minHeap.add(pair.cost, pair);
		}
		
		// 3. till the heap is empty, we pull out two, create a new and enter it back
		while(minHeap.size() != 1){
			Pair p1 = minHeap.removeHP();
			Pair p2 = minHeap.removeHP();
			
			BinaryTree bt = new BinaryTree(0, p1.bt, p2.bt);
			Pair p = new Pair(p1.cost + p2.cost, bt);
			
			minHeap.add(p.cost, p);
		}
		
		// 4. Get final tree out of heap
		Pair fp = minHeap.removeHP();
		BinaryTree ft = fp.bt;
		
		// 5. Get enc, dec filled
		this.encoder = new HashMap<>();
		this.decoder = new HashMap<>();
		
		ft.traversalForHC(encoder, decoder);
	}
	
	// input - aaaaaaaaaaaaaaaaafadsfaaaaaaaaaaaaaaaaaaaabbbbbbbbbbbbbbbbbbccccccccc
	// output - 11110101010101111100001101010101010101
	public String encode(String str){
		String rv = "";
		
		for(int i = 0; i < str.length(); i++){
			rv += encoder.get(str.charAt(i));
		}
		
		return rv;
	}
	
	// input - 11110101010101111100001101010101010101
	// output - aaaaaaaaaaaaaaaaafadsfaaaaaaaaaaaaaaaaaaaabbbbbbbbbbbbbbbbbbccccccccc
	public String decode(String str){
		String rv = "";
		
		String key = "";
		for(int i = 0; i < str.length(); i++){
			key += str.charAt(i);
			
			if(decoder.containsKey(key)){
				rv += decoder.get(key);
				key = "";
			}
		}
		
		return rv;
	}
	
	private class Pair {
		int cost;
		BinaryTree bt;
		
		Pair(int cost, BinaryTree bt){
			this.cost = cost;
			this.bt = bt;
		}
	}
}
