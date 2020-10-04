package psa.naloga3;

import java.util.Random;

public class SkipList
{

	private NodeSkipList head;
	private int maxHeight;

	public enum Coin
	{
		HEAD, TAIL
	}

	/*
	 * Tvoritelj sprejme kot parameter stevilo elementov, ki jih je sposoben
	 * obdelati
	 */
	public SkipList(long maxNodes)
	{
		this.maxHeight = (int) Math.round(Math.log(maxNodes) / Math.log(2)); // Logarithm with base 2
		this.head = new NodeSkipList(Integer.MIN_VALUE, maxHeight);
	}

	/*
	 * Metoda sprejme stevilo in ga vstavi v preskocni seznam. Ce element ze obstaja
	 * v podatkovni strukturi, vrne false. Metoda vrne true, ce je bil element
	 * uspesno vstavljen in false sicer.
	 */
	public boolean insert(int searchKey)
	{
		int level = getRandomLevel();
		NodeSkipList newNode = new NodeSkipList(searchKey, maxHeight);

		NodeSkipList currentNode = head;

		for (int i = maxHeight - 1; i >= 0; i--)
		{
			while (currentNode.successors[i] != null)
			{
				if (currentNode.successors[i].key > searchKey)
					break;
				else if (currentNode.successors[i].key == searchKey)
					return false;

				currentNode = currentNode.successors[i];
			}

			if (i <= level)
			{
				newNode.successors[i] = currentNode.successors[i];
				currentNode.successors[i] = newNode;
			}
		}
		return true;
	}

	/*
	 * Metoda sprejme stevilo in poisce element v preskocnem seznamu. Metoda vrne
	 * true, ce je bil element uspesno najden v podatkovni strukturi, in false sicer
	 */
	public boolean search(int searchKey)
	{
		NodeSkipList currentNode = head;
		for (int i = maxHeight - 1; i >= 0; i--)
		{
			while (currentNode.successors[i] != null)
			{
				if (currentNode.successors[i].key > searchKey)
					break;
				if (currentNode.successors[i].key == searchKey)
					return true;

				currentNode = currentNode.successors[i];
			}
		}
		return false;
	}

	/*
	 * Metoda sprejme stevilo in izbrise element iz preskocnega seznama. Metoda vrne
	 * true, ce je bil element uspesno izbrisan iz podatkovne strukture, in false
	 * sicer
	 */
	public boolean delete(int key)
	{
		NodeSkipList currentNode = head, nextNode = null;
		boolean result = false;
		for (int i = maxHeight - 1; i >= 0; i--)
		{
			while (currentNode.successors[i] != null)
			{
				if (currentNode.successors[i].key > key)
					break;
				else if (currentNode.successors[i].key == key)
				{
					nextNode = currentNode.successors[i];
					currentNode.successors[i] = nextNode.successors[i];
					result = true;
					break;
				}
				currentNode = currentNode.successors[i];
			}
		}

		return result;
	}

	public static Coin getRandomCoinValue()
	{
		return Coin.values()[new Random().nextInt(Coin.values().length)];
	}

	public int getRandomLevel()
	{
		int count = 0;
		for (Coin value = getRandomCoinValue(); value != Coin.TAIL
				&& count != maxHeight - 1; value = getRandomCoinValue(), count++);

		return count;
	}
	
}
