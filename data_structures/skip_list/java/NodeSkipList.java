package psa.naloga3;

public class NodeSkipList {
	
	int key;
	NodeSkipList[] successors;
	
	NodeSkipList(int key, int maxLevels)
	{
		this.key = key;
		this.successors = new NodeSkipList[maxLevels];
	}
}
